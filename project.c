#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>
#include <stdlib.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

int firsttime = 0;
float x = 0 , y = 0, z = 0.0;
GLfloat oldy = 0, oldz = 0, tempz, dy = 0, dz = 0;
int triggered = 0;
float b_y = -0.8;
float b_z = -1.5;
int reached =0;

GLfloat courtVertices[][3] = {
    //basket ball court vertices
    {-2.5, -1.0, -4.7}, {2.5, -1.0, -4.7},
    {2.5, -1.0, 4.7}, {-2.5, -1.0, 4.7}
};

GLfloat firstPoleVertices[][3] = {
    //basket pole vertices
    //base
    {-0.1, -1.0, -5.2}, {0.1, -1.0, -5.2},
    {-0.1, -1.0, -5.0}, {0.1, -1.0, -5.0},
    //middle
    {-0.1, 0.5, -5.2}, {0.1, 0.5, -5.2},
    {-0.1, 0.4, -5.0}, {0.1, 0.4, -5.0},
    //top
    {-0.1, 1.3, -4.4 }, { 0.1, 1.3 , -4.4},
    {-0.1, 1.7, -4.4 }, { 0.1, 1.7, -4.4 }
};

GLfloat secondPoleVertices[][3] = {
    //basket pole vertices
    //base
    {-0.1, -1.0, 5.2}, {0.1, -1.0, 5.2},
    {-0.1, -1.0, 5.0}, {0.1, -1.0, 5.0},
    //middle
    {-0.1, 0.5, 5.2}, {0.1, 0.5, 5.2},
    {-0.1, 0.4, 5.0}, {0.1, 0.4, 5.0},
    //top
    {-0.1, 1.3, 4.4 }, { 0.1, 1.3 , 4.4},
    {-0.1, 1.7, 4.4 }, { 0.1, 1.7, 4.4}
};

GLfloat firstBoardVertices[][3] = {
    //basket first board vertices
    //base
    {-0.5, 1.0, -4.3}, { 0.5, 1.0, -4.3},
    {-0.5, 1.0, -4.4}, { 0.5, 1.0, -4.4},

    //top
    {-0.5, 2.0, -4.3}, { 0.5, 2.0, -4.3},
    {-0.5, 2.0, -4.4}, { 0.5, 2.0, -4.4},
};

GLfloat secondBoardVertices[][3] = {
    //basket second board vertices
    //base
    {-0.5, 1.0, 4.3}, { 0.5, 1.0, 4.3},
    {-0.5, 1.0, 4.4}, { 0.5, 1.0, 4.4},

    //top
    {-0.5, 2.0, 4.3}, { 0.5, 2.0, 4.3},
    {-0.5, 2.0, 4.4}, { 0.5, 2.0, 4.4},
};

GLfloat baseVertices[][3] = {
    //top
    {-3.0, -1.0001, -5.2}, {3.0, -1.0001, -5.2},
    {-3.0, -1.0001, 5.2}, {3.0, -1.0001, 5.2},
    //bottom
    {-3.0, -1.5, -5.2}, {3.0, -1.5, -5.2},
    {-3.0, -1.5, 5.2}, {3.0, -1.5, 5.2},

};

