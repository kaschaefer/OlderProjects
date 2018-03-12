#include "PNMreader.h"

PNMreader::PNMreader(){
	file = nullptr;
}

PNMreader::PNMreader(char* filename) {
	file = new char[128];
	strcpy(file, filename);
}

PNMreader::~PNMreader(){
	if (file != nullptr){
		delete file;
	}
}

void PNMreader::Execute(){
	//Read info from the file, put it in the source image
	int width=0;
	int height=0;
	int maxval=0;
	Image * img = GetOutput();
	FILE *f_in = fopen(this->file, "r");
	char magicNum[128];
	if (f_in != NULL) {
		fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
		img->ResetSize(width, height);
		fread(img->getBuffer(), sizeof(Pixel)*width*height, 1, f_in);
	}
	fclose(f_in);
}

void PNMreader::Update(){
    this->Execute();
}
