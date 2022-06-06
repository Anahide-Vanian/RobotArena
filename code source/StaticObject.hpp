#ifndef STATICOBJECT_HPP
#define STATICOBJECT_HPP


#include "Object.hpp"

class StaticObject : public Object {

public:
    Static_Object();
    ~Static_Object();

    // Display methods
    void initTexture(char* texture_name);
    void initSprite(Texture texture);
    void display(Sprite sprite);

private:
     float xpos;
     float ypos;
};

#endif // STATIC_OBJECT_HPP
