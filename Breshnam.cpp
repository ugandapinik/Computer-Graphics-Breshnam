#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;


int x0,y0,x1,y1;


void myInit (void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void MidPoint(void){

    int dx = x1 - x0;
    int dy = y1 - y0;

    int d = 2 * dy - dx;
    int incE = 2 * dy;
    int incNE = 2 * (dy - dx);

    int x = x0, y = y0;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_LINES);

    glVertex2d(x,y);

    while(x < x1){
        if( d <= 0 ){
            d = d + incE;
        }else{
            d = d + incNE;
            y = y+3;
        }
        x = x + 3;
        glVertex2d(x,y);

    }

    glEnd();

  glFlush();

}


int main(int argc, char** argv){

    cout<<"Enter you first Point : ";
    cin>>x0>>y0;
    cout<<endl;
    cout<<"Enter you second Point : ";
    cin>>x1>>y1;




    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("my first attempt");
    glutDisplayFunc(MidPoint);
    myInit ();
    glutMainLoop();
}



