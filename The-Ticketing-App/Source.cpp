#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>
#include <vector>
#include <set>
#include <list>
using namespace std;
#pragma warning(disable:4996)


//Interfata
class File
{
public:

	virtual void writeToFile(fstream& file) = 0;
	virtual void readFromFile(fstream& file) = 0;
};

//Prima clasa
class Eveniment : public File
{
private:
	char* denumireEveniment;
	char* tipEveniment;//vector alocat dinamic de caractere
	int durataEveniment;
	int nrPersoane;
	static int nrEvenimente;
public:


	//constructor fara paratmetri
	Eveniment()
	{
		this->denumireEveniment = new char[strlen("Necunoscut") + 1];
		strcpy(this->denumireEveniment, "Necunoscut");
		this->tipEveniment = new char[strlen("Necunoscut") + 1];
		strcpy(this->tipEveniment, "Necunoscut");
		this->durataEveniment = 0;
		this->nrPersoane = 0;
		nrEvenimente++;

	}
	//constructor cu parametri
	Eveniment(const char* denumireEveniment, const char* tipEveniment, int durataEveniment, int nrPersoane)
	{
		if (denumireEveniment != NULL)
		{
			this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
			strcpy(this->denumireEveniment, denumireEveniment);

		}
		else
			this->denumireEveniment = NULL;
		if (tipEveniment != NULL)
		{
			this->tipEveniment = new char[strlen(tipEveniment) + 1];
			strcpy(this->tipEveniment, tipEveniment);

		}
		else
			this->tipEveniment = NULL;
		if (durataEveniment > 0)
		{
			this->durataEveniment = durataEveniment;
		}
		else
			this->durataEveniment = 0;
		if (nrPersoane > 0)
		{
			this->nrPersoane = nrPersoane;
		}
		else
			this->nrPersoane = 0;
		nrEvenimente++;

	}
	//constructor de copiere
	Eveniment(const Eveniment& e)
	{
		if (e.denumireEveniment != NULL)
		{
			this->denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
			strcpy(this->denumireEveniment, e.denumireEveniment);

		}
		else
			this->denumireEveniment = NULL;
		if (e.tipEveniment != NULL)
		{
			this->tipEveniment = new char[strlen(e.tipEveniment) + 1];
			strcpy(this->tipEveniment, e.tipEveniment);
		}
		else
			this->tipEveniment = NULL;
		if (e.durataEveniment > 0)
		{
			this->durataEveniment = e.durataEveniment;
		}
		else
			this->durataEveniment = 0;
		if (e.nrPersoane > 0)
		{
			this->nrPersoane = e.nrPersoane;
		}
		else
			this->nrPersoane = 0;
		nrEvenimente++;

	}
	//destructor
	~Eveniment()
	{
		if (this->denumireEveniment != NULL)
			delete[]this->denumireEveniment;
		if (this->tipEveniment != NULL)
			delete[]this->tipEveniment;
		nrEvenimente--;

	}
	//getter pentru denumireEveniment
	char* getDenumireEveniment()
	{
		char* copieDenumire = new char[strlen(this->denumireEveniment) + 1];
		strcpy(copieDenumire, this->denumireEveniment);
		return copieDenumire;
	}
	//getter pentru tipEveniment
	char* getTipEveniment()
	{
		char* copieTip = new char[strlen(this->tipEveniment) + 1];
		strcpy(copieTip, this->tipEveniment);
		return copieTip;
	}
	//getter pentru durataEveniment
	int getDurataEveniment()
	{
		return this->durataEveniment;
	}
	//getter pentru nrPersoane
	int getNrPersoane()
	{
		return this->nrPersoane;
	}
	//setter pentru denumireEveniment
	void setDenumireEveniment(const char* denumireEveniment)
	{
		if (this->denumireEveniment != NULL)
		{
			delete[]this->denumireEveniment;
		}
		this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
		strcpy(this->denumireEveniment, denumireEveniment);

	}
	//setter pentru tipEveniment
	void setTipEveniment(const char* tipEveniment)
	{
		if (this->tipEveniment != NULL)
		{
			delete[]this->tipEveniment;
		}
		this->tipEveniment = new char[strlen(tipEveniment) + 1];
		strcpy(this->tipEveniment, tipEveniment);
	}
	//setter pentru durataEveniment
	void setDurataEveniment(int durata)
	{
		durataEveniment = durata;
	}
	//setter pentru nrPersoane
	void setNrPersoane(int nr)
	{
		nrPersoane = nr;
	}

