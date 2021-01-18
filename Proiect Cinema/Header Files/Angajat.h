#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Angajat {

	const int idAngajat;
	static int id;

	char* username;
	int nrAni;
	int* bonus;
	int anulNasterii;

public:
	//constructor implicit
	Angajat();
	//constructor cu parametri
	Angajat(int, const char*, int, int*, int);
	Angajat(const char*, int, int*, int);
	//constructorul de copiere
	Angajat(const Angajat& a);
	//destructorul
	~Angajat();
	//operatorul =
	Angajat& operator=(const Angajat& a);

	static vector<Angajat> incarca(string fisier);
	static void salveaza(string fisier, vector<Angajat> angajati);

	//operator []
	int& operator[](int);
	//un operator matematic
	Angajat operator+(int);
	//operatorul ++ sau -- (cele 2 forme)
	Angajat operator++();
	Angajat operator++(int);
	//operator cast (catre orice tip) explicit sau implicit
	explicit operator int();
	//operator !
	bool operator!();
	//operator conditional (<.>,=<,>=)
	friend bool operator<(const Angajat& a1, const Angajat& a2);
	//operatorul pentru testarea egalitatii dintre 2 obiecte ==
	friend bool operator==(const Angajat& a1, const Angajat& a2);
	//friend istream >> si ostream <<
	friend ostream& operator<<(ostream& out, Angajat);
	friend istream& operator>>(istream& in, Angajat&);

	char* getUsername();
	void setUsername(const char*);

	int getNrAni();
	void setNrAni(int);

	int* getBonus();
	void setBonus(int*, int);

	int getIdAngajat();
	void setAnulNasterii(int);
};

Angajat operator+(int, Angajat);
bool operator==(const Angajat& a1, const Angajat& a2);
bool operator<(const Angajat& a1, const Angajat& a2);
ostream& operator<<(ostream& out, Angajat a);
istream& operator>>(istream& in, Angajat& a);

