#ifndef __PINHOLE__
#define __PINHOLE__

// This file contains the declaration of the class Pinhole

#include "Point2D.h"
#include<vector>
#include "Camera.h"
   // we can #include "World.h" here

//--------------------------------------------------------------------- class Pinhole
class World;
class Pinhole: public Camera {
	public:
		//vector<RGBColor> pvector;
		Pinhole();   							

		Pinhole(const Pinhole& ph);	
		
		virtual Camera*						
		clone(void) const;			

		Pinhole& 							
		operator= (const Pinhole& rhs);	
		
		virtual
		~Pinhole();   						
			
		void
		set_view_distance(const float vpd);
		
		void
		set_zoom(const float zoom_factor);
		
		Vector3D								
		get_direction(const Point2D& p) const;
		
		virtual void											
		render_scene(World& w);

		//vector<RGBColor> getcolorvector();
		
//		void addPVector(const RGBColor L){
//			pvector.push_back(L);
//		}
//		vector<RGBColor> getcolorvector(){
//	     //vector<RGBColor> tmp = pvector;
//	     return pvector;
//}
		
		
	private:
			
		float	d;		// view plane distance
		float	zoom;	// zoom factor
		
};




//-------------------------------------------------------------------------- set_vpd

inline void
Pinhole::set_view_distance(float _d) {
	d = _d;
}	
	


//-------------------------------------------------------------------------- set_zoom

inline void
Pinhole::set_zoom(float zoom_factor) {
	zoom = zoom_factor;
}	
#endif