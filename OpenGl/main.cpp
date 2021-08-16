#include "engine.h"

Engine *engine;

GLvoid MyKey(GLint key, GLint a, GLint b)
{
	engine->MyKeyboard(key, a, b);
}



GLvoid Mouses(GLint button, GLint state, GLint x, GLint y)
{
	engine->Mouse(button,  state,  x,  y);
}


GLvoid MenuCheks(GLint v)
{
	engine->MenuChek(v);
}


GLvoid display(GLvoid)
{
	
	engine->Draw();

	glutSwapBuffers();
}

GLvoid reshape(GLsizei width, GLsizei height)
{
	engine->Resize(width, height);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);///������� ����� � ���
	glutInitWindowSize(300, 300);
	//glutInitWindowPosition(100, 100);

	glutCreateWindow("������ ����, ������");
	engine = new Engine();
	engine->Init();
	///�����������
	glutMouseFunc(Mouses); //��
	glutCreateMenu(MenuCheks); //���� ���������� �������� ���
	glutAddMenuEntry("������� ��������� �����", 0); //����� ����
	glutAddMenuEntry("��������", 1); //����� ����
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glClearColor(1, 1, 1, 1); //���� ���� (RGBA)
	glMatrixMode(GL_PROJECTION); //���������� ���� ������ (������� ��������)
	glLoadIdentity(); //���������� ������� ������� ������ ���������

	glOrtho(0, 350, 0, 350, 0, 1); //���������� ������� ������ ���������
	glColor3f(0, 0, 0); //���������� ������� ���� (R,G,B)


	glutSpecialFunc(MyKey);///������
	glutDisplayFunc(display);///����������� ����
	glutReshapeFunc(reshape);///��������� �������� ����
	glutIdleFunc(display);///��� ��������
	glutMainLoop();///��������� ������� ��� �������
	return 0;
}
