/* 
 * File:   TextRect.cpp
 * Author: seh
 * 
 * Created on February 22, 2010, 11:05 AM
 */

#include "TextRect.h"


//        //draw font
//	{
//		int now = glutGet(GLUT_ELAPSED_TIME);
//
//		float n = (float) now / 20.;
//		float t1 = sin(n / 80);
//		float t2 = sin(n / 50 + 1);
//		float t3 = sin(n / 30 + 2);
//
//		float ambient[4] = { (t1 + 2.0) / 3, (t2 + 2.0) / 3, (t3 + 2.0) / 3,
//				0.3 };
//		float diffuse[4] = { 1.0, 0.9, 0.9, 1.0 };
//		float specular[4] = { 1.0, 0.7, 0.7, 1.0 };
//		float position[4] = { 100.0, 100.0, 0.0, 1.0 };
//
//		float front_ambient[4] = { 0.7, 0.7, 0.7, 0.0 };
//
//		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glEnable(GL_LIGHTING);
//		glEnable(GL_DEPTH_TEST);
//
//		glPushMatrix();
//		glTranslatef(-0.9, -0.2, -10.0);
//		glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
//		glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
//		glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
//		glLightfv(GL_LIGHT1, GL_POSITION, position);
//		glEnable(GL_LIGHT1);
//		glPopMatrix();
//
//		if (font == NULL) {
//			font = new FTExtrudeFont("media/font/DejaVuSans.ttf");
//			font->FaceSize(1);
//			font->CharMap(ft_encoding_unicode);
//		}
//
//		glPushMatrix();
//		glMaterialfv(GL_FRONT, GL_AMBIENT, front_ambient);
//		glColorMaterial(GL_FRONT, GL_DIFFUSE);
//		glTranslatef(5.0, 5.0, 20.0);
//		glRotatef(n / 1.11, 0.0, 1.0, 0.0);
//		glRotatef(0, 1.0, 0.0, 0.0);
//		glRotatef(0, 0.0, 0.0, 1.0);
//		glColor3f(1.0, 1.0, 1.0);
//		//drawText3D(font[fontindex], "SpaceGraph", 0, 0, 20.0);
//
//		font->Render("CRITTERGOD");
//
//		glPopMatrix();
//
//	}
