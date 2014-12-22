#include "PointLight.h"
//构造函数
PointLight::PointLight():Light(),ls(1.0),color(1.0),location(0,1,0){}
//拷贝构造函数
PointLight::PointLight(const PointLight& pl):Light(),ls(pl.ls),color(pl.color),location(pl.location){}
//clone
Light* PointLight::clone()const{
	return (new PointLight(*this));
}
PointLight& PointLight::operator=(const PointLight& rhs){
if(this==&rhs)
	return (*this);
Light::operator=(rhs);
ls = rhs.ls;
color = rhs.color;
location = rhs.location;
}
PointLight::~PointLight(){}
Vector3D PointLight::get_direction(ShadeRec& sr){
return(location-sr.hit_point);
}
RGBColor PointLight::L(ShadeRec &sr){
	return (ls*color/(location.length()));
}
bool PointLight::in_shadow(const Ray& ray,const ShadeRec& sr)const{
    float t;
	int num_objects = sr.w.objects.size();
	float d = (location-ray.o).length();
	for(int j=0;j<num_objects;j++)
		if(sr.w.objects[j]->shadow_hit(ray,t)&&t<d)
			return(true);
	return(false);
}
