#include "Czesc_prost.h"


//Konstr i Destruktor
Czesc_prost::Czesc_prost(float x, float y) : Czesc()
{
	this->szer = x;
	this->wys = y;
	this->angle = 0.f;
	this->lewo = true;
	this->origin = 'E';
	this->w_B_x = this->w_B_y = this->w_A_x = this->w_A_y = this->w_C_x = this->w_C_y = 
		this->w_D_x = this->w_D_y = this->w_E_x = this->w_E_y = this->w_F_x = this->w_F_y = 0;
}

Czesc_prost::~Czesc_prost()
{
}

//Settery
void Czesc_prost::set_Dim(float width, float height)
{
	this->szer = width;
	this->wys = height;
}

void Czesc_prost::set_Origin(char gdzie_origin, bool czy_lewo)
{
	switch (gdzie_origin)
	{
	case 'E':
		this->pozycja_x = this->w_E_x;
		this->pozycja_y = this->w_E_y;;
		this->origin = 'E';
		break;
	case 'F':
		this->pozycja_x = this->w_F_x;;
		this->pozycja_y = this->w_F_y;;
		this->origin = 'F';
		break;
	case 'B':
		this->pozycja_x = this->w_B_x;
		this->pozycja_y = this->w_B_y;
		this->origin = 'B';
		break;
	case 'A':
		this->pozycja_x = this->w_A_x;
		this->pozycja_y = this->w_A_y;
		this->origin = 'A';
		break;
	case 'C':
		this->pozycja_x = this->w_C_x;
		this->pozycja_y = this->w_C_y;
		this->origin = 'C';
		break;
	case 'S':
		this->pozycja_x = (this->w_A_x + this->w_C_x) / 2.f;
		this->pozycja_y = (this->w_A_y + this->w_C_y) / 2.f;
		this->origin = 'S';
		break;
	}

	this->lewo = czy_lewo;
}

void Czesc_prost::set_Angle(float kat)
{
	this->angle = kat;
}

