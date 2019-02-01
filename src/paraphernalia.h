#include "main.h"

#ifndef PARAPHERNALIA_H
#define PARAPHERNALIA_H


class LevelText {
public:
    LevelText() {}
    LevelText(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;

    void draw(glm::mat4 VP, int i);
    void set_position(float x, float y);
private:
    VAO *object;
    VAO *object1;
    VAO *object2;
    VAO *object3;
};


class ScoreBoard {
public:
    ScoreBoard() {}
    ScoreBoard(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;

    void draw(glm::mat4 VP, int i);
    void set_position(float x, float y);

private:
    VAO *object0;
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    VAO *object6;
    VAO *object7;
    VAO *object8;
    VAO *object9;
    VAO *objectneg;
};


#endif // PARAPHERNALIA_H
