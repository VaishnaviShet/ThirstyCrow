#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>
#include<string.h>
#define PI 3.142

float x =-6 ;float x2 = -5; //for crow movement 
float y = -6;  float y2 = -3; // for crow movement when it sees the pot

float a = 0, b = -5, c = -5;

float z = -2.6, z1 = -3;

float x3 =2.6, y3= -3 ;//for scene 7 to take crow out of the screen





float scene_decide=0;
float next = 1;
float i=5;


void crow_moving(int, int);
void scene1();
void scene2();
void scene3();
void scene4();
void scene5();
void scene6();
void scene7();
void scene8();

void draw_crow() {

   glColor3f(0.1,0.2,0.1);
   glScalef(0.5, 0.5, 0.5);
//body
   glBegin(GL_POLYGON);
      glVertex2f(-2.5, -1.5);
      glVertex2f(-1.5, -1.3);
      glVertex2f(0.5,-0.5);
      glVertex2f(1.5,0);
      glVertex2f(2.0,3);
      glVertex2f(1.6,3.9);
      glVertex2f(0,3);
      glVertex2f(-1.5, 1);
   glEnd();
   
//beak
   glColor3f(0.1, 0.1,0.1);
   glBegin(GL_POLYGON);
      glVertex2f(1.8,2.7); 
      glVertex2f(2,3);
      glVertex2f(2.8,2.5); 
   glEnd();

   glColor3f(0.2, 0.2,0.2);
      glBegin(GL_POLYGON);
      glVertex2f(1.7,2.6);
      glVertex2f(2.8,2.5);
      glVertex2f(1.8,2.2);
   glEnd();

//leg
   glLineWidth(4);
   glBegin(GL_LINES);
      glVertex2f(-0.2,-0.7);
      glVertex2d(-0.1, -1.5);

      glVertex2d(-0.1, -1.5);
      glVertex2d(-0.2, -1.8);

      glVertex2d(-0.1, -1.5);
      glVertex2d(0.1, -1.8);
   glEnd();

   glTranslatef(1,0.5,0);
   glBegin(GL_LINES);
      glVertex2f(-0.2,-0.7);
      glVertex2d(-0.1, -1.5);

      glVertex2d(-0.1, -1.5);
      glVertex2d(-0.2, -1.8);

      glVertex2d(-0.1, -1.5);
      glVertex2d(0.1, -1.8);
   glEnd();

   glColor3f(1,1,1);
   glPointSize(10);
   glBegin(GL_POINTS);
      glVertex2f(0.3,2.6);
   glEnd();

//feather
}

void ground(void){
   glColor3f(0,1,0);
   glBegin(GL_POLYGON);
      glVertex2f(-5,0);
      glVertex2f(5,0);
      glVertex2f(5,-5);
      glVertex2f(-5,-5);
   glEnd();
}

void sky(void){
   glColor3f(0,0,1);
   glBegin(GL_POLYGON);
      glVertex2f(-5,0);
      glVertex2f(-5,5);
      glVertex2f(5,5);
      glVertex2f(5,0);
   glEnd();
}

void draw_house(void){
   glColor3f(1,1,0);
   glBegin(GL_POLYGON);
      glVertex2f(-1, 0);
      glVertex2f(1,0);
      glVertex2f(1,2);
      glVertex2f(-1,2);
   glEnd();

   glBegin(GL_POLYGON);
      glVertex2f(1,0);
      glVertex2f(3,0);
      glVertex2f(3,2);
      glVertex2f(2,3);
      glVertex2f(1,2);
   glEnd();

   glColor3f(0.8,0,0);
   glBegin(GL_POLYGON);
      glVertex2f(-1,2);
      glVertex2f(1,2);
      glVertex2f(2,3);
      glVertex2f(0,3);
   glEnd();

   //door
   glColor3f(1,0.4,0);
   glBegin(GL_POLYGON);
      glVertex2f(1.5,0);
      glVertex2f(1.5,1.5);
      glVertex2f(2.5,1.5);
      glVertex2f(2.5,0);
   glEnd();

   //window
   glBegin(GL_POLYGON);
      glVertex2f(-0.5,0.5);
      glVertex2f(0.5,0.5);
      glVertex2f(0.5,1.5);
      glVertex2f(-0.5,1.5);
   glEnd();

   glBegin(GL_POLYGON);
      glVertex2f(1.8,2);
      glVertex2f(2.1,2);
      glVertex2f(2.1,2.3);
      glVertex2f(1.8,2.3);
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_LINES);
      glVertex2f(-1,2);glVertex2f(-1,0);
      glVertex2f(-1,0);glVertex2f(3,0);
      glVertex2f(3,2);glVertex2f(2,3);
      glVertex2f(3,0);glVertex2f(3,2);
      glVertex2f(1,2);glVertex2f(1,0);
   glEnd();
}


