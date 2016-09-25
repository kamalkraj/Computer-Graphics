#include<stdio.h>
#include<GL/glut.h>

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

    
}

void dda()
{
    int dx,dy,steps,i;
    glClear(GL_COLOR_BUFFER_BIT);
    dx = abs(xe - xs);
    dy = abs(ye - ys);
    if(dx>dy)
        steps  = dx;
    else
        steps = dy;
    for(i=0;i<steps;i++)
    {
        setpixel(xs,ys);
        printf("%d\t%d\n",xs,ys);
        xs = xs + (dx/steps);
        ys = ys + (dy/steps);
        glFlush();
    }
}

int main(int argc,char* argv[])
{
    scanf("%d%d%d%d",&xs,&ys,&xe,&ye);
    glutInit(&argc,argv);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(300,300);
    glutCreateWindow("DDA");
    init();
    glutDisplayFunc(dda);
    glutMainLoop();
    return 0;
}