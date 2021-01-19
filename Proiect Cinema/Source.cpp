#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

#include "Header Files/Cinema.h"
#include "Header Files/Film.h"
#include "Header Files/Bilet.h"
#include "Header Files/Sala.h"
#include "Header Files/Angajat.h"

using namespace std;

vector<Film> filme;
vector<Angajat> angajati;
vector<Cinema> cinemas;
vector<Bilet> bilete;
vector<Sala> sali;

int sizeMargini = 77;
void afisareMeniu(string e, int sizeMargini) {
	int marginLeft = 10;
	int marginRight = sizeMargini - marginLeft - size(e);

	std::cout << "\xBA";
	for (int i = 0; i < marginLeft; i++) {
		std::cout << " ";
	}
	std::cout << e;
	for (int i = 0; i < marginRight; i++) {
		std::cout << " ";
	}
	std::cout << "\xBA" << endl;
}
void header() {
	//header
	cout << "\xC9";
	for (int i = 0; i < sizeMargini; i++) {
		cout << "\xCD";
	}
	cout << "\xBB" << endl;
	cout << "\xBA";
	for (int i = 0; i < sizeMargini; i++) {
		cout << " ";
	}
	cout << "\xBA" << endl;
}
void titluCinema() {
	//titlu Cinema
	cout << "\xBA";
	string titlu = "Cinema Griffindor";
	int pTitlu = (sizeMargini - size(titlu)) / 2;
	//cout << pTitlu;
	for (int i = 0; i < pTitlu; i++) {
		cout << " ";
	}
	cout << titlu;
	for (int i = 0; i < pTitlu; i++) {
		cout << " ";
	}
	cout << "\xBA" << endl;
}
void titlu(string t) {
	//titlu
	cout << "\xBA";
	int pTitlu = (sizeMargini - size(t)) / 2;
	//cout << pTitlu;
	for (int i = 0; i < pTitlu; i++) {
		cout << " ";
	}
	cout << t;
	for (int i = 0; i < pTitlu; i++) {
		cout << " ";
	}
	cout << "\xBA" << endl;
}
void randuriLibere() {
	//rand liber
	for (int j = 0; j < 2; j++) {
		cout << "\xBA";
		for (int i = 0; i < sizeMargini; i++) {
			cout << " ";
		}
		cout << "\xBA" << endl;
	}
}
void footer() {
	//footer
	cout << "\xC8";
	for (int i = 0; i < sizeMargini; i++) {
		cout << "\xCD";
	}
	cout << "\xBC" << endl;
}
void meniu_principal();
//meniu Filme
void command_lm() // list movies
{
	std::system("CLS");
	cout << "Se afiseaza " << filme.size() << " filme:\n";
	for (Film& f : filme)
	{
		cout << "#" << f.getId() << " -> " << f.getNume() << "\n";
	}
	cout << "\n";
}
void command_rm() // read movie
{
	std::system("CLS");
	cout << "Introdu ID (#) film: ";
	int id;
	cin >> id;

	for (int i = 0; i < filme.size(); ++i)
	{
		if (filme[i].getId() == id)
		{
			cout << filme[i];
		}
		else {
			cout << "Filmul nu a fost gasit." << endl;
			break;
		}
	}
}
void command_am() // add movie
{
	std::system("CLS");
	cout << "Nume film: ";
	string nume;
	getline(cin, nume); // sarim peste \n
	getline(cin, nume);

	cout << "Durata: ";
	int durata;
	cin >> durata;

	cout << "Intervale (introdu numar, apoi ENTER, introdu -1 pentru a te opri): ";
	vector<int> intervale;
	while (true) {
		int interval;
		cin >> interval;
		if (interval < 0) {
			break;
		}
		intervale.emplace_back(interval);
	}

	Film f(nume.c_str(), durata);
	f.setIntervale(intervale);
	filme.emplace_back(f);

	cout << "Am adaugat filmul:\n";
	cout << f;

	Film::salveaza("filme.bin", filme);
}
void command_um() // update movie
{
	std::system("CLS");
	cout << "Introdu ID (#) film: ";
	int id;
	cin >> id;

	int index = -1;
	for (int i = 0; i < filme.size(); ++i)
	{
		if (filme[i].getId() == id)
		{
			index = i;
		}
	}

	if (index == -1)
	{
		cout << "Nu am gasit filmul cu ID #" << id << "\n";
		cout << "Foloseste LM sa vezi toate filmele\n";
		return;
	}

	cout << "Nume film: ";
	string nume;
	cin >> nume; // sarim peste \n
	getline(cin, nume);
	filme[index].setNume(nume.c_str());

	cout << "Durata: ";
	int durata;
	cin >> durata;
	filme[index].setDurata(durata);

	cout << "Intervale (introdu numar, apoi ENTER, introdu -1 pentru a te opri): ";
	vector<int> intervale;
	while (true) {
		int interval;
		cin >> interval;
		if (interval < 0) {
			break;
		}
		intervale.emplace_back(interval);
	}
	filme[index].setIntervale(intervale);

	cout << "Am modificat filmul:\n";
	cout << filme[index];

	Film::salveaza("filme.bin", filme);
}
void command_dm() // delete movie
{
	std::system("CLS");
	cout << "Introdu ID (#) film: ";
	int id;
	cin >> id;

	int index = -1;
	for (int i = 0; i < filme.size(); ++i)
	{
		if (filme[i].getId() == id)
		{
			index = i;
		}
	}

	if (index != -1)
	{
		filme.erase(filme.begin() + index);
	}

	Film::salveaza("filme.bin", filme);
}
void meniuFilm() {
	std::system("CLS");
	// Incarcare filme
	filme = Film::incarca("filme.bin");

	while (true)
	{
		header();
		titluCinema();
		titlu("Film ");
		randuriLibere();

		string meniu1 = "1. Afiseaza filmele";
		string meniu2 = "2. Afiseaza film";
		string meniu3 = "3. Adauga film";
		string meniu4 = "4. Modifica film";
		string meniu5 = "5. Sterge film";
		string meniu6 = "6. Meniu Principal";
		string meniu7 = "7. Iesire Program";

		afisareMeniu(meniu1, sizeMargini);
		afisareMeniu(meniu2, sizeMargini);
		afisareMeniu(meniu3, sizeMargini);
		afisareMeniu(meniu4, sizeMargini);
		afisareMeniu(meniu5, sizeMargini);
		afisareMeniu(meniu6, sizeMargini);
		afisareMeniu(meniu7, sizeMargini);

		randuriLibere();
		footer();
		cout << endl;
		for (int i = 0; i < 20; i++) {
			cout << " ";
		}
		std::cout << "Introdu codul unei comenzi: ";

		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			command_lm();
		}
		else if (cmd == 2)
		{
			command_rm();
		}
		else if (cmd == 3)
		{
			command_am();
		}
		else if (cmd == 4)
		{
			command_um();
		}
		else if (cmd == 5)
		{
			command_dm();
		}
		else if (cmd == 6)
		{
			meniu_principal();
		}
		else if (cmd == 7)
		{
			break;
		}
	}
}

