#include "main.h"

#ifndef COIN_H
#define COIN_H


class Coin {
public:
    Coin() {}
    Coin(float x, float y, color_t color, float radius);
    glm::vec3 position;
    float rotation;
    float speed;
    int jumpStatus;
    int jumpTime;

    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bounding_box_t def_bounding_box();
    void tick();
    // double speed;
private:
    VAO *object;
};



#endif // COIN_H