void poles(int a, int b, int c, int d)
{

    glBegin(GL_POLYGON);
    glColor3f(55.0 / 255.0, 51.0/ 255.0, 49.0/ 255.0);
    glVertex3fv(firstPoleVertices[a]);
    glVertex3fv(firstPoleVertices[b]);
    glVertex3fv(firstPoleVertices[c]);
    glVertex3fv(firstPoleVertices[d]);
    glEnd();
    //border for the poles
    glBegin(GL_LINE_LOOP);
    glColor3f(43.0 / 255.0, 39.0/ 255.0, 37.0/ 255.0);
    glVertex3fv(firstPoleVertices[a]);
    glVertex3fv(firstPoleVertices[b]);
    glVertex3fv(firstPoleVertices[c]);
    glVertex3fv(firstPoleVertices[d]);
    glEnd();
    //second right  pole
    glBegin(GL_POLYGON);
    glColor3f(55.0 / 255.0, 51.0/ 255.0, 49.0/ 255.0);
    glVertex3fv(secondPoleVertices[a]);
    glVertex3fv(secondPoleVertices[b]);
    glVertex3fv(secondPoleVertices[c]);
    glVertex3fv(secondPoleVertices[d]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(43.0 / 255.0, 39.0/ 255.0, 37.0/ 255.0);
    glVertex3fv(secondPoleVertices[a]);
    glVertex3fv(secondPoleVertices[b]);
    glVertex3fv(secondPoleVertices[c]);
    glVertex3fv(secondPoleVertices[d]);
    glEnd();
}
void lines(float a, float b, float c, float d)
{
    //a = -2.5, b = -0.05 c = 0.05 d = 2.5
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(a , -0.9999 , b);
    glVertex3f(d , -0.9999 , b);
    glVertex3f(d , -0.9999 , c);
    glVertex3f(a , -0.9999 , c);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(a , -0.9999 , b);
    glVertex3f(d , -0.9999 , b);
    glVertex3f(d , -0.9999 , c);
    glVertex3f(a , -0.9999 , c);
    glEnd();
}

void onBoardLines(float a, float b, float c, float d)
{
    glBegin(GL_POLYGON);//left board
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(a, b, -4.29);
    glVertex3f(d, b, -4.29);
    glVertex3f(d, c, -4.29);
    glVertex3f(a, c, -4.29);
    glEnd();

    glBegin(GL_POLYGON);//right board
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(a, b, 4.29);
    glVertex3f(d, b, 4.29);
    glVertex3f(d, c, 4.29);
    glVertex3f(a, c, 4.29);
    glEnd();
}

void board(int a, int b, int c, int d)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3fv(firstBoardVertices[a]);
    glVertex3fv(firstBoardVertices[b]);
    glVertex3fv(firstBoardVertices[c]);
    glVertex3fv(firstBoardVertices[d]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(86.0/255.0, 86.0/255.0, 86.0/255.0);
    glVertex3fv(firstBoardVertices[a]);
    glVertex3fv(firstBoardVertices[b]);
    glVertex3fv(firstBoardVertices[c]);
    glVertex3fv(firstBoardVertices[d]);
    glEnd();

    // right board
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3fv(secondBoardVertices[a]);
    glVertex3fv(secondBoardVertices[b]);
    glVertex3fv(secondBoardVertices[c]);
    glVertex3fv(secondBoardVertices[d]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(86.0/255.0, 86.0/255.0, 86.0/255.0);
    glVertex3fv(secondBoardVertices[a]);
    glVertex3fv(secondBoardVertices[b]);
    glVertex3fv(secondBoardVertices[c]);
    glVertex3fv(secondBoardVertices[d]);
    glEnd();
}


void base(int a, int b, int c, int d)
{
    glBegin(GL_POLYGON);
    glColor3f (0.5, 0.5, 0.5);
    glVertex3fv(baseVertices[a]);
    glVertex3fv(baseVertices[b]);
    glVertex3fv(baseVertices[c]);
    glVertex3fv(baseVertices[d]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(165.0/255.0, 0.0/255.0, 3.0/255.0);
    glVertex3fv(baseVertices[a]);
    glVertex3fv(baseVertices[b]);
    glVertex3fv(baseVertices[c]);
    glVertex3fv(baseVertices[d]);
    glEnd();
}
void polygon(int a, int b, int c, int d)
{
    // base of court
    base(0, 1, 3, 2); // front of base
    base(4, 5, 7, 6);// top of base
    base(2, 3, 7, 6);// right of base
    base(0, 1, 5, 4);// left of base
    base(0, 2, 6, 4); //bottom of base
    base(1, 3, 7, 5);// back of base

    // color of court vertices
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.4, 1.0);
    glVertex3fv(courtVertices[a]);
    glColor3f(0.0, 0.4, 1.0);
    glVertex3fv(courtVertices[b]);
    glColor3f(0.0, 0.4, 1.0);
    glVertex3fv(courtVertices[c]);
    glColor3f(0.0, 0.4, 1.0);
    glVertex3fv(courtVertices[d]);
    glEnd();
    // pole from base to the top
    poles(0, 1, 3, 2);
    poles(4, 5, 7, 6);
    poles(2, 3, 7, 6);
    poles(4, 5, 1, 0);
    poles(3, 1, 5, 7);
    poles(0, 2, 6, 4);

    //poles from center to board
    poles(6, 7, 9, 8);
    poles(4, 5, 11, 10);
    poles(6, 4, 10 , 8);
    poles(7, 5, 11, 9);

    //drawing board
    board(0, 1, 3, 2);// bottom of board
    board(4, 5, 7, 6);// top of the board
    board(0, 2, 6, 4);// left of board
    board(1, 3, 7, 5);//right of the board
    board(0, 1, 5, 4);// front of board
    board(3, 7, 6, 2);	// back of the board

    //center line
    lines(-2.5, -0.05, 0.05, 2.5);

    //side lines
    lines(-2.50, 4.7, -4.7, -2.55);//front
    lines(2.50, 4.7, -4.7, 2.55);

    //left right base lines
    lines(-2.55, 4.70, 4.75, 2.55);// left
    lines(-2.55, -4.70, -4.75, 2.55);//right


    //three pointer lines
    lines(-2.2, 4.7, 4.05, -2.27);//right front
    lines( 2.2, 4.7, 4.05, 2.27);// right back

    lines(-2.2, -4.7, -4.05, -2.27);//left front
    lines( 2.2, -4.7, -4.05, 2.27);//left back

    //two pointer lines
    lines(-0.6, 4.7, 2.8, -0.64);//right back
    lines(0.6, 4.7, 2.8, 0.64);// right front

    lines(-0.6, -4.7, -2.8, -0.64);//left front
    lines(0.6, -4.7, -2.8, 0.64);//left back

    //lines joining the above two lines
    lines(-0.6, 2.8, 2.84, 0.6);// right
    lines(-0.6, -2.8, -2.84, 0.6);//left

    //vertical lines on the board
    onBoardLines(-0.15, 1.2, 1.24, 0.15); //bottom
    onBoardLines(-0.15, 1.5, 1.54, 0.15); //down

    //horizontal lines on board
    onBoardLines(-0.15, 1.2, 1.5, -0.10);//left
    onBoardLines(0.15, 1.2, 1.5, 0.10);//right

}
void logo()
{
    glColor3ub(85,26,139);
    glBegin(GL_POLYGON); // top diamond
    glVertex2f(1.00,3.20);
    glVertex2f(1.30,3.50);
    glVertex2f(1.00,3.80);
    glVertex2f(0.70,3.50);
    glEnd();
    glColor3ub(85,26,139);
    glBegin(GL_POLYGON); //right triangle
    glVertex2f(0.4,3.20);
    glVertex2f(0.95,3.20);
    glVertex2f(0.60,3.40);
    glEnd();
    glColor3ub(85,26,139);
    glBegin(GL_POLYGON); // left triangle
    glVertex2f(1.05,3.20);
    glVertex2f(1.60,3.20);
    glVertex2f(1.40,3.40);
    glEnd();
    glColor3ub(255,145,0);
    glBegin(GL_POLYGON); //right ear
    glVertex2f(0.50,3.70);
    glVertex2f(0.70,3.50);
    glVertex2f(0.60,3.40);
    glVertex2f(0.40,3.60);
    glEnd();
    glColor3ub(255,145,0); //left ear
    glBegin(GL_POLYGON);
    glVertex2f(1.50,3.70);
    glVertex2f(1.30,3.50);
    glVertex2f(1.40,3.40);
    glVertex2f(1.60,3.60);
    glEnd();
}
void circle(float r)
{
    int i;
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(3.0);
    glBegin(GL_POINTS);
    for(i = 0; i < 1000; i++) {
        //x and y defines the radius
        glVertex3f( (r * cos(2*3.14159 * i/1000.0)), -0.9999, (r * sin(2*3.14159 * i/1000.0)));
    }
    glEnd();
}

void Dcircle(float r)
{
    int i;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    for(i = 0; i < 1000; i++) {
        //x and y defines the radius
        glVertex3f( (r * cos(1*3.14159 * i/1000.0)), -0.9999, 2.8 - (r * sin(1*3.14159 * i/1000.0)));//right semi d circle
        glVertex3f( (r * cos(1*3.14159 * i/1000.0)), -0.9999, -2.8 + (r * sin(1*3.14159 * i/1000.0)));//left semi d circle

    }

    for(i = 0; i < 20; i++) {
        //x and y defines the radius
        glVertex3f( (r * cos(1*3.14159 * i/20.0)), -0.9999, 2.8 + (r * sin(1*3.14159 * i/20.0)));//right semi d-circle
        glVertex3f( (r * cos(1*3.14159 * i/20.0)), -0.9999, -2.8 - (r * sin(1*3.14159 * i/20.0)));//left semi-dcirlce
    }
    glEnd();
}

void ring(float r)
{
    int i;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for(i = 0; i< 1000; i++) {
        //x and y defines the radius
        glVertex3f((r * cos(2*3.14159 * i/1000.0)), 1.2, 4.3 - 0.19 + (r * sin(2*3.14159 * i/1000.0)));//right ring
        glVertex3f((r * cos(2*3.14159 * i/1000.0)), 1.2, -4.3 + 0.19 + (r * sin(2*3.14159 * i/1000.0)));//left ring
    }
    glEnd();
}


void semicircle(float r)
{
    int i;
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(3.0);
    glBegin(GL_POINTS);
    for(i = 0; i < 1000; i++) {
        glVertex3f((r * cos(1*3.14159 * i/1000.0)), -0.9999, 4.05 - (r * sin(1*3.14159 * i/1000.0)));//right
        glVertex3f((r * cos(1*3.14159 * i/1000.0)), -0.9999, -4.05 + (r * sin(1*3.14159 * i/1000.0)));//left
    }
    glEnd();
}

void ball()
{
    if(triggered) {
        glTranslatef(0.0, b_y, b_z); //calculated using the last vertex of parabola
    } else {
        glTranslatef(0.0, -0.85, -1.5); //calculated using the last vertex of parabola
    }
    glColor3f(0.81176, 0.3254, 0.0);
    glutSolidSphere(0.15, 1000, 20);
}

void stairs1()
{
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);

    GLfloat x = 5, y = -1.2, sx = 3.5;
    for(int i = 0; i< 7; i++) {
        glPushMatrix();
        glTranslatef(x, y, 0.0);
        glScaled(sx, 0.5, 17.5);
        glutSolidCube(1);
        sx = sx - 0.5;
        x = x + 0.25;
        y = y + 0.5;
        glPopMatrix();
    }
    glPopMatrix();
}

void stairs2()
{
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);

    GLfloat z = -7, y = -1.2, sz = 3.5;
    for(int i = 0; i< 7; i++) {
        glPushMatrix();
        glTranslatef(1.7, y, z);
        glScaled(9.5, 0.5, sz);
        glutSolidCube(1);
        sz = sz - 0.5;
        z = z - 0.25;
        y = y + 0.5;
        glPopMatrix();
    }
    glTranslatef(1.7, 2.2, -8.5);
    glScaled(9.5, 2.0, 0.5);
    glutSolidCube(1);
    glPopMatrix();
}