	//operator =
	Eveniment& operator=(const Eveniment& e)
	{
		if (e.denumireEveniment != NULL)
		{
			this->denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
			strcpy(this->denumireEveniment, e.denumireEveniment);

		}
		else
			this->denumireEveniment = NULL;
		if (e.tipEveniment != NULL)
		{
			this->tipEveniment = new char[strlen(e.tipEveniment) + 1];
			strcpy(this->tipEveniment, e.tipEveniment);
		}
		else
			this->tipEveniment = NULL;
		if (e.durataEveniment > 0)
		{
			this->durataEveniment = e.durataEveniment;
		}
		else
			this->durataEveniment = 0;
		if (e.nrPersoane > 0)
		{
			this->nrPersoane = e.nrPersoane;
		}
		else
			this->nrPersoane = 0;

		return *this;

	}

	//operator <
	bool operator<(Eveniment e)
	{
		return this->durataEveniment < e.durataEveniment;
	}

	//operator +
	Eveniment operator+(int x)
	{
		Eveniment aux = *this;
		if (aux.durataEveniment + x < 90)
			aux.durataEveniment += x;
		else
			aux.durataEveniment = 90;
		return aux;

	}
	//metoda statica
	static int getNrEvenimente();

	//metoda pentru a vedea daca durata este mai mare decat 90
	bool verificareDurata()
	{
		if (durataEveniment > 90)
			return true;
		else
			return false;
	}

	//metoda pentru a vedea daca nr de persoane este mai mic decat 20000
	bool verificareNrPersoane()
	{
		if (nrPersoane < 20000)
			return true;
		else
			return false;

	}
	void writeToFile(fstream& file)
	{
		//char*
		int lg = strlen(this->denumireEveniment) + 1;
		file.write((char*)&lg, sizeof(int));
		file.write(this->denumireEveniment, lg);
		//char*
		int lg2 = strlen(this->tipEveniment) + 1;
		file.write((char*)&lg2, sizeof(int));
		file.write(this->tipEveniment, lg2);
		//int durataEveniment
		file.write((char*)&this->durataEveniment, sizeof(int));
		//int nrPersoane
		file.write((char*)&this->nrPersoane, sizeof(int));

	}

	void readFromFile(fstream& file)
	{
		//citire nume(char*);
		delete[] this->denumireEveniment;
		int lg = 0;
		file.read((char*)&lg, sizeof(int));
		this->denumireEveniment = new char[lg];
		file.read(this->denumireEveniment, lg);
		//citire nume(char*);
		delete[] this->tipEveniment;
		int lg2 = 0;
		file.read((char*)&lg2, sizeof(int));
		this->tipEveniment = new char[lg2];
		file.read(this->tipEveniment, lg2);
		//citire int durataEveniment
		file.read((char*)&this->durataEveniment, sizeof(int));
		//citire int nrPersoane
		file.read((char*)&this->nrPersoane, sizeof(int));
	}


	friend ostream& operator<<(ostream& out, const Eveniment& e);
	friend istream& operator>>(istream& in, Eveniment& e);
	friend ofstream& operator<<(ofstream& out, const Eveniment& e);
	friend ifstream& operator>>(ifstream& in, Eveniment& e);

};

int Eveniment::nrEvenimente = 0;

//operator <<
ostream& operator<<(ostream& out, const Eveniment& e)
{
	out << "Denumirea evenimentului:" << e.denumireEveniment << endl;
	out << "Tipul evenimentului:" << e.tipEveniment << endl;
	out << "Durata evenimentului:" << e.durataEveniment << endl;
	out << "Numarul de persoane:" << e.nrPersoane << endl;
	out << "Numarul evenimentelor:" << e.nrEvenimente;
	return out;
}
//operator >>
istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Denumirea evenimentului:" << endl;
	in >> e.denumireEveniment;
	cout << "Tipul evenimentului:" << endl;
	in >> e.tipEveniment;
	cout << "Durata evenimentului:" << endl;
	in >> e.durataEveniment;
	cout << "Numarul de persoane:" << endl;
	in >> e.nrPersoane;
	return in;
}
ofstream& operator<<(ofstream& g, const Eveniment& e)
{
	g << e.denumireEveniment << ",";
	g << e.tipEveniment << ",";
	g << e.durataEveniment << ",";
	g << e.nrPersoane << ",";
	return g;
}

ifstream& operator>>(ifstream& f, Eveniment& e)
{
	delete[]e.denumireEveniment;
	delete[]e.tipEveniment;
	char denumireEv[10];
	f >> denumireEv;
	e.denumireEveniment = new char[strlen(denumireEv) + 1];
	strcpy(e.denumireEveniment, denumireEv);
	char tip[10];
	f >> tip;
	e.tipEveniment = new char[strlen(tip) + 1];
	strcpy(e.tipEveniment, tip);
	f >> e.durataEveniment;
	f >> e.nrPersoane;
	return f;

}


//Has a
class Intrare : public Eveniment
{
private:
	int nrIntrari;
	vector<Eveniment*> eveniment;
public:
	Intrare()
	{
		this->nrIntrari = 0;
	}

