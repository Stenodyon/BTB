#include "scenecircle.hpp"


SceneCircle::SceneCircle(sf::RenderWindow * window, const SceneElementData * a_data)
    : window(window)
{
    data = a_data;
    casted_data = dynamic_cast<const SceneCircleData*>(data);

    // create image, texture and sprites
    circle_image.create(2 * casted_data->getRadius(), 2 * casted_data->getRadius(), sf::Color(0,0,0,0));

    // drawing the image to display
    for(unsigned int x = 0; x != 2 * casted_data->getRadius(); x++)
    {
        for(unsigned int y = 0; y != 2 * casted_data->getRadius(); y++)
        {
            if(static_cast<int>(distance(x,y,casted_data->getRadius(),casted_data->getRadius())) <= casted_data->getRadius())
            {
                circle_image.setPixel(x,y,casted_data->getColor());
            }
        }
    }

    circle_tex.loadFromImage(circle_image);
    circle_tex.setSmooth(true);
    circle_1.setTexture(circle_tex, true);
    circle_2.setTexture(circle_tex, true);
}

SceneCircle::~SceneCircle()
{

}

void SceneCircle::prepare(const sf::Time& time)
{
    SceneElement::prepare(time);

    // if it is time to display the element
    if(visible)
    {
        // calculation of both circles positions
        if(time < casted_data->getClickTime()) // before click time
        {
            pos_circle_1.x = casted_data->getPosition().x - 2 * casted_data->getRadius() + static_cast<int>(static_cast<float>(casted_data->getRadius()) * (time.asSeconds() - (casted_data->getClickTime().asSeconds() - casted_data->getDuration().asSeconds() * casted_data->getRatio())) / (casted_data->getDuration().asSeconds() * casted_data->getRatio()));
            pos_circle_1.y = casted_data->getPosition().y - casted_data->getRadius();
            pos_circle_2.x = casted_data->getPosition().x + (casted_data->getPosition().x - pos_circle_1.x) - 2 * casted_data->getRadius();
            pos_circle_2.y = pos_circle_1.y;
        }
        else // after click time
        {
            pos_circle_1.x = casted_data->getPosition().x - casted_data->getRadius();
            pos_circle_1.y = casted_data->getPosition().y - casted_data->getRadius();
            pos_circle_2.x = pos_circle_1.x;
            pos_circle_2.y = pos_circle_1.y;
        }

        // assigns positions to both sprites
        circle_1.setPosition(pos_circle_1);
        circle_2.setPosition(pos_circle_2);
    }
}

void SceneCircle::show()
{
    // if it is time to show the element
    if(visible)
    {
        // draw both circles on the window
        window->draw(circle_1);
        window->draw(circle_2);
    }
}