//Angajati
void lista_angajati() {
	std::system("CLS");
	cout << "Lista de angajati: "<<endl;
	for (Angajat& a : angajati) {
		cout << "#" << a.getIdAngajat() << ". Username: " << a.getUsername() << endl;
		cout << "     Vechime: " << a.getNrAni() << endl;
	}
	cout << "Total de " << angajati.size() << " angajat/i.";
	cout << endl;
}
void lista_angajat() {
	std::system("CLS");
	cout << "Introduceti Id(#) angajat: ";
	int id;
	cin >> id;

	for (int i = 0; i < size(angajati); i++) {
		if (angajati[i].getIdAngajat() == id) {
			cout << angajati[i] << endl;
		}
	}

	if (size(angajati) == 0) {
		cout << "Angajatul cu Id#" << id << " nu exista." << endl;
	}
}
void adauga_angajat() {
	std::system("CLS");
	cout << "Pentru salvarea unui nou angajat, introduceti urmatoarele date:" << endl;;
	cout << "Username: ";
	char buffer[100];
	char* username;
	cin >> ws;
	cin.getline(buffer, 99);
	username = new char[strlen(buffer) + 1];
	strcpy_s(username, strlen(buffer) + 1, buffer);

	cout << "Anul Nasterii: ";
	int anNastere;
	cin >> anNastere;

	cout << "Vechime: ";
	int vechime;
	cin >> vechime;

	cout << "Bonus: ";
	int* bonusuri;
	if (vechime > 0) {
		bonusuri = new int[vechime];
		for (int i = 0; i < vechime; i++)
		{
			cout << "Bonus#" << i << " = ";
			cin >> bonusuri[i];
		}
	}
	else {
		vechime = 0;
		bonusuri = nullptr;
	}

	Angajat a(username, vechime, bonusuri, anNastere);
	angajati.emplace_back(a);

	cout << "Angajatul a fost adaugat" << endl;
	cout << a << endl;

	Angajat::salveaza("angajati.bin", angajati);
}
void modifica_angajat() {
	std::system("CLS");
	cout << "Pentru modificarea unui angajat, introduceti urmatoarele date:" << endl;
	cout << "Introduceti Id(#) angajat: ";
	int id;
	cin >> id;

	int index = -1;
	for (int i = 0; i < size(angajati); ++i)
	{
		if (angajati[i].getIdAngajat() == id)
		{
			index = i;
		}
	}

	if (index == -1)
	{
		cout << "Angajatul cu Id#" << id << " nu a fost gasit." << endl;
		cout << "Mergeti la lista cu angajati, folosind tasta 1.";
		return;
	}

	cout << "Username: ";
	char buffer[100];
	char* username;
	cin >> ws;
	cin.getline(buffer, 99);
	username = new char[strlen(buffer) + 1];
	strcpy_s(username, strlen(buffer) + 1, buffer);
	//cout << username << endl;
	angajati[index].setUsername(username);
	//cout << angajati[index].getUsername() << endl;

	cout << "Anul Nasterii: ";
	int anNastere;
	cin >> anNastere;
	//cout << anNastere << endl;
	angajati[index].setAnulNasterii(anNastere);

	cout << "Vechime (in ani): ";
	int vechime;
	cin >> vechime;
	//cout << vechime << endl;
	angajati[index].setNrAni(vechime);
	//cout << angajati[index].getNrAni() << endl;

	cout << "Bonus: ";
	int* bonusuri;
	if (vechime > 0) {
		bonusuri = new int[vechime];
		for (int i = 0; i < vechime; i++)
		{
			cout << "Bonus#" << i << " = ";
			cin >> bonusuri[i];
		}
		cout << bonusuri << endl;
	}
	else {
		vechime = 0;
		bonusuri = nullptr;
	}
	angajati[index].setBonus(bonusuri, vechime);
	//cout << angajati[index].getBonus() << endl;

	cout << "Angajatul cu Id#:" << angajati[index].getIdAngajat() << " a fost modificat." << endl;
	cout << angajati[index];
	cout << endl;

	Angajat::salveaza("angajati.bin", angajati);
}
void sterge_angajat() {
	std::system("CLS");
	cout << "Introduceti Id(#) angajat: ";
	int id;
	cin >> id;

	int index = -1;
	for (int i = 0; i < size(angajati); ++i)
	{
		if (angajati[i].getIdAngajat() == id)
		{
			index = i;
		}
	}

	if (index != -1)
	{
		angajati.erase(angajati.begin() + index);
	}

	Angajat::salveaza("angajati.bin", angajati);
}
void meniuAngajat() {
	// Incarcare Meniu Angajat
	std::system("CLS");
	angajati = Angajat::incarca("angajati.bin");

	while (true)
	{
		header();
		titluCinema();
		titlu("Angajat");
		randuriLibere();

		string meniu1 = "1. Afiseaza angajatii";
		string meniu2 = "2. Afiseaza angajat";
		string meniu3 = "3. Adauga angajat";
		string meniu4 = "4. Modifica angajat";
		string meniu5 = "5. Sterge angajat";
		string meniu6 = "6. Meniu Principal";
		string meniu7 = "7. Iesire Program";

		afisareMeniu(meniu1, sizeMargini);
		afisareMeniu(meniu2, sizeMargini);
		afisareMeniu(meniu3, sizeMargini);
		afisareMeniu(meniu4, sizeMargini);
		afisareMeniu(meniu5, sizeMargini);
		afisareMeniu(meniu6, sizeMargini);
		afisareMeniu(meniu7, sizeMargini);

		randuriLibere();
		footer();
		cout << endl;
		for (int i = 0; i < 20; i++) {
			cout << " ";
		}
		std::cout << "Introdu codul unei comenzi: ";

		int cmd;
		std::cin >> cmd;
		if (cmd == 1)
		{
			lista_angajati();
		}
		else if (cmd == 2)
		{
			lista_angajat();
		}
		else if (cmd == 3)
		{
			adauga_angajat();
		}
		else if (cmd == 4)
		{
			modifica_angajat();
		}
		else if (cmd == 5)
		{
			sterge_angajat();
		}
		else if (cmd == 6)
		{
			meniu_principal();
		}
		else if (cmd == 7)
		{
			break;
		}
	}
}

