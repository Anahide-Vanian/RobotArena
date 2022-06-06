#include "Renderer.hpp"

#include "Player.hpp"
#include "Environment.hpp"
#include "Laser.hpp"
#include "Gun.hpp"
#include "Health.hpp"
#include "Speed.hpp"
#include "Attack.hpp"
#include "Projectile.hpp"
#include <iostream>

//DESIGN PATERN visiteur 
//constructeur du renderer
Renderer::Renderer() //crée la fenêtre
{
  window = new sf::RenderWindow(sf::VideoMode(1600, 900),"ROBOT ARENA", sf::Style::Titlebar | sf::Style::Close);
  window->setFramerateLimit(60);//60 frames/secondes -> fréquence
}

//destructeur
//destructeur du renderer
Renderer::~Renderer()
{
    delete window;
}

//DISPLAY les éléments du jeu
void Renderer::displayPlayer(const sf::Sprite& p){ window->draw(p); }
void Renderer::displayEnvironment(const sf::Sprite& e){ window->draw(e); }
void Renderer::displayArmeLaser(const sf::Sprite& p){ window->draw(p);}
void Renderer::displayArmeGun(const sf::Sprite& p){ window->draw(p);}
void Renderer::displayAttack(const sf::Sprite& p){ window->draw(p);}
void Renderer::displayHealth(const sf::Sprite& p){window->draw(p);}
void Renderer::displaySpeed(const sf::Sprite& p) {window->draw(p);}
void Renderer::displayProjectile(const sf::Sprite& p) {window->draw(p);}
