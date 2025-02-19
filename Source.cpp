#include "GameOver.h"
#include "Menu.h"
#include "Modes.h"
#include "ShowingOptions.h"
#include "levels.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using namespace sf;
struct PiPe {
  Sprite topPipe;
  Sprite bottomPipe;
  Sprite topp2;
  Sprite bottomp2;
  bool passed = false;
};
struct Bird {

  string name;
  string opponentname;
  int score = 0;
  int count8 = 0;
  int i = 0;
  // Bird setup

  float birdVelocity = 0.0f;
  float birdVelocity2 = 0.0f;
  float gravity = 0.5f;
  float gravity2 = 0.5f;
  Texture player;
  Texture player2;
  Texture player3;
  RectangleShape bird;
  RectangleShape bird2;
  RectangleShape bird3;
  void Atrributes() {
    player.loadFromFile("Assets/"
                        "bird1.png");
    bird.setTexture(&player);
    bird.setPosition(Vector2f(300, 400));
    bird.setSize(Vector2f(125, 100));
    bird.setScale(0.4, 0.3);
    bird.setTextureRect(IntRect(0, 0, 255, 180));
    bird.setOrigin(Vector2f(62.5, 50));
    player2.loadFromFile("Assets/"
                         "bird6.png");
    bird2.setTexture(&player2);
    bird2.setPosition(Vector2f(300, 400));
    bird2.setSize(Vector2f(125, 100));
    bird2.setScale(0.4, 0.3);
    bird2.setTextureRect(IntRect(0, 0, 68, 48));
    bird2.setOrigin(Vector2f(62.5, 50));
    player3.loadFromFile("Assets/"
                         "bird5.png");
    bird3.setTexture(&player3);
    bird3.setPosition(Vector2f(300, 400));
    bird3.setSize(Vector2f(125, 100));
    bird3.setScale(0.4, 0.3);
    bird3.setTextureRect(IntRect(0, 0, 68, 48));
    bird3.setOrigin(Vector2f(62.5, 50));
  }
  void animation() {
    count8++;
    if (count8 % 10 == 0) {
      i++;
    }
    i %= 3;
    bird.setTextureRect(IntRect((i * 255), 0, 255, 180));
  }
  void animation2() {
    count8++;
    if (count8 % 10 == 0) {
      i++;
    }

    i %= 3;
    bird2.setTextureRect(IntRect((i * 68), 0, 68, 48));
  }
  void animation3() {
    count8++;
    if (count8 % 10 == 0) {
      i++;
    }
    i %= 3;
    bird3.setTextureRect(IntRect((i * 68), 0, 68, 48));
  }

} Flappy;
struct Pipe {
  float amplitude = 50;  // Amplitude of the movement
  float frequency = 0.7; // Frequency of the movement
  float time = 0;

  float gap = 550;
  Texture Pipetp, Pipebm, flag, pipetpl2, pipebml2, pipebml3, pipetpl3;
  Sprite PipeOftop[25], PipeOfbottom[25], Pipetopl2[40], Pipebottoml2[40],
      Pipebottoml3[60], Pipetopl3[60];
  void attributes() {
    Pipetp.loadFromFile("Assets/"
                        "pipe.png");
    Pipebm.loadFromFile("Assets/"
                        "coloumn.png");
    pipetpl2.loadFromFile("Assets/"
                          "top.png");
    pipebml2.loadFromFile("Assets/"
                          "colomnbottom_lvl2.png");
    pipebml3.loadFromFile("Assets/"
                          "columnbottom_lvl3.png");
    pipetpl3.loadFromFile("Assets/"
                          "columntop_lvl3.png");
    for (int i = 0; i < 25; i++) {
      PipeOftop[i].setTexture(Pipetp);
      PipeOfbottom[i].setTexture(Pipebm);
    }

    for (int i = 0; i < 40; i++) {
      Pipetopl2[i].setTexture(pipetpl2);
      Pipebottoml2[i].setTexture(pipebml2);
      Pipetopl2[i].setScale(2, 2);
      Pipebottoml2[i].setScale(2, 2);
      Pipetopl2[i].setOrigin(0, 150);
    }
    for (int i = 0; i < 60; i++) {
      Pipebottoml3[i].setTexture(pipebml3);
      Pipebottoml3[i].setScale(2, 2);
      Pipetopl3[i].setTexture(pipetpl3);
      Pipetopl3[i].setScale(2, 2);
      Pipetopl3[i].setOrigin(0, 150);
    }
  }
  void setPositionsl1() {

    for (int i = 0; i < 10; i++) {
      PipeOfbottom[i].setPosition(Vector2f(1200 + (i * 350), 510));
      PipeOfbottom[i].setScale(3, 2.5);
    }

    for (int i = 10; i < 20; i++) {
      PipeOfbottom[i].setPosition(Vector2f(5000 + (i * 75), 510));
      PipeOfbottom[i].setScale(3, 2.5);
    }

    for (int i = 20; i < 25; i += 2) {
      PipeOfbottom[i].setPosition(Vector2f(2500 + (i * 250), 500));
      PipeOfbottom[i].setScale(3, 2.6);
    }
    for (int i = 21; i < 25; i += 2) {
      PipeOfbottom[i].setPosition(Vector2f(2500 + (i * 250), 555));
      PipeOfbottom[i].setScale(3, 2.2);
    }

    for (int i = 0; i < 10; i++) {
      PipeOftop[i].setPosition(Vector2f(1200 + (i * 350), 1));
      PipeOftop[i].setScale(3.0, 2.6);
    }

    for (int i = 10; i < 20; i++) {
      PipeOftop[i].setPosition(Vector2f(5000 + (i * 75), 2));
      PipeOftop[i].setScale(3, 2.6);
    }

    for (int i = 20; i < 25; i += 2) {
      PipeOftop[i].setPosition(Vector2f(2500 + (i * 250), 2));
      PipeOftop[i].setScale(3, 2.4);
    }
    for (int i = 21; i < 25; i += 2) {
      PipeOftop[i].setPosition(Vector2f(2500 + (i * 250), 2));
      PipeOftop[i].setScale(3, 3);
    }
  }
  void setPositionl2() {
    // Positions of first 5 pipes
    for (int i = 0; i < 5; i++) {
      Pipebottoml2[i].setPosition(Vector2f(1200 + (i * 350), 530 - i * 60));
    }

    // Position of 6~10 pipes
    for (int i = 5; i < 10; i++) {
      Pipebottoml2[i].setPosition(Vector2f(
          1200 + (i * 350), Pipebottoml2[i - 1].getPosition().y + i * 10));
    }

    // Position of 10~15 pipes
    for (int i = 10; i < 15; i += 2) {
      Pipebottoml2[i].setPosition(Vector2f(1200 + (i * 350), 450 - i * 2));
      Pipebottoml2[11].setPosition(Vector2f(1200 + (11 * 350), 310));
      Pipebottoml2[13].setPosition(Vector2f(1200 + (13 * 350), 650));
      Pipebottoml2[15].setPosition(Vector2f(1200 + (15 * 350), 300));
    }
    // Position of 15~20 TOP pipes
    for (int i = 15; i < 20; i += 2) {
      Pipebottoml2[i].setPosition(Vector2f(1200 + (i * 350), 500));
    }
    // Position of 15~20 BOTTOM pipes
    for (int i = 16; i < 20; i += 2) {

      Pipebottoml2[i].setPosition(Vector2f(1200 + (i * 350), 350));
    }
    // Position of 20~27 pipes
    for (int i = 20; i < 27; i++) {
      Pipebottoml2[20].setPosition(Vector2f(1200 + (20 * 350), 290));
      Pipebottoml2[i].setPosition(Vector2f(
          1200 + (i * 350), Pipebottoml2[i - 1].getPosition().y + i * 3));
    }
    // Position of 27~33 pipes
    for (int i = 27; i < 33; i++) {
      Pipebottoml2[20].setPosition(Vector2f(1200 + (20 * 350), 290));
      Pipebottoml2[i].setPosition(Vector2f(
          1200 + (i * 350), Pipebottoml2[i - 1].getPosition().y - i * 2));
    }
    // Position of 33~40 pipes
    for (int i = 33; i < 40; i++) {
      Pipebottoml2[33].setPosition(Vector2f(1200 + (33 * 350), 680));
      Pipebottoml2[i].setPosition(
          Vector2f(Pipebottoml2[i - 1].getPosition().x + i * 5, 680));
    }
    // Positions of first 5 top pipes
    for (int i = 0; i < 5; i++) {
      Pipetopl2[i].setPosition(Vector2f(1200 + (i * 350), 1 - i * 60));
    }
    // Position of 6~10 pipes
    for (int i = 5; i < 10; i++) {
      Pipetopl2[i].setPosition(Vector2f(
          1200 + (i * 350), Pipetopl2[i - 1].getPosition().y + i * 10));
    }
    // Position of 10~15 pipes
    for (int i = 10; i < 15; i += 2) {
      Pipetopl2[i].setPosition(Vector2f(1200 + (i * 350), -79 - i * 2));
      Pipetopl2[11].setPosition(Vector2f(1200 + (11 * 350), -219));
      Pipetopl2[13].setPosition(Vector2f(1200 + (13 * 350), 131));
      Pipetopl2[15].setPosition(Vector2f(1200 + (15 * 350), -229));
    }
    // Position of 15~20 TOP pipes

    for (int i = 15; i < 20; i += 2) {
      Pipetopl2[i].setPosition(Vector2f(1200 + (i * 350), -29));
    }
    // Position of 15~20 BOTTOM pipes
    for (int i = 16; i < 20; i += 2) {
      Pipetopl2[i].setPosition(Vector2f(1200 + (i * 350), -179));
    }
    // Position of 20~25 pipes
    for (int i = 20; i < 27; i++) {
      Pipetopl2[20].setPosition(Vector2f(1200 + (20 * 350), -239));
      Pipetopl2[i].setPosition(
          Vector2f(1200 + (i * 350), Pipetopl2[i - 1].getPosition().y + i * 3));
    }
    // Position of 27~33 pipes
    for (int i = 27; i < 33; i++) {
      Pipetopl2[20].setPosition(Vector2f(1200 + (20 * 350), -239));
      Pipetopl2[i].setPosition(
          Vector2f(1200 + (i * 350), Pipetopl2[i - 1].getPosition().y - i * 2));
    }
    // Position of 33~40 pipes
    for (int i = 33; i < 40; i++) {
      Pipetopl2[33].setPosition(Vector2f(1200 + (33 * 350), 151));
      Pipetopl2[i].setPosition(
          Vector2f(Pipetopl2[i - 1].getPosition().x + i * 5, 151));
    }
  }
  // SET POSITIONS

