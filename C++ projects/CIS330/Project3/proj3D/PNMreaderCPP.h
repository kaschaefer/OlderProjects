#include <source.h>

#ifndef PNM_READER_CPP_CLASS
#define PNM_READER_CPP_CLASS
class PNMreaderCPP : public Source {
private:
	char* file;
public:
	PNMreaderCPP();
	PNMreaderCPP(char* filename);
	~PNMreaderCPP();
	virtual void Execute();
};
#endif
