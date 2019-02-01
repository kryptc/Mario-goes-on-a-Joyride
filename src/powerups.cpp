#include "powerups.h"
#include "main.h"

BigMoney::BigMoney(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed = 0.2  ;

    this->jumpStatus = 1;
    this->jumpTime = 0;

    bounding_box_t bb;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float initx = 0.1f, inity = 0.1f;
    const int n = 200;

    static  GLfloat vertex_buffer_data1[9*n];

   for (int i=0; i<n; i++) 
   {
      vertex_buffer_data1[9*i] = 0.0f;
       vertex_buffer_data1[9*i + 1] = 0.0f;
        vertex_buffer_data1[9*i + 2] = 0.0f;
         vertex_buffer_data1[9*i + 3] = initx;
          vertex_buffer_data1[9*i + 4] = inity;
           vertex_buffer_data1[9*i + 5] = 0.0f;
            vertex_buffer_data1[9*i + 6] = initx*cos(2*3.14159/n) - inity*sin(2*3.14159/n);
             vertex_buffer_data1[9*i + 7] = initx*sin(2*3.14159/n) + inity*cos(2*3.14159/n);
              vertex_buffer_data1[9*i + 8] = 0.0f;

              initx = vertex_buffer_data1[9*i + 6];
              inity = vertex_buffer_data1[9*i + 7];
    }

   static  GLfloat vertex_buffer_data[9*30];
   initx = 0.15f, inity = 0.15f;
   for (int i=0; i<30; i++) 
   {
      vertex_buffer_data[9*i] = 0.0f;
       vertex_buffer_data[9*i + 1] = 0.0f;
        vertex_buffer_data[9*i + 2] = -0.1f;
         vertex_buffer_data[9*i + 3] = initx;
          vertex_buffer_data[9*i + 4] = inity;
           vertex_buffer_data[9*i + 5] = -0.1f;
            vertex_buffer_data[9*i + 6] = initx*cos(2*3.14159/30) - inity*sin(2*3.14159/30);
             vertex_buffer_data[9*i + 7] = initx*sin(2*3.14159/30) + inity*cos(2*3.14159/30);
              vertex_buffer_data[9*i + 8] = -0.1f;

              initx = vertex_buffer_data[9*i + 6];
              inity = vertex_buffer_data[9*i + 7];
    }


    this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data1, COLOR_GOLD, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 3*30, vertex_buffer_data, COLOR_WHITE, GL_FILL);
}

void BigMoney::draw(glm::mat4 VP) 
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
    draw3DObject(this->object1);

}

void BigMoney::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}


bounding_box_t BigMoney::def_bounding_box()
{
    bounding_box_t bb;
    bb.x = this->position.x;
    bb.y = this->position.y;
    bb.width = 0.2f;
    bb.height = 0.2f;
    return bb;
}

void BigMoney::jump()
{
    float v = 5;
    v = v - (10)*((float)1/(float)60); // v = u - at;
    float dis = v * ((float)1/(float)60) - 5 * ((float)1/(float)60) * ((float)1/(float)60); // s = ut - 1/2 at^2;
    if (this->jumpTime == 80)
    {
        this->jumpStatus = 0;
        this->jumpTime = 0;
    }
    else
    {
        this->jumpStatus = 1;
        this->position.y += dis;
        this->position.x += dis;
        this->jumpTime += 1;
    }
}

void BigMoney::gravityEffect()
{
      float v= 0;
      v = v  + (10)*((float)1/(float)60); // v = u + at;
      float dis = v * ((float)1/(float)60) + 5 * ((float)1/(float)60) * ((float)1/(float)60); // s = ut + 1/2 at^2;
      dis *= 10; //for speed's sake
      if (this->position.y > -3.2 )
      {
        this->position.y -= dis;
        this->position.x += dis;
      }
      else if (this->jumpStatus == 0)
        this->position.y = -90;
}

void BigMoney::tick() 
{
    if (this->jumpStatus == 0)
    {
      // printf("fallin\n");
        this->gravityEffect();
    }
    else
    {
        // printf("jumping\n");
        this->jump();
    }
}


