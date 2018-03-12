#include <source.h>

Source::Source() : theImg(this) {
    ;
}

Image * Source::GetOutput(){
	Image *img = &theImg;
	return img;
}
