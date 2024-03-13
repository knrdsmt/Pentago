#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

struct struktura
{
	int** PlanszaGracza = nullptr;
	string imie;
	string zeton;
	bool wygrana = 0;
};

int** tworzeniePlanszy(struktura& gracz)
{
	int** tab = new int* [6];
	for (int i = 0; i < 6; i++)
		tab[i] = new int[6];
	return tab;
}
void usuwanie(struktura& gracz)
{
	for (int i = 0; i < 6; i++)
		delete gracz.PlanszaGracza[i];
	delete gracz.PlanszaGracza;
}
void wypelnianieZerami(struktura& gracz)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			gracz.PlanszaGracza[i][j] = 0;
		}

	}
}

void wczytywanieImienia(struktura& gracz1, struktura& gracz2)
{
	cout << "Imie gracza 1: ";
	cin >> gracz1.imie;
	cout << "Imie gracza 2: ";
	cin >> gracz2.imie;
}
void wyborZetonu(struktura& gracz)
{
	string zetonPodanyPrzezGracza;

	cout << "\nZeton gracza " << gracz.imie << ": ";
	cin >> zetonPodanyPrzezGracza;
	gracz.zeton = zetonPodanyPrzezGracza[0];	//zeton to pierwszy znak stringa
}
bool sprawdzenieCzyZetonySaTakieSame(struktura& gracz1, struktura& gracz2)
{
	if (gracz1.zeton == gracz2.zeton)
	{
		cout << "Zetony sa takie same!/n";
		system("pause");
		return 1;
	}
	return 0;
}

void warunekZwyciestwaPoziom(struktura& gracz)
{
	int suma;

	for (int i = 0; i < 6; i++)
	{
		suma = 0;
		for (int j = 0; j < 5; j++)
		{
			suma += gracz.PlanszaGracza[i][j];
			if (suma == 5)
			{
				gracz.wygrana = 1;
			}
		}
		suma = 0;
		for (int j = 1; j < 6; j++)
		{
			suma += gracz.PlanszaGracza[i][j];
			if (suma == 5)
			{
				gracz.wygrana = 1;
			}
		}
	}
}
void warunekZwyciestwaPion(struktura& gracz)
{
	int suma;

	for (int i = 0; i < 5; i++)
	{
		suma = 0;
		for (int j = 0; j < 5; j++)
		{
			suma += gracz.PlanszaGracza[j][i];
			if (suma == 5)
			{
				gracz.wygrana = 1;
			}
		}
	}
	for (int i = 1; i < 6; i++)
	{
		suma = 0;
		for (int j = 1; j < 6; j++)
		{
			suma += gracz.PlanszaGracza[j][i];
			if (suma == 5)
			{
				gracz.wygrana = 1;
			}
		}
	}
}
void warunekZwyciestwaSkos1(struktura& gracz)
{
	int suma00_44 = 0, suma11_55 = 0, suma01_45 = 0, suma10_54 = 0;		//poprawic

	for (int i = 0; i < 5; i++)
	{
		suma00_44 += gracz.PlanszaGracza[i][i];
		suma11_55 += gracz.PlanszaGracza[i + 1][i + 1];
		suma01_45 += gracz.PlanszaGracza[i][i + 1];
		suma10_54 += gracz.PlanszaGracza[i + 1][i];
		if (suma00_44 == 5 || suma11_55 == 5 || suma01_45 == 5 || suma10_54 == 5)
		{
			gracz.wygrana = 1;
		}
	}
}
void warunekZwyciestwaSkos2(struktura& gracz)
{
	int suma05_41 = 0, suma14_50 = 0, suma04_40 = 0, suma15_51 = 0;
	for (int i = 0, j = 5; i < 5; i++, j--)
	{
		suma05_41 += gracz.PlanszaGracza[i][j];
		suma04_40 += gracz.PlanszaGracza[i][j - 1];
		suma15_51 += gracz.PlanszaGracza[i + 1][j];
		suma14_50 += gracz.PlanszaGracza[i + 1][j - 1];
	}
	if (suma05_41 == 5 || suma14_50 == 5 || suma04_40 == 5 || suma15_51 == 5)
	{
		gracz.wygrana = 1;
	}
}
void warunekZwyciestwa(struktura& gracz)
{
	warunekZwyciestwaPoziom(gracz);
	warunekZwyciestwaPion(gracz);
	warunekZwyciestwaSkos1(gracz);
	warunekZwyciestwaSkos2(gracz);
}

