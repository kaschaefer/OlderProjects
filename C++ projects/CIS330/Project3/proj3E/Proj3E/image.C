#include <image.h>
#include <source.h>

Pixel& Pixel::operator=(Pixel &p) {
	this->r = p.r;
	this->g = p.g;
	this->b = p.b;
}


//Image Constructors

Image::Image() {
	this->width = 0;
	this->height = 0;
	pixel = nullptr;
    imgSource = nullptr;
}

Image::Image(int w, int h) {
	width = w;
	height = h;
	pixel = new Pixel[width*height];
    imgSource = nullptr;
}

Image::Image(Source* aSource) {
    this->imgSource = aSource;
    width = 0;
    height = 0;
    pixel = nullptr;
}

Image::Image(class Image &oldImg){
	this->width = oldImg.getWidth();
	this->height = oldImg.getHeight();
	this->pixel = new Pixel[width*height];
	memcpy(this->pixel, oldImg.getBuffer(), width*height*sizeof(Pixel));
}

//Image Destructor

Image::~Image(){
	if (pixel != nullptr) {
		delete [] pixel;
	}
}

//Mutators

void Image::ResetSize(int w, int h){
	width = w;
	height = h;
    if (pixel != nullptr) {
        delete [] pixel;
    }
	this->pixel = new Pixel[w*h];
}

void Image::Update(){
    if (imgSource != nullptr){
        imgSource->Update();
    }
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

