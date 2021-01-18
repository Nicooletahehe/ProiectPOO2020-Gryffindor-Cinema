#include "Header Files/Angajat.h"

#include <stdlib.h>
#include <string.h>

//constructor implicit
Angajat::Angajat() : idAngajat(1)
{
	username = NULL;
	nrAni = 0;
	bonus = NULL;
	anulNasterii = 0;
}
//constructor cu parametri
Angajat::Angajat(const char* nume, int i1, int* i2, int i3) : idAngajat(idAngajat)
{
	username = new char[strlen(nume) + 1];
	strcpy_s(username, strlen(nume) + 1, nume);
	if (i2 != nullptr && i1 > 0)
	{
		bonus = new int[i1];
		for (int i = 0; i < i1; i++)
		{
			bonus[i] = i2[i];
		}
		nrAni = i1;
	}
	else {
		bonus = nullptr;
		nrAni = 0;
	}
	anulNasterii = i3;
}
//constructorul de copiere
Angajat::Angajat(const Angajat& a) : idAngajat(a.idAngajat)
{
	username = new char[strlen(a.username) + 1];
	strcpy_s(username, strlen(a.username) + 1, a.username);
	if (a.bonus != nullptr && a.nrAni > 0)
	{
		bonus = new int[a.nrAni];
		for (int i = 0; i < a.nrAni; i++)
		{
			bonus[i] = a.bonus[i];
		}
		nrAni = a.nrAni;
	}
	else {
		bonus = nullptr;
		nrAni = 0;
	}
	anulNasterii = a.anulNasterii;
}
//destructorul
Angajat::~Angajat()
{
	if (bonus != nullptr)
	{
		delete[] bonus;
	}
	if (username != nullptr)
	{
		delete[] username;
	}
}
//operatorul =
Angajat& Angajat::operator=(const Angajat& a)
{
	if (this != &a) {
		if (bonus != nullptr)
		{
			delete[] bonus;
		}
		if (a.bonus != nullptr && a.nrAni > 0)
		{
			bonus = new int[a.nrAni];
			for (int i = 0; i < a.nrAni; i++)
			{
				bonus[i] = a.bonus[i];
			}
			nrAni = a.nrAni;
		}
		else {
			bonus = nullptr;
			nrAni = 0;
		}

		if (username != nullptr)
		{
			delete[] username;
		}
		username = new char[strlen(a.username) + 1];
		strcpy_s(username, strlen(a.username) + 1, a.username);
	}
	anulNasterii = a.anulNasterii;
	return *this;
}
//operator []
int& Angajat::operator[](int index)
{
	if (index >= 0 && index < nrAni && bonus != nullptr)
	{
		return bonus[index];
	}
	else {
		throw exception("index invalid");
	}
}
//un operator matematic
Angajat Angajat::operator+(int nrAni)
{
	if (nrAni < 0) { throw 500; }
	Angajat copie = *this;
	copie.anulNasterii += nrAni;
	return copie;
}
//operatorul ++ sau -- (cele 2 forme)
//incrementez numarul de ani de vechime
Angajat Angajat::operator++()
{
	this->nrAni;
	return *this;
}
Angajat Angajat::operator++(int i)
{
	Angajat copie = *this;
	this->nrAni++;
	return copie;
}
//operator cast (catre orice tip) explicit sau implicit
Angajat::operator int()
{
	return anulNasterii;
}
//operator !
bool Angajat::operator!()
{
	return nrAni > 0;
}
//operator conditional (<.>,=<,>=)
bool operator<(const Angajat& a1, const Angajat& a2)
{
	return strcmp(a1.username, a2.username) < 0;
}
//operatorul pentru testarea egalitatii dintre 2 obiecte ==
bool operator==(const Angajat& a1, const Angajat& a2)
{
	return strcmp(a1.username, a2.username) == 0;
}
//friend istream >> si ostream <<
ostream& operator<<(ostream& out, Angajat a)
{
	out << "Id Angajat: " << a.idAngajat << endl;
	if (a.username != nullptr)
	{
		out << "Username: " << a.username << endl;
	}
	out << "Anul Nasterii: " << a.anulNasterii << endl;
	out << "Vechime Ani: " << a.nrAni << endl;
	out << "Bonus: ";
	if (a.bonus != nullptr)
	{
		for (int i = 0; i < a.nrAni; i++)
		{
			out << a.bonus[i] << " ";
		}
	}
	return out;
}
istream& operator>>(istream& in, Angajat& a)
{
	if (a.username != nullptr)
	{
		delete[] a.username;
	}
	cout << "Username: ";
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	a.username = new char[strlen(buffer) + 1];
	strcpy_s(a.username, strlen(buffer) + 1, buffer);

	cout << "Anul Nasterii: ";
	in >> a.anulNasterii;

	cout << "Vechime (nr ani): ";
	in >> a.nrAni;
	if (a.nrAni > 0)
	{
		a.bonus = new int[a.nrAni];
		for (int i = 0; i < a.nrAni; i++)
		{
			cout << "bonus[" << i << "] = ";
			in >> a.bonus[i];
		}
	}
	else {
		a.nrAni = 0;
		a.bonus = nullptr;
	}

	return in;
}


char* Angajat::getUsername()
{
	if (username != nullptr)
	{
		char* aux = new char[strlen(username) + 1];
		strcpy_s(aux, strlen(username) + 1, username);
		return aux;
	}
	else {
		return nullptr;
	}
}
void Angajat::setUsername(const char* nume)
{
	if (nume != nullptr && strlen(nume) > 3)
	{
		if (username != nullptr)
		{
			delete[] username;
		}
		username = new char[strlen(nume) + 1];
		strcpy_s(username, strlen(nume) + 1, nume);
	}
}

int Angajat::getNrAni()
{
	return nrAni;
}
void Angajat::setNrAni(int i)
{
	if (i > 0)
	{
		nrAni = i;
	}
	else {
		nrAni;
	}
}

int* Angajat::getBonus()
{
	if (bonus != nullptr)
	{
		int* aux = new int[nrAni];
		for (int i = 0; i < nrAni; i++)
		{
			aux[i] = bonus[i];
		}
		return aux;
	}
	else {
		return nullptr;
	}
}
void Angajat::setBonus(int* b, int nr)
{
	if (b != nullptr && nr > 0)
	{
		bonus = new int[nr];
		for (int i = 0; i < nr; i++)
		{
			bonus[i] = b[i];
		}
		nrAni = nr;
	}
	else {
		bonus = nullptr;
	}
}

int Angajat::getIdAngajat()
{
	return idAngajat;
}

//initializarea atributului static
string Angajat::numeCinema = "Griffindor";