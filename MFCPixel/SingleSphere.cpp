#include "SingleSphere.h"
#include "World.h"
#include "ShadeRec.h"

SingleSphere::SingleSphere():Tracer(){}

SingleSphere::SingleSphere(World* _worldPtr):Tracer(_worldPtr){}
SingleSphere::~SingleSphere(){}

RGBColor SingleSphere::trace_ray(const Ray& ray)const{
	ShadeRec sr(*world_ptr);
	double t;
//���������ཻ�����غ�ɫ�����򷵻غ�ɫ
	if(world_ptr->sphere.hit(ray,t,sr))
		return (red);
	else 
		return (black);
}