void Czesc_prost::set_Corners()
{
	//Origin w E
	if (this->origin == 'E')	
	{
		this->w_E_x = this->pozycja_x;
		this->w_E_y = this->pozycja_y;

		this->w_B_x = this->pozycja_x + this->wys * sinf(this->angle * PI / 180.f) / 2.f;
		this->w_B_y = this->pozycja_y + this->wys * cosf(this->angle * PI / 180.f) / 2.f;

		this->w_A_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f) / 2.f;
		this->w_A_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f) / 2.f;

		this->w_F_x = this->pozycja_x + this->szer * cosf(this->angle * PI / 180.f);
		this->w_F_y = this->pozycja_y - this->szer * sinf(this->angle * PI / 180.f);

		this->w_C_x = this->pozycja_x + this->wys * sinf(this->angle * PI / 180.f) / 2.f + this->szer * cosf(this->angle * PI / 180.f);
		this->w_C_y = this->pozycja_y + this->wys * cosf(this->angle * PI / 180.f) / 2.f - this->szer * sinf(this->angle * PI / 180.f);

		this->w_D_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f) / 2.f + this->szer * cosf(this->angle * PI / 180.f);
		this->w_D_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f) / 2.f - this->szer * sinf(this->angle * PI / 180.f);
	}

	//Origin w F
	if (this->origin == 'F')
	{
		this->w_F_x = this->pozycja_x;
		this->w_F_y = this->pozycja_y;

		this->w_C_x = this->pozycja_x + this->wys * sinf(this->angle * PI / 180.f) / 2.f;
		this->w_C_y = this->pozycja_y + this->wys * cosf(this->angle * PI / 180.f) / 2.f;

		this->w_D_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f) / 2.f;
		this->w_D_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f) / 2.f;

		this->w_E_x = this->pozycja_x - this->szer * cosf(this->angle * PI / 180.f);
		this->w_E_y = this->pozycja_y + this->szer * sinf(this->angle * PI / 180.f);

		this->w_B_x = this->pozycja_x + this->wys * sinf(this->angle * PI / 180.f) / 2.f - this->szer * cosf(this->angle * PI / 180.f);
		this->w_B_y = this->pozycja_y + this->wys * cosf(this->angle * PI / 180.f) / 2.f + this->szer * sinf(this->angle * PI / 180.f);

		this->w_A_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f) / 2.f - this->szer * cosf(this->angle * PI / 180.f);
		this->w_A_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f) / 2.f + this->szer * sinf(this->angle * PI / 180.f);
	}

	//Origin w B
	if (this->origin == 'B')
	{
		this->w_B_x = this->pozycja_x;
		this->w_B_y = this->pozycja_y;

		this->w_E_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f) / 2.f;
		this->w_E_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f) / 2.f;

		this->w_A_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f);
		this->w_A_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f);

		this->w_C_x = this->pozycja_x + this->szer * cosf(this->angle * PI / 180.f);
		this->w_C_y = this->pozycja_y - this->szer * sinf(this->angle * PI / 180.f);

		this->w_F_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f) / 2.f + this->szer * cosf(this->angle * PI / 180.f);
		this->w_F_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f) / 2.f - this->szer * sinf(this->angle * PI / 180.f);

		this->w_D_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f) + this->szer * cosf(this->angle * PI / 180.f);
		this->w_D_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f) - this->szer * sinf(this->angle * PI / 180.f);
	}

	//Origin w A
	if (this->origin == 'A')
	{
		this->w_A_x = this->pozycja_x;
		this->w_A_y = this->pozycja_y;

		this->w_E_x = this->pozycja_x + this->wys * sinf(this->angle * PI / 180.f) / 2.f;
		this->w_E_y = this->pozycja_y + this->wys * cosf(this->angle * PI / 180.f) / 2.f;

		this->w_B_x = this->pozycja_x + this->wys * sinf(this->angle * PI / 180.f);
		this->w_B_y = this->pozycja_y + this->wys * cosf(this->angle * PI / 180.f);

		this->w_D_x = this->pozycja_x + this->szer * cosf(this->angle * PI / 180.f);
		this->w_D_y = this->pozycja_y - this->szer * sinf(this->angle * PI / 180.f);

		this->w_F_x = this->pozycja_x + this->wys * sinf(this->angle * PI / 180.f) / 2.f + this->szer * cosf(this->angle * PI / 180.f);
		this->w_F_y = this->pozycja_y + this->wys * cosf(this->angle * PI / 180.f) / 2.f - this->szer * sinf(this->angle * PI / 180.f);

		this->w_C_x = this->pozycja_x + this->wys * sinf(this->angle * PI / 180.f) + this->szer * cosf(this->angle * PI / 180.f);
		this->w_C_y = this->pozycja_y + this->wys * cosf(this->angle * PI / 180.f) - this->szer * sinf(this->angle * PI / 180.f);
	}

	//Origin w C
	if (this->origin == 'C')
	{
		this->w_C_x = this->pozycja_x;
		this->w_C_y = this->pozycja_y;

		this->w_F_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f) / 2.f;
		this->w_F_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f) / 2.f;

		this->w_D_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f);
		this->w_D_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f);

		this->w_B_x = this->pozycja_x - this->szer * cosf(this->angle * PI / 180.f);
		this->w_B_y = this->pozycja_y + this->szer * sinf(this->angle * PI / 180.f);

		this->w_E_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f) / 2.f - this->szer * cosf(this->angle * PI / 180.f);
		this->w_E_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f) / 2.f + this->szer * sinf(this->angle * PI / 180.f);

		this->w_A_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f) - this->szer * cosf(this->angle * PI / 180.f);
		this->w_A_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f) + this->szer * sinf(this->angle * PI / 180.f);
	}

	//Origin w srodku
	if (this->origin == 'S')
	{
		this->w_E_x = this->pozycja_x - this->szer * cosf(this->angle * PI / 180.f) / 2.f;
		this->w_E_y = this->pozycja_y + this->szer * sinf(this->angle * PI / 180.f) / 2.f;

		this->w_B_x = this->pozycja_x + this->wys * sinf(this->angle * PI / 180.f) / 2.f - this->szer * cosf(this->angle * PI / 180.f) / 2.f;
		this->w_B_y = this->pozycja_y + this->wys * cosf(this->angle * PI / 180.f) / 2.f + this->szer * sinf(this->angle * PI / 180.f) / 2.f;

		this->w_A_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f) / 2.f - this->szer * cosf(this->angle * PI / 180.f) / 2.f;
		this->w_A_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f) / 2.f + this->szer * sinf(this->angle * PI / 180.f) / 2.f;

		this->w_F_x = this->pozycja_x + this->szer * cosf(this->angle * PI / 180.f) / 2.f;
		this->w_F_y = this->pozycja_y - this->szer * sinf(this->angle * PI / 180.f) / 2.f;

		this->w_C_x = this->pozycja_x + this->wys * sinf(this->angle * PI / 180.f) / 2.f + this->szer * cosf(this->angle * PI / 180.f) / 2.f;
		this->w_C_y = this->pozycja_y + this->wys * cosf(this->angle * PI / 180.f) / 2.f - this->szer * sinf(this->angle * PI / 180.f) / 2.f;

		this->w_D_x = this->pozycja_x - this->wys * sinf(this->angle * PI / 180.f) / 2.f + this->szer * cosf(this->angle * PI / 180.f) / 2.f;
		this->w_D_y = this->pozycja_y - this->wys * cosf(this->angle * PI / 180.f) / 2.f - this->szer * sinf(this->angle * PI / 180.f) / 2.f;
	}
}

