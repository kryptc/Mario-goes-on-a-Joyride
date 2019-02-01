#include "main.h"

#ifndef BACKGROUND_H
#define BACKGROUND_H


class Floor {
public:
    Floor() {}
    Floor(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bounding_box_t def_bounding_box();
    void tick();
    // double speed;
private:
    VAO *object;
};

class Floor2 {
public:
    Floor2() {}
    Floor2(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bounding_box_t def_bounding_box();
    void tick();
    // double speed;
private:
    VAO *object;
};
// class Wall {
// public:
//     Wall() {}
//     Wall(float x, float y, color_t color);
//     glm::vec3 position;

//     void draw(glm::mat4 VP);
//     void set_position(float x, float y);
//     bounding_box_t def_bounding_box();
//     void tick();
//     // double speed;
// private:
//     VAO *object;
// };

#endif // BACKGROUND_H
