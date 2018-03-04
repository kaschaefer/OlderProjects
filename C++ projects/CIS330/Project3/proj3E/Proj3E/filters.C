#include <filters.h>

using namespace std;

void Filter::Update(void) {
    if (input1 != nullptr) {
        input1->Update();
    }
    if (input2 != nullptr) {
        input2->Update();
    }
    this->Execute();
}

void Shrinker::Execute(void) {
	Image* in = this->input1;
	Image* out = this->GetOutput();
	int width = in->getWidth()/2;
	int height = in->getHeight()/2;
	out->ResetSize(width, height);
	Pixel * inBuff = in->getBuffer();
	Pixel * outBuff = out->getBuffer();
	for (int r=0; r<height*2; r = r+2) {
		for (int c=0; c < width; c++) {
			outBuff[(r/2)*width+c] = inBuff[2*(r*width+c)];
		}
	}
}


void LRConcat::Execute(void) {
	int leftWidth = this->input1->getWidth();
	int rightWidth = this->input2->getWidth();
	int width = leftWidth+rightWidth;
	int height = this->input1->getHeight();
	Pixel* in1Buff = this->input1->getBuffer();
	Pixel* in2Buff = this->input2->getBuffer();
	Image* output = this->GetOutput();
	output->ResetSize(width, height);
	Pixel* outBuff = output->getBuffer();
	
	for (int r =0; r < height; r++) {
		for (int c=0; c < width; c++) {
			if (c <leftWidth) {
				outBuff[r*width+c] = in1Buff[r*leftWidth+c];
			}
			else {
                outBuff[r*width+c] = in2Buff[r*rightWidth+(c-leftWidth)];
			}
		}
	}

}

void TBConcat::Execute(void) {
	int width = this->input1->getWidth();
	int topHeight = this->input1->getHeight();
	int newHeight = this->input1->getHeight()+this->input2->getHeight();
	Image * output = this->GetOutput();
	output->ResetSize(width, newHeight);
	Pixel* topBuff = this->input1->getBuffer();
	Pixel* bottomBuff = this->input2->getBuffer();
	Pixel* outBuff = output->getBuffer();
	
	for (int r=0; r < newHeight; r++) {
		for (int c=0; c < width; c++) {
			if (r < topHeight) {
				outBuff[r*width+c] = topBuff[r*width+c];
			}
			else {
				outBuff[r*width+c] = bottomBuff[(r-topHeight)*width+c];
			}
		}
	}
}

Blender::Blender() {
	factor = 0.0;
}

Blender::Blender(float num) {
	factor = num;
}

void Blender::SetFactor(float num){
	factor = num;
}

void Blender::Execute(){
	Image* output = this->GetOutput();
	Pixel* in1Buff = this->input1->getBuffer();
	Pixel* in2Buff = this->input2->getBuffer();
	float remainder = 1-(this->factor);
	int width = this->input1->getWidth();
	int height = this->input1->getHeight();
	output->ResetSize(width, height);
	Pixel* outBuff = output->getBuffer();
	for (int r=0; r < height; r++) {
		for (int c =0; c < width; c++) {
			outBuff[r*width+c].r = ((in1Buff[r*width+c].r)*factor)+((in2Buff[r*width+c].r)*remainder);
			outBuff[r*width+c].g = ((in1Buff[r*width+c].g)*factor)+((in2Buff[r*width+c].g)*remainder);
			outBuff[r*width+c].b = ((in1Buff[r*width+c].b)*factor)+((in2Buff[r*width+c].b)*remainder);
		}
	}

}
