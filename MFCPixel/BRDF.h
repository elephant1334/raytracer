#ifndef __BRDF__
#define __BRDF__

#include<math.h>
#include "RGBColor.h"
#include "Vector3D.h"
#include "ShadeRec.h"

class BRDF{
public:
BRDF();
BRDF(const BRDF& object);
virtual BRDF* clone() const = 0;
~BRDF();
virtual RGBColor sample_f(const ShadeRec& sr,const Vector3D& wo,Vector3D& wi)const;
virtual RGBColor sample_f(const ShadeRec& sr,const Vector3D& wo,Vector3D& wi,float& pdf)const;
virtual RGBColor rho(const ShadeRec&sr,const Vector3D& wo,Vector3D &wi,float &pdf)const;
protected:
	BRDF& operator = (const BRDF& rhs);
};
#endif