	Intrare(int nrIntrari)
	{
		this->nrIntrari = nrIntrari;
	}
	Intrare(const Intrare& i)
	{
		this->nrIntrari = i.nrIntrari;
		this->eveniment = i.eveniment;
	}

	~Intrare()
	{
		nrIntrari = 0;

		for (int i = 0; i < eveniment.size(); i++)
			eveniment.pop_back();
	}

	void add_eveniment(Eveniment* e)

	{
		this->eveniment.push_back(e);
	}
	friend ostream& operator<<(ostream& out, const Intrare& i)
	{
		out << "\nNumarul intrarilor: " << i.nrIntrari << endl;
		return out;
	}
};


//A doua clasa
class Bilet :public File
{
private:

	char* tipBilet;
	int nrBilete; //nr de elemente al vectorului
	float* valoareBilete;//vector
	string nrRand;
	string nrLoc;
	static long id;

public:

	//constructor fara parametri
	Bilet()
	{
		this->tipBilet = new char[strlen("Necunoscut") + 1];
		strcpy(this->tipBilet, "Necunoscut");
		valoareBilete = nullptr;
		nrBilete = 0;
		this->nrLoc = "0";
		this->nrRand = "0";

		id = id + rand() % 100000;

	}

	//constructor cu parametri
	Bilet(const char* tipBilet, int nrBilete, float* valoare, string nrLoc, string nrRand)
	{
		if (tipBilet != NULL)
		{
			this->tipBilet = new char[strlen(tipBilet) + 1];
			strcpy(this->tipBilet, tipBilet);

		}
		else
			this->tipBilet = NULL;


		if (nrBilete != NULL && valoare != NULL)
		{
			if (nrBilete > 0)
			{
				valoareBilete = new float[nrBilete];
				for (int i = 0; i < nrBilete; i++)
					this->valoareBilete[i] = valoare[i];
				this->nrBilete = nrBilete;
			}

		}

		this->nrLoc = nrLoc;
		this->nrRand = nrRand;
		id = id + rand() % 100000;
	}

	//destructor
	~Bilet()
	{
		if (this->tipBilet != NULL)
		{
			delete[]this->tipBilet;
		}
		if (this->valoareBilete != nullptr)
		{
			delete[]this->valoareBilete;
		}
		id = id - rand() % 100000;
	}

	//constructor de copiere
	Bilet(const Bilet& b)
	{
		if (b.tipBilet != NULL)
		{
			this->tipBilet = new char[strlen(b.tipBilet) + 1];
			strcpy(this->tipBilet, b.tipBilet);

		}
		else
			this->tipBilet = NULL;
		this->nrBilete = b.nrBilete;
		this->valoareBilete = new float[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			this->valoareBilete[i] = b.valoareBilete[i];
		}
		this->nrLoc = b.nrLoc;
		this->nrRand = b.nrRand;

	}

	//operator =
	Bilet operator=(const Bilet& b)
	{
		if (b.tipBilet != NULL)
		{
			this->tipBilet = new char[strlen(b.tipBilet) + 1];
			strcpy(this->tipBilet, b.tipBilet);

		}
		else
			this->tipBilet = NULL;
		this->nrBilete = b.nrBilete;
		this->valoareBilete = new float[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			this->valoareBilete[i] = b.valoareBilete[i];
		}

		this->nrLoc = b.nrLoc;
		this->nrRand = b.nrRand;

		return *this;

	}

	//operator!
	bool operator!() {
		if (this->id > this->nrBilete) {
			return 0;
		}
		else return 1;
	}


	//getter pentru tipBilet
	char* getTipBilet()
	{
		char* copieTip = new char[strlen(this->tipBilet) + 1];
		strcpy(copieTip, this->tipBilet);
		return copieTip;
	}

	//getter pentru valoareBilete
	float* getValoareBilete()
	{
		return this->valoareBilete;
	}
	//getter pentru nrBilete
	int getNrBilete()
	{
		return this->nrBilete;
	}

	//getter pentru nrLoc
	string getNrLoc()
	{
		return nrLoc;
	}
	//getter pentru nrRand
	string getNrRand()
	{
		return this->nrRand;
	}

	//setter pentru nrBilete
	void setNrBilete(int nrBilete)
	{
		if (nrBilete >= 0)
			this->nrBilete = nrBilete;
	}
	//setter pentru valoareBilete
	void setValoareBilete(int nrBilete, float* valoareBilete)
	{
		if (nrBilete >= 0 && valoareBilete != nullptr)
		{
			this->nrBilete = nrBilete;

			if (this->valoareBilete != nullptr)
				delete[] this->valoareBilete;

			this->valoareBilete = new float[this->nrBilete];

			for (int i = 0; i < this->nrBilete; i++)
				this->valoareBilete[i] = valoareBilete[i];
		}

	}


