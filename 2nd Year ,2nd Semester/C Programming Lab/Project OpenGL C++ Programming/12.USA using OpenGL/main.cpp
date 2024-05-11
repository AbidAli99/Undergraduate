#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
//adjust position so that our flag can be centered.
const int rx=5;
const int ry=50;
//the star get d as semi-diameter,rx,ry as the center position
void star(double d,double rx,double ry);
//draw flag
void draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);//the flag base
    glColor3f(1,1,1);
    glVertex2f(0+rx,0+ry);
    glVertex2f(0+rx,100+ry);
    glVertex2f(190+rx,100+ry);
    glVertex2f(190+rx,0+ry);
    glEnd();

    glColor3f(0.756,0.076,0.238);
    const GLdouble stripwidth=7.69;
    for(int i=0;i<13;i=i+2)//draw strip
    {
        glBegin(GL_POLYGON);
        glVertex2d(0+rx,i*stripwidth+ry);
        glVertex2d(0+rx,(i+1)*stripwidth+ry);
        glVertex2d(190+rx,(i+1)*stripwidth+ry);
        glVertex2d(190+rx,i*stripwidth+ry);
        glEnd();
    }

    glColor3f(0,0.172,0.46);
    //get left-top blue base's position
    const GLdouble blue_height=100-53.85;
    const GLdouble blue_width=76;
    glBegin(GL_POLYGON);
    glVertex2d(rx,blue_height+ry);
    glVertex2d(rx,100+ry);
    glVertex2d(blue_width+rx,100+ry);
    glVertex2d(blue_width+rx,blue_height+ry);
    glEnd();
    glFlush();
    //get the distance between stars
    const  GLdouble E=5.38;
    const  GLdouble G=6.33;
    //get the semi-diameter of star
    const GLdouble k=6.1803/2;
    //draw star
    for(int i=0;i<11;i=i+2)
    {
        for (int j = 0; j < 9; j=j+2) {
            star(k,G+i*G+rx,blue_height+E+j*E+ry);

        }
    }
    for(int i=0;i<9;i=i+2)
    {
        for (int j = 0; j < 7; j=j+2) {
            star(k,G+(i+1)*G+rx,blue_height+E+(j+1)*E+ry);

        }
    }


}
void init()
{
    glClearColor(0.0,0.0,0.0,0.0);

}
void star(double d,double rx,double ry)
{
    const double t=0.38196;
    const double transform=3.1415926/180;
    //get the star vertex position compared with center
    GLdouble draw_star[10][2]={
                                0,1,//A 1
                                cos( 54*transform )*t,t*sin( 54*transform ),//dd 2
                                cos( 18*transform  ),sin( 18*transform  ),//b 3
                                cos( 18*transform  )*t,-t*sin( 18*transform  ),//ee 4
                                cos( 54*transform ),-sin( 54*transform ),//c 5
                                0,-t,//aa 6
                                -cos( 54*transform ),-sin( 54*transform ),//d 7
                                -t*cos( 18*transform  ),-t*sin( 18*transform  ),//bb 8
                                -cos( 18*transform  ),sin( 18*transform  ),//E 9
                                -t*cos( 54*transform ),t*sin( 54*transform ),//cc 10

    };
    //get the size of star
    const GLdouble size=d;
    //draw first triangle
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);//the star
    glVertex2d(draw_star[0][0]*size+rx,draw_star[0][1]*size+ry);
    glVertex2d(draw_star[4][0]*size+rx,draw_star[4][1]*size+ry);
    glVertex2d(draw_star[7][0]*size+rx,draw_star[7][1]*size+ry);
    glEnd();
    //draw second triangle
    glBegin(GL_POLYGON);//the star
    glVertex2d(draw_star[2][0]*size+rx,draw_star[2][1]*size+ry);
    glVertex2d(draw_star[5][0]*size+rx,draw_star[5][1]*size+ry);
    glVertex2d(draw_star[8][0]*size+rx,draw_star[8][1]*size+ry);
    glEnd();
    //draw third small triangle
    glBegin(GL_POLYGON);//the star
    glVertex2d(draw_star[5][0]*size+rx,draw_star[5][1]*size+ry);
    glVertex2d(draw_star[6][0]*size+rx,draw_star[6][1]*size+ry);
    glVertex2d(draw_star[7][0]*size+rx,draw_star[7][1]*size+ry);
    glEnd();
    glFlush();

}


int main(int argc,char **argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowPosition(300,300);
    glutInitWindowSize(600,600);
    glutCreateWindow("the USA flag");
    init();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,200.0,0.0,200.0,-1,1);
    glutDisplayFunc(draw);
    //glutDisplayFunc(star);
    glutMainLoop();

    return 0;
}
