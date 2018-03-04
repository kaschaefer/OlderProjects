//**************   Header - All necessary libraries included here ************//
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
class Source;
//*************** End Header **********//

#ifndef PIXEL_CLASS
#define PIXEL_CLASS
class Pixel {
public:
	unsigned char r;
	unsigned char g;
	unsigned char b;
	Pixel &operator=(Pixel &p);
};
#endif

#ifndef IMAGE_CLASS
#define IMAGE_CLASS
class Image {
private:
	Pixel *pixel;
	int width;
	int height;
	Image(Image& newImg);
    Source* imgSource;
	
public:
	//Constructors
	Image(void);
    Image(Source* aSource);
	Image(int w, int h);
	~Image();
	//Accessors
	int getWidth();
	int getHeight();
	Pixel * getBuffer();
	//Mutators
	void ResetSize(int w, int h);
    virtual void Update(void);
};
#endif

