//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400


//height and width of paddle
#define PHEIGHT 10
#define PWIDTH 80

// Brick properties
#define ROWS 5
#define COLS 10
#define BRSPACING 6

//Brick width information calculated from pixels and cols/rows
#define brickHeight 4
int brickWidth = (WIDTH-COLS*BRSPACING)/COLS;



// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    double velX = 3;
    double velY = 3;
    int counter = 0;

    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    updateScoreboard(window, label, points);
    pause(5000);


    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        //Update scoreboard, this line doesn't seem to be working or is overwritten almost instantaneously
        updateScoreboard(window, label, points);
        pause(200);
       
        if(counter==0)
        {
            move(ball, 3+drand48(), 3+drand48());
            pause(20);
        }
        else
        {
            move(ball, velX, velY);
            pause(20);
        }

        GEvent event = getNextEvent(MOUSE_EVENT);
                    
        //Position the paddle along the x coordinate of the mouse
        if (event != NULL)
        {
            double x = getX(event);
            setLocation(paddle, x, HEIGHT-PHEIGHT-20); 
        }
               
        //Left-right wall bouncing works!!
        if((getX(ball)-RADIUS)<=0 || (getX(ball)+RADIUS)>=WIDTH)
        {
            velX = -velX;
            counter++;
            continue;
        }
        
        //If ball hits top of screen, bounce off
        if((getY(ball)-RADIUS)<=0)
        {
            velY = -velY;
            counter++;
            continue;
        }

        //If ball goes past the paddle, stop it at the bottom of the screen, subtract a life, remove old ball and re-initialize
        if((getY(ball)+RADIUS)>=HEIGHT)
        {
            lives -= 1;
            pause(2000);
            waitForClick();
            removeGWindow(window, ball);
            ball = initBall(window);
            pause(2000);
            counter = 0;
            continue;
        }       

        //Detect if ball touches a brick, remove said brick and bounce ball off
        GObject object = detectCollision(window, ball);
        
        if(object == paddle)
        {
            velY = -velY;
        }
        else if(object != NULL)
        {
            removeGWindow(window, detectCollision(window, ball));
            points++;
            velY = -velY;
            counter++;
            continue;
        }
        
        counter++;
        
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow myWindow)
{
    // WORKS!!!!
    
    //Trial and error initial x,y values for the first brick
    int xcounter = 5;
    int ycounter = 10;
    
   // GRect myBrick = newGRect(x,y, brickHeight, brickWidth)    
    
    for(int i=0; i<COLS; i++)
    {
        //for(int j=xcounter; j<(WIDTH-COLS*BRSPACING); j+=brickWidth)
        for(int j=0; j<(WIDTH-COLS*BRSPACING); j+=brickWidth)
        {
            GRect myBrick = newGRect(j+xcounter,i+ycounter, brickWidth, brickHeight);
            add(myWindow, myBrick);
            setColor(myBrick, "red");
            setFilled(myBrick, true);
            xcounter += 5;
        }
        xcounter = 5;
        ycounter += 20;
        
    }
    
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow myWindow)
{
    // WORKS!!!!
     
    GOval myCircle = newGOval(WIDTH/2, HEIGHT/2, 2*RADIUS, 2*RADIUS);
    add(myWindow, myCircle);
    setColor(myCircle, "Black");
    setFilled(myCircle, true);
    
    return myCircle;

}

 
/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow myWindow)
{
    //WORKS!!!!
    GRect myPaddle = newGRect((WIDTH/2)-(PWIDTH/2), HEIGHT-PHEIGHT-20, PWIDTH, PHEIGHT);
    add(myWindow, myPaddle);
    setColor(myPaddle, "BLACK");
    setFilled(myPaddle, true);
   
    return myPaddle;
    
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow myWindow)
{
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-36");
    add(myWindow, label);
    
    //setLocation(label, WIDTH/2, HEIGHT/2);
   // setLabel(label, "t");
    
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow myWindow, GLabel myLabel, int myPoints)
{
    // update label
    char s[12];
    sprintf(s, "%i", myPoints);
    setLabel(myLabel, s);

    // center label in window
    double x = (getWidth(myWindow) - getWidth(myLabel)) / 2;
    double y = (getHeight(myWindow) - getHeight(myLabel)) / 2;
    setLocation(myLabel, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow myWindow, GOval myBall)
{
    // ball's location
    double x = getX(myBall);
    double y = getY(myBall);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(myWindow, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(myWindow, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(myWindow, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(myWindow, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
