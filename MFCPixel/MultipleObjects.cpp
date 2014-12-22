#include "MultipleObjects.h"
#include "World.h"
MultipleObjects::MultipleObjects():Tracer(){}
MultipleObjects::MultipleObjects(World* _worldPtr):Tracer(_worldPtr){}
MultipleObjects::~MultipleObjects(){}
RGBColor MultipleObjects::trace_ray(const Ray& ray)const{
ShadeRec sr(world_ptr->hit_bare_bones_objects(ray));
if(sr.hit_an_object)
	return (sr.color);
else
	return (world_ptr->background_color);
}