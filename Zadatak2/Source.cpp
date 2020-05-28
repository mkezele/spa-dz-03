#include<iostream>
#include<vector>
#include<chrono>
#include<queue>
#include<Windows.h>
#include"koordinata.h"

using namespace std;
using namespace::chrono;

char get_rnd() {

	if ((rand() % (100 - 0 + 1) + 0) <= 10) return '*';
	else return '-';
}

void ucitaj_poziciju(unsigned& redak, unsigned& stupac, char znak) {

	cout << "redak " << znak << ": ";
	cin >> redak;
	cout << "stupac " << znak << ": ";
	cin >> stupac;

	redak--;
	stupac--;

}

bool provjera(vector<koordinata>& v, int redak, int stupac, int counter) {

	for (int i = 0; i < v.size(); i++) {

		if (v[i].x == redak && v[i].y == stupac && v[i].posjeceno <= counter) return 1;

	}

	return 0;
}

int main() {

	char polje[20][40];

	srand(time(nullptr));
	for (unsigned i = 0; i < 20; i++)
		for (unsigned j = 0; j < 40; j++)
			polje[i][j] = get_rnd();

	unsigned pocetak_redak;
	unsigned pocetak_stupac;
	ucitaj_poziciju(pocetak_redak, pocetak_stupac, 'A');
	polje[pocetak_redak][pocetak_stupac] = 'A';

	unsigned cilj_redak;
	unsigned cilj_stupac;
	ucitaj_poziciju(cilj_redak, cilj_stupac, 'B');
	polje[cilj_redak][cilj_stupac] = 'B';

	polje[pocetak_redak][pocetak_stupac] = 'A';
	polje[cilj_redak][cilj_stupac] = 'B';

	vector<koordinata> v;

	koordinata odrediste;
	odrediste.x = cilj_redak;
	odrediste.y = cilj_stupac;
	odrediste.posjeceno = 0;
	v.push_back(odrediste);

	for (int i = 0; i < v.size(); i++) {

		int counter = v[i].posjeceno + 1;

		int x = v[i].x;
		int y = v[i].y;
		int posjeceno = v[i].posjeceno;

		koordinata pomocna;

		//gore
		if (x - 1 >= 0 && polje[x - 1][y] != '*') {

			if (!provjera(v, x - 1, y, counter)) {
				pomocna.x = x - 1;
				pomocna.y = y;
				pomocna.posjeceno = counter;
				v.push_back(pomocna);
			}

			if (x - 1 == pocetak_redak && y == pocetak_stupac) {
				break;
			}
		}
		//dolje
		if (x + 1 <= 19 && polje[x + 1][y] != '*') {

			if (!provjera(v, x + 1, y, counter)) {
				pomocna.x = x + 1;
				pomocna.y = y;
				pomocna.posjeceno = counter;
				v.push_back(pomocna);
			}

			if (x + 1 == pocetak_redak && y == pocetak_stupac) {
				break;
			}
		}
		//lijevo
		if (y - 1 >= 0 && polje[x][y - 1] != '*') {

			if (!provjera(v, x, y - 1, counter)) {
				pomocna.x = x;
				pomocna.y = y - 1;
				pomocna.posjeceno = counter;
				v.push_back(pomocna);
			}

			if (x == pocetak_redak && y - 1 == pocetak_stupac) {
				break;
			}
		}
		//desno
		if (y + 1 <= 39 && polje[x][y + 1] != '*') {

			if (!provjera(v, x, y + 1, counter)) {
				pomocna.x = x;
				pomocna.y = y + 1;
				pomocna.posjeceno = counter;
				v.push_back(pomocna);
			}

			if (x == pocetak_redak && y + 1 == pocetak_stupac) {
				break;
			}
		}

	}

	int broj_koraka = v.back().posjeceno;

	queue<int> s;

	for (int i = broj_koraka; i >= 0; i--) {

		broj_koraka -= 1;

		for (int j = v.size() - 1; j >= 0; j--) {

			if (v[j].posjeceno == broj_koraka) {

				int x = v[j].x;
				int y = v[j].y;

				if (x == pocetak_redak - 1 && y == pocetak_stupac) {
					pocetak_redak = x;
					pocetak_stupac = y;
					s.push(x);
					s.push(y);
					break;
				}
				else if (x == pocetak_redak + 1 && y == pocetak_stupac) {
					pocetak_redak = x;
					pocetak_stupac = y;
					s.push(x);
					s.push(y);
					break;
				}
				else if (x == pocetak_redak && y == pocetak_stupac - 1) {
					pocetak_redak = x;
					pocetak_stupac = y;
					s.push(x);
					s.push(y);
					break;
				}
				else if (x == pocetak_redak && y == pocetak_stupac + 1) {
					pocetak_redak = x;
					pocetak_stupac = y;
					s.push(x);
					s.push(y);
					break;
				}

			}

		}

	}

	while (!s.empty()) {

		system("cls");

		int x = s.front();
		s.pop();
		int y = s.front();
		s.pop();

		for (unsigned i = 0; i < 20; i++) {
			for (unsigned j = 0; j < 40; j++) {

				if (i == x && j == y) cout << "x" << "";
				else cout << polje[i][j] << "";
			}
			cout << endl;
		}

		Sleep(100);
	}

	return 0;
}