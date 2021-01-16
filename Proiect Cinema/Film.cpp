#include "Film.h"

#include <stdlib.h>
#include <string.h>

#include <iomanip>

int Film::last_id = 0;

Film::Film(int id, const char* nume, int *intervale, int nrIntervale, int vizionari, int durata)
	: id(id)
	, nume(nullptr)
	, intervale(nullptr)
	, nrIntervale(0)
	, vizionari(0)
	, durata(durata)
{
	this->setNume(nume);
	this->setIntervale(intervale, nrIntervale);

	// Ne asiguram ca acest camp e mereu "corect" dpdv functional
	if (last_id < id)
	{
		last_id = id;
	}
}

Film::Film(const char *nume, int durata)
	: id(++last_id)
	, nume(nullptr)
	, intervale(nullptr)
	, nrIntervale(0)
	, vizionari(0)
	, durata(durata)
{
	this->setNume(nume);
}

Film::Film(const Film& film)
	: id(film.id)
	, nume(nullptr)
	, intervale(nullptr)
	, nrIntervale(0)
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

vector<Film> Film::incarca(string cale)
{
	vector<Film> filme;

	ifstream in(cale, ios::binary);
	if (!in.good()) {
		// Fisierul poate sa nu existe
		return filme;
	}

	int nr;
	in.read((char*)&nr, sizeof(nr));

	for (int i = 0; i < nr; ++i)
	{
		int id;
		in.read((char*)&id, sizeof(id));

		int numeLen;
		in.read((char*)&numeLen, sizeof(numeLen));
		char* nume = new char[numeLen];
		in.read(nume, numeLen);

		int nrIntervale;
		in.read((char*)&nrIntervale, sizeof(nrIntervale));
		int *intervale = new int[nrIntervale];
		in.read((char*)intervale, nrIntervale * sizeof(int));
		
		int vizionari;
		in.read((char*)&vizionari, sizeof(vizionari));

		int durata;
		in.read((char*)&durata, sizeof(durata));

		filme.emplace_back(id, nume, intervale, nrIntervale, vizionari, durata);

		delete[] nume;
		delete[] intervale;
	}

	return filme;
}

void Film::salveaza(string cale, vector<Film> filme)
{
	ofstream out(cale, ios::binary);
	
	int nr = filme.size();
	out.write((char*)&nr, sizeof(nr));

	for (int i = 0; i < filme.size(); ++i)
	{
		out.write((char*)&filme[i].id, sizeof(filme[i].id));
		int len = strlen(filme[i].nume) + 1;
		out.write((char*)&len, sizeof(len));
		out.write(filme[i].nume, len);
		out.write((char*)&filme[i].nrIntervale, sizeof(filme[i].nrIntervale));
		out.write((char*)&filme[i].intervale, filme[i].nrIntervale * sizeof(int));
		out.write((char*)&filme[i].vizionari, sizeof(filme[i].vizionari));
		out.write((char*)&filme[i].durata, sizeof(filme[i].durata));
	}
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
	out << "Film '" << film.nume << "' (id = " << film.id << ", vizionat de " << film.getVizionari() << " ori, durata " << film.durata << " minute)\n";
	
	if (film.nrIntervale > 0)
	{
		out << "Filmul se difuzeaza in urmatoarele intervale orare:\n";
		for (int i = 0; i < film.nrIntervale; ++i) {
			int h = film.intervale[i] / 100, m = film.intervale[i] % 100;

			// Calculam ora de final
			int m2 = m + film.durata;
			int h2 = (h + (m2 / 60)) % 24;
			m2 %= 60;

			out << " - "
				<< std::setw(2) << std::setfill('0') << h
				<< ":"
				<< std::setw(2) << std::setfill('0') << m
				<< " -> "
				<< std::setw(2) << std::setfill('0') << h2
				<< ":"
				<< std::setw(2) << std::setfill('0') << m2
				<< "\n";
		}
	}
	else
	{
		out << "Filmul nu se difuzeaza";
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
	this->nume = nullptr;

	if (nume != nullptr)
	{
		size_t len = strlen(nume);
		if (len > 0)
		{
			this->nume = new char[len + 1];
			strcpy_s(this->nume, len + 1, nume);
		}
	}
}

char *Film::getNume()
{
	return nume;
}

void Film::setIntervale(int* intervale, int nrIntervale)
{
	delete[] this->intervale;
	this->intervale = nullptr;
	this->nrIntervale = 0;

	if (intervale != nullptr && nrIntervale > 0)
	{
		this->intervale = new int[nrIntervale];
		this->nrIntervale = nrIntervale;

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
