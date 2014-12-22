#ifndef __SHADE_REC__
#define __SHADE_REC__

// this file contains the declaration of the class ShadeRec
	// only need a forward class declaration as the World data member is a reference

#include "Point3D.h"
#include "Normal.h"
#include "RGBColor.h"
#include "Ray.h"
#include "Material.h"

class World;
class ShadeRec {
	public:
	
		bool				hit_an_object;		// did the ray hit an object?
		Point3D             hit_point;
		Point3D				local_hit_point;	// world coordinates of hit point 
		Normal				normal;				// normal at hit point
		Material*           material_ptr;
		Ray                 ray;
		int                 depth;              //recursion depth
		float               t;
		//RGBColor			color;				// used in Chapter 3 only
		World&				w;					// world reference for shading
		Vector3D            dir;                //for area light		
		ShadeRec(World& wr);				// constructor
		
		ShadeRec(const ShadeRec& sr);		// copy constructor
};
#endif