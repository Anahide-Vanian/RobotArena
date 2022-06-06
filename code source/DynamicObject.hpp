#ifndef DYNAMICOBJECT_HPP
#define DYNAMICOBJECT_HPP


#include "Object.hpp"

class DynamicObject : public Object {

public:
    DynamicObject();
    //~DynamicObject();

    // Display methods
    void initObject(const char* nom, int x, int y);
    void display(Renderer& renderer) const;

protected:
    float speed;
    float xdir;
    float ydir;
};

#endif // DYNAMICOBJECT_HPP
