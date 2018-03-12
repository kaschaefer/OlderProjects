#include <sink.h>

#ifndef PNM_WRITER_CPP_CLASS
#define PNM_WRITER_CPP_CLASS
class PNMwriterCPP : public Sink {
public:
	PNMwriterCPP(){;};
	~PNMwriterCPP(){;};
	void Write(char* file);
};
#endif
