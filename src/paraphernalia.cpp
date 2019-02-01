#include "paraphernalia.h"
#include "main.h"

LevelText::LevelText(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*6 vertices

    static const GLfloat vertex_buffer_data[] = {
    	//L
        0.0f, 0.0f, 0.2f,
        0.0f, 0.4f, 0.2f,
        0.05f, 0.0f, 0.2f,

        0.0f, 0.4f, 0.2f,
        0.05f, 0.0f, 0.2f,
        0.05f, 0.4f, 0.2f,

        0.05f, 0.05f, 0.2f,
        0.05f, 0.0f, 0.2f,
        0.35f, 0.0f, 0.2f,

		0.05f, 0.05f, 0.2f,
        0.35f, 0.0f, 0.2f, 
        0.35f, 0.05f, 0.2f,

        //E

        0.4f, 0.0f, 0.2f,
        0.4f, 0.4f, 0.2f,
        0.45f, 0.0f, 0.2f,

        0.4f, 0.4f, 0.2f,
        0.45f, 0.0f, 0.2f,
        0.45f, 0.4f, 0.2f,

        0.45f, 0.05f, 0.2f,
        0.45f, 0.0f, 0.2f,
        0.75f, 0.0f, 0.2f,

		0.45f, 0.05f, 0.2f,
        0.75f, 0.0f, 0.2f, 
        0.75f, 0.05f, 0.2f,

        0.45f, 0.25f, 0.2f,
        0.45f, 0.2f, 0.2f,
        0.75f, 0.2f, 0.2f,

		0.45f, 0.25f, 0.2f,
        0.75f, 0.2f, 0.2f, 
        0.75f, 0.25f, 0.2f,

        0.45f, 0.4f, 0.2f,
        0.45f, 0.35f, 0.2f,
        0.75f, 0.35f, 0.2f,

		0.45f, 0.4f, 0.2f,
        0.75f, 0.35f, 0.2f, 
        0.75f, 0.4f, 0.2f,

        //V

        0.80f, 0.4f, 0.2f,
        0.85f, 0.4f, 0.2f,
        0.95f, 0.0f, 0.2f,

        0.80f, 0.4f, 0.2f,
        0.85f, 0.4f, 0.2f,
        0.90f, 0.0f, 0.2f,

        1.00f, 0.4f, 0.2f,
        1.05f, 0.4f, 0.2f,
        0.95f, 0.0f, 0.2f,

        1.00f, 0.4f, 0.2f,
        1.05f, 0.4f, 0.2f,
        0.90f, 0.0f, 0.2f,


    };

    static const GLfloat vertex_buffer_data1[] = {
        1.30f, 0.0f, 0.2f,
        1.30f, 0.4f, 0.2f,
        1.35f, 0.0f, 0.2f,

        1.30f, 0.4f, 0.2f,
        1.35f, 0.0f, 0.2f,
        1.35f, 0.4f, 0.2f,
    };

    static const GLfloat vertex_buffer_data2[] = {
        1.30f, 0.25f, 0.2f,
        1.30f, 0.0f, 0.2f,
        1.35f, 0.25f, 0.2f,

        1.30f, 0.0f, 0.2f,
        1.35f, 0.25f, 0.2f,
        1.35f, 0.0f, 0.2f,

        1.6f, 0.2f, 0.2f,
        1.6f, 0.4f, 0.2f,
        1.65f, 0.2f, 0.2f,

        1.6f, 0.4f, 0.2f,
        1.65f, 0.2f, 0.2f,
        1.65f, 0.4f, 0.2f,

        1.35f, 0.05f, 0.2f,
        1.35f, 0.0f, 0.2f,
        1.65f, 0.0f, 0.2f,

        1.35f, 0.05f, 0.2f,
        1.65f, 0.0f, 0.2f, 
        1.65f, 0.05f, 0.2f,

        1.35f, 0.25f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.65f, 0.2f, 0.2f,

        1.35f, 0.25f, 0.2f,
        1.65f, 0.2f, 0.2f, 
        1.65f, 0.25f, 0.2f,

        1.3f, 0.4f, 0.2f,
        1.3f, 0.35f, 0.2f,
        1.65f, 0.35f, 0.2f,

        1.3f, 0.4f, 0.2f,
        1.65f, 0.35f, 0.2f, 
        1.65f, 0.4f, 0.2f,


    };

    static const GLfloat vertex_buffer_data3[] = {

        1.6f, 0.4f, 0.2f,
        1.6f, 0.0f, 0.2f,
        1.65f, 0.4f, 0.2f,

        1.6f, 0.0f, 0.2f,
        1.65f, 0.4f, 0.2f,
        1.65f, 0.0f, 0.2f,

        1.35f, 0.05f, 0.2f,
        1.35f, 0.0f, 0.2f,
        1.65f, 0.0f, 0.2f,

        1.35f, 0.05f, 0.2f,
        1.65f, 0.0f, 0.2f, 
        1.65f, 0.05f, 0.2f,

        1.35f, 0.25f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.65f, 0.2f, 0.2f,

        1.35f, 0.25f, 0.2f,
        1.65f, 0.2f, 0.2f, 
        1.65f, 0.25f, 0.2f,

        1.35f, 0.4f, 0.2f,
        1.35f, 0.35f, 0.2f,
        1.65f, 0.35f, 0.2f,

        1.35f, 0.4f, 0.2f,
        1.65f, 0.35f, 0.2f, 
        1.65f, 0.4f, 0.2f,

    };

    this->object = create3DObject(GL_TRIANGLES, 16*3, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data1, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 10*3, vertex_buffer_data2, color, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 8*3, vertex_buffer_data3, color, GL_FILL);

}

