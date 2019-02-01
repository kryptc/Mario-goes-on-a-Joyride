#include "ball.h"
#include "main.h"

Ball::Ball(float x, float y, color_t color) 
{
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed = 0.3;
    this->velocity = 0;
    this->rightFlag = 0;

    this->jumpStatus = 0;
    this->jumpTime = 0;
    this->override = 0;

    // float u = 0.2, time = 3.0;
    // float horizontal_dist = u*time, vertical_dist = (u/2.0) * time;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data1[] = {
        -0.25f,-0.25f,0.0f, // jetpack : begin
        -0.25f, 0.25f, 0.0f,
        0.0f, 0.25f, 0.0f, // triangle 1 : end

        -0.25f, -0.25f, 0.0f, // jetpack : begin
        0.0f, -0.25f, 0.0f,  
        0.0f, 0.25f, 0.0f,
    };

    static const GLfloat vertex_buffer_data2[] = {

        0.0f, 0.0f,0.0f, // triangle 1 : begin
        0.0f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f, // triangle 1 : end
    };

    static const GLfloat vertex_buffer_data3[] = {

        0.5f, 0.5f, 0.0f, // triangle 2 : begin
        0.5f, 0.0f, 0.0f,  
        0.0f, 0.0f, 0.0f,
    };
    static const GLfloat vertex_buffer_data4[] = {

        0.0f, 0.0f,0.0f, // triangle 1 : begin
        0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, // triangle 1 : end

        0.0f, 0.0f, 0.0f, // triangle 2 : begin
        0.0f, -0.5f, 0.0f,  
        0.5f, -0.5f, 0.0f,
    };
    const int n = 200;
    static GLfloat vertex_buffer_data5[9*n];
    float initx = 0.035f, inity = 0.035f;
     for (int i=0; i<n; i++) 
     {
        vertex_buffer_data5[9*i] = 0.0f;
         vertex_buffer_data5[9*i + 1] = 0.0f;
          vertex_buffer_data5[9*i + 2] = 0.1f;
           vertex_buffer_data5[9*i + 3] = initx;
            vertex_buffer_data5[9*i + 4] = inity;
             vertex_buffer_data5[9*i + 5] = 0.1f;
              vertex_buffer_data5[9*i + 6] = initx*cos(2*3.14159/n) - inity*sin(2*3.14159/n);
               vertex_buffer_data5[9*i + 7] = initx*sin(2*3.14159/n) + inity*cos(2*3.14159/n);
                vertex_buffer_data5[9*i + 8] = 0.1f;

                initx = vertex_buffer_data5[9*i + 6];
                inity = vertex_buffer_data5[9*i + 7];
      }
      static const GLfloat vertex_buffer_data6[] = {

        -0.17f, -0.25f, 0.0f, // triangle 1 : begin
        -0.20f, -0.50f, 0.0f,
        -0.14f, -0.50f, 0.0f, // triangle 1 : end
        -0.08f, -0.25f, 0.0f, // triangle 2 : begin
        -0.11f, -0.50f, 0.0f,  
        -0.05f, -0.50f, 0.0f,
    };


    this->object = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data1, COLOR_STEEL, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_data2, COLOR_BLACK, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_data3, COLOR_FLESH, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data4, COLOR_GREEN, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data5, COLOR_BLACK, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data6, COLOR_ORANGE, GL_FILL);

}

void Ball::draw(glm::mat4 VP) 
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
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    // draw3DObject(this->object4);
    draw3DObject(this->object5);

}

void Ball::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}

void Ball::jump()
{
  // // float vertical_vel = vertical_dist/3.0;
  // float vertical_vel = 0.1;
  // float horizontal_vel = 0.1;

  // // float horizontal_vel = horizontal_dist/3.0;
    float v = 5;
    v = v - (10)*((float)1/(float)60); // v = u - at;
    float dis = v * ((float)1/(float)60) - 5 * ((float)1/(float)60) * ((float)1/(float)60); // s = ut - 1/2 at^2;
    if (this->jumpTime == 3)
    {
        this->jumpStatus = 0;
        this->jumpTime = 0;
    }
    else
    {
        this->jumpStatus = 1;
        // this->position.y += dis;
        // this->position.x += dis;
        this->position.y += 0.3;
        this->jumpTime += 1;
    }
    // this->velocity = dis;

}

void Ball::gravityEffect()
{
  // float horizontal_vel = horizontal_dist/3.0;
      float v= 0;
      v = v  + (10)*((float)1/(float)60); // v = u + at;
      float dis = v * ((float)1/(float)60) + 5 * ((float)1/(float)60) * ((float)1/(float)60); // s = ut + 1/2 at^2;
      dis *= 15; //for speed's sake
      this->velocity = dis;
      if (this->position.y > -2.95 )
      {
        this->position.y -= 0.1;
        if (this->rightFlag == 1)
        {
          this->position.x += this->velocity;  
        }
        else if (rightFlag == -1)
        {
          this->position.x -= this->velocity;
        }
      }
      else
        this->rightFlag = 0;

}

bounding_box_t Ball::def_bounding_box()
{
    bounding_box_t bb;
    bb.x = this->position.x;
    bb.y = this->position.y;
    bb.width = 1.0f;
    bb.height = 1.0f;
    return bb;
}

void Ball::tick() 
{
  if (this->override) 
    this->position.x += 0.5;
  else
  {
    if (this->jumpStatus == 0)
        this->gravityEffect();
    else
        this->jump();
  }
}
