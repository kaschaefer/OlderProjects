#include <image.h>

#ifndef SOURCE_CLASS
#define SOURCE_CLASS

class Source{
private:
	Image theImg;
protected:
    virtual void Execute(void) =0;
	
public:
	Image * GetOutput();
	virtual void Update(void) =0;
    Source();
    ~Source(){;};
};

#endif
