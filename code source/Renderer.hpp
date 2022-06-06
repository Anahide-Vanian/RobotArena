#ifndef RENDERER_HPP
#define RENDERER_HPP

//#include"SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player;
class Environment;
class Laser;
class Gun;
class Attack;
class Health;
class Speed;
class Projectile;

class Renderer {



public:
  Renderer();
  ~Renderer();
  void displayPlayer(const sf::Sprite& p);
  void displayEnvironment(const sf::Sprite& e);
  void displayArmeLaser(const sf::Sprite& p);
  void displayArmeGun(const sf::Sprite& p);
  void displayAttack(const sf::Sprite& p);
  void displayHealth(const sf::Sprite& p);
  void displaySpeed(const sf::Sprite& p);
  void displayProjectile(const sf::Sprite& p);
  sf::RenderWindow& getWindow() {return *window;};

private:
  sf::RenderWindow* window;
};


#endif
