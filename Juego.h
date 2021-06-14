#pragma once
#include "Jugador.h"
#include "Obstaculo.h"

//Mi Nuevo comentario

class Juego
{
private:
	Jugador* player;
	Obstaculos* obj_obstaculos;
public:
	Juego()
	{
		player = new Jugador();
		obj_obstaculos = new Obstaculos(5, player->Area());
	}
	~Juego()
	{
		delete player;
		delete obj_obstaculos;
	}

	void MovimientoJugador(bool accion, Keys tecla)
	{
		int velocidad = 4;
		if (accion == true)
		{
			if (tecla == Keys::Up)
				player->SetDY(-velocidad);
			else if (tecla == Keys::Down)
				player->SetDY(velocidad);
			else if (tecla == Keys::Left)
				player->SetDX(-velocidad);
			else if (tecla == Keys::Right)
				player->SetDX(velocidad);
		}
		else
		{
			if (tecla == Keys::Up)
				player->SetDY(0);
			else if (tecla == Keys::Down)
				player->SetDY(0);
			else if (tecla == Keys::Left)
				player->SetDX(0);
			else if (tecla == Keys::Right)
				player->SetDX(0);
		}
	}
	void Mover(Graphics^ g)
	{
		if(obj_obstaculos->Colision(player->NextArea()) == false)
			player->Mover(g);
		obj_obstaculos->Mover(g);
	}
	void Mostrar(Graphics^ g)
	{
		player->Mostrar(g);
		obj_obstaculos->Mostrar(g);
	}
};