#ifndef __POINT_LIGHT__
#define __POINT_LIGHT__

#include "Light.h"
#include "Vector3D.h"
#include "RGBColor.h"

#include "World.h"
#include "ShadeRec.h"
class PointLight:public Light{
public:
	PointLight();
	PointLight(const PointLight& pl);
	virtual Light* clone() const;
	PointLight& operator=(const PointLight& rhs);
	virtual ~PointLight();
	void scale_radiance(const float b);
	void set_color(const float c);
	void set_color(const RGBColor& c);
	void set_color(const float r,const float g,const float b);
	void set_location(Vector3D d);
	void set_location(float dx,float dy,float dz);
	virtual Vector3D get_direction(ShadeRec& sr);
	virtual RGBColor L(ShadeRec& sr);
	bool in_shadow(const Ray& ray,const ShadeRec& sr)const;
private:
	float ls;
	RGBColor color;
	Vector3D location;
};
inline void PointLight::scale_radiance(const float b){
ls=b;
}
inline void PointLight::set_color(const float c){
color.r=c;color.g=c;color.b=c;
}
inline void PointLight::set_color(const RGBColor& c){
color=c;
}
inline void PointLight::set_color(const float r,const float g,const float b){
color.r=r;color.g=g;color.b=b;
}
inline void PointLight::set_location(Vector3D d){
location = d;
}
inline void PointLight::set_location(float dx,float dy,float dz){
	location.x=dx;location.y=dy;location.z=dz;
}

#endif