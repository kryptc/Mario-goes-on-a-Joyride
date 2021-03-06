#include "ring.h"
#include "main.h"

Ring::Ring(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed = 0.2  ;
    this->time = 1200;
    this->attract = 0;

    bounding_box_t bb;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float initx = 5.0f, inity = 0.0f;
    const int m = 100;

    static  GLfloat vertex_buffer_data1[9*m];

   for (int i=0; i<m; i++) 
   {
      inity *= inity<0?-1:1;
      vertex_buffer_data1[9*i] = 0.0f;
       vertex_buffer_data1[9*i + 1] = 0.0f;
        vertex_buffer_data1[9*i + 2] = -0.2f;
         vertex_buffer_data1[9*i + 3] = initx;
          vertex_buffer_data1[9*i + 4] = inity;
           vertex_buffer_data1[9*i + 5] = -0.2f;
            vertex_buffer_data1[9*i + 6] = initx*cos(2*3.14159/m) - inity*sin(2*3.14159/m);
             vertex_buffer_data1[9*i + 7] = initx*sin(2*3.14159/m) + inity*cos(2*3.14159/m);
              vertex_buffer_data1[9*i + 8] = -0.2f;

              initx = vertex_buffer_data1[9*i + 6];
              inity = vertex_buffer_data1[9*i + 7];
    }

    initx = 4.8f, inity = 0.0f;
    const int n = 100;

    static  GLfloat vertex_buffer_data2[9*n];

   for (int i=0; i<n; i++) 
   {
      inity *= inity<0?-1:1;
      vertex_buffer_data2[9*i] = 0.0f;
       vertex_buffer_data2[9*i + 1] = 0.0f;
        vertex_buffer_data2[9*i + 2] = -0.1f;
         vertex_buffer_data2[9*i + 3] = initx;
          vertex_buffer_data2[9*i + 4] = inity;
           vertex_buffer_data2[9*i + 5] = -0.1f;
            vertex_buffer_data2[9*i + 6] = initx*cos(2*3.14159/n) - inity*sin(2*3.14159/n);
             vertex_buffer_data2[9*i + 7] = initx*sin(2*3.14159/n) + inity*cos(2*3.14159/n);
              vertex_buffer_data2[9*i + 8] = -0.1f;

              initx = vertex_buffer_data2[9*i + 6];
              inity = vertex_buffer_data2[9*i + 7];
    }

    this->object = create3DObject(GL_TRIANGLES, 3*m, vertex_buffer_data1, COLOR_PINK, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data2, COLOR_AUBERGINE, GL_FILL);
}

void Ring::draw(glm::mat4 VP) 
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
}

void Ring::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}

bounding_box_t Ring::def_bounding_box()
{
    bounding_box_t bb;
    bb.x = this->position.x;
    bb.y = this->position.y;
    bb.width = 2.0f;
    bb.height = 1.5f;
    return bb;
}

void Ring::tick(float x)
{

} 