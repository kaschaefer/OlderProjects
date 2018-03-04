#include <filters.h>

using namespace std;

//Filter Methods
void Filter::Update(void) {
    char msg[128];
    if (input1 != nullptr) {
	sprintf(msg, "%s: about to update input1", FilterName());
	Logger::LogEvent(msg);
	input1->Update();
	sprintf(msg, "%s: done updating input1", FilterName());
    Logger::LogEvent(msg);
    }
    if (input2 != nullptr) {
	sprintf(msg, "%s: about to update input2", FilterName());
	Logger::LogEvent(msg);
	input2->Update();
	sprintf(msg, "%s: done updating input2", FilterName());
    Logger::LogEvent(msg);
    }
 //   if (this != nullptr) {
    sprintf(msg, "%s: about to execute", FilterName());
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "%s: done executing", FilterName());
	Logger::LogEvent(msg);
 //   }
}

//Shrinker Methods

Shrinker::Shrinker(){
	filterName = "Shrinker";
}

void Shrinker::Execute(void) {
	const Image* in = this->input1;
	Image* out = this->GetOutput();
    if (in == nullptr){
        char msg[1024];
        sprintf(msg, "%s: no input!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (out == nullptr) {
        char msg[1024];
        sprintf(msg, "%s: no output!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    else {
        int width = in->getWidth()/2;
        int height = in->getHeight()/2;
        if (width < 0) {
            char msg[1024];
            sprintf(msg, "%s: Image width is not initialized correctly, width is %d", FilterName(), width);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (height < 0) {
            char msg[1024];
            sprintf(msg, "%s: Image height is not initialized correctly, height is %d", FilterName(), height);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else {
            out->ResetSize(width, height);
            Pixel * inBuff = in->getBuffer();
            Pixel * outBuff = out->getBuffer();
            
            if (inBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Input Buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            else if (outBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Output buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            else {
		int inputWidth = in->getWidth();
                for (int r=0; r<height; r++) {
                    for (int c=0; c < width; c++) {
                        outBuff[r*width+c] = inBuff[2*r*inputWidth+2*c];
                    }
                }
            }
        }
    }
}

//LRConcat Methods

LRConcat::LRConcat(){
	filterName = "LRConcat";
}


void LRConcat::Execute(void) {
    const Image* in1 = this->input1;
    const Image* in2 = this->input2;
    Image* output = this->GetOutput();
    if (in1 == nullptr){
        char msg[1024];
        sprintf(msg, "%s: no input1!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (in2 == nullptr){
        char msg[1024];
        sprintf(msg, "%s: no input2!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (output == nullptr) {
        char msg[1024];
        sprintf(msg, "%s: no output!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    else {
        int leftWidth = in1->getWidth();
        int rightWidth = in2->getWidth();
        int width = leftWidth+rightWidth;
        int in1Height = in1->getHeight();
        int in2Height = in2->getHeight();
        
        if (width < 0) {
            char msg[1024];
            sprintf(msg, "%s: Image width is %d", FilterName(), width);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (in1Height < 0) {
            char msg[1024];
            sprintf(msg, "%s: Input 1's height is %d", FilterName(), in1Height);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (in2Height < 0) {
            char msg[1024];
            sprintf(msg, "%s: Input 2's height is %d", FilterName(), in2Height);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (in1Height != in2Height) {
            char msg[1024];
            sprintf(msg, "%s: heights must match: %d, %d", FilterName(), in1Height, in2Height);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        
        else {
            output->ResetSize(width, in1Height);
            Pixel* outBuff = output->getBuffer();
            Pixel* in1Buff = this->input1->getBuffer();
            Pixel* in2Buff = this->input2->getBuffer();
            
            if (in1Buff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Input 1 Buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else if(in2Buff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Input 2 Buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else if (outBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Output buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else {
                for (int r =0; r < in1Height; r++) {
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
        }
    }

}

//TBConcat Methods

TBConcat::TBConcat(){
	filterName = "TBConcat";
}


void TBConcat::Execute(void) {
    const Image* in1 = this->input1;
    const Image* in2 = this->input2;
    Image* output = this->GetOutput();
    if (in1 == nullptr){
        char msg[1024];
        sprintf(msg, "%s: no input 1!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (in2 == nullptr){
        char msg[1024];
        sprintf(msg, "%s: no input 2!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (output == nullptr) {
        char msg[1024];
        sprintf(msg, "%s: no output!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    else {
        int in1Width = in1->getWidth();
        int in2Width = in2->getWidth();
        int topHeight = in1->getHeight();
        int bottomHeight = in2->getHeight();
        int newHeight = topHeight+bottomHeight;
        
        if (newHeight < 0) {
            char msg[1024];
            sprintf(msg, "%s: new Image height is %d", FilterName(), newHeight);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (in1Width < 0) {
            char msg[1024];
            sprintf(msg, "%s: Input 1's width is %d", FilterName(), in1Width);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (in2Width < 0) {
            char msg[1024];
            sprintf(msg, "%s: Input 2's width is %d", FilterName(), in2Width);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (in1Width != in2Width) {
            char msg[1024];
            sprintf(msg, "%s: widths must match: %d, %d", FilterName(), in1Width, in2Width);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        
        else {
            Image * output = this->GetOutput();
            output->ResetSize(in1Width, newHeight);
            Pixel* topBuff = in1->getBuffer();
            Pixel* bottomBuff = in2->getBuffer();
            Pixel* outBuff = output->getBuffer();
            
            
            if (topBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Input 1 Buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else if(bottomBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Input 2 Buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else if (outBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Output buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else {
                for (int r=0; r < newHeight; r++) {
                    for (int c=0; c < in1Width; c++) {
                        if (r < topHeight) {
                            outBuff[r*in1Width+c] = topBuff[r*in1Width+c];
                        }
                        else {
                            outBuff[r*in1Width+c] = bottomBuff[(r-topHeight)*in1Width+c];
                        }
                    }
                }
            }
        }
    }
}

//Blender Methods

Blender::Blender() {
	filterName = "Blender";
	factor = 0.0;
}

Blender::Blender(float num) {
	filterName = "Blender";
	factor = num;
}

void Blender::SetFactor(float num){
	factor = num;
}

void Blender::Execute(){
    const Image* in1 = this->input1;
    const Image* in2 = this->input2;
    Image* output = this->GetOutput();
    
    //Check for Valid Image Pointers
    if (in1 == nullptr){
        char msg[1024];
        sprintf(msg, "%s: no input 1!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (in2 == nullptr){
        char msg[1024];
        sprintf(msg, "%s: no input 2!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (output == nullptr) {
        char msg[1024];
        sprintf(msg, "%s: no output!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    
    else {
        float remainder = 1-(this->factor);
        int width = in1->getWidth();
        int height = in1->getHeight();
        int in2Width = in2->getWidth();
        int in2Height = in2->getHeight();
        
        //Check for valid nums
        if (width != in2Width) {
            char msg[1024];
            sprintf(msg, "%s: Widths must match %d, %d", FilterName(), width, in2Width);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (height != in2Height) {
            char msg[1024];
            sprintf(msg, "%s: Heights must match %d, %d", FilterName(), height, in2Height);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (height <= 0) {
            char msg[1024];
            sprintf(msg, "%s: Input's height is %d", FilterName(), height);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (width <= 0) {
            char msg[1024];
            sprintf(msg, "%s: Input's width is %d", FilterName(), width);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (this->factor >= 1) {
            char msg[1024];
            sprintf(msg, "Invalid factor for Blender: %f", this->factor);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else {
            Pixel* in1Buff = in1->getBuffer();
            Pixel* in2Buff = in2->getBuffer();
            output->ResetSize(width, height);
            Pixel* outBuff = output->getBuffer();
            
            //Check for valid buffers
            
            if (in1Buff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Input 1 Buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else if(in2Buff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Input 2 Buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else if (outBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Output buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else {
                for (int r=0; r < height; r++) {
                    for (int c =0; c < width; c++) {
                        outBuff[r*width+c].r = ((in1Buff[r*width+c].r)*factor)+((in2Buff[r*width+c].r)*remainder);
                        outBuff[r*width+c].g = ((in1Buff[r*width+c].g)*factor)+((in2Buff[r*width+c].g)*remainder);
                        outBuff[r*width+c].b = ((in1Buff[r*width+c].b)*factor)+((in2Buff[r*width+c].b)*remainder);
                    }
                }
            }
        }
    }

}

//Mirror Methods

Mirror::Mirror() {
	filterName = "Mirror";
}

void Mirror::Execute(void) {
    const Image* in = this->input1;
    Image* output = this->GetOutput();
    
    //Check for Valid Image Pointers
    if (in == nullptr){
        char msg[1024];
        sprintf(msg, "%s: no input 1!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    
    if (output == nullptr) {
        char msg[1024];
        sprintf(msg, "%s: no output!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    
    else {
        int width = in->getWidth();
        int height = in->getHeight();
        
        //Check for valid nums
        if (height <= 0) {
            char msg[1024];
            sprintf(msg, "%s: Input's height is %d", FilterName(), height);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (width <= 0) {
            char msg[1024];
            sprintf(msg, "%s: Input's width is %d", FilterName(), width);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
	
        else {
            Pixel* inBuff = in->getBuffer();
            output->ResetSize(width, height);
            Pixel* outBuff = output->getBuffer();
            
            //Check for valid buffers
            
            if (inBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Input 1 Buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else if (outBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Output buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else {
                for (int r=0; r < height; r++) {
                    for (int c =0; c < width; c++) {
			outBuff[r*width+c] = inBuff[r*width+(width-c-1)];				                       
                    }
                }
            }
        }
    }
}

//Rotate Methods

Rotate::Rotate() {
	filterName = "Rotate";
}

void Rotate::Execute(void) {
    const Image* in = this->input1;
    Image* output = this->GetOutput();
    
    //check for valid Image pointers
    if (in == nullptr){
        char msg[1024];
        sprintf(msg, "%s: no input 1!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    
    if (output == nullptr) {
        char msg[1024];
        sprintf(msg, "%s: no output!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    
    else {
        int height = in->getWidth();
        int width = in->getHeight();
	int inputWidth = height;
        //check for valid nums
        if (height <= 0) {
            char msg[1024];
            sprintf(msg, "%s: input's height is %d", FilterName(), height);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (width <= 0) {
            char msg[1024];
            sprintf(msg, "%s: input's width is %d", FilterName(), width);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
	
        else {
            Pixel* inbuff = in->getBuffer();
            output->ResetSize(width, height);
            Pixel* outbuff = output->getBuffer();
            
            //check for valid buffers
            
            if (inbuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: input 1 buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else if (outbuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: output buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else {
                for (int r=0; r < height; r++) {
                    for (int c =0; c < width; c++) {
			outbuff[r*width+c]=inbuff[c*inputWidth+r];		
                    }
                }
            }
        }
    }
}

//Subtract Methods

Subtract::Subtract(){
	filterName = "Subtract";
}

void Subtract::Execute(void){
    const Image* in1 = this->input1;
    const Image* in2 = this->input2;
    Image* output = this->GetOutput();
    
    //Check for Valid Image Pointers
    if (in1 == nullptr){
        char msg[1024];
        sprintf(msg, "%s: no input 1!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (in2 == nullptr){
        char msg[1024];
        sprintf(msg, "%s: no input 2!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (output == nullptr) {
        char msg[1024];
        sprintf(msg, "%s: no output!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    
    else {
        int width = in1->getWidth();
        int height = in1->getHeight();
        int in2Width = in2->getWidth();
        int in2Height = in2->getHeight();
        
        //Check for valid nums
        if (width != in2Width) {
            char msg[1024];
            sprintf(msg, "%s: Widths must match %d, %d", FilterName(), width, in2Width);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (height != in2Height) {
            char msg[1024];
            sprintf(msg, "%s: Heights must match %d, %d", FilterName(), height, in2Height);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (height <= 0) {
            char msg[1024];
            sprintf(msg, "%s: Input's height is %d", FilterName(), height);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (width <= 0) {
            char msg[1024];
            sprintf(msg, "%s: Input's width is %d", FilterName(), width);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else {
            Pixel* in1Buff = in1->getBuffer();
            Pixel* in2Buff = in2->getBuffer();
            output->ResetSize(width, height);
            Pixel* outBuff = output->getBuffer();
            
            //Check for valid buffers
            
            if (in1Buff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Input 1 Buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else if(in2Buff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Input 2 Buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else if (outBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Output buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else {
                for (int r=0; r < height; r++) {
                    for (int c =0; c < width; c++) {
                        outBuff[r*width+c].r = ((in1Buff[r*width+c].r)%256 < (in2Buff[r*width+c].r)%256) ? 0 : (in1Buff[r*width+c].r)%256-(in2Buff[r*width+c].r)%256;
                        outBuff[r*width+c].g = ((in1Buff[r*width+c].g)%256 < (in2Buff[r*width+c].g)%256) ? 0 : (in1Buff[r*width+c].g)%256-(in2Buff[r*width+c].g)%256;
                        outBuff[r*width+c].b = ((in1Buff[r*width+c].b)%256 < (in2Buff[r*width+c].b)%256) ? 0 : (in1Buff[r*width+c].b)%256-(in2Buff[r*width+c].b)%256;
                    }
                }
            }
        }
    }
}

//Grayscale Methods
Grayscale::Grayscale(){
	filterName = "Grayscale";
}

void Grayscale::Execute(void){
    const Image* in = this->input1;
    Image* output = this->GetOutput();
    
    //check for valid Image pointers
    if (in == nullptr){
        char msg[1024];
        sprintf(msg, "%s: no input 1!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    
    if (output == nullptr) {
        char msg[1024];
        sprintf(msg, "%s: no output!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    
    else {
        int width = in->getWidth();
        int height = in->getHeight();
        //check for valid nums
        if (height <= 0) {
            char msg[1024];
            sprintf(msg, "%s: input's height is %d", FilterName(), height);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (width <= 0) {
            char msg[1024];
            sprintf(msg, "%s: input's width is %d", FilterName(), width);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
	
        else {
            Pixel* inBuff = in->getBuffer();
            output->ResetSize(width, height);
            Pixel* outBuff = output->getBuffer();
            
            //check for valid buffers
            
            if (inBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: input 1 buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else if (outBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: output buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else {
                for (int r=0; r < height; r++) {
                    for (int c =0; c < width; c++) {
			outBuff[r*width+c].r = (inBuff[r*width+c].r)/5 + (inBuff[r*width+c].g)/2 + (inBuff[r*width+c].b)/4;		
                	outBuff[r*width+c].g = (inBuff[r*width+c].r)/5 + (inBuff[r*width+c].g)/2 + (inBuff[r*width+c].b)/4;
			outBuff[r*width+c].b = (inBuff[r*width+c].r)/5 + (inBuff[r*width+c].g)/2 + (inBuff[r*width+c].b)/4;
		    }
                }
            }
        }
    }
}

//Blur Methods
Blur::Blur(){
	filterName = "Blur";
}

void Blur::Execute(void){
    const Image* in1 = this->input1;
    const Image* in2 = this->input2;
    Image* output = this->GetOutput();
    
    //Check for Valid Image Pointers
    if (in1 == nullptr){
        char msg[1024];
        sprintf(msg, "%s: no input 1!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (output == nullptr) {
        char msg[1024];
        sprintf(msg, "%s: no output!", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    
    else {
        int width = in1->getWidth();
        int height = in1->getHeight();
        
        //Check for valid nums
        if (height <= 0) {
            char msg[1024];
            sprintf(msg, "%s: Input's height is %d", FilterName(), height);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else if (width <= 0) {
            char msg[1024];
            sprintf(msg, "%s: Input's width is %d", FilterName(), width);
            DataFlowException e(FilterName(), msg);
            throw e;
        }
        else {
            Pixel* inBuff = in1->getBuffer();
            output->ResetSize(width, height);
            Pixel* outBuff = output->getBuffer();
            
            //Check for valid buffers
            
            if (inBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Input 1 Buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else if (outBuff == nullptr) {
                char msg[1024];
                sprintf(msg, "%s: Output buffer is not initialized correctly", FilterName());
                DataFlowException e(FilterName(), msg);
                throw e;
            }
            
            else {
                for (int r=0; r < height; r++) {
                    for (int c =0; c < width; c++) {
			if (r == 0 || c == 0 || r+1 == height || c+1 == width) {
				outBuff[r*width+c].r = inBuff[r*width+c].r;
				outBuff[r*width+c].g = inBuff[r*width+c].g;
				outBuff[r*width+c].b = inBuff[r*width+c].b;
			}
			else{
                        outBuff[r*width+c].r = (inBuff[(r-1)*width+(c-1)].r)/8 + (inBuff[(r-1)*width+c].r)/8 + (inBuff[(r-1)*width+(c+1)].r)/8 + (inBuff[r*width+(c-1)].r)/8 + (inBuff[r*width+(c+1)].r)/8 + (inBuff[(r+1)*width+(c-1)].r)/8 + (inBuff[(r+1)*width+c].r)/8 + (inBuff[(r+1)*width+(c+1)].r)/8; 
                        outBuff[r*width+c].g = (inBuff[(r-1)*width+(c-1)].g)/8 + (inBuff[(r-1)*width+c].g)/8 + (inBuff[(r-1)*width+(c+1)].g)/8 + (inBuff[r*width+(c-1)].g)/8 + (inBuff[r*width+(c+1)].g)/8 + (inBuff[(r+1)*width+(c-1)].g)/8 + (inBuff[(r+1)*width+c].g)/8 + (inBuff[(r+1)*width+(c+1)].g)/8;
                        outBuff[r*width+c].b = (inBuff[(r-1)*width+(c-1)].b)/8 + (inBuff[(r-1)*width+c].b)/8 + (inBuff[(r-1)*width+(c+1)].b)/8 + (inBuff[r*width+(c-1)].b)/8 + (inBuff[r*width+(c+1)].b)/8 + (inBuff[(r+1)*width+(c-1)].b)/8 + (inBuff[(r+1)*width+c].b)/8 + (inBuff[(r+1)*width+(c+1)].b)/8;
                	}    
		}
                }
            }
        }
    }
}


//Color Methods
Color::Color(){
	width = 0;
	height = 0;
	r = 0;
	g = 0;
	b = 0;
}

Color::Color(int w, int h, unsigned char red, unsigned char green, unsigned char blue){
	width = w;
	height = h;
	r = red;
	g = green;
	b = blue;
}

void Color::Update(void) {
	char msg[128];
	sprintf(msg, "%s: about to execute", "Color");
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "%s: done executing", "Color");
	Logger::LogEvent(msg);
}

void Color::Execute(void){
	Image * img = GetOutput();
	if (img == nullptr) {
		char msg[1024];
		sprintf(msg, "%s: Source image not initialized correctly", "Color");
		Logger::LogEvent(msg);
		DataFlowException e("Color", msg);
		throw e;
	}
	else if (this->width <= 0 || this->height <= 0 ) {
		char msg[1024];
		sprintf(msg, "%s: Source image's dimensions below 0", "Color");
		Logger::LogEvent(msg);
		DataFlowException e("Color", msg);
		throw e;
	}
	else {
		img->ResetSize(this->width, this->height);
		Pixel * buffer = img->getBuffer();
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				buffer[r*width+c].r = this->r;
				buffer[r*width+c].g = this->g;
				buffer[r*width+c].b = this->b;
			}
		}
	}
}

//CheckSum Methods
void CheckSum::OutputCheckSum(const char* file){
	const Image* output = this->input1;
	int width = output->getWidth();
	int height = output->getHeight();
	Pixel* buffer = output->getBuffer();
	unsigned char redSum = 0;
	unsigned char blueSum = 0;
	unsigned char greenSum = 0;
	for (int r =0; r< height; r++) {
		for (int c =0; c < width; c++) {
			redSum += buffer[r*width+c].r;
			greenSum += buffer[r*width+c].g;
			blueSum += buffer[r*width+c].b;
		}
	}
	FILE *f_out = fopen(file, "w");
	if (f_out == NULL) {
		char msg[1024];
		sprintf(msg, "CheckSum Output File did not open correctly");
		Logger::LogEvent(msg);
	}
	else {
		fprintf(f_out, "%s: %d, %d, %d\n", "CHECKSUM", redSum, greenSum, blueSum);
		fclose(f_out);
	}
}
