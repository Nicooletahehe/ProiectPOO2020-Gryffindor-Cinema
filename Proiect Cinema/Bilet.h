#pragma once
#include <iostream>
#include <string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Bilet
{
	const int idBilet;
	static string numeCinema;
	//Film numeFilm;
	//Film durata;
	char* numeFilm;
	int idSala;
	int nrLoc;
	int nrRand;
	int nrBilete;
	double* pretBilet;
	//Sala numeSala;
	//Sala randDinSala;
	//Sala locDinSala;
public:
	//constructor implicit
	Bilet();
	//constructor cu parametri
	Bilet(char*, int, int, int, int, double*);
	//constructorul de copiere
	Bilet(const Bilet& b);
	//destructorul
	~Bilet();
	//operatorul =
	Bilet& operator=(const Bilet& b);
	//operator []
	double& operator[](int);
	//un operator matematic
	Bilet operator+(int);
	//operatorul ++ sau -- (cele 2 forme)
	Bilet operator++();
	Bilet operator++(int);
	//operator cast (catre orice tip) explicit sau implicit
	explicit operator int();
	//operator !
	bool operator!();
	//operator conditional (<.>,=<,>=)
	bool operator<(Bilet b1);
	//operatorul pentru testarea egalitatii dintre 2 obiecte ==
	bool operator==(Bilet b1);
	//friend istream >> si ostream <<
	friend ostream& operator<<(ostream& out, Bilet);
	friend istream& operator>>(istream& in, Bilet&);

	char* getNumeFilm();
	void setNumeFilm(const char*);

	int getNrBilete();
	void setNrBilete(int);

	double* getPretBilet();
	void setPretBilet(double* pretBilet, int nrBilet);
};

Bilet operator+(int, Bilet);
bool operator==(const Bilet& sb1, const Bilet& b2);
bool operator<(const Bilet& b1, const Bilet& b2);
ostream& operator<<(ostream& out, Bilet b);
istream& operator>>(istream& in, Bilet& b);