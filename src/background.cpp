#include "background.h"
#include "main.h"

Floor::Floor(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;

    bounding_box_t bb;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    // float initx = 0.25f, inity = 0.25f;
    const int n = 500;

    static  GLfloat vertex_buffer_data[18*n];
    float k;
   for (int i=0; i<n; i++) 
   {
    float j = 0.25f;
    k = 0.25f * i;
   

     if (i % 2 == 1) j = 0;
      vertex_buffer_data[18*i] = -3.0f + k;
       vertex_buffer_data[18*i + 1] = -2.0f + j;
        vertex_buffer_data[18*i + 2] = 0.0f;
         vertex_buffer_data[18*i + 3] = -3.0 + k;
          vertex_buffer_data[18*i + 4] = -1.75f + j;
           vertex_buffer_data[18*i + 5] = 0.0f;
            vertex_buffer_data[18*i + 6] = -2.75f + k;
             vertex_buffer_data[18*i + 7] = -1.75f + j;
              vertex_buffer_data[18*i + 8] = 0.0f;
              vertex_buffer_data[18*i + 9] = -2.75f + k;
               vertex_buffer_data[18*i + 10] = -2.0f + j;
                vertex_buffer_data[18*i + 11] = 0.0f;
                 vertex_buffer_data[18*i + 12] = -3.0f + k;
                  vertex_buffer_data[18*i + 13] = -2.0f + j;
                   vertex_buffer_data[18*i + 14] = 0.0f;
                    vertex_buffer_data[18*i + 15] = -2.75f + k;
                     vertex_buffer_data[18*i + 16] = -1.75f + j;
                      vertex_buffer_data[18*i + 17] = 0.0f;
    }

    this->object = create3DObject(GL_TRIANGLES, 18*n, vertex_buffer_data, color, GL_FILL);
}

void Floor::draw(glm::mat4 VP) 
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

void Floor::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}


bounding_box_t Floor::def_bounding_box()
{
    bounding_box_t bb;
    bb.x = this->position.x;
    bb.y = this->position.y;
    bb.width = 500.0f/0.25f;
    bb.height = 0.25f;
    return bb;
}

void Floor::tick() 
{
    // this->position.y += this->speed;
}

Floor2::Floor2(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;

    bounding_box_t bb;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    // float initx = 0.25f, inity = 0.25f;
    const int n = 500;

    static  GLfloat vertex_buffer_data[18*n];
    float k;
   for (int i=0; i<n; i++) 
   {
    float j = 0.25f;
    k = 0.25f * i;
   

     if (i % 2 == 0) j = 0;
      vertex_buffer_data[18*i] = -3.0f + k;
       vertex_buffer_data[18*i + 1] = -2.0f + j;
        vertex_buffer_data[18*i + 2] = 0.0f;
         vertex_buffer_data[18*i + 3] = -3.0 + k;
          vertex_buffer_data[18*i + 4] = -1.75f + j;
           vertex_buffer_data[18*i + 5] = 0.0f;
            vertex_buffer_data[18*i + 6] = -2.75f + k;
             vertex_buffer_data[18*i + 7] = -1.75f + j;
              vertex_buffer_data[18*i + 8] = 0.0f;
              vertex_buffer_data[18*i + 9] = -2.75f + k;
               vertex_buffer_data[18*i + 10] = -2.0f + j;
                vertex_buffer_data[18*i + 11] = 0.0f;
                 vertex_buffer_data[18*i + 12] = -3.0f + k;
                  vertex_buffer_data[18*i + 13] = -2.0f + j;
                   vertex_buffer_data[18*i + 14] = 0.0f;
                    vertex_buffer_data[18*i + 15] = -2.75f + k;
                     vertex_buffer_data[18*i + 16] = -1.75f + j;
                      vertex_buffer_data[18*i + 17] = 0.0f;
    }

    this->object = create3DObject(GL_TRIANGLES, 18*n, vertex_buffer_data, color, GL_FILL);
}

void Floor2::draw(glm::mat4 VP) 
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

void Floor2::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}


bounding_box_t Floor2::def_bounding_box()
{
    bounding_box_t bb;
    bb.x = this->position.x;
    bb.y = this->position.y;
    bb.width = 500.0f/0.25f;
    bb.height = 0.25f;
    return bb;
}
