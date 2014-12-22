#ifndef __POINT3D__
#define __POINT3D__
#include "Matrix.h"
#include "Vector3D.h"
class Point3D{
public:
	double x,y,z;
	Point3D();
	Point3D(const double a);
	Point3D(const double a,const double b,const double c);
	Point3D(const Point3D& p);
	~Point3D();
	//重载操作符
	Point3D& operator=(const Point3D& p);
	Point3D operator-()const;
	Vector3D operator-(const Point3D& p)const;
	Point3D operator+(const Vector3D& v)const;
	Point3D operator-(const Vector3D& v)const;
	Point3D operator*(const double a)const;
	double d_squared(const Point3D& p) const;
	double distance(const Point3D& p)const;
};
//求点坐标求负
inline Point3D Point3D::operator-()const{
return (Point3D(-x,-y,-z));
}
//通过两个点求一个向量
inline Vector3D Point3D::operator-(const Point3D& p)const{
return (Vector3D(x-p.x,y-p.y,z-p.z));
}
//点和向量相加求终点
inline Point3D Point3D::operator+(const Vector3D& v)const{
return (Point3D(x+v.x,y+v.y,z+v.z));
}
//通过点和向量相减求另一个点
inline Point3D Point3D::operator-(const Vector3D& v)const{
return (Point3D(x-v.x,y-v.y,z-v.z));
}
//点坐标乘上一个数
inline Point3D Point3D::operator*(const double a) const{
return (Point3D(x*a,y*a,z*a));
}
//计算点和点距离的平方
inline double Point3D::d_squared(const Point3D& p)const{
	return((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)+(z-p.z)*(z-p.z));
}
inline Point3D operator*(double a,const Point3D& p){
return (Point3D(a*p.x,a*p.y,a*p.z));
}
//矩阵和点的乘法
Point3D operator*(const Matrix& mat,const Point3D& p);
#endif