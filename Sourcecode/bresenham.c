#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int xs,xe,ys,ye;

void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,1000,0,1000);
}

void setpixel(int x,int y)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
        glVertex2f(x,y);
    glEnd();
    glFlush();
}

void bresenham()
{
    int d,dy,dx;
    dx = abs(xe - xs);
    dy = abs(ye - ys);
    d = 2*dy - dx;
    setpixel(xs,ys);
    while(xs<=xe)
    {
        if(d<0)
        {
            d = 2*dy;
        }
        else
        {
            ys = ys + 1;
            d = 2*(dy - dx);  
        }
        xs = xs + 1;
        setpixel(xs,ys);
    }

}

int main(int argc,char* argv[])
{
    scanf("%d%d%d%d",&xs,&ys,&xe,&ye);
    glutInit(&argc,argv);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(300,300);
    glutCreateWindow("BRESENHAM");
    init();
    glutDisplayFunc(bresenham);
    glutMainLoop();
    return 0;
}