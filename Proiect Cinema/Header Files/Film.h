#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class IFilm
{
public:
	virtual int getId() = 0;
	virtual void setNume(const char* nume) = 0;
	virtual char* getNume() = 0;
};

class Film : public IFilm
{
private:
	// Un intreg unic care identifica filmul in sistemul nostru
	const int id;

	// ID-ul urmatorului film (este incrementat dupa ce un nou film este initializat)
	static int last_id;

	// Numele filmului
	char* nume;

	// Intervalele orare in care filmul este programat
	// Fiecare ora, este de forma HHMM
	int* intervale;

	// Numarul de intervale
	int nrIntervale;

	// Numarul de vizualizari
	int vizionari;

	// Durata filmului (in minute)
	int durata;

public:
	Film(int id, const char* nume, int* intervale, int nrIntervale, int vizionari, int durata);
	Film(const char* nume, int durata);
	Film(const Film& film);
	~Film();

	static vector<Film> incarca(string cale);
	static void salveaza(string cale, vector<Film> filme);

	Film operator=(const Film& film);
	int operator[](std::size_t i);

	Film& operator+=(const Film& rhs);
	friend Film operator+(Film lhs, const Film& rhs);

	Film& operator++();
	Film operator++(int);
	Film& operator--();
	Film operator--(int);

	operator int() const { return vizionari; }

	bool operator!() { return vizionari > 0; }

	friend bool operator==(const Film& lhs, const Film& rhs);
	friend bool operator<(const Film& lhs, const Film& rhs);

	friend ostream& operator<<(ostream& out, Film& film);
	friend istream& operator>>(istream& in, Film& film);

	int getId();

	void setNume(const char* nume);
	char* getNume();

	void setIntervale(int* intervale, int nrIntervale);
	// Deoarece trebuie sa intoarcem doua valori, le vom intoarce prin referinta.
	void getIntervale(int** intervale, int* nrIntervale);

	// Este util sa stim numarul de intervale, deoarece putem folosi operatorul de
	// indexare [] pentru a accesa intervalele.
	int getNrIntervale();

	void setVizionari(int vizionari);
	int getVizionari();

	void setDurata(int durata);
	int getDurata();
};

Film operator+(Film lhs, const Film& rhs);

bool operator==(const Film& lhs, const Film& rhs);
bool operator<(const Film& lhs, const Film& rhs);

ostream& operator<<(ostream& out, Film& film);
istream& operator>>(istream& in, Film& film);
