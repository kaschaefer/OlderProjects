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
};
#endif


#ifndef SHRINKER_CLASS
#define SHRINKER_CLASS
class Shrinker : public Filter {
public:
	Shrinker(){;};
	~Shrinker(){;};
	virtual void Execute(void);
};
#endif

#ifndef LRCONCAT_CLASS
#define LRCONCAT_CLASS
class LRConcat : public Filter {
public:
	LRConcat(){;};
	~LRConcat(){;};
	virtual void Execute(void);
};
#endif

#ifndef TBCONCAT_CLASS
#define TBCONCAT_CLASS
class TBConcat : public Filter {
public:
	TBConcat(){;};
	~TBConcat(){;};
	virtual void Execute(void);
};
#endif

#ifndef BLENDER_CLASS
#define BLENDER_CLASS
class Blender : public Filter {
private:
	float factor;
public:
	Blender();
	Blender(float num);
	~Blender(){;};
	void SetFactor(float num);
	virtual void Execute(void);
};
#endif

