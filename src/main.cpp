#include "main.h"
#include "timer.h"
#include "ball.h"
#include "waterballoon.h"
#include "background.h"
#include "coin.h"
#include "enemies.h"
#include "powerups.h"
#include "magnet.h"
#include "paraphernalia.h"
#include "ring.h"


using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* LEVEL 1 : SPARKY ENEMIES, LASER BOIS, COINS
  LEVEL 2 : ZOOM POWERUP, BIG MONEY POWERUP, CIRCULAR RING
  LEVEL 3 : MAGNETS, BOOMERANG, DRAGON

/**************************
* Map variables *
*************************/
Ball ball;
WaterBalloon waterballoon;
vector <WaterBalloon> wbarr;
Snowball snowball;
vector <Snowball> snowballarr;
bounding_box_t bb1, bb2, big1, big2, zo1, zo2, magbb;
bounding_box_t coin_bb[250], snow_bb[200];
bounding_box_t shieldbb, dragbb;


Floor floortiles;
Floor2 moretiles;
Coin goldcoins, greencoins, salmoncoins;
vector <Coin> coinarr;
FireLine fireline;
vector <FireLine> enemy1arr;
vector <LaserBeam> enemy2arr;
LaserBeam laser;
BigMoney biggie1, biggie2;
Zoomer zoom1, zoom2;
Magnet magnet;
Boomerang boomer;
Ring ring;
Dragon viserion;
Shield shield;

LevelText level;
int level1 = 1, level2 = 0, level3 = 0;
ScoreBoard UNITS, TENS, HUNDREDS, THOUSANDS, NEG;
int units = 0, tens = 0, hundreds = 0, thousands = 0;


int makeWaterBalloon = 0;
int score = 0;
int immunity = 0, timer = 0;
int magflag = 0, boomflag = 0, shieldflag = 0;
int ringflag = 0, goLeft = 0, goRight = 0;
int shieldtimer = 700;
int dragonlife = 50;