  void setPositionl3() {

    /*warning.setPosition(7400, 400);*/

    for (int i = 0; i < 5; i++) {
      // BOTTOM
      Pipebottoml3[i].setPosition(Vector2f(1200 + (i * 310), 510));
      // TOP
      Pipetopl3[i].setPosition(Vector2f(1200 + (i * 310), 1));
    }
    for (int i = 5; i < 10; i++) {
      // BOTTOM
      Pipebottoml3[6].setPosition(Vector2f(3500, 510));
      Pipebottoml3[i].setPosition(Vector2f(
          Pipebottoml3[i - 1].getPosition().x + (i * 30), 510 - i * (8)));
      Pipebottoml3[5].setPosition(Vector2f(3000, 510));
      Pipebottoml3[8].setPosition(
          Vector2f(Pipebottoml3[7].getPosition().x + (8 * 30), 600 + 50));
      Pipebottoml3[9].setPosition(
          Vector2f(Pipebottoml3[8].getPosition().x + (9 * 30), 540));
      // TOP
      Pipetopl3[i].setPosition(
          Vector2f(Pipetopl3[i - 1].getPosition().x + (i * 30), 1 - i * (8)));
      Pipetopl3[5].setPosition(Vector2f(3000, 1));
      Pipetopl3[6].setPosition(Vector2f(3500, 1));
      Pipetopl3[8].setPosition(
          Vector2f(Pipetopl3[7].getPosition().x + (8 * 30), 70 + 50));
      Pipetopl3[9].setPosition(
          Vector2f(Pipetopl3[8].getPosition().x + (9 * 30), -41));
    }
    for (int i = 10; i < 15; i++) {
      // BOTTOM
      Pipebottoml3[i].setPosition(
          Vector2f(1200 + (i * 310) + 200, 580 - (i * 29)));
      Pipebottoml3[10].setPosition(
          Vector2f(1200 + (10 * 310) + 200, 610 - (10 * 29)));
      // TOP
      Pipetopl3[i].setPosition(Vector2f(1200 + (i * 310) + 200, 50 - (i * 29)));
      Pipetopl3[10].setPosition(
          Vector2f(1200 + (10 * 310) + 200, 80 - (10 * 29)));
    }
    for (int i = 15; i < 20; i++) {
      // BOTTOM
      Pipebottoml3[i].setPosition(
          Vector2f(1200 + (i * 310) + 150, 570 + (i * 20)));
      Pipebottoml3[15].setPosition(
          Vector2f(1200 + (15 * 310) + 200, 510 + 15 * 20));
      Pipebottoml3[19].setPosition(
          Vector2f(1200 + (19 * 310) + 200, 580 + 19 * 20));
      // TOP
      Pipetopl3[i].setPosition(Vector2f(1200 + (i * 310) + 150, 40 + (i * 20)));
      Pipetopl3[15].setPosition(
          Vector2f(1200 + (15 * 310) + 200, -20 + (15 * 20)));
      Pipetopl3[19].setPosition(
          Vector2f(1200 + (19 * 310) + 200, 50 + (19 * 20)));
    }
    for (int i = 20; i < 30; i++) {
      // BOTTOM
      Pipebottoml3[i].setPosition(Vector2f(2500 + (i * 330), 510));
      Pipebottoml3[22].setPosition(Vector2f(2500 + (22 * 330), 750));
      Pipebottoml3[24].setPosition(Vector2f(2500 + (24 * 330), 580));
      Pipebottoml3[27].setPosition(Vector2f(2500 + (27 * 330), 480));
      // TOP
      Pipetopl3[i].setPosition(Vector2f(2500 + (i * 330), 1));
      Pipetopl3[22].setPosition(Vector2f(2500 + (22 * 330), 220));
      Pipetopl3[24].setPosition(Vector2f(2500 + (24 * 330), 51));
      Pipetopl3[27].setPosition(Vector2f(2500 + (27 * 330), -49));
    }

    // individual sequence

    Pipebottoml3[30].setPosition(Vector2f(2300 + (30 * 400), 520));
    Pipebottoml3[31].setPosition(Vector2f(2300 + (31 * 400), 530 + 1 * 100));
    Pipebottoml3[33].setPosition(Vector2f(2300 + (33 * 400), 530 + 3 * 80));
    Pipebottoml3[35].setPosition(Vector2f(2300 + (35 * 400), 700 - 5 * 60));
    Pipebottoml3[36].setPosition(Vector2f(2300 + (36 * 400), 700 - 6 * 50));
    Pipebottoml3[38].setPosition(Vector2f(2300 + (38 * 400), 700 - 8 * 23));
    Pipebottoml3[39].setPosition(Vector2f(2300 + (39 * 400), 500 - 9 * 20));
    Pipebottoml3[42].setPosition(Vector2f(2300 + (42 * 400), 330));
    Pipebottoml3[44].setPosition(Vector2f(2300 + (44 * 400), 790));
    Pipebottoml3[46].setPosition(
        Vector2f(2300 + ((46) * 400), 880 - (46 - 30) * 30));
    Pipebottoml3[51].setPosition(Vector2f(2300 + ((51) * 400), 425));
    Pipebottoml3[58].setPosition(Vector2f(2300 + (58 * 400), 500));
    Pipebottoml3[59].setPosition(Vector2f(2300 + (59 * 400), 790));
    Pipetopl3[31].setPosition(Vector2f(2300 + (31 * 400), 1 + 1 * 100));
    Pipetopl3[33].setPosition(Vector2f(2300 + (33 * 400), 1 + 3 * 80));
    Pipetopl3[35].setPosition(Vector2f(2300 + (35 * 400), 1 - 5 * 20));
    Pipetopl3[36].setPosition(Vector2f(2300 + (36 * 400), 1 - 6 * 15));
    Pipetopl3[38].setPosition(Vector2f(2300 + (38 * 400), 40));
    Pipetopl3[39].setPosition(Vector2f(2300 + (39 * 400), 1 - 9 * 20));
    Pipetopl3[42].setPosition(Vector2f(2300 + (42 * 400), -200));
    Pipetopl3[43].setPosition(Vector2f(2300 + (43 * 400), 20));
    Pipetopl3[44].setPosition(Vector2f(2300 + (44 * 400), 250));
    Pipetopl3[46].setPosition(
        Vector2f(2300 + ((46) * 400), 400 - (46 - 30) * 30));
    Pipetopl3[51].setPosition(Vector2f(2300 + ((51) * 400), -105));
    Pipetopl3[58].setPosition(Vector2f(2300 + (58 * 400), -29));
    Pipetopl3[59].setPosition(Vector2f(2300 + (59 * 400), 250));

    for (int i = 30; i <= 33; i += 2) {
      // Bottom
      Pipebottoml3[i].setPosition(
          Vector2f(2300 + ((i) * 400), 520 - (i - 30) * 60));
      // Top
      Pipetopl3[i].setPosition(Vector2f(2300 + ((i) * 400), 1 - (i - 30) * 60));
    }

    for (int i = 34; i <= 40; i += 3) {
      // Bottom
      Pipebottoml3[i].setPosition(
          Vector2f(2300 + ((i) * 400), 530 - (i - 30) * -30));
      // Top
      Pipetopl3[i].setPosition(
          Vector2f(2300 + ((i) * 400), 1 - (i - 30) * -30));
    }
    for (int i = 41; i <= 44; i += 2) {
      // Bottom
      Pipebottoml3[i].setPosition(Vector2f(2300 + ((i) * 400), (i - 30) * 50));
      // Top
      Pipetopl3[i].setPosition(Vector2f(2300 + ((i) * 400), (i - 30) * -5));
    }

    for (int i = 45; i <= 50; i++) {
      // Bottom
      Pipebottoml3[i].setPosition(
          Vector2f(2300 + ((i) * 400), 880 - (i - 30) * 25));
      // Top
      Pipetopl3[i].setPosition(
          Vector2f(2300 + ((i) * 400), 400 - (i - 30) * 25));
    }
    for (int i = 51; i <= 56; i++) {
      // Bottom
      Pipebottoml3[i].setPosition(
          Vector2f(2300 + ((i) * 400),
                   Pipebottoml3[i - 1].getPosition().y + (i - 30) * 3));
      // Top
      Pipetopl3[i].setPosition(Vector2f(
          2300 + ((i) * 400), Pipetopl3[i - 1].getPosition().y + (i - 30) * 3));
    }
    for (int i = 57; i < 60; i += 2) {
      // Bottom
      Pipebottoml3[i].setPosition(Vector2f(2300 + ((i) * 400), (i - 30) * 25));
      // Top
      Pipetopl3[i].setPosition(Vector2f(2300 + ((i) * 400), (i - 30) * 3));
    }
  }

  void draw(RenderWindow &window) {
    for (int i = 0; i < 25; i++) {
      window.draw(PipeOfbottom[i]);
      window.draw(PipeOftop[i]);
    }
  }
  void drawl2(RenderWindow &window) {
    for (int i = 0; i < 40; i++) {
      window.draw(Pipetopl2[i]);
      window.draw(Pipebottoml2[i]);
    }
  }
  void drawl3(RenderWindow &window) {
    for (int i = 0; i < 60; i++) {
      window.draw(Pipebottoml3[i]);
      window.draw(Pipetopl3[i]);
    }
  }
  void move(int a, int b) {

    for (int i = 0; i < 25; i++) {
      PipeOftop[i].move(-a, b);
      PipeOfbottom[i].move(-a, b);
    }
  }
  void movelevel2(int a, int b) {
    for (int i = 0; i < 40; i++) {
      Pipetopl2[i].move(-a, b);
      Pipebottoml2[i].move(-a, b);
    }
  }
  void movel3(int a, int b) {
    for (int i = 0; i < 60; i++) {
      Pipetopl3[i].move(-a, b);
      Pipebottoml3[i].move(-a, b);
    }
  }
  // Pipe Move

  void pipemovel3() {

    for (int i = 0; i < 3; i++) {
      time += 0.1;
      float Vib_top = amplitude * sin(frequency * time);
      float Vib_bottom = 1100 - gap + amplitude * sin(frequency * time);

      Pipetopl3[2 * i + 1].setPosition(
          Vector2f(Pipetopl3[2 * i + 1].getPosition().x, Vib_top - i * 10));
      Pipebottoml3[2 * i + 1].setPosition(Vector2f(
          Pipebottoml3[2 * i + 1].getPosition().x, Vib_bottom - i * 10));
      Pipetopl3[20].setPosition(
          Vector2f(Pipetopl3[20].getPosition().x, Vib_top - i * 10));
      Pipebottoml3[20].setPosition(
          Vector2f(Pipebottoml3[20].getPosition().x, Vib_bottom - i * 10));
      Pipetopl3[26].setPosition(
          Vector2f(Pipetopl3[26].getPosition().x, Vib_top - i * 10));
      Pipebottoml3[26].setPosition(
          Vector2f(Pipebottoml3[26].getPosition().x, Vib_bottom - i * 10));
      Pipetopl3[28].setPosition(
          Vector2f(Pipetopl3[28].getPosition().x, Vib_top - i * 10));
      Pipebottoml3[28].setPosition(
          Vector2f(Pipebottoml3[28].getPosition().x, Vib_bottom - i * 10));
      if (Flappy.bird.getPosition().x == Pipetopl3[4].getPosition().x) {

        Pipetopl3[4].move(4, 0);
        Pipebottoml3[4].move(4, 0);

      } else if (Pipebottoml3[4].getPosition().x >=
                 Pipebottoml3[6].getPosition().x - 100) {
        Pipetopl3[4].move(-8, 0);
        Pipebottoml3[4].move(-8, 0);
      }
    }
    for (int i = 10; i < 15; i++) {
      if (Flappy.bird.getPosition().x >= Pipetopl3[10].getPosition().x) {

        Pipetopl3[i].move(0, 1.5);
        Pipebottoml3[i].move(0, 1.5);
      }
    }

    for (int i = 15; i < 20; i++) {
      if (Flappy.bird.getPosition().x >= Pipetopl3[15].getPosition().x) {

        Pipetopl3[i].move(0, -2);
        Pipebottoml3[i].move(0, -2);
      }
    }

    for (int i = 21; i < 30; i += 4) {

      if (Flappy.bird.getPosition().x >= Pipetopl3[i - 1].getPosition().x) {

        Pipetopl3[i].move(0, -2);
        Pipebottoml3[i].move(0, -2);
      }
    }
    for (int i = 23; i < 30; i += 4) {

      if (Flappy.bird.getPosition().x >= Pipetopl3[i - 1].getPosition().x) {

        Pipetopl3[i].move(0, 2);
        Pipebottoml3[i].move(0, 2);
      }
    }
  }

} levelonepipes, level2, level3;
struct bommm {
  int count10 = 0;
  int m = 0;
  int ii = 0;

  Texture fire1, fire2;
  Sprite Fireworks1[20], Fireworks2[20];
  Texture Fire1;
  Sprite Btngan1;
  void attributes() {
    Fire1.loadFromFile("Assets/"
                       "BOM.png");
    Btngan1.setPosition(Vector2f(0, 0));
    Btngan1.setTexture(Fire1);
    Btngan1.setScale(2, 2);
    Btngan1.setTextureRect(IntRect(0, 0, 475, 400));
  }

  void Fireworks() {

    for (int i = 0; i < 20; i++) {
      fire1.loadFromFile("Assets/"
                         "bom1.png");
      Fireworks1[i].setTexture(fire1);
      Fireworks1[i].setScale(1.4, 1.3);
      Fireworks1[i].setTextureRect(IntRect(0, 0, 140, 193));
      Fireworks1[i].setPosition(Vector2f(rand() % 700, rand() % 500));

      fire2.loadFromFile("Assets/"
                         "bom2.png");
      Fireworks2[i].setTexture(fire2);
      Fireworks2[i].setScale(1.4, 1.3);
      Fireworks2[i].setTextureRect(IntRect(0, 0, 140, 196));

      Fireworks2[i].setPosition(Vector2f(rand() % 700, rand() % 500));
    }
  }

  void Fireworks_animation() {

    count10++;
    if (count10 % 10 == 0)
      m++;

    m %= 4;
    Btngan1.setTextureRect(IntRect((m * 475), 0, 475, 400));
  }
  void draw_Fireworks(RenderWindow &window) { window.draw(Btngan1); }
} bomm1;
struct Flags {

  Texture f1, f2, f3;
  Sprite flag1, flag2, flag3;
  void Attributes_flag1() {
    f1.loadFromFile("Assets/"
                    "FLAG L11.png");
    flag1.setTexture(f1);
    flag1.setPosition(9200, 10);
  }
  void Attributes_flag2() {
    f2.loadFromFile("Assets/"
                    "FLAG L22.png");
    flag2.setTexture(f2);
    flag2.setPosition(15400, 10);
  }
  void Attributes_flag3() {
    f3.loadFromFile("Assets/"
                    "FLAG L3.png");
    flag3.setTexture(f3);
    flag3.setPosition(26300, 10);
  }
} Flag;
struct sship {
  int birdVelocity = 0;
  int gravity = 0.5;
  int count8 = 0;
  int T = 0;
  RectangleShape b[6];
  RectangleShape b1[5];
  RectangleShape b2[5];

  void Spaceship_body() {

    for (int i = 0; i < 6; i++) {

      b[i].setFillColor(Color::Black);
      b[i].setScale(1, 1);
    }

    b[0].setSize(Vector2f(42, 13));
    b[1].setSize(Vector2f(24, 12));
    b[2].setSize(Vector2f(18, 5));
    b[3].setSize(Vector2f(8, 6));
    b[4].setSize(Vector2f(6, 4));
    b[5].setSize(Vector2f(6, 4));
  }
  void spaceship_position() {
    b[0].setPosition(308, 417);
    b[1].setPosition(317, 407);
    b[2].setPosition(320, 404);
    b[3].setPosition(325, 402);
    b[4].setPosition(349, 422);
    b[5].setPosition(303, 422);
  }
  void Spaceship_body_2p1() {

    for (int i = 0; i < 5; i++) {

      b1[i].setFillColor(Color::Black);
      b1[i].setScale(1, 1);
    }

    b1[0].setSize(Vector2f(18, 12));
    b1[1].setSize(Vector2f(10, 12));
    b1[2].setSize(Vector2f(4, 6));
    b1[3].setSize(Vector2f(6, 4));
    b1[4].setSize(Vector2f(6, 4));
  }
  void spaceship_position_2p1() {
    b1[0].setPosition(156, 413);
    b1[1].setPosition(159, 404);
    b1[2].setPosition(163, 402);
    b1[3].setPosition(171, 417);
    b1[4].setPosition(152, 417);
  }
  void Spaceship_body_2p2() {

    for (int i = 0; i < 5; i++) {

      b2[i].setFillColor(Color::Black);
      b2[i].setScale(1, 1);
    }

    b2[0].setSize(Vector2f(18, 12));
    b2[1].setSize(Vector2f(10, 12));
    b2[2].setSize(Vector2f(4, 6));
    b2[3].setSize(Vector2f(6, 4));
    b2[4].setSize(Vector2f(6, 4));
  }
  void spaceship_position_2p2() {
    b2[0].setPosition(606, 413);
    b2[1].setPosition(609, 404);
    b2[2].setPosition(613, 402);
    b2[3].setPosition(621, 417);
    b2[4].setPosition(602, 417);
  }
  void spaceship_move() {
    for (int k = 0; k < 6; k++) {
      b[k].move(0, Flappy.birdVelocity);
    }
  }