//Cinemas
void lista_cinemas() {
	std::system("CLS");
	cout << "Lista de cinemas: " << endl;
	for (Cinema& c : cinemas) {
		cout << "Id#" << c.getIdCinema() << ". Adresa: " << c.getAdresa() << endl;
		cout << "     Intrari: " << c.getNrIntrari() << endl;
	}
	cout << "Total de " << size(cinemas) << " cinema/s.";
	cout << endl;
}
void lista_cinema() {
	std::system("CLS");
	cout << "Introduceti Id(#) cinema: ";
	int id;
	cin >> id;

	for (int i = 0; i < size(cinemas); i++) {
		if (cinemas[i].getIdCinema() == id) {
			cout << cinemas[i] << endl;
		}
	}

	if (size(cinemas) == 0) {
		cout << "Cinema-ul cu Id#" << id << " nu exista." << endl;
	}
}
void adauga_cinema() {
	std::system("CLS");
	cout << "Pentru salvarea unui nou cinema, introduceti urmatoarele date:" << endl;;
	cout << "Adresa: ";
	char buffer[100];
	char* adresa;
	cin >> ws;
	cin.getline(buffer, 99);
	adresa = new char[strlen(buffer) + 1];
	strcpy_s(adresa, strlen(buffer) + 1, buffer);

	cout << "Numar Intrari: ";
	int intrari;
	cin >> intrari;

	cout << "Profit: ";
	double* profit;
	if (intrari > 0) {
		profit = new double[intrari];
		for (int i = 0; i < intrari; i++)
		{
			cout << "Profit#" << i << " = ";
			cin >> profit[i];
		}
	}
	else {
		intrari = 0;
		profit = nullptr;
	}

	Cinema c(adresa, intrari, profit);
	cinemas.emplace_back(c);

	cout << "Cinema-ul a fost adaugat." << endl;
	cout << c << endl;

	Cinema::salveaza("cinemas.bin", cinemas);
}
void modifica_cinema() {
	std::system("CLS");
	cout << "Pentru modificarea unui cinema, introduceti urmatoarele date:" << endl;
	cout << "Introduceti Id(#) cinema: ";
	int id;
	cin >> id;

	int index = -1;
	for (int i = 0; i < size(cinemas); ++i)
	{
		if (cinemas[i].getIdCinema() == id)
		{
			index = i;
		}
	}

	if (index == -1)
	{
		cout << "Cinema-ul cu Id#" << id << " nu a fost gasit." << endl;
		cout << "Mergeti la lista cu cinemas, folosind tasta 1.";
		return;
	}

	cout << "Adresa: ";
	char buffer[100];
	char* adresa;
	cin >> ws;
	cin.getline(buffer, 99);
	adresa = new char[strlen(buffer) + 1];
	strcpy_s(adresa, strlen(buffer) + 1, buffer);
	cinemas[index].setAdresa(adresa);

	cout << "Numar intrari: ";
	int intrari;
	cin >> intrari;
	cinemas[index].setNrIntrari(intrari);

	cout << "Profit: ";
	double* profit;
	if (intrari > 0) {
		profit = new double[intrari];
		for (int i = 0; i < intrari; i++)
		{
			cout << "Bonus#" << i << " = ";
			cin >> profit[i];
		}
		cout << profit << endl;
	}
	else {
		intrari = 0;
		profit = nullptr;
	}
	cinemas[index].setProfitIntrari(profit, intrari);
	cinemas[index].getProfitIntrari();

	cout << "Cinema-ul cu Id#:" << cinemas[index].getIdCinema() << " a fost modificat." << endl;
	cout << cinemas[index];
	cout << endl;

	Cinema::salveaza("cinemas.bin", cinemas);
}
void sterge_cinema() {
	std::system("CLS");
	cout << "Introduceti Id(#) Cinema: ";
	int id;
	cin >> id;

	int index = -1;
	for (int i = 0; i < size(cinemas); ++i)
	{
		if (cinemas[i].getIdCinema() == id)
		{
			index = i;
		}
	}

	if (index != -1)
	{
		cinemas.erase(cinemas.begin() + index);
	}

	Cinema::salveaza("cinemas.bin", cinemas);
}
void meniuCinema() {
	//Incarcare Meniu Cinema
	std::system("CLS");
	cinemas = Cinema::incarca("cinemas.bin");

	while (true)
	{
		header();
		titluCinema();
		titlu("Cinema ");
		randuriLibere();

		string meniu1 = "1. Afiseaza cinemas";
		string meniu2 = "2. Afiseaza cinema";
		string meniu3 = "3. Adauga cinema";
		string meniu4 = "4. Modifica cinema";
		string meniu5 = "5. Sterge cinema";
		string meniu6 = "6. Meniu Principal";
		string meniu7 = "7. Iesire Program";

		afisareMeniu(meniu1, sizeMargini);
		afisareMeniu(meniu2, sizeMargini);
		afisareMeniu(meniu3, sizeMargini);
		afisareMeniu(meniu4, sizeMargini);
		afisareMeniu(meniu5, sizeMargini);
		afisareMeniu(meniu6, sizeMargini);
		afisareMeniu(meniu7, sizeMargini);

		randuriLibere();
		footer();
		cout << endl;
		for (int i = 0; i < 20; i++) {
			cout << " ";
		}
		std::cout << "Introdu codul unei comenzi: ";

		int cmd;
		std::cin >> cmd;
		if (cmd == 1)
		{
			lista_cinemas();
		}
		else if (cmd == 2)
		{
			lista_cinema();
		}
		else if (cmd == 3)
		{
			adauga_cinema();
		}
		else if (cmd == 4)
		{
			modifica_cinema();
		}
		else if (cmd == 5)
		{
			sterge_cinema();
		}
		else if (cmd == 6)
		{
			meniu_principal();
		}
		else if (cmd == 7)
		{
			break;
		}
	}
}

