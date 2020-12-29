#pragma once
#include <iostream>
#include <string>
#include "Film.h"
#include "Sala.h"
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Bilet
{
	const int idBilet;
	static int numarBilet;
	Film numeFilm;
	Film durata;
	double pretBilet;
	Sala numeSala;
	Sala randDinSala;
	Sala locDinSala; //=>de aici trebuie creata o functie care sa imi adune
	//numarul de locuri ocupate din acea sala, gen locuriOcupate()

public:
	//Bilet() : idBilet(numarBilet)
	//{
	//	pretBilet = 0;
	//}

	//constructor cu parametri

	//constructorul de copiere

	//destructorul

	//operatorul =

	//operator []

	//un operator matematic

	//operatorul ++ sau -- (cele 2 forme)

	//operator cast (catre orice tip) explicit sau implicit

	//operator !

	//operator conditional (<.>,=<,>=)

	//operatorul pentru testarea egalitatii dintre 2 obiecte ==

	//friend istream >> si ostream <<
};

int Bilet::numarBilet = 0;