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
		delete [] file;
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
	if (f_in == NULL) {
		char msg[1024];
		sprintf(msg, "PNMreader: Input File failed to open");
		Logger::LogEvent(msg);
		DataFlowException e("PNMreader", msg);
		throw e;
	}
	else if (img == nullptr) {
		char msg[1024];
		sprintf(msg, "PNMreader: Source image is nullptr");
		Logger::LogEvent(msg);
		DataFlowException e("PNMreader", msg);
		throw e;
	}
	else{
		fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
		if (strncmp(magicNum, "P6", 128) != 0){
			char msg[1024];
			sprintf(msg, "PNMreader: Input File Type is Incorrect");
			Logger::LogEvent(msg);
			DataFlowException e("PNMReader", msg);
			throw e;
		}
		else if (width <= 0) {
			char msg[1024];
			sprintf(msg, "PNMreader: Input File Width is bad");
			Logger::LogEvent(msg);
			DataFlowException e("PNMreader", msg);
			throw e;
		}
		else if (height <= 0) {
			char msg[1024];
			sprintf(msg, "PNMreader: Input File Height is bad");
			Logger::LogEvent(msg);
			DataFlowException e("PNMreader", msg);
			throw e;
		}
		else if (maxval != 255) {
			char msg[1024];
			sprintf(msg, "PNMreader: Input File Maxval is incorrect");
			Logger::LogEvent(msg);
			DataFlowException e("PNMreader", msg);
			throw e;
		}
		else {
			img->ResetSize(width, height);
			fread(img->getBuffer(), sizeof(Pixel)*width*height, 1, f_in);
		}
	}
	fclose(f_in);
}

void PNMreader::Update(){
    	char msg[1024];
	sprintf(msg, "PNMreader: about to execute");
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "PNMreader: done executing");
	Logger::LogEvent(msg);
}
