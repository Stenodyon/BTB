/*** This file contains the InterfaceElement class relating
 * to the game display. ***/

#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include <list>
#include <vector>

#include "interface.hpp"
#include "mapreader.hpp"
#include "scenecircle.hpp"
#include "sceneelement.hpp"

class GameScene : public InterfaceElement
{
public:
    GameScene(MapReader*, sf::RenderWindow*);
    ~GameScene();

    // computes circles' positions, and update the SceneElement chain
    void update(const sf::Time&) override;

    // display the game
    void show(const sf::View&) override; // TODO : make the parameter usefull

private:
    // remove useless elements
    void removeUselessElements(const sf::Time&);

    MapReader * map_reader;

    sf::RenderWindow * window;

    std::list<SceneElement*> elements;
};

#endif // GAMESCENE_HPP

