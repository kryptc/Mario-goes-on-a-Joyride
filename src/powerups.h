#include "main.h"

#ifndef POWERUPS_H
#define POWERUPS_H

class BigMoney {
public:
    BigMoney() {}
    BigMoney(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float speed;
    int jumpStatus;
    int jumpTime;

    void gravityEffect();
    void jump();
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bounding_box_t def_bounding_box();
    void tick();
    // double speed;
private:
    VAO *object;
    VAO *object1;

};

class Zoomer {
public:
    Zoomer() {}
    Zoomer(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float speed;
    int jumpStatus;
    int jumpTime;

    void gravityEffect();
    void jump();
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bounding_box_t def_bounding_box();
    void tick();
    // double speed;
private:
    VAO *object;
    VAO *object1;

};

class Shield {
public:
    Shield() {}
    Shield(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float speed;
    int jumpStatus;
    int jumpTime;
    int active;

    void gravityEffect();
    void jump();
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bounding_box_t def_bounding_box();
    void tick();
    // double speed;
private:
    VAO *object1;

};
#endif // POWERUPS_H