	//setter pentru tipBilet
	void setTipBilet(const char* tipBilet)
	{
		if (this->tipBilet != NULL)
		{
			delete[]this->tipBilet;
		}
		this->tipBilet = new char[strlen(tipBilet) + 1];
		strcpy(this->tipBilet, tipBilet);
	}

	//setter pentru nrLoc
	void setNrLoc(string loc)
	{
		nrLoc = loc;
	}
	//setter pentru nrRand
	void setNrRand(string rand)
	{
		nrRand = rand;
	}

	//operator +=
	Bilet operator+=(Bilet b) {
		if (this->nrBilete > 0 && b.nrBilete > 0) {
			float* tmp = new float[this->nrBilete + b.nrBilete];
			for (int i = 0; i < this->nrBilete; i++)
				tmp[i] = this->valoareBilete[i];
			for (int i = this->nrBilete;
				i < this->nrBilete + b.nrBilete; i++)
				tmp[i] = b.valoareBilete[i - this->nrBilete];
			delete[] this->valoareBilete;

			this->nrBilete += b.nrBilete;
			this->valoareBilete = tmp;
		}
		else if (this->nrBilete == 0 && b.nrBilete > 0) {
			this->nrBilete = b.nrBilete;
			this->valoareBilete = new float[this->nrBilete];
			for (int i = 0; i < this->nrBilete; i++)
				this->valoareBilete[i] = b.valoareBilete[i];
		}

		return *this;
	}

	//operator []
	float& operator[](int i) {
		if (i < this->nrBilete && i >= 0) {
			return this->valoareBilete[i];
		}

		float x = -1;
		return x;
	}



	//metoda statica
	static long getId()
	{
		return id;
	}
	void writeToFile(fstream& file)
	{
		//char*
		int lg = strlen(this->tipBilet) + 1;
		file.write((char*)&lg, sizeof(int));
		file.write(this->tipBilet, lg);
		//int
		file.write((char*)&this->nrBilete, sizeof(int));
		//int
		file.write((char*)&this->id, sizeof(int));
		//float*
		file.write((char*)&this->valoareBilete, sizeof(float*));
		//int
		file.write((char*)&this->nrLoc, sizeof(string));
		//int
		file.write((char*)&this->nrRand, sizeof(string));


	}

	void readFromFile(fstream& file)
	{
		//citire char* tipBilet
		delete[] this->tipBilet;
		int lg = 0;
		file.read((char*)&lg, sizeof(int));
		this->tipBilet = new char[lg];
		file.read(this->tipBilet, lg);
		//citire int nrBilete
		file.read((char*)&this->nrBilete, sizeof(int));
		//citite int id
		file.read((char*)&this->id, sizeof(int));
		//citire nrLoc
		file.read((char*)&this->nrLoc, sizeof(string));
		//citire nrRand
		file.read((char*)&this->nrRand, sizeof(string));
		//citire valoareBilete
		file.read((char*)&this->valoareBilete, sizeof(float*));
	}



	friend ostream& operator<<(ostream& out, Bilet b);
	friend istream& operator>>(istream& in, Bilet& b);
	friend ofstream& operator<<(ofstream& out, const Bilet& b);
	friend ifstream& operator>>(ifstream& in, Bilet& b);
};

long Bilet::id = 1234567;

ostream& operator<<(ostream& out, Bilet b)
{
	out << "Tipul biletului:" << b.tipBilet << endl;
	out << "Nr bilete:" << b.nrBilete << endl;
	for (int i = 0; i < b.nrBilete; i++)
		out << "Valoarea biletului " << i + 1 << " este " << b.valoareBilete[i] << endl;
	out << "Id-ul=" << b.id << endl;
	out << "Numarul locului este:" << b.nrLoc << endl;
	out << "Numarul randului este:" << b.nrRand << endl;

	return out;
}

istream& operator>>(istream& in, Bilet& b)
{
	cout << "Tipul biletului:" << endl;
	in >> b.tipBilet;
	cout << "Nr bilete:" << endl;
	in >> b.nrBilete;
	if (b.valoareBilete != nullptr)
		delete[]b.valoareBilete;
	b.valoareBilete = new float[b.nrBilete];
	cout << "Valoarea biletelor:" << endl;
	for (int i = 0; i < b.nrBilete; i++)
		in >> b.valoareBilete[i];
	cout << "Numarul locului este:" << endl;
	in >> b.nrLoc;
	cout << "Numarul randului este:" << endl;
	in >> b.nrRand;
	return in;

}
ofstream& operator<<(ofstream& g2, const Bilet& b)
{
	g2 << b.tipBilet << ",";
	g2 << b.nrBilete << ",";
	g2 << b.valoareBilete << ",";
	g2 << b.id << ",";
	g2 << b.nrLoc << ",";
	g2 << b.nrRand << ",";
	return g2;
}
ifstream& operator>>(ifstream& f2, Bilet& b)
{
	delete[]b.tipBilet;
	delete[]b.valoareBilete;
	char tip[10];
	f2 >> tip;
	b.tipBilet = new char[strlen(tip) + 1];
	strcpy(b.tipBilet, tip);
	f2 >> b.nrBilete;
	f2 >> b.id;
	f2 >> b.nrLoc;
	f2 >> b.nrRand;
	return f2;

}

