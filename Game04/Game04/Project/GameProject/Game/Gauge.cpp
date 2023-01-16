#include "Gauge.h"

Gauge::Gauge(int gauge_type) :Base(eType_UI) {
	m_img = COPY_RESOURCE("Gauge1", CImage);
	m_par = 0;
	m_gauge_type = gauge_type;

}

void Gauge::Draw() {
	//�g�̕\��
	//m_img.SetRect(0, 0, 256, 64);
	//m_img.SetSize(256, 64);
	//m_img.SetPos(m_pos);
	//m_img.Draw();
	m_img.SetRect(0, 20, 256, 64);
	m_img.SetSize(556, 95);
	m_img.SetPos(m_pos);
	m_img.Draw();

	int border = 4;
	int width = (556 - border - border) * m_par;
	int y = (m_gauge_type + 1);
	m_img.SetRect(0, 80, 256, 128);
	m_img.SetSize(width, 95 - border - border);
	m_img.SetPos(m_pos + CVector2D(border, border));
	m_img.Draw();
}
void Gauge::SetValue(float par)
{
	m_par = par;
}