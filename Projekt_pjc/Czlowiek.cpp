#include "Czlowiek.h"

Czlowiek::Czlowiek()
{
	this->init_Czesci_Vector();
	this->Glowa.set_Radius(62.f);	//Deafaultowo czesc_kolo ma 0 promieñ
	this->Default();
}

Czlowiek::~Czlowiek()
{
}

void Czlowiek::init_Czesci_Vector()
{
	this->Czesci.push_back(&LN_1);
	this->Czesci.push_back(&LN_2);
	this->Czesci.push_back(&LN_3);
	this->Czesci.push_back(&LN_4);

	this->Czesci.push_back(&Miednica);

	this->Czesci.push_back(&PN_1);
	this->Czesci.push_back(&PN_2);
	this->Czesci.push_back(&PN_3);
	this->Czesci.push_back(&PN_4);

	this->Czesci.push_back(&Kreg1);
	this->Czesci.push_back(&Kreg2);
	this->Czesci.push_back(&Kreg3);

	this->Czesci.push_back(&Bark);

	this->Czesci.push_back(&Szyja);

	this->Czesci.push_back(&LR_1);
	this->Czesci.push_back(&LR_2);
	this->Czesci.push_back(&LR_3);

	this->Czesci.push_back(&PR_1);
	this->Czesci.push_back(&PR_2);
	this->Czesci.push_back(&PR_3);
}

void Czlowiek::Default()
{
	//////////////////////////////////////////////////////////// Lewa noga //////////////////////////////////////////////////////////////////
	this->LN_1.set_Origin('B');
	this->LN_1.set_Position(600.f, 800.f);
	this->LN_1.set_Angle(80.f);
	this->LN_1.set_Corners();

	this->LN_2.set_Origin();
	this->LN_2.set_Connections_EF(this->LN_1);
	this->LN_2.set_Angle(75.f);
	this->LN_2.set_Corners();

	this->LN_3.set_Origin();
	this->LN_3.set_Connections_EF(this->LN_2);
	this->LN_3.set_Angle(70.f);
	this->LN_3.set_Corners();

	this->LN_4.set_Origin();
	this->LN_4.set_Connections_EF(this->LN_3);
	this->LN_4.set_Angle(65.f);
	this->LN_4.set_Corners();

	/////////////////////////////////////////////////////// Miednica /////////////////////////////////////////////////////////////////////////
	this->Miednica.set_Origin('B');
	this->Miednica.set_Connections_EF(this->LN_4);
	this->Miednica.set_Angle(0.f);
	this->Miednica.set_Corners();

	/////////////////////////////////////////////////////// Prawa noga ////////////////////////////////////////////////////////////////////////
	this->PN_4.set_Origin('F', false);
	this->PN_4.set_Connections_BC(this->Miednica);
	this->PN_4.set_Angle(180.f - 65.f);
	this->PN_4.set_Corners();

	this->PN_3.set_Origin('F', false);
	this->PN_3.set_Connections_EF(this->PN_4);
	this->PN_3.set_Angle(180.f - 70.f);
	this->PN_3.set_Corners();

	this->PN_2.set_Origin('F', false);
	this->PN_2.set_Connections_EF(this->PN_3);
	this->PN_2.set_Angle(180.f - 75.f);
	this->PN_2.set_Corners();

	this->PN_1.set_Origin('F', false);
	this->PN_1.set_Connections_EF(this->PN_2);
	this->PN_1.set_Angle(180.f - 80.f);
	this->PN_1.set_Corners();

	/////////////////////////////////////////////////////////// Krêgos³up /////////////////////////////////////////////////////////////////////
	this->Kreg1.set_Origin();
	this->Kreg1.set_Connections_center(this->Miednica);
	this->Kreg1.set_Angle(90.f);
	this->Kreg1.set_Corners();

	this->Kreg2.set_Origin();
	this->Kreg2.set_Connections_EF(this->Kreg1);
	this->Kreg2.set_Angle(90.f);
	this->Kreg2.set_Corners();

	this->Kreg3.set_Origin();
	this->Kreg3.set_Connections_EF(this->Kreg2);
	this->Kreg3.set_Angle(90.f);
	this->Kreg3.set_Corners();

	/////////////////////////////////////////////////////////// Bark ////////////////////////////////////////////////////////////////////////
	this->Bark.set_Dim(70.f, 20.f);
	this->Bark.set_Origin('S');
	this->Bark.set_Connections_EF(this->Kreg3);
	this->Bark.set_Angle(0.f);
	this->Bark.set_Corners();

	/////////////////////////////////////////////////////////// Szyja /////////////////////////////////////////////////////////////////////
	this->Szyja.set_Dim(55.f, 20.f);
	this->Szyja.set_Origin();
	this->Szyja.set_Angle(90.f);
	this->Szyja.set_Connections_center(this->Bark);
	this->Szyja.set_Corners();

	////////////////////////////////////////////////////////// Lewa rêka ///////////////////////////////////////////////////////////////////
	this->LR_3.set_Angle(60.f);
	this->LR_3.set_Origin('F');
	this->LR_3.set_Connections_BC(this->Bark);
	this->LR_3.set_Corners();

	this->LR_2.set_Angle(70.f);
	this->LR_2.set_Origin('F');
	this->LR_2.set_Connections_EF(this->LR_3);
	this->LR_2.set_Corners();

	this->LR_1.set_Angle(80.f);
	this->LR_1.set_Origin('F');
	this->LR_1.set_Connections_EF(this->LR_2);
	this->LR_1.set_Corners();

	/////////////////////////////////////////////////////////// Prawa rêka /////////////////////////////////////////////////////////////
	this->PR_3.set_Angle(180.f - 60.f);
	this->PR_3.set_Origin('F', false);
	this->PR_3.set_Connections_BC(this->Bark);
	this->PR_3.set_Corners();

	this->PR_2.set_Angle(180.f - 70.f);
	this->PR_2.set_Origin('F', false);
	this->PR_2.set_Connections_EF(this->PR_3);
	this->PR_2.set_Corners();

	this->PR_1.set_Angle(180.f - 80.f);
	this->PR_1.set_Origin('F', false);
	this->PR_1.set_Connections_EF(this->PR_2);
	this->PR_1.set_Corners();

	////////////////////////////////////////////////////////// G³owa /////////////////////////////////////////////////////////////////////////
	this->Glowa.set_Position(this->Bark.get_Position_x(), this->Bark.get_Position_y() - this->Glowa.get_Radius() - this->Szyja.get_Dim_szer());
	
	////////////////////////////////////////////////////////// Zmienne //////////////////////////////////////////////////////////////////////
	this->wybor_obrotu = 0;
	this->x_B_Miednica = this->Miednica.get_Position_x();
}

