#include "enemies.h"
#include "main.h"

FireLine::FireLine(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = rand()/180;

    bounding_box_t bb;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*6 vertices

    static const GLfloat vertex_buffer_data[] = {
        0.0f, 0.0f, 0.0f, // triangle 1 : begin
        0.10f, 0.30f, 0.0f,
        0.10f, 0.0f, 0.0f, // triangle 1 : end
        0.0f, 0.0f, 0.0f, // triangle 1 : end
        0.0f, 0.30f, 0.0f,
        0.10f, 0.30f, 0.0f,

        1.20f, 0.0f, 0.0f, // triangle 1 : begin
        1.30f, 0.30f, 0.0f,
        1.30f, 0.0f, 0.0f, // triangle 1 : end
        1.20f, 0.0f, 0.0f, // triangle 1 : end
        1.20f, 0.30f, 0.0f,
        1.30f, 0.30f, 0.0f,
    };

    static const GLfloat vertex_buffer_data1[] = {

        0.10f, 0.15f, 0.0f,
        0.15f, 0.0f, 0.0f,
        0.20f, 0.15f, 0.0f,

        0.20f, 0.15f, 0.0f,
        0.25f, 0.30f, 0.0f,
        0.30f, 0.15f, 0.0f,

        0.30f, 0.15f, 0.0f,
        0.35f, 0.0f, 0.0f,
        0.40f, 0.15f, 0.0f,


        0.40f, 0.15f, 0.0f,
        0.45f, 0.30f, 0.0f,
        0.50f, 0.15f, 0.0f,

        0.50f, 0.15f, 0.0f,
        0.55f, 0.0f, 0.0f,
        0.60f, 0.15f, 0.0f,

        0.60f, 0.15f, 0.0f,
        0.65f, 0.30f, 0.0f,
        0.70f, 0.15f, 0.0f,

        0.70f, 0.15f, 0.0f,
        0.75f, 0.0f, 0.0f,
        0.80f, 0.15f, 0.0f,

        0.80f, 0.15f, 0.0f,
        0.85f, 0.30f, 0.0f,
        0.90f, 0.15f, 0.0f,

        0.90f, 0.15f, 0.0f,
        0.95f, 0.0f, 0.0f,
        1.00f, 0.15f, 0.0f,

        1.00f, 0.15f, 0.0f,
        1.05f, 0.30f, 0.0f,
        1.10f, 0.15f, 0.0f,

        1.10f, 0.15f, 0.0f,
        1.15f, 0.0f, 0.0f,
        1.20f, 0.15f, 0.0f,
    };

    this->object = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data, COLOR_STEEL, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 11*3, vertex_buffer_data1, COLOR_ORANGE, GL_FILL);

}

void FireLine::draw(glm::mat4 VP) 
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);

}

void FireLine::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}


bounding_box_t FireLine::def_bounding_box()
{
    bounding_box_t bb;
    bb.x = this->position.x;
    bb.y = this->position.y;
    bb.width = 0.9f;
    bb.height = 0.2f;
    return bb;
}

void FireLine::tick() 
{
    this->position.y += this->speed;
}


LaserBeam::LaserBeam(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed = 0.05;
    this->down = 1;


    bounding_box_t bb;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*6 vertices

    static const GLfloat vertex_buffer_data[] = {
        -3.0f, 0.0f, 0.0f, // triangle 1 : begin
        -3.10f, 0.30f, 0.0f,
        -3.10f, 0.0f, 0.0f, // triangle 1 : end
        -3.0f, 0.0f, 0.0f, // triangle 1 : end
        -3.0f, 0.30f, 0.0f,
        -3.10f, 0.30f, 0.0f,

        4.20f, 0.0f, 0.0f, // triangle 1 : begin
        4.30f, 0.30f, 0.0f,
        4.30f, 0.0f, 0.0f, // triangle 1 : end
        4.20f, 0.0f, 0.0f, // triangle 1 : end
        4.20f, 0.30f, 0.0f,
        4.30f, 0.30f, 0.0f,
    };

    static const GLfloat vertex_buffer_data1[] = {

        -3.10f, 0.10f, 0.0f,
        4.20f, 0.20f, 0.0f,
        -3.10f, 0.20f, 0.0f,

        4.20f, 0.20f, 0.0f,
        4.20f, 0.10f, 0.0f,
        -3.10f, 0.10f, 0.0f,

    };

    this->object = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data, COLOR_STEEL, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data1, COLOR_RED, GL_FILL);

}

void LaserBeam::draw(glm::mat4 VP) 
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

void LaserBeam::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}


bounding_box_t LaserBeam::def_bounding_box()
{
    bounding_box_t bb;
    bb.x = this->position.x;
    bb.y = this->position.y;
    bb.width = 7.10f;
    bb.height = 0.10f;
    return bb;
}


void LaserBeam::tick() 
{
  if (this->position.y > -2.3 && this->down == 1)
    this->position.y -= this->speed;
  else 
    this->down = 0;

  if (this->position.y < 3 && this->down == 0)
    this->position.y += this->speed;
  else
    this->down = 1;
}


Boomerang::Boomerang(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed = 0.35;
    this->apex = 0;
    this->journeyTime = 400;

    bounding_box_t bb;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    static  GLfloat vertex_buffer_data1[] = {
        0.0f, 0.75f, 0.0f,
        0.0f, 0.35f, 0.0f,
        0.9f, 0.0f, 0.0f,

        0.0f, 0.75f, 0.0f,
        0.0f, 0.35f, 0.0f,
        -0.9f, 0.0f, 0.0f,
    };

    this->object = create3DObject(GL_TRIANGLES, 3*2, vertex_buffer_data1, COLOR_BROWN, GL_FILL);
}

