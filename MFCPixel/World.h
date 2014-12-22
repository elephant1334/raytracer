#ifndef __WORLD__
#define __WORLD__
#include <vector>
#include "GeometricObject.h"
#include"ViewPlane.h"
#include "RGBColor.h"
#include "Tracer.h"
#include "Sphere.h"
#include "Light.h"
#include "Ray.h"
#include "Camera.h"
#include "Matte.h"
#pragma once
using namespace std;
class World{
public:
	ViewPlane vp;
	RGBColor background_color;
	Tracer* tracer_ptr;
	Camera* camera_ptr;
	Light* ambient_ptr;
	vector<GeometricObject*> objects;
	vector<Light*> lights;
	vector<RGBColor> vcolor;
public:
	World();
	~World();
	void add_object(GeometricObject* object_ptr);
	void add_light(Light* light_ptr);
	void set_ambient_light(Light* light_ptr);
	void set_camera(Camera* c_ptr);
	void build();
	void buildwithdirectional();
	void buildwithpointlight();
	void buildwithpointanddirection();
	void delete_objects();
	//ShadeRec hit_bare_bones_objects(const Ray& ray);
	ShadeRec hit_objects(const Ray& ray);
	void render_scene(vector<RGBColor> &vcolor)const;
	RGBColor max_to_one(const RGBColor& c)const;
	RGBColor clamp_to_color(const RGBColor& c)const;
	void display_pixel(const int row,const int column,const RGBColor& pixel_color);
	vector<RGBColor> getVectorColor();
	void addVectorColor(RGBColor L);
};
inline void World::add_object(GeometricObject* object_ptr){
	objects.push_back(object_ptr);
}
inline void World::add_light(Light* light_ptr){
	lights.push_back(light_ptr);
}
inline void World::set_ambient_light(Light* light_ptr){
	ambient_ptr = light_ptr;
}
inline void World::set_camera(Camera* c_ptr){
camera_ptr = c_ptr;
}
#endif