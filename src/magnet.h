#include "main.h"

#ifndef MAGNET_H
#define MAGNET_H


class Magnet {
public:
    Magnet() {}
    Magnet(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float speed;
    int time;
    int attract;

    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bounding_box_t def_bounding_box();
    void tick(float x);
    // double speed;
private:
    VAO *object;
    VAO *object1;
    VAO *object2;

};



#endif // MAGNET_H
