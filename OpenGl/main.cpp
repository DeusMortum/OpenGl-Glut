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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);///Двойной буфер и РГБ
	glutInitWindowSize(300, 300);
	//glutInitWindowPosition(100, 100);

	glutCreateWindow("Приедь проц, приедь");
	engine = new Engine();
	engine->Init();
	///Регистрация
	glutMouseFunc(Mouses); //ус
	glutCreateMenu(MenuCheks); //Меню вызываемое нажатием ПКМ
	glutAddMenuEntry("Удалить последнюю точку", 0); //Пункт меню
	glutAddMenuEntry("Очистить", 1); //Пункт меню
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glClearColor(1, 1, 1, 1); //цвет фона (RGBA)
	glMatrixMode(GL_PROJECTION); //Определяем стек матриц (матрица проекций)
	glLoadIdentity(); //установить текущую матрицу равной еденичной

	glOrtho(0, 350, 0, 350, 0, 1); //Установить границы объема отсечения
	glColor3f(0, 0, 0); //Установить текущий цвет (R,G,B)


	glutSpecialFunc(MyKey);///кнопок
	glutDisplayFunc(display);///перерисовка окна
	glutReshapeFunc(reshape);///изменение размеров окна
	glutIdleFunc(display);///для анимации
	glutMainLoop();///обработка событий при простое
	return 0;
}