void wyswitleniePlanszy(struktura& gracz1, struktura& gracz2, int& runda)
{
	string ramkaGora, kratkaPion, kratkaPoziom, ramkaDol, odstep, puste;
	ramkaGora = "ÉÍÍÍÍÍËÍÍÍÍÍËÍÍÍÍÍ» ÉÍÍÍÍÍËÍÍÍÍÍËÍÍÍÍÍ»";
	kratkaPoziom = "ĚÍÍÍÍÍÎÍÍÍÍÍÎÍÍÍÍÍą ĚÍÍÍÍÍÎÍÍÍÍÍÎÍÍÍÍÍą";
	kratkaPion = "ş";
	ramkaDol = "ČÍÍÍÍÍĘÍÍÍÍÍĘÍÍÍÍÍĽ ČÍÍÍÍÍĘÍÍÍÍÍĘÍÍÍÍÍĽ";
	odstep = "  ";
	puste = "     ";
	system("CLS");
	cout << ramkaGora << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << kratkaPion;
		for (int j = 0; j < 6; j++)
		{
			if (j == 3)
				cout << " " << kratkaPion;
			if (gracz1.PlanszaGracza[i][j] == 1)
			{
				cout << setw(3) << gracz1.zeton;
				cout << odstep;
				cout << kratkaPion;
				continue;
			}

			if (gracz2.PlanszaGracza[i][j] == 1)
			{
				cout << setw(3) << gracz2.zeton;
				cout << odstep;
				cout << kratkaPion;
				continue;
			}
			if (gracz1.PlanszaGracza[i][j] == 0 && gracz2.PlanszaGracza[i][j] == 0)
			{
				cout << puste;
				cout << kratkaPion;
				continue;
			}

		}
		cout << endl;
		if (i != 5 && i != 2)
			cout << kratkaPoziom << endl;
		else
			cout << ramkaDol << endl;
		if (i == 2)
			cout << ramkaGora << endl;
	}

	cout << endl;
	cout << "Runda: " << (runda + 1) / 2 << "        ";
	cout << "licznik: " << runda + 1 << "        ";
	if (gracz1.wygrana == 0 && gracz2.wygrana == 0)
	{
		if (runda % 2 == 1)
		{
			cout << "Ruch gracza " << gracz1.imie << "  zeton: " << gracz1.zeton << endl << endl;
		}
		else
		{
			cout << "Ruch gracza " << gracz2.imie << "  zeton: " << gracz2.zeton << endl << endl;
		}
		if (runda == 38)
		{
			cout << "Remis" << endl;
			system("pause");
		}

	}
	else
	{
		cout << "Zwyciestwo gracza ";
		if (gracz1.wygrana == 1)
		{
			cout << gracz1.imie << endl;
			system("pause");

		}
		if (gracz2.wygrana == 1)
		{
			cout << gracz2.imie << endl;
			system("pause");
		}
		cout << endl;
	}

}

void pomoc(struktura& gracz1, struktura& gracz2, int& licznik)
{
	system("cls");
	cout << "						--- POMOC ---\n\n";
	cout << "q,w,a,s - wybor czesci planszy odpowiednio: lewej gornej, prawej gornej, lewej dolnej, prawej dolnej\n"
		<< "1..9 - wybor pola na czesci planszy jak na klawiaturze numerycznej tj. 1 to dolne lewe pole\n"
		<< "z, x - obrot odpowiednio : zgodnie z ruchem wskazowek zegara, odwrotnie do ruchu wskazowek\n"
		<< "p - pauza\n"
		<< "u - undo\n"
		<< "o - wczytanie predefiniowanej planszy\n"
		<< "m - wejscie do opcji\n"
		<< "h - wejscie do opisu programu\n"
		<< "Ruch to najpierw wybor czesci planszy i pola(np.q5), a nastepnie wybor czesci planszy i obrotu (np.az).\n"
		<< "Wyjscie z opcji p, m, h dowolnie wybrana komenda.\n";
	system("pause");
	wyswitleniePlanszy(gracz1, gracz2, licznik);
}
void pauza(struktura& gracz1, struktura& gracz2, int& licznik)
{
	system("cls");
	cout << "						--- PAUZA ---\n";
	system("pause");
	wyswitleniePlanszy(gracz1, gracz2, licznik);
}
void szablonO(struktura& gracz1, struktura& gracz2, int& licznik)
{
	wypelnianieZerami(gracz1);
	wypelnianieZerami(gracz2);
	gracz2.PlanszaGracza[0][4] = 1;
	gracz2.PlanszaGracza[1][0] = 1;
	gracz2.PlanszaGracza[1][1] = 1;
	gracz2.PlanszaGracza[1][3] = 1;
	gracz2.PlanszaGracza[2][1] = 1;
	gracz2.PlanszaGracza[3][0] = 1;
	gracz2.PlanszaGracza[3][1] = 1;
	gracz2.PlanszaGracza[4][2] = 1;
	gracz2.PlanszaGracza[4][2] = 1;
	gracz1.PlanszaGracza[0][1] = 1;
	gracz1.PlanszaGracza[0][1] = 1;
	gracz1.PlanszaGracza[1][2] = 1;
	gracz1.PlanszaGracza[1][4] = 1;
	gracz1.PlanszaGracza[4][0] = 1;
	gracz1.PlanszaGracza[4][4] = 1;
	gracz1.PlanszaGracza[5][1] = 1;
	gracz1.PlanszaGracza[5][4] = 1;
	gracz1.PlanszaGracza[5][5] = 1;
	licznik = 16;
	wyswitleniePlanszy(gracz1, gracz2, licznik);
}

