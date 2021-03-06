#ifndef TIME_VIEWER
#define TIME_VIEWER

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include <string>

#include "interface.hpp"

std::string timeToString(sf::Time time);
std::string scoreToString(int score);

class DataViewer : public sf::Text, public InterfaceElement
{
public :
  DataViewer(sf::RenderWindow* window);
  void update(const sf::Time&) override {}
  void show(const sf::View& sf_view) override;
  void setTime(const sf::Time& time);
  void setScore(int score);
private :
  sf::RenderWindow* window;
};
#endif
