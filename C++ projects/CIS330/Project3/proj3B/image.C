#include <image.h>
#include <cstring>
#include <stdlib.h>

Image::Image(){
	this->width = 0;
	this->height = 0;
	pixel = NULL;
}

Image::Image(int w, int h){
	this->width = w;
	this->height = h;
}

Image::Image(Image &oldImg){
	this->width = oldImg.width;
	this->height = oldImg.height;
	this->pixel = (Pixel *) malloc((this->width)*(this->height)*sizeof(struct Pixel));
	memcpy(this->pixel, oldImg.pixel, (this->width)*(this->height)*sizeof(struct Pixel));
}

void Image::ResetSize(int width, int height){
	this->width = width;
	this->height = height;	
}
