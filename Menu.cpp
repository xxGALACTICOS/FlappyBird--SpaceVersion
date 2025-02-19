#include "Menu.h"
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

Menu::Menu(int width, int height)
{
	font.loadFromFile("Assets/""Jersey20Charted-Regular.ttf");
	// Play
	mainmenu[0].setFont(font);
	mainmenu[0].setString("Play");
	mainmenu[0].setFillColor(Color(0, 95, 106));
	mainmenu[0].setCharacterSize(80);
	mainmenu[0].setPosition(Vector2f(100, 50));
	//Achievement
	mainmenu[1].setFont(font);
	mainmenu[1].setString("Achievement");
	mainmenu[1].setFillColor(Color(204, 204, 195));
	mainmenu[1].setCharacterSize(80);
	mainmenu[1].setPosition(Vector2f(90, 200));
	// About
	mainmenu[2].setFont(font);
	mainmenu[2].setString("About");
	mainmenu[2].setFillColor(Color(204, 204, 195));
	mainmenu[2].setCharacterSize(80);
	mainmenu[2].setPosition(Vector2f(100, 350));
	//Instructions
	
	mainmenu[3].setFont(font);
	mainmenu[3].setString("Instructions");
	mainmenu[3].setFillColor(Color(204, 204, 195));
	mainmenu[3].setCharacterSize(80);
	mainmenu[3].setPosition(Vector2f(100,500));

	//Exit
	mainmenu[4].setFont(font);
	mainmenu[4].setString("Exit");
	mainmenu[4].setFillColor(Color(204, 204, 195));
	mainmenu[4].setCharacterSize(80);
	mainmenu[4].setPosition(Vector2f(100, 650));

	selected = 0;
}
void Menu::draw(RenderWindow & window)
{
	for (int i = 0; i < 5; i++)
	{
		window.draw(mainmenu[i]);
	}
}
void Menu::moveup()
{
	if (selected - 1 >= -1)  //
	{
		mainmenu[selected].setFillColor(Color(204, 204, 195));
		selected--;  //-1
	}
	if (selected == -1)
	{
		selected = 4;
	}
		mainmenu[selected].setFillColor(Color(0, 95, 106));
}
void Menu::moveDown()
{
	if (selected + 1 <= 5)
	{
		mainmenu[selected].setFillColor(Color(204, 204, 195));
		selected++;
	}
	if (selected == 5)
	{
		selected = 0;
	}
		mainmenu[selected].setFillColor(Color(0, 95, 106));
}
void Menu::SetSelected(int n)
{
	selected = n;
}
Menu::~Menu()
{
}
