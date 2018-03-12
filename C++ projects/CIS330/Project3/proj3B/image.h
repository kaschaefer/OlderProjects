#ifndef PIXEL_STRUCT_H
#define PIXEL_STRUCT_H
struct Pixel
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

#endif

#ifndef IMAGE_STRUCT_H
#define IMAGE_STRUCT_H
struct Image
{
//Member Variables
public:
	struct Pixel *pixel;
private:
    int width;
   	int height;

public:
//Member Functions
	Image(void);
	Image(int w, int h);
	Image(Image &);
	void ResetSize(int width, int height);
	int getWidth() { return this->width; }
	int getHeight(){ return this->height; }
};

#endif