std::vector<Czesc_prost*> Czlowiek::get_Rect_Objs() const
{
	return this->Czesci;
}

Czesc_kolo Czlowiek::get_Head() const
{
	return this->Glowa;
}

void Czlowiek::set_Origins(Czesc_kolo *Pocisk)
{
	/////////////////////////////////////////////////////// Stopy /////////////////////////////////////////////////////////////////////
	// Tylko pierwsza i druga czêœæ 
	// nogi bez dotykania 3
	if ((Pocisk->Kolizja(this->LN_1) || Pocisk->Kolizja(this->LN_2)) && !Pocisk->Kolizja(this->LN_3))
	{
		//Originy
		this->LN_1.set_Origin('F');
		this->LN_2.set_Origin('F');
		this->LN_3.set_Origin('F');
		this->LN_4.set_Origin('F');
		this->Miednica.set_Origin('B');

		//Obrót
		if (this->wybor_obrotu == 0)
			this->wybor_obrotu = 1;
	}

	if ((Pocisk->Kolizja(this->PN_1) || Pocisk->Kolizja(this->PN_2)) && !Pocisk->Kolizja(this->PN_3))
	{
		//Originy
		this->PN_1.set_Origin('F', false);
		this->PN_2.set_Origin('F', false);
		this->PN_3.set_Origin('F', false);
		this->PN_4.set_Origin('F', false);
		this->Miednica.set_Origin('C');
	
		//Obrót
		if (this->wybor_obrotu == 0)
			this->wybor_obrotu = 2;
	}

	////////////////////////////////////////////////////// Kolana /////////////////////////////////////////////////////////////////////
	// 3 czêœæ nogi bez dotykania 4 
	if (Pocisk->Kolizja(this->LN_3) && !Pocisk->Kolizja(this->LN_4))
	{
		//Originy
		this->LN_1.set_Origin('A');
		this->LN_2.set_Origin();
		this->LN_3.set_Origin();
		this->LN_4.set_Origin();
		this->Miednica.set_Origin('B');
		this->PN_1.set_Origin('F', false);
		this->PN_2.set_Origin('F', false);
		this->PN_3.set_Origin('F', false);
		this->PN_4.set_Origin('F', false);
		
		//Obrót
		if (this->wybor_obrotu == 0)
			this->wybor_obrotu = 3;
	}

	if (Pocisk->Kolizja(this->PN_3) && !Pocisk->Kolizja(this->PN_4))
	{
		//Originy
		this->PN_1.set_Origin('B');
		this->PN_2.set_Origin('E', false);
		this->PN_3.set_Origin('E', false);
		this->PN_4.set_Origin('E', false);
		this->Miednica.set_Origin('C');
		this->LN_1.set_Origin('F');
		this->LN_2.set_Origin('F');
		this->LN_3.set_Origin('F');
		this->LN_4.set_Origin('F');

		//Obrót
		if (this->wybor_obrotu == 0)
			this->wybor_obrotu = 4;
	}

	////////////////////////////////////////////////////// Uda/Miednica/Pierwszy krag //////////////////////////////////////////////////            
	// Czwarta czêœæ nogi, miednica 
	// lub pierwszy kr¹g bez dotykania krêgu 2
	if (Pocisk->Kolizja(this->LN_4) || Pocisk->Kolizja(this->PN_4) || Pocisk->Kolizja(this->Miednica) ||
		(Pocisk->Kolizja(this->Kreg1) && !Pocisk->Kolizja(this->Kreg2)))
	{
		//Originy
		this->LN_1.set_Origin('A');
		this->LN_2.set_Origin();
		this->LN_3.set_Origin();
		this->LN_4.set_Origin();
		this->Miednica.set_Origin('B');
		this->PN_1.set_Origin('F', false);
		this->PN_2.set_Origin('F', false);
		this->PN_3.set_Origin('F', false);
		this->PN_4.set_Origin('F', false);

		//Obrót
		if (this->wybor_obrotu == 0)
			this->wybor_obrotu = 5;
	}

	////////////////////////////////////////////////// Kregoslup/Sszyja/Bark/Ramie /////////////////////////////////////////////////////
	//Krêgos³up szyja bark ramiona_3_czesc,
	//bez dotykania 2 czesci ramion i g³owy
	if ((Pocisk->Kolizja(this->Kreg2) || Pocisk->Kolizja(this->Kreg3) || Pocisk->Kolizja(this->Bark) ||
		Pocisk->Kolizja(this->Szyja) || Pocisk->Kolizja(this->LR_3) || Pocisk->Kolizja(this->PR_3)) &&
		(!Pocisk->Kolizja(this->LR_2) && !Pocisk->Kolizja(this->PR_2) && !Pocisk->Kolizja(this->Glowa)))
	{
		//Obrót
		if (this->wybor_obrotu == 0)
			this->wybor_obrotu = 6;
	}

	////////////////////////////////////////////////////// G³owa ////////////////////////////////////////////////////////////////////
	if (Pocisk->Kolizja(this->Glowa))
	{
		//Obrót
		if (this->wybor_obrotu == 0)
			this->wybor_obrotu = 7;
	}

	////////////////////////////////////////////////////// Rêce ///////////////////////////////////////////////////////////////////////////
	if (Pocisk->Kolizja(this->LR_1) || Pocisk->Kolizja(this->LR_2))
	{
		//Obrót
		if (this->wybor_obrotu == 0)
			this->wybor_obrotu = 8;
	}

	if (Pocisk->Kolizja(this->PR_1) || Pocisk->Kolizja(this->PR_2))
	{
		//Obrót
		if (this->wybor_obrotu == 0)
			this->wybor_obrotu = 9;
	}
}