void LevelText::draw(glm::mat4 VP, int i) 
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
    if (i == 1) draw3DObject(this->object1);
    else if (i == 2) draw3DObject(this->object2);
    else if (i == 3) draw3DObject(this->object3);

}

void LevelText::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}


ScoreBoard::ScoreBoard(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*6 vertices
    static const GLfloat vertex_buffer_data0[] = {
        1.30f, 0.0f, 0.2f,
        1.30f, 0.4f, 0.2f,
        1.35f, 0.0f, 0.2f,

        1.30f, 0.4f, 0.2f,
        1.35f, 0.0f, 0.2f,
        1.35f, 0.4f, 0.2f, 

        //side right top bar
        1.6f, 0.2f, 0.2f,
        1.6f, 0.4f, 0.2f,
        1.65f, 0.2f, 0.2f,

        1.6f, 0.4f, 0.2f,
        1.65f, 0.2f, 0.2f,
        1.65f, 0.4f, 0.2f,

        //side right bottom bar
        1.6f, 0.0f, 0.2f,
        1.6f, 0.25f, 0.2f,
        1.65f, 0.0f, 0.2f,

        1.6f, 0.25f, 0.2f,
        1.65f, 0.0f, 0.2f,
        1.65f, 0.25f, 0.2f,

        //bars top and bottom
        1.35f, 0.05f, 0.2f,
        1.35f, 0.0f, 0.2f,
        1.65f, 0.0f, 0.2f,

        1.35f, 0.05f, 0.2f,
        1.65f, 0.0f, 0.2f, 
        1.65f, 0.05f, 0.2f,

        1.3f, 0.4f, 0.2f,
        1.3f, 0.35f, 0.2f,
        1.65f, 0.35f, 0.2f,

        1.3f, 0.4f, 0.2f,
        1.65f, 0.35f, 0.2f, 
        1.65f, 0.4f, 0.2f,
    };

    static const GLfloat vertex_buffer_data1[] = {
        1.30f, 0.0f, 0.2f,
        1.30f, 0.4f, 0.2f,
        1.35f, 0.0f, 0.2f,

        1.30f, 0.4f, 0.2f,
        1.35f, 0.0f, 0.2f,
        1.35f, 0.4f, 0.2f,
    };

    static const GLfloat vertex_buffer_data2[] = {
        //side left bottom bar
        1.30f, 0.25f, 0.2f,
        1.30f, 0.0f, 0.2f,
        1.35f, 0.25f, 0.2f,

        1.30f, 0.0f, 0.2f,
        1.35f, 0.25f, 0.2f,
        1.35f, 0.0f, 0.2f,

        //others

        1.6f, 0.2f, 0.2f,
        1.6f, 0.4f, 0.2f,
        1.65f, 0.2f, 0.2f,

        1.6f, 0.4f, 0.2f,
        1.65f, 0.2f, 0.2f,
        1.65f, 0.4f, 0.2f,

        1.35f, 0.05f, 0.2f,
        1.35f, 0.0f, 0.2f,
        1.65f, 0.0f, 0.2f,

        1.35f, 0.05f, 0.2f,
        1.65f, 0.0f, 0.2f, 
        1.65f, 0.05f, 0.2f,

        1.35f, 0.25f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.65f, 0.2f, 0.2f,

        1.35f, 0.25f, 0.2f,
        1.65f, 0.2f, 0.2f, 
        1.65f, 0.25f, 0.2f,

        1.3f, 0.4f, 0.2f,
        1.3f, 0.35f, 0.2f,
        1.65f, 0.35f, 0.2f,

        1.3f, 0.4f, 0.2f,
        1.65f, 0.35f, 0.2f, 
        1.65f, 0.4f, 0.2f,

    };

    static const GLfloat vertex_buffer_data3[] = {

        //side right bar full length
        1.6f, 0.4f, 0.2f,
        1.6f, 0.0f, 0.2f,
        1.65f, 0.4f, 0.2f,

        1.6f, 0.0f, 0.2f,
        1.65f, 0.4f, 0.2f,
        1.65f, 0.0f, 0.2f,

        //bottom bar
        1.35f, 0.05f, 0.2f,
        1.35f, 0.0f, 0.2f,
        1.65f, 0.0f, 0.2f,

        1.35f, 0.05f, 0.2f,
        1.65f, 0.0f, 0.2f, 
        1.65f, 0.05f, 0.2f,

        //middle bar
        1.35f, 0.25f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.65f, 0.2f, 0.2f,

        1.35f, 0.25f, 0.2f,
        1.65f, 0.2f, 0.2f, 
        1.65f, 0.25f, 0.2f,

        //top bar
        1.35f, 0.4f, 0.2f,
        1.35f, 0.35f, 0.2f,
        1.65f, 0.35f, 0.2f,

        1.35f, 0.4f, 0.2f,
        1.65f, 0.35f, 0.2f, 
        1.65f, 0.4f, 0.2f,

    };

    static const GLfloat vertex_buffer_data4[] = {

        //side right bar full length
        1.6f, 0.4f, 0.2f,
        1.6f, 0.0f, 0.2f,
        1.65f, 0.4f, 0.2f,

        1.6f, 0.0f, 0.2f,
        1.65f, 0.4f, 0.2f,
        1.65f, 0.0f, 0.2f,

        //middle bar
        1.35f, 0.25f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.65f, 0.2f, 0.2f,

        1.35f, 0.25f, 0.2f,
        1.65f, 0.2f, 0.2f, 
        1.65f, 0.25f, 0.2f,

        //side left top bar
        1.30f, 0.2f, 0.2f,
        1.30f, 0.4f, 0.2f,
        1.35f, 0.2f, 0.2f,

        1.30f, 0.4f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.35f, 0.4f, 0.2f,

    };

    static const GLfloat vertex_buffer_data5[] = {

        //bottom bar
        1.35f, 0.05f, 0.2f,
        1.35f, 0.0f, 0.2f,
        1.65f, 0.0f, 0.2f,

        1.35f, 0.05f, 0.2f,
        1.65f, 0.0f, 0.2f, 
        1.65f, 0.05f, 0.2f,

        //top bar
        1.35f, 0.4f, 0.2f,
        1.35f, 0.35f, 0.2f,
        1.65f, 0.35f, 0.2f,

        1.35f, 0.4f, 0.2f,
        1.65f, 0.35f, 0.2f, 
        1.65f, 0.4f, 0.2f,

        //middle bar
        1.35f, 0.25f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.65f, 0.2f, 0.2f,

        1.35f, 0.25f, 0.2f,
        1.65f, 0.2f, 0.2f, 
        1.65f, 0.25f, 0.2f,

        //side left top bar
        1.30f, 0.2f, 0.2f,
        1.30f, 0.4f, 0.2f,
        1.35f, 0.2f, 0.2f,

        1.30f, 0.4f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.35f, 0.4f, 0.2f,

        //side right bottom bar
        1.6f, 0.0f, 0.2f,
        1.6f, 0.25f, 0.2f,
        1.65f, 0.0f, 0.2f,

        1.6f, 0.25f, 0.2f,
        1.65f, 0.0f, 0.2f,
        1.65f, 0.25f, 0.2f,
    };

    static const GLfloat vertex_buffer_data6[] = {

        //bottom bar
        1.35f, 0.05f, 0.2f,
        1.35f, 0.0f, 0.2f,
        1.65f, 0.0f, 0.2f,

        1.35f, 0.05f, 0.2f,
        1.65f, 0.0f, 0.2f, 
        1.65f, 0.05f, 0.2f,

        //top bar
        1.35f, 0.4f, 0.2f,
        1.35f, 0.35f, 0.2f,
        1.65f, 0.35f, 0.2f,

        1.35f, 0.4f, 0.2f,
        1.65f, 0.35f, 0.2f, 
        1.65f, 0.4f, 0.2f,

        //middle bar
        1.35f, 0.25f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.65f, 0.2f, 0.2f,

        1.35f, 0.25f, 0.2f,
        1.65f, 0.2f, 0.2f, 
        1.65f, 0.25f, 0.2f,

        //side left top bar
        1.30f, 0.2f, 0.2f,
        1.30f, 0.4f, 0.2f,
        1.35f, 0.2f, 0.2f,

        1.30f, 0.4f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.35f, 0.4f, 0.2f,

        //side right bottom bar
        1.6f, 0.0f, 0.2f,
        1.6f, 0.25f, 0.2f,
        1.65f, 0.0f, 0.2f,

        1.6f, 0.25f, 0.2f,
        1.65f, 0.0f, 0.2f,
        1.65f, 0.25f, 0.2f,

        //side left bottom bar
        1.30f, 0.25f, 0.2f,
        1.30f, 0.0f, 0.2f,
        1.35f, 0.25f, 0.2f,

        1.30f, 0.0f, 0.2f,
        1.35f, 0.25f, 0.2f,
        1.35f, 0.0f, 0.2f,
    };

    static const GLfloat vertex_buffer_data7[] = {

        //side right bar full length
        1.6f, 0.4f, 0.2f,
        1.6f, 0.0f, 0.2f,
        1.65f, 0.4f, 0.2f,

        1.6f, 0.0f, 0.2f,
        1.65f, 0.4f, 0.2f,
        1.65f, 0.0f, 0.2f,

        //top bar
        1.35f, 0.4f, 0.2f,
        1.35f, 0.35f, 0.2f,
        1.65f, 0.35f, 0.2f,

        1.35f, 0.4f, 0.2f,
        1.65f, 0.35f, 0.2f, 
        1.65f, 0.4f, 0.2f,
    };


    static const GLfloat vertex_buffer_data8[] = {

        //side right bar full length
        1.6f, 0.4f, 0.2f,
        1.6f, 0.0f, 0.2f,
        1.65f, 0.4f, 0.2f,

        1.6f, 0.0f, 0.2f,
        1.65f, 0.4f, 0.2f,
        1.65f, 0.0f, 0.2f,

        //bottom bar
        1.35f, 0.05f, 0.2f,
        1.35f, 0.0f, 0.2f,
        1.65f, 0.0f, 0.2f,

        1.35f, 0.05f, 0.2f,
        1.65f, 0.0f, 0.2f, 
        1.65f, 0.05f, 0.2f,

        //middle bar
        1.35f, 0.25f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.65f, 0.2f, 0.2f,

        1.35f, 0.25f, 0.2f,
        1.65f, 0.2f, 0.2f, 
        1.65f, 0.25f, 0.2f,

        //top bar
        1.35f, 0.4f, 0.2f,
        1.35f, 0.35f, 0.2f,
        1.65f, 0.35f, 0.2f,

        1.35f, 0.4f, 0.2f,
        1.65f, 0.35f, 0.2f, 
        1.65f, 0.4f, 0.2f,

        //side left top bar
        1.30f, 0.2f, 0.2f,
        1.30f, 0.4f, 0.2f,
        1.35f, 0.2f, 0.2f,

        1.30f, 0.4f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.35f, 0.4f, 0.2f,

        //side left bottom bar
        1.30f, 0.25f, 0.2f,
        1.30f, 0.0f, 0.2f,
        1.35f, 0.25f, 0.2f,

        1.30f, 0.0f, 0.2f,
        1.35f, 0.25f, 0.2f,
        1.35f, 0.0f, 0.2f,
    };


    static const GLfloat vertex_buffer_data9[] = {

        //side right bar full length
        1.6f, 0.4f, 0.2f,
        1.6f, 0.0f, 0.2f,
        1.65f, 0.4f, 0.2f,

        1.6f, 0.0f, 0.2f,
        1.65f, 0.4f, 0.2f,
        1.65f, 0.0f, 0.2f,

        //bottom bar
        1.35f, 0.05f, 0.2f,
        1.35f, 0.0f, 0.2f,
        1.65f, 0.0f, 0.2f,

        1.35f, 0.05f, 0.2f,
        1.65f, 0.0f, 0.2f, 
        1.65f, 0.05f, 0.2f,

        //middle bar
        1.35f, 0.25f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.65f, 0.2f, 0.2f,

        1.35f, 0.25f, 0.2f,
        1.65f, 0.2f, 0.2f, 
        1.65f, 0.25f, 0.2f,

        //top bar
        1.35f, 0.4f, 0.2f,
        1.35f, 0.35f, 0.2f,
        1.65f, 0.35f, 0.2f,

        1.35f, 0.4f, 0.2f,
        1.65f, 0.35f, 0.2f, 
        1.65f, 0.4f, 0.2f,

        //side left top bar
        1.30f, 0.2f, 0.2f,
        1.30f, 0.4f, 0.2f,
        1.35f, 0.2f, 0.2f,

        1.30f, 0.4f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.35f, 0.4f, 0.2f,
    };


    static const GLfloat vertex_buffer_dataneg[] = {

        //middle bar
        1.35f, 0.25f, 0.2f,
        1.35f, 0.2f, 0.2f,
        1.65f, 0.2f, 0.2f,

        1.35f, 0.25f, 0.2f,
        1.65f, 0.2f, 0.2f, 
        1.65f, 0.25f, 0.2f,
    };

    this->object0 = create3DObject(GL_TRIANGLES, 10*3, vertex_buffer_data0, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data1, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 10*3, vertex_buffer_data2, color, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 8*3, vertex_buffer_data3, color, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 6*3, vertex_buffer_data4, color, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 10*3, vertex_buffer_data5, color, GL_FILL);
    this->object6 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data6, color, GL_FILL);
    this->object7 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data7, color, GL_FILL);
    this->object8 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data8, color, GL_FILL);
    this->object9 = create3DObject(GL_TRIANGLES, 10*3, vertex_buffer_data9, color, GL_FILL);
    this->objectneg = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_dataneg, color, GL_FILL);

}

void ScoreBoard::draw(glm::mat4 VP, int i) 
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

    if (i == 1) draw3DObject(this->object1);
    else if (i == 2) draw3DObject(this->object2);
    else if (i == 3) draw3DObject(this->object3);
    else if (i == 4) draw3DObject(this->object4);
    else if (i == 5) draw3DObject(this->object5);
    else if (i == 6) draw3DObject(this->object6);
    else if (i == 7) draw3DObject(this->object7);
    else if (i == 8) draw3DObject(this->object8);
    else if (i == 9) draw3DObject(this->object9);
    else if (i == 0) draw3DObject(this->object0);
    else if (i == -1) draw3DObject(this->objectneg);

}

void ScoreBoard::set_position(float x, float y) 
{
    this->position = glm::vec3(x, y, 0);
}

