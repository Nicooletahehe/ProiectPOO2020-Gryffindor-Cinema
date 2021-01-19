#include "Header Files/Bilet.h"

#include <stdlib.h>
#include <string.h>
#include <vector>

#include <iomanip>

//initializarea atributului static
int Bilet::id = 0;

//constructor implicit
Bilet::Bilet() : idBilet(id)
{
	numeFilm = NULL;
	idSala = 0;
	nrRand = 0;
	nrLoc = NULL;
	nrBilete = 0;
	pretBilet = NULL;
}
//constructor cu parametri
Bilet::Bilet(int idBilet, char* nume, int idS, int* loc, int rand, int nr, double* pret) : idBilet(idBilet)
{
	numeFilm = new char[strlen(nume) + 1];
	strcpy_s(numeFilm, strlen(nume) + 1, nume);
	idSala = idS;
	nrRand = rand;
	if (pret != nullptr && nr > 0 && loc != nullptr)
	{
		pretBilet = new double[nr];
		nrLoc = new int[nr];
		for (int i = 0; i < nr; i++)
		{
			pretBilet[i] = pret[nr];
			nrLoc[i] = loc[i];
		}
		nrBilete = nr;
	}
	else {
		pretBilet = nullptr;
		nrLoc = nullptr;
		nrBilete = 0;
	}
}
Bilet::Bilet(char* nume, int idS, int* loc, int rand, int nr, double* pret) : idBilet(++id)
{
	numeFilm = new char[strlen(nume) + 1];
	strcpy_s(numeFilm, strlen(nume) + 1, nume);
	idSala = idS;
	nrRand = rand;
	if (pret != nullptr && nr > 0 && loc != nullptr)
	{
		pretBilet = new double[nr];
		nrLoc = new int[nr];
		for (int i = 0; i < nr; i++)
		{
			pretBilet[i] = pret[nr];
			nrLoc[i] = loc[i];
		}
		nrBilete = nr;
	}
	else {
		pretBilet = nullptr;
		nrLoc = nullptr;
		nrBilete = 0;
	}
}
//constructorul de copiere
Bilet::Bilet(const Bilet& b) : idBilet(b.idBilet)
{
	numeFilm = new char[strlen(b.numeFilm) + 1];
	strcpy_s(numeFilm, strlen(b.numeFilm) + 1, b.numeFilm);
	if (b.pretBilet != nullptr && b.nrBilete > 0 && b.nrLoc != nullptr)
	{
		pretBilet = new double[b.nrBilete];
		nrLoc = new int[b.nrBilete];
		for (int i = 0; i < b.nrBilete; i++)
		{
			pretBilet[i] = b.pretBilet[i];
			nrLoc[i] = b.nrLoc[i];
		}
		nrBilete = b.nrBilete;
	}
	else {
		pretBilet = nullptr;
		nrLoc = nullptr;
		nrBilete = 0;
	}
	idSala = b.idSala;
	nrRand = b.nrRand;
}
//destructorul
Bilet::~Bilet()
{
	if (pretBilet != nullptr)
	{
		delete[] pretBilet;
	}

	if (nrLoc != nullptr)
	{
		delete[] nrLoc;
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
		if (nrLoc != nullptr) {
			delete[] nrLoc;
		}
		if (b.pretBilet != nullptr && b.nrBilete > 0 && b.nrLoc != nullptr)
		{
			pretBilet = new double[b.nrBilete];
			nrLoc = new int[b.nrBilete];
			for (int i = 0; i < b.nrBilete; i++)
			{
				pretBilet[i] = b.pretBilet[i];
				nrLoc[i] = b.nrLoc[i];
			}
			nrBilete = b.nrBilete;
		}
		else {
			pretBilet = nullptr;
			nrLoc = nullptr;
			nrBilete = 0;
		}

		idSala = b.idSala;
		nrRand = b.nrRand;

		if (numeFilm != nullptr)
		{
			delete[] numeFilm;
		}
		numeFilm = new char[strlen(b.numeFilm) + 1];
		strcpy_s(numeFilm, strlen(b.numeFilm) + 1, b.numeFilm);
	}

	return *this;
}

