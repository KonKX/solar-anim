#include "Solar.h"   
#include <stdlib.h> 
#include "gl/glut.h"

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 360);
	glutCreateWindow("Solar System");

	OpenGLInit();
	glutKeyboardFunc(KeyFunc);
	glutReshapeFunc(ResizeWindow);
	glutDisplayFunc(Idle);
	glutMainLoop();

	return(0);
}