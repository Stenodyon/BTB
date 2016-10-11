/*** This file contains the View part of the MVC architecture.
***/

#ifndef VIEW_HPP
#define VIEW_HPP

#include <vector>

#include "dataviewer.hpp"
#include "gamescene.hpp"

class View
{
public:
    View(MapReader*);
    ~View();

    // displays the program
    void show(const sf::Time&);

    // window on which the program is displayed
    sf::RenderWindow* window;

private:

    // InterfaceElements to display
    GameScene * game_scene;
    DataViewer* tv;

    sf::Font font;

    MapReader * map_reader;
};

#endif // VIEW_HPP

