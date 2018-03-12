#include <image.h>

#ifndef SINK_CLASS
#define SINK_CLASS

class Sink{
protected:
	const Image * input1;
	const Image * input2;
public:
	Sink();
	~Sink() {;};
	void SetInput(Image* in);
	void SetInput2(Image* in);
};

#endif

