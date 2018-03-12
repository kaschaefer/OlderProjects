#include <source.h>

#ifndef PNM_READER_CLASS
#define PNM_READER_CLASS
class PNMreader : public Source {
private:
	char* file;	
public:
	PNMreader();
	PNMreader(char* filename);
	~PNMreader();
	virtual void Execute();
    virtual void Update();

};
#endif
