#ifndef __GEOMETRIC_OBJECT__
#define __GEOMETRIC_OBJECT__

// this file contains the declaration of the class GeometricObject

#include "Point3D.h"
#include "Ray.h"
#include "ShadeRec.h"
					
class Material;
class GeometricObject {	
	
	public:	

		GeometricObject(void);									// default constructor
		
		GeometricObject(const GeometricObject& object);			// copy constructor
	
		virtual GeometricObject*								// virtual copy constructor
		clone(void) const = 0;

		virtual 												// destructor
		~GeometricObject (void);	
			
		virtual bool 												 
		hit(const Ray& ray, double& t, ShadeRec& s) const = 0;
		
		virtual bool shadow_hit(const Ray& ray,float& tmin)const =0;
		// the following three functions are only required for Chapter 3
		
		Material*						
		get_material(void) const;

		virtual void 							// needs to virtual so that it can be overriden in Compound
		set_material(Material* mPtr); 	

	
	protected:
	
		//RGBColor   color;						// only used for Bare Bones ray tracing
	    mutable Material*   material_ptr; 
		GeometricObject&						// assignment operator
		operator= (const GeometricObject& rhs);
};
inline Material* 
GeometricObject::get_material(void) const {
	return (material_ptr);
}

#endif