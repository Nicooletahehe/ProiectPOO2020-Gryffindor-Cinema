#include "Header Files/Cinema.h"

#include <stdlib.h>
#include <string.h>

//constructor implicit
Cinema::Cinema() : idCinema(1)
{
	adresa = NULL;
	nrIntrari = 0;
	profitIntrari = NULL;
}
//constructor cu parametri
Cinema::Cinema(char* adr, int nr, double* pret) : idCinema(idCinema)
{
	adresa = new char[strlen(adr) + 1];
	strcpy_s(adresa, strlen(adr) + 1, adr);
	if (pret != nullptr && nr > 0)
	{
		profitIntrari = new double[nr];
		for (int i = 0; i < nr; i++)
		{
			profitIntrari[i] = pret[nr];
		}
		nrIntrari = nr;
	}
	else {
		profitIntrari = nullptr;
		nrIntrari = 0;
	}
}
//constructorul de copiere
Cinema::Cinema(const Cinema& c) : idCinema(c.idCinema)
{
	adresa = new char[strlen(c.adresa) + 1];
	strcpy_s(adresa, strlen(c.adresa) + 1, c.adresa);
	if (c.profitIntrari != nullptr && c.nrIntrari > 0)
	{
		profitIntrari = new double[c.nrIntrari];
		for (int i = 0; i < c.nrIntrari; i++)
		{
			profitIntrari[i] = c.profitIntrari[i];
		}
		nrIntrari = c.nrIntrari;
	}
	else {
		profitIntrari = nullptr;
		nrIntrari = 0;
	}
}
//destructorul
Cinema::~Cinema()
{
	if (profitIntrari != nullptr)
	{
		delete[] profitIntrari;
	}
	if (adresa != nullptr)
	{
		delete[] adresa;
	}
}
//operatorul =
Cinema& Cinema::operator=(const Cinema& c)
{
	if (this != &c) {
		if (profitIntrari != nullptr)
		{
			delete[] profitIntrari;
		}
		if (c.profitIntrari != nullptr && c.nrIntrari > 0)
		{
			profitIntrari = new double[c.nrIntrari];
			for (int i = 0; i < c.nrIntrari; i++)
			{
				profitIntrari[i] = c.profitIntrari[i];
			}
			nrIntrari = c.nrIntrari;
		}
		else {
			profitIntrari = nullptr;
			nrIntrari = 0;
		}

		if (adresa != nullptr)
		{
			delete[] adresa;
		}
		adresa = new char[strlen(c.adresa) + 1];
		strcpy_s(adresa, strlen(c.adresa) + 1, c.adresa);
	}

	return *this;
}
//operator []
double& Cinema::operator[](int index)
{
	if (index >= 0 && index < nrIntrari && profitIntrari != nullptr)
	{
		return profitIntrari[index];
	}
	else {
		throw exception("index invalid");
	}
}
//un operator matematic
Cinema Cinema::operator+(int nr)
{
	if (nrIntrari < 0) { throw 500; }
	Cinema copie = *this;
	copie.nrIntrari += nr;
	return copie;
}
//operatorul ++ sau -- (cele 2 forme)
//incrementez numarul de ani de vechime
Cinema Cinema::operator++()
{
	this->nrIntrari;
	return *this;
}
Cinema Cinema::operator++(int i)
{
	Cinema copie = *this;
	this->nrIntrari++;
	return copie;
}
//operator cast (catre orice tip) explicit sau implicit
Cinema::operator int()
{
	return nrIntrari;
}
//operator !
bool Cinema::operator!()
{
	return nrIntrari > 0;
}
//operator conditional (<.>,=<,>=)
bool Cinema::operator<(Cinema c1)
{
	return nrIntrari < c1.nrIntrari;
}
//operatorul pentru testarea egalitatii dintre 2 obiecte ==
bool Cinema::operator==(Cinema& c1)
{
	return nrIntrari == c1.nrIntrari;
}
//friend istream >> si ostream <<
ostream& operator<<(ostream& out, Cinema c)
{
	cout << "Id Cinema: " << c.idCinema << endl;
	if (c.adresa != nullptr)
	{
		out << "Adresa: " << c.adresa << endl;
	}
	out << "Numar intrari: " << c.nrIntrari << endl;
	out << "Profit intrari: ";
	if (c.profitIntrari != nullptr)
	{
		for (int i = 0; i < c.nrIntrari; i++)
		{
			out << c.profitIntrari[i] << " ";
		}
	}
	return out;
}
istream& operator>>(istream& in, Cinema& c)
{
	if (c.adresa != nullptr)
	{
		delete[] c.adresa;
	}
	cout << "Adresa: ";
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	c.adresa = new char[strlen(buffer) + 1];
	strcpy_s(c.adresa, strlen(buffer) + 1, buffer);

	cout << "Numar intrari: ";
	in >> c.nrIntrari;
	if (c.nrIntrari > 0 && c.profitIntrari != nullptr)
	{
		c.profitIntrari = new double[c.nrIntrari];
		for (int i = 0; i < c.nrIntrari; i++)
		{
			cout << "Profit per intrare[" << i << "] = ";
			in >> c.profitIntrari[i];
		}
	}
	else {
		c.nrIntrari = 0;
		c.profitIntrari = nullptr;
	}
	return in;
}


char* Cinema::getAdresa()
{
	if (adresa != nullptr)
	{
		char* aux = new char[strlen(adresa) + 1];
		strcpy_s(aux, strlen(adresa) + 1, adresa);
		return aux;
	}
	else {
		return nullptr;
	}
}
void Cinema::setAdresa(const char* adr)
{
	if (adr != nullptr && strlen(adr) > 3)
	{
		if (adresa != nullptr)
		{
			delete[] adresa;
		}
		adresa = new char[strlen(adr) + 1];
		strcpy_s(adresa, strlen(adr) + 1, adr);
	}
}

int Cinema::getNrIntrari()
{
	return nrIntrari;
}
void Cinema::setNrIntrari(int i)
{
	if (i > 0)
	{
		nrIntrari = i;
	}
	else {
		nrIntrari;
	}
}

double* Cinema::getProfitIntrari()
{
	if (profitIntrari != nullptr)
	{
		double* aux = new double[nrIntrari];
		for (int i = 0; i < nrIntrari; i++)
		{
			aux[i] = profitIntrari[nrIntrari];
		}
		return aux;
	}
	else {
		return nullptr;
	}
}
void Cinema::setProfitIntrari(double* profit, int nr)
{
	if (profit != nullptr && nr > 0)
	{
		profitIntrari = new double[nr];
		for (int i = 0; i < nr; i++)
		{
			profitIntrari[i] = profit[i];
		}
		nrIntrari = nr;
	}
	else {
		profitIntrari = nullptr;
		nrIntrari = 0;
	}
}

//initializarea atributului static
string Cinema::nume = "Griffindor";