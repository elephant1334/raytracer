#include "SingleSphere.h"
#include "World.h"
#include "ShadeRec.h"

SingleSphere::SingleSphere():Tracer(){}

SingleSphere::SingleSphere(World* _worldPtr):Tracer(_worldPtr){}
SingleSphere::~SingleSphere(){}

RGBColor SingleSphere::trace_ray(const Ray& ray)const{
	ShadeRec sr(*world_ptr);
	double t;
//如果与光线相交，返回红色，否则返回黑色
	if(world_ptr->sphere.hit(ray,t,sr))
		return (red);
	else 
		return (black);
}