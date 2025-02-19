#include "GameOver.h"
#include<SFML/Graphics.hpp>
using namespace sf;
GameOver::GameOver(int widht,int height)
{
	font.loadFromFile("Assets/""Jersey20Charted-Regular.ttf");
	gameO.setString("Game Over");
	gameO.setCharacterSize(110);
	gameO.setPosition(Vector2f(250, 60));
	gameO.setFont(font);
	gameO.setFillColor(Color::Red);
	gameover[0].setString("Restart");
	gameover[0].setCharacterSize(80);
	gameover[0].setFillColor(Color(0, 95, 106));
	gameover[0].setPosition(Vector2f(280, 300));
	gameover[0].setFont(font);
	gameover[1].setString("Go To Next level");
	gameover[1].setCharacterSize(80);
	gameover[1].setFillColor(Color(204, 204, 195));
	gameover[1].setPosition(Vector2f(280, 450));
	gameover[1].setFont(font);
	gameover[2].setString("Main Menu");
	gameover[2].setCharacterSize(80);
	gameover[2].setFillColor(Color(204, 204, 195));
	gameover[2].setPosition(Vector2f(280, 650));
	gameover[2].setFont(font);
	//winning 
	winning[0].setString("Restart");
	winning[1].setString("Next Level");
	winning[2].setString("Main Menu");
	for (int i = 0; i < 3; i++)
	{
		winning[i].setFont(font);
		winning[i].setCharacterSize(80);
	}
	winning[0].setFillColor(Color(0, 95, 106));
	winning[0].setPosition(Vector2f(250, 300));
	winning[1].setFillColor(Color(204, 204, 195));
	winning[1].setPosition(Vector2f(250, 450));
	winning[2].setFillColor(Color(204, 204, 195));
	winning[2].setPosition(Vector2f(250, 600));
	

	selected = 0;
	selected2 = 0;
}
void GameOver::movedown_gameover()
{
	if (selected + 1 <= 3)
	{
		gameover[selected].setFillColor(Color(204, 204, 195));
		selected++;
	}
	if (selected== 3)
	{
		selected = 0;
	}
	gameover[selected].setFillColor(Color(0, 95, 106));

}
void GameOver::moveup_gameover()
{
	if (selected - 1 >= -1)
	{
		gameover[selected].setFillColor(Color(204, 204, 195));
		selected--;
	}
	if (selected == -1)
	{
		selected = 2;
	}
	gameover[selected].setFillColor(Color(0, 95, 106));
}
void GameOver::Draw_gameover(RenderWindow& window)
{
	window.draw(gameO);
	for (int i = 0; i < 3; i++)
	{
		window.draw(gameover[i]);
	}
}

void GameOver::winningdraw(RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(winning[i]);
	}
}

void GameOver::moveup_winning()
{
	if (selected2 - 1 >= -1)
	{
		winning[selected2].setFillColor(Color(135, 206, 235));
		selected2--;
	}
	if (selected2 == -1)
	{
		selected2 = 2;
	}
	winning[selected2].setFillColor(Color(0, 95, 106));
}

void GameOver::movedown_winning()
{
	if (selected2 + 1 <= 3)
	{
		winning[selected2].setFillColor(Color(135, 206, 235));
		selected2++;
	}
	if (selected2 == 3)
	{
		selected2 = 0;
	}
	winning[selected2].setFillColor(Color(0, 95, 106));
}

GameOver::~GameOver()
{
}
