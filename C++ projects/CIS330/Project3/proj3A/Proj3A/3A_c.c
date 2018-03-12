#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
} Pixel;

typedef struct
{
   Pixel *pixel;
   int width;
   int height;
} Image;

Image * 
ReadImage(char *filename)
{
	int r, c;
	int width, height, maxval;
	FILE *f_in;
	char magicNum[128];
	f_in = fopen(filename, "r");
	Image *myImg;

	f_in = fopen(filename, "r");
	myImg = (Image *) malloc(sizeof(Image));
	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
	if (f_in != NULL) {
		myImg->width = width;
		myImg->height = height;
		myImg->pixel = malloc(width*height*sizeof(Pixel));
		//Loop over columns and rows and get dem pixels
		for (r=0; r < height; r++) {
			for(c=0; c<width; c++) {
				fread(&(myImg->pixel[r*width+c].r), sizeof(unsigned char), 1, f_in);
				fread(&(myImg->pixel[r*width+c].g), sizeof(unsigned char), 1, f_in);
				fread(&(myImg->pixel[r*width+c].b), sizeof(unsigned char), 1, f_in);		
			}
		}
	}
	fclose(f_in);
	return myImg;
}



void WriteImage(Image *img, char *filename)
{
	FILE *f_out;
	int width, height, maxval;
	char magicNum[128] = "P6";
	int r, c;
	
	width = img->width;
	f_out = fopen(filename, "w");
	height = img->height;
	maxval = 255;
	
	if (f_out != NULL) {
	fprintf(f_out, "%s\n%d %d\n%d\n", magicNum, width, height, maxval);
	for (r=0; r < height; r++) {
		for (c=0; c < width; c++) {
			fwrite(&(img->pixel[r*width+c].r), sizeof(unsigned char), 1, f_out);
			fwrite(&(img->pixel[r*width+c].g), sizeof(unsigned char), 1, f_out);
			fwrite(&(img->pixel[r*width+c].b), sizeof(unsigned char), 1, f_out);		
		}
	}
	}//endif	
}

Image *
YellowDiagonal(Image *input)
{
	int width, height, r, c;
	Image * newImg;

	newImg = (Image *) malloc(sizeof(Image));
	newImg->width = input->width;
	newImg->height = input->height;
	height = newImg->height;
	width = newImg->width;
	newImg->pixel = malloc(width*height*sizeof(Pixel));
	for (r=0; r < height; r++) {
		for(c=0; c < width; c++) {
			if (r == c) {
				newImg->pixel[r*width+c].r = 255;
				newImg->pixel[r*width+c].g = 255;
				newImg->pixel[r*width+c].b = 0;
			}
			else{
				newImg->pixel[r*width+c].r = input->pixel[r*width+c].r;
				newImg->pixel[r*width+c].g = input->pixel[r*width+c].g;
				newImg->pixel[r*width+c].b = input->pixel[r*width+c].b;
			}
		}
	}
	return newImg;
}

int main(int argc, char *argv[])
{
   /* Read an image, apply yellow diagonal to it, then write*/
	Image * img;
	Image * yellowImg;
	img = ReadImage(argv[1]);
	yellowImg = YellowDiagonal(img);
	free(img);
	WriteImage(yellowImg, argv[2]);
	free(yellowImg);
	return 0;	
}
