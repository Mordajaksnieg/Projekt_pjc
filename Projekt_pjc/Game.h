#pragma once
#include "Czlowiek.h"

/// Klasa odpowiedzialna za oddzialywanie z uzytkownikiem oraz za silnik graficzny
///
/// Klasa, ktora tworzy ekran gry oraz wizualizuje go. Reaguje ona na poszczegolne klawisze wcisniete przez uzytkownika oraz
/// lewy przycisk myszy. Jej metody kopiuja czesci ciala z klasy czlowieka do  formy odpowiedniej do wyswietlenia przez SFML
/// 
class Game
{
private:
	//Moje obiekty
	Czlowiek czlowiek;										///< Obiekt klasy czlowiek
	Czesc_kolo* pocisk;										///< Wskaznik do obiektu klasy Czesc_kolo

	//Obiekty SFML
	std::vector<sf::RectangleShape> Czesci_sfml;			///< Wektora czesci ciala SFMLa, odpowiadajacy temu z klasy Czlowiek
	sf::CircleShape Glowa_sfml;								///< Glowa SFMLa
	sf::CircleShape Pocisk_sfml;							///< Pocisk SFMLa
	sf::VideoMode videoMode;								///< Wlasciwosci rozdzielczosci okna SFML
	sf::RenderWindow* window;								///< Wskaznik do dynamicznego tworzenia ona SFML
	sf::Event sfmlEvent;									///< Obiekt klasy pracujacej na inpucie z klawiatury i myszki
	sf::Font font;											///< Obiekt klasy pracujacej na foncie
	sf::Text Wyjdz_z_gry;									///< Obiekt tekstu, ktory umozliwia jego modyfikacje		
	sf::Text Restart;										///< Obiekt tekstu, ktory umozliwia jego modyfikacje

	//Zmienne
	int timeMax;											///< Maksymalny czas zycia pocisku
	int time;												///< Zmienna liczaca, jak dlugo zyje pocisk
	
	/// Inicjalizacja wektora czesci ciala SFML
	///
	/// Rezerwuje on miejsce w wektorze. Inicjalizacja w konstruktorze.
	void init_czesci_Sfml_Vector();

	/// Inizcjalizacja zmiennych
	///
	/// timeMax = 80, time = 80 (jesli time>=timeMax to mozna wystrzelic pocisk). Inicjalizacja w konstruktorze.
	void init_Zmienne();

	/// Inicjalizacja okna
	///
	/// Dynamiczne zaalokowanie okna o rozdzielczosci 1500x800. Ograniczenie FPS do 60. Inicjalizacja w konstruktorze.
	void init_Window();

	/// Zaladowanie fontu z pliku
	///
	/// Metoda zawiera zabezpieczenie w formie komunikatu, jesli nie uda sie zaladowac fontu. Inicjalizacja w konstruktorze.
	void init_Fonty();

	/// Stworzenie tekstu
	///
	/// Metoda przypisuje mu font, rozmiar, polozenie, kolor i tekst. Tworzone sa 2 stringi. Inicjalizacja w konstruktorze.
	void init_Text();

	/// Inicjalizacja wskaznika pocisku
	///
	/// Na NULL. Inicjalizacja w konstruktorze.
	void init_Pocisk();

	/// Metoda dynamicznie tworzaca pocisk
	///
	/// Wpierw wywoluje funkcje delete_Pocisk(), a nastepnie tworzy dynamicznie pocisk o promieniu 10
	void new_Pocisk();

	/// Niszczy obiekt pocisk
	///
	/// Jesli wskaznik pocisku nie jest rowny NULL to niszczy pocisk, a nastepnie ustawia wskaznik na NULL
	void delete_Pocisk();

	/// Metoda reagujaca na input uzytkownika
	///
	/// Klawisz "c" resetuje okno (Czlowiek::Default(), delete_Pocisk(), time=timeMax).
	/// Klawisz "escape" usuwa pocisk delete_Pocisk() oraz zamyka okno
	/// Klikniecie w zamkniecie okna (przycisk "X" w prawym gornym  roku) dziala analogicznie jak "escape"
	void wydarzenia();					

	/// Ustawia rozmiar czesci SFML
	///
	/// Metoda kopiuje rozmiar czesci ciala czlowieka do czesci ciala SFMLa.
	void set_Size_Sfml();

	/// Ustawia polozenie katowe czesci SFML
	///
	/// Metoda kopiuje polozenie katowe czesci ciala czlowieka do czesci ciala SFMLa.
	void set_Angle_Sfml();

	/// Ustawia pozycje czesci SFML
	///
	/// Metoda kopiuje pozycje czesci ciala czlowieka do czesci ciala SFMLa.
	void set_Position_Sfml();

	/// Ustawia parametry pocisku SFML
	///
	/// Metoda kopiuje rozmiar, polozenie katowe oraz pozycje pocisku do pocisku SFMLa.
	void update_Bullet_Sfml();

public:
	/// Konstruktor
	///
	/// Inicjalizuje metody Init oraz wywoluje metode Czlowiek::Default()
	/// @see init_Zmienne()
	/// @see init_Window()
	/// @see init_Fonty()
	/// @see init_Text()
	/// @see init_Pocisk()
	/// @see init_czesci_Sfml_Vector()
	Game();

	/// Destruktor
	///
	/// Wywoluje funkcje delete_Pocisk() oraz usuwa obiekt "window"
	~Game();	

	/// Funkcja sprawdzajaca, czy okno gry jest otwarte
	///
	/// Jesli nie jest, to "main" nie wywoluje logiki gry
	const bool running() const;

	/// Metoda odpowiedzialna za logike gry
	///
	/// Sprawdza, czy wystepuja jakies wydarzenia(). Ustawia czlowieka w pozycji poczatkowej, kasuje (jesli jest) poprzedni
	/// pocisk. Gdy nowy pocisk zostanie wystrzelony (LPM) tworzy nowy pocisk, ustawia go w miejscu pozycji myszki, resetuje czas
	/// zycia pocisku. Do czasu konca zycia pocisku wywoluje metode Czlowiek::ALL_UPDATE(Czesc_kolo*) oraz aktualizuje obiekty
	/// SFMLa poprzez funkcje update_Bullet_Sfml() set_Size_Sfml() set_Angle_Sfml() set_Position_Sfml().
	void update();

	/// Metoda uaktualniajaca widok okna
	///
	/// Wykonuje to w 3 etapach: czysci go, rysuje obiekty SFML, a potem je wyswietla
	void wyswietlanie();
};

