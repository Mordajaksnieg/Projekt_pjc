#include "Czesc_kolo.h"

Czesc_kolo::Czesc_kolo(float r)
{
	this->radius = r;
	this->bufor = 6.f;
}

Czesc_kolo::~Czesc_kolo()
{
}

void Czesc_kolo::set_Radius(float r)
{
	this->radius = r;
}

float Czesc_kolo::get_Radius() const
{
	return this->radius;
}

bool Czesc_kolo::Kolizja(Czesc_prost czesc_ciala) const
{
	czesc_ciala.set_Origin();	//ustawia origin w pukncie E

	//Kolizja z BC
	bool cond1 = -(czesc_ciala.get_Position_x() - this->pozycja_x) * sinf(czesc_ciala.get_Angle() * PI / 180.f) - (czesc_ciala.get_Position_y()
		- this->pozycja_y) * cosf(czesc_ciala.get_Angle() * PI / 180.f) - this->radius - (czesc_ciala.get_Dim_wys() / 2.f) - this->bufor <= 0;

	//Kolizja z AD
	bool cond2 = (czesc_ciala.get_Position_x() - this->pozycja_x) * sinf(czesc_ciala.get_Angle() * PI / 180.f) + (czesc_ciala.get_Position_y()
		- this->pozycja_y) * cosf(czesc_ciala.get_Angle() * PI / 180.f) - this->radius - (czesc_ciala.get_Dim_wys() / 2.f) - this->bufor <= 0;

	//Kolizja z AB
	bool cond3 = (czesc_ciala.get_Position_x() - this->pozycja_x) * cosf(czesc_ciala.get_Angle() * PI / 180.f) - (czesc_ciala.get_Position_y()
		- this->pozycja_y) * sinf(czesc_ciala.get_Angle() * PI / 180.f) - this->radius - this->bufor <= 0;

	//Kolizja z CD
	bool cond4 = -(czesc_ciala.get_Position_x() - this->pozycja_x) * cosf(czesc_ciala.get_Angle() * PI / 180.f) + (czesc_ciala.get_Position_y()
		- this->pozycja_y) * sinf(czesc_ciala.get_Angle() * PI / 180.f) - this->radius - this->bufor - czesc_ciala.get_Dim_szer() <= 0;

	return (cond1 && cond2 && cond3 && cond4);
}

bool Czesc_kolo::Kolizja(Czesc_kolo glowa) const
{
	bool cond = sqrtf(powf(glowa.pozycja_x - this->pozycja_x, 2) + powf(glowa.pozycja_y - this->pozycja_y, 2))
		<= glowa.get_Radius() +	this->radius + this->bufor;

	return cond;
}

