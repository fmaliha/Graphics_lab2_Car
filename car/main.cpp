#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
# define PI           3.14159265358979323846
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	GLfloat x=.0f; GLfloat y=-.5f; GLfloat radius =.1f;
	GLfloat xa=-.4f;    GLfloat yb=-.5f;  GLfloat radiusab =.07f;
	GLfloat xc=-.5f;       GLfloat yd=-.5f;
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;


//mountains

   glBegin(GL_POLYGON);
   glColor3ub(115, 77, 38);
	glVertex2f(-1.0,.3);
	glVertex2f(-.3,.5);
	glVertex2f(-.5,.1);
	glVertex2f(-.5,.8);
	glVertex2f(-.9,.9);
	glVertex2f(1.0,.1);

	glVertex2f(1.3,.5);
	glVertex2f(1.6,.1);
	glVertex2f(1.0,.1);



	glEnd();
	glFlush();

	//upper field


	glBegin(GL_QUADS);
	glColor3f(0.0f, .502f, 0.0f);
	glVertex2f(-1.0,.3);
	glVertex2f(-1.0,.1);
	glVertex2f(1.0,.1);
	glVertex2f(1.0,.3);
	glEnd();
	glFlush();

//road

glBegin(GL_QUADS);
	glColor3ub(51, 51, 51);
	glVertex2f(-1.0,.1);
	glVertex2f(-1.0,-.8);
	glVertex2f(1.0,-.8);
	glVertex2f(1.0,.1);


	glEnd();
	glFlush();

//Lower field

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.502f, 0.0f);
	glVertex2f(-1.0,-.8);
	glVertex2f(-1.0,-1.0);
	glVertex2f(1.0,-1.0);
	glVertex2f(1.0,-.8);
	glEnd();
	glFlush();


	//car

	glBegin(GL_POLYGON);
	glColor3f(128.0f, 0.0f, 0.0f);
	glVertex2f(-.5,-.1);
	glVertex2f(-.6,-.2);
	glVertex2f(-.7,-.3);
	glVertex2f(-.8,-.3);
	glVertex2f(-.9,-.3);
	glVertex2f(-.9,-.5);


	glVertex2f(.2,-.5);
	glVertex2f(.2,-.3);
	glVertex2f(.1,-.3); //
	glVertex2f(0.0,-.1);
	//glVertex2f(-.2,-.1);
	//glVertex2f(.2,-.2);
	glEnd();
	glFlush();


	//road divider line


    glBegin(GL_LINES);
	glColor3ub(230, 230, 0);
	//glVertex2f(-.10,-.4);
	//glVertex2f(-.09,-.4);

	glVertex2f(.4,-.4);
	glVertex2f(.3,-.4);

	glVertex2f(.5,-.4);
	glVertex2f(.6,-.4);

	glVertex2f(.7,-.4);
	glVertex2f(.8,-.4);

glVertex2f(.9,-.4);
	glVertex2f(1.0,-.4);

	glEnd();
	glFlush();


//wheel back 3
	glBegin(GL_POLYGON);
		for(i = 0; i <= lineAmount;i++) {

                glColor3f(0.0f, 0.0f, 0.0f);
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

	glFlush();  // Render now


	//wheel front 2

	glBegin(GL_POLYGON);
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    xa+ (radiusab * cos(i *  twicePi / lineAmount)),
			    yb + (radiusab* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
glVertex2f(.2,-.5);
	glFlush();  // Render now

//wheel front 1
	glBegin(GL_POLYGON);
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    xc + (radius * cos(i *  twicePi / lineAmount)),
			    yd + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

	glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("My Car"); // Create a window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
