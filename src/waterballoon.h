#include "main.h"

#ifndef WATERBALLOON_H
#define WATERBALLOON_H


class WaterBalloon {
public:
    WaterBalloon() {}
    WaterBalloon(float x, float y, color_t color);
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

#endif // WATERBALLOON_H