  void spaceship_move_2p() {
    for (int k = 0; k < 5; k++) {
      b1[k].move(0, Flappy.birdVelocity);
      b2[k].move(0, Flappy.birdVelocity2);
    }
  }
  void draw_Spaceship_body(RenderWindow &window) {
    for (int ii = 0; ii < 6; ii++) {
      window.draw(b[ii]);
    }
  }
  void draw_Spaceship_body_2p(RenderWindow &window) {
    for (int ii = 0; ii < 5; ii++) {
      window.draw(b1[ii]);
      window.draw(b2[ii]);
    }
  }

} spaceship10;

struct Alien {
  int count8 = 0;
  int T = 0;
  Texture ship, ship1, ship2;
  Sprite Spaceship;
  Sprite spaceship[2];
  void Spaceship1() {

    ship.loadFromFile("Assets/"
                      "Spaceship blue.png");
    Spaceship.setTexture(ship);
    Spaceship.setScale(1, 1);
    Spaceship.setTextureRect(IntRect(0, 0, 58, 38));
    Spaceship.setPosition(Vector2f(300, 400)); // for space mode
  }
  void Spaceship_2p() {
    ship1.loadFromFile("Assets/"
                       "Spaceship red.png");
    ship2.loadFromFile("Assets/"
                       "Spaceship white.png");

    spaceship[0].setTexture(ship1);
    spaceship[1].setTexture(ship2);
    for (int i = 0; i < 2; i++) {
      spaceship[i].setScale(0.5, 0.8);
      spaceship[i].setTextureRect(IntRect(0, 0, 58, 38));
    }

    /// positions

    spaceship[0].setPosition(Vector2f(150, 400));
    spaceship[1].setPosition(Vector2f(600, 400));
  }
  void spaceship_animation() {
    count8++;
    if (count8 % 7 == 0)
      T++;
    T %= 12;
    Spaceship.setTextureRect(IntRect((T * 58), 0, 58, 38));
  }
  void spaceship_animation_2p() {
    count8++;
    if (count8 % 7 == 0)
      T++;
    T %= 12;
    spaceship[0].setTextureRect(IntRect((T * 58), 0, 58, 38));
  }
  void animationforrightp() {
    count8++;
    if (count8 % 7 == 0)
      T++;
    T %= 12;
    spaceship[1].setTextureRect(IntRect((T * 58), 0, 58, 38));
  }

} monster;

static const float viewwidth = 900;
static const float viewheight = 1000;
float PIPE_SPEED = 5;
int Gap_y = 100;
float twoplayersspeed = 3.5;
float speed_y = 0;
float twoplayersspeed_y = 0;
float pipeOffset = 0;
float pipeOffset2 = 0;
float BirdIndex = 0; // factor we multiply it to scale of bird
int difficulty2 = 150;
int difficulty = 150;
int j = 0; // BirdIndex of level1
int n = 0; // BirdIndex of level2
int f = 0; // BirdIndex of level3
int count3 = 0;
int y =
    0; // To change position of pipe in y to make random sequence (first player)
int y2 =
    0; // To change position of pipe in y to make random sequence (two player)
int pagenum = 1000; // pages of our game
int pipeCount = 0;
int count2 = 0;      // count that determine the collision
int scores[60] = {}; // scores[0] always the higher score
int it = 0;          // BirdIndex of scores
int countofplayers = 0;
int countenter = 0;

bool lsa = false;    // check point on the first game that tell me player didn't
                     // press space yet
bool finish = false; // check point on collision scope
bool r = true;       // check point to show the winning or gameover
bool khbt = true;
bool rightplayerwin = false;
bool leftplayerwin = false;
bool exit2 = true;

string name; // the name that storage into Flappy.name
/*==================================================================================================================================*/

// Declaration must be Global

Texture pipeTexturebottom, pipeTexturetop, top2, bottom2;
Text ready[4], scoretext;
Font font;

vector<PiPe> pipes;
vector<PiPe> pipespr;
vector<PiPe> pipespl;

SoundBuffer click;
Sound Click(click);

// All Functions

void pname(RenderWindow &window, string &name); // taking the name from user
void pname2(RenderWindow &window, string &name);
void opponent(RenderWindow &window,
              string &name); // taking the name of opponent (two player mode)
void modes(RenderWindow &window); // Function that have i needded to
                                  // show,settexts,move up ,move down
void endlessmode(
    RenderWindow &window); // Function includes The one and two players needs
void selectedLevels(RenderWindow &window); // Function that show the 3 levels
void freepalstine(RenderWindow &window);
void Attributesofcounting_score();
void showingoptions(RenderWindow &window); // when player press Escape  in easy
                                           // level,he found( 3 options)
void showingoptionsl2(
    RenderWindow &window); // when player press Escape in medium level he found
                           // (3 options)
void showingoptionsl3(RenderWindow &window);
void Gameoverl3(RenderWindow &window);
void winningl3(RenderWindow &window);
void leaderboard(
    RenderWindow &window); // saving the data that user input it in file and
                           // showing it in achievement option
void Gameoverl1(RenderWindow &window); // here we showing 3options when player
                                       // died and reset all The bird function
                                       // to its usual condition (level 1)
void winningl1(RenderWindow &window);  // here we showing 3 options when player
                                       // is winning and reset all bird "" "" ""
void Gameoverl2(RenderWindow &window); // same Gameover1 but (level2)
void winningl2(RenderWindow &window);  // same winning1 but (level2)
void Gameoveronep(RenderWindow &window); // same Gameover1 but (one player mode)
void Gameovertwop(RenderWindow &window);
void countingp1(RenderWindow &window); // Function that showing the counting of
                                       // 3,2,1,0 to first player
void countingp2(RenderWindow &window); // same but second player
void updatePipes(vector<PiPe> &pipes,
                 float &pipeOffset); // Function that generates ,moves,drawing
                                     // and delets pipes of endless mode
void updatePipespl(vector<PiPe> &pipespl,
                   float &pipeOffset); // Function that generates ,moves,drawing
                                       // and delets pipes of endless mode
void updatePipespr(vector<PiPe> &pipespr,
                   float &pipeOffset2); // i used it to rewriting same function
                                        // to two players mode
void controlingOn_game(); // Function that i used it to change speed of pipes
                          // ,difficulty ,etc