vector<Bilet> Bilet::incarca(string fisier)
{
	vector<Bilet> bilete;

	ifstream in(fisier, ios::binary);
	if (!in.good()) {
		// Fisierul poate sa nu existe
		return bilete;
	}

	int nr;
	in.read((char*)&nr, sizeof(nr));

	for (int i = 0; i < nr; ++i)
	{
		int id;
		in.read((char*)&id, sizeof(id));

		int numeFilmLen;
		in.read((char*)&numeFilmLen, sizeof(numeFilmLen));
		char* numeFilm = new char[numeFilmLen];
		in.read(numeFilm, numeFilmLen);

		int nrBilete;
		in.read((char*)&nrBilete, sizeof(nrBilete));
		double* pretBilet = new double[nrBilete];
		in.read((char*)pretBilet, nrBilete * sizeof(double));
		int* nrLoc = new int[nrBilete];
		in.read((char*)nrLoc, nrBilete * sizeof(int));

		int idSala;
		in.read((char*)&idSala, sizeof(idSala));

		int nrRand;
		in.read((char*)&nrRand, sizeof(nrRand));

		bilete.emplace_back(id, numeFilm, idSala, nrLoc, nrRand, nrBilete, pretBilet);

		delete[] numeFilm;
		delete[] pretBilet;
		delete[] nrLoc;
	}

	return bilete;
}
void Bilet::salveaza(string fisier, vector<Bilet> bilete)
{
	ofstream out(fisier, ios::binary);

	int nr = size(bilete);
	out.write((char*)&nr, sizeof(nr));

	for (int i = 0; i < size(bilete); ++i)
	{
		out.write((char*)&bilete[i].idBilet, sizeof(bilete[i].idBilet));

		int len = strlen(bilete[i].numeFilm) + 1;
		out.write((char*)&len, sizeof(len));
		out.write(bilete[i].numeFilm, len);

		out.write((char*)&bilete[i].nrBilete, sizeof(bilete[i].nrBilete));
		out.write((char*)&bilete[i].pretBilet, bilete[i].nrBilete * sizeof(double));
		out.write((char*)&bilete[i].nrLoc, bilete[i].nrBilete * sizeof(int));

		out.write((char*)&bilete[i].idSala, sizeof(bilete[i].idSala));
		out.write((char*)&bilete[i].nrRand, sizeof(bilete[i].nrRand));
	}

	//out.close();
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

	cout << "Rand: ";
	in >> b.nrRand;

	cout << "Numar bilete: ";
	in >> b.nrBilete;
	if (b.nrBilete > 0 && b.pretBilet != nullptr && b.nrLoc != nullptr)
	{
		b.pretBilet = new double[b.nrBilete];
		b.nrLoc = new int[b.nrBilete];
		for (int i = 0; i < b.nrBilete; i++)
		{
			cout << "Pret per bilet[" << i << "] = ";
			in >> b.pretBilet[i];
		}

		for (int i = 0; i < b.nrBilete; i++)
		{
			cout << "Loc per bilet[" << i << "] = ";
			in >> b.nrLoc[i];
		}
	}
	else {
		b.nrBilete = 0;
		b.pretBilet = nullptr;
		b.nrLoc = nullptr;
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
void Bilet::setPretBilet(double* pretBilet, int nrBilete)
{
	if (pretBilet != nullptr && nrBilete > 0)
	{
		this->pretBilet = new double[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			this->pretBilet[i] = pretBilet[i];
		}
		this->nrBilete = nrBilete;
	}
	else {
		this->pretBilet = nullptr;
		this->nrBilete = 0;
	}
}

int Bilet::getIdBilet() {
	return idBilet;
}
int Bilet::getRandBilet() {
	return nrRand;
}
void Bilet::setRandBilet(int i) {
	if (i > 0)
	{
		nrRand = i;
	}
	else {
		nrRand;
	}
}
int* Bilet::getLocBilet() {
	if (nrLoc != nullptr)
	{
		int* aux = new int[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			aux[i] = nrLoc[nrBilete];
		}
		return aux;
	}
	else {
		return nullptr;
	}
}
void Bilet::setLocBilet(int* loc, int nrBilete) {
	if (loc != nullptr && nrBilete > 0)
	{
		nrLoc = new int[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			nrLoc[i] = loc[i];
		}
		this->nrBilete = nrBilete;
	}
	else {
		this->nrLoc = nullptr;
		this->nrBilete = 0;
	}
}
int Bilet::getIdSala() {
	return idSala;
}
void Bilet::setIdSala(int i) {
	if (i > 0)
	{
		idSala = i;
	}
	else {
		idSala;
	}
}
