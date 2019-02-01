#include "main.h"

#ifndef RING_H
#define RING_H


class Ring {
public:
    Ring() {}
    Ring(float x, float y, color_t color);
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
};



#endif // RING_H