void Boomerang::draw(glm::mat4 VP) 
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Boomerang::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}

bounding_box_t Boomerang::def_bounding_box()
{
    bounding_box_t bb;
    bb.x = this->position.x;
    bb.y = this->position.y;
    bb.width = 1.5f;
    bb.height = 0.75f;
    return bb;
}

void Boomerang::moveLeft()
{
  this->position.x -= 0.1;
  this->position.y -= 0.02;
  this->journeyTime--;
  if (this->journeyTime == 200) this->apex = 1;
}

void Boomerang::moveRight()
{
  this->position.x += 0.15;
  this->position.y -= 0.015;
  this->journeyTime--;
  if (this->journeyTime == -20) this->apex = -1;
}

void Boomerang::tick()
{
  this->rotation += 20%360;
  if (this->apex == 0)
    this->moveLeft();
  else if (this->apex == 1)
    this->moveRight();
  else
    this->set_position(this->position.x + 30, 4);
} 

Dragon::Dragon(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed = 0.2;
    this->ShootTime = 70;
    this->down = 0;
    this->dead = 0;

    bounding_box_t bb;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
  static GLfloat vertex_buffer_data1[] = {

          0.0f, 0.0f, 0.0f, // head
          -0.4f, 0.0f, 0.0f,
          0.0f, 0.2f, 0.0f,

          0.0f,0.0f,0.0f, //torso
          0.2f,-0.8f,0.0f,
          0.5f,-0.8f,0.0f,

          0.0f,-0.8f,0.0f, // hip
          0.5f,-0.8f,0.0f,
          0.5f,-1.1f,0.0f,

          0.0f,-1.0f,0.0f, // leg 1 
          0.2f,-1.0f,0.0f,
          0.1f,-0.9f,0.0f,

          0.2f,-1.1f,0.0f, // leg 2 
          0.35f,-1.1f,0.0f,
          0.3f,-1.0f,0.0f,

          0.5f,-0.8f,0.0f, //tail 
          0.5f,-1.1f,0.0f,
          1.5f, -1.5f,0.0f,
      } ;

      static GLfloat vertex_buffer_data2[] = {
          0.2f, -0.2f, 0.0f, // wing 1 
          1.2f, -0.2f, 0.0f,
          0.6f, 0.3f, 0.0f,

          0.2f, -0.2f, 0.0f, // wing 2
          0.6f, -0.4f, 0.0f,
          0.7f, -0.2f, 0.0f,

          1.45f,-1.45f, 0.0f, // tail tip
          1.5f, -1.5f, 0.0f,
          1.7f, -1.3f, 0.0f,

          -0.1f, 0.12f, 0.0f, //ear 1
          -0.03f, 0.20f, 0.0f,
          -0.03f, 0.28f, 0.0f,

          0.0f, 0.14f, 0.0f, //ear 2
          0.0f, 0.22f, 0.0f,
          0.1f, 0.3f, 0.0f,
      } ; 

      static GLfloat vertex_buffer_data3[] = {
          0.0f,0.0f,0.0f, // belly
          0.0f,-0.8f,0.0f,
          0.2f,-0.8f,0.0f, 
      } ;

    this->object1 = create3DObject(GL_TRIANGLES, 3*6, vertex_buffer_data1, COLOR_DARKBLUE, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 3*5, vertex_buffer_data2, COLOR_BLUE, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 3*1, vertex_buffer_data3, COLOR_TEAL, GL_FILL);

}

void Dragon::draw(glm::mat4 VP) 
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
}

void Dragon::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}

bounding_box_t Dragon::def_bounding_box()
{
    bounding_box_t bb;
    bb.x = this->position.x;
    bb.y = this->position.y;
    bb.width = 0.5f;
    bb.height = 1.0f;
    return bb;
}

void Dragon::tick(int dir)
{
  if (!this->dead)
  {
      this->down = dir;
      if (this->position.y > -2.3 && this->down == 1)
        this->position.y -= this->speed;
      // else 
      //   this->down = 0;

      else if (this->position.y < 3.3 && this->down == 0)
        this->position.y += this->speed;
      else
        this->down = 1;

      this->ShootTime--;
      if (this->ShootTime == 0)
        this->ShootTime = 60;
  }
  else
  {
    this->rotation = 90;
    this->position.y = -2.2;
  }

} 


Snowball::Snowball(float x, float y, color_t color) 
{
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed = 0.2;

    bounding_box_t bb;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float initx = 0.2f, inity = 0.0f;
    // float initx = 0.095f, inity = 0.095f;
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

    this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data1, color, GL_FILL);
}

void Snowball::draw(glm::mat4 VP) 
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
}

void Snowball::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}


bounding_box_t Snowball::def_bounding_box()
{
    bounding_box_t bb;
    bb.x = this->position.x;
    bb.y = this->position.y;
    bb.width = 0.35f;
    bb.height = 0.3f;
    return bb;
}

void Snowball::tick()
{
      float v= 0;
      v = v  + (10)*((float)1/(float)60); // v = u + at;
      float dis = v * ((float)1/(float)60) + 5 * ((float)1/(float)60) * ((float)1/(float)60); // s = ut + 1/2 at^2;
      dis *= 15; //for speed's sake
      if (this->position.y > -3.2 )
      {
        this->position.y -= dis;
        this->position.x -= dis + this->speed;
      }
} 



