/* This file should *contain the 9 functions defined in prototypes.h */

#include <prototypes.h>

void InitializeCircle(Shape *c, double radius, double origin, double originY){
	c->radius = radius;
	c->origin = origin;
	c->originY = originY;
	c->area = 3.14159*radius*radius;
}
void InitializeRectangle(Shape *r, double minX, double maxX, double minY, double maxY){
	r->minX = minX;
	r->maxX = maxX;
	r->minY = minY;
	r->maxY = maxY;
	r->area = (maxX-minX)*(maxY-minY);
}
void InitializeTriangle(Shape *t, double pt1X, double pt2X, double minY, double maxY){
    struct Shape tri;      //Instantiate the Struct
    tri.type = triangle;   //initialize the ENUM
    tri.ft.GetArea = &GetTriangleArea;  //Initialize First Function Pointer
    tri.ft.GetBoundingBox = &GetTriangleBoundingBox;    //Initialize Second Pointer
    tri.shape.t.pt1X = pt1X;
	tri.shape.t.pt2X = pt2X;
	tri.shape.t.minY = minY;
	tri.shape.t.maxY = maxY;
	tri.shape.t.area = (pt2X-pt1X)*(maxY-minY)/2;
    t = &tri;
}

double GetCircleArea(Shape *c){
	return c->area;
}
double GetRectangleArea(Shape *r){
	return r->area;
}
double GetTriangleArea(Shape *t){
	return t->area;
}

void GetCircleBoundingBox(Shape *c, double *bbox){
	bbox[0] = c->origin - c->radius;
	bbox[1] = c->origin + c->radius;
	bbox[2] = c->originY - c->radius;
	bbox[3] = c->originY + c->radius;
}
void GetRectangleBoundingBox(Shape *r, double *bbox){
	bbox[0] = r->minX;
	bbox[1] = r->maxX;
	bbox[2] = r->minY;
	bbox[3] = r->maxY;
}
void GetTriangleBoundingBox(Shape *t, double *bbox){
	bbox[0] = t->pt1X;
	bbox[1] = t->pt2X;
	bbox[2] = t->minY;
	bbox[3] = t->maxY;
}
