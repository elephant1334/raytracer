#ifndef __VIEW_PLANE__
#define __VIEW_PLANE__
//��ƽ��
class ViewPlane{
public:
	int num_samples;//���ز�������
	int hres;//ˮƽ����ͼ��ֱ���
	int vres;//��ֱ����ͼ��ֱ���
	float s;//���ش�С
	float gamma;//��ɫֵ����
	float inv_gamma;//��ɫֵ�����ĵ���
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