Zoomer::Zoomer(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed = 0.4;

    this->jumpStatus = 1;
    this->jumpTime = 0;

    bounding_box_t bb;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float initx = 0.15f, inity = 0.15f;
    const int n = 15;

    static  GLfloat vertex_buffer_data1[9*n];

   for (int i=0; i<n; i++) 
   {
      vertex_buffer_data1[9*i] = 0.0f;
       vertex_buffer_data1[9*i + 1] = 0.0f;
        vertex_buffer_data1[9*i + 2] = 0.0f;
         vertex_buffer_data1[9*i + 3] = initx;
          vertex_buffer_data1[9*i + 4] = inity;
           vertex_buffer_data1[9*i + 5] = 0.0f;
            vertex_buffer_data1[9*i + 6] = initx*cos(2*3.14159/n) - inity*sin(2*3.14159/n);
             vertex_buffer_data1[9*i + 7] = initx*sin(2*3.14159/n) + inity*cos(2*3.14159/n);
              vertex_buffer_data1[9*i + 8] = 0.0f;

              initx = vertex_buffer_data1[9*i + 6];
              inity = vertex_buffer_data1[9*i + 7];
    }

   static  GLfloat vertex_buffer_data[] = {
          0.0f, 0.0f, 0.1f,
          0.12f, 0.0f, 0.1f,
          0.06f, -0.6f, 0.1f,
          0.0f, 0.0f, 0.1f,
          -0.12f, 0.0f, 0.1f,
          -0.06f, 0.6f, 0.1f,
   };


    this->object = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, COLOR_BLUE, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 9*n, vertex_buffer_data1, COLOR_WHITE, GL_FILL);

}

void Zoomer::draw(glm::mat4 VP) 
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
    draw3DObject(this->object1);

}

void Zoomer::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}


bounding_box_t Zoomer::def_bounding_box()
{
    bounding_box_t bb;
    bb.x = this->position.x;
    bb.y = this->position.y;
    bb.width = 0.2f;
    bb.height = 0.2f;
    return bb;
}

void Zoomer::jump()
{
    float v =5;
    v = v - (10)*((float)1/(float)60); // v = u - at;
    float dis = v * ((float)1/(float)60) - 5 * ((float)1/(float)60) * ((float)1/(float)60); // s = ut - 1/2 at^2;
    if (this->jumpTime == 80)
    {
        this->jumpStatus = 0;
        this->jumpTime = 0;
    }
    else
    {
        this->jumpStatus = 1;
        this->position.y += dis;
        this->position.x += dis;
        this->jumpTime += 1;
    }
}

void Zoomer::gravityEffect()
{
      float v= 0;
      v = v  + (10)*((float)1/(float)60); // v = u + at;
      float dis = v * ((float)1/(float)60) + 5 * ((float)1/(float)60) * ((float)1/(float)60); // s = ut + 1/2 at^2;
      dis *= 10; //for speed's sake
      if (this->position.y > -3.2 )
      {
        this->position.y -= dis;
        this->position.x += dis;
      }
      else if (this->jumpStatus == 0)
        this->position.y = -90;
}

void Zoomer::tick() 
{
    if (this->jumpStatus == 0)
    {
      // printf("fallin\n");
        this->gravityEffect();
    }
    else
    {
        // printf("jumping\n");
        this->jump();
    }
}

Shield::Shield(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed = 0.4;
    this->active = 0;
    this->jumpStatus = 1;
    this->jumpTime = 0;

    bounding_box_t bb;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    static  GLfloat vertex_buffer_data1[] = {
        -0.5f, 0.3f, 1.0f,
        -0.5f, -0.3f, 1.0f,
        0.5f, -0.3f, 1.0f,

        -0.5f, 0.3f, 1.0f,
        0.5f, 0.3f, 1.0f,
        0.5f, -0.3f, 1.0f,  

        -0.5f, -0.3f, 1.0f,
        0.5f, -0.3f, 1.0f,
        0.0f, -0.7f, 1.0f,
    };

    this->object1 = create3DObject(GL_TRIANGLES, 3*3, vertex_buffer_data1, COLOR_STEEL, GL_FILL);

}

void Shield::draw(glm::mat4 VP) 
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
}

void Shield::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}


bounding_box_t Shield::def_bounding_box()
{
    bounding_box_t bb;
    bb.x = this->position.x;
    bb.y = this->position.y;
    bb.width = 0.2f;
    bb.height = 0.2f;
    return bb;
}

void Shield::jump()
{
    float v =5;
    v = v - (10)*((float)1/(float)60); // v = u - at;
    float dis = v * ((float)1/(float)60) - 5 * ((float)1/(float)60) * ((float)1/(float)60); // s = ut - 1/2 at^2;
    if (this->jumpTime == 80)
    {
        this->jumpStatus = 0;
        this->jumpTime = 0;
    }
    else
    {
        this->jumpStatus = 1;
        this->position.y += dis;
        this->position.x += dis;
        this->jumpTime += 1;
    }
}

void Shield::gravityEffect()
{
      float v= 0;
      v = v  + (10)*((float)1/(float)60); // v = u + at;
      float dis = v * ((float)1/(float)60) + 5 * ((float)1/(float)60) * ((float)1/(float)60); // s = ut + 1/2 at^2;
      dis *= 10; //for speed's sake
      if (this->position.y > -3.2 )
      {
        this->position.y -= dis;
        this->position.x += dis;
      }
      else if (this->jumpStatus == 0)
        this->position.y = -90;
}

void Shield::tick() 
{
    if (this->jumpStatus == 0)
    {
      // printf("fallin\n");
        this->gravityEffect();
    }
    else
    {
        // printf("jumping\n");
        this->jump();
    }
}

