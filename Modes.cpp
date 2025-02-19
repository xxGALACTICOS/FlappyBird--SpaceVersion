#include "Modes.h"
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

Modes::Modes(int a, int b)
{
	font.loadFromFile("Assets/""Jersey20Charted-Regular.ttf");
	mod[0].setString("Levels");
	mod[0].setCharacterSize(80);
	mod[0].setFont(font);
	mod[0].setPosition(Vector2f(100, 300));
	mod[0].setFillColor(Color(0, 95, 106));
	mod[1].setString("Space Mode");
	mod[1].setCharacterSize(80);
	mod[1].setFont(font);
	mod[1].setPosition(Vector2f(100, 500));
	mod[1].setFillColor(Color(204, 204, 195));


	twoone[0].setString("One Player");
	twoone[0].setCharacterSize(80);
	twoone[0].setFont(font);
	twoone[0].setPosition(Vector2f(100, 300));
	twoone[0].setFillColor(Color(0, 95, 106));
	twoone[1].setString("Two Players");
	twoone[1].setCharacterSize(80);
	twoone[1].setFont(font);
	twoone[1].setPosition(Vector2f(100, 500));
	twoone[1].setFillColor(Color(204, 204, 195));


	G_over[0].setString("Restart");
	G_over[0].setCharacterSize(60);
	G_over[0].setFont(font);
	G_over[0].setPosition(100, 250);
	G_over[0].setFillColor(Color(0, 95, 106));
	G_over[1].setString("Go TO Modes");
	G_over[1].setCharacterSize(60);
	G_over[1].setFont(font);
	G_over[1].setPosition(100, 400);
	G_over[1].setFillColor(Color(204, 204, 195));
	G_over[2].setString("MainMenu");
	G_over[2].setCharacterSize(60);
	G_over[2].setFont(font);
	G_over[2].setPosition(100, 550);
	G_over[2].setFillColor(Color(204, 204, 195));

	//options after winning   level3

	win[3].setFont(font);
	win[3].setCharacterSize(100);
	win[3].setPosition(150, 10);
	win[3].setString("What a Player!");
	win[3].setFillColor(Color::Red);

	win[2].setFont(font);
	win[2].setCharacterSize(50);
	win[2].setPosition(150, 880);
	win[2].setString("we will add many levels soon.");
	win[2].setFillColor(Color::White);
	
	win[0].setFont(font);
	win[0].setCharacterSize(80);
	win[0].setPosition(220, 300);
	win[0].setString("Restart");
	win[0].setFillColor(Color(0, 95, 106));

	win[1].setFont(font);
	win[1].setCharacterSize(80);
	win[1].setPosition(220, 500);
	win[1].setString("Mainmenu");
	win[1].setFillColor(Color(204, 204, 195));

	//options after death

	end[2].setFont(font);
	end[2].setString("Game Over");
	end[2].setCharacterSize(100);
	end[2].setFillColor(Color::Red);
	end[2].setPosition(220, 10);

	end[0].setFont(font);
	end[0].setString("Restart");
	end[0].setCharacterSize(70);
	end[0].setFillColor(Color(0,95,106));
	end[0].setPosition(220, 200);

	end[1].setFont(font);
	end[1].setString("Mainmenu");
	end[1].setCharacterSize(70);
	end[1].setFillColor(Color(204,204,195));
	end[1].setPosition(220, 350);
	

	 selec = 0; 
	 selec2 = 0;  
	 selecg = 0;
	 selecwin = 0;
	 selecgameover = 0;
}
void Modes::draw(RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(mod[i]);
	}
}
void Modes::movewinup()
{
	if (selecwin - 1 >= -1)
	{
		win[selecwin].setFillColor(Color(204, 204, 195));
		selecwin--;
	}
	if (selecwin == -1)
	{
		selecwin = 1;
	}
	win[selecwin].setFillColor(Color(0, 95, 106));
}
void Modes::movegameoverup()
{
	if (selecgameover - 1 >= -1)
	{
		end[selecgameover].setFillColor(Color(204, 204, 195));
		selecgameover--;
	}
	if (selecgameover == -1)
	{
		selecgameover = 1;
	}
	end[selecgameover].setFillColor(Color(0, 95, 106));
}
void Modes::movegameoverdown()
{
	if (selecgameover + 1 <= 2)
	{
		end[selecgameover].setFillColor(Color(204, 204, 195));
		selecgameover++;
	}
	if (selecgameover == 2)
	{
		selecgameover = 0;
	}
	end[selecgameover].setFillColor(Color(0, 95, 106));
}
void Modes::movewindown()
{
	if (selecwin + 1 <= 2)
	{
		win[selecwin].setFillColor(Color(204, 204, 195));
		selecwin++;
	}
	if (selecwin == 2)
	{
		selecwin = 0;
	}
	win[selecwin].setFillColor(Color(0, 95, 106));
}
void Modes::drawwin(RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
		window.draw(win[i]);
}
void Modes::drawgameover(RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
		window.draw(end[i]);
}
void Modes::drawplayer(RenderWindow& window)
{
	for (int i = 0; i < 2; i++) {
		window.draw(twoone[i]);
	}
}
void Modes::moveright()
{
	if (selec - 1 >= -1)
	{
		mod[selec].setFillColor(Color(204, 204, 195));
		selec--;
	}
	if (selec == -1)
	{
		selec = 1;
	}
	mod[selec].setFillColor(Color(0, 95, 106));
}
void Modes::moveleft()
{
	if (selec + 1 <= 2)
	{
		mod[selec].setFillColor(Color(204, 204, 195));
		selec++;
	}
	if (selec == 2)
	{
		selec= 0;
	}
	mod[selec].setFillColor(Color(0, 95, 106));
}

void Modes::moveup()
{
	if (selec2 - 1 >= -1)
	{
		twoone[selec2].setFillColor(Color(204, 204, 195));
		selec2--;
	}
	if (selec2 == -1)
	{
		selec2 = 1;
	}
	twoone[selec2].setFillColor(Color(0, 95, 106));
}

void Modes::movedown()
{
	if (selec2 + 1 <= 2)
	{
		twoone[selec2].setFillColor(Color(204, 204, 195));
		selec2++;
	}
	if (selec2 == 2)
	{
		selec2 = 0;
	}
	twoone[selec2].setFillColor(Color(0, 95, 106));
}

void Modes::moveu()
{
	if (selecg - 1 >= -1)
	{
		G_over[selecg].setFillColor(Color(204, 204, 195));
		selecg--;
	}
	if (selecg == -1)
	{
		selecg = 2;
	}
	G_over[selecg].setFillColor(Color(0, 95, 106));
}

void Modes::moved()
{
	if (selecg + 1 <= 3)
	{
		G_over[selecg].setFillColor(Color(204, 204, 195));
		selecg++;
	}
	if (selecg == 3)
	{
		selecg = 0;
	}
	G_over[selecg].setFillColor(Color(0, 95, 106));
}

void Modes::drawGover(RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(G_over[i]);
	}
}

Modes::~Modes()
{

}