int wybor_pola(struktura& gracz1, struktura& gracz2, int& licznik)
{
	char czesc, pole;
	int x, y;
	cout << "Wybierz 1 z 4 czesci planszy: ";
	cin >> czesc;
	switch (czesc)
	{
	case 'q':
		x = 0;
		y = 0;
		break;
	case 'w':
		x = 0;
		y = 3;
		break;
	case 'a':
		x = 3;
		y = 0;
		break;
	case 's':
		x = 3;
		y = 3;
		break;
	case 'h':
		pomoc(gracz1, gracz2, licznik);
		return 0;
		break;
	case 'p':
		pauza(gracz1, gracz2, licznik);
		return 0;
		break;
	case 'o':
		szablonO(gracz1, gracz2, licznik);
		return 0;
		break;
	case 'm':
		do
		{
			system("cls");
			cout << "Zmiana zetonow\n";
			wyborZetonu(gracz1);
			wyborZetonu(gracz2);
		} while (sprawdzenieCzyZetonySaTakieSame(gracz1, gracz2));
		return 0;
		break;
	default:
		cout << "Niedozwolony wybor. | h - pomoc\n";
		system("pause");
		return 0;
		break;
	}
	cout << "Pole: ";
	cin >> pole;
	switch (pole)
	{
	case '1':
		if (gracz1.PlanszaGracza[x + 2][y] == 0 && gracz2.PlanszaGracza[x + 2][y] == 0)
			gracz1.PlanszaGracza[x + 2][y] = 1;
		else
			return 0;
		break;
	case '2':
		if (gracz1.PlanszaGracza[x + 2][y + 1] == 0 && gracz2.PlanszaGracza[x + 2][y + 1] == 0)
			gracz1.PlanszaGracza[x + 2][y + 1] = 1;
		else
			return 0;
		break;
	case '3':
		if (gracz1.PlanszaGracza[x + 2][y + 2] == 0 && gracz2.PlanszaGracza[x + 2][y + 2] == 0)
			gracz1.PlanszaGracza[x + 2][y + 2] = 1;
		else
			return 0;
		break;
	case '4':
		if (gracz1.PlanszaGracza[x + 1][y] == 0 && gracz2.PlanszaGracza[x + 1][y] == 0)
			gracz1.PlanszaGracza[x + 1][y] = 1;
		else
			return 0;
		break;
	case '5':
		if (gracz1.PlanszaGracza[x + 1][y + 1] == 0 && gracz2.PlanszaGracza[x + 1][y + 1] == 0)
			gracz1.PlanszaGracza[x + 1][y + 1] = 1;
		else
			return 0;
		break;
	case '6':
		if (gracz1.PlanszaGracza[x + 1][y + 2] == 0 && gracz2.PlanszaGracza[x + 1][y + 2] == 0)
			gracz1.PlanszaGracza[x + 1][y + 2] = 1;
		else
			return 0;
		break;
	case '7':
		if (gracz1.PlanszaGracza[x][y] == 0 && gracz2.PlanszaGracza[x][y] == 0)
			gracz1.PlanszaGracza[x][y] = 1;
		else
			return 0;
		break;
	case '8':
		if (gracz1.PlanszaGracza[x][y + 1] == 0 && gracz2.PlanszaGracza[x][y + 1] == 0)
			gracz1.PlanszaGracza[x][y + 1] = 1;
		else
			return 0;
		break;
	case '9':
		if (gracz1.PlanszaGracza[x][y + 2] == 0 && gracz2.PlanszaGracza[x][y + 2] == 0)
			gracz1.PlanszaGracza[x][y + 2] = 1;
		else
			return 0;
		break;
	case 'h':
		pomoc(gracz1, gracz2, licznik);
		return 0;
		break;
	case 'p':
		pauza(gracz1, gracz2, licznik);
		return 0;
		break;
	case 'o':
		szablonO(gracz1, gracz2, licznik);
		return 0;
		break;
	case 'm':
		do
		{
			system("cls");
			cout << "Zmiana zetonow\n";
			wyborZetonu(gracz1);
			wyborZetonu(gracz2);
		} while (sprawdzenieCzyZetonySaTakieSame(gracz1, gracz2));
		return 0;
		break;
	default:
		cout << "Niedozwolony wybor. | h - pomoc\n";
		system("pause");
		return 0;
		break;
	}
	return 1;
}
void obrot(struktura& gracz, int x, int y, int ilosc)
{

	for (int i = 0; i < ilosc; i++)
	{

		int buf;
		buf = gracz.PlanszaGracza[x + 2][y];
		gracz.PlanszaGracza[x + 2][y] = gracz.PlanszaGracza[x + 2][y + 2];
		gracz.PlanszaGracza[x + 2][y + 2] = gracz.PlanszaGracza[x][y + 2];
		gracz.PlanszaGracza[x][y + 2] = gracz.PlanszaGracza[x][y];
		gracz.PlanszaGracza[x][y] = buf;

		buf = gracz.PlanszaGracza[x + 2][y + 1];
		gracz.PlanszaGracza[x + 2][y + 1] = gracz.PlanszaGracza[x + 1][y + 2];
		gracz.PlanszaGracza[x + 1][y + 2] = gracz.PlanszaGracza[x][y + 1];
		gracz.PlanszaGracza[x][y + 1] = gracz.PlanszaGracza[x + 1][y];
		gracz.PlanszaGracza[x + 1][y] = buf;
	}
}
bool wyborCzesciDoObrotu(struktura& gracz1, struktura& gracz2, int& licznik)	//zwraca 0 - nie dozwolony wybor
{
	char czesc, strona;
	int x, y, ilosc_obrotow;
	cout << "Ktora czesc planszy obrocic: ";
	cin >> czesc;
	switch (czesc)
	{
	case 'q':
		x = 0;
		y = 0;
		break;
	case 'w':
		x = 0;
		y = 3;
		break;
	case 'a':
		x = 3;
		y = 0;
		break;
	case 's':
		x = 3;
		y = 3;
		break;
	case 'h':
		pomoc(gracz1, gracz2, licznik);
		return 0;
		break;
	case 'p':
		pauza(gracz1, gracz2, licznik);
		return 0;
		break;
	case 'o':
		szablonO(gracz1, gracz2, licznik);
		return 0;
		break;
	case 'm':
		do
		{
			system("cls");
			cout << "Zmiana zetonow\n";
			wyborZetonu(gracz1);
			wyborZetonu(gracz2);
		} while (sprawdzenieCzyZetonySaTakieSame(gracz1, gracz2));
		return 0;
		break;
	default:
		cout << "Niedozwolony wybor. | h - pomoc\n";
		system("pause");
		return 0;
		break;
	}

	cout << "W ktora strona?";
	cin >> strona;
	switch (strona)
	{
	case 'z':
		ilosc_obrotow = 1;
		break;
	case'x':
		ilosc_obrotow = 3;
		break;
	case 'h':
		pomoc(gracz1, gracz2, licznik);
		return 0;
		break;
	case 'p':
		pauza(gracz1, gracz2, licznik);
		return 0;
		break;
	case 'o':
		szablonO(gracz1, gracz2, licznik);
		return 0;
		break;
	case 'm':
		do
		{
			system("cls");
			cout << "Zmiana zetonow\n";
			wyborZetonu(gracz1);
			wyborZetonu(gracz2);
		} while (sprawdzenieCzyZetonySaTakieSame(gracz1, gracz2));
		return 0;
		break;
	default:
		cout << "Niedozwolony wybor. | h - pomoc\n";
		system("pause");
		return 0;
		break;
	}
	obrot(gracz1, x, y, ilosc_obrotow);
	obrot(gracz2, x, y, ilosc_obrotow);
	return 1;
}

