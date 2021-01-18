#pragma once
#include <iostream>
#include <string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Cinema
{
	const int idCinema;
	static string nume;
	char* adresa;
	//Sala nrSali[4]; //5 sali in cinema
	int nrIntrari;
	//Bilet bileteVandute;
	double* profitIntrari;
	//Angajat nrAngajati;

public:
	//constructor implicit
	Cinema();
	//constructor cu parametri
	Cinema(char*, int, double*);
	//constructorul de copiere
	Cinema(const Cinema& c);
	//destructorul
	~Cinema();
	//operatorul =
	Cinema& operator=(const Cinema& c);
	//operator []
	double& operator[](int);
	//un operator matematic
	Cinema operator+(int);
	//operatorul ++ sau -- (cele 2 forme)
	Cinema operator++();
	Cinema operator++(int);
	//operator cast (catre orice tip) explicit sau implicit
	explicit operator int();
	//operator !
	bool operator!();
	//operator conditional (<.>,=<,>=)
	bool operator<(Cinema c1);
	//operatorul pentru testarea egalitatii dintre 2 obiecte ==
	bool operator==(Cinema& c1);
	//friend istream >> si ostream <<
	friend ostream& operator<<(ostream& out, Cinema);
	friend istream& operator>>(istream& in, Cinema&);

	char* getAdresa();
	void setAdresa(const char*);

	int getNrIntrari();
	void setNrIntrari(int);

	double* getProfitIntrari();
	void setProfitIntrari(double* profit, int intrari);
};

Cinema operator+(int, Cinema);
bool operator==(const Cinema& c1, const Cinema& c2);
bool operator<(const Cinema& c1, const Cinema& c2);
ostream& operator<<(ostream& out, Cinema c);
istream& operator>>(istream& in, Cinema& c);
