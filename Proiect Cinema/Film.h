#pragma once
#include <iostream>
#include <string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Film
{
	const int idFilm;
	static string tipFilm;// camp static
	char* numeFilm;
	int nrVizionari;
	//int*
	int durata; //in secunde
	//Tipologii filme

public:
	//Film() : idFilm(0)
	//{
	//	numeFilm = nullptr;
	//	durata = 0;
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
string Film::tipFilm = "digital";