void stairs3()
{
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);

    GLfloat z = 7, y = -1.2, sz = 3.5;
    for(int i = 0; i< 7; i++) {
        glPushMatrix();
        glTranslatef(1.7, y, z);
        glScaled(9.5, 0.5, sz);
        glutSolidCube(1);
        sz = sz - 0.5;
        z = z + 0.25;
        y = y + 0.5;
        glPopMatrix();
    }
    glPopMatrix();
}

/*
   glTranslatef(1.5, -1.2, -7);
glScaled(9, 0.5, 3.5);
glutSolidCube(1);
*/
void draw()
{
    glPushMatrix();
    if(firsttime == 0) {
        glTranslatef(0, y, dz);
    }

    ball();
    glPopMatrix();

    polygon(0, 1, 2, 3);
    //center circle
    circle(0.60);

    Dcircle(0.6);

    ring(0.17);

    ////three pointer semi cirlce
    semicircle(2.22);
    stairs1();
    stairs2();
    stairs3();
    glPushMatrix();
    {
    glTranslated(6.0,-1.0,4.0);
    //glScaled(1.0,1,4);
    glRotated(90,0,1,0);
    logo();
    }
    glPopMatrix();
}
void RenderString(float x, float y)
{
    char *c;

    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,"ACHARYA BASKETBALL COURT");
}

