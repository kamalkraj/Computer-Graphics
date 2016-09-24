#include<stdio.h>
#include<GL/glut.h>


void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,1000.0,0,1000.00);
}

void line()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
        glVertex2i(100,100);
        glVertex2i(400,400);
    glEnd();
    glFlush();
}

int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Line");
    init();
    glutDisplayFunc(line);
    glutMainLoop();
    return 0;
}