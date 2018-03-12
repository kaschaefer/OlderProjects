#include <image.h>

#ifndef SINK_CLASS
#define SINK_CLASS

class Sink{
protected:
	Image * input1;
	Image * input2;
public:
	Sink();
	~Sink() {;};
	void SetInput(Image* in);
	void SetInput2(Image* in);
};

#endif

