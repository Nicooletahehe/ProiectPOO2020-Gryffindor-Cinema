#include <iostream>
#include <vector>

#include "Header Files/Cinema.h"
#include "Header Files/Film.h"
#include "Header Files/Bilet.h"
#include "Header Files/Sala.h"
#include "Header Files/Angajat.h"

using namespace std;

//Cinema-ul Griffindor isi pune la dispozitie cele 5 sali pentru vizionarea filmelor
//dupa urmatorul program: de la ora 16:00 vor rula doar 2 filme (pentru copii), la ora 18:30 vor rula
//3 filme, de la 21:15 4 filme si de la 23:30 5 filme;
//vom mai adauga detalii treptat

vector<Film> filme;

void command_lm() // list movies
{
	cout << "Se afiseaza " << filme.size() << " filme:\n";
	for (Film& f : filme)
	{
		cout << "#" << f.getId() << " -> " << f.getNume() << "\n";
	}
	cout << "\n";
}

void command_rm() // read movie
{
	cout << "Introdu ID (#) film: ";
	int id;
	cin >> id;

	for (int i = 0; i < filme.size(); ++i)
	{
		if (filme[i].getId() == id)
		{
			cout << filme[i];
		}
	}
}

void command_am() // add movie
{
	cout << "Nume film: ";
	string nume;
	cin >> nume; // sarim peste \n
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

int main()
{
	// Incarcare filme
	filme = Film::incarca("filme.bin");

	while (true)
	{
		std::cout << "----------------------------------\n";
		std::cout << "\n";
		std::cout << "Meniu:\n";
		std::cout << "\n";
		std::cout << "LM. Afiseaza filmele\n";
		std::cout << "RM. Afiseaza film\n";
		std::cout << "AM. Adauga film\n";
		std::cout << "UM. Modifica film\n";
		std::cout << "DM. Sterge film\n";
		std::cout << "E. Iesire program\n";
		std::cout << "\n";
		std::cout << "Introdu codul unei comenzi (ex. LM, AM, UM sau DM): ";

		std::string cmd;
		std::cin >> cmd;

		if (cmd == "LM")
		{
			command_lm();
		}
		else if (cmd == "RM")
		{
			command_rm();
		}
		else if (cmd == "AM")
		{
			command_am();
		}
		else if (cmd == "UM")
		{
			command_um();
		}
		else if (cmd == "DM")
		{
			command_dm();
		}
		else if (cmd == "E")
		{
			break;
		}
	}

	//
	//interfata consola meniu
	//for (int i = 0; i < 77; i++) {
	//	cout << "=";
	//}
	//cout << "Meniu";

	/*cout << "\xC9";
	cout << "\xCD";
	cout << "\xBB";
	cout << endl;
	cout << "\xBA"<<" "<< "\xBA" <<endl;
	cout << "\xC8";
	cout << "\xCD";
	cout << "\xBC";*/

	return 0;
}
