/*   GWM_GL
 * Simple, Cross-platform solution for Window Notifications in OpenGL
 *  Made by ApplehatDot (ApplehatDoesStuff)
 */

#include <GL/freeglut.h>
#include <GL/glut.h>
#include "GWM.h"

// Those 2 Values must be given for GWM.
#define PosX 100.0f
#define PosY 100.0f

// wWidth, wHeight determine the size generated by the OpenGL for scaling
// PosX, PosY are the Position of the GWM Window
WindowPosition WP = {wWidth, wHeight, PosX, PosY};

// GWM Window Size {200.0f, 100.0f}, Description character - no limit, Text Position(s) 
GWMConfig GWM = {
	200.0f, 
	100.0f, 
	"a quick brown fox jumps\nover the lazy dog\n\nIt Works :P", 
	PosX + 1.0f, 
	PosY + 78.0f
}; 

/* 
You could also define the description as below:
    GWMConfig GWM;
    GWM.DESC = "a quick brown fox jumps over the lazy dog";
 */

void display(){
    glClearColor(0.0f/255.0f, 0.0f/255.0f, 0.0f/255.0f, 1.0f);	//Background - Black
    glClear(GL_COLOR_BUFFER_BIT);
	
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, wWidth, 0, wHeight);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
	
	
    MakeWindow(&GWM, &WP);
	
	
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glutSwapBuffers();
} 

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, wWidth, 0, wHeight);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutReshapeWindow(wWidth, wHeight);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(wWidth, wHeight);

    glutCreateWindow("GWM_GL Demo");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
