#pragma once
#include <math.h>
#include <vector>
#include "SFML/Graphics.hpp"
#include <iostream>

const float PI = 3.1415f;

/// Klasa zawierajaca pozycje ORIGINu czesci ciala.
///
/// Klasa zawierajaca wspolrzedne ORIGINu (pozycja czesci ciala, bedaca
/// jednoczesnie srodkiem obrotu) w dwuwymiarowej przestrzeni i umozliwiajaca dostep do nieg poprzez Settery i Gettery.

class Czesc
{
protected:
	///@{
	/** Wspolrzedna ORIGINu */
	float pozycja_x, pozycja_y;
	///@}
																 
public:
	/// Konstruktor
	///
	/// pozycja_x oraz pozycja_y zainicjowane na 0.
	Czesc();

	/// Destruktor
	~Czesc();

	/// Metoda ustawiajaca ORIGIN w danym miejscu.
	///
	/// @param x Wspolrzedna x ORIGINu.
	/// @param y Wspolrzedna y ORIGINu.
	void set_Position(float x, float y);	

	/// Metoda zwracajaca wspolrzedna x ORIGINu.
	/// @return pozycja_x
	float get_Position_x() const;

	/// Metoda zwracajaca wspolrzedna y ORIGINu.
	/// @return pozycja_y
	float get_Position_y() const;
};