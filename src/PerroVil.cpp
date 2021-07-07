#include "PerroVil.h"

void PerroVil::gira()
{
	vector2D aux = GetVel();
	SetVel(0, 0);
	if (aux.x > 0)			SetPos(GetPos().x - 0.5f, 0);
	else if (aux.x < 0)		SetPos(GetPos().x + 0.5f, 0);
	SetVel(-aux.x, 0);
}

PerroVil::PerroVil(float x, float y) :
	Enemigos(x, y, "imagenes/wolfy.png",4)
{
	velocidad.x = 3.0f;
}

PerroVil::PerroVil(vector2D a):
	Enemigos(a,"imagenes/wolfy.png",4)
{
	velocidad.x =3.0f;
}

PerroVil::PerroVil():
	Enemigos(0,0, "imagenes/wolfy.png", 4)
{
	velocidad.x = 3.0f;
}

void PerroVil::ataca() {}
void PerroVil::reacciona()
{
	aceleracion.x = 0.002 + aceleracion.x * 1.2;			//Empieza a patrullar cada vez m�s r�pido
}