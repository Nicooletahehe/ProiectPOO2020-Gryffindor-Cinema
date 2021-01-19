#include "Header Files/Sala.h"

#include <stdlib.h>
#include <string.h>

//constructor implicit
Sala::Sala() : idSala(1)
{
	numeSala = NULL;
	nrRanduri = 0;
	nrLocuri = 0;
	diagramaLocuri = NULL;
}

//constructor cu parametri
Sala::Sala(const char* nume, int i1, int i2, int** i3) : idSala(idSala)
{
	numeSala = new char[strlen(nume) + 1];
	strcpy_s(numeSala, strlen(nume) + 1, nume);
	if (i3 != nullptr && i2 > 0 && i1 > 0)
	{
		diagramaLocuri = new int* [i1];
		for (int i = 0; i < i1; i++)
		{
			diagramaLocuri[i] = new int[i2];
		}
		nrRanduri = i1;
		nrLocuri = i2;
	}
	else {
		diagramaLocuri = nullptr;
		nrRanduri = 0;
		nrLocuri = 0;
	}
}

//constructorul de copiere
Sala::Sala(const Sala& s) : idSala(s.idSala)
{
	numeSala = new char[strlen(s.numeSala) + 1];
	strcpy_s(numeSala, strlen(s.numeSala) + 1, s.numeSala);
	if (s.diagramaLocuri != nullptr && s.nrRanduri > 0 && s.nrLocuri)
	{
		diagramaLocuri = new int* [s.nrRanduri];
		for (int i = 0; i < s.nrRanduri; i++)
		{
			diagramaLocuri[i] = new int[s.nrLocuri];
		}
		nrRanduri = s.nrRanduri;
		nrLocuri = s.nrLocuri;
	}
	else {
		diagramaLocuri = nullptr;
		nrRanduri = 0;
		nrLocuri = 0;
	}
}
//destructorul
Sala::~Sala()
{
	if (diagramaLocuri != nullptr)
	{
		for (int i = 0; i < nrRanduri; i++)
		{
			delete[] diagramaLocuri[i];
		}
		delete[] diagramaLocuri;
	}
	if (numeSala != nullptr)
	{
		delete[] numeSala;
	}
}
//operatorul =
Sala& Sala::operator=(const Sala& s)
{
	if (this != &s) {
		if (diagramaLocuri != nullptr)
		{
			for (int i = 0; i < nrRanduri; i++)
			{
				delete[] diagramaLocuri[i];
			}
			delete[] diagramaLocuri;
		}
		if (s.diagramaLocuri != nullptr && s.nrRanduri > 0 && s.nrLocuri > 0)
		{
			diagramaLocuri = new int* [s.nrRanduri];
			for (int i = 0; i < s.nrRanduri; i++)
			{
				diagramaLocuri[i] = new int[s.nrLocuri];
			}
			nrRanduri = s.nrRanduri;
			nrLocuri = s.nrLocuri;
		}
		else {
			diagramaLocuri = nullptr;
			nrRanduri = 0;
			nrLocuri = 0;
		}

		if (numeSala != nullptr)
		{
			delete[] numeSala;
		}
		numeSala = new char[strlen(s.numeSala) + 1];
		strcpy_s(numeSala, strlen(s.numeSala) + 1, s.numeSala);
	}

	return *this;
}
//operator []
int& Sala::operator[](int index)
{
	if (index >= 0 && index < nrRanduri && diagramaLocuri != nullptr && nrLocuri > 0)
	{
		return diagramaLocuri[index][nrLocuri];
	}
	else {
		throw exception("index invalid");
	}
}
//un operator matematic
Sala Sala::operator+(int nr)
{
	if (nrRanduri < 0) { throw 500; }
	Sala copie = *this;
	copie.nrRanduri += nr;
	return copie;
}
//operatorul ++ sau -- (cele 2 forme)
//incrementez numarul de ani de vechime
Sala Sala::operator++()
{
	this->nrRanduri;
	return *this;
}
Sala Sala::operator++(int i)
{
	Sala copie = *this;
	this->nrRanduri++;
	return copie;
}
//operator cast (catre orice tip) explicit sau implicit
Sala::operator int()
{
	return nrRanduri;
}
//operator !
bool Sala::operator!()
{
	return nrRanduri > 0;
}
//operator conditional (<.>,=<,>=)
bool operator<(const Sala& s1, const Sala& s2)
{
	return strcmp(s1.numeSala, s2.numeSala) < 0;
}
//operatorul pentru testarea egalitatii dintre 2 obiecte ==
bool operator==(const Sala& s1, const Sala& s2)
{
	return strcmp(s1.numeSala, s2.numeSala) == 0;
}
//friend istream >> si ostream <<
ostream& operator<<(ostream& out, Sala s)
{
	out << "Id Sala: " << s.idSala << endl;
	if (s.numeSala != nullptr)
	{
		out << "Nume Sala: " << s.numeSala << endl;
	}
	out << "Numar Randuri: " << s.nrRanduri << endl;
	out << "Numar Locuri: " << s.nrLocuri << endl;
	out << "Diagrama Locuri: ";
	if (s.diagramaLocuri != nullptr)
	{
		for (int i = 0; i < s.nrRanduri; i++)
		{
			for (int j = 0; j < s.nrLocuri; i++)
			{
				out << s.diagramaLocuri[i][j] << " ";
			}

		}
	}
	return out;
}
istream& operator>>(istream& in, Sala& s)
{
	if (s.numeSala != nullptr)
	{
		delete[] s.numeSala;
	}
	cout << "Nume Sala: ";
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	s.numeSala = new char[strlen(buffer) + 1];
	strcpy_s(s.numeSala, strlen(buffer) + 1, buffer);

	cout << "Numar Randuri: ";
	in >> s.nrRanduri;

	cout << "Numar Locuri: ";
	in >> s.nrLocuri;
	if (s.nrRanduri > 0 && s.nrLocuri > 0)
	{
		s.diagramaLocuri = new int* [s.nrRanduri];
		for (int i = 0; i < s.nrRanduri; i++)
		{
			for (int j = 0; j < s.nrLocuri; j++)
			{
				cout << "Locuri[" << i << "][" << j << "] = ";
				in >> s.diagramaLocuri[i][j];
			}
		}
	}
	else {
		s.nrRanduri = 0;
		s.nrLocuri = 0;
		s.diagramaLocuri = nullptr;
	}
	return in;
}

