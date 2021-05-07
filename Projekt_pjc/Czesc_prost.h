#pragma once
#include "Czesc.h"

/// Klasa pracujaca na prostokatnych czesciach.
///
/// Klasa zawierajaca wszystkie atrybuty protokata, takie jak: wspolrzedne wierzcholkow, wymiary oraz polozenie katowe.
/// Pozwala ona na ich ustwienie zadajac oczekiwane parametry, np. zadajac miejsce ORIGINu, wymiary oraz polozenie katowe funkcja
/// set_Corners() oblicza nam polozenie wierzcholkow prostokata. Klasa umozliwia rowniez tworzenie relacji (wiazania) miedzy
/// dwoma czesciami prostokatnymi - ruch jednej powoduje okreslony ruch drugiej. Jest w niej rowniez metoda pozwajaca na
/// obrot katowy czesci z okreslona szybkoscia.

class Czesc_prost : public Czesc
{
private:
	///@{
	/** Pozycja wierzcholka */
	float w_B_x, w_B_y, w_A_x, w_A_y, w_C_x, w_C_y, w_D_x, 
		w_D_y, w_E_x, w_E_y, w_F_x, w_F_y;									
	///@}
	float szer;										///< Wymiar prostokata - szerokosc (w osi x).
	float wys;										///< Wymiar prostokata - wysokosc (w osi y).
	float angle;									///< Stopien obrotu.
	bool lewo;										///< Czy dana czesc znajduje sie po lewej stronie korpusu (rece i nogi).
	char origin;									///< Umiejscowienie ORIGINu rowne oznaczeniu wierzcholka (np. 'E' lub 'A').
		
public:
	/// Konstruktor
	///
	/// Defaultowe wartosci atrybutow to: angle = 0, lewo = true, origin = 'E', pozycje wierzcholkow = 0.
	/// @param x Szerokosc prostokata.
	/// @param y Wysokosc prostokata.
	Czesc_prost(float x = 85.f, float y = 20.f);

	/// Destruktor
	~Czesc_prost();

	/// Metoda ustawiajaca wymiary prostokata.
	///
	/// @param width Szerokosc prostokata.
	/// @param height Wysokosc prostokata.
	void set_Dim(float width, float height);
	
	/// Metoda ustawiajaca ORIGIN prostokata.
	///
	/// Ustawia origin w zadanym pukncie. Przy okazji przekazuje infromacje o tym, czy czesc prostokatna
	/// jest z lewej czy prawej strony
	/// @param gdzie_origin ORIGIN prostokata.
	/// @param czy_lewo Czy prostokat znajduje sie po lewej.
	void set_Origin(char gdzie_origin = 'E', bool czy_lewo = true);

	/// Metoda ustawiajaca polozenie katowe prostokata.
	///
	/// @param kat Polozenie katowe.
	void set_Angle(float kat);

	/// Metoda ustawiajaca wierzcholki prostokata.
	///
	/// W zaleznosci od tego, gdzie znajduje sie ORIGIN, funkcja ta ustawia polozenie wierzcholkow
	/// @see set_Origin(char, bool)
	void set_Corners();

	/// Metoda ustawiajaca relacje (wiazania).
	///
	/// Prostokat wykorzystujacy te metode ustawia sie odpowiednio w stosunku do prostokata przekazywanego jako argument.
	/// ORIGIN ustawia sie w punkcie 'E' lub 'F' przekazywanego prostokata.
	/// @param czesc Przekazywany prostokat.
	/// @see Czesc::set_Position(float, float)
	void set_Connections_EF(Czesc_prost& czesc);

	/// Metoda ustawiajaca relacje (wiazania).
	///
	/// Prostokat wykorzystujacy te metode ustawia sie odpowiednio w stosunku do prostokata przekazywanego jako argument.
	/// ORIGIN ustawia sie w punkcie 'B' lub 'C' przekazywanego prostokata.
	/// @param czesc Przekazywany prostokat.
	/// @see Czesc::set_Position(float, float)
	void set_Connections_BC(Czesc_prost& czesc);

	/// Metoda ustawiajaca relacje (wiazania).
	///
	/// Prostokat wykorzystujacy te metode ustawia sie odpowiednio w stosunku do prostokata przekazywanego jako argument.
	/// ORIGIN ustawia sie w srodku przekazywanego prostokata.
	/// @param czesc Przekazywany prostokat.	
	/// @see Czesc::set_Position(float, float)
	void set_Connections_center(Czesc_prost& czesc);

	/// Metoda zwracajaca szerokosc prostokata.
	/// @return szer
	float get_Dim_szer() const;

	/// Metoda zwracajaca wysokosc prostokata.
	/// @return wys
	float get_Dim_wys() const;

	/// Metoda zwracajaca wpolrzedna 'x' punkt 'A' prostokata.
	/// 
	/// Funkcja wykorzystywana do ustawienia obiektu SFML, gdyz prostokaty tworzone w ich bibliotece maja defaultowo ORIGIN
	/// w punkcie 'A'
	/// @return w_A_x
	float get_Corner_A_x() const;

	/// Metoda zwracajaca wpolrzedna 'y' punkt 'A' prostokata.
	/// 
	/// Funkcja wykorzystywana do ustawienia obiektu SFML, gdyz prostokaty tworzone w ich bibliotece maja defaultowo ORIGIN
	/// w punkcie 'A'
	/// @return w_A_y
	float get_Corner_A_y() const;

	/// Metoda zwracajaca polozenie katowe prostokata.
	/// @return angle
	float get_Angle() const;

	/// Metoda odpowiedzialna za obrot prostokata wokol ORIGINu.
	///
	/// Jest 6 poziomow (bieg), im wyzszy, tym szybszy obrot. "cw = true" oznacza, ze obrot jest zgodnie z kierunkiem  ruchu
	/// wskazowek zegara.
	/// @param bieg Predkosc obrotu.
	/// @param cw Kierunek obrotu
	void rotate(int bieg = 5, bool cw = true);
};

