#include <windows.h> 
#include <glut.h>
#include <GL/gl.h>
#include <GL/GLU.H>
#include <iostream>
#include <math.h>
#include <cmath>

void init() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300,300,-300,300);
	
}

    float r = 0.0f;
    float t = -110;



	float r2 = 40;
    float t2 = -180;
		

	float r3 = 280;
    float t3 = -195;
		
	float r4 = 230;
    float t4 = -195;


	void drawTree() {
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-10.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(0.0f, 30.0f);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-15.0f, 30.0f);
    glVertex2f(15.0f, 30.0f);
    glVertex2f(0.0f, 60.0f);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-20.0f, 60.0f);
    glVertex2f(20.0f, 60.0f);
    glVertex2f(0.0f, 90.0f);
    glEnd();
}







void drawTree2() {
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-10.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(0.0f, 30.0f);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-15.0f, 30.0f);
    glVertex2f(15.0f, 30.0f);
    glVertex2f(0.0f, 60.0f);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-20.0f, 60.0f);
    glVertex2f(20.0f, 60.0f);
    glVertex2f(0.0f, 90.0f);
    glEnd();
}









void grass()
{
	glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		glVertex2f(-300,-200);
		glVertex2f(-300,-300);
		glVertex2f(300,-300);
		glVertex2f(300,-200);
	glEnd();
}



void drawSphere()
{
	 glColor3f(1.0f, 1.0f, 1.0f);

     glutSolidSphere(10, 32, 32); 
	 gluDisk(gluNewQuadric(),0.0,10.0,32,1);
	 glPopMatrix();
}



void drawStickFigure()
{
    glColor3f(1.0f, 1.0f, 1.0f); 
	
    // Draw the head
    glBegin(GL_POLYGON);
	glPushMatrix();
	gluDisk(gluNewQuadric(),0.0,10.0,32,1);
	glPopMatrix();

	

    // Draw the torso
    glBegin(GL_LINES);
    glVertex2f(0, 0);
	glVertex2f(0, 0 - 50);
    glEnd();

    // Draw the arms
    glBegin(GL_LINES);
	glVertex2f(0,  - 20);
	glVertex2f( - 20, - 20);
    glEnd();

    glBegin(GL_LINES);
	glVertex2f(0, 0 - 20);
	glVertex2f(  20, 0 - 20);
    glEnd();

    // Draw the legs
    glBegin(GL_LINES);
	glVertex2f(0, 0 - 50);
	glVertex2f(0 - 20, 0 - 80);
    glEnd();
	
    glBegin(GL_LINES);
    glVertex2f(0, 0 - 50);
    glVertex2f(  20, 0 - 80);
    glEnd();

}


void handleKeyboard(unsigned char key,int n, int m)
{
    switch (key) {
    case 'a':
		r -= 20;
        break;
    case 'd':
		r += 20;
        break;
    case 'w':
		t += 20;
        break;
    case 's':
		t -= 20;
        break;


    case  'j':
        r2 -= 20;
        break;
    case 'l':
	    r2 += 20;
        break;
	case 'i':
	    t2 += 20;
        break;
    case 'k':
	    t2 -= 20;
        break;



    }

    glutPostRedisplay();
}




void circl(double r)
{
	double pi=3.14 , x=0 , y=0 , i=0;
	glBegin(GL_POLYGON);
	for ( i = 0; i < 2*pi; i+=pi/50)
	{
		x=r*cos(i);
		y=r*sin(i);
		glVertex2f(x,y);
	}
	glEnd();
}



double o=0, p=0;
void up(int v)
{
	p+=1;
	glutPostRedisplay();
	glutTimerFunc(1,up,0);
}

double a1=0,b1=0,c=0,d=0;
void moon()
{
	glBegin(GL_POLYGON);
		glColor3f(0.5,0.5,0.5);
		circl(40);
		glTranslatef(10+a1,2+b1,0);
		glColor3f(0.0,0.0,0.0);
		circl(40);
	glEnd();
}



double a=0, b=0,count=0,aa=0,bb=0;
void display () {
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
	
	glTranslatef(-150+a,0+b,0);
	moon();

	glutSwapBuffers();
	o+=0.02;
	if(o>320)
		o=-60;
	a+=0.007;
	b+=0.005;
	count=b;
	glLoadIdentity();
	
	aa+=0.007;
	bb-=0.005;
	b1+=0.003;
	a1+=0.0015;
	c+=0.0022;
	d-=0.0014;
	if(c>=100)
	{
		aa=1000;
	}
	glutPostRedisplay();
	glLoadIdentity();

	glTranslatef(r,t,0.0f);
	drawStickFigure();
	glutSwapBuffers();


	glLoadIdentity();
	glTranslatef(r2,t2, 0.0f); 
	drawSphere();
	glutSwapBuffers();

	glLoadIdentity();
	grass();
	glutSwapBuffers();



	glLoadIdentity();
	glTranslatef(r3,t3, 0.0f); 
	drawTree();
	glutSwapBuffers();



	glLoadIdentity();
	glTranslatef(r4,t4, 0.0f); 
	drawTree2();
	glutSwapBuffers();

}


int main(int argc, char** argv) {
glutInit(&argc, argv); 
glutCreateWindow("Vertex, Primitive & Color"); 
glutInitWindowSize(620, 420); 
glutInitWindowPosition(50, 50);
glutDisplayFunc(display); 
glutKeyboardFunc(handleKeyboard);
init(); 
glutInitDisplayMode(GLUT_DOUBLE);
glutTimerFunc(900,up,0);
glutMainLoop(); 


return 0;
}