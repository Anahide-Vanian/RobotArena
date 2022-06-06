#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP


#include "Object.hpp"

class Environment : public Object {

public:
    Environment();
    Environment(const char* nom, int x, int y);
    //~Environment();
    sf::Sprite getSprite();
    const sf::FloatRect getSpriteBounds() const;

    // Display methods
    void initObject();
    void initObject(const char* nom, int x, int y);
    void display(Renderer& renderer) const;

private:

};

#endif // ENVIRONMENT_HPP
