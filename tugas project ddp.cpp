#include <iostream>
using namespace std;

void tampilkanPapan(char papan[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << papan[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

void inputPemain(char papan[3][3], char simbol) {
    int baris, kolom;
    do {
        cout << "Masukkan baris (0-2) dan kolom (0-2) untuk '" << simbol << "' (pisahkan dengan spasi): ";
        cin >> baris >> kolom;
    } while (baris < 0 || baris >= 3 || kolom < 0 || kolom >= 3 || papan[baris][kolom] != ' ');

    papan[baris][kolom] = simbol;
}

bool cekPemenang(char papan[3][3], char simbol) {
    for (int i = 0; i < 3; i++) {
        
        if ((papan[i][0] == simbol && papan[i][1] == simbol && papan[i][2] == simbol) ||
            (papan[0][i] == simbol && papan[1][i] == simbol && papan[2][i] == simbol))
            return true;
    }

    if ((papan[0][0] == simbol && papan[1][1] == simbol && papan[2][2] == simbol) ||
        (papan[0][2] == simbol && papan[1][1] == simbol && papan[2][0] == simbol))
        return true;

    return false;
}

bool cekPenuh(char papan[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (papan[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
	
	cout <<"|---------------------------------------|"<< endl;
	cout <<"|      DASAR DASAR PEMROGRAMAN          |"<< endl;
	cout <<"|---------------------------------------|"<< endl;
	cout <<"|NAMA  : Abil Adriansyah                |"<< endl;
	cout <<"|NIM   : 2300018022                     |" << endl;
	cout <<"|KELAS : A                              |" << endl;
	cout <<"|PRODI : Informatika                    |" << endl;
	cout <<"|---------------------------------------|"<< endl;
	
    char papan[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char giliran = 'X';

    cout << "Selamat datang di permainan Tic Tac Toe!" << endl;

    do {
        tampilkanPapan(papan);
        inputPemain(papan, giliran);

        if (cekPemenang(papan, giliran)) {
            tampilkanPapan(papan);
            cout << "Pemain '" << giliran << "' menang! Selamat!!" << endl;
            break;
        }

        giliran = (giliran == 'X') ? 'O' : 'X';

        if (cekPenuh(papan)) {
            tampilkanPapan(papan);
            cout << "Permainan seri!" << endl;
            break;
        }

    } while (true);

    return 0;
}

