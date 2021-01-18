#include "Header Files/Bilet.h"

#include <stdlib.h>
#include <string.h>

//constructor implicit
Bilet::Bilet() : idBilet(1)
{
	numeFilm = NULL;
	idSala = 0;
	nrRand = 0;
	nrLoc = 0;
	nrBilete = 0;
	pretBilet = NULL;
}
//constructor cu parametri
Bilet::Bilet(char* nume, int idS, int loc, int rand, int nr, double* pret) : idBilet(idBilet)
{
	numeFilm = new char[strlen(nume) + 1];
	strcpy_s(numeFilm, strlen(nume) + 1, nume);
	idSala = idS;
	nrLoc = loc;
	nrRand = rand;
	if (pret != nullptr && nr > 0)
	{
		pretBilet = new double[nr];
		for (int i = 0; i < nr; i++)
		{
			pretBilet[i] = pret[nr];
		}
		nrBilete = nr;
	}
	else {
		pretBilet = nullptr;
		nrBilete = 0;
	}
}
//constructorul de copiere
Bilet::Bilet(const Bilet& b) : idBilet(b.idBilet)
{
	numeFilm = new char[strlen(b.numeFilm) + 1];
	strcpy_s(numeFilm, strlen(b.numeFilm) + 1, b.numeFilm);
	if (b.pretBilet != nullptr && b.nrBilete > 0)
	{
		pretBilet = new double[b.nrBilete];
		for (int i = 0; i < b.nrBilete; i++)
		{
			pretBilet[i] = b.pretBilet[i];
		}
		nrBilete = b.nrBilete;
	}
	else {
		pretBilet = nullptr;
		nrBilete = 0;
	}
	idSala = b.idSala;
	nrLoc = b.nrLoc;
	nrRand = b.nrRand;
}
//destructorul
Bilet::~Bilet()
{
	if (pretBilet != nullptr)
	{
		delete[] pretBilet;
	}
	if (numeFilm != nullptr)
	{
		delete[] numeFilm;
	}
}
//operatorul =
Bilet& Bilet::operator=(const Bilet& b)
{
	if (this != &b) {
		if (pretBilet != nullptr)
		{
			delete[] pretBilet;
		}
		if (b.pretBilet != nullptr && b.nrBilete > 0)
		{
			pretBilet = new double[b.nrBilete];
			for (int i = 0; i < b.nrBilete; i++)
			{
				pretBilet[i] = b.pretBilet[i];
			}
			nrBilete = b.nrBilete;
		}
		else {
			pretBilet = nullptr;
			nrBilete = 0;
		}

		if (numeFilm != nullptr)
		{
			delete[] numeFilm;
		}
		numeFilm = new char[strlen(b.numeFilm) + 1];
		strcpy_s(numeFilm, strlen(b.numeFilm) + 1, b.numeFilm);
	}

	return *this;
}
//operator []
double& Bilet::operator[](int index)
{
	if (index >= 0 && index < nrBilete && pretBilet != nullptr)
	{
		return pretBilet[index];
	}
	else {
		throw exception("index invalid");
	}
}
//un operator matematic
Bilet Bilet::operator+(int nr)
{
	if (nrBilete < 0) { throw 500; }
	Bilet copie = *this;
	copie.nrBilete += nr;
	return copie;
}
//operatorul ++ sau -- (cele 2 forme)
//incrementez numarul de ani de vechime
Bilet Bilet::operator++()
{
	this->nrBilete;
	return *this;
}
Bilet Bilet::operator++(int i)
{
	Bilet copie = *this;
	this->nrBilete++;
	return copie;
}
//operator cast (catre orice tip) explicit sau implicit
Bilet::operator int()
{
	return nrBilete;
}
//operator !
bool Bilet::operator!()
{
	return idSala > 0;
}
//operator conditional (<.>,=<,>=)
bool Bilet::operator<(Bilet b1)
{
	return idBilet < b1.idBilet;
}
//operatorul pentru testarea egalitatii dintre 2 obiecte ==
bool Bilet::operator==(Bilet b1)
{
	return idBilet < b1.idBilet;
}
//friend istream >> si ostream <<
ostream& operator<<(ostream& out, Bilet b)
{
	out << "Id Bilet: " << b.idBilet << endl;
	if (b.numeFilm != nullptr)
	{
		out << "Nume Film: " << b.numeFilm << endl;
	}
	out << "Sala: " << b.idSala << endl;
	out << "Rand: " << b.nrRand << endl;
	out << "Loc: " << b.nrLoc << endl;
	out << "Numar bilete: " << b.nrBilete << endl;
	out << "Pret Bilet/e: ";
	if (b.pretBilet != nullptr)
	{
		for (int i = 0; i < b.nrBilete; i++)
		{
			out << b.pretBilet[i] << " ";
		}
	}
	return out;
}
istream& operator>>(istream& in, Bilet& b)
{
	if (b.numeFilm != nullptr)
	{
		delete[] b.numeFilm;
	}
	cout << "Nume Film: ";
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	b.numeFilm = new char[strlen(buffer) + 1];
	strcpy_s(b.numeFilm, strlen(buffer) + 1, buffer);

	cout << "Sala: ";
	in >> b.idSala;

	cout << "Loc: ";
	in >> b.nrLoc;
	cout << "Rand: ";
	in >> b.nrRand;
	cout << "Numar bilete: ";
	in >> b.nrBilete;
	if (b.nrBilete > 0 && b.pretBilet != nullptr)
	{
		b.pretBilet = new double[b.nrBilete];
		for (int i = 0; i < b.nrBilete; i++)
		{
			cout << "Pret per bilet[" << i << "] = ";
			in >> b.pretBilet[i];
		}
	}
	else {
		b.nrBilete = 0;
		b.pretBilet = nullptr;
	}
	return in;
}


char* Bilet::getNumeFilm()
{
	if (numeFilm != nullptr)
	{
		char* aux = new char[strlen(numeFilm) + 1];
		strcpy_s(aux, strlen(numeFilm) + 1, numeFilm);
		return aux;
	}
	else {
		return nullptr;
	}
}
void Bilet::setNumeFilm(const char* nume)
{
	if (nume != nullptr && strlen(nume) > 3)
	{
		if (numeFilm != nullptr)
		{
			delete[] numeFilm;
		}
		numeFilm = new char[strlen(nume) + 1];
		strcpy_s(numeFilm, strlen(nume) + 1, nume);
	}
}

int Bilet::getNrBilete()
{
	return nrBilete;
}
void Bilet::setNrBilete(int i)
{
	if (i > 0)
	{
		nrBilete = i;
	}
	else {
		nrBilete;
	}
}

double* Bilet::getPretBilet()
{
	if (pretBilet != nullptr)
	{
		double* aux = new double[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			aux[i] = pretBilet[nrBilete];
		}
		return aux;
	}
	else {
		return nullptr;
	}
}
void Bilet::setPretBilet(double* pretBilet, int nrBilet)
{
	if (pretBilet != nullptr && nrBilet > 0)
	{
		this->pretBilet = new double[nrBilet];
		for (int i = 0; i < nrBilet; i++)
		{
			this->pretBilet[i] = pretBilet[i];
		}
		this->nrBilete = nrBilet;
	}
	else {
		this->pretBilet = nullptr;
		this->nrBilete = nrBilet;
	}
}

//initializarea atributului static
string Bilet::numeCinema = "Griffindor";