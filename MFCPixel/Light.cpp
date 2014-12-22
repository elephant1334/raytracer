#include "Light.h"
#include "Constants.h"
Light::Light(){}
Light::Light(const Light& ls){}
Light& Light::operator=(const Light &rhs){
	if(this==&rhs)
		return(*this);
	return (*this);
}
Light::~Light(){}
RGBColor Light::L(ShadeRec& s){
return black;
}

bool Light::in_shadow(const Ray& ray,const ShadeRec& sr)const{
	return false;
}