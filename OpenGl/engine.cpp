#include "engine.h"
GLuint  texture[6]; ///����� �������
GLfloat xrot;          /// �������� X
GLfloat yrot;          /// Y
bool keys[256];  ///������
int parm = 0;
float px0, px1, px2, px3, py0, py1, py2, py3, xt, yt;
struct point { float x, y; } P[350];
int n = 0, i, j;
bool tP = false;

int LoadGLTextures()                                    
{
	
	texture[0] = SOIL_load_OGL_texture ///�������� �������
	(
		"text1.jpg",
		SOIL_LOAD_AUTO,///�����������  �� �����
		SOIL_CREATE_NEW_ID,///����� �������������
		SOIL_FLAG_INVERT_Y/// ����������� ��� y �����������
		///����� ��� ������� ����������� ��������, ������� � ������ �������� ����,
		///� OpenGL ���������� ������ ����������� � ����� ������ ����
	);
	texture[1] = SOIL_load_OGL_texture
	(
		"text2.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	texture[2] = SOIL_load_OGL_texture
	(
		"text3.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	texture[3] = SOIL_load_OGL_texture
	(
		"text4.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	texture[4] = SOIL_load_OGL_texture
	(
		"text5.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	texture[5] = SOIL_load_OGL_texture
	(
		"text6.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	if (texture[0] == 0 && texture[1] == 1 && texture[2] == 2 && texture[3] == 3 && texture[4] == 4 && texture[5] == 5)
		return false;



	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	///���������� ��������
	///������� ������� ��������� � ���������� ����������� ��������

	return true;                                        
}

GLvoid Engine::SetProjectionMatrix(GLvoid){

	//glMatrixMode(GL_PROJECTION);						
	//glLoadIdentity();									/// ������� ������� ������������ �� ���������
	//gluPerspective(45.0f, 1.5f, 0.1f, 100.0f);
	// ��������� � ������� ��������
	//glMatrixMode(GL_MODELVIEW);					
}

GLvoid Engine::SetModelviewMatrix(GLvoid){
//	glMatrixMode(GL_MODELVIEW);							/// ������� ������
//	glLoadIdentity();									/// ������� ������� ������������ �� ���������
	//glTranslatef(0.0, 0.0, -8.0);																	
//glRotatef(30.0, 1.0, 0.0, 0.0);
}

GLvoid Engine::Resize(GLsizei width, GLsizei height){
	if (height == 0)									
	{
		height = 1;										
	}

	glViewport(0, 0, width, height);					///  ������� ���������

	Height = height;
	Width = width;

	SetProjectionMatrix();
	SetModelviewMatrix();
}

GLvoid Engine::Init(GLvoid){
	//LoadGLTextures();           // �������� �������
//	glEnable(GL_TEXTURE_2D);
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);				///  ����� ���
//	glClearDepth(1.0f);									/// �������� ��� ���������� ������ ������� �� ���������
														
//	glEnable(GL_DEPTH_TEST);							/// ���������� ���� �������
	//glDepthFunc(GL_LEQUAL);								/// ��������, ������������  � ���������� ��� ������������� ������ �������
														


//	glShadeModel(GL_SMOOTH);							///  ������� ���������
	//glEnable(GL_LINE_SMOOTH);							///  ����������� �����
	//glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);				///  ������������ ����� ����������� ��� �����
													
//	glEnable(GL_BLEND);									/// ���������� �������� ������, �����������
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	/// ��� ������ ����������� � �������� ������ ��������
														
}

GLvoid Engine::MyKeyboard(GLint key, GLint a, GLint b)
{

	switch (key)
	{


	case 100: yrot += 0.7; break;
	case 102: yrot -= 0.7; break;
	case 103: xrot += 0.7; break;
	case 101: xrot -= 0.7; break;



	}

	/*101= �����
		102 = ����
		100 �����
		103 ������*/
}











GLvoid Engine::Mouse(GLint button, GLint state, GLint x, GLint y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (tP && (x > 0 && x < 350) && (350 > y && y < 700)) {
			P[j].x = x;
			P[j].y = 350 - y;
		}
		else if (state == GLUT_DOWN && n != 0 && !tP)
			for (i = 0; i <= n; i++)
				if ((x<P[i].x + 30 && x>P[i].x - 30) && (320 - y<P[i].y && 380 - y>P[i].y)) {
					tP = true;
					j = i;
					break;
				}
		if (state == GLUT_UP) {
			if (!tP) {
				P[n].x = x;
				P[n].y = 350 - y;
				n++;
			}
			tP = false;
		}
	}
	glutPostRedisplay(); //�������� ������� ����
}

GLvoid Engine::MenuChek(GLint v) {
	if (v == 0 && n > 0)
		n--;
	else if (v == 1)
		n = 0;
	glutPostRedisplay(); //�������� ������� ����
}

GLvoid Engine::Line() {
	glPointSize(5);
	glColor3f(0, 0, 0);

	//����������� �����
	glBegin(GL_POINTS);
	for (i = n - 1; i >= 0; i--)
		glVertex2f(P[i].x, P[i].y);
	glEnd();

	//���������� �����
	glLineStipple(2, 58360);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	for (i = 0; i < n - 1; i++) {
		glVertex2f(P[i].x, P[i].y);
		glVertex2f(P[i + 1].x, P[i + 1].y);
	}
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	glPointSize(1);
}

GLvoid Engine::CurveBezier() {
	float px0, px1, px2, px3, py0, py1, py2, py3, xt, yt;
	for (i = 1; i < n - 2; i++) {
		px0 = (P[i - 1].x + 4 * P[i].x + P[i + 1].x) / 6.0;
		px1 = (-P[i - 1].x + P[i + 1].x) / 2.0;
		px2 = (P[i - 1].x - 2 * P[i].x + P[i + 1].x) / 2.0;
		px3 = (-P[i - 1].x + 3 * P[i].x - 3 * P[i + 1].x + P[i + 2].x) / 6.0;

		py0 = (P[i - 1].y + 4 * P[i].y + P[i + 1].y) / 6.0;
		py1 = (-P[i - 1].y + P[i + 1].y) / 2.0;
		py2 = (P[i - 1].y - 2 * P[i].y + P[i + 1].y) / 2.0;
		py3 = (-P[i - 1].y + 3 * P[i].y - 3 * P[i + 1].y + P[i + 2].y) / 6.0;

		glColor3f(1, 0, 0);
		glPointSize(2);
		glBegin(GL_POINTS);
		for (float t = 0.0; t <= 1.0; t += 0.001) {
			xt = ((px3*t + px2)*t + px1)*t + px0;
			yt = ((py3*t + py2)*t + py1)*t + py0;
			glVertex3f(xt, yt, 0);
		}
		glEnd();
	}
}








GLvoid Engine::Draw(GLvoid)									
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -5.0f);
//	glRotatef(xrot, 1.0f, 0.0f, 0.0f);     /// �������� �� ��� X
	//glRotatef(yrot, 0.0f, 1.0f, 0.0f);     /// �������� �� ��� Y

	
	Line();
	if (n > 3)
		CurveBezier();
	glutSwapBuffers();










	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -5.0f);
	//glRotatef(xrot, 1.0f, 0.0f, 0.0f);     /// �������� �� ��� X
	//glRotatef(yrot, 0.0f, 1.0f, 0.0f);     /// �������� �� ��� Y

	//glBindTexture(GL_TEXTURE_2D, texture[0]);
	//glBegin(GL_QUADS);/// �������� �����
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  /// ��� ����
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);  /// ��� �����
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);  /// ���� �����
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  /// ���� ����
	//glEnd();

	//glBindTexture(GL_TEXTURE_2D, texture[1]);		
	//glBegin(GL_QUADS);/// ������ �����
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); /// ��� �����
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  /// ���� �����
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);  /// ���� ����
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);  /// ��� ����
	//glEnd();

	//glBindTexture(GL_TEXTURE_2D, texture[2]);
	//glBegin(GL_QUADS);/// ������� �����
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  /// ���� ����
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  /// ��� ����
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);  /// ��� �����
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);  /// ���� �����
	//glEnd();

	//glBindTexture(GL_TEXTURE_2D, texture[3]);		
	//glBegin(GL_QUADS);/// ������ �����
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  /// ���� �����
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);  /// ���� ����
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);  /// ��� ����
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  /// ��� �����
	//glEnd();

	//glBindTexture(GL_TEXTURE_2D, texture[4]);	
	//glBegin(GL_QUADS);/// ������ �����
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);  /// ��� �����
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);  /// ���� �����
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);  /// ���� ����
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);  /// ��� ����
	//glEnd();

	//glBindTexture(GL_TEXTURE_2D, texture[5]);
	//glBegin(GL_QUADS);////// ����� �����
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  /// ��� ����
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  /// ��� �����
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);  /// ���� �����
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  /// ���� ����
	//glEnd();


						
}