/**************************
* Customizable functions *
**************************/

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() 
{
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    glm::vec3 eye ( screen_center_x, 0, 20 );
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    // change if zoomed in or out, z axis should come closer/further
    glm::vec3 target (screen_center_x, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    level = LevelText(screen_center_x-3.5, 3.3, COLOR_WHITE);

    if (screen_center_x > 130)
        level3 = 1;
    else if (screen_center_x > 80)
        level2 = 1;

    if (level3)
        level.draw(VP, 3);
    else if (level2)
        level.draw(VP, 2);
    else
        level.draw(VP, 1);

    //calculating and drawing score
    int temp = score;
    if (temp < 0) 
    {
        temp *= -1;
        NEG = ScoreBoard(screen_center_x + 0.4, 3.3, COLOR_WHITE);
        NEG.draw(VP, -1);
    }
    units = temp%10;
    temp /= 10;
    tens = temp%10;
    temp /= 10;
    hundreds = temp%10;
    temp /= 10;
    thousands = temp%10;
    UNITS = ScoreBoard(screen_center_x + 2.0, 3.3, COLOR_WHITE);
    UNITS.draw(VP, units);
    TENS = ScoreBoard(screen_center_x + 1.6, 3.3, COLOR_WHITE);
    TENS.draw(VP, tens);
    HUNDREDS = ScoreBoard(screen_center_x + 1.2, 3.3, COLOR_WHITE);
    HUNDREDS.draw(VP, hundreds);
    THOUSANDS = ScoreBoard(screen_center_x + 0.8, 3.3, COLOR_WHITE);
    THOUSANDS.draw(VP, thousands);

    //drawing floor

        if (screen_center_x < 105)
        {
            floortiles = Floor(-5, -2, COLOR_OCEAN);
            moretiles = Floor2(-5, -2, COLOR_IVORY);
            floortiles.draw(VP);
            moretiles.draw(VP);
        }
        else if (screen_center_x < 205)
        {
            floortiles = Floor(100, -2, COLOR_OCEAN);
            moretiles = Floor2(100, -2, COLOR_IVORY);
            floortiles.draw(VP);
            moretiles.draw(VP);
        }
        else if (screen_center_x < 305)
        {
            floortiles = Floor(200, -2, COLOR_OCEAN);
            moretiles = Floor2(200, -2, COLOR_IVORY);
            floortiles.draw(VP);
            moretiles.draw(VP);
        }
        else if (screen_center_x < 405)
        {
            floortiles = Floor(300, -2, COLOR_OCEAN);
            moretiles = Floor2(300, -2, COLOR_IVORY);
            floortiles.draw(VP);
            moretiles.draw(VP);
        }
        else if (screen_center_x < 505)
        {
            floortiles = Floor(400, -2, COLOR_OCEAN);
            moretiles = Floor2(400, -2, COLOR_IVORY);
            floortiles.draw(VP);
            moretiles.draw(VP);
        }
        else if (screen_center_x < 605)
        {
            floortiles = Floor(500, -2, COLOR_OCEAN);
            moretiles = Floor2(500, -2, COLOR_IVORY);
            floortiles.draw(VP);
            moretiles.draw(VP);
        }
        
    ball.draw(VP);

    if (makeWaterBalloon % 80 == 3)
    {
        waterballoon = WaterBalloon(ball.position.x, ball.position.y+0.9, COLOR_BLUE);
        wbarr.push_back(waterballoon);
        makeWaterBalloon = 0;
    }
    for (int i = 0; i < wbarr.size(); ++i)
        wbarr[i].draw(VP);

    if (viserion.ShootTime == 60)
    {
        snowball = Snowball(viserion.position.x - 0.5, viserion.position.y, COLOR_WHITE);
        snowballarr.push_back(snowball);
    }

    for (int i = 0; i < snowballarr.size(); ++i)
        snowballarr[i].draw(VP);

    for (int i = 0; i < coinarr.size(); ++i)
        coinarr[i].draw(VP);

    for (int i = 0; i < enemy1arr.size(); ++i)
        enemy1arr[i].draw(VP);

    for (int i = 0; i < enemy2arr.size(); ++i)
        enemy2arr[i].draw(VP);

    if (screen_center_x > 52) biggie1.draw(VP);
    if (screen_center_x > 132) biggie2.draw(VP);
    if (screen_center_x > 32) zoom1.draw(VP);
    if (screen_center_x > 82) zoom2.draw(VP);

    if (screen_center_x + 1 > shield.position.x)
        shield.draw(VP);
    if (shield.active) shield.draw(VP);

    if (screen_center_x > magnet.position.x)
    {
        magflag = 1;
        magnet.draw(VP);
    }
    if (magflag) 
        magnet.draw(VP);

    // ring.draw(VP);
    ring.draw(VP);


    if (screen_center_x + 10 > boomer.position.x) 
        boomer.draw(VP);

    viserion.draw(VP);
}

void tick_input(GLFWwindow *window) 
{
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_SPACE);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int toss  = glfwGetKey(window, GLFW_KEY_W);

    if (right) 
    {
        if (ball.position.x < viserion.position.x)
        {
            ball.position.x += ball.speed;
            ball.rightFlag = 1;
        }

    }
    if (left)
    {
        if (ball.position.x > -3.3)
            ball.position.x -= ball.speed;
        ball.rightFlag = -1;
    }
    if (up && !ringflag) 
    {
        if (ball.position.y < 3 )
            // if (ball.jumpStatus != 1)
                ball.jump();
        else if (ball.position.y > 3.1)
        {
            ball.position.y = 3.1;
            ball.position.x += ball.speed;
        }
        ball.rightFlag = 0;

    }
    if (down && !ringflag) 
    {
        if (ball.position.y > -2.75 )
            ball.position.y -= ball.speed;
        ball.rightFlag = 0;
    }
    if (toss)
    {
        makeWaterBalloon += 1;
    }
}

