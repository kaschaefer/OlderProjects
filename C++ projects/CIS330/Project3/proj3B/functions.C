#include <functions.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ReadImage(char *filename, Image &output) {
	int width=0;
	int height=0;
	int maxval=0;
	FILE *f_in = fopen(filename, "r");
	char magicNum[128];
	if (f_in != NULL) {
		fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
		output.ResetSize(width, height);
		output.pixel = (Pixel *) malloc(width*height*sizeof(Pixel));
		fread(output.pixel, sizeof(Pixel)*width*height, 1, f_in);
	}
	fclose(f_in);
}

void WriteImage(char *filename, Image &img) {
	int width= img.getWidth();
	int height= img.getHeight();
	char magicNum[128] = "P6";
	int maxval = 255;
	FILE *f_out = fopen(filename, "w");
	if (f_out != NULL) {
		fprintf(f_out, "%s\n%d %d\n%d\n", magicNum, width, height, maxval);
		fwrite(img.pixel, sizeof(Pixel)*width*height, 1, f_out);
	}
	fclose(f_out);
}

void HalveInSize(Image &input, Image &output) {
	int width = input.getWidth()/2;
	int height = input.getHeight()/2;
	output.ResetSize(width, height);
	output.pixel = (Pixel *) malloc(width*height*sizeof(Pixel));
	//So now output is half the size of input.
	for (int r = 0; r < height*2; r = r+2) {
		for (int c = 0; c < width; c++) {
		output.pixel[(r/2)*width+c].r = input.pixel[2*(r*width+c)].r;
		output.pixel[(r/2)*width+c].g = input.pixel[2*(r*width+c)].g;
		output.pixel[(r/2)*width+c].b = input.pixel[2*(r*width+c)].b;
		}
	}
}

void LeftRightConcatenate(Image &leftInput, Image &rightinput, Image &output){
	output.ResetSize(leftInput.getWidth()+rightinput.getWidth(), leftInput.getHeight());
	int width = output.getWidth();
	output.pixel = (Pixel *) malloc(width*output.getHeight()*sizeof(Pixel));
	int leftW = leftInput.getWidth();
	int rightW = rightinput.getWidth();
	for (int r =0; r < output.getHeight(); r++) {
		for(int c=0; c < width; c++) {
			if (c < leftW) {
			output.pixel[r*width+c].r = leftInput.pixel[r*leftW+c].r;
			output.pixel[r*width+c].g = leftInput.pixel[r*leftW+c].g;
			output.pixel[r*width+c].b = leftInput.pixel[r*leftW+c].b;
			}
			else {
			output.pixel[r*width+c].r = rightinput.pixel[r*rightW+(c-leftW)].r;
			output.pixel[r*width+c].g = rightinput.pixel[r*rightW+(c-leftW)].g;
			output.pixel[r*width+c].b = rightinput.pixel[r*rightW+(c-leftW)].b;
			}
		}
	}
}

void TopBottomConcatenate(Image &topInput, Image &bottomInput, Image &output){
	int width = topInput.getWidth();
	int newHeight = topInput.getHeight()+bottomInput.getHeight();
	int topH = topInput.getHeight();
	output.ResetSize(width, newHeight);
	output.pixel = (Pixel *) malloc(width*newHeight*sizeof(Pixel));
	for (int r=0; r < newHeight; r++) {
		for(int c=0; c < width; c++) {
			if (r < topInput.getHeight()) {
			output.pixel[r*width+c].r = topInput.pixel[r*width+c].r;
			output.pixel[r*width+c].g = topInput.pixel[r*width+c].g;
			output.pixel[r*width+c].b = topInput.pixel[r*width+c].b;
			}
			else {
			output.pixel[r*width+c].r = bottomInput.pixel[(r-topH)*width+c].r;
			output.pixel[r*width+c].g = bottomInput.pixel[(r-topH)*width+c].g;
			output.pixel[r*width+c].b = bottomInput.pixel[(r-topH)*width+c].b;
			}
		}
	}
}

void Blend(Image &input1, Image &input2, float factor, Image &output){
	int width = input1.getWidth();
	int height = input1.getHeight();
	float remainder = 1-factor;
	output.ResetSize(width, height);
	output.pixel = (Pixel *) malloc(width*height*sizeof(Pixel));
	for (int r=0; r < height; r++) {
		for (int c=0; c< width; c++) {
			output.pixel[r*width+c].r = ((input1.pixel[r*width+c].r)*factor)+((input2.pixel[r*width+c].r)*remainder);
			output.pixel[r*width+c].g = ((input1.pixel[r*width+c].g)*factor)+((input2.pixel[r*width+c].g)*remainder);
			output.pixel[r*width+c].b = ((input1.pixel[r*width+c].b)*factor)+((input2.pixel[r*width+c].b)*remainder);
		}
	}	
}