//Bilete
void lista_bilete() {
	std::system("CLS");
	cout << "Lista de bilete: " << endl;
	for (Bilet& b : bilete) {
		cout << "Id#" << b.getIdBilet() << ". Nume Film: " << b.getNumeFilm() << endl;
		cout << "     Numar Sala: " << b.getIdSala() << endl;
		cout << "     Numar Rand: " << b.getRandBilet() << endl;
	}
	cout << "Total de " << size(bilete) << " bilet/e.";
	cout << endl;
}
void lista_bilet() {
	std::system("CLS");
	cout << "Introduceti Id(#) bilet: ";
	int id;
	cin >> id;

	for (int i = 0; i < size(bilete); i++) {
		if (bilete[i].getIdBilet() == id) {
			cout << bilete[i] << endl;
		}
	}

	if (size(bilete) == 0) {
		cout << "Biletul cu Id#" << id << " nu exista." << endl;
	}
}
void adauga_bilet() {
	std::system("CLS");
	cout << "Pentru salvarea unui nou bilet, introduceti urmatoarele date:" << endl;;
	cout << "Nume Film: ";
	char buffer[100];
	char* numefilm;
	cin >> ws;
	cin.getline(buffer, 99);
	numefilm = new char[strlen(buffer) + 1];
	strcpy_s(numefilm, strlen(buffer) + 1, buffer);

	cout << "Id Sala: ";
	int idSala;
	cin >> idSala;
	cout << idSala;

	cout << "Numar Bilete: ";
	int nrBilete;
	cin >> nrBilete;
	cout << nrBilete;

	cout << "Pret Bilete: ";
	double* pret;
	if (nrBilete > 0) {
		pret = new double[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			cout << "Pret Bilet#" << i << " = ";
			cin >> pret[i];
		}
	}
	else {
		nrBilete = 0;
		pret = nullptr;
	}
	
	cout << "Rand: ";
	int rand;
	cin >> rand;

	cout << "Nr Loc/uri: ";
	int* loc;
	if (nrBilete > 0) {
		loc = new int[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			cout << "Loc Bilet#" << i << " = ";
			cin >> loc[i];
		}
	}
	else {
		nrBilete = 0;
		loc = nullptr;
	}

	for (int i = 0; i < nrBilete; i++) {
		cout << pret[i] << endl;
		cout << loc[i] << endl;
	}

	Bilet b(numefilm, idSala, loc, rand, nrBilete, pret);
	bilete.emplace_back(b);

	cout << "Biletul a fost adaugat." << endl;
	cout << b << endl;

	Bilet::salveaza("bilete.bin", bilete);
}
void modifica_bilet() {
	std::system("CLS");
	cout << "Pentru modificarea unui bilet, introduceti urmatoarele date:" << endl;
	cout << "Introduceti Id(#) bilet: ";
	int id;
	cin >> id;

	int index = -1;
	for (int i = 0; i < size(bilete); ++i)
	{
		if (bilete[i].getIdBilet() == id)
		{
			index = i;
		}
	}

	if (index == -1)
	{
		cout << "Biletul cu Id#" << id << " nu a fost gasit." << endl;
		cout << "Mergeti la lista cu bilete, folosind tasta 1.";
		return;
	}

	cout << "Nume Film: ";
	char buffer[100];
	char* nume;
	cin >> ws;
	cin.getline(buffer, 99);
	nume = new char[strlen(buffer) + 1];
	strcpy_s(nume, strlen(buffer) + 1, buffer);
	bilete[index].setNumeFilm(nume);

	cout << "Numar sala: ";
	int sala;
	cin >> sala;
	bilete[index].setIdSala(sala);

	cout << "Numar rand: ";
	int rand;
	cin >> rand;
	bilete[index].setRandBilet(rand);

	cout << "Numar bilete: ";
	int nrBilete;
	cin >> nrBilete;
	bilete[index].setNrBilete(nrBilete);

	cout << "Pret bilet/e: ";
	double* pret;
	if (nrBilete > 0) {
		pret = new double[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			cout << "Pret#" << i << " = ";
			cin >> pret[i];
		}
		cout << pret << endl;
	}
	else {
		nrBilete = 0;
		pret = nullptr;
	}
	bilete[index].setPretBilet(pret, nrBilete);
	bilete[index].getPretBilet();

	cout << "Loc bilet/e: ";
	int* loc;
	if (nrBilete > 0) {
		loc = new int[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			cout << "Loc#" << i << " = ";
			cin >> loc[i];
		}
		cout << loc << endl;
	}
	else {
		nrBilete = 0;
		loc = nullptr;
	}
	bilete[index].setLocBilet(loc, nrBilete);
	bilete[index].getLocBilet();

	cout << "Biletul cu Id#:" << bilete[index].getIdBilet() << " a fost modificat." << endl;
	cout << bilete[index];
	cout << endl;

	Bilet::salveaza("bilete.bin", bilete);
}
void sterge_bilet() {
	std::system("CLS");
	cout << "Introduceti Id(#) Bilet: ";
	int id;
	cin >> id;

	int index = -1;
	for (int i = 0; i < size(bilete); ++i)
	{
		if (bilete[i].getIdBilet() == id)
		{
			index = i;
		}
	}

	if (index != -1)
	{
		bilete.erase(bilete.begin() + index);
	}

	Bilet::salveaza("bilete.bin", bilete);
}
void meniuBilet() {
	//Incarcare Meniu Bilet
	std::system("CLS");
	bilete = Bilet::incarca("bilete.bin");

	while (true)
	{
		header();
		titluCinema();
		titlu("Bilet");
		randuriLibere();

		string meniu1 = "1. Afiseaza bilete";
		string meniu2 = "2. Afiseaza bilet";
		string meniu3 = "3. Adauga bilet";
		string meniu4 = "4. Modifica bilet";
		string meniu5 = "5. Sterge bilet";
		string meniu6 = "6. Meniu Principal";
		string meniu7 = "7. Iesire Program";

		afisareMeniu(meniu1, sizeMargini);
		afisareMeniu(meniu2, sizeMargini);
		afisareMeniu(meniu3, sizeMargini);
		afisareMeniu(meniu4, sizeMargini);
		afisareMeniu(meniu5, sizeMargini);
		afisareMeniu(meniu6, sizeMargini);
		afisareMeniu(meniu7, sizeMargini);

		randuriLibere();
		footer();
		cout << endl;
		for (int i = 0; i < 20; i++) {
			cout << " ";
		}
		std::cout << "Introdu codul unei comenzi: ";

		int cmd;
		std::cin >> cmd;
		if (cmd == 1)
		{
			lista_bilete();
		}
		else if (cmd == 2)
		{
			lista_bilet();
		}
		else if (cmd == 3)
		{
			adauga_bilet();
		}
		else if (cmd == 4)
		{
			modifica_bilet();
		}
		else if (cmd == 5)
		{
			sterge_bilet();
		}
		else if (cmd == 6)
		{
			meniu_principal();
		}
		else if (cmd == 7)
		{
			break;
		}
	}
}

