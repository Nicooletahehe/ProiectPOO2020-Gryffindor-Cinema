#pragma once
#include <iostream>
#include <string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Sala {

	const int idSala;
	static string numeCinema;

	char* numeSala;
	int nrRanduri;
	int nrLocuri;
	int** diagramaLocuri; //capacitate


public:
	//constructor implicit
	Sala();
	//constructor cu parametri
	Sala(const char*, int, int, int**);
	//constructorul de copiere
	Sala(const Sala& s);
	//destructorul
	~Sala();
	//operatorul =
	Sala& operator=(const Sala& s);
	//operator []
	int& operator[](int);
	//un operator matematic
	Sala operator+(int);
	//operatorul ++ sau -- (cele 2 forme)
	Sala operator++();
	Sala operator++(int);
	//operator cast (catre orice tip) explicit sau implicit
	explicit operator int();
	//operator !
	bool operator!();
	//operator conditional (<.>,=<,>=)
	friend bool operator<(const Sala& s1, const Sala& s2);
	//operatorul pentru testarea egalitatii dintre 2 obiecte ==
	friend bool operator==(const Sala& s1, const Sala& s2);
	//friend istream >> si ostream <<
	friend ostream& operator<<(ostream& out, Sala);
	friend istream& operator>>(istream& in, Sala&);

	int totalLocuri();

	char* getNumeSala();
	void setNumeSala(const char* nume);

	int getNrRanduri();
	void setNrRanduri(int);

	int** getDiagramaLocuri();
	void setDiagramaLocuri(int* diagramaLocuri, int randuri, int locuri);
};

Sala operator+(int, Sala);
bool operator==(const Sala& s1, const Sala& s2);
bool operator<(const Sala& s1, const Sala& s2);
ostream& operator<<(ostream& out, Sala s);
istream& operator>>(istream& in, Sala& s);