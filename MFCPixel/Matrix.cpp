#include "Matrix.h"
//默认初始化矩阵为单位阵
Matrix::Matrix(){
	for(int x=0;x<4;x++)
		for(int y=0;y<4;y++){
		if(x==y)
			m[x][y]=1.0;
		else
			m[x][y]=0.0;
		}
}
//拷贝构造函数
Matrix::Matrix(const Matrix& mat){
for(int x=0;x<4;x++)
	for(int y=0;y<4;y++){
	m[x][y]=mat.m[x][y];
	}
}
Matrix::~Matrix(){}
//定义赋值运算符(深拷贝？)
Matrix& Matrix::operator=(const Matrix& rhs){
if(this==&rhs)
	return (*this);
for(int x=0;x<4;x++)
	for(int y=0;y<4;y++)
		m[x][y]=rhs.m[x][y];

return (*this);
}
//定义矩阵乘法
Matrix Matrix::operator*(const Matrix& mat) const{
Matrix product;
for(int x=0;x<4;x++)
	for(int y=0;y<4;y++){
		double sum = 0.0;
		for(int j=0;j<4;j++)
			sum+=m[x][j]*m[j][y];
		product.m[x][y]=sum;
	}
	return (product);
}
//矩阵除以实数
Matrix Matrix::operator/(const double d){
	for(int x=0;x<4;x++)
		for(int y=0;y<4;y++)
			m[x][y]/=d;
	return (*this);
}
//设为单位阵
void Matrix::set_identity(){
	for(int x=0;x<4;x++)
		for(int y=0;y<4;y++){
		if(x==y)
			m[x][y]=1.0;
		else
			m[x][y]=0.0;
		}
}