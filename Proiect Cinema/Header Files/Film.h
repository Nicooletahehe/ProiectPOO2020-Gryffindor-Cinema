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
	virtual void setNume(string nume) = 0;
	virtual string getNume() = 0;
};

class Film : public IFilm
{
private:
	// Un intreg unic care identifica filmul in sistemul nostru
	const int id;

	// ID-ul urmatorului film (este incrementat dupa ce un nou film este initializat)
	static int last_id;

	// Numele filmului
	string nume;

	// Intervalele orare in care filmul este programat
	// Fiecare ora, este de forma HHMM
	vector<int> intervale;

	// Numarul de vizualizari
	int vizionari;

	// Durata filmului (in minute)
	int durata;

public:
	Film(int id, string nume, vector<int> intervale, int vizionari, int durata);
	Film(string nume, int durata);
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

	void setNume(string nume);
	string getNume();

	void setIntervale(vector<int> intervale);
	vector<int> getIntervale();

	void setVizionari(int vizionari);
	int getVizionari();

	void setDurata(int durata);
	int getDurata();
};

template<typename T>
class Serie
{
private:
	vector<T> filme;

public:
	T operator[](std::size_t i) { return filme[i]; };
};

Film operator+(Film lhs, const Film& rhs);

bool operator==(const Film& lhs, const Film& rhs);
bool operator<(const Film& lhs, const Film& rhs);

ostream& operator<<(ostream& out, Film& film);
istream& operator>>(istream& in, Film& film);