void controlingOn_twoplayersgame();
void Myteam(RenderWindow &window);
void Instructions(RenderWindow &window);
int main() {
  // setup window

  RenderWindow window(VideoMode(viewwidth, viewheight), "Flappy Bird",
                      Style::Default, ContextSettings(0, 0, 8));
  window.setFramerateLimit(60);

  // All objects of Classes

  Menu menu(900, 1000);
  levels stages(900, 1000);

  // Functions of Structs  must be called

  Flappy.Atrributes();
  levelonepipes.attributes();
  levelonepipes.setPositionsl1();
  level2.setPositionl2();
  level2.attributes();
  level3.attributes();
  level3.setPositionl3();
  bomm1.Fireworks();
  bomm1.attributes();
  Flag.Attributes_flag1();
  Flag.Attributes_flag2();
  Flag.Attributes_flag3();
  monster.Spaceship1();
  monster.Spaceship_2p();
  level3.attributes();
  level3.setPositionl3();
  spaceship10.Spaceship_body();
  spaceship10.spaceship_position();
  spaceship10.Spaceship_body_2p1();
  spaceship10.Spaceship_body_2p2();
  spaceship10.spaceship_position_2p1();
  spaceship10.spaceship_position_2p2();

  // Declaration of All Sprites,Textures, Sounds ,etc

  SoundBuffer wing, death, points, countdown, menusound, clap, s1, s2;
  Sound Wing, Death, Points, Count, menus, Clap, S1, S2;
  Texture BackgroundMenu, map, gr, map2, gr2, tp1, gp1, sp, za, kora1, spacegr,
      spacegr2, lvl3, grl3, nos;
  Sprite Map[2], Map2[2], Gr[2], Gr2[2], Background, mapp1[2], groundp1[2],
      spark, zarzeer, Kora[2], spaceground[2], spaceground2[2], Grl3[2],
      maplvl3[2];
  // Font

  font.loadFromFile("Assets/"
                    "Jersey20Charted-Regular.ttf");

  // Background of menu

  BackgroundMenu.loadFromFile("Assets/"
                              "copy 2.jpg");
  Background.setTexture(BackgroundMenu);

  // map of easy level

  map.loadFromFile("Assets/"
                   "wp6956942.png");
  for (int i = 0; i < 2; i++) {
    Map[i].setTexture(map);
    Map[i].setPosition(Vector2f(i * 1920, 0));
  }
  gr.loadFromFile("Assets/"
                  "ground2.png");
  for (int i = 0; i < 2; i++) {
    Gr[i].setTexture(gr);
    Gr[i].setPosition(Vector2f(i * 1920, 850));
  }

  // map of medium level

  map2.loadFromFile("Assets/"
                    "maplvl2.jpg");
  for (int i = 0; i < 2; i++) {
    Map2[i].setTexture(map2);
    Map2[i].setPosition(Vector2f(i * 1920, 0));
  }
  gr2.loadFromFile("Assets/"
                   "ground2_lvl2.jpg");
  for (int i = 0; i < 2; i++) {
    Gr2[i].setTexture(gr2);
    Gr2[i].setPosition(Vector2f(i * 1920, 850));
  }

  // map and ground of hard level

  lvl3.loadFromFile("Assets/"
                    "maplvl3.jpg");

  grl3.loadFromFile("Assets/"
                    "ground2_copy.png");
  for (int i = 0; i < 2; i++) {
    maplvl3[i].setTexture(lvl3);
    maplvl3[i].setPosition(i * 1920, 0);
  }
  for (int i = 0; i < 2; i++) {
    Grl3[i].setTexture(grl3);
    Grl3[i].setPosition(i * 1920, 840);
  }

  // setup endless mode

  // Player one Map setup

  tp1.loadFromFile("Assets/"
                   "koraardia.jpg");
  gp1.loadFromFile("Assets/"
                   "smallground.png");
  for (int i = 0; i < 2; i++) {
    mapp1[i].setTexture(tp1);

    mapp1[i].setPosition(i * 1920, 0);
  }

  for (int i = 0; i < 2; i++) {
    groundp1[i].setTexture(gp1);
  }
  groundp1[0].setPosition(Vector2f(-30, 850));
  groundp1[0].setScale(0.5, 1);

  // our signature

  za.loadFromFile("Assets/"
                  "bg.jpg");
  zarzeer.setTexture(za);

  // Spark

  sp.loadFromFile("Assets/"
                  "spark.png");
  spark.setTexture(sp);

  // Space Background

  kora1.loadFromFile("Assets/"
                     "spacexx.jpg");
  for (int i = 0; i < 2; i++) {
    Kora[i].setTexture(kora1);
    Kora[i].setPosition(Vector2f(i * 1920, 0));
  }

  // Rectangle that seprates the window
  // RectangleShape fasel(Vector2f(10,1080));
  // fasel.setFillColor(Color(65,131,214));
  Sprite fasel;
  nos.loadFromFile("Assets/"
                   "bar.png");
  fasel.setTexture(nos);
  fasel.setPosition(0, 0);

  // Textures Funtion "updatePipes" needs them

  pipeTexturebottom.loadFromFile("Assets/"
                                 "bottomcol.jpg");
  pipeTexturetop.loadFromFile("Assets/"
                              "topcol.jpg");
  top2.loadFromFile("Assets/"
                    "spacetop.jpg");
  bottom2.loadFromFile("Assets/"
                       "spacebottom.jpg");

  // icon
  Image icon;
  icon.loadFromFile("Assets/"
                    "ICON.png");
  window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

  // All sounds

  wing.loadFromFile("Assets/"
                    "sfx_wing.wav");
  Wing.setBuffer(wing);
  Wing.setVolume(20);
  death.loadFromFile("Assets/"
                     "sfx_die.wav");
  Death.setBuffer(death);
  points.loadFromFile("Assets/"
                      "sfx_point.wav");
  Points.setBuffer(points);
  countdown.loadFromFile("Assets/"
                         "countdown.mp3");
  Count.setBuffer(countdown);
  menusound.loadFromFile("Assets/"
                         "soundmenu.mp3");
  menus.setBuffer(menusound);
  menus.setVolume(120);
  menus.setLoop(true);
  Points.setVolume(50);
  clap.loadFromFile("Assets/"
                    "clapping.mp3");
  Clap.setBuffer(clap);
  s1.loadFromFile("Assets/"
                  "tmheed.wav");
  s2.loadFromFile("Assets/"
                  "enfgar.wav");
  S1.setBuffer(s1);
  S2.setBuffer(s2);
  SoundBuffer sps;
  sps.loadFromFile("Assets/"
                   "spaceshipsound.mp3");
  Sound spacesound(sps);
  SoundBuffer ph;
  ph.loadFromFile("Assets/"
                  "hehe.mp3");
  Sound phenix(ph);
  SoundBuffer ship1;
  ship1.loadFromFile("Assets/"
                     "newsoundofspace.wav");
  Sound Ship1(ship1);
  Ship1.setVolume(10);
  SoundBuffer bre;
  bre.loadFromFile("Assets/"
                   "fighting.mp3");
  Sound Br(bre);
  click.loadFromFile("Assets/"
                     "ButtonClick.wav");
  SoundBuffer tell;

  // Clock

  Clock clock;

  // playing music on menu

  menus.play();

  // count determine The collision and it has a big role in showing the gameover

  int count = 0;

  while (true) {
    if (pagenum == 1000) {
      while (true) {
        window.clear();
        window.draw(zarzeer);
        window.display();
        if (clock.getElapsedTime().asSeconds() > 3) {
          pagenum = 0;
          break;
        }
      }
    }
    if (pagenum == 0) {
      menus.Playing;
      while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
          if (event.type == Event::Closed) {
            window.close();
            break;
          }
          if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::Up) {
              menu.moveup();
            }
            if (event.key.code == Keyboard::Down) {
              menu.moveDown();
            }
          }
          if (event.type == Event::KeyReleased) {

            if (event.key.code == Keyboard::Enter) {
              if (menu.pressed() == 0) {
                Click.play();
                pagenum = 1; // play
              }
              if (menu.pressed() == 1) {
                Click.play();
                pagenum = 12; // achei
              }
              if (menu.pressed() == 2) {
                Click.play();
                pagenum = 13; // about
              }
              if (menu.pressed() == 3) {
                Click.play();
                pagenum = 14; // instruction
              }
              if (menu.pressed() == 4) {
                Click.play();
                pagenum = -1; // exit
              }
            }
          }
        }
        window.clear();

        if (pagenum != 0)
          break;
        window.draw(Background);
        menu.draw(window);
        freepalstine(window);

        window.display();
      }
    }
    if (pagenum == -1) {
      window.close();
      break; // without it window will not close
    }
    if (pagenum == 1) {
      modes(window); // select between space mode ,levels
    }
    if (pagenum == 2) {
      selectedLevels(window); // easy,medium,hard
    }
    if (pagenum == 3) {
      Attributesofcounting_score(); //
      bool exit1 = true;
      Clock c;
      while (exit1) // showing 3,2,1 and the bird appears behind it
      {
        menus.stop();
        Count.play();
        while (true) {
          Flappy.animation();
          window.clear();
          for (int i = 0; i < 2; i++) /////
            window.draw(Map[i]);      /////
          levelonepipes.draw(window);
          for (int i = 0; i < 2; i++)
            window.draw(Gr[i]);
          window.draw(Flappy.bird);
          window.draw(ready[0]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 1)
            break;
        }
        while (true) {
          Flappy.animation();
          window.clear();
          for (int i = 0; i < 2; i++)
            window.draw(Map[i]);
          levelonepipes.draw(window);
          for (int i = 0; i < 2; i++)
            window.draw(Gr[i]);
          window.draw(Flappy.bird);
          window.draw(ready[1]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 2)
            break;
        }
        while (true) {
          Flappy.animation();
          window.clear();
          for (int i = 0; i < 2; i++)
            window.draw(Map[i]);
          levelonepipes.draw(window);
          for (int i = 0; i < 2; i++)
            window.draw(Gr[i]);
          window.draw(Flappy.bird);
          window.draw(ready[2]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 3)
            break;
        }
        while (true) {
          Flappy.animation();
          window.clear();
          for (int i = 0; i < 2; i++)
            window.draw(Map[i]);
          levelonepipes.draw(window);
          for (int i = 0; i < 2; i++)
            window.draw(Gr[i]);
          window.draw(Flappy.bird);
          window.draw(ready[3]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 4)
            break;
        }
        exit1 = false;
      }
      while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
          if (event.type == Event::Closed) {
            window.close();
          }
          if (event.type == sf::Event::KeyPressed &&
              event.key.code == sf::Keyboard::Space &&
              Flappy.bird.getPosition().y >= 40) {
            Wing.play();
            Flappy.birdVelocity = -5; // Jump
          }
        }
        // animation of The game

        Flappy.animation();

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
          showingoptions(window); // continue,restart and menu
          break;
        }

        // Update bird Position on Y

        Flappy.birdVelocity += Flappy.gravity;
        Flappy.bird.move(0, Flappy.birdVelocity);
        // collision

        for (int i = 0; i < 25; i++) {
          if (Flappy.bird.getGlobalBounds().intersects(
                  levelonepipes.PipeOfbottom[i].getGlobalBounds()) ||
              Flappy.bird.getGlobalBounds().intersects(
                  levelonepipes.PipeOftop[i].getGlobalBounds()) ||
              Flappy.bird.getPosition().y >= 840)
            count++;
        }
        if (j < 25) // tricky and solve infinte score after bird exceed the last
                    // pipe
        {
          if (Flappy.bird.getPosition().x >
              levelonepipes.PipeOfbottom[j].getPosition().x + 20) {
            Points.play();
            Flappy.score++;
            j++;
          }
        }
        // Important scope(it shows the game over )

        if (count >= 1) {
          Clock c2;
          while (r) {
            while (window.isOpen()) {
              BirdIndex++;
              Flappy.bird.setScale(0.4 + BirdIndex / 150,
                                   0.4 + BirdIndex / 150);
              Flappy.bird.rotate(20);
              Map[0].setPosition(
                  0, 0); // to prevent shifting the Picture of window
              if (c2.getElapsedTime().asSeconds() >
                  2) // if he enters this condition it means that he finishs
                     // that rotating
              {
                bomm1.Fireworks_animation();
                window.clear();
                window.draw(Map[0]);
                bomm1.draw_Fireworks(window);
                window.display();
                S2.play();
                r = false;
                break;
              }

              window.clear();
              for (int i = 0; i < 2; i++)
                window.draw(Map[i]);

              levelonepipes.draw(window);

              for (int i = 0; i < 2; i++)
                window.draw(Gr[i]);

              window.draw(Flappy.bird);
              window.display();
            }
          }
          // reseting All things to use it every time the game is played

          r = true;                       // To enter while true again
          Flappy.bird.setScale(0.4, 0.3); // Default bird position
          c2.restart();
          count = 0;                  // To make collision show again
          Gameoverl1(window);         // let user choose his option
          Flappy.bird.setRotation(0); // stop rotate
          Map[0].setPosition(0, 0);   // to prevent shifting picture of window
          Map[1].setPosition(1920, 0);
          Gr[0].setPosition(0, 850);
          Gr[1].setPosition(1920, 850);
          Flappy.bird.setPosition(300, 400); // At All reseting pos of bird
          levelonepipes.setPositionsl1();    // reseting pipes position
          Flappy.birdVelocity =
              0; // important... to prevent the fasting falling in next game
          Flappy.score = 0;
          j = 0; // To enter the condition of if(j<25) again
          Flag.flag1.setPosition(9200, 10);
          BirdIndex =
              0; // reset the factor of the big scale in the rotation show
          break; // break to moving to the page that user enter
        }

        // winning

        if (Flappy.bird.getGlobalBounds().intersects(
                Flag.flag1.getGlobalBounds())) // he is winning
        {
          winningl1(window);
          Map[0].setPosition(0, 0); // prevent shifting
          Map[1].setPosition(1920, 0);
          Gr[0].setPosition(0, 850);
          Gr[1].setPosition(1920, 850);
          Flappy.bird.setPosition(300, 400);
          levelonepipes.setPositionsl1();
          Flappy.birdVelocity = 0;
          Flappy.score = 0;
          j = 0;
          Flag.flag1.setPosition(9200, 10);
          break;
        }

        for (int i = 0; i < 2; i++) // moving the Map picture after picture and
                                    // they repeat themselves .
        {
          Map[i].move(-2, 0);
          if (Map[i].getPosition().x <= -1920)

            Map[i].setPosition(Vector2f(1920, 0));
        }
        for (int i = 0; i < 2; i++) {
          Gr[i].move(-2, 0);
          if (Gr[i].getPosition().x <= -1920)

            Gr[i].setPosition(Vector2f(1920, 850));
        }

        // moving The Pipes

        levelonepipes.move(4, 0);
        Flag.flag1.move(-4, 0);

        // showing the score

        string scorestring =
            to_string(Flappy.score); // to trans from int to string `
        scoretext.setString("score " + scorestring);

        window.clear();
        for (int i = 0; i < 2; i++)
          window.draw(Map[i]);

        levelonepipes.draw(window);
        window.draw(Flappy.bird);
        window.draw(Flag.flag1);

        for (int i = 0; i < 2; i++)
          window.draw(Gr[i]);

        window.draw(scoretext);
        window.display();
      }
    }
    if (pagenum == 4) {
      Attributesofcounting_score();
      bool exit1 = true;
      Clock c;
      // showing 3,2,1,0 counting

      while (exit1) {
        menus.stop();
        Count.play();
        while (true) {
          Flappy.animation3();
          window.clear();
          for (int i = 0; i < 2; i++)
            window.draw(Map2[i]);
          level2.drawl2(window);
          for (int i = 0; i < 2; i++)
            window.draw(Gr2[i]);
          window.draw(Flappy.bird3);
          window.draw(ready[0]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 1)
            break;
        }
        while (true) {
          Flappy.animation3();
          window.clear();
          for (int i = 0; i < 2; i++)
            window.draw(Map2[i]);
          level2.drawl2(window);
          for (int i = 0; i < 2; i++)
            window.draw(Gr2[i]);
          window.draw(Flappy.bird3);
          window.draw(ready[1]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 2)
            break;
        }
        while (true) {
          Flappy.animation3();
          window.clear();
          for (int i = 0; i < 2; i++)
            window.draw(Map2[i]);
          level2.drawl2(window);
          for (int i = 0; i < 2; i++)
            window.draw(Gr2[i]);
          window.draw(Flappy.bird3);
          window.draw(ready[2]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 3)
            break;
        }
        while (true) {
          Flappy.animation3();
          window.clear();
          for (int i = 0; i < 2; i++)
            window.draw(Map2[i]);
          level2.drawl2(window);
          for (int i = 0; i < 2; i++)
            window.draw(Gr2[i]);
          window.draw(Flappy.bird3);
          window.draw(ready[3]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 4)
            break;
        }
        exit1 = false;
      }
      while (window.isOpen()) {
        // convert int score to string score

        string scorestring = to_string(Flappy.score);
        scoretext.setString("score " + scorestring);

        Event event;
        while (window.pollEvent(event)) {
          if (event.type == Event::Closed) {
            window.close();
          }

          if (event.type == sf::Event::KeyPressed &&
              event.key.code == sf::Keyboard::Space &&
              Flappy.bird.getPosition().y >= 40) {
            Wing.play();
            Flappy.birdVelocity = -6.2f; // Jump
          }
        }
        // Animation of Blue Bird

        Flappy.animation3();

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
          showingoptionsl2(window);
          break;
        }

        // Update bird position

        Flappy.birdVelocity += Flappy.gravity;
        Flappy.bird3.move(0, Flappy.birdVelocity);

        // collision

        for (int i = 0; i < 40; i++) {
          if (Flappy.bird3.getGlobalBounds().intersects(
                  level2.Pipetopl2[i].getGlobalBounds()) ||
              Flappy.bird3.getGlobalBounds().intersects(
                  level2.Pipebottoml2[i].getGlobalBounds()) ||
              Flappy.bird3.getPosition().y >= 840)
            count++;
        }

        if (n < 40) // tricky condition to stop increment score after it moves
                    // last pipe
        {
          if (Flappy.bird3.getPosition().x >
              level2.Pipebottoml2[n].getPosition().x + 20) {
            Points.play();
            Flappy.score++;
            n++;
          }
        }

        // Game Over Show

        if (count >= 1) {
          Clock c2;
          while (r) {
            while (window.isOpen()) {
              BirdIndex++;
              Flappy.bird3.setScale(0.4 + BirdIndex / 150,
                                    0.4 + BirdIndex / 150);
              Flappy.bird3.rotate(20);
              Map2[0].setPosition(0, 0);
              if (c2.getElapsedTime().asSeconds() > 2) {
                bomm1.Fireworks_animation();
                window.clear();
                window.draw(Map2[0]);
                bomm1.draw_Fireworks(window);
                window.display();
                S2.play();
                r = false;
                break;
              }

              window.clear();
              for (int i = 0; i < 2; i++)
                window.draw(Map2[i]);

              level2.drawl2(window);

              for (int i = 0; i < 2; i++)
                window.draw(Gr2[i]);

              window.draw(Flappy.bird3);
              window.display();
            }
            c2.restart();
          }

          // Reseting all things to can play it again without any problem

          r = true;
          Flappy.bird3.setScale(0.4, 0.3);
          count = 0;
          Gameoverl2(window);
          Map2[0].setPosition(0, 0);
          Map2[1].setPosition(1920, 0);
          Gr2[0].setPosition(0, 850);
          Gr2[1].setPosition(1920, 850);
          Flag.flag2.setPosition(15400, 10);
          level2.setPositionl2();
          Flappy.birdVelocity = 0;
          Flappy.bird3.setPosition(300, 400);
          Flappy.score = 0;
          n = 0;
          Flappy.bird3.setRotation(0);
          BirdIndex = 0;
          break;
        }

        // Winning

        if (Flappy.bird.getGlobalBounds().intersects(
                Flag.flag2.getGlobalBounds())) {
          winningl2(window);
          Map2[0].setPosition(0, 0);
          Map2[1].setPosition(1920, 0);
          Gr2[0].setPosition(0, 850);
          Gr2[1].setPosition(1920, 850);
          Flappy.bird.setPosition(300, 400);
          level2.setPositionl2();
          Flappy.birdVelocity = 0;
          Flappy.score = 0;
          n = 0;
          Flag.flag2.setPosition(15400, 10);
          break;
        }
        for (int i = 0; i < 2; i++) {
          Map2[i].move(-2, 0);
          if (Map2[i].getPosition().x <= -1920) {
            Map2[i].setPosition(Vector2f(1920, 0));
          }
        }
        for (int i = 0; i < 2; i++) {
          Gr2[i].move(-2, 0);
          if (Gr2[i].getPosition().x <= -1920) {
            Gr2[i].setPosition(Vector2f(1920, 850));
          }
        }

        // Moves Pipes

        level2.movelevel2(5.3, 0);
        Flag.flag2.move(-5.3, 0);

        window.clear();
        for (int i = 0; i < 2; i++)
          window.draw(Map2[i]);

        level2.drawl2(window);

        window.draw(Flappy.bird3);
        window.draw(Flag.flag2);
        for (int i = 0; i < 2; i++)
          window.draw(Gr2[i]);
        window.draw(scoretext);
        window.display();
      }
    }
    if (pagenum == 5) {
      Attributesofcounting_score();
      bool exit1 = true;
      Clock c;
      // showing 3,2,1,0 counting

      while (exit1) {
        menus.stop();
        Count.play();
        while (true) {
          Flappy.animation2();
          window.clear();
          for (int i = 0; i < 2; i++)
            window.draw(maplvl3[i]);
          level3.drawl3(window);
          for (int i = 0; i < 2; i++)
            window.draw(Grl3[i]);
          window.draw(Flappy.bird2);
          window.draw(ready[0]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 1)
            break;
        }
        while (true) {
          Flappy.animation2();
          window.clear();
          for (int i = 0; i < 2; i++)
            window.draw(maplvl3[i]);
          level3.drawl3(window);
          for (int i = 0; i < 2; i++)
            window.draw(Grl3[i]);
          window.draw(Flappy.bird2);
          window.draw(ready[1]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 2)
            break;
        }
        while (true) {
          Flappy.animation2();
          window.clear();
          for (int i = 0; i < 2; i++)
            window.draw(maplvl3[i]);
          level3.drawl3(window);
          for (int i = 0; i < 2; i++)
            window.draw(Grl3[i]);
          window.draw(Flappy.bird2);
          window.draw(ready[2]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 3)
            break;
        }
        while (true) {
          Flappy.animation2();
          window.clear();
          for (int i = 0; i < 2; i++)
            window.draw(maplvl3[i]);
          level3.drawl3(window);
          for (int i = 0; i < 2; i++)
            window.draw(Grl3[i]);
          window.draw(Flappy.bird2);
          window.draw(ready[3]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 4)
            break;
        }
        exit1 = false;
      }
      while (window.isOpen()) {
        // convert int score to string score

        string scorestring = to_string(Flappy.score);
        scoretext.setString("score " + scorestring);

        Event event;
        while (window.pollEvent(event)) {
          if (event.type == Event::Closed) {
            window.close();
          }

          if (event.type == sf::Event::KeyPressed &&
              event.key.code == sf::Keyboard::Space &&
              Flappy.bird.getPosition().y >= 40) {
            Wing.play();
            Flappy.birdVelocity = -6; // Jump
          }
        }
        // Animation of Blue Bird

        Flappy.animation2();

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
          showingoptionsl3(window);
          break;
        }

        // Update bird position

        Flappy.birdVelocity += Flappy.gravity;
        Flappy.bird2.move(0, Flappy.birdVelocity);

        ////collision

        for (int i = 0; i < 60; i++) {
          if (Flappy.bird2.getGlobalBounds().intersects(
                  level3.Pipetopl3[i].getGlobalBounds()) ||
              Flappy.bird2.getGlobalBounds().intersects(
                  level3.Pipebottoml3[i].getGlobalBounds()) ||
              Flappy.bird2.getPosition().y >= 840)
            count++;
        }

        if (f < 60) {
          if (Flappy.bird2.getPosition().x >
              level3.Pipebottoml3[f].getPosition().x + 20) {
            Points.play();
            Flappy.score++;
            f++;
          }
        }

        // Game Over Show

        if (count >= 1) {
          Clock c2;
          while (r) {
            while (window.isOpen()) {
              BirdIndex++;
              Flappy.bird2.setScale(0.4 + BirdIndex / 150,
                                    0.4 + BirdIndex / 150);
              Flappy.bird2.rotate(20);
              maplvl3[0].setPosition(0, 0);
              if (c2.getElapsedTime().asSeconds() > 2) {
                bomm1.Fireworks_animation();
                window.clear();
                window.draw(maplvl3[0]);
                bomm1.draw_Fireworks(window);
                window.display();
                S2.play();
                r = false;
                break;
              }

              window.clear();
              for (int i = 0; i < 2; i++)
                window.draw(maplvl3[i]);

              level2.drawl2(window);

              for (int i = 0; i < 2; i++)
                window.draw(Grl3[i]);

              window.draw(Flappy.bird2);
              window.display();
            }
            c2.restart();
          }

          // Reseting all things to can play it again without any problem

          r = true;
          Flappy.bird2.setScale(0.4, 0.3);
          count = 0;
          Gameoverl3(window);
          maplvl3[0].setPosition(0, 0);
          maplvl3[1].setPosition(1920, 0);
          Grl3[0].setPosition(0, 850);
          Grl3[1].setPosition(1920, 850);
          Flag.flag3.setPosition(26700, 10);
          level3.setPositionl3();
          Flappy.birdVelocity = 0;
          Flappy.bird2.setPosition(300, 400);
          Flappy.score = 0;
          n = 0;
          Flappy.bird2.setRotation(0);
          BirdIndex = 0;
          break;
        }

        // Winning

        if (Flappy.bird2.getGlobalBounds().intersects(
                Flag.flag3.getGlobalBounds())) {
          winningl3(window);
          maplvl3[0].setPosition(0, 0);
          maplvl3[1].setPosition(1920, 0);
          Grl3[0].setPosition(0, 850);
          Grl3[1].setPosition(1920, 850);
          Flappy.bird2.setPosition(300, 400);
          level3.setPositionl3();
          Flappy.birdVelocity = 0;
          Flappy.score = 0;
          f = 0;
          Flag.flag3.setPosition(26700, 10);
          break;
        }

        for (int i = 0; i < 2; i++) {
          maplvl3[i].move(-2, 0);
          if (maplvl3[i].getPosition().x <= -1920) {
            maplvl3[i].setPosition(Vector2f(1920, 0));
          }
        }
        for (int i = 0; i < 2; i++) {
          Grl3[i].move(-2, 0);
          if (Grl3[i].getPosition().x <= -1920) {
            Grl3[i].setPosition(Vector2f(1920, 850));
          }
        }

        // Moves Pipes
        level3.movel3(5.5, 0);
        level3.pipemovel3();
        Flag.flag3.move(-5.5, 0);

        window.clear();
        for (int i = 0; i < 2; i++)
          window.draw(maplvl3[i]);

        level3.drawl3(window);
        window.draw(Flappy.bird2);
        window.draw(Flag.flag3);

        for (int i = 0; i < 2; i++)
          window.draw(Grl3[i]);

        window.draw(scoretext);
        window.display();
      }
    }
    if (pagenum == 6) {
      menus.stop();
      endlessmode(window); // choosing one,two players
    }
    if (pagenum == 7) {
      pname(window, name); // name of player in one player mode
    }
    if (pagenum == 8) {
      Attributesofcounting_score();
      bool exit1 = true;
      Clock c;
      while (exit1) {
        Count.play();
        while (true) {
          Flappy.animation3();
          window.clear();
          window.draw(Kora[0]);
          window.draw(monster.Spaceship);
          window.draw(ready[0]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 1)
            break;
        }
        while (true) {
          Flappy.animation3();
          window.clear();
          window.draw(Kora[0]);
          window.draw(monster.Spaceship);
          window.draw(ready[1]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 2)
            break;
        }
        while (true) {
          Flappy.animation3();
          window.clear();
          window.draw(Kora[0]);
          window.draw(monster.Spaceship);
          window.draw(ready[2]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 3)
            break;
        }
        while (true) {
          Flappy.animation3();
          window.clear();
          window.draw(Kora[0]);
          window.draw(monster.Spaceship);
          window.draw(ready[3]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 4)
            break;
        }
        exit1 = false;
      }
      while (window.isOpen()) {
        if (Flappy.score > 0) // showing score after he moves first pipe
        {
          string scorestring = to_string(Flappy.score);
          scoretext.setString("score " + scorestring);
        }
        Event event;
        while (window.pollEvent(event)) {
          if (event.type == Event::Closed) {
            window.close();
          }

          if (event.type == sf::Event::KeyPressed &&
              event.key.code == sf::Keyboard::Up &&
              monster.Spaceship.getPosition().y >= 40) {
            Ship1.play();
            Flappy.birdVelocity = -6;
          }
        }
        // animation of The Game

        monster.spaceship_animation();

        // Gravity Effect

        Flappy.birdVelocity += Flappy.gravity;
        monster.Spaceship.move(0, Flappy.birdVelocity);
        spaceship10.spaceship_move(); // The combination of Rectangles that fit
                                      // the collision

        // Generating Pipes
        updatePipes(pipes, pipeOffset);

        // collision with rectangles not  Original spaceship
        for (auto &pipe : pipes) {
          for (int M = 0; M < 6; M++) {
            if (spaceship10.b[M].getGlobalBounds().intersects(
                    pipe.topPipe.getGlobalBounds()) ||
                spaceship10.b[M].getGlobalBounds().intersects(
                    pipe.bottomPipe.getGlobalBounds()) ||
                spaceship10.b[M].getPosition().y >= 840) {
              count3++;
            }
          }
        }

        for (auto &pipe : pipes) {
          if (!pipe.passed && pipe.topPipe.getPosition().x <
                                  monster.Spaceship.getPosition().x) {
            pipe.passed = true; // Mark this pipe as passed
            Flappy.score++;
          }
        }

        // The Gameplay of Game
        controlingOn_game();

        // GameOver Show
        if (count3 >= 1) {
          Clock c2;
          while (r) {
            while (window.isOpen()) {
              BirdIndex++;
              monster.Spaceship.setScale(0.4 + BirdIndex / 150,
                                         0.4 + BirdIndex / 150);
              monster.Spaceship.rotate(10);
              Kora[0].setPosition(0, 0);
              if (c2.getElapsedTime().asSeconds() > 1.2) {
                bomm1.Fireworks_animation();
                window.clear();
                window.draw(Kora[0]);
                bomm1.draw_Fireworks(window);
                window.display();
                S2.play();
                r = false;
                break;
              }

              Kora[0].setPosition(0, 0);
              window.clear();
              window.draw(Kora[0]);
              window.draw(monster.Spaceship);
              window.display();
            }
          }
          r = true;
          monster.Spaceship.setScale(1, 1);
          Kora[0].setPosition(0, 0);
          Kora[1].setPosition(1920, 0);
          c2.restart();
          count3 = 0;

          // Saving Data
          ofstream offile;
          offile.open("history.txt", ios::app);
          offile << Flappy.name << "              " << Flappy.score
                 << "                " << " EndLess " << " * " << endl;

          // gameover options
          Gameoveronep(window);

          // resting every thing must to using it in next game

          for (auto &pipe : pipes) // Delete Pipes
          {
            pipes.pop_back();
          }
          difficulty = 150;                 // reset default difficulty
          PIPE_SPEED = 5;                   // reset default speed
          spaceship10.spaceship_position(); // reset Rectangles position
          monster.Spaceship.setPosition(300, 400);
          Flappy.birdVelocity = 0;
          Flappy.score = 0;
          speed_y = 0;
          monster.Spaceship.setRotation(0);
          BirdIndex = 0;
          break;
        }

        for (int i = 0; i < 2; i++) {
          Kora[i].move(-2, 0);
          if (Kora[i].getPosition().x <= -1920) {
            Kora[i].setPosition(Vector2f(1920, 0));
          }
        }
        // asking

        /*	for (int i = 0; i < 2; i++)
                {
                        spaceground2[i].move(-2, 0);
                        if (spaceground2[i].getPosition().x <= -1400)
                        {
                                spaceground2[i].setPosition(Vector2f(1400,
           850));
                        }
                }*/
        // window Display per frame

        window.clear();

        for (int i = 0; i < 2; i++)
          window.draw(Kora[i]);

        for (auto &pipe : pipes) {
          window.draw(pipe.topPipe);
          window.draw(pipe.bottomPipe);
        }
        /*for (int i = 0; i < 2; i++)
        {
                window.draw(spaceground2[i]);
        }*/

        window.draw(monster.Spaceship);
        window.draw(scoretext);
        window.display();
      }
    }
    if (pagenum == 9) {
      pname2(window, name); // name of left side player
    }
    if (pagenum == 10) {
      opponent(window, name); // Name of right side player
    }
    if (pagenum == 11) {
      window.setPosition(Vector2i(0, 0));
      window.setSize(Vector2u(1920, 1080));
      monster.spaceship[0].setPosition(150, 400);
      monster.spaceship[1].setPosition(600, 400);
      spaceship10.spaceship_position_2p1();
      spaceship10.spaceship_position_2p2();
      mapp1[0].setPosition(0, 0);

      bool exit1 = true;
      Clock c;

      Text ready[4], ready2[4];
      ready[0].setString("3");
      ready[1].setString("2");
      ready[2].setString("1");
      ready[3].setString("0");
      ready2[0].setString("3");
      ready2[1].setString("2");
      ready2[2].setString("1");
      ready2[3].setString("0");

      for (int i = 0; i < 4; i++) {
        ready[i].setFont(font);
        ready[i].setCharacterSize(200);
        ready[i].setFillColor(Color(0, 95, 106));
        ready[i].setPosition(Vector2f(220, 350));

        ready2[i].setFont(font);
        ready2[i].setCharacterSize(200);
        ready2[i].setFillColor(Color(0, 95, 106));
        ready2[i].setPosition(Vector2f(700, 350));
      }

      while (exit1) {
        Br.play();
        while (true) {
          window.clear();
          window.draw(mapp1[0]);
          for (int i = 0; i < 2; i++)
            window.draw(monster.spaceship[i]);
          window.draw(ready[0]);
          window.draw(ready2[0]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 1)
            break;
        }
        while (true) {

          window.clear();
          window.draw(mapp1[0]);
          for (int i = 0; i < 2; i++)
            window.draw(monster.spaceship[i]);
          window.draw(ready[1]);
          window.draw(ready2[1]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 2)
            break;
        }
        while (true) {

          window.clear();
          window.draw(mapp1[0]);
          for (int i = 0; i < 2; i++)
            window.draw(monster.spaceship[i]);
          window.draw(ready[2]);
          window.draw(ready2[2]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 3)
            break;
        }
        while (true) {

          window.clear();
          window.draw(mapp1[0]);
          for (int i = 0; i < 2; i++)
            window.draw(monster.spaceship[i]);
          window.draw(ready[3]);
          window.draw(ready2[3]);
          window.display();
          if (c.getElapsedTime().asSeconds() > 4)
            break;
        }
        exit1 = false;
      }
      while (window.isOpen()) {
        Event Ev;
        while (window.pollEvent(Ev)) {
          if (Ev.type == Event::Closed)
            window.close();
          if (Ev.type == sf::Event::KeyPressed &&
              Ev.key.code == sf::Keyboard::Space &&
              monster.spaceship[0].getPosition().y >= 40) {
            Ship1.play();
            Flappy.birdVelocity = -5.5; // Jump
          }
          if (Ev.type == sf::Event::KeyPressed &&
              Ev.key.code == sf::Keyboard::Up &&
              monster.spaceship[1].getPosition().y >= 40) {
            Ship1.play();
            Flappy.birdVelocity2 = -5.5; // Jump
          }
        }

        // animaiton of the game

        monster.spaceship_animation_2p(); // left player [0]
        monster.animationforrightp();     // right player  [1]

        Flappy.birdVelocity += Flappy.gravity;
        Flappy.birdVelocity2 += Flappy.gravity2;

        monster.spaceship[0].move(0, Flappy.birdVelocity);
        monster.spaceship[1].move(0, Flappy.birdVelocity2);
        spaceship10.spaceship_move_2p();

        // Generating Pipes for each player   (different sequences of pipes)
        updatePipespl(pipespl, pipeOffset);
        updatePipespr(pipespr, pipeOffset2);

        for (auto &pipe :
             pipespr) // collision with combination of rects   (right player)
        {
          for (int M = 0; M < 5; M++) {
            if (spaceship10.b2[M].getGlobalBounds().intersects(
                    pipe.topPipe.getGlobalBounds()) ||
                spaceship10.b2[M].getGlobalBounds().intersects(
                    pipe.bottomPipe.getGlobalBounds()) ||
                spaceship10.b2[M].getPosition().y >= 1000) {
              count++;
              leftplayerwin = true;
            }
          }
        }
        for (auto &pipe : pipespr) {
          if (!pipe.passed && pipe.topPipe.getPosition().x <
                                  monster.spaceship[1].getPosition().x) {
            pipe.passed = true;
            Flappy.score++;
          }
        }
        for (auto &pipe :
             pipespl) // collision with combination of rects (left player)
        {
          for (int M = 0; M < 5; M++) {
            if (spaceship10.b1[M].getGlobalBounds().intersects(
                    pipe.topp2.getGlobalBounds()) ||
                spaceship10.b1[M].getGlobalBounds().intersects(
                    pipe.bottomp2.getGlobalBounds()) ||
                spaceship10.b1[M].getPosition().y >= 1000) {
              count2++;
              rightplayerwin = true;
            }
          }
        }
        for (auto &pipe : pipespl) {
          if (!pipe.passed && pipe.topp2.getPosition().x <
                                  monster.spaceship[0].getPosition().x) {
            pipe.passed = true;
            Flappy.score++;
          }
        }
        // GamePlay   :::needs to tweak
        controlingOn_twoplayersgame();

        // Gameover Show

        if (count >= 1) // collision of right player
        {
          Clock c2;
          phenix.play(); // hehe sound
          while (r) {
            while (window.isOpen()) {
              BirdIndex++;
              monster.spaceship[1].setScale(0.4 + BirdIndex / 150,
                                            0.4 + BirdIndex / 150);
              monster.spaceship[1].rotate(10);
              if (c2.getElapsedTime().asSeconds() > 1.2) {
                bomm1.Fireworks_animation();
                window.clear();
                bomm1.draw_Fireworks(window);
                window.display();
                S2.play();
                r = false;
                break;
              }

              window.clear();
              for (int i = 0; i < 2; i++)
                window.draw(mapp1[i]);
              window.draw(monster.spaceship[1]);
              window.display();
            }
          }
          r = true;
          count = 0;
          monster.spaceship[1].setScale(0.5, 0.8);
          c2.restart();

          // gameover options
          Gameovertwop(window);

          mapp1[0].setPosition(0, 0); // Shifting problem
          difficulty2 = 150;
          twoplayersspeed = 3.5;
          spaceship10.spaceship_position_2p2();
          monster.spaceship[1].setPosition(600, 400);
          twoplayersspeed_y = 0;
          monster.spaceship[1].setRotation(0);
          BirdIndex = 0;
          Flappy.score = 0;
          break;
        }

        if (count2 >= 1) {
          Clock c2;
          phenix.play();
          while (r) {
            while (window.isOpen()) {
              BirdIndex++;
              monster.spaceship[0].setScale(0.4 + BirdIndex / 150,
                                            0.4 + BirdIndex / 150);
              monster.spaceship[0].rotate(10);
              if (c2.getElapsedTime().asSeconds() > 1.2) {
                bomm1.Fireworks_animation();
                window.clear();
                bomm1.draw_Fireworks(window);
                window.display();
                S2.play();
                r = false;
                break;
              }

              window.clear();
              for (int i = 0; i < 2; i++)
                window.draw(mapp1[i]);
              window.draw(monster.spaceship[0]);
              window.display();
            }
          }
          r = true;
          monster.spaceship[0].setScale(0.5, 0.8);
          c2.restart();
          count2 = 0;
          Gameovertwop(window);
          mapp1[0].setPosition(0, 0);
          twoplayersspeed = 3.5;
          difficulty2 = 150;
          monster.spaceship[0].setPosition(150, 400);
          spaceship10.spaceship_position_2p1();
          twoplayersspeed_y = 0;
          monster.spaceship[0].setRotation(0);
          BirdIndex = 0;
          Flappy.score = 0;
          break;
        }

        for (int i = 0; i < 2; i++) {
          mapp1[i].move(-2, 0);
          if (mapp1[i].getPosition().x <= -1920) {
            mapp1[i].setPosition(1920, 0);
          }
        }

        window.clear();

        for (int i = 0; i < 2; i++)
          window.draw(mapp1[i]);

        for (auto &pipe : pipespr) {
          window.draw(pipe.bottomPipe);
          window.draw(pipe.topPipe);
        }
        for (auto &pipe : pipespl) {
          window.draw(pipe.topp2);
          window.draw(pipe.bottomp2);
        }
        window.draw(monster.spaceship[1]);
        window.draw(monster.spaceship[0]);
        window.draw(fasel);

        window.display();
      }
    }

    if (pagenum == 12) {
      // Achievements will be here
      leaderboard(window);
    }
    if (pagenum == 14) {
      Instructions(window);
    }
    if (pagenum == 13) {
      Myteam(window);
    }
  }
  return 0;
}
void pname(RenderWindow &window, string &name) {
  Texture backg;
  backg.loadFromFile("Assets/"
                     "spacebackground.jpg");
  Sprite back;
  back.setPosition(-100, 0);
  back.setTexture(backg);
  if (!name.empty())
    name.clear();
  Text textone, texttwo;
  textone.setFont(font);
  texttwo.setFont(font);
  textone.setString("Enter your Name");
  textone.setPosition(10, 25);
  texttwo.setPosition(10, 150);
  textone.setCharacterSize(70);
  texttwo.setCharacterSize(70);
  textone.setFillColor(Color(204, 204, 204));
  texttwo.setFillColor(Color(0, 95, 106));

  while (window.isOpen()) {

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::TextEntered) {
        name += static_cast<char>(event.text.unicode);
      }

      if (Keyboard::isKeyPressed(Keyboard::BackSpace) && name.size() > 0) {
        name.pop_back();
      }
      if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Enter && name.size() > 4) {
          Click.play();
          Flappy.name = name;
          pagenum = 8;
          return;
        }
        if (event.key.code == Keyboard::Escape) {
          Click.play();
          pagenum = 6;
          return;
        }
      }
    }

    texttwo.setString(name);
    window.clear();
    window.draw(back);
    window.draw(textone);
    window.draw(texttwo);
    window.display();
  }
}
void pname2(RenderWindow &window, string &name) {
  Texture backg;
  backg.loadFromFile("Assets/"
                     "spacebackground.jpg");
  Sprite back;
  back.setTexture(backg);
  back.setPosition(-100, 0);
  if (!name.empty())
    name.clear();
  Text textone, texttwo;
  textone.setFont(font);
  texttwo.setFont(font);
  textone.setString("Enter Player One Name");
  textone.setPosition(10, 25);
  texttwo.setPosition(10, 150);
  textone.setCharacterSize(70);
  texttwo.setCharacterSize(70);
  textone.setFillColor(Color(204, 204, 204));
  texttwo.setFillColor(Color(0, 95, 106));

  while (window.isOpen()) {

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::TextEntered) {
        name += static_cast<char>(event.text.unicode);
      }

      if (Keyboard::isKeyPressed(Keyboard::BackSpace) && name.size() > 0) {
        name.pop_back();
      }
      if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Enter && name.size() > 4) {
          Click.play();
          Flappy.name = name;
          pagenum = 10;
          return;
        }
        if (event.key.code == Keyboard::Escape) {
          Click.play();
          pagenum = 6;
          return;
        }
      }
    }

    texttwo.setString(name);
    window.clear();
    window.draw(back);
    window.draw(textone);
    window.draw(texttwo);
    window.display();
  }
}
void opponent(RenderWindow &window, string &name) {
  Texture backg;
  backg.loadFromFile("Assets/"
                     "spacebackground.jpg");
  Sprite back;
  back.setPosition(-100, 0);
  back.setTexture(backg);
  if (!name.empty())
    name.clear();
  Text textone, texttwo;
  textone.setFont(font);
  texttwo.setFont(font);
  textone.setString("Enter Player Two Name");
  textone.setPosition(10, 25);
  texttwo.setPosition(10, 150);
  textone.setCharacterSize(70);
  texttwo.setCharacterSize(70);
  textone.setFillColor(Color(204, 204, 195));
  texttwo.setFillColor(Color(0, 95, 106));
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::TextEntered) {
        name += static_cast<char>(event.text.unicode);
      }

      if (Keyboard::isKeyPressed(Keyboard::BackSpace) && name.size() > 0) {
        name.pop_back();
      }
      if (Keyboard::isKeyPressed(Keyboard::Enter) && name.size() > 4) {
        Click.play();
        Flappy.opponentname = name;
        pagenum = 11;
        return;
      }
      if (event.type == Event::KeyReleased) {

        if (event.key.code == Keyboard::Escape) {
          Click.play();
          pagenum = 6;
          return;
        }
      }
    }

    texttwo.setString(name);
    window.clear();
    window.draw(back);
    window.draw(textone);
    window.draw(texttwo);
    window.display();
  }
}
void selectedLevels(RenderWindow &window) {
  levels stages(1440, 900);
  Texture BackgroundMenu;
  BackgroundMenu.loadFromFile("Assets/"
                              "copy 2.jpg");
  Sprite Background;
  Background.setTexture(BackgroundMenu);
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
        break;
      }
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up)

          stages.moveUp();

        if (event.key.code == Keyboard::Down)

          stages.moveDown();
      }
      if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Enter) {
          if (stages.getselected() == 0) {
            Click.play();
            pagenum = 3;
            return;
          }
          if (stages.getselected() == 1) {
            Click.play();
            pagenum = 4;
            return;
          }
          if (stages.getselected() == 2) {
            Click.play();
            pagenum = 5;
            return;
          }
        }
        if (event.key.code == Keyboard::Escape) {
          Click.play();
          pagenum = 1;
          return;
        }
      }
    }
    window.clear();
    window.draw(Background);
    stages.draw(window);
    window.display();
  }
}
void freepalstine(RenderWindow &window) {
  Font font2;
  font2.loadFromFile("Assets/"
                     "Roboto-BoldCondensed.ttf");
  Text t1, t2, t3;
  t1.setString("#free");
  t1.setCharacterSize(50);
  t1.setFillColor(Color::Green);
  t1.setFont(font2);
  t1.setPosition(Vector2f(550, 10));

  t2.setString("palse");
  t2.setCharacterSize(50);
  t2.setFillColor(Color::White);
  t2.setFont(font2);
  t2.setPosition(Vector2f(660, 10));

  t3.setString("tine");
  t3.setCharacterSize(50);
  t3.setFillColor(Color::Red);
  t3.setFont(font2);
  t3.setPosition(Vector2f(765, 10));
  window.draw(t1);
  window.draw(t2);
  window.draw(t3);
}
void showingoptions(RenderWindow &window) {
  Texture map;
  map.loadFromFile("Assets/"
                   "wp6956942.png");
  Sprite sp(map);
  ShowingOptions sh(900, 1000);
  while (window.isOpen()) {
    window.clear();
    window.draw(sp);
    sh.draw(window);
    window.display();

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up)

          sh.moveup();

        if (event.key.code == Keyboard::Down)

          sh.movedown();
      }
      if (event.type == Event::KeyReleased) {

        if (event.key.code == Keyboard::Enter && sh.returnpressed() == 0) {
          Click.play();
          pagenum = 3;
          return;
        }
        if (event.key.code == Keyboard::Enter && sh.returnpressed() == 1) {
          Click.play();
          levelonepipes.setPositionsl1();
          Flappy.bird.setPosition(300, 400);
          Flag.flag1.setPosition(9200, 10);
          Flappy.birdVelocity = 0;
          Flappy.score = 0;
          j = 0; ////
          pagenum = 3;
          return;
        }
        if (event.key.code == Keyboard::Enter && sh.returnpressed() == 2) {
          Click.play();
          levelonepipes.setPositionsl1();
          Flappy.bird.setPosition(300, 400);
          Flag.flag1.setPosition(9200, 10);
          Flappy.birdVelocity = 0;
          Flappy.score = 0;
          j = 0;
          pagenum = 0;
          return;
        }
      }
    }
  }
}
void showingoptionsl2(RenderWindow &window) {

  ShowingOptions sh(900, 1000);
  Texture t;
  t.loadFromFile("Assets/"
                 "maplvl2.jpg");
  Sprite tp(t);
  while (window.isOpen()) {
    window.clear();
    window.draw(tp);
    sh.draw(window);
    window.display();

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up)

          sh.moveup();

        if (event.key.code == Keyboard::Down)

          sh.movedown();
      }
      if (event.type == Event::KeyReleased) {

        if (event.key.code == Keyboard::Enter) {
          if (sh.returnpressed() == 0) {
            Click.play();
            pagenum = 4;
            return;
          }
          if (sh.returnpressed() == 1) {
            Click.play();
            Flag.flag2.setPosition(15400, 10);
            level2.setPositionl2();
            Flappy.bird3.setPosition(300, 400);
            Flappy.birdVelocity = 0;
            Flappy.score = 0;
            n = 0;
            pagenum = 4;
            return;
          }
          if (sh.returnpressed() == 2) {
            Click.play();
            Flag.flag2.setPosition(15400, 10);
            level2.setPositionl2();
            Flappy.bird3.setPosition(300, 400);
            Flappy.birdVelocity = 0;
            Flappy.score = 0;
            n = 0;
            pagenum = 0;
            return;
          }
        }
      }
    }
  }
}
void showingoptionsl3(RenderWindow &window) {
  ShowingOptions sh(900, 1000);
  Texture t;
  t.loadFromFile("Assets/"
                 "maplvl3.jpg");
  Sprite tp(t);
  while (window.isOpen()) {
    window.clear();
    window.draw(tp);
    sh.draw(window);
    window.display();

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up)

          sh.moveup();

        if (event.key.code == Keyboard::Down)

          sh.movedown();
      }
      if (event.type == Event::KeyReleased) {

        if (event.key.code == Keyboard::Enter) {
          if (sh.returnpressed() == 0) {
            Click.play();
            pagenum = 5;
            return;
          }
          if (sh.returnpressed() == 1) {
            Click.play();
            Flag.flag2.setPosition(15400, 10);
            level2.setPositionl2();
            Flappy.bird2.setPosition(300, 400);
            Flappy.birdVelocity = 0;
            Flappy.score = 0;
            n = 0;
            pagenum = 5;
            return;
          }
          if (sh.returnpressed() == 2) {
            Click.play();
            Flag.flag2.setPosition(15400, 10);
            level2.setPositionl2();
            Flappy.bird2.setPosition(300, 400);
            Flappy.birdVelocity = 0;
            Flappy.score = 0;
            n = 0;
            pagenum = 0;
            return;
          }
        }
      }
    }
  }
}
void leaderboard(RenderWindow &window) {

  Texture t2;
  t2.loadFromFile("Assets/"
                  "copy 2.jpg");
  Sprite sp(t2);
  sp.setPosition(0, 0);

  Text tex[60];
  for (int i = 0; i < 60; i++) {
    tex[i].setFont(font);
    tex[i].setCharacterSize(50);
    tex[i].setFillColor(Color(0, 95, 106));
  }

  ifstream infile;
  infile.open("history.txt", ios::in);
  string lines[60]; // Array of strings
  string line;
  int count = 0;
  while (getline(infile, line, '*') && count < 60) {
    lines[count] = line;
    count++;
  }
  infile.close(); // Close file after reading

  for (int i = 0; i < count; i++) {
    tex[i].setString(lines[i]);
    tex[i].setPosition(Vector2f(100, 50 * i));
  }

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
        break;
      }
      if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        pagenum = 0;
        return;
      }
    }
    window.clear();
    window.draw(sp);
    for (int i = 0; i < count; i++) {
      window.draw(tex[i]);
    }
    window.display();
  }
}
void Gameoverl1(RenderWindow &window) {
  GameOver game1(900, 1000);
  Texture map;
  map.loadFromFile("Assets/"
                   "wp6956942.png");
  Sprite sp(map);
  while (window.isOpen()) {

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up)

          game1.moveup_gameover();

        if (event.key.code == Keyboard::Down)

          game1.movedown_gameover();
      }
      if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Enter) {

          if (game1.Getselected() == 0) {
            Click.play();
            Flappy.bird.setPosition(300, 400);
            Flappy.birdVelocity = 0;
            levelonepipes.setPositionsl1();
            Flappy.score = 0;
            j = 0;
            pagenum = 3;
            return;
          }
          if (game1.Getselected() == 1) {
            Click.play();
            Flappy.bird.setPosition(300, 400);
            Flappy.birdVelocity = 0;
            levelonepipes.setPositionsl1();
            Flappy.score = 0;
            j = 0;
            pagenum = 4;
            return;
          }
          if (game1.Getselected() == 2) {
            Click.play();
            Flappy.birdVelocity = 0;
            Flappy.bird.setPosition(300, 400);
            levelonepipes.setPositionsl1();
            Flappy.score = 0;
            j = 0;
            pagenum = 0;
            return;
          }
        }
      }
    }
    window.clear();
    window.draw(sp);
    game1.Draw_gameover(window);
    window.display();
  }
}
void winningl1(RenderWindow &window) {
  Font font;
  font.loadFromFile("Assets/"
                    "Jersey20Charted-Regular.ttf");
  Text t;
  t.setString("What a Player!");
  t.setFillColor(Color::Red);
  t.setFont(font);
  t.setCharacterSize(100);
  t.setPosition(150, 10);
  GameOver game1(900, 1000);
  Texture BackgroundMenu;
  BackgroundMenu.loadFromFile("Assets/"
                              "wp6956942.png");
  Sprite Background;
  Background.setTexture(BackgroundMenu);
  while (window.isOpen()) {

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up)

          game1.moveup_winning();

        if (event.key.code == Keyboard::Down)

          game1.movedown_winning();
      }
      if (event.type == Event::KeyReleased) {

        if (event.key.code == Keyboard::Enter) {

          if (game1.Getselected2() == 0) {
            Click.play();
            levelonepipes.setPositionsl1();
            Flappy.bird.setPosition(300, 400);
            Flappy.birdVelocity = 0;
            Flappy.score = 0;
            j = 0;
            pagenum = 3;
            return;
          }
          if (game1.Getselected2() == 1) {
            Click.play();
            Flappy.bird.setPosition(300, 400);
            levelonepipes.setPositionsl1();
            Flappy.birdVelocity = 0;
            Flappy.score = 0;
            j = 0;
            pagenum = 4;
            return;
          }
          if (game1.Getselected2() == 2) {
            Click.play();
            Flappy.bird.setPosition(300, 400);
            levelonepipes.setPositionsl1();
            Flappy.birdVelocity = 0;
            Flappy.score = 0;
            j = 0;
            pagenum = 0;
            return;
          }
        }
      }
    }
    window.clear();
    window.draw(Background);
    window.draw(t);
    game1.winningdraw(window);
    window.display();
  }
}
void Gameoverl2(RenderWindow &window) {

  GameOver game1(900, 1000);
  Texture map;
  map.loadFromFile("Assets/"
                   "maplvl2.jpg");
  Sprite sp(map);
  while (window.isOpen()) {

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up)

          game1.moveup_gameover();

        if (event.key.code == Keyboard::Down)

          game1.movedown_gameover();
      }
      if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Enter) {

          if (game1.Getselected() == 0) {
            Click.play();
            pagenum = 4;
            return;
          }
          if (game1.Getselected() == 1) {
            Click.play();
            pagenum = 5;
            return;
          }
          if (game1.Getselected() == 2) {
            Click.play();
            pagenum = 0;
            return;
          }
        }
      }
    }
    window.clear();
    window.draw(sp);
    game1.Draw_gameover(window);
    window.display();
  }
}
void winningl2(RenderWindow &window) {
  Text t;
  t.setString("What a Player!");
  t.setFillColor(Color::Red);
  t.setFont(font);
  t.setCharacterSize(100);
  t.setPosition(150, 10);
  GameOver game1(900, 1000);
  Texture BackgroundMenu;
  BackgroundMenu.loadFromFile("Assets/"
                              "maplvl2.jpg");
  Sprite Background;
  Background.setTexture(BackgroundMenu);
  while (window.isOpen()) {

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up)

          game1.moveup_winning();

        if (event.key.code == Keyboard::Down)

          game1.movedown_winning();
      }
      if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Enter) {

          if (game1.Getselected2() == 0) {
            Click.play();
            pagenum = 4;
            return;
          }
          if (game1.Getselected2() == 1) {
            Click.play();
            pagenum = 5;
            return;
          }
          if (game1.Getselected2() == 2) {
            Click.play();
            pagenum = 0;
            return;
          }
        }
      }
    }
    window.clear();
    window.draw(Background);
    window.draw(t);
    game1.winningdraw(window);
    window.display();
  }
}
void Gameoverl3(RenderWindow &window) {
  Modes m(900, 1000);
  Texture backg;
  backg.loadFromFile("Assets/"
                     "maplvl3.jpg");
  Sprite back;
  back.setTexture(backg);
  while (window.isOpen()) {
    Event ev;
    while (window.pollEvent(ev)) {
      if (ev.type == Event::Closed) {
        window.close();
        break;
      }
      if (ev.type == Event::KeyPressed) {
        if (ev.key.code == Keyboard::Up)

          m.movegameoverup();

        if (ev.key.code == Keyboard::Down)

          m.movegameoverdown();
      }
      if (ev.type == Event::KeyReleased) {
        if (ev.key.code == Keyboard::Enter) {
          if (m.selecgm() == 0) {
            Click.play();
            Flappy.score = 0;
            pagenum = 5;
            return;
          }
          if (m.selecgm() == 1) {
            Click.play();
            pagenum = 0;
            return;
          }
        }
      }
    }
    window.clear();
    window.draw(back);
    m.drawgameover(window);
    window.display();
  }
}
void winningl3(RenderWindow &window) {
  Modes m(900, 1000);
  Texture backg;
  backg.loadFromFile("Assets/"
                     "maplvl3.jpg");
  Sprite back;
  back.setTexture(backg);
  while (window.isOpen()) {
    Event ev;
    while (window.pollEvent(ev)) {
      if (ev.type == Event::Closed) {
        window.close();
        break;
      }
      if (ev.type == Event::KeyPressed) {
        if (ev.key.code == Keyboard::Up)

          m.movewinup();

        if (ev.key.code == Keyboard::Down)

          m.movewindown();
      }
      if (ev.type == Event::KeyReleased) {
        if (ev.key.code == Keyboard::Enter) {
          if (m.select() == 0) {
            Click.play();
            Flappy.score = 0;
            pagenum = 5;
            return;
          }
          if (m.select() == 1) {
            Click.play();
            pagenum = 0;
            return;
          }
        }
      }
    }
    window.clear();
    window.draw(back);
    m.drawwin(window);
    window.display();
  }
}

