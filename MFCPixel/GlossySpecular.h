#ifndef __GLOSSY_SPECULAR__
#define __GLOSSY_SPECLUAR__

#include "BRDF.h"
class GlossySpecular:public BRDF{
public:
	GlossySpecular(void);
		
		GlossySpecular(const GlossySpecular& glossy);
		
		virtual GlossySpecular*
		clone(void) const;
		
		~GlossySpecular(void);

		GlossySpecular& 
		operator= (const GlossySpecular& rhs);
		
		virtual RGBColor
		f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
		
		virtual RGBColor
		rho(const ShadeRec& sr, const Vector3D& wo) const;
			
		/*void
		set_ka(const float ka);	
				
		void
		set_kd(const float kd);*/
		void
		set_ks(const float k);
		
		void
		set_cs(const RGBColor& c);
		
		void													
		set_cs(const float r, const float g, const float b);
		
		void													
		set_cs(const float c);

		void
		set_exp(const float e);
private:
	float ks;
	RGBColor cs;
	int exp;    //ps*(r*w0)^exp
};
inline void GlossySpecular::set_ks(const float k){
	ks = k;
}
inline void GlossySpecular::set_cs(const RGBColor& c){
cs = c;
}
inline void GlossySpecular::set_cs(const float r,const float g,const float b){
cs.r = r; cs.g = g;cs.b = b;
}
inline void GlossySpecular::set_cs(const float c){
cs.r = c; cs.g = c;cs.b = c;
}
inline void GlossySpecular::set_exp(const float e){
exp = e;
}
#endif