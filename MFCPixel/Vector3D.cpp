#include<math.h>
#include"Vector3D.h"
#include"Point3D.h"
#include"Normal.h"

Vector3D::Vector3D():x(0),y(0),z(0){}
Vector3D::Vector3D(double a):x(a),y(a),z(a){}
Vector3D::Vector3D(double _x,double _y,double _z):x(_x),y(_y),z(_z){}
//拷贝构造函数
Vector3D::Vector3D(const Vector3D& v):x(v.x),y(v.y),z(v.z){}
//从法线转为向量的构造函数
Vector3D::Vector3D(const Normal& n):x(n.x),y(n.y),z(n.z){}
//从点转化为向量的构造函数
Vector3D::Vector3D(const Point3D& p):x(p.x),y(p.y),z(p.z){}
//析构
Vector3D::~Vector3D(){};
//赋值运算
Vector3D& Vector3D::operator=(const Vector3D& rhs){
	if(this==&rhs)
		return (*this);
	x=rhs.x;y=rhs.y;z=rhs.z;
    return (*this);
}
Vector3D& Vector3D::operator=(const Normal& rhs){
x=rhs.x;y=rhs.y;z=rhs.z;
return (*this);
}
Vector3D& Vector3D::operator=(const Point3D& rhs){
x=rhs.x;y=rhs.y;z=rhs.z;
return (*this);
}
//计算向量长度
double Vector3D::length(){
return (sqrt(x*x+y*y+z*z));
}
//向量规范化（有改动）
void Vector3D::normalize(){
	double length=(*this).length();
	x/=length;y/=length;z/=length;
}
Vector3D& Vector3D::hat(){
double length = sqrt(x*x+y*y+z*z);
x/=length;y/=length;z/=length;
return (*this);
}
//矩阵乘以向量
Vector3D 
operator* (const Matrix& mat, const Vector3D& v) {
	return (Point3D(mat.m[0][0] * v.x + mat.m[0][1] * v.y + mat.m[0][2] * v.z,
					mat.m[1][0] * v.x + mat.m[1][1] * v.y + mat.m[1][2] * v.z,
					mat.m[2][0] * v.x + mat.m[2][1] * v.y + mat.m[2][2] * v.z));
}