void Czesc_prost::set_Connections_EF(Czesc_prost& czesc)
{
	//wi¹zanie do F
	if (this->origin == 'A' || this->origin == 'E' || this->origin == 'B' || this->origin == 'S' || this->origin == 'C')
		this->set_Position(czesc.w_F_x, czesc.w_F_y);
	//wi¹zanie do E
	else
		this->set_Position(czesc.w_E_x, czesc.w_E_y);	
}

void Czesc_prost::set_Connections_BC(Czesc_prost& czesc)
{
	//wi¹zanie do C
	if (!this->lewo)
		this->set_Position(czesc.w_C_x, czesc.w_C_y);
	//wiazanie do B
	else
		this->set_Position(czesc.w_B_x, czesc.w_B_y);	
}

void Czesc_prost::set_Connections_center(Czesc_prost& czesc)
{
	//wi¹zanie do œrodka
	this->set_Position((czesc.w_B_x + czesc.w_D_x) / 2.f, (czesc.w_B_y + czesc.w_D_y) / 2.f);
}

//Gettery
float Czesc_prost::get_Dim_szer() const
{
	return this->szer;
}

float Czesc_prost::get_Dim_wys() const
{
	return this->wys;
}

float Czesc_prost::get_Corner_A_x() const
{
	return this->w_A_x;
}

float Czesc_prost::get_Corner_A_y() const
{
	return this->w_A_y;
}

float Czesc_prost::get_Angle() const
{
	return this->angle;
}

//Funkcje
void Czesc_prost::rotate(int bieg, bool cw)
{
	switch (bieg)
	{
	case 1:
		if (cw)
			this->angle += 0.5f;
		else
			this->angle -= 0.5f;
		break;
	case 2:
		if (cw)
			this->angle += 0.6f;
		else
			this->angle -= 0.6f;
		break;
	case 3:
		if (cw)
			this->angle += 0.7f;
		else
			this->angle -= 0.7f;
		break;
	case 4:
		if (cw)
			this->angle += 0.8f;
		else
			this->angle -= 0.8f;
		break;
	case 5:
		if (cw)
			this->angle += 0.9f;
		else
			this->angle -= 0.9f;
		break;
	case 6:
		if (cw)
			this->angle += 1.f;
		else
			this->angle -= 1.f;
		break;
	}
}