#include "Material.h"
#include "ShadeRec.h"
#include "Constants.h"
Material::Material(){}

Material::Material(const Material& m){}

Material& Material::operator=(const Material& rhs){
if(this==&rhs)
	return (*this);
return (*this);
}

Material::~Material(){}

RGBColor Material::shade(ShadeRec& sr){
return (black);
}