void Czlowiek::update_Corners()
{
	for (int i = 0; i < int(this->Czesci.size()); i++)
	{
		this->Czesci[i]->set_Corners();
	}
}

void Czlowiek::ruchy_i_Obroty(Czesc_kolo *Pocisk)
{
	if (Pocisk->Kolizja(this->LN_1) || Pocisk->Kolizja(this->LN_2) || Pocisk->Kolizja(this->LN_3) ||
		Pocisk->Kolizja(this->LN_4) || Pocisk->Kolizja(this->Miednica) || Pocisk->Kolizja(this->PN_1) ||
		Pocisk->Kolizja(this->PN_2) || Pocisk->Kolizja(this->PN_3) || Pocisk->Kolizja(this->PN_4) ||
		Pocisk->Kolizja(this->Kreg1) || Pocisk->Kolizja(this->Kreg2) || Pocisk->Kolizja(this->Kreg3) ||
		Pocisk->Kolizja(this->Bark) || Pocisk->Kolizja(this->Szyja) || Pocisk->Kolizja(this->LR_3) ||
		Pocisk->Kolizja(this->LR_2) || Pocisk->Kolizja(this->LR_1) || Pocisk->Kolizja(this->PR_3) ||
		Pocisk->Kolizja(this->PR_2) || Pocisk->Kolizja(this->PR_1) || Pocisk->Kolizja(this->Glowa))
	{
		switch (this->wybor_obrotu)
		{

		//Lewa stopa
		case 1:
			//Wi¹zania
			this->LN_4.set_Connections_BC(this->Miednica);
			this->LN_3.set_Connections_EF(this->LN_4);
			this->LN_2.set_Connections_EF(this->LN_3);
			this->LN_1.set_Connections_EF(this->LN_2);

			//Obrót
			this->LN_4.rotate(5, false);
			this->LN_3.rotate(2, false);
			break;

		//Prawa stopa
		case 2:
			//Wi¹zania
			this->PN_4.set_Connections_BC(this->Miednica);
			this->PN_3.set_Connections_EF(this->PN_4);
			this->PN_2.set_Connections_EF(this->PN_3);
			this->PN_1.set_Connections_EF(this->PN_2);

			//Obroty
			this->PN_4.rotate();
			this->PN_3.rotate(2);
			break;

		//Lewe kolano
		case 3:
			//Wi¹zania
			this->LN_2.set_Connections_EF(this->LN_1);
			this->LN_3.set_Connections_EF(this->LN_2);
			this->LN_4.set_Connections_EF(this->LN_3);
			this->Miednica.set_Connections_EF(this->LN_4);
			this->PN_4.set_Connections_BC(this->Miednica);
			this->PN_3.set_Connections_EF(this->PN_4);
			this->PN_2.set_Connections_EF(this->PN_3);
			this->PN_1.set_Connections_EF(this->PN_2);		

			this->wiazania_Gora();

			//Obroty
			this->LN_1.rotate();
			this->LN_2.rotate(1);
			this->PN_4.rotate(1);
			break;

		//Prawe kolano
		case 4:
			//Wi¹zania
			this->PN_2.set_Connections_EF(this->PN_1);
			this->PN_3.set_Connections_EF(this->PN_2);
			this->PN_4.set_Connections_EF(this->PN_3);
			this->Miednica.set_Connections_EF(this->PN_4);
			this->LN_4.set_Connections_BC(this->Miednica);
			this->LN_3.set_Connections_EF(this->LN_4);
			this->LN_2.set_Connections_EF(this->LN_3);
			this->LN_1.set_Connections_EF(this->LN_2);

			this->wiazania_Gora();

			//Obroty
			this->PN_1.rotate(5, false);
			this->PN_2.rotate(1, false);
			this->LN_4.rotate(1, false);
			break;

		//Uda i miednica
		case 5:
			//Wi¹zania
			this->LN_2.set_Connections_EF(this->LN_1);
			this->LN_3.set_Connections_EF(this->LN_2);
			this->LN_4.set_Connections_EF(this->LN_3);
			this->Miednica.set_Connections_EF(this->LN_4);
			this->PN_4.set_Connections_BC(this->Miednica);
			this->PN_3.set_Connections_EF(this->PN_4);
			this->PN_2.set_Connections_EF(this->PN_3);
			this->PN_1.set_Connections_EF(this->PN_2);

			this->wiazania_Gora();

			//Obrót nóg
			if (this->Miednica.get_Position_x() < this->x_B_Miednica)
			{
				this->LN_4.rotate(2, false);
				this->LN_3.rotate(2, false);
				this->PN_4.rotate(1);
				this->PN_3.rotate(1);
			}
			this->LN_1.rotate(6);
			this->PN_1.rotate(6, false);

			//Obrót krêgos³upu
			if ((Pocisk->Kolizja(this->Miednica) && !Pocisk->Kolizja(this->LN_4) && !Pocisk->Kolizja(this->PN_4)) ||
				(Pocisk->Kolizja(this->Kreg1) && !Pocisk->Kolizja(this->Kreg2) && !Pocisk->Kolizja(this->Miednica)))
			{
				if (Pocisk->get_Position_x() < (this->x_B_Miednica + this->Miednica.get_Dim_szer() / 2.f))
				{
					this->Kreg1.rotate(3, false);
					this->Kreg2.rotate(1, false);
					this->LR_3.rotate(1, false);
				}
				else
				{
					this->Kreg1.rotate(3);
					this->Kreg2.rotate(1);
					this->PR_3.rotate(1);
				}
			}
			break;

		//Tu³ów
		case 6:
			//Wi¹zania
			this->wiazania_Gora();

			//Obroty
			if (Pocisk->get_Position_x() < this->Kreg3.get_Position_x())
			{
				this->Kreg1.rotate(3, false);
				this->Kreg2.rotate(1, false);
			}
			else
			{
				this->Kreg1.rotate(3);
				this->Kreg2.rotate(1);
			}
			break;

		//G³owa
		case 7:
			//Wi¹zania
			this->Glowa.set_Position(this->Szyja.get_Position_x() + (this->Szyja.get_Dim_szer() + this->Glowa.get_Radius())
				* cosf(this->Szyja.get_Angle() * PI / 180.f), this->Szyja.get_Position_y() - (this->Szyja.get_Dim_szer() +
					this->Glowa.get_Radius()) * sinf(this->Szyja.get_Angle() * PI / 180.f));

			//Obroty
			if (Pocisk->get_Position_x() < this->Glowa.get_Position_x())
				this->Szyja.rotate(5, false);
			else
				this->Szyja.rotate(5);
			break;

		//Lewa rêka
		case 8:
			//Wi¹zania
			this->LR_3.set_Connections_BC(this->Bark);
			this->LR_2.set_Connections_EF(this->LR_3);
			this->LR_1.set_Connections_EF(this->LR_2);

			//Obroty
			this->LR_3.rotate(5, false);
			this->LR_2.rotate(3, false);
			this->LR_1.rotate(1, false);
			break;
		
		//Prawa rêka
		case 9:
			//Wi¹zania
			this->PR_3.set_Connections_BC(this->Bark);
			this->PR_2.set_Connections_EF(this->PR_3);
			this->PR_1.set_Connections_EF(this->PR_2);

			//Obroty
			this->PR_3.rotate(5);
			this->PR_2.rotate(3);
			this->PR_1.rotate(1);
			break;
		}
	}
}

