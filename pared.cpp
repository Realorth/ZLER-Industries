#include "pared.h"
#include "freeglut.h"
#include "vector2D.h"
#include"ETSIDI.h"
pared::pared():color(0,0,200)
{	
}
pared::~pared()
{}

void pared::dibuja()
{
	// TODO: Agregar aqu� el c�digo de implementaci�n.
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, ancho);
	glVertex3d(limite2.x, limite2.y, ancho);
    glVertex3d(limite2.x, limite2.y, -ancho);
	glVertex3d(limite1.x, limite1.y, -ancho);
	glEnd();
	glEnable(GL_LIGHTING);

}
void pared::SetColor(Byte r, Byte v, Byte b) {
	color.set(r, v, b);
}
void pared::SetPos(float x1, float y1, float x2, float y2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
//Calculo de distancia de una pared a un punto, adicionalmente
//se modifica el valor de un vector direccion opcional que contendr�
//el vector unitario saliente que indica la direccion de la
//recta m�s corta entre el punto y la pared.
float pared::distancia(vector2D punto, vector2D* direccion)
{
	vector2D u = (punto - limite1);
	vector2D v = (limite2 - limite1).unitario();
	float longitud = (limite1 - limite2).modulo();
	vector2D dir;
	float valor = u * v;
	float distancia = 0;

	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;

	distancia = dir.modulo();

	if (direccion != 0) //si nos dan un vector�
		*direccion = dir.unitario();
	return distancia;
}