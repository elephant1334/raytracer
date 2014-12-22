#ifndef __VIEW_PLANE__
#define __VIEW_PLANE__
//视平面
class ViewPlane{
public:
	int num_samples;//像素采样数量
	int hres;//水平方向图像分辨率
	int vres;//垂直方向图像分辨率
	float s;//像素大小
	float gamma;//颜色值修正
	float inv_gamma;//颜色值修正的倒数
	bool show_out_of_gamut;
public:
	ViewPlane();
	ViewPlane(const ViewPlane& vp);
	ViewPlane& operator=(const ViewPlane& rhs);
	~ViewPlane();
	void set_samples(const int _num_samples);
	void set_hres(const int h_res);
	void set_vres(const int v_res);
	void set_pixel_size(const float size);
	void set_gamma(const float g);
	void set_gamut_display(const bool show);
};
inline void ViewPlane::set_samples(const int _num_samples){
num_samples = _num_samples;
}
inline void ViewPlane::set_hres(const int h_res){
hres=h_res;
}
inline void ViewPlane::set_vres(const int v_res){
vres = v_res;
}
inline void ViewPlane::set_pixel_size(const float size){
s=size;
}
inline void ViewPlane::set_gamma(const float g){
gamma=g;
inv_gamma = 1.0/gamma;
}
inline void ViewPlane::set_gamut_display(const bool show){
	show_out_of_gamut = show;
}
#endif