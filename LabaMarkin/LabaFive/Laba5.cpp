#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
#define NFIO 15
#define NS 6

using namespace std;

struct Date {
	int Day, Month, Year;
};

struct stud {
	char FIO[NFIO], Pol, Obr, Adress, Stip; 
	Date DateR;
	int Ocen[5], KB;
};

int otbor(stud Group[NS], stud Group1[NS]) {
	int n = 0, i;
		for (i=0; i<NS; i++) {
			if ((Group[i].Obr == 's') && (Group[i].Stip == 'y') && (Group[i].Adress == 'p')) {
				Group1[n] = Group[i];
				n++;
			}
		}
	return n;
}

int main() {
	int i, j, n;
	stud Group[NS],Group1[NS];
	char dir[10],dir1[10], fileName[10],fileName1[10], dir2[10], fileName2[20];
	cout << "Vvedite direktoriy" << endl;
	cin >> dir;
	cout << "Vvedite nazvanie fila spiska" << endl;
	cin >> fileName;
	strcat (dir,fileName);
	ofstream fln;
	cout << "Proverka puti" << endl; 
	if (fln == NULL) {
		cout << "Puti net" << endl; 
		getch();
		return 0;
	}
	else 
		cout << "Ok! Dir = " << dir << endl<< endl;
	cout << "Vvedite spisok v vide\nIvanov_I.I.___ mkpy 21 21 1999 5 5 5 5 5 200\n\n"; //��� ������ ���� � ��������(��� ��������)
	for(i=0; i<NS; i++ ) {
		cin >> Group[i].FIO >> Group[i].Pol >> Group[i].Obr >> Group[i].Adress >> Group[i].Stip 
				>> Group[i].DateR.Day >> Group[i].DateR.Month >> Group[i].DateR.Year;
		for (j=0; j<5; j++) 
			cin >> Group[i].Ocen[j] ;
		cin >> Group[i].KB;
	}
	fln.open(dir);
	for(i=0; i<NS; i++ ){
		fln << Group[i].FIO << ' ' << Group[i].Pol << Group[i].Obr << Group[i].Adress << Group[i].Stip << ' ' 
			<< Group[i].DateR.Day << ' ' << Group[i].DateR.Month << ' ' << Group[i].DateR.Year << ' ';
		for (j=0; j<5; j++) 
			fln << Group[i].Ocen[j] << ' ' ;
		fln << Group[i].KB << endl;
	} 
	fln.close();
	cout << endl;
	cout << "Vvedite disk: dlya schitivaniya obshego spiska" << endl;
	cin >> dir1;
	cout << "Vvedite nazvanie fila so spiskom" << endl;
	cin >> fileName1;
	strcat (dir1,fileName1);
	ifstream fln1(dir1);
	cout << "Proverka puti..." << endl << endl;
	if (fln == NULL)
		cout << "Puti net" << endl;
	else 
		cout << "Ok! Dir = " << dir1 << endl << endl;
	for(i=0; i<NS; i++ ) {
		fln1 >> Group[i].FIO >> Group[i].Pol >> Group[i].Obr >> Group[i].Adress >> Group[i].Stip 
			>> Group[i].DateR.Day >> Group[i].DateR.Month >> Group[i].DateR.Year;
		for (j=0; j<5; j++)
			fln1 >> Group[i].Ocen[j] ;
		fln1 >> Group[i].KB;
	}
	fln1.close();
	cout << endl;
	cout << "Vvedite disk: dlya sohraneniya spiska otbora" << endl;
	cin >> dir2;
	cout << "Vvedite nazvanie fila.txt dlya sohraneniya spiska otbora " << endl;
	cin >> fileName2;
	strcat (dir2,fileName2);
	ofstream fln2(dir2);
	cout << "Proverka puti..." << endl << endl;
	if (fln2 == NULL)
		cout << "Puti net" << endl;
	else 
		cout << "Ok! Dir = " << dir2 << endl << endl;
	n = otbor (Group,Group1);
	fln2 << "\t<< Okonchili midSchool i na Stip >>\n\n";
	for(i=0; i<n; i++ ) {
		fln2 << Group1[i].FIO << ' ' << Group1[i].Pol << Group1[i].Obr << Group1[i].Adress << Group1[i].Stip << ' '  
			 << Group1[i].DateR.Day << ' ' << Group1[i].DateR.Month << ' ' << Group1[i].DateR.Year << ' ' ;
		for (j=0; j<5; j++)
			fln2 << Group1[i].Ocen[j] << ' ' ;
		fln2 << Group1[i].KB << endl ;
	}
		fln2 << endl << "Vsego " << n;
		fln2.close();
	return 0;
}