static GLfloat theta[] = {0.0, 90.0, 0.0};
static GLdouble viewer[] =  {0.0, 7.0, 7.0};

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(viewer[0], viewer[1], viewer[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
    draw();
    RenderString(0, 3.60);
    glFlush();
    glutSwapBuffers();
}

void update(int value)
{
    if(triggered && b_y < 1.6) {
        b_y += 0.1;
        b_z -= 0.1;
        if(b_y == 1.0) {
            b_y == -0.8;
        }
        firsttime = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(1000/60,update,0);
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w , h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w <= h)
        glFrustum(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w , 2.0 * (GLfloat)h / (GLfloat)w, 2.0, 20.0);
    else
        glFrustum(-2.0, 2.0, -2.0 * (GLfloat)w / (GLfloat)h , 2.0 * (GLfloat)w / (GLfloat)h,  2.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void initLighting()
{
    GLfloat lightColor0[] = { 0.6f, 0.6f, 0.6f, 1.0f };
    GLfloat lightPos0[] = { -0.5f, 0.8f, 1.0f, 0.0f };
    GLfloat ambientColor[] = { 0.4f, 0.4f, 0.4f, 1.0f };

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

}


void keys(unsigned char key, int x, int y)
{
    //test conditions to ensure that the camera always capture the obejct and does move too far from the object
    if(key == 'x' && viewer[0] != -6) viewer[0] -= 1.0;
    if(key == 'X' && viewer[0] != 6) viewer[0] += 1.0;
    if(key == 'y' && viewer[1] != 0) viewer[1] -= 1.0;
    if(key == 'Y' && viewer[1] != 9) viewer[1] += 1.0;
    if(key == 'z'  && viewer[2] != 4) viewer[2] -= 1.0;
    if(key == 'Z'  && viewer[2] != 10) viewer[2] += 1.0;
    if(key == 's' || key == 'S') {
        triggered = 1;
        firsttime = 1;
    }
    display();
}
int main(int argc, char **argv)
{
    glutInit(&argc , argv);
    float ambient[]= {1,1,1,1};
    float light_pos[]= {0,2,-2,0};
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Acharya Basket Ball Court");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    initLighting();
    glEnable(GL_DEPTH_TEST);
    glutTimerFunc(100, update, 0);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutMainLoop();
}
