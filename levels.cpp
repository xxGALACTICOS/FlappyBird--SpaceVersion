#include "levels.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

levels::levels(int width, int height)
{
	font.loadFromFile("Assets/""Jersey20Charted-Regular.ttf");
	 
	levelmenu[0].setCharacterSize(80);
	levelmenu[0].setString("Low");
	levelmenu[0].setFillColor(Color(0, 95, 106));
	levelmenu[0].setFont(font);
	levelmenu[0].setPosition(Vector2f(100, 150)); 

	levelmenu[1].setCharacterSize(80);
	levelmenu[1].setString("Medium");
	levelmenu[1].setFillColor(Color(204, 204, 195));
	levelmenu[1].setFont(font);
	levelmenu[1].setPosition(Vector2f(100, 350)); 

	levelmenu[2].setCharacterSize(80);
	levelmenu[2].setString("Hard");
	levelmenu[2].setFillColor(Color(204, 204, 195));
	levelmenu[2].setFont(font);
	levelmenu[2].setPosition(Vector2f(100, 550));

	selected2 = 0;

}

void levels::draw(RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(levelmenu[i]);
	}
}

void levels::moveUp()
{
	if (selected2 - 1 >= -1)
	{
		levelmenu[selected2].setFillColor(Color(204, 204, 195));
		selected2--;
	}
	if (selected2 == -1)
	{
		selected2 = 2;
	}
	levelmenu[selected2].setFillColor(Color(0, 95, 106));
}

void levels::moveDown()
{
	if (selected2 + 1 <= 3)
	{
		levelmenu[selected2].setFillColor(Color(204, 204, 195));
		selected2++;
	}
	if (selected2 == 3)
	{
		selected2 = 0;
	}
	levelmenu[selected2].setFillColor(Color(0, 95, 106));
}

void levels::setselected(int n)
{
	selected2 = n;
}

levels::~levels()
{
}