void Czlowiek::wiazania_Gora()
{
	this->Kreg1.set_Connections_center(this->Miednica);
	this->Kreg2.set_Connections_EF(this->Kreg1);
	this->Kreg3.set_Connections_EF(this->Kreg2);
	this->Bark.set_Connections_EF(this->Kreg3);
	this->Szyja.set_Connections_center(this->Bark);
	this->Glowa.set_Position(this->Szyja.get_Position_x() + (this->Szyja.get_Dim_szer() + this->Glowa.get_Radius())
		* cosf(this->Szyja.get_Angle() * PI / 180.f), this->Szyja.get_Position_y() - (this->Szyja.get_Dim_szer() +
			this->Glowa.get_Radius()) * sinf(this->Szyja.get_Angle() * PI / 180.f));
	this->LR_3.set_Connections_BC(this->Bark);
	this->LR_2.set_Connections_EF(this->LR_3);
	this->LR_1.set_Connections_EF(this->LR_2);
	this->PR_3.set_Connections_BC(this->Bark);
	this->PR_2.set_Connections_EF(this->PR_3);
	this->PR_1.set_Connections_EF(this->PR_2);
}

void Czlowiek::ALL_UPDATE(Czesc_kolo *Pocisk)
{
	//Ustalenie wi¹zañ i originów
	if (this->wybor_obrotu == 0)
		this->set_Origins(Pocisk);

	//Ustawienie wierzcho³ków wszystkich czêœci i ich obrót
	this->ruchy_i_Obroty(Pocisk);
	this->update_Corners();
}