void draw_sun(int rad=1, float pos_x=0, float pos_y=0){
   glColor3f(1, 0.647, 0);
   glBegin(GL_POLYGON);
      for(int i=0; i<360; i++){
         float deg = i*PI/180;
         glVertex2f(pos_x+rad*sin(deg), pos_y+rad*cos(deg));
      }
   glEnd();

}

void Draw_Tree(void){
      glColor3f(0.5,1.0,0.1);
    //glScalef(0.5, 0.5, 0.5);

    //branch
    glBegin(GL_POLYGON);
      glVertex2f(0.0, 4.0);
      glVertex2f(2.0, 2.0);
      glVertex2f(1.0,2.0);
      glVertex2f(3.0,0.0);
      glVertex2f(2.0,0.0);
      glVertex2f(4.0,-2.0);

      glVertex2f(-4.0,-2.0);
      glVertex2f(-2.0, 0.0);
      glVertex2f(-3.0,0.0);
      glVertex2f(-1.0,2.0);
      glVertex2f(-2.0,2.0);
      glEnd();

      //stem
      glColor3f(0.588,0.294,0.1);
       glBegin(GL_POLYGON);
       glVertex2f(0.5,-2.0);
      glVertex2f(0.5, -4.0);
      glVertex2f(-0.5,-4.0);
      glVertex2f(-0.5,-2.0);
   glEnd();

  glColor3f(0.1,0.1,0.1);
  glBegin(GL_LINES);
      glVertex2f(0, 4.0);glVertex2f(2.0, 2.0);
      glVertex2f(2.0, 2.0);glVertex2f(1.0,2.0);
      glVertex2f(1.5,2.0);glVertex2f(3.0,0.0);
      glVertex2f(3.0,0.0);glVertex2f(2.0,0.0);
      glVertex2f(2.6,0.0);glVertex2f(4.0,-2.0);

      glVertex2f(4.0,-2.0);glVertex2f(-4.0,-2.0);
      glVertex2f(-4.0,-2.0);glVertex2f(-2.6,0.0);
      glVertex2f(-2.0,0.0);glVertex2f(-3.0,0.0);
      glVertex2f(-3.0,0.0);glVertex2f(-1.5,2.0);
      glVertex2f(-1.0,2.0);glVertex2f(-2.0,2.0);
      glVertex2f(-2.0,2.0);glVertex2f(0.0,4.0);

      glVertex2f(0.5,-2.0);glVertex2f(0.5, -4.0);
      glVertex2f(0.5, -4.0);glVertex2f(-0.5,-4.0);
      glVertex2f(-0.5,-4.0);glVertex2f(-0.5,-2.0);
      glVertex2f(-0.5,-2.0);glVertex2f(0.5,-2.0);
glEnd();

}


void mountain(){
   glColor3f(.588,0.294, 0);
      glBegin(GL_POLYGON);
         glVertex2f(-1, 0);
         glVertex2f(-0.2, 1);
         glVertex2f(0.8,0);
      glEnd();

      glBegin(GL_POLYGON);
         glVertex2f(0.2, 0);
         glVertex2f(0.8, 0.6);
         glVertex2f(1.4,0);
      glEnd();

   
   glColor3f(0,0,0);
   glBegin(GL_LINE_STRIP);
         glVertex2f(-1, 0);
         glVertex2f(-0.2, 1);
         glVertex2f(0.8,0);
   glEnd();

   glBegin(GL_LINE_STRIP);
         glVertex2f(0.2, 0);
         glVertex2f(0.8, 0.6);
         glVertex2f(1.4,0);
      glEnd();

}




