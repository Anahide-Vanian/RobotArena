#ifndef OBJECT_HPP
#define OBJECT_HPP

/*
#include<iostream>
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include"math.h"*/

#include "Renderer.hpp"
class Object {
public:
    virtual void initObject(const char* nom, int x, int y) =0;
    virtual void display(Renderer& renderer) const = 0;
    virtual ~Object() {};
protected:
    float xpos;
    float ypos;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif // OBJECT_HPP
