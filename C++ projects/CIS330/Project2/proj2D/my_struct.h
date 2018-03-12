/* This file should contain your struct definitions for Circle, Triangle, and 
  Rectangle */

typedef struct{
	double minX;
	double maxX;
	double minY;
	double maxY;
	double area;	
}Rectangle;

typedef struct{
	double radius;
	double origin;
	double originY;
	double area;	
}Circle;

typedef struct{
	double pt1X;
	double pt2X;
	double minY;
	double maxY;
	double area;		
}Triangle;

typedef union{
    Triangle t;
    Circle c;
    Rectangle r;
} ShapeUnion;

struct Shape;

typedef enum {
    triangle,
    circle,
    rectangle
} ShapeType;

typedef struct {
    double (*GetArea)(struct Shape *);
    void (*GetBoundingBox)(struct Shape *, double *);
} FunctionTable;

struct Shape {
    ShapeUnion shape;  
    ShapeType type;
    FunctionTable ft;
};
