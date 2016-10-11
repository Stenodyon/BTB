/*** This file contains an abstract class for using the scene element data ***/

#ifndef SCENE_ELEMENT_DATA
#define SCENE_ELEMENT_DATA

#include <SFML/System.hpp>
#include <stdexcept>
#include <string>

#include "mapdata.hpp"

#define MISSED -50

sf::Vector2f parsePosition(const json& json_position);


class SceneElementData
{
    public :
        SceneElementData(int elementID , const MapData& map_data);

        //accessors
        virtual int computeScore(const sf::Time& click_moment,
                const sf::Vector2f& click_position)
        {}

        sf::Time getClickTime() const;
        sf::Time getDuration() const;
        sf::Time getEmergence() const;
        float getRatio() const;
        std::string getType() const;

        bool isVisible(const sf::Time& timeElapsed) const;

        //can not be clicked anymore
        bool isPassed(const sf::Time& timeElapsed) const;

        void emerge();
        bool hasToEmerge(const sf::Time&);


        class EmergenceComparison
        {
            public :
                EmergenceComparison(){}
                bool operator()(const SceneElementData* sed1,
                                const SceneElementData* sed2)
                {
                    return sed1->getEmergence() <= sed2->getEmergence();
                }
        };

        class ClickComparison
        {
            public :
                bool operator()(const SceneElementData* sed1,
                                const SceneElementData* sed2)
                {
                    return sed1->getClickTime() <= sed2->getClickTime();
                }
        };

    protected :
        const MapData& map_data;
        int elementID;
        bool emerged;
        bool clicked; //unused for the moment
};


#endif //SCENE_ELEMENT_DATA
