#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Object.hpp"
#include "Projectile.hpp"
#include "DynamicObject.hpp"

class Player : public DynamicObject {

public:
    Player();
    Player(const char* nom, float x, float y);
    ~Player();
    //getters et setters
		sf::Sprite getSprite();
    const sf::FloatRect getSpriteBounds() const;
    void setPos(float xpos, float ypos);
    void setMove(float xpos, float ypos);
    float getPosx();
    float getPosy();
    int getHp(){ return this->hp; };
    int getMaxhp(){ return this->maxhp; };
    int getSpeed(){ return this->speed; };
    int getAttack(){ return this->attack; };
    int getGun(){ return this->gun; };
    int getLaser(){ return this->laser; };
    int getDir(){ return this->dir; };
    std::vector<Projectile*>& getProjectile(){return this->projectiles; };

    void setHp(int hp){this->hp = hp; };
    void setMaxhp(int maxhp){this->maxhp = maxhp; };
    void setSpeed(int speeds){this->speed = speeds; };
    void setAttack(int attacks){ this->attack = attacks; };
    void setGun(int amo){ this->gun = amo; };
    void setLaser(int amo){ this->laser = amo; };
    void setDir(int dire){this->dir = dire; }

    // Display methods
    void initObject(const char* nom, int x, int y);
    void display(Renderer& renderer) const;

    void addProjectile();
    void deleteProjectile(int i);


protected:
     int hp;
     int maxhp;
     int speed;
     int attack;
		 int sword;
		 int gun;
		 int laser;
     std::vector<Projectile*> projectiles;
     int dir;
};

#endif // PLAYER_HPP
