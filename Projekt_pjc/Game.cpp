#include "Game.h"


//Init functions
void Game::init_Zmienne()
{
	this->timeMax = 80;
	this->time = this->timeMax;
}

void Game::init_Window()
{
	this->videoMode = sf::VideoMode(1500, 800);
	this->window = new sf::RenderWindow(this->videoMode, "Matrix", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::init_Fonty()
{
	if (!this->font.loadFromFile("Font/Lato-Medium.ttf"))
	{
		std::cout << "!ERROR!   NIE MOZNA ZALADOWAC FONTA" << "\n";
	}
}

void Game::init_Text()
{
	this->Wyjdz_z_gry.setFont(this->font);
	this->Wyjdz_z_gry.setCharacterSize(24);
	this->Wyjdz_z_gry.setFillColor(sf::Color::White);
	this->Wyjdz_z_gry.setString("Press 'Esc' for exit");
	this->Wyjdz_z_gry.setPosition(float(window->getSize().x) - 300.f, 10.f);

	this->Restart = this->Wyjdz_z_gry;
	this->Restart.setString("Press 'C' for reset");
	this->Restart.setPosition(float(window->getSize().x) - 300.f, 50.f);
}

void Game::init_Pocisk()
{
	this->pocisk = NULL;
}

void Game::init_czesci_Sfml_Vector()
{
	for (int i = 0; i < (this->czlowiek.get_Rect_Objs().size()); i++)
	{
		this->Czesci_sfml.emplace_back();
	}
}

//Constructors and Destructors
Game::Game()
{
	this->init_Zmienne();
	this->init_Window();
	this->init_Fonty();
	this->init_Text();
	this->init_Pocisk();
	this->init_czesci_Sfml_Vector();
	this->czlowiek.Default();
}

Game::~Game()
{
	delete this->window;
	this->delete_Pocisk();
}

//SFML Functions
void Game::set_Size_Sfml()
{
	for (int i = 0; i < (this->czlowiek.get_Rect_Objs().size()); i++)
	{
		this->Czesci_sfml[i].setSize(sf::Vector2f(this->czlowiek.get_Rect_Objs()[i]->get_Dim_szer(), 
			this->czlowiek.get_Rect_Objs()[i]->get_Dim_wys()));
	}
	this->Glowa_sfml.setRadius(this->czlowiek.get_Head().get_Radius());
}

void Game::set_Angle_Sfml()
{
	for (int i = 0; i < (this->czlowiek.get_Rect_Objs().size()); i++)
	{
		this->Czesci_sfml[i].setRotation(-(this->czlowiek.get_Rect_Objs()[i]->get_Angle()));
	}
}

void Game::set_Position_Sfml()
{
	for (int i = 0; i < (this->czlowiek.get_Rect_Objs().size()); i++)
	{
		this->Czesci_sfml[i].setPosition(sf::Vector2f(this->czlowiek.get_Rect_Objs()[i]->get_Corner_A_x(),
			this->czlowiek.get_Rect_Objs()[i]->get_Corner_A_y()));
	}
	this->Glowa_sfml.setOrigin(sf::Vector2f(this->czlowiek.get_Head().get_Radius(), this->czlowiek.get_Head().get_Radius()));
	this->Glowa_sfml.setPosition(sf::Vector2f(this->czlowiek.get_Head().get_Position_x(), 
		this->czlowiek.get_Head().get_Position_y()));	
}

void Game::update_Bullet_Sfml()
{
	this->Pocisk_sfml.setFillColor(sf::Color::Green);	

	if (this->time <= this->timeMax / 3)
	{
		this->Pocisk_sfml.setRadius(this->pocisk->get_Radius());
		this->Pocisk_sfml.setOrigin(sf::Vector2f(this->pocisk->get_Radius(),
			this->pocisk->get_Radius()));
	}		
	if (this->time > this->timeMax / 3)
	{
		this->Pocisk_sfml.setRadius(this->pocisk->get_Radius() * 2.f / 3.f);
		this->Pocisk_sfml.setOrigin(sf::Vector2f(this->pocisk->get_Radius() * 2.f / 3.f,
			this->pocisk->get_Radius() * 2.f / 3.f));
	}
		
	if (this->time > this->timeMax * 2 / 3)
	{
		this->Pocisk_sfml.setRadius(this->pocisk->get_Radius() / 3.f);
		this->Pocisk_sfml.setOrigin(sf::Vector2f(this->pocisk->get_Radius() / 3.f,
			this->pocisk->get_Radius() / 3.f));
	}

	this->Pocisk_sfml.setPosition(sf::Vector2f(this->pocisk->get_Position_x(),
		this->pocisk->get_Position_y()));
}

//Game logic
const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::new_Pocisk()
{
	this->delete_Pocisk();
	this->pocisk = new Czesc_kolo(10.f);	
}

void Game::delete_Pocisk()
{
	if (this->pocisk != NULL)
		delete this->pocisk;
	this->pocisk = NULL;

}

void Game::wydarzenia()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		if (this->sfmlEvent.type == sf::Event::Closed)
		{
			this->window->close();
			this->delete_Pocisk();
		}

		if (this->sfmlEvent.KeyPressed && this->sfmlEvent.key.code == sf::Keyboard::Escape)
		{
			this->window->close();
			this->delete_Pocisk();
		}

		if (this->sfmlEvent.KeyPressed && this->sfmlEvent.key.code == sf::Keyboard::C)			
		{
			this->czlowiek.Default();
			this->delete_Pocisk();
			time = timeMax;
		}
	}
}

void Game::update()
{
	this->wydarzenia();

	if (time >= timeMax)
	{
		this->czlowiek.Default();
		this->delete_Pocisk();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->new_Pocisk();
			this->pocisk->set_Position(float(sf::Mouse::getPosition(*this->window).x),
				float(sf::Mouse::getPosition(*this->window).y));
			time = 0;
		}
	}
	else
		time++;

	if (this->pocisk != NULL)
	{
		czlowiek.ALL_UPDATE(pocisk);
		this->update_Bullet_Sfml();
	}
	this->set_Size_Sfml();
	this->set_Angle_Sfml();
	this->set_Position_Sfml();
	
	
}

void Game::wyswietlanie()
{
	this->window->clear();

	this->window->draw(this->Wyjdz_z_gry);
	this->window->draw(this->Restart);

	for (int i = 0; i < this->Czesci_sfml.size(); i++)
	{
		this->window->draw(this->Czesci_sfml[i]);
	}
	this->window->draw(this->Glowa_sfml);
	if (this->pocisk != NULL)
		this->window->draw(this->Pocisk_sfml);

	this->window->display();
}