void pentago(struktura& gracz1, struktura& gracz2, int& licznik, bool obroty)
{
	//brak wyboru zetonow w Kolko i krzyzyk
	if (obroty)
	{
		do
		{
			wyborZetonu(gracz1);
			wyborZetonu(gracz2);
		} while (sprawdzenieCzyZetonySaTakieSame(gracz1, gracz2));


	}
	else
	{
		gracz1.zeton = 'X';
		gracz2.zeton = 'O';
	}

	wyswitleniePlanszy(gracz1, gracz2, licznik);
	while (licznik <= 37)
	{
		//ruch gracza 1
		if (licznik % 2)
		{
			if (wybor_pola(gracz1, gracz2, licznik) == 0)
			{
				wyswitleniePlanszy(gracz1, gracz2, licznik);
				continue;
			}
			else
			{
				wyswitleniePlanszy(gracz1, gracz2, licznik);
				warunekZwyciestwa(gracz1);
				if (gracz1.wygrana == 1 || gracz2.wygrana == 1)
				{
					wyswitleniePlanszy(gracz1, gracz2, licznik);
					break;
				}
				licznik++;
			}
		}
		if (licznik == 37 && gracz1.wygrana == 0 && gracz2.wygrana == 0)
		{
			cout << "Remis" << endl;
			system("pause");
			break;
		}
		//ruch gracza 2
		else
		{
			if (wybor_pola(gracz2, gracz1, licznik) == 0)
			{
				wyswitleniePlanszy(gracz1, gracz2, licznik);
				continue;
			}
			else
			{
				wyswitleniePlanszy(gracz1, gracz2, licznik);
				warunekZwyciestwa(gracz2);
				if (gracz1.wygrana == 1 || gracz2.wygrana == 1)
				{
					wyswitleniePlanszy(gracz1, gracz2, licznik);
					break;
				}
				licznik++;
			}
		}
		if (obroty)
		{
			//obracanie planszy
			while (wyborCzesciDoObrotu(gracz1, gracz2, licznik) == 0)
			{
				wyswitleniePlanszy(gracz1, gracz2, licznik);
				continue;
			}
			warunekZwyciestwa(gracz1);
			warunekZwyciestwa(gracz2);
			if (gracz1.wygrana == 1 || gracz2.wygrana == 1)
			{
				wyswitleniePlanszy(gracz1, gracz2, licznik);
				break;
			}
		}
		wyswitleniePlanszy(gracz1, gracz2, licznik);
	}
	wyswitleniePlanszy(gracz1, gracz2, licznik);
	if (licznik == 37 && gracz1.wygrana == 0 && gracz2.wygrana == 0)
	{
			cout << "Remis" << endl;
			system("pause");
	}
}

