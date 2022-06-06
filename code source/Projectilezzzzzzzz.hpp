#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "Object.hpp"
#include "Player.hpp"
#include "DynamicObject.hpp"

class Projectile : public DynamicObject {

public:
    Projectile();
    Projectile(float x, float y);
    //~Player();
		sf::Sprite getSprite();
    const sf::FloatRect getSpriteBounds() const;
    void setPos(float xpos, float ypos);
    void setMove();
    float getPosx();
    float getPosy();
    void setDirx();
    void setDiry();

    // Display methods
    void initObject(const char* nom, int x, int y);
    void display(Renderer& renderer) const;


protected:
     int dir;
};

#endif // PLAYER_HPP
