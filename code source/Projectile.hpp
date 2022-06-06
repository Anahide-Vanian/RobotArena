#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "Object.hpp"
#include "Player.hpp"
#include "DynamicObject.hpp"

class Projectile : public DynamicObject {

public:
    Projectile();
    Projectile(float x, float y,int dire);
    //~Player();
	sf::Sprite getSprite();
    const sf::FloatRect getSpriteBounds() const;
    void setPos(float xpos, float ypos);
    void setMove(Player& p);
    float getPosx();
    float getPosy();

    // Display methods
    void initObject(const char* nom, int x, int y);
    void display(Renderer& renderer) const;


protected:
    int dir;

};

#endif // PLAYER_HPP
