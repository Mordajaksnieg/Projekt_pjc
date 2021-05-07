#pragma once
#include "Czesc.h"
#include "Czesc_prost.h"

/** Klasa dotyczaca okraglych czesci. Z tej klasy powstaje glowa oraz pocisk. */

class Czesc_kolo : public Czesc 
{
protected:
	float radius;								///< Promien kola.	
	float bufor;								///< Odleglosc dodatkowa miedzy pociskiem a cialem przy obliczaniu kolizji.
												///< Gwarantuje, ze pocisk mija cialo w wiekszej odleglosci.	
public:
	/// Konstruktor
	///
	/// Atrybut bufor inicjalizowany na 6.
	/// @param r Promien.
	Czesc_kolo(float r = 0.f);

	/// Destruktor
	~Czesc_kolo();


	/// Metoda ustawiajaca promien.
	///
	/// @param r Promien.
	void set_Radius(float r); 

	/// Metoda zwracajaca promien.
	/// @return radius
	float get_Radius() const;	

	/// Metoda sprawdzajaca kolizje.
	///
	/// Zwraca boolowska jedynke jesli wystepuje kolizja pocisku z prostokatna czescia ciala.
	/// @param czesc_ciala Obiekt prostokatnej czesci ciala.
	bool Kolizja(Czesc_prost czesc_ciala) const;

	/// Metoda sprawdzajaca kolizje.
	///
	/// Zwraca boolowska jedynke jesli wystepuje kolizja pocisku z glowa.
	/// @param glowa Obiekt okraglej czesci ciala - glowy.
	bool Kolizja(Czesc_kolo glowa) const;
};

