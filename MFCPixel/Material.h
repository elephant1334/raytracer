#ifndef __MATERIAL__
#define __MATERIAL__

#include "RGBColor.h"
class ShadeRec;

class Material{
public:
	Material();
	Material(const Material& material);
	virtual Material* clone()const = 0;
	virtual ~Material();
	virtual RGBColor shade(ShadeRec &sr);
protected:
	Material& operator=(const Material& rhs);
};
#endif