//draw circle
void pot(void){
   
   glColor3f(0.588, 0.294, 0);
   glBegin(GL_POLYGON);
      glVertex2f(sin(31*PI/180), cos(31*PI/180));
      glVertex2f(sin(29*PI/180), cos(35*PI/180)+1);
      glVertex2f(sin(329*PI/180), cos(329*PI/180)+1);
      glVertex2f(sin(329*PI/180), cos(329*PI/180));
   glEnd();

   glBegin(GL_POLYGON);
   for(int i=30; i<330; i++){
      float deg = i*3.14/180;
      glVertex2f(sin(deg), cos(deg));
   }
   glEnd();

   glColor3f(0,0,0);
   glLineWidth(2);
   glBegin(GL_LINE_STRIP);
      glVertex2f(sin(31*PI/180), cos(31*PI/180));
      glVertex2f(sin(29*PI/180), cos(35*PI/180)+1);
      glVertex2f(sin(329*PI/180), cos(329*PI/180)+1);
      glVertex2f(sin(329*PI/180), cos(329*PI/180));
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_LINES);
   for(int i=30; i<330; i++){
      float deg = i*3.14/180;
      glVertex2f(sin(deg), cos(deg));
   }
   glEnd();

}

void draw_stones(int pos_x, int pos_y ){
   glColor3f(0.2, 0.1, 0.1);
   glPointSize(5);
   glBegin(GL_POINTS);
      glVertex2f(pos_x, pos_y);
   glEnd();
}

void display(void) {
   glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(1,1,1,1); 

   if(scene_decide == 1){ //start simulation 
      scene1(); //opening scene
   }
   else if(scene_decide==2) {
      exit(0);
   }
   
   if(next == 1){
      scene1();
   }
   if(next==2){
      scene2();
   }
   if(next==3){
      scene3();
   }
   if(next==4){
      scene4();
   }
   if(next==5){
      scene5();
   }
   if(next==6){
      scene6();
   }
   if(next == 7){
      scene7();
   }
   if(next==8){
      scene8();
   }
   if(next==9){
      exit(0);
   }
  // draw_stones(-3, -3);

   glutSwapBuffers();
   glutPostRedisplay();
   glFlush();
}


 

void reshape(int w, int h) {
   glClearColor(0,0,0, 1);
   glViewport(0,0,w,h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      gluOrtho2D(-5, 5, -5*(GLfloat)h / (GLfloat)w,5*(GLfloat)h / (GLfloat)w);
   else
   {
      gluOrtho2D(-5*(GLfloat)w / (GLfloat)h,5*(GLfloat)w / (GLfloat)h, -5, 5);
   }
   glMatrixMode(GL_MODELVIEW);
   // glLoadIdentity();
   glutPostRedisplay();
   glFlush();
}

void keyboard(unsigned char key, int x, int y){
   if(key == 'n'){ //to go next
      next++;
   }
   else if(key == 'b'){ // to go back
      next--;
   }

   }

void mouse (int button, int state, int x, int y){
   if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
      scene_decide = 1; //start the simulation
   } 

     if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      scene_decide = 2; //stop
   } 
   
}

// void myinit(){
//     glClearColor(1, 1,1, 1);
//     gluOrtho2D(-5, 5,-5, 5);
//  }

int main(int argc, char** argv) {
   glutInit(&argc, argv);          
   glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
   glutInitWindowSize(900, 900);  
   glutInitWindowPosition(0,0); 
  
   glutCreateWindow("OpenGL Setup Test");
   // myinit();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape); 
   glutKeyboardFunc(keyboard);
   glutMouseFunc(mouse);
   glutMainLoop();  
   return 0;
}


