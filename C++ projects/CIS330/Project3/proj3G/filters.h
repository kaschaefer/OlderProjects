#include <image.h>
#include <sink.h>
#include <source.h>

#ifndef FILTER_CLASS
#define FILTER_CLASS
class Filter : public Source, public Sink {
public:
	Filter(){;};
	~Filter(){;};
        virtual void Update(void);
	virtual const char* FilterName(void) = 0;
};
#endif

#ifndef CHECK_SUM_CLASS
#define CHECK_SUM_CLASS
class CheckSum : public Sink {
public:
	CheckSum(){;};
	~CheckSum(){;};
	void OutputCheckSum(const char* file);
};
#endif

#ifndef CONSTANT_COLOR_CLASS
#define CONSTANT_COLOR_CLASS
class Color : public Source {
private:
	int width;
	int height;
	unsigned char r;
	unsigned char g;
	unsigned char b;
public:
	Color();
	Color(int w, int h, unsigned char red, unsigned char green, unsigned char blue);
	~Color(){;};
	virtual void Execute(void);
	virtual void Update(void);
};
#endif

#ifndef SHRINKER_CLASS
#define SHRINKER_CLASS
class Shrinker : public Filter {
private:
	const char* filterName;
public:
	Shrinker();
	~Shrinker(){;};
	virtual void Execute(void);
	virtual const char* FilterName(void) {return this->filterName;};
};
#endif

#ifndef LRCONCAT_CLASS
#define LRCONCAT_CLASS
class LRConcat : public Filter {
private:
	const char* filterName;
public:
	LRConcat();
	~LRConcat(){;};
	virtual void Execute(void);
	virtual const char* FilterName(void) {return this->filterName;};

};
#endif

#ifndef TBCONCAT_CLASS
#define TBCONCAT_CLASS
class TBConcat : public Filter {
private:
	const char* filterName;

public:
	TBConcat();
	~TBConcat(){;};
	virtual void Execute(void);
	virtual const char* FilterName(void) {return this->filterName;};

};
#endif

#ifndef BLENDER_CLASS
#define BLENDER_CLASS
class Blender : public Filter {
private:
	float factor;
	const char* filterName;
public:
	Blender();
	Blender(float num);
	~Blender(){;};
	void SetFactor(float num);
	virtual void Execute(void);
	virtual const char* FilterName(void) {return this->filterName;};

};
#endif

#ifndef MIRROR_CLASS
#define MIRROR_CLASS
class Mirror : public Filter {
private:
	const char* filterName;
public:
	Mirror();
	~Mirror(){;};
	virtual void Execute(void);
	virtual const char* FilterName(void) {return this->filterName;};
};
#endif

#ifndef ROTATE_CLASS
#define ROTATE_CLASS
class Rotate : public Filter {
private:
	const char* filterName;
public:
	Rotate();
	~Rotate(){;};
	virtual void Execute(void);
	virtual const char* FilterName(void) {return this->filterName;};


};
#endif

#ifndef SUBTRACT_CLASS
#define SUBTRACT_CLASS
class Subtract : public Filter {
private:
	const char* filterName;
public:
	Subtract();
	~Subtract(){;};
	virtual void Execute(void);
	virtual const char* FilterName(void) {return this->filterName;};
};
#endif

#ifndef GRAYSCALE_CLASS
#define GRAYSCALE_CLASS
class Grayscale : public Filter {
private:
	const char* filterName;
public:
	Grayscale();
	~Grayscale(){;};
	virtual void Execute(void);
	virtual const char* FilterName(void) {return this->filterName;};
};
#endif

#ifndef BLUR_CLASS
#define BLUR_CLASS
class Blur : public Filter {
private:
	const char* filterName;
public:
	Blur();
	~Blur(){;};
	virtual void Execute(void);
	virtual const char* FilterName(void) {return this->filterName;};
};
#endif

