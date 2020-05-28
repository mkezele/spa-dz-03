#include<iostream>
#include<chrono>
#include<Windows.h>
using namespace std;
using namespace::chrono;

void ucitaj_poziciju(unsigned& redak, unsigned& stupac, char znak) {

	cout << "redak " << znak << ": ";
	cin >> redak;
	cout << "stupac " << znak << ": ";
	cin >> stupac;

	redak--;
	stupac--;

}

int main() {

	char polje[20][40];

	for (unsigned i = 0; i < 20; i++)
		for (unsigned j = 0; j < 40; j++)
			polje[i][j] = '-';

	unsigned pocetak_redak;
	unsigned pocetak_stupac;
	ucitaj_poziciju(pocetak_redak, pocetak_stupac, 'A');
	polje[pocetak_redak][pocetak_stupac] = 'A';

	unsigned cilj_redak;
	unsigned cilj_stupac;
	ucitaj_poziciju(cilj_redak, cilj_stupac, 'B');
	polje[cilj_redak][cilj_stupac] = 'B';

	unsigned trenutni_redak = pocetak_redak;
	unsigned trenutni_stupac = pocetak_stupac;

	while (trenutni_redak != cilj_redak || trenutni_stupac != cilj_stupac) {

		if (trenutni_stupac < cilj_stupac)
			trenutni_stupac++;

		else if (trenutni_stupac > cilj_stupac)
			trenutni_stupac--;

		else if (trenutni_redak < cilj_redak)
			trenutni_redak++;

		else if (trenutni_redak > cilj_redak)
			trenutni_redak--;


		Sleep(100);

		system("cls");

		for (unsigned i = 0; i < 20; i++) {
			for (unsigned j = 0; j < 40; j++) {
				if (i == trenutni_redak && j == trenutni_stupac) cout << "x" << "";
				else cout << polje[i][j] << "";
			}
			cout << endl;
		}

	}

	return 0;
}