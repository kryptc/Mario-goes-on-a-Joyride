#include "main.h"

#ifndef ENEMIES_H
#define ENEMIES_H


class FireLine {
public:
    FireLine() {}
    FireLine(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float speed;

    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bounding_box_t def_bounding_box();
    void tick();
    // double speed;
private:
    VAO *object;
    VAO *object1;
};

class LaserBeam {
public:
    LaserBeam() {}
    LaserBeam(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float speed;
    int down;

    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bounding_box_t def_bounding_box();
    void tick();
private:
    VAO *object;
    VAO *object1;

};

class Boomerang {
public:
    Boomerang() {}
    Boomerang(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float speed;
    int apex;
    int journeyTime;

    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bounding_box_t def_bounding_box();
    void tick();
    void moveLeft();
    void moveRight();
private:
    VAO *object;
};

class Dragon {
public:
    Dragon() {}
    Dragon(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float speed;
    int ShootTime;
    int down;
    int dead;

    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bounding_box_t def_bounding_box();
    void tick(int dir);

private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
};


class Snowball {
public:
    Snowball() {}
    Snowball(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float speed;

    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bounding_box_t def_bounding_box();
    void tick();
    // double speed;
private:
    VAO *object;
};

#endif // ENEMIES_H
