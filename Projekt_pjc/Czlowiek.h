#pragma once
#include "Czesc_prost.h"
#include "Czesc_kolo.h"

/// Klasa tworzaca czlowieka z czesci prostokatnych i kolowych oraz odpowiedzialna za jego zachowanie.
///
/// Klasa implementuje wszystkie potrzebne czesci prostokatne oraz jedna czesc kolowa - glowe. Zawarta w niej logika odpowiedzialna 
/// jest za zachowanie po kolizji z pociskiem. Wtedy to odpowiednie metody ustawiaja ORIGINy set_Origins(Czesc_kolo*) oraz wykonuja
/// przesuniecia i  obroty ruchy_i_Obroty(Czesc_kolo*). Cale zachowanie zamkniete jest w funkcji ALL_UPDATE(Czesc_kolo*). Dodatkowo
/// klasa ta posiada funkcje Default(), ktora ustawia "czlowieka" w pozycji poczatkowej.

class Czlowiek
{
private:
	///@{
	/** Czesc ciala */
	Czesc_prost LN_1, LN_2, LN_3, LN_4;
	Czesc_prost Miednica;
	Czesc_prost PN_1, PN_2, PN_3, PN_4;
	Czesc_prost Kreg1, Kreg2, Kreg3;
	Czesc_prost Bark;
	Czesc_prost Szyja;
	Czesc_prost LR_1, LR_2, LR_3;
	Czesc_prost PR_1, PR_2, PR_3;
	Czesc_kolo	Glowa;
	///@}

	std::vector<Czesc_prost*> Czesci;				///< Wektora wskaznikow czesi ciala
	float x_B_Miednica;								///< Przechowuje wspolrzedna x wierzcholka B miednicy w trakcie wywolania
													///< kolizji nr 5 (jest stalym parametrem ulatwiajacym obliczanie w ktora strone
													///< czlowiek sie przechyla)
	int wybor_obrotu;								///< Gwarantuje tylko jedna kombinacje ORIGINow, ruchow i obrotow

	/// Metoda inicjalizujaca wektor wskaznikow czesci ciala
	///
	/// Jej wywolanie znajduje sie w konstruktorze
	void init_Czesci_Vector();

	/// Metoda ustawiajaca ORIGINy
	///
	/// Ustawia ORIGINy oraz atrybut wybor_obrotu w zaleznosci od kolizji. 
	/// @param *Pocisk Wskaznik pocisku
	/// @see Czesc_prost::set_Origin(char, bool)
	/// @see Czesc_kolo::Kolizja()
	void set_Origins(Czesc_kolo *Pocisk);

	/// Metoda ustawiajaca wierzcholki prostokatow.
	///
	/// Metoda ta wykorzystuje metode set_Corners() do kazdej z prostokatnej czesci ciala. Jest wykonywana po wykonaniu
	/// ruchow i obrotow.
	void update_Corners();

	/// Metoda wykonujaca ruchy i obroty czesci ciala.
	///
	/// Sekwencja ruchow odpowiadajaca miejscu uderzenia i konczaca sie z chwila, gdy nie ma zadnych  kolizji. Metoda ta ustawie
	/// odpowiednie wiazania miedzy czesciami
	/// @see Czesc_prost::rotate(int, bool)
	/// @see Czesc_prost::set_Connections_EF(Czesc_prost&)
	/// @see Czesc_prost::set_Connections_BC(Czesc_prost&)
	/// @see Czesc_prost::set_Connections_center(Czesc_prost&)
	/// @see Czesc_kolo::Kolizja()
	/// @see wiazania_Gora()
	/// @param *Pocisk Wskaznik pocisku
	void ruchy_i_Obroty(Czesc_kolo* Pocisk);

	/// Metoda wykonujaca wiazania elementow powyzej miednicy
	///
	/// Zebrane w jedna funkcje wiazania elementow powyzej miednicy. Ich relacje sa niezalezne od kolizji (zawsze takie same).
	/// Zbierajac je w jedna metode mozna zmniejszyc ilosc kodu oraz zwiekszyc jego przejrzystosc.
	/// @see Czesc_prost::set_Connections_EF(Czesc_prost&)
	/// @see Czesc_prost::set_Connections_BC(Czesc_prost&)
	/// @see Czesc_prost::set_Connections_center(Czesc_prost&)
	void wiazania_Gora();

public:
	/// Konstruktor
	///
	/// Ustawia promien glowy na 62 (defaultowo 0), inicjalizuje wektor wskaznikow czesci ciala (init_Czesci_Vector()) oraz
	/// ustawia czlowieka w pozycji poczatkowej Default().
	Czlowiek();

	/// Destruktor
	~Czlowiek();

	/// Poczatkowe ustawienie czlowieka
	///
	/// Ustawia dla kazdej czesci jej ORIGIN, polozenie katowe, pozycje (wiazanie), wierzcholki.
	/// Ustawia wartosc zmiennej wybor_obrotu na 0 oraz wartosc zmiennej x_B_Miednica na wartosc wspolrzednej ixowej punktu B
	/// miednicy w pozycji poczatkowej 
	/// @see Czesc_prost::set_Connections_EF(Czesc_prost&)
	/// @see Czesc_prost::set_Connections_BC(Czesc_prost&)
	/// @see Czesc_prost::set_Connections_center(Czesc_prost&)
	/// @see Czesc_prost::set_Origin(char, bool)
	/// @see Czesc_prost::set_Angle(float kat)
	/// @see Czesc_prost::set_Corners()
	void Default();

	/// Zwraca wektor wskaznikow czesci ciala
	/// @return Czesci
	std::vector<Czesc_prost*> get_Rect_Objs() const;

	/// Zwraca czesc ciala - glowe
	/// @return Glowa
	Czesc_kolo get_Head() const;

	/// Metoda wykonujaca kilka innych metod z tej klasy
	///
	/// Jesli wybor_obrotu == 0, to ustawia ona ORIGINy (set_Origins(Czesc_kolo*)), a potem niezaleznie od zmiennej wybor_obrotu
	/// wykonuje metody ruchy_i_Obroty(Czesc_kolo*) i update_Corners()
	void ALL_UPDATE(Czesc_kolo* Pocisk);
};	