void scene1(){
   // this is for displaying texts
   
   char title[] = {"Where there is a will, there is a way."};
   char name1[] = {"--Vaishnavi(4CB18CS107)"};
   char name2[] = {"  Vainidhi(4CB18CS106)"};

   char info1[] = {"Click 'n' to go to next scene"};
   char info2[] = {"Click 'b' to go to previous scene"};

   char stop[] ={"To Stop the simulation, just 'Right click'. "};

   glColor3f(0.2,0.3,0.22);
	glRasterPos2f(-2.5,2.5);
	for(int k=0;k<strlen(title);k++)
        	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,title[k]);

   glRasterPos2f(1,1.5);
	for(int k=0;k<strlen(name1);k++)
        	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,name1[k]);

   glRasterPos2f(1.2,1);
	for(int k=0;k<strlen(name2);k++)
        	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,name2[k]);

   glRasterPos2f(-2.5,-2.5);
	for(int k=0;k<strlen(info1);k++)
        	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,info1[k]);

   glRasterPos2f(-2.5,-2.9);
	for(int k=0;k<strlen(info2);k++)
        	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,info2[k]);

   glRasterPos2f(-2.5,-3.5);
	for(int k=0;k<strlen(stop);k++)
        	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,stop[k]);

   
   glutPostRedisplay();
   glFlush();


}

void scene2(){
   sky();
   ground();

   glPushMatrix();
      glScalef(5,5,0);
      mountain();
   glPopMatrix();


   glPushMatrix();
      glTranslatef(2,-1,0);
      glScalef(0.8,0.8,0);
      draw_house();
   glPopMatrix();

   glPushMatrix();
      glTranslatef(2,-1,0);
      draw_sun(1,-5,5);
   glPopMatrix();

   glPushMatrix();
      glScalef(0.5,0.5,0);
      glTranslatef(-5,0,0);
      Draw_Tree();
   glPopMatrix();

   //glutSwapBuffers(); // this lines gives error
   glutPostRedisplay();
   glFlush();

}

void scene3(){
   //crow is searching for water

   
   sky();
   ground();

   glPushMatrix();
      glTranslatef(-2,-1,0);
      draw_sun(0.2,-5,5);
   glPopMatrix(); 

   glPushMatrix();
      glScalef(5,5,0);
      glTranslatef(a,0,0);
      mountain();
   glPopMatrix();
   a-=0.05;
   if(a<-5){
      a=1.5;
   }


   glPushMatrix();
      glScalef(0.5,0.5,0);
      glTranslatef(b,2,0);
      Draw_Tree();
   glPopMatrix();
   b-=0.18;
   if(b<-15){
      b=11;
   }

   glPushMatrix();
      glScalef(0.4,0.8,0);
      glTranslatef(c,-2,0);
      Draw_Tree();
   glPopMatrix();
   c-=0.23;
   if(c<-15){
      c=15;
   }


   glPushMatrix();
      glTranslatef(0,-4,0);
      crow_moving(1,1);
   glPopMatrix();

}

void scene4(){
// sees the pot
   sky();
   ground();

   glPushMatrix();
      glScalef(5,5,0);
      mountain();
   glPopMatrix();

   glPushMatrix();
      glTranslatef(2,-1,0);
      glScalef(0.8,0.8,0);
      draw_house();
   glPopMatrix();

   glPushMatrix();
      glTranslatef(2,-1,0);
      draw_sun(1,-5,5);
   glPopMatrix();

   glPushMatrix();
      glScalef(0.5,0.5,0);
      glTranslatef(-5,0,0);
      Draw_Tree();
   glPopMatrix();

   glPushMatrix();
      glScalef(0.4,0.8,0);
      glTranslatef(-6,-3,0);
      Draw_Tree();
   glPopMatrix();

   glPushMatrix();
      glScalef(1.3,1,0);
      glTranslatef(3,-4, 0);
      pot();
   glPopMatrix();

   //get the crow near the pot
   

   glPushMatrix();
      glScalef(0.9, 0.9, 0);
      glTranslatef(y,y2, 0 );
      draw_crow();
   glPopMatrix();
      if(y<=1.5){
          y+=0.1;
          y2 +=0.1;
      }
      else{
         if(y2>-3){
            y+=0.02;
            y2-=0.15;
         }
      }

   draw_stones(1,-3);
   draw_stones(0.5, -2.5);
   draw_stones(-3.3,-4.50);

}


