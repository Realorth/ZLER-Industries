#include "disparoespecial.h"
#include "freeglut.h"

disparoespecial::disparoespecial():disparo()
{
	textura = "imagenes/AtaqueBolaFuego.png";
	SetNombre("Especial");
}
disparoespecial::disparoespecial(float x, float y) :disparo(x,y, "imagenes/AtaqueBolaFuego.png")
{
	SetNombre("Especial");
}
disparoespecial::disparoespecial(vector2D a) :disparo(a, "imagenes/AtaqueBolaFuego.png")
{
	SetNombre("Especial");
}
disparoespecial::disparoespecial(vector2D a, vector2D origen):disparo(a,origen, "imagenes/AtaqueBolaFuego.png")
{
	SetNombre("Especial");
}
disparoespecial::~disparoespecial()
{}



