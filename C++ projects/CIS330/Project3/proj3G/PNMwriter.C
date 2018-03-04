 #include <PNMwriter.h>

void PNMwriter::Write(char* file){
	const Image* output = this->input1;  
	int width = output->getWidth();
	int height = output->getHeight();
	char magicNum[128] = "P6";
	int maxval = 255;
	FILE *f_out = fopen(file, "w");
	if (f_out == NULL) {
		char msg[1024];
		sprintf(msg, "Output file did not open correctly");
		Logger::LogEvent(msg);
	}
	else if (output == nullptr) {
		char msg[1024];
		sprintf(msg, "Output img was not initialized correctly");
		Logger::LogEvent(msg);

	}
	else if (width <= 0) {
		char msg[1024];
		sprintf(msg, "Output img has an incorrect width");
		Logger::LogEvent(msg);
	}
	else if (height <= 0) {
		char msg[1024];
		sprintf(msg, "Output img has an incorrect height");
		Logger::LogEvent(msg);
	}

	else {
		fprintf(f_out, "%s\n%d %d\n%d\n", magicNum, width, height, maxval);
		fwrite(output->getBuffer(), sizeof(Pixel)*width*height, 1, f_out);
	}
	fclose(f_out);
};
