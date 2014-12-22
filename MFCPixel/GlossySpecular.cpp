#include "GlossySpecular.h"
GlossySpecular::GlossySpecular(void):BRDF(),ks(0.0),cs(0.0),exp(1){}
GlossySpecular::GlossySpecular(const GlossySpecular& glossy):BRDF(glossy),ks(glossy.ks),cs(glossy.cs),exp(glossy.exp){}

GlossySpecular* GlossySpecular::clone()const{
	return (new GlossySpecular(*this));
}
GlossySpecular::~GlossySpecular(){}

GlossySpecular& GlossySpecular::operator=(const GlossySpecular& rhs){
if(this==&rhs)
	return (*this);
BRDF::operator=(rhs);
ks=rhs.ks;
cs=rhs.cs;
exp=rhs.exp;
return (*this);
}
RGBColor GlossySpecular::f(const ShadeRec& sr,const Vector3D& wo,const Vector3D& wi)const{
RGBColor L;
float ndotwi = sr.normal*wi;
Vector3D r(-wi+2.0*sr.normal*ndotwi);
float rdotwo = r*wo;
if(rdotwo>0.0)
	L=ks*pow(rdotwo,exp);

return(L);
}
RGBColor GlossySpecular::rho(const ShadeRec& sr,const Vector3D& wo)const{
return (ks*cs);
}