//A treia clasa
class Locatie :public File
{
private:

	char* zone;
	int nrTotalLocuri;
	const int intrari;
	int nrRanduri;
	int nrScaun;
public:

	//constructori fara parametri
	Locatie() :intrari(3)
	{
		this->zone = new char[strlen("Necunoscut") + 1];
		strcpy(this->zone, "Necunoscut");
		this->nrRanduri = 0;
		this->nrScaun = 0;
		this->nrTotalLocuri = 0;

	}

	//constructor cu parametri
	Locatie(const char* zone, int nrRanduri, int nrScaun) :intrari(3)
	{
		if (zone != NULL)
		{
			this->zone = new char[strlen(zone) + 1];
			strcpy(this->zone, zone);

		}
		else
			this->zone = NULL;

		if (nrRanduri > 0)
		{
			this->nrRanduri = nrRanduri;
		}
		else
			this->nrRanduri = 0;

		if (nrScaun > 0)
		{
			this->nrScaun = nrScaun;
		}
		else
			this->nrScaun = 10;

		this->nrTotalLocuri = nrTotalLocuri;
	}

	//constructor de copiere
	Locatie(const Locatie& l) :intrari(l.intrari)
	{
		if (l.zone != NULL)
		{
			this->zone = new char[strlen(l.zone) + 1];
			strcpy(this->zone, l.zone);

		}
		else
			this->zone = NULL;

		if (l.nrRanduri > 0)
		{
			this->nrRanduri = l.nrRanduri;
		}
		else
			this->nrRanduri = 0;
		if (l.nrScaun > 0)
		{
			this->nrScaun = l.nrScaun;
		}
		else

			this->nrScaun = 10;

		this->nrTotalLocuri = l.nrTotalLocuri;

	}

	//destructor
	~Locatie()
	{
		if (this->zone != NULL)
			delete[]this->zone;

	}

	//getter pentru zone
	char* getZone()
	{
		char* copieZone = new char[strlen(this->zone) + 1];
		strcpy(copieZone, this->zone);
		return copieZone;

	}

	//getter pentru nrTotalLocuri
	int getNrTotalLocuri()
	{
		return this->nrTotalLocuri;
	}
	//getter pentru nrRanduri
	int getNrRanduri()
	{
		return this->nrRanduri;
	}

	//getter petru nrScaun
	int getNrScaun()
	{
		return this->nrScaun;
	}

	//setter pentru zone
	void setZone(const char* zone)
	{
		if (this->zone != NULL)
		{
			delete[]this->zone;
		}
		this->zone = new char[strlen(zone) + 1];
		strcpy(this->zone, zone);
	}

	//setter pentru nrRanduri
	void setNrRanduri(int randuri)
	{
		nrRanduri = randuri;

	}

	//setter pentru nrTotalLocuri
	void setNrTotalLocuri(int locuri)
	{
		nrTotalLocuri = locuri;

	}
	//setter pentru nrScaun
	void setNrScaun(int scaune)
	{
		nrScaun = scaune;
	}

	//operator =
	Locatie operator=(const Locatie& l)
	{
		if (l.zone != NULL)
		{
			this->zone = new char[strlen(l.zone) + 1];
			strcpy(this->zone, l.zone);

		}
		else
			this->zone = NULL;

		if (l.nrRanduri > 0)
		{
			this->nrRanduri = l.nrRanduri;
		}
		else
			this->nrRanduri = 0;


		if (l.nrScaun > 0)
		{
			this->nrScaun = l.nrScaun;
		}
		else

			this->nrScaun = 10;


		this->nrTotalLocuri = l.nrTotalLocuri;
		return *this;
	}

	//operator >
	bool operator>(Locatie r)
	{
		return this->nrRanduri > r.nrRanduri;

	}

	//operator cast
	operator int()
	{
		return this->nrRanduri;
	}

	//operator --
	Locatie& operator--(int x)
	{
		Locatie copie = *this;
		this->nrTotalLocuri--;
		return copie;
	}
	void writeToFile(fstream& file)
	{
		//char*
		int lg = strlen(this->zone) + 1;
		file.write((char*)&lg, sizeof(int));
		file.write(this->zone, lg);
		//int nrRanduri
		file.write((char*)&this->nrRanduri, sizeof(int));
		//int nrScaun
		file.write((char*)&this->nrScaun, sizeof(int));
		//int nrTotalLocuri
		file.write((char*)&this->nrTotalLocuri, sizeof(int));

	}

	void readFromFile(fstream& file)
	{
		//citire char* numeClient
		delete[] this->zone;
		int lg = 0;
		file.read((char*)&lg, sizeof(int));
		this->zone = new char[lg];
		file.read(this->zone, lg);
		//citire int nrRanduri
		file.read((char*)&this->nrRanduri, sizeof(int));
		//citire int nrScaun
		file.read((char*)&this->nrScaun, sizeof(int));
		//citire din nrTotalLocuri
		file.read((char*)&this->nrTotalLocuri, sizeof(int));
	}


	friend ostream& operator<<(ostream& out, Locatie l);
	friend istream& operator>>(istream& in, Locatie& l);
	friend ofstream& operator<<(ofstream& out, const Locatie& l);
	friend ifstream& operator>>(ifstream& in, Locatie& l);
};

//operator<<
ostream& operator<<(ostream& out, Locatie l)
{
	out << "Zona locatiei:" << l.zone << endl;
	out << "Nr intrari:" << l.intrari << endl;
	out << "Nr randuri:" << l.nrRanduri << endl;
	out << "Nr scaune:" << l.nrScaun << endl;

	return out;
}

//operator>>
istream& operator>>(istream& in, Locatie& l)
{
	cout << "Zona locatiei:" << endl;
	in >> l.zone;
	cout << "Nr randuri:" << endl;
	in >> l.nrRanduri;
	cout << "Nr scaune:" << endl;
	in >> l.nrScaun;

	return in;
}

ofstream& operator<<(ofstream& g3, const Locatie& l)
{
	g3 << l.zone << ",";
	g3 << l.nrRanduri << ",";
	g3 << l.nrScaun << ",";


	return g3;
}
ifstream& operator>>(ifstream& f3, Locatie& l)
{
	delete[]l.zone;
	char zone[10];
	f3 >> zone;
	l.zone = new char[strlen(zone) + 1];
	strcpy(l.zone, zone);
	f3 >> l.nrRanduri;
	f3 >> l.nrScaun;


	return f3;
}

//Is a
class Stadion :public Locatie
{
private:
	char* numeStadion;

public:
	Stadion() :Locatie()
	{
		this->numeStadion = new char[strlen("Necunoscut") + 1];
		strcpy(this->numeStadion, "Necunoscut");

	}
	Stadion(const char* zone, int nrRanduri, int nrScaun, const char* numeStadion) :Locatie(zone, nrRanduri, nrScaun)
	{
		this->numeStadion = new char[strlen(numeStadion) + 1];
		strcpy(this->numeStadion, numeStadion);

	}
	Stadion(const Stadion& s) :Locatie(s)
	{
		this->numeStadion = new char[strlen(s.numeStadion) + 1];
		strcpy(this->numeStadion, s.numeStadion);
	}
	~Stadion()
	{
		delete[]this->numeStadion;
	}
	friend ostream& operator<<(ostream& out, const Stadion& s)
	{
		out << "Numele stadionului este:" << s.numeStadion;
		return out;

	}
};

//A patra clasa

class DateEveniment
{
private:
	char* denumireEveniment;
	int durataEveniment;
	float pretBilet;
	char* zone;
	int nrRanduri;
	int nrScaun;
	Locatie* locatie;
	Bilet* bilet;

public:
	DateEveniment()
	{
		this->denumireEveniment = new char[strlen("Necunoscut") + 1];
		strcpy(this->denumireEveniment, "Necunoscut");
		this->durataEveniment = 0;
		this->pretBilet = 0;
		this->zone = new char[strlen("Necunoscut") + 1];
		strcpy(this->zone, "Necunoscut");
		this->nrRanduri = 0;
		this->nrScaun = 0;
		this->bilet = nullptr;
		this->locatie = nullptr;

	}
	//constructor cu parametri
	DateEveniment(const char* denumireEveniment, int durataEveniment, float pretBilet, const char* zone, int nrRanduri, int nrScaun, Locatie& locatie, Bilet& bilet)
	{
		this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
		strcpy(this->denumireEveniment, denumireEveniment);
		this->durataEveniment = durataEveniment;
		this->pretBilet = pretBilet;
		this->zone = new char[strlen(zone) + 1];
		strcpy(this->zone, zone);
		this->nrRanduri = nrRanduri;
		this->nrScaun = nrScaun;
		this->locatie = new Locatie(locatie);
		this->bilet = new Bilet(bilet);

	}
	//constructor de copiere
	DateEveniment(const DateEveniment& d)
	{
		this->denumireEveniment = new char[strlen(d.denumireEveniment) + 1];
		strcpy(this->denumireEveniment, d.denumireEveniment);
		this->durataEveniment = d.durataEveniment;
		this->pretBilet = d.pretBilet;
		this->zone = new char[strlen(d.zone) + 1];
		strcpy(this->zone, d.zone);
		this->nrRanduri = d.nrRanduri;
		this->nrScaun = d.nrScaun;
		this->locatie = new Locatie(*d.locatie);
		this->bilet = new Bilet(*d.bilet);
	}
	DateEveniment operator=(const DateEveniment& d)
	{
		this->denumireEveniment = new char[strlen(d.denumireEveniment) + 1];
		strcpy(this->denumireEveniment, d.denumireEveniment);
		this->durataEveniment = d.durataEveniment;
		this->pretBilet = d.pretBilet;
		this->zone = new char[strlen(d.zone) + 1];
		strcpy(this->zone, d.zone);
		this->nrRanduri = d.nrRanduri;
		this->nrScaun = d.nrScaun;
		this->locatie = new Locatie(*d.locatie);
		this->bilet = new Bilet(*d.bilet);

		return *this;
	}
	//destructor
	~DateEveniment()
	{
		delete[]this->zone;
		delete[]this->denumireEveniment;
		delete locatie;
		delete bilet;
	}


