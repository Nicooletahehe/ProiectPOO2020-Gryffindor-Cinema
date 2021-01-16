#include "Film.h"

#include <stdlib.h>
#include <string.h>

#include <vector>

int Film::last_id = 0;

Film::Film(char *nume, int durata)
	: id(++last_id)
	, nume(nullptr)
	, nrIntervale(0)
	, intervale(nullptr)
	, vizionari(0)
	, durata(durata)
{
	this->setNume(nume);
}

Film::Film(const Film& film)
	: id(film.id)
	, nume(nullptr)
	, nrIntervale(0)
	, intervale(nullptr)
	, vizionari(film.vizionari)
	, durata(film.durata)
{
	this->setNume(film.nume);
	this->setIntervale(film.intervale, film.nrIntervale);
}

Film::~Film()
{
	this->setNume(nullptr);
	this->setIntervale(nullptr, 0);
}

Film Film::operator=(const Film& film)
{
	this->setNume(film.nume);
	this->setIntervale(film.intervale, film.nrIntervale);
	this->setVizionari(film.vizionari);
	this->setDurata(film.durata);
	return *this;
}

int Film::operator[](std::size_t i)
{
	if (i > 0 && i < nrIntervale)
	{
		return intervale[i];
	}

	return 0;
}

Film& Film::operator+=(const Film& rhs)
{
	this->vizionari += rhs.vizionari;
	return *this;
}

Film operator+(Film lhs, const Film& rhs)
{
	lhs += rhs;
	return lhs;
}

Film& Film::operator++()
{
	++this->vizionari;
	return *this;
}

Film Film::operator++(int)
{
	Film tmp(*this);
	operator++();
	return tmp;
}

Film& Film::operator--()
{
	--this->vizionari;
	return *this;
}

Film Film::operator--(int)
{
	Film tmp(*this);
	operator--();
	return tmp;
}

bool operator==(const Film& lhs, const Film& rhs)
{
	return strcmp(lhs.nume, rhs.nume) == 0;
}

bool operator<(const Film& lhs, const Film& rhs)
{
	return strcmp(lhs.nume, rhs.nume) < 0;
}

ostream& operator<<(ostream& out, Film& film)
{
	out << "Film '" << film.nume << "' (vizionat de " << film.getVizionari() << " ori, durata " << film.durata << " minute)\n";
	out << "Filmul se difuzeaza in urmatoarele intervale orare:\n";
	for (int i = 0; i < film.nrIntervale; ++i) {
		int h = film.intervale[i] / 100, m = film.intervale[i] % 100;
		
		// Calculam ora de final
		int m2 = m + film.durata;
		int h2 = (h + (m2 / 60)) % 24;
		m2 %= 60;

		out << " - " << h << ":" << m << " -> " << h2 << ":" << m2 << "\n";
	}

	return out;
}

istream& operator>>(istream& in, Film& film)
{
	string nume;
	getline(in, nume);
	film.setNume(nume.c_str());

	int nrIntervale;
	in >> nrIntervale;
	std::vector<int> intervale;
	for (int i = 0; i < nrIntervale; ++i) {
		int interval;
		in >> interval;
		intervale.emplace_back(interval);
	}

	film.setIntervale(intervale.data(), nrIntervale);

	return in;
}

int Film::getId()
{
	return id;
}

void Film::setNume(const char* nume)
{
	delete[] this->nume;

	size_t len = strlen(nume);
	if (nume != nullptr && len > 0)
	{
		this->nume = new char[len + 1];
		strcpy_s(this->nume, len + 1, nume);
	}
}

char *Film::getNume()
{
	return nume;
}

void Film::setIntervale(int* intervale, int nrIntervale)
{
	delete[] this->intervale;
	this->nrIntervale = 0;

	if (intervale != nullptr && nrIntervale > 0)
	{
		this->intervale = new int[nrIntervale];
		for (int i = 0; i < nrIntervale; ++i)
		{
			this->intervale[i] = intervale[i];
		}
	}
}

void Film::getIntervale(int** intervale, int *nrIntervale)
{
	*intervale = this->intervale;
	*nrIntervale = this->nrIntervale;
}

int Film::getNrIntervale()
{
	return nrIntervale;
}

void Film::setVizionari(int vizionari)
{
	if (vizionari >= 0)
	{
		this->vizionari = vizionari;
	}
}

int Film::getVizionari()
{
	return vizionari;
}

void Film::setDurata(int durata)
{
	if (durata > 0)
	{
		this->durata = durata;
	}
}

int Film::getDurata()
{
	return durata;
}
