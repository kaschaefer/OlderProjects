#include <sink.h>

#ifndef PNM_WRITER_CLASS
#define PNM_WRITER_CLASS
class PNMwriter : public Sink {

public:
	PNMwriter() {;};
	~PNMwriter() {;};
	void Write(char* file);
};


#endif