//Sali
void lista_sali() {
	std::system("CLS");
	cout << "Lista de sali: " << endl;
	for (Sala& s : sali) {
		cout << "Id#" << s.getIdSala() << ". Nume Sala: " << s.getNumeSala() << endl;
		cout << "     Numar Rand: " << s.getNrRanduri() << endl;
		cout << "     Numar Loc: " << s.getNrLocuri() << endl;
	}
	cout << "Total de " << size(sali) << " sala/i.";
	cout << endl;
}
void lista_sala() {
	std::system("CLS");
	cout << "Introduceti Id(#) sala: ";
	int id;
	cin >> id;

	for (int i = 0; i < size(sali); i++) {
		if (sali[i].getIdSala() == id) {
			cout << sali[i] << endl;
		}
	}

	if (size(sali) == 0) {
		cout << "Sala cu Id#" << id << " nu exista." << endl;
	}
}
void adauga_sala() {
	std::system("CLS");
	cout << "Pentru salvarea unei sali, introduceti urmatoarele date:" << endl;;
	cout << "Nume Sala: ";
	char buffer[100];
	char* numeSala;
	cin >> ws;
	cin.getline(buffer, 99);
	numeSala = new char[strlen(buffer) + 1];
	strcpy_s(numeSala, strlen(buffer) + 1, buffer);

	cout << "Rand: ";
	int rand;
	cin >> rand;
	cout << rand << endl;

	cout << "Loc: ";
	int loc;
	cin >> loc;
	cout << loc << endl;

	Sala s(numeSala, rand, loc);
	sali.emplace_back(s);

	cout << "Sala a fost adaugata." << endl;
	cout << s << endl;

	Sala::salveaza("sali.bin", sali);
}
void modifica_sala() {
	std::system("CLS");
	cout << "Pentru modificarea unei sali, introduceti urmatoarele date:" << endl;
	cout << "Introduceti Id(#) sala: ";
	int id;
	cin >> id;

	int index = -1;
	for (int i = 0; i < size(sali); ++i)
	{
		if (sali[i].getIdSala() == id)
		{
			index = i;
		}
	}

	if (index == -1)
	{
		cout << "Sala cu Id#" << id << " nu a fost gasita." << endl;
		cout << "Mergeti la lista cu sali, folosind tasta 1.";
		return;
	}

	cout << "Nume Sala: ";
	char buffer[100];
	char* nume;
	cin >> ws;
	cin.getline(buffer, 99);
	nume = new char[strlen(buffer) + 1];
	strcpy_s(nume, strlen(buffer) + 1, buffer);
	bilete[index].setNumeFilm(nume);

	cout << "Numar rand: ";
	int rand;
	cin >> rand;
	sali[index].setNrRanduri(rand);

	cout << "Numar loc: ";
	int loc;
	cin >> loc;
	sali[index].setNrLocuri(loc);

	cout << "Sala cu Id#:" << sali[index].getIdSala() << " a fost modificat." << endl;
	cout << sali[index];
	cout << endl;

	Sala::salveaza("sali.bin", sali);
}
void sterge_sala() {
	std::system("CLS");
	cout << "Introduceti Id(#) Sala: ";
	int id;
	cin >> id;

	int index = -1;
	for (int i = 0; i < size(sali); ++i)
	{
		if (sali[i].getIdSala() == id)
		{
			index = i;
		}
	}

	if (index != -1)
	{
		sali.erase(sali.begin() + index);
	}

	Sala::salveaza("sali.bin", sali);
}
void meniuSala() {
	//Incarcare Meniu Sala
	std::system("CLS");
	sali = Sala::incarca("sali.bin");

	while (true)
	{
		header();
		titluCinema();
		titlu("Bilet");
		randuriLibere();

		string meniu1 = "1. Afiseaza salile";
		string meniu2 = "2. Afiseaza sala";
		string meniu3 = "3. Adauga sala";
		string meniu4 = "4. Modifica sala";
		string meniu5 = "5. Sterge sala";
		string meniu6 = "6. Meniu Principal";
		string meniu7 = "7. Iesire Program";

		afisareMeniu(meniu1, sizeMargini);
		afisareMeniu(meniu2, sizeMargini);
		afisareMeniu(meniu3, sizeMargini);
		afisareMeniu(meniu4, sizeMargini);
		afisareMeniu(meniu5, sizeMargini);
		afisareMeniu(meniu6, sizeMargini);
		afisareMeniu(meniu7, sizeMargini);

		randuriLibere();
		footer();
		cout << endl;
		for (int i = 0; i < 20; i++) {
			cout << " ";
		}
		std::cout << "Introdu codul unei comenzi: ";

		int cmd;
		std::cin >> cmd;
		if (cmd == 1)
		{
			lista_sali();
		}
		else if (cmd == 2)
		{
			lista_sala();
		}
		else if (cmd == 3)
		{
			adauga_sala();
		}
		else if (cmd == 4)
		{
			modifica_sala();
		}
		else if (cmd == 5)
		{
			sterge_sala();
		}
		else if (cmd == 6)
		{
			meniu_principal();
		}
		else if (cmd == 7)
		{
			break;
		}
	}
}

