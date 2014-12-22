#ifndef __RAY__
#define __RAY__
#include "Point3D.h"
#include "Vector3D.h"
class Ray{
public:
Point3D o;//光线起点
Vector3D d;//光线方向
//构造函数
Ray();
Ray(const Point3D& origin,const Vector3D& dir);
//拷贝构造函数
Ray(const Ray& ray);
Ray& operator=(const Ray& rhs);
~Ray();
};
#endif