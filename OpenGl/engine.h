#include "api.h"

#ifndef __ENGINE
#define __ENGINE

class Engine {
	GLsizei Height, Width;
	GLvoid SetProjectionMatrix(GLvoid);						/// ������� ������������ ��������������
	GLvoid SetModelviewMatrix(GLvoid);						/// ������� �������������� ������-����

public:

	GLvoid Resize(GLsizei width, GLsizei height);			/// �������, ���������� ��� ��������� �������� ����
	GLvoid Init(GLvoid);									/// �������, ��� ������� ��������� ����������
	GLvoid Draw(GLvoid);									/// �������, ���������
	GLvoid MyKeyboard(GLint key, GLint a, GLint b);			/// �������, ������� ������
	// ��������� (render) �����
	
	GLvoid Mouse(GLint button, GLint state, GLint x, GLint y);
	GLvoid MenuChek(GLint v);
	GLvoid CurveBezier();
	GLvoid Line();
};

#endif