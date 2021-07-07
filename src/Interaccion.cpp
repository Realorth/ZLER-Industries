#include "Interaccion.h"
#include <math.h>
#include <iostream>

Interaccion::~Interaccion()
{
}
bool Interaccion::colision(disparo d, pared p)
{
	vector2D pos =d. GetPos();
	if ((pos.y >= p.limite1.y)&& (pos.x > p.limite1.x)&&(pos.x < p.limite2.x))
		return true;
	
	return false;
}
void Interaccion::colision(hombre& h, pared p)
{

	vector2D dir;
	float dif = p.distancia(h.posicion, &dir) -h.altura / 10;
	if (dif <= 0.0f)
	{
		//vector2D v_inicial = h.velocidad;
		h.velocidad.y=0 ;
		h.posicion = h.posicion - dir * dif;
		h.posicion.y += 0.001f;
	}
}
void Interaccion::rebote(hombre& h, std::vector<pared*> d)
{
	for (auto i : d)
		colision(h, *i);
	if (h.GetPos().x < -3.5)
		h.SetPos(-3.5, h.GetPos().y);
	if (h.GetPos().x > 293)
		h.SetPos(293,h.GetPos().y);
}

void Interaccion::rebote(Enemigos& e, std::vector<pared*> d)
{
	Enemigos aux(e);

	aux.SetVel(0, 0);
	int sentido = (e.GetVel().x > 0) ? 1 : -1;
	aux.SetPos(e.GetPos().x + 0.5f * sentido, e.GetPos().y );
	//aux.mueve(0.25);

	for (auto i : d)
		colision(e, *i);
	for (auto i : d)
		colision(aux, *i);
		
		
	bool girar = (roundf((e.GetPos().y-aux.GetPos().y)*1000)>0);
	if (girar/* aux.GetPos().y < e.GetPos().y*/) {
		e.SetVel(e.GetVel().x*(-1),e.GetVel().y);
	}


	if (e.GetPos().x < -3.5) {
		e.SetPos(-3.5, e.GetPos().y);
		e.SetVel(e.GetVel().x * (-1), e.GetVel().y);
	}
		
	if (e.GetPos().x > 293) {
		e.SetPos(293, e.GetPos().y);
		e.SetVel(e.GetVel().x * (-1), e.GetVel().y);
	}
	
	

	
}
bool Interaccion::colision(Enemigos& e, pared p)
{
	vector2D dir;
	float dif = p.distancia(e.GetPos(), &dir) - 0.1f;
	if (dif <= 0.0f)
	{
		//vector2D v_inicial = h.velocidad;
		e.SetVel(e.GetVel().x, 0);
		e.SetPos(e.GetPos() - dir * dif);
		e.SetPos(e.GetPos().x, e.GetPos().y += 0.001f);
		return true;
	}
	return false;

}
bool Interaccion::colision(hombre h, bonus& b)
{
	vector2D pos = h.GetPos(); //la posicion de la base del hombre
	vector2D posBonus = b.GetPos();
	pos.y += h.GetAltura() / 2.0f; //posicion del centro
	float distancia = (posBonus - pos).modulo();
	if (distancia < 1.0f)
		return true;
	return false;
}
bool Interaccion::colision(hombre h, coin c)
{
	vector2D pos = h.GetPos(); //la posicion de la base del hombre
	vector2D posMoneda = c.GetPos();
	pos.y += h.GetAltura() / 2.0f; //posicion del centro
	float distancia = (posMoneda - pos).modulo();
	if (distancia < 1.0f)
		return true;
	return false;

}
bool Interaccion::muertecaida(hombre h)
{
	vector2D m = h.GetPos();
	if (m.y < -7.0f)
		return true;
	return false;
}
bool Interaccion::colision(objetomovil& e, pared p)
{
	vector2D dir;
	float dif = p.distancia(e.GetPos(), &dir) - 0.1f;
	if (dif <= 0.0f)
	{
		//vector2D v_inicial = h.velocidad;
		e.SetVel(e.GetVel().x, 0);
		e.SetPos(e.GetPos() - dir * dif);
		e.SetPos(e.GetPos().x, e.GetPos().y += 0.001f);
		return true;
	}
	return false;
}
bool Interaccion::colision(hombre& h, Enemigos& e)
{
	vector2D pos = h.GetPos(); //la posicion de la base del hombre
	vector2D posEnemigo = e.GetPos();
	pos.y += h.GetAltura() / 2.0f; //posicion del centro
	float distancia = (posEnemigo - pos.y).modulo();
	if (distancia < (e.GetTam()).modulo() / 2 + 1.0f)
		return true;
	return false;
}
bool Interaccion::proximidad(hombre& h, Enemigos& e) {
	vector2D pos = h.GetPos() - e.GetPos();
	if (pos.modulo() < e.GetRango()) return true;						//si el hombre está a rango
	else return false;
}
bool Interaccion::deteccion(hombre& h, Enemigos& e) {
	vector2D pos = h.GetPos() - e.GetPos();
	if (pos.x > 0) return true;									//si el hombre está a la derecha
	else return false;
}
