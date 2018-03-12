 #include <PNMwriter.h>

void PNMwriter::Write(char* file){
	Image* output = this->input1;  
	int width = output->getWidth();
	int height = output->getHeight();
	char magicNum[128] = "P6";
	int maxval = 255;
	FILE *f_out = fopen(file, "w");
	if (f_out != NULL) {
		fprintf(f_out, "%s\n%d %d\n%d\n", magicNum, width, height, maxval);
		fwrite(output->getBuffer(), sizeof(Pixel)*width*height, 1, f_out);
	}
	fclose(f_out);
};