void meniu_principal()
{
	std::system("CLS");
	header();
	titluCinema();
	titlu("Meniu Principal");
	randuriLibere();

	string meniu1 = "1. Cinema";
	string meniu2 = "2. Film";
	string meniu3 = "3. Bilet";
	string meniu4 = "4. Sala";
	string meniu5 = "5. Angajat";
	string meniu6 = "6. Iesire Program";

	afisareMeniu(meniu1, sizeMargini);
	afisareMeniu(meniu2, sizeMargini);
	afisareMeniu(meniu3, sizeMargini);
	afisareMeniu(meniu4, sizeMargini);
	afisareMeniu(meniu5, sizeMargini);
	afisareMeniu(meniu6, sizeMargini);

	randuriLibere();
	footer();
	cout << endl;

	int optiune;
	for (int i = 0; i < 20; i++) {
		cout << " ";
	}
	cout << "Introduceti meniul dorit: ";
	cin >> optiune;
	if (optiune == 1) {
		//cinema
		meniuCinema();
	}
	else if (optiune == 2) {
		//film
		meniuFilm();
	}
	else if (optiune == 3) {
		//bilet
		meniuBilet();
	}
	else if (optiune == 4) {
		//sala
		meniuSala();
	}
	else if (optiune == 5) {
		//angajat
		meniuAngajat();
	}
}
void harry_intro() {
	vector<string> harry = {
		"                                                                            ",
		"                                                                            ",
		"            _            _.,----,                                           ",
		" __  _.-._ / '-.        -  ,._  \\)                                          ",
		"|  `-)_   '-.   \\       / < _ )/\" }                                         ",
		"/__    '-.   \\   '-, ___(c-(6)=(6)                                          ",
		" , `'.    `._ '.  _,'   >\\    \"  )                                          ",
		" :;;,,'-._   '---' (  ( \" / `. -= '/                                        ",
		";:;;:;;,  '..__    ,`-.`)'- '--'                                            ",
		";';:;;;;;'-._ /'._|   Y/   _/' \\                                            ",
		"      '''\"._ F | _ / _.'._   `\\                                             ",
		"             L    \\   \\/     '._  \\                                         ",
		"      .-,-,_ |     `.  `'---,  \\_ _|                                        ",
		"      //    'L    /  \\,   (\"--',=`)7                                        ",
		"     | `._       : _,  \\  /'`-._L,_'-._                                     ",
		"     '--' '-.\\__/ _L   .`'         './/                                     ",
		"                 [ (  /                                                     ",
		"                  ) `{                                                      ",
		"       snd        \\__)                                                      ",
		"                                                                            ",
		"                                                                            " };
	for (int j = 0; j < 80; j++) {
		for (int i = 0; i < size(harry); i++) {
			cout << harry[i] << endl;
			string aux = harry[i].substr(harry[i].length() - 2);
			harry[i].erase(harry[i].length() - 2);
			harry[i].insert(0, aux);
		};

		cout << "Apasati tasta enter pentru a va indrepta spre meniul principal.";
		//string enter;
		//cin >> enter;
		Sleep(50);
		system("CLS");
	}
}

int main()
{
	harry_intro();
	meniu_principal();

	return 0;
}
