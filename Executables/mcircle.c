#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int x,y,r;
int xc,yc;

void o(int,int);

void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1000,1000,-1000,1000);
}

void setpixel(int x,int y)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
        glVertex2f(x,y);
    glEnd();
    glFlush();
}

void circle()
{
    int d;
    x = 0;
    y = r;
    d = 5/4 -r;
    o(x,y);
    while(x<y)
    {
        x++;
        if(d<0)
        {
            d = d + 2*(x+1) + 1; 
        }
        else
        {
            y--;
            d = d + 2*(x+1) + 1 + - 2*(y-1);
        }
        o(x,y);
    }
}


void o(int x,int y)
{
    setpixel(x,y);
    setpixel(y,x);
    setpixel(y,-x);
    setpixel(x,-y);
    setpixel(-x,-y);
    setpixel(-y,-x);
    setpixel(-y,x);
    setpixel(-x,y);
}

int main(int argc,char* argv[])
{
    scanf("%d%d%d",&xc,&yc,&r);
    glutInit(&argc,argv);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(300,300);
    glutCreateWindow("Midpoint Circle");
    init();
    glutDisplayFunc(circle);
    glutMainLoop();
    return 0;
}