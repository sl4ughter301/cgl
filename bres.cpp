#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;
float r,g,b,x,y;
float x_1,x_2,y_1,y_2;
bool flag = true;
void mouse(int button , int state, int mousex, int mousey){
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
flag = true;
x = mousex;
y = 480-mousey;
}
cout<<"mousex = "<<x;
cout<<"mousey = "<<y;
}
int sgn(float a){
if(a==0){
return 0;
}
if(a<0){
return -1;
}
else{
return 1;
}
}
void Line(){
cout<<"x_1=" << x_1 <<"y_1=" << y_1;
cout<<"x_2=" << x_2 <<"y_2=" << y_2;
float dx,dy,length,G;
//x_2 = x;
//y_2 = y;
dy = y_2 - y_1;
dx = x_2 - x_1;
G = (2*dy)-dx;
if(abs(dx) >= abs(dy)){
length = abs(dx);
}
else{
length = abs(dy);
}
int j =0;
x = x_1;
y = y_1;
while(j <= length){
if(abs(dx) >= abs(dy)){
x = x+1;
if(G>=0){
y = y+1;
G = G+2*(dy-dx);
}
else{
G = G + (2*dy);
}
}
else{
y = y+1;
if(G>=0){
x = x+1;
G = G+2*(dy-dx);
}
else{
G = G+ (2*dy);
}
}
cout<< "\n x = " << x;
cout<< "y = " << y;
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
j++;
}
glFlush();
}
void init(void)
{
glClearColor(0,0,0,0);
glColor3f(1.0,1.0,0.0);
gluOrtho2D(0,640,0,640);
glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc, char **argv)
{
cout<<"Enter x1,y1 point";
cin>>x_1>>y_1;
cout<<"Enter x2,y2 point";
cin>>x_2>>y_2;
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
glutInitWindowSize(0,600);
glutCreateWindow("BRESENHAM LINE ");
init();
//glutMouseFunc(mouse);
glutDisplayFunc(Line);
glutMainLoop();
return 0;
}
