#include "view.hpp"
#include <iostream>
#include <string>

using namespace std;

View::View(MapReader* map_reader)
  : map_reader(map_reader)
{
  // création de le fenêtre
  window = new sf::RenderWindow(sf::VideoMode(500, 500), "Bite The Beat v0.0");

  game_scene = new GameScene(map_reader, window);
  game_scene->setActivity(true);
  game_scene->setVisibility(true);

  font.loadFromFile("font/augusta.ttf");
  tv = new TimeViewer(window);
  tv->setFont(font);
  tv->setCharacterSize(24);
  tv->setPosition(0,0);
}

View::~View()
{
  delete window;
  delete game_scene;
  delete tv;
}

void View::show()
{

  sf::View sf_view = window->getView();

  window->clear();

  tv->setTime(map_reader->getTime());
  tv->show(sf_view);
  // displaying InterfaceElements...
  game_scene->update(map_reader->getTime());

  game_scene->show(sf_view);

  window->display();
}
