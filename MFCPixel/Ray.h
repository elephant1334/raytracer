#ifndef __RAY__
#define __RAY__
#include "Point3D.h"
#include "Vector3D.h"
class Ray{
public:
Point3D o;//�������
Vector3D d;//���߷���
//���캯��
Ray();
Ray(const Point3D& origin,const Vector3D& dir);
//�������캯��
Ray(const Ray& ray);
Ray& operator=(const Ray& rhs);
~Ray();
};
#endif