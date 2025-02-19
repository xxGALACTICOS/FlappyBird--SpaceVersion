#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
class Modes
{
public:
	Modes(int a,int b);
	void moveright();
	void moveleft();
	void moveup();
	void movedown();
	void moveu();
	void moved();
	void drawGover(RenderWindow& window);
	void drawplayer(RenderWindow& window);
	void draw(RenderWindow&window);
	void movewinup();
	void movegameoverup();
	void movegameoverdown();
	void movewindown();
	void drawwin(RenderWindow& window);
	void drawgameover(RenderWindow& window);
	int selected()
	{
		return selec;
	}
	int selected2() {
		return selec2;
	}
	int selecG()
	{
		return selecg;
	}
	int select()
	{
		return selecwin;
	}
	int selecgm()
	{
		return selecgameover;
	}


	int selecg;
	int selec;
	int selec2;
	int selecwin;
	int selecgameover;
	Text mod[2];
	Text twoone[2];
	Text G_over[3];
	Text win[4];
	Text end[3];
	Font font;
	~Modes();

};