void scene5(){
   sky();
   ground();

   glPushMatrix();
      glScalef(5,5,0);
      mountain();
   glPopMatrix();

   glPushMatrix();
      glTranslatef(2,-1,0);
      glScalef(0.8,0.8,0);
      draw_house();
   glPopMatrix();

   glPushMatrix();
      glScalef(0.5,0.5,0);
      glTranslatef(-5,0,0);
      Draw_Tree();
   glPopMatrix(); 

   glPushMatrix();
      glTranslatef(2,-1,0);
      draw_sun(1,-5,5);
   glPopMatrix();

   
   glPushMatrix();
      glScalef(1.3,1,0);
      glTranslatef(3, -4, 0);
      pot();
   glPopMatrix();

  
   draw_stones(-4, -4);
   draw_stones(-3.3,-4.5);
   draw_stones(-3.7, -4.1);

// get the crow near stones
   glPushMatrix();
      glScalef(-1, 1,0);
      glTranslatef(z, -3, 0);
      draw_crow();
   glPopMatrix();
   if(z<3){
      z+=0.2;
   }

   // if(z>=3){
   //       glScalef(-1, 1, 0);
   //       glPushMatrix();
   //       glScalef(0.9, 0.9, 0);
   //          glTranslatef(z1,-3, 0 );
   //          draw_crow();
   //       glPopMatrix();
   //       if(z1<=2.6){
   //          z1+=0.1;
   //       }
   // }

}

void scene6(){
   //take crow back near pot
sky();
   ground();

   glPushMatrix();
      glScalef(5,5,0);
      mountain();
   glPopMatrix();

   glPushMatrix();
      glTranslatef(2,-1,0);
      glScalef(0.8,0.8,0);
      draw_house();
   glPopMatrix();

   glPushMatrix();
      glScalef(0.5,0.5,0);
      glTranslatef(-5,0,0);
      Draw_Tree();
   glPopMatrix(); 

   glPushMatrix();
      glTranslatef(2,-1,0);
      draw_sun(1,-5,5);
   glPopMatrix();

   
   glPushMatrix();
      glScalef(1.3,1,0);
      glTranslatef(3, -4, 0);
      pot();
   glPopMatrix();

  
   draw_stones(-4, -4);
   draw_stones(-3.3,-4.5);
   draw_stones(-3.7, -4.1);

   
   glPushMatrix();
      glScalef(0.9, 0.9,  0);
      glTranslatef(z1,-3, 0 );
      draw_crow();
   glPopMatrix();
   if(z1<=2.6){
      z1+=0.1;
   }

}

void scene7(){
  scene2();
  glPushMatrix();
      glScalef(1.3,1,0);
      glTranslatef(3, -4, 0);
      pot();
   glPopMatrix();

   glPushMatrix();
      glScalef(0.9, 0.9, 0);
      glTranslatef(x3,y3,0 );
      draw_crow();
   glPopMatrix();

   if(x3<7){
      x3+=0.2;
      y3+=0.2;
   }

}

void scene8(){
   char message[] = {"Thank you"};

   glColor3f(0,0,0);
   glRasterPos2f(0,0);
   for(int k=0; k<strlen(message); k++){
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[k]);
   }
   
 }


void crow_moving(int size_x, int size_y){

   // glPushMatrix();
   // glScalef(size_x,size_y,0);
   // glTranslatef(x, 0, 0);
   // // glRotatef(10, 0, 0.5, 0);
   // draw_crow();
   // glPopMatrix();
   // x=x+0.02;

   // if(x>5){
   //    x=-6;
   // }


   // if(y<2.6){
   x2+=0.03;
      glPushMatrix();
         glScalef(0.9, 0.9,0);
         glTranslatef(x, 0, 0);
         glTranslatef(0, x2, 0);
         draw_crow();
      glPopMatrix();

      x+=0.02;
      x2-=0.05;

      if(x>5){
         x=-6;
      }
      if(x2<5){
         x2+=0.5;
      }


}

