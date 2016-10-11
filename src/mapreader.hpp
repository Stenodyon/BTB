#ifndef MAP_READER
#define MAP_READER

#include <algorithm>
#include <vector>
#include <SFML/System.hpp>
#include <stdexcept>

#include "mapdata.hpp"
#include "scenecircledata.hpp"
#include "sceneelementdata.hpp"


class MapReader
{
public:
  MapReader(const MapData& map_data);
  ~MapReader();
  void startSong();
  std::vector<SceneElementData*> getNewElements(const sf::Time&); //can't be const because last_id_not_displayed is modified.
  int getScore() const;
  void computeScore(const int x, const int y, const sf::Time &time);


private :
  std::vector<SceneElementData*> scene_elements;//this vector is sorted by click order.
  const MapData& map_data;
  int last_id_not_displayed; //this id avoids to  browse all the scene_elements vector when getNewElements is called.
  int last_id_not_clicked;
  int score;
};

#endif //MAP_READER
