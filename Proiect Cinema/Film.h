#pragma once

#include <iostream>
#include <string>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class Film
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

	Film(char* nume, int durata);
	Film(const Film& film);
	~Film();

	Film operator=(const Film& film);
	int operator[](std::size_t i);

	Film& operator+=(const Film& rhs);
	friend Film operator+(Film lhs, const Film& rhs);

	Film& operator++();
	Film operator++(int);
	Film& operator--();
	Film operator--(int);

	operator int() const { return vizionari; }

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
