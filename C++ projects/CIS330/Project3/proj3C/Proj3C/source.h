#include <image.h>

#ifndef SOURCE_CLASS
#define SOURCE_CLASS

class Source{
private:
	Image theImg;
	
public:
	Image * GetOutput();
	virtual void Execute(void) =0;
};

#endif