	void setBilet()
	{
		int rand = 0;
		int loc = 0;
		rand = stoi(bilet->getNrRand()) - 1;
		loc = stoi(bilet->getNrLoc()) - 1;
		if (rand < locatie->getNrRanduri() && loc < locatie->getNrTotalLocuri())
		{
			cout << "Locul este deja rezervat" << endl;
		}
		else
			cout << "Numarul locului sau randului nu exista" << endl;

	}
	//getter denumireEveniment
	char* getDenumireEveniment()
	{
		char* copieDenumire = new char[strlen(this->denumireEveniment) + 1];
		strcpy(copieDenumire, this->denumireEveniment);
		return copieDenumire;
	}
	//getter durataEveniment
	int getDurataEveniment()
	{
		return this->durataEveniment;
	}

	//getter pretBilet
	int getPretBilet()
	{
		return this->pretBilet;
	}
	//getter zone
	char* getZone()
	{
		char* copieZone = new char[strlen(this->zone) + 1];
		strcpy(copieZone, this->zone);
		return copieZone;

	}
	//getter nrRanduri
	int getNrRanduri()
	{
		return this->nrRanduri;
	}
	//getter nrScaun
	int getNrScaun()
	{
		return this->nrScaun;
	}
	//setter denumireEveniment
	void setDenumireEveniment(const char* denumireEveniment)
	{
		if (this->denumireEveniment != NULL)
		{
			delete[]this->denumireEveniment;
		}
		this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
		strcpy(this->denumireEveniment, denumireEveniment);

	}
	//setter durataEveniment
	void setDurataEveniment(int durata)
	{
		durataEveniment = durata;
	}
	//setter zone
	void setZone(const char* zone)
	{
		if (this->zone != NULL)
		{
			delete[]this->zone;
		}
		this->zone = new char[strlen(zone) + 1];
		strcpy(this->zone, zone);
	}
	//setter pretBilet
	void setPretBilet(int pret)
	{
		pretBilet = pret;

	}
	//setter nrRanduri
	void setNrRanduri(int rand)
	{
		nrRanduri = rand;
	}
	//setter nrScaun
	void setNrScaun(int loc)
	{
		nrScaun = loc;
	}

	friend ostream& operator<<(ostream& out, const DateEveniment& d);
	friend istream& operator>>(istream& in, DateEveniment& d);

};
//operator<<
ostream& operator<<(ostream& out, const DateEveniment& d)
{
	out << "Denumirea evenimentului:" << d.denumireEveniment << endl;
	out << "Durata evenimentului:" << d.durataEveniment << endl;
	out << "Pretul biletului este:" << d.pretBilet << endl;
	out << "Zona este:" << d.zone << endl;
	out << "Nr randului este:" << d.nrRanduri << endl;
	out << "Nr locului este:" << d.nrScaun << endl;

	return out;
}
//operator >>
istream& operator>>(istream& in, DateEveniment& d)
{
	cout << "Denumirea evenimentului:" << endl;
	in >> d.denumireEveniment;
	cout << "Durata evenimentului:" << endl;
	in >> d.durataEveniment;
	cout << "Pretul biletului este:" << endl;
	in >> d.pretBilet;
	cout << "Nr randului este:" << endl;
	in >> d.pretBilet;
	cout << "Nr randului este:" << endl;
	in >> d.nrRanduri;
	cout << "Nr locului este:" << endl;
	in >> d.nrScaun;

	return in;
}

//afisarea meniului
void meniu()
{
	cout << endl << "------MENIU------" << endl;
	cout << "1.Adauga locatia" << endl;
	cout << "2.Vizualizare locatie" << endl;
	cout << "3.Cumpara bilet" << endl;
	cout << "4.Vizualizare bilet" << endl;
	cout << "5.Verificare existenta bilet" << endl;
	cout << "6.Detalii eveniment" << endl;
	cout << "7.Exit" << endl;

}




