#include <image.h>

Pixel& Pixel::operator=(Pixel &p) {
	this->r = p.r;
	this->g = p.g;
	this->b = p.b;
}

Image::Image() {
	this->width = 0;
	this->height = 0;
	pixel = nullptr;	
}

Image::Image(int w, int h) {
	width = w;
	height = h;
	pixel = new Pixel[width*height];
}

Image::Image(class Image &oldImg){
	this->width = oldImg.getWidth();
	this->height = oldImg.getHeight();
	this->pixel = new Pixel[width*height];
	memcpy(this->pixel, oldImg.getBuffer(), width*height*sizeof(Pixel));
}

Image::~Image(){
	if (pixel != nullptr) {
		delete [] pixel;
	}
}

void Image::ResetSize(int w, int h){
	width = w;
	height = h;
	delete [] pixel;
	this->pixel = new Pixel[w*h];
}


int Image::getWidth(){
	return width;
}

int Image::getHeight(){
	return height;
}

Pixel * Image::getBuffer(){
	return pixel;
}