bool start(struktura& gracz1, struktura& gracz2, int& licznik)
{
	char wybor;
	bool obroty;
	system("cls");
	while (1)
	{
		gracz1.wygrana = 0;
		gracz2.wygrana = 0;
		licznik = 1;
		cout << "\t--MENU--\n\n";
		cout << "\n1 - Kolko i krzyzyk\n";
		cout << "2 - Pentago\n";
		cout << "0 - Wyjscie\n\n";
		cout << "Wybor gry:";
		cin >> wybor;
		switch (wybor)
		{
		case '1':
			obroty = 0;	//gra bez obrotow
			pentago(gracz1, gracz2, licznik, obroty);
			return 1;
			break;
		case '2':
			obroty = 1; //gra z obrotami
			pentago(gracz1, gracz2, licznik, obroty);
			return 1;
			break;
		case '0':
			return 0;
			break;
		default:
			break;
		}
	}
}

int main()
{
	int licznik;
	struktura gracz1, gracz2;
	wczytywanieImienia(gracz1, gracz2);
	gracz1.PlanszaGracza = tworzeniePlanszy(gracz1);
	gracz2.PlanszaGracza = tworzeniePlanszy(gracz2);


	while (1)
	{
		wypelnianieZerami(gracz1);
		wypelnianieZerami(gracz2);

		if (start(gracz1, gracz2, licznik) == 0)
		{
			break;
		}
	}

	usuwanie(gracz1);
	usuwanie(gracz2);
	return 0;
}