void updatePipes(vector<PiPe> &pipes, float &pipeOffset) {

  if (pipes.empty() || pipes.back().topPipe.getPosition().x <= 1000) {
    PiPe newPipe;
    newPipe.topPipe.setTexture(pipeTexturetop);
    newPipe.bottomPipe.setTexture(pipeTexturebottom);
    newPipe.topPipe.setPosition(1200 + y, -1350 / 2 + pipeOffset);
    newPipe.bottomPipe.setPosition(1200 + y, 600 - 300 / 2 + pipeOffset);
    newPipe.topPipe.setScale(1.6, 1.1);
    newPipe.bottomPipe.setScale(1.6, 1.1);
    pipes.push_back(newPipe);
  }

  // Loop over the pipes and update their positions
  for (auto &pipe : pipes) {
    pipe.topPipe.move(-PIPE_SPEED, speed_y);
    pipe.bottomPipe.move(-PIPE_SPEED, speed_y);
  }

  // Remove pipes that are out of the screen
  if (pipes[0].topPipe.getPosition().x < -50) {
    pipes.erase(pipes.begin(), pipes.begin() + 1);
    pipeOffset = rand() % difficulty2 - 100; // Randomize pipe position
    y = rand() % Gap_y;
  }
}
void updatePipespr(vector<PiPe> &pipespr, float &pipeOffset) {
  if (pipespr.empty() || pipespr.back().topPipe.getPosition().x <= 800) {
    PiPe newPipe;
    newPipe.topPipe.setTexture(pipeTexturetop);
    newPipe.bottomPipe.setTexture(pipeTexturebottom);
    newPipe.topPipe.setPosition(900 + y2, -200 + pipeOffset);
    newPipe.bottomPipe.setPosition(900 + y2, 400 + pipeOffset);
    newPipe.topPipe.setScale(1, 0.5);
    newPipe.bottomPipe.setScale(1, 1);
    pipespr.push_back(newPipe);
  }

  // Loop over the pipes and update their positions
  for (auto &pipe : pipespr) {
    pipe.topPipe.move(-twoplayersspeed, twoplayersspeed_y);
    pipe.bottomPipe.move(-twoplayersspeed, twoplayersspeed_y);
  }

  // Remove pipes that are out of the screen
  if (pipespr[0].topPipe.getPosition().x < 450) {
    pipespr.erase(pipespr.begin(), pipespr.begin() + 1);
    pipeOffset = rand() % difficulty2 - 100; // Randomize pipe position
    y2 = rand() % 50;
  }
}
void updatePipespl(vector<PiPe> &pipespl, float &pipeOffset2) {
  if (pipespl.empty() || pipespl.back().topp2.getPosition().x <= 300) {
    PiPe newPipe;
    newPipe.topp2.setTexture(top2);
    newPipe.bottomp2.setTexture(bottom2);
    newPipe.topp2.setPosition(400 + y2, -400 / 2 + pipeOffset2);
    newPipe.bottomp2.setPosition(400 + y2, 600 - 400 / 2 + pipeOffset2);
    newPipe.topp2.setScale(1, 0.5);
    newPipe.bottomp2.setScale(1, 1);
    pipespl.push_back(newPipe);
  }

  // Loop over the pipes and update their positions
  for (auto &pipe : pipespl) {
    pipe.topp2.move(-twoplayersspeed, twoplayersspeed_y);
    pipe.bottomp2.move(-twoplayersspeed, twoplayersspeed_y);
  }

  // Remove pipes that are out of the screen
  if (pipespl[0].topp2.getPosition().x < -50) {
    pipespl.erase(pipespl.begin(), pipespl.begin() + 1);
    pipeOffset2 = rand() % difficulty2 - 100; // Randomize pipe position
    y2 = rand() % 50;
  }
}
void modes(RenderWindow &window) {
  Modes m(900, 1000);
  Texture backg;
  backg.loadFromFile("Assets/"
                     "copy 2.jpg");
  Sprite back;
  back.setTexture(backg);
  while (window.isOpen()) {
    Event ev;
    while (window.pollEvent(ev)) {
      if (ev.type == Event::Closed) {
        window.close();
        break;
      }
      if (ev.type == Event::KeyPressed) {
        if (ev.key.code == Keyboard::Up)

          m.moveright();

        if (ev.key.code == Keyboard::Down)

          m.moveleft();
      }
      if (ev.type == Event::KeyReleased) {
        if (ev.key.code == Keyboard::Enter) {
          if (m.selected() == 0) {
            Click.play();
            Flappy.score = 0;
            pagenum = 2;
            return;
          }
          if (m.selected() == 1) {
            Click.play();
            pagenum = 6;
            return;
          }
        }
      }
      if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        Click.play();
        pagenum = 0;
        return;
      }
    }
    window.clear();
    window.draw(back);
    m.draw(window);
    window.display();
  }
}
void endlessmode(RenderWindow &window) {

  Modes m(900, 1000);
  Texture backg;
  backg.loadFromFile("Assets/"
                     "spacebackground.jpg");
  Sprite back;
  back.setPosition(-100, 0);
  back.setTexture(backg);
  while (window.isOpen()) {
    Event ev;
    while (window.pollEvent(ev)) {
      if (ev.type == Event::Closed) {
        window.close();
        break;
      }
      if (ev.type == Event::KeyPressed) {
        if (ev.key.code == Keyboard::Up)

          m.moveup();

        if (ev.key.code == Keyboard::Down)

          m.movedown();
      }
      if (ev.type == Event::KeyReleased) {

        if (ev.key.code == Keyboard::Enter) {
          if (m.selected2() == 0) {
            Click.play();
            pagenum = 7;
            return;
          }
          if (m.selected2() == 1) {
            Click.play();
            pagenum = 9;
            return;
          }
        }
        if (ev.key.code == Keyboard::Escape) {
          Click.play();
          pagenum = 1;
          return;
        }
      }
    }
    window.clear();
    window.draw(back);
    m.drawplayer(window);
    window.display();
  }
}
void Gameoveronep(RenderWindow &window) {

  Modes mo(1920, 1080);
  Text G;
  G.setFont(font);
  G.setCharacterSize(120);
  G.setString("GAME OVER");
  G.setFillColor(Color::Red);
  G.setPosition(Vector2f(250, 20));
  Texture BackgroundMenu;
  BackgroundMenu.loadFromFile("Assets/"
                              "spacexx.jpg");
  Sprite Background;
  Background.setTexture(BackgroundMenu);
  while (window.isOpen()) {

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up)

          mo.moveu();

        if (event.key.code == Keyboard::Down)

          mo.moved();
      }
      if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Enter) {

          if (mo.selecG() == 0) {
            Click.play();
            pagenum = 8;
            return;
          }
          if (mo.selecG() == 1) {
            Click.play();
            pagenum = 1;
            return;
          }
          if (mo.selecG() == 2) {
            Click.play();
            pagenum = 0;
            return;
          }
        }
      }
    }
    window.clear();
    window.draw(Background);
    window.draw(G);
    mo.drawGover(window);
    window.display();
  }
}
void Gameovertwop(RenderWindow &window) {
  Modes mo(1920, 1080);
  Text G;
  G.setFont(font);
  G.setCharacterSize(80);
  G.setFillColor(Color::Red);
  G.setPosition(Vector2f(100, 40));
  if (rightplayerwin == true) {
    G.setString(Flappy.opponentname + " is The winner ");
    rightplayerwin = false;
  }
  if (leftplayerwin == true) {
    G.setString(Flappy.name + " is The winner ");
    leftplayerwin = false;
  }
  Texture BackgroundMenu;
  BackgroundMenu.loadFromFile("Assets/"
                              "koraardia.jpg");
  Sprite Background;
  Background.setTexture(BackgroundMenu);
  while (window.isOpen()) {

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up)

          mo.moveu();

        if (event.key.code == Keyboard::Down)

          mo.moved();
      }
      if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Enter) {
          Click.play();
          if (mo.selecG() == 0) {
            for (auto &pipe : pipespr)
              pipespr.pop_back();
            for (auto &pipe : pipespl)
              pipespl.pop_back();
            Flappy.birdVelocity = 0;
            Flappy.birdVelocity2 = 0;
            pagenum = 11;
            return;
          }
          if (mo.selecG() == 1) {
            Click.play();
            for (auto &pipe : pipespr)
              pipespr.pop_back();
            for (auto &pipe : pipespl)
              pipespl.pop_back();
            Flappy.birdVelocity = 0;
            Flappy.birdVelocity2 = 0;
            window.setSize(Vector2u(900, 1000));
            window.setPosition(Vector2i(450, 0));
            pagenum = 1;
            return;
          }
          if (mo.selecG() == 2) {
            Click.play();
            for (auto &pipe : pipespr)
              pipespr.pop_back();
            for (auto &pipe : pipespl)
              pipespl.pop_back();
            Flappy.birdVelocity = 0;
            Flappy.birdVelocity2 = 0;
            window.setPosition(Vector2i(450, 0));
            window.setSize(Vector2u(900, 1000));
            pagenum = 0;
            return;
          }
        }
      }
    }
    window.clear();
    window.draw(Background);
    window.draw(G);
    mo.drawGover(window);
    window.display();
  }
}
void controlingOn_game() {

  if (Flappy.score == 25) {
    PIPE_SPEED = 5.3;
  }
  if (Flappy.score == 50) {
    PIPE_SPEED = 5.5;
    difficulty = 175;
  }
  if (Flappy.score == 75) {
    PIPE_SPEED = 6;
  }
  if (Flappy.score == 100) {
    speed_y = -1;
    difficulty = 200;
  }
  if (Flappy.score == 125) {
    speed_y = 1;
    difficulty = 200;
    PIPE_SPEED = 6.5;
  }
  if (Flappy.score == 150) {
    speed_y = 0;
    PIPE_SPEED = 7;
    difficulty = 230;
  }
  if (Flappy.score == 160) {
    PIPE_SPEED = 7.3;
    difficulty = 260;
    Gap_y = 150;
  }
  if (Flappy.score == 175) {
    difficulty = 300;
    PIPE_SPEED = 7.6;
    speed_y = -1.5;
  }
  if (Flappy.score == 185) {
    speed_y = 0;
    PIPE_SPEED = 8;
    difficulty = 350;
  }
  if (Flappy.score == 250) {
    PIPE_SPEED = 8.5;
    difficulty = 375;
    Gap_y = 175;
  }
  if (Flappy.score == 280) {
    PIPE_SPEED = 8.8;
    difficulty = 400;
  }
}
void controlingOn_twoplayersgame() {
  if (Flappy.score == 25) {
    twoplayersspeed = 4;
  }
  if (Flappy.score == 50) {
    twoplayersspeed = 4.5;
    difficulty2 = 175;
  }
  if (Flappy.score == 100) {
    twoplayersspeed = 5;
    difficulty2 = 200;
  }
  if (Flappy.score == 125) {
    twoplayersspeed_y = 0.5;
  }
  if (Flappy.score == 160) {
    twoplayersspeed_y = -0.5;
  }
  if (Flappy.score == 200) {
    twoplayersspeed = 5.5;
    difficulty2 = 225;
  }
  if (Flappy.score == 220) {
    twoplayersspeed = 6;
  }
  if (Flappy.score == 240) {
    difficulty2 = 250;
    twoplayersspeed_y = -1.3;
  }
  if (Flappy.score == 290) {
    twoplayersspeed_y = 1.3;
  }
  if (Flappy.score == 330) {
    twoplayersspeed = 6.8;
    difficulty2 = 275;
  }
  if (Flappy.score == 380) {
    difficulty2 = 300;
    twoplayersspeed = 7.3;
  }
}
void Myteam(RenderWindow &window) {
  Texture t1, t2, t3, t4, t5, t6, t7;
  t1.loadFromFile("Assets/"
                  "alaa.jpg");
  t2.loadFromFile("Assets/"
                  "ashraf 2.jpg");
  t3.loadFromFile("Assets/"
                  "hamdy.jpg");
  t4.loadFromFile("Assets/"
                  "ibrahim 2.jpg");
  t5.loadFromFile("Assets/"
                  "bassam.jpg");
  t6.loadFromFile("Assets/"
                  "hossam.jpg");
  t7.loadFromFile("Assets/"
                  "khaled.jpg");
  Sprite Alaa(t1), Ashraf(t2), Hamdy(t3), Khaled(t7), Hema(t4), Hossam(t6),
      Bassam(t5);

  // Peaky Blinders

  while (exit2) {
    Clock c;
    while (true) {
      window.clear();
      window.draw(Ashraf);
      window.display();
      if (c.getElapsedTime().asSeconds() > 2)
        break;
    }
    while (true) {
      window.clear();
      window.draw(Alaa);
      window.display();
      if (c.getElapsedTime().asSeconds() > 4)
        break;
    }
    while (true) {
      window.clear();
      window.draw(Hema);
      window.display();
      if (c.getElapsedTime().asSeconds() > 6)
        break;
    }
    while (true) {
      window.clear();
      window.draw(Hamdy);
      window.display();
      if (c.getElapsedTime().asSeconds() > 8)
        break;
    }
    while (true) {
      window.clear();
      window.draw(Hossam);
      window.display();
      if (c.getElapsedTime().asSeconds() > 10)
        break;
    }
    while (true) {
      window.clear();
      window.draw(Khaled);
      window.display();
      if (c.getElapsedTime().asSeconds() > 12)
        break;
    }
    while (true) {
      window.clear();
      window.draw(Bassam);
      window.display();
      if (c.getElapsedTime().asSeconds() > 14)
        break;
    }
    exit2 = false;
  }
  exit2 = true;
  pagenum = 0;
  return;
}
void Instructions(RenderWindow &window) {
  Texture t1, t2, t3, t4, t5, t6;
  t1.loadFromFile("Assets/"
                  "ins1.jpg");
  t2.loadFromFile("Assets/"
                  "inst2.jpg");
  t3.loadFromFile("Assets/"
                  "inst3.jpg");
  t4.loadFromFile("Assets/"
                  "multi.jpg");
  t5.loadFromFile("Assets/"
                  "Escape.jpg");
  t6.loadFromFile("Assets/"
                  "Bugs.jpg");

  Sprite inst[6];
  inst[0].setTexture(t1);
  inst[1].setTexture(t2);
  inst[2].setTexture(t3);
  inst[3].setTexture(t4);
  inst[4].setTexture(t5);
  inst[5].setTexture(t6);
  Sprite *ptr = inst;

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Enter) {
          ptr++;
          countenter++;
          if (countenter == 6) {
            pagenum = 0;
            return;
          }
        }
      }
    }
    window.clear();
    window.draw(*ptr);
    window.display();
  }
}
void Attributesofcounting_score() {
  // score

  scoretext.setFont(font);
  scoretext.setPosition(370, 0);
  scoretext.setScale(1.2, 1.2);
  scoretext.setFillColor(Color::Black);

  // counting

  ready[0].setString("3");
  ready[1].setString("2");
  ready[2].setString("1");
  ready[3].setString("0");

  for (int i = 0; i < 4; i++) {
    ready[i].setFont(font);
    ready[i].setCharacterSize(150);
    ready[i].setFillColor(Color(0, 95, 106));
    ready[i].setPosition(Vector2f(400, 350));
  }
}