int Sala::totalLocuri() {
	return nrRanduri * nrLocuri;
}

char* Sala::getNumeSala()
{
	if (numeSala != nullptr)
	{
		char* aux = new char[strlen(numeSala) + 1];
		strcpy_s(aux, strlen(numeSala) + 1, numeSala);
		return aux;
	}
	else {
		return nullptr;
	}
}
void Sala::setNumeSala(const char* nume)
{
	if (nume != nullptr && strlen(nume) > 3)
	{
		if (numeSala != nullptr)
		{
			delete[] numeSala;
		}
		numeSala = new char[strlen(nume) + 1];
		strcpy_s(numeSala, strlen(nume) + 1, nume);
	}
}

int Sala::getNrRanduri()
{
	return nrRanduri;
}
void Sala::setNrRanduri(int i)
{
	if (i > 0)
	{
		nrRanduri = i;
	}
	else {
		nrRanduri;
	}
}

int** Sala::getDiagramaLocuri()
{
	if (diagramaLocuri != nullptr)
	{
		int** aux = new int* [nrRanduri];
		for (int i = 0; i < nrRanduri; i++)
		{
			aux[i] = new int[nrLocuri];
		}
		return aux;
	}
	else {
		return nullptr;
	}
}
void Sala::setDiagramaLocuri(int* diagramaLocuri, int randuri, int locuri)
{
	if (diagramaLocuri != nullptr && randuri > 0 && locuri > 0)
	{
		this->diagramaLocuri = new int* [randuri];
		for (int i = 0; i < randuri; i++)
		{
			this->diagramaLocuri[i] = new int[locuri];
		}
		nrRanduri = randuri;
		nrLocuri = locuri;
	}
	else {
		this->diagramaLocuri = nullptr;
		nrRanduri = 0;
		nrLocuri = 0;
	}
}

//initializarea atributului static
string Sala::numeCinema = "Griffindor";