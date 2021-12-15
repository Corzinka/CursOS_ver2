#include <iostream>
#include <random>
#include <time.h>
#include "Zadacha.h"
#include "Process.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int a;
	int tik = 0;
	int T = 0;
	int complete = 0;
	int mincpu = -1;
	int col = 6;
	Zadacha* z = new Zadacha[col];
	for (int i = 0; i < col; i++) {
		z[i].setZadacha(i, rand() % 6 + 1, rand() % 4, rand() % 5 + 4);
		T += z[i].recpuburst();
		cout << "id:" << z[i].repid() << " C:" << z[i].recpuburst() << " t:" << z[i].reptime() << " r:" << z[i].represurce() << endl;
	}
	Process* p = new Process[col];
	cout << endl;
	while (complete != col) {
		for (int i = 0; i < col; i++) {
			if (z[i].reptime() == tik) {
				p[i].setProcess(z[i].repid(), z[i].recpuburst(), z[i].reptime(), z[i].represurce());
				p[i].setMemory();
				cout << "id:" << p[i].repid() << " C:" << p[i].recpuburst() << " t:" << p[i].reptime() << " r:" << p[i].represurce() << endl;
			}
		}
		cout << endl;
		for (int i = 0; i < col; i++) {
			//if (p[i].readdress() == 0) p[i].setMemory();
			if (!p[i].redone() && (p[i].readdress() == 1)) {
				if (mincpu == -1) mincpu = i;
				if (p[mincpu].recpuburst() > p[i].recpuburst()) mincpu = i;
			}
		}
		if (mincpu >= 0) {
			if (!p[mincpu].chektabl()) {
				cout << tik <<": " << "Выполнение p" << mincpu << " c:" << p[mincpu].recpuburst() << " a:";
				cout << p[mincpu].repid() << "(";
				p[mincpu].printtabl();
				cout << ")\n";
				p[mincpu].work();
				if (p[mincpu].recpuburst() <= 0) {
					p[mincpu].setdone();
					mincpu = -1;
				}
			}
			else {
				while (true) {
					for (a = 0; a < col; a++) {
						if (p[a].readdress() == 1)
							if (a != mincpu)
								break;
					}
					cout << "vigruz p" << a << " for p" << mincpu << endl;
					p[a].vigruz();
					cout << endl;
					p[mincpu].setMemory();
					if (!p[mincpu].chektabl()) break;
				}
			}
		}
		tik++;
		complete = 0;
		for (int i = 0; i < col; i++) {
			if (p[i].redone()) complete++;
		}
	}
	cout << complete;
	cout << "Process:" << endl;
	for (int i = 0; i < col; i++) {
		cout << "id:" << p[i].repid() << " C:" << p[i].recpuburst() << endl;
	}
	cout << "Process address:" << endl;
	for (int i = 0; i < col; i++) {
		cout << p[i].repid() << "(";
		p[i].printtabl();
		cout << ")\n";
	}
	cout << "PMemory: " << endl;
	for (int i = 0; i < M; i++) {
		cout << pmemory[i][0] << " ";
	}
	cout << "\nHard: " << endl;
	for (int i = 0; i < M * 10; i++) {
		cout << hard[i][1] << " ";
	}
}
