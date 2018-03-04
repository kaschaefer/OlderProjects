/* This file should *contain the 9 functions defined in prototypes.h */

#include <prototypes.h>

void InitializeCircle(struct Shape *c, double radius, double origin, double originY){
	c->type = circle;
	c->ft.GetArea = &GetCircleArea;
	c->ft.GetBoundingBox = &GetCircleBoundingBox;
	c->shape.c.radius = radius;
	c->shape.c.origin = origin;
	c->shape.c.originY = originY;
	c->shape.c.area = 3.14159*radius*radius;
}
void InitializeRectangle(struct Shape *r, double minX, double maxX, double minY, double maxY){
	r->type = rectangle;
	r->ft.GetArea = &GetRectangleArea;
	r->ft.GetBoundingBox = &GetRectangleBoundingBox;	
	r->shape.r.minX = minX;
	r->shape.r.maxX = maxX;
	r->shape.r.minY = minY;
	r->shape.r.maxY = maxY;
	r->shape.r.area = (maxX-minX)*(maxY-minY);
}
void InitializeTriangle(struct Shape *t, double pt1X, double pt2X, double minY, double maxY){
	t->type = triangle;      
    	t->ft.GetArea = &GetTriangleArea; 
    	t->ft.GetBoundingBox = &GetTriangleBoundingBox;    
    	t->shape.t.pt1X = pt1X;
    	t->shape.t.pt2X = pt2X;
    	t->shape.t.minY = minY;
    	t->shape.t.maxY = maxY;
    	t->shape.t.area = (pt2X-pt1X)*(maxY-minY)/2;
}

double GetCircleArea(struct Shape *c){
	return c->shape.c.area;
}
double GetRectangleArea(struct Shape *r){
	return r->shape.r.area;
}
double GetTriangleArea(struct Shape *t){
	return t->shape.t.area;
}

void GetCircleBoundingBox(struct Shape *c, double *bbox){
	bbox[0] = (c->shape.c.origin) - (c->shape.c.radius);
	bbox[1] = (c->shape.c.origin) + (c->shape.c.radius);
	bbox[2] = (c->shape.c.originY) - (c->shape.c.radius);
	bbox[3] = (c->shape.c.originY) + (c->shape.c.radius);
}
void GetRectangleBoundingBox(struct Shape *r, double *bbox){
	bbox[0] = r->shape.r.minX;
	bbox[1] = r->shape.r.maxX;
	bbox[2] = r->shape.r.minY;
	bbox[3] = r->shape.r.maxY;
}
void GetTriangleBoundingBox(struct Shape *t, double *bbox){
	bbox[0] = t->shape.t.pt1X;
	bbox[1] = t->shape.t.pt2X;
	bbox[2] = t->shape.t.minY;
	bbox[3] = t->shape.t.maxY;
}
