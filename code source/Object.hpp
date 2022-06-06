#ifndef OBJECT_HPP
#define OBJECT_HPP


#include "Renderer.hpp"
class Object {
public:
    virtual void initObject(const char* nom, int x, int y) =0;
    virtual void display(Renderer& renderer) const = 0;
    virtual ~Object() {};
protected:
    float xpos;//position en x de l'objet
    float ypos;//position en y de l'objet
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif // OBJECT_HPP
