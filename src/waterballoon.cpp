#include "waterballoon.h"
#include "main.h"

WaterBalloon::WaterBalloon(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed = 0.2  ;

    this->jumpStatus = 0;
    this->jumpTime = 0;

    bounding_box_t bb;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float initx = 0.2f, inity = 0.2f;
    const int n = 200;

    static  GLfloat vertex_buffer_data[9*n];

   for (int i=0; i<n; i++) 
   {
      vertex_buffer_data[9*i] = 0.0f;
       vertex_buffer_data[9*i + 1] = 0.0f;
        vertex_buffer_data[9*i + 2] = 1.0f;
         vertex_buffer_data[9*i + 3] = initx;
          vertex_buffer_data[9*i + 4] = inity;
           vertex_buffer_data[9*i + 5] = 1.0f;
            vertex_buffer_data[9*i + 6] = initx*cos(2*3.14159/n) - inity*sin(2*3.14159/n);
             vertex_buffer_data[9*i + 7] = initx*sin(2*3.14159/n) + inity*cos(2*3.14159/n);
              vertex_buffer_data[9*i + 8] = 1.0f;

              initx = vertex_buffer_data[9*i + 6];
              inity = vertex_buffer_data[9*i + 7];
    }


    this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, color, GL_FILL);
}

void WaterBalloon::draw(glm::mat4 VP) 
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void WaterBalloon::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}


bounding_box_t WaterBalloon::def_bounding_box()
{
    bounding_box_t bb;
    bb.x = this->position.x;
    bb.y = this->position.y;
    bb.width = 0.2f;
    bb.height = 0.2f;
    return bb;
}

void WaterBalloon::tick() 
{
    this->position.y += this->speed;
}