int main()
{
	//date eveniment
	DateEveniment d1;
	cout << d1 << endl;

	cout << "Evenimentul 1" << endl;
	Eveniment e1;
	cout << e1 << endl;
	/*cin >> e1;
	cout << e1 << endl;*/

	cout << endl << "Evenimentul 2" << endl;
	Eveniment e2("Cupa mondiala", "Meci fotbal", 90, 20000);
	cout << e2 << endl;

	//getteri
	cout << endl << "Apelare getteri" << endl;
	cout << "Denumire=" << e2.getDenumireEveniment() << endl;
	cout << "Tip=" << e2.getTipEveniment() << endl;
	cout << "Durata=" << e2.getDurataEveniment() << endl;
	cout << "Numar persoane=" << e2.getNrPersoane() << endl;

	//setteri
	cout << endl << "Apelare setteri" << endl;
	e1.setDenumireEveniment("Teatru");
	e1.setTipEveniment("Drama");
	e1.setDurataEveniment(60);
	e1.setNrPersoane(500);
	cout << e1 << endl;

	//constructor de copiere
	cout << endl << "Constructor de copiere" << endl;
	Eveniment e3 = e2;
	cout << e3 << endl;

	//operator =
	cout << endl << "Operator=" << endl;
	Eveniment e4;
	e4 = e2;
	cout << e4;

	//operator <
	cout << endl << "Operator <" << endl;
	if (e1 < e2)
		cout << "Durata e1 mai mica decat durata e2" << endl;
	else
		cout << "Durata e2 mai mica decat durata e1" << endl;

	//operator+
	cout << endl << "Operator +" << endl;
	e1 = e1 + 20;
	cout << e1 << endl;

	cout << endl << "Fisiere binare" << endl;
	//fisier binar
	fstream fOut1("fisier.txt", ios::out | ios::binary);
	e2.writeToFile(fOut1);
	fOut1.close();

	//fisier binar
	fstream fIn1("fisier.txt", ios::in | ios::binary);
	e1.readFromFile(fIn1);
	fIn1.close();
	cout << e1;
	cout << endl;

	cout << endl << "Fisere normale" << endl;
	////fisier normal
	ofstream g("Eveniment.csv");
	g << e2;
	g.close();

	////fisier normal
	ifstream f("Eveniment.txt");
	Eveniment e20;
	f >> e20;
	cout << e20;
	f.close();

	//relatie de tip has a
	cout << endl << "Relatie de tip has a:" << endl;
	Intrare intrare(3);
	intrare.add_eveniment(&e2);
	cout << intrare << endl;


	//bilet
	Bilet b1;
	cout << b1 << endl;
	Bilet b2("VIP", 1, new float[1] {2}, "20", "30");
	cout << b2 << endl;

	//locatie
	Locatie l1;
	cout << l1 << endl;



	//vector stl
	cout << endl << "Vector STL" << endl;
	vector<Eveniment> vEv;
	vEv.push_back(e1);
	vEv.push_back(e2);

	vector<Eveniment>::iterator itV2;
	for (itV2 = vEv.begin(); itV2 != vEv.end(); itV2++)
		cout << *itV2;

	//lista stl
	cout << endl << "Lista STL" << endl;
	list<Eveniment> lEv;
	lEv.push_back(e1);
	lEv.push_front(e2);

	list<Eveniment>::iterator itLEv;
	for (itLEv = lEv.begin(); itLEv != lEv.end(); itLEv++)
		cout << *itLEv << " ";

	//locatie
	Locatie loc1;
	//bilet
	Bilet bil1;
	//datele evenimentului
	DateEveniment date1;

	//meniu
	int alegere = 0;

start:


	do {

		meniu();
		cout << "Introduceti optiunea: " << endl;
		cin >> alegere;
		system("cls");
		switch (alegere)
		{
		case 1:
			cin.ignore();
			cin >> loc1;
			cout << endl << "Locatie adaugata cu succes!" << endl;
			break;

		case 2:

			cout << loc1 << endl;
			break;



		case 3:

			cin.ignore();
			cin >> bil1;
			cout << "Bilet inregistrat cu succes!" << endl;
			break;

		case 4:
			cout << bil1;
			break;

		case 5:

			if (bil1.operator!() == 1)
				cout << "Biletul exista in baza de date!" << endl;
			else
				cout << "Biletul nu exista in baza de date!" << endl;
			break;

		case 6:
			cin.ignore();
			DateEveniment Eveniment1("Untold", 90, 50, "loja", 20, 8, loc1, bil1);
			cin >> Eveniment1;
			cout << endl << "Evenimentul a fost adaugat" << endl;
			Eveniment1.setBilet();
			cout << "Detalii eveniment: " << endl;
			cout << Eveniment1 << endl;
		}

	} while (alegere != 7);



	return 0;
}