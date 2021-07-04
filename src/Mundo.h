#pragma once
#include "hombre.h"
#include "bonus.h"
#include "disparo.h"
#include "pared.h"
#include "disparoespecial.h"
#include "Vector3D.h"
#include "BonusCorazon.h"
#include "BonusArmadura.h"
#include "bonusBolaFuego.h"
#include "fondo.h"
#include "plataforma.h"
#include "suelo.h"
#include "ListaCoins.h"
#include "coin.h"
#include <string>
#include <iostream>
#include "ListaArmaduras.h"
#include "ListaCorazones.h"
#include "ListaBolaFuego.h"

class Mundo
{
public:
	//Enumeracion para saber que mundo se va a generar
	enum tipo { CEMENTERIO = 0, NIEVE, BASICO };

public: 
	Mundo();
	virtual ~ Mundo();
	void tecla(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char key);
	void teclaEspecialUp(unsigned char key);
	int getnCoin() { return ncoin; }
	bool getImpacto() { return impacto; }
	void setImpacto(bool i) { impacto = i; }
	bool getcaida() { return caida; }
	void setcaida(bool c) { caida = c; }
	Vector3D getOjo() { return Vector3D(x_ojo, y_ojo, z_ojo); }
private:
	Vector3D ojo;
    float x_ojo;
	float y_ojo;
	float z_ojo;
	bool impacto=false;
	bool caida = false;
	int ncoin = 0;//Numero de monedas de cada partida
   // esfera esfera2;
	//disparo disparo1;
	//esfera esfera1;
	hombre hombre;
//	caja caja;
	//bonus bonus;
	//pared plataforma;

	listadisparos disparos;

	disparoespecial disparogrande;

	coin moneda1;
	coin moneda2;
	BonusCorazon corazon;
	BonusArmadura armadura;
	bonusBolaFuego bolaFuego;
	ListaArmaduras listaArmaduras;
	ListaCorazones listaCorazones;
	ListaBolaFuego listaBFuego;
	ListaCoins listaCoins;
	// Se crean instancias para cada parte del mundo
	suelo Suelos;
	plataforma Plataformas;
	fondo Fondo;

	tipo ptipo=tipo::CEMENTERIO;//Guarda el tipo de mapa

private:
	// Funciones privadas para la generacion de mundo
	void Genera();

};
