#pragma once
#include "Entidad.h"

class Obstaculo : public Entidad
{
public:
	Obstaculo()
	{
		x = rand() % 200;
		y = rand() % 200;
		ancho = alto = rand() % 25 + 25;
	}
};

class Obstaculos
{
private:
	vector <Obstaculo*> obstaculos;
public:
	Obstaculos(int n, Rectangle obj)
	{
		for (int i = 0; i < n; i++)
		{
			Obstaculo* obs = new Obstaculo();
			if (obs->Area().IntersectsWith(obj) == false && Colision(obs->Area()) == false)
				obstaculos.push_back(obs);
			else
			{
				delete obs;
				i--;
			}
		}
	}
	~Obstaculos()
	{
		for (int i = 0; i < obstaculos.size(); i++)
			delete obstaculos.at(i);
	}

	bool Colision(Rectangle obj)
	{
		for each (Obstaculo * obs in obstaculos)
		{
			if (obs->NextArea().IntersectsWith(obj))
				return true;
		}
		return false;
	}

	void Mover(Graphics^ g)
	{
		for each (Obstaculo * obs in obstaculos)
			obs->Mover(g);
	}
	void Mostrar(Graphics^ g)
	{
		for each (Obstaculo * obs in obstaculos)
			obs->Mostrar(g);
	}
};