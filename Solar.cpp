#include "Solar.h"   
#include <stdlib.h> 
#include "gl/glut.h"

static float Increment = 1.0;  // Time step
static float Hour = 0.0;
static float Day = 0.0;
static float rotx = 0.0;
static float roty = 0.0;
GLenum spin = GL_TRUE;


void KeyFunc( unsigned char Key, int x, int y )
{
	switch ( Key ) {
	case 'a': rotx -= 2.0f;
		break;
	case 'd': rotx += 2.0f;
		break;
	case 'x': roty -= 2.0f;
		break;
	case 'w': roty += 2.0f;
		break;
	case 'r':
		spin = !spin;
		break;
	case 'q':
		exit(1);
	}
}


void Idle(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (spin) {
		// Update animation state
        Hour += Increment;
        Day += Increment/24;
		}
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef ( 0.0, 0.0, -8.0 );
	glRotatef(rotx, 1, 0, 0);
	glRotatef(roty, 0, 1, 0);

    // Sun
	
	glPushMatrix();	
	glColor3f(1.0, 1.0, 0.0);
	glutSolidSphere(2.0, 20, 20);
	glPopMatrix();

    // Earth
    glRotatef( 360.0*Day/365.0, 0.0, 1.0, 0.0 );
    glTranslatef( 4.0, 0.0, 0.0 );
    
	glPushMatrix();						
	glRotatef( 360.0*Hour/24.0, 0.0, 1.0, 0.0 );
    glColor3f( 1.0, 0.0, 0.0 );
    glutSolidSphere( 0.4, 10, 10);
    glPopMatrix();						

	//  Moon
	glPushMatrix();
   	glRotatef( 360.0*10.0*Day/365.0, 0.0, 1.0, 0.0 );
    glTranslatef( 0.7, 0.0, 0.0 );
    glColor3f( 0.0, 0.0, 1.0 );
    glutSolidSphere( 0.2, 5, 5 );
	glPopMatrix();

    glFlush();
    glutSwapBuffers();

	glutPostRedisplay();

}

void OpenGLInit(void)
{
    glShadeModel( GL_FLAT );
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glClearDepth( 1.0 );
    glEnable( GL_DEPTH_TEST );
}

void ResizeWindow(int w, int h)
{
    float aspectRatio;
	h = (h == 0) ? 1 : h;
	w = (w == 0) ? 1 : w;
	glViewport( 0, 0, w, h );	// View port uses whole window
	aspectRatio = (float)w/(float)h;

	// Set up the projection view matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 60.0, aspectRatio, 1.0, 30.0 );

    glMatrixMode( GL_MODELVIEW );
}