void tick_elements() 
{
    ball.tick();
    bb1 = ball.def_bounding_box();


    if (screen_center_x + 10 > boomer.position.x) boomflag = 1;
    if (boomflag) boomer.tick();

    if (screen_center_x > shield.position.x + 2) shieldflag = 1;
    if (shieldflag) shield.tick();

    int b1flag, b2flag;
    if (screen_center_x > 51)
        b1flag = 1;
    if (screen_center_x > 251)
        b2flag = 1;
    if (b1flag) biggie1.tick();
    if (b2flag) biggie2.tick();

    int z1flag, z2flag;
    if (screen_center_x > 31)
        z1flag = 1;
    if (screen_center_x > 101)
        z2flag = 1;
    if (z1flag) zoom1.tick();
    if (z2flag) zoom2.tick();   

    //magnet stuff

    magbb = magnet.def_bounding_box();
    if (magflag) magnet.tick(screen_center_x);

    if (magnet.attract)
    {
        if (!detect_collision(magbb, bb1) )
        {
            if (ball.position.x < magnet.position.x - 0.5 ) 
                ball.position.x += 0.08;
            else if ( ball.position.x > magnet.position.x + 0.5)
                ball.position.x -= 0.08;

            if (ball.position.y < 3) ball.position.y += 0.15;
        }
    }
    else magflag = 0;

    if (ring_collision() && ball.position.y >= -3.0 )
    {
        // ringflag = 1;

        // printf("touched ring\n");
        immunity = 1;
        float initx = ball.position.x, inity = ball.position.y;
        if ( ball.position.x < ring.position.x) goRight = 1;
        else if ( ball.position.x > ring.position.x) goLeft = 1;

        if (goRight) ball.position.x += 0.04;
        // else if (goLeft) ball.position.x -= 0.04;
        float temp = 25 - pow(ball.position.x - ring.position.x, 2);
        if (temp >= 0) ball.position.y = ring.position.y + sqrt(temp);
        else ball.position.y = -2.9;
        // ball.position.x = (initx*cos(2*3.14159/180) - inity*sin(2*3.14159/180));
        // ball.position.y = initx*sin(2*3.14159/180) + inity*cos(2*3.14159/180);
        if ((ball.position.x - ring.position.x) > 4.8 || ball.position.y < -3.1 )
        {
            // printf("ring movement done\n");
            if (goRight) ball.position.x += 0.5;
            else if (goLeft) ball.position.x -= 0.5;

            ringflag = 0;
            immunity = 0;
            goRight = 0;
            goLeft = 0;
        }
    }
  


    //screen panning 

    if (ball.position.x > screen_center_x+2)
    {
        // if (ball.speed > ball.velocity)
        if (ball.override)
            screen_center_x += 0.5;
        else
            screen_center_x += ball.speed + ball.velocity;
        // else
        //     screen_center_x += ball.velocity;
        // printf("screencent-x=%f\n", screen_center_x);
        // printf("ball x =%f\n", ball.position.x);

    }
    if (ball.position.x < screen_center_x - 3)
    {
        if (ball.speed > ball.velocity)
            screen_center_x -= ball.speed;
        else
            screen_center_x -= ball.velocity;
        // printf("screencent-x=%f\n", screen_center_x);
        // printf("ball x =%f\n", ball.position.x);
        // // printf("ball y =%f\n", ball.position.y);

    }
    for (int i = 0; i < wbarr.size(); ++i)
    {
        wbarr[i].tick();
        if (wbarr[i].position.y > 3.1)
            wbarr.erase(wbarr.begin() + i);
    }

    for (int i = 0; i < enemy2arr.size(); ++i)
        enemy2arr[i].tick();

    if (ball.position.y < viserion.position.y)
        viserion.tick(1);
    else
        viserion.tick(0);

    for (int i = 0; i < snowballarr.size(); ++i)
    {
        snowballarr[i].tick();
        if (snowballarr[i].position.y < -3.1)
            snowballarr.erase(snowballarr.begin() + i);
        snow_bb[i] = snowballarr[i].def_bounding_box();
        if (detect_collision (bb1, snow_bb[i]) && !immunity)
        {
            // printf("hit icy\n");
            score -= 100;
            // printf("score = %d\n", score);
            snowballarr.erase(snowballarr.begin() + i);
        }
    }

    
    for (int i = 0; i < coinarr.size(); ++i)
    {
        coinarr[i].tick();
        coin_bb[i] = coinarr[i].def_bounding_box();
        if (detect_collision (bb1, coin_bb[i]))
        {
            coinarr.erase(coinarr.begin() + i);
            if (i % 2 == 0) score += 5;
            else if (i % 3 == 0 || i % 5 == 0) score += 10;
            else score += 15;
            // printf("score = %d\n", score);
        }
    }

    shieldbb = shield.def_bounding_box();
    if (detect_collision (bb1, shieldbb) && shieldflag)
    {
        shield.active = 1;
    }

    if (shield.active)
    {
        immunity = 1;
        shield.position.y = ball.position.y;
        shield.position.x = ball.position.x + 1.0f;
        shieldtimer--;
        // printf("shield active, timer = %d\n", shieldtimer);
        if (shieldtimer == 0)
        {
            shield.active = 0;
            immunity = 0;
            shieldflag = 0;
            shield.position.x = 50.0f;
        }
    }

    dragbb = viserion.def_bounding_box();
    if (detect_collision (dragbb, shieldbb) && shieldflag)
    {
        dragonlife--;
    }

    if (dragonlife == 0)
    {
        viserion.ShootTime = -1;
        viserion.dead = 1;
        dragonlife--;
        score += 1000;
        printf("Score = %d\n", score);
        printf("You have won the game! Press ESC to exit the game.\n");
    }


    big1 = biggie1.def_bounding_box();
    if (detect_collision (bb1, big1) && b1flag)
    {
        biggie1.position.y = -90;
        score += 50;
        // printf("score = %d\n", score);
    }
    big2 = biggie2.def_bounding_box();

    if (detect_collision (bb1, big2) && b2flag)
    {
        biggie2.position.y = -90;
        score += 50;
        // printf("score = %d\n", score);
    }

    zo1 = zoom1.def_bounding_box();
    if (detect_collision (bb1, zo1) && z1flag)
    {
        zoom1.position.y = -90;
        // ball.speed *= 5
        ball.override = 1;
        immunity = 1;
        timer = 200;
    }

    zo2 = zoom2.def_bounding_box();
    if (detect_collision (bb1, zo2) && z2flag)
    {
        zoom2.position.y = -90;
        ball.override = 1;
        immunity = 1;
        timer = 200;
    }

    if (ball.override) timer--;
    if (timer < 0)
    {
        ball.override = 0;
        immunity = 0;
        timer = 0;
    }

    if (score < -100)
    {
        printf("Your score is too low to continue. You died. Score = %d\n", score);
        exit(0);
    }

    //enemy collision stuff

    bounding_box_t enemy1_bb[600];
    bounding_box_t enemy2_bb[600];
    bounding_box_t wb_bb[600];

    for (int i = 0; i < enemy1arr.size(); ++i)
    {
        enemy1_bb[i] = enemy1arr[i].def_bounding_box();
        if (detect_collision (bb1, enemy1_bb[i]) && !immunity)
        {
            // printf("hit sparky\n");
            ball.position.y = -2.9;
            score -= 15;
            // printf("score = %d\n", score);
            // exit(0);
        }
        for (int j = 0; j < wbarr.size(); ++j)
        {
            wb_bb[j] = wbarr[j].def_bounding_box();
            if (detect_collision (wb_bb[j], enemy1_bb[i]) && !immunity)
            {
                enemy1arr.erase(enemy1arr.begin() + i);
                score += 15;
                printf("Destroyed with water! Score = %d\n", score);
            }
        }

    }
    for (int i = 0; i < enemy2arr.size(); ++i)
    {
        enemy2_bb[i] = enemy2arr[i].def_bounding_box();
        if (detect_collision (bb1, enemy2_bb[i]) && !immunity)
        {
            // printf("hit laserboi\n");
            score -= 40;
            ball.position.y = -2.9;
            // printf("score = %d\n", score);
            // exit(0);
        }
    }

    bounding_box_t boomerbb;
    boomerbb = boomer.def_bounding_box();
    if (detect_collision(boomerbb, bb1))
    {
        boomer.position.y = -100;
        ball.position.x -= 1.5;
        score -= 60;
        printf("Hit a boomerang! Score = %d\n", score);
    }


    camera_rotation_angle += 0;

}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) 
{
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    ball = Ball(-2, -2.9, COLOR_GREEN);
    viserion = Dragon(170, 3, COLOR_BLUE);

    //create magnet and position
    magnet = Magnet(rand() % 50 + 60, 3, COLOR_RED);
    // printf("mag pos=%f\n", magnet.position.x);

    ring = Ring(rand() % 20 + 70, -2.9, COLOR_PINK);

    //powerups initialisation

    biggie1 = BigMoney(50, -2.9, COLOR_BLUE);
    biggie2 = BigMoney(130, -2.9, COLOR_BLUE);
    biggie1.jumpStatus = 1;
    biggie2.jumpStatus = 1;

    shield = Shield(rand() % 30 + 50, -2.9, COLOR_GREY);

    zoom1 = Zoomer(30, -2.9, COLOR_BLUE);
    zoom2 = Zoomer(80, -2.9, COLOR_BLUE);
    zoom1.jumpStatus = 1;
    zoom2.jumpStatus = 1;

    //make enemies and randomize locations

    for (int i = 0; i < 200; ++i)
    {
        float coin_xrange = (rand() % 700) + 10 * 0.5;
        int coin_yrange = (rand() % 3);
        if (i%10 == 0)
        {
            laser = LaserBeam(coin_xrange, coin_yrange, COLOR_RED);
            enemy2arr.push_back(laser);
        }
        else
        {
            fireline = FireLine(coin_xrange, coin_yrange, COLOR_ORANGE);
            enemy1arr.push_back(fireline);
        }
    }

    boomer = Boomerang(rand() % 20 + 100, 4, COLOR_BROWN);


    //make goldcoins and randomize locations


    for (int i = 0; i < 250; ++i)
    {
        // int coin_num = (rand() % 20 + 10)*0.5;
        float coin_xrange = (rand() % 250) + 3 * 0.5;
        int coin_yrange = (rand() % 6 - 2);
        if (i % 2 == 0)
        {
            goldcoins = Coin(coin_xrange, coin_yrange, COLOR_GOLD, 0.095f); 
            coinarr.push_back(goldcoins); 
        }
        else if (i % 5 == 0 || i % 3 == 0)
        {
            greencoins = Coin(coin_xrange, coin_yrange, COLOR_TEAL, 0.15f);
            coinarr.push_back(greencoins); 
        }
        else
        {
            salmoncoins = Coin(coin_xrange, coin_yrange, COLOR_SALMON, 0.11f);
            coinarr.push_back(salmoncoins); 
        }
    }

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_AUBERGINE.r / 256.0, COLOR_AUBERGINE.g / 256.0, COLOR_AUBERGINE.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) 
{
    srand(time(0));
    int width  = 800;
    int height = 800;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window); //gets keyboard input
            glFinish();
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) 
{
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

bool ring_collision() 
{
    // if (abs(ball.position.x - ring.position.x) >= 4.8 && abs(ball.position.x - ring.position.x) <= 5.0)
    //     if (abs(ball.position.y - ring.position.y) >= 4.8 && abs(ball.position.x - ring.position.y) <= 5.0)
    //         return true;
    // return false;
    if (sqrt(pow((ball.position.x - ring.position.x), 2) + pow((ball.position.y - ring.position.y), 2)) >= 4.6) 
        if (sqrt(pow((ball.position.x - ring.position.x), 2) + pow((ball.position.y - ring.position.y), 2)) <= 5.2)
        {
            ringflag = 1;
            return true;
        }
    ringflag = 0;
    return false;
}

void reset_screen() 
{
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
