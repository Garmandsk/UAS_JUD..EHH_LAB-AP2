#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Penggunaan Class/Struct
struct game{
    string nama;
    string petunjuk;
};

// Penggunaan Pointer
int data_koin = 50, g = 0;
int *ptr_koin = &data_koin; 
int &koin = *ptr_koin;

// Penggunaan Vector
vector<int>riwayat_koin = {0};
vector<string> riwayat_game = {""};
int ukuran1 = riwayat_game.size();
int ukuran2 = riwayat_koin.size();

// PENGGUNAAN FUNCTION UNTUK KESELURUHAN PROGRAM
/*FUNGSI TAMBAHAN*/
void menu();
void dompet();
void garis();
/*■■■■■■■■■■■■*/

/*FUNGSI GAME SLOT*/
void gacha(int digit, int row);
void tampil_gacha();
void display_numbers(int angka_acak[3]);
void spin_animation(int angka_acak[3], int duration_ms);
void slot();
/*●●●●●●●●●●●●●●*/

/*FUNGSI GAME TEBAK GELAS*/
void gelas();
void tampil_gelas(int acak);
void acak_gelas();
/*◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇*/

/*FUNGSI GAME BLACKJACK*/
void gachak(int digit, int row);
void kartu(int kartu[], int size);
void blackjack();
/*☆☆☆☆☆☆☆☆☆☆☆☆*/

int main() {
    string pilihangame;
    
    awal:
    system ("cls");
    menu();
    printf("\n");
    cout<<"Pilihan Anda: "; getline(cin, pilihangame); printf("\n");
    
    if(pilihangame == "1"){
        slot();
    system("cls");
    cout<<"Tekan Enter Untuk Kembali Ke Menu Utama"<<endl;
    getchar(); getchar();
    goto awal;
    }
    else if(pilihangame == "2"){
        acak_gelas(); 
    system("cls");      
    cout<<"Tekan Enter Untuk Kembali Ke Menu Utama"<<endl;
    getchar(); getchar();
    goto awal;
    }else if(pilihangame == "3"){
        blackjack();   
    system("cls");    
    cout<<"Tekan Enter Untuk Kembali Ke Menu Utama"<<endl;
    getchar(); getchar();
    goto awal;
    }else if(pilihangame == "4"){
        dompet();       
    cout<<"\nTekan Enter Untuk Kembali Ke Menu Utama"<<endl;
    getchar(); 
    goto awal;
    }else{
        cout<<"Error: Masukkan Tidak Valid"<<endl;
        cout<<"Tekan Enter Untuk Input Ulang"<<endl;
        getchar(); 
        system("cls");
        goto awal;
    }
    return 0;
}

void dompet(){
    system("cls");
    cout <<"Koin mu: " <<"\033[33m"<< koin <<"\033[0m"<< endl;
    cout <<"\nRiwayat Koin Yang didapat:" << endl;
    for(int i = 1; i < ukuran2; i++){
        cout<<i<<". +"<<riwayat_koin[i]<<"["<<riwayat_game[i]<<"]"<<endl;
   }
}

void menu(){
    cout <<"\033[33m";
    cout << "I========================================================================================I"<< endl;
    cout << "\033[33m"<<"|  "<<"\033[36m"<<"8888  88  88 88888         88888 88  88 88  88"<<"\033[1m\033[30m"<<"\033[37m"<<"    88888    888   88   88 88888 888888 "<<"\033[33m"<<"|"<< endl;
    cout << "\033[33m"<<"|    "<<"\033[36m"<<"88  88  88 88  88        88ww  888888 888888"<<"\033[1m\033[30m"<<"\033[37m"<<"    88 www  88 88  888m888 88www 8wwwww "<<"\033[33m"<<"|"<< endl;
    cout << "\033[33m"<<"| "<<"\033[36m"<<"88 88  88  88 88  88        88    88  88 88  88"<<"\033[1m\033[30m"<<"\033[37m"<<"    88  88 8888888 88 8 88 88        w8 "<<"\033[33m"<<"|"<< endl;
    cout << "\033[33m"<<"|  "<<"\033[36m"<<"888    8888  88888  [] []  88888 88  88 88  88"<<"\033[1m\033[30m"<<"\033[37m"<<"    888888 88   88 88   88 88888 888888 "<<"\033[33m"<<"|"<< endl;
    cout << "\033[33m";
    cout << "I==============================II===========================II===========================I"<<"\033[0m"<< endl;
    cout << "\033[33m"<<"                               ||         "<<"\033[0m"<<"GAMES MENU"<<"\033[33m"<<"        ||                            "<< endl;
    cout << "\033[33m"<<"                               ||---------------------------||"<< endl;
    cout << "\033[33m"<<"                               ||       "<<"\033[0m"<<"1. "<<"\033[31m"<<"S"<<"\033[0m"<<"\033[33m"<<"L"<<"\033[0m"<<"\033[32m"<<"O"<<"\033[0m"<<"\033[34m"<<"T"<<"\033[0m"<<" GAMES"<<"\033[33m"<<"       ||                          "<< endl;                            
    cout << "\033[33m"<<"                               ||       "<<"\033[0m"<<"2. "<<"\033[34m"<<"TEBAK"<<"\033[0m"<<" GELAS"<<"\033[33m"<<"      ||                            "<< endl;
    cout << "\033[33m"<<"                               ||       "<<"\033[0m"<<"3. "<<"\033[1m\033[30m"<<"BLACK"<<"\033[0m"<<"JACK!"<<"\033[33m"<<"       ||                            "<< endl;
    cout << "\033[33m"<<"                               ||---------------------------||                           "<< endl;
    cout << "\033[33m"<<"                               ||           "<<"\033[0m"<<"OTHERS"<<"\033[33m"<<"          ||                            "<< endl;
    cout << "\033[33m"<<"                               ||---------------------------||"<< endl;
    cout << "\033[33m"<<"                               ||         "<<"\033[0m"<<"4. "<<"\033[35m"<<"DOMPET"<<"\033[0m"<<"\033[33m"<<"         ||                            "<< endl;
    cout <<"\033[33m";
    cout << "                               II===========================II                            "<<"\033[0m"<< endl;
    cout << "                            "<<"\033[32m"<<"PILIH GAME ATAU CEK WALLET (1/2/3/4): " <<"\033[0m"<< endl;
}


void garis(){
    cout <<"===================================================================="<< endl;
}

void gacha(int digit, int row) {
    cout << "\033[0m";
    cout << "|  ";
    switch (digit) {
        case 0:
            cout << "\033[1m\033[30m";
            if (row == 1)      cout << "|     0000     |";
            else if (row == 2) cout << "|   00    00   |";
            else if (row == 3) cout << "|  00      00  |";
            else if (row == 4) cout << "|  00      00  |";
            else if (row == 5) cout << "|  00      00  |";
            else if (row == 6) cout << "|  00      00  |";
            else if (row == 7) cout << "|   00    00   |";
            else if (row == 8) cout << "|     0000     |";
            cout << "\033[0m";
            break;
        case 1:
            cout << "\033[31m";
            if (row == 1)      cout << "|       11     |";
            else if (row == 2) cout << "|      111     |";
            else if (row == 3) cout << "|     1111     |";
            else if (row == 4) cout << "|       11     |";
            else if (row == 5) cout << "|       11     |";
            else if (row == 6) cout << "|       11     |";
            else if (row == 7) cout << "|       11     |";
            else if (row == 8) cout << "|      1111    |";
            cout << "\033[0m";
            break;
        case 2:
            cout <<"\033[32m" ;
            if (row == 1)      cout << "|     22222    |";
            else if (row == 2) cout << "|    22   22   |";
            else if (row == 3) cout << "|         22   |";
            else if (row == 4) cout << "|        22    |";
            else if (row == 5) cout << "|      222     |";
            else if (row == 6) cout << "|    22        |";
            else if (row == 7) cout << "|   22         |";
            else if (row == 8) cout << "|   222222222  |";
            cout << "\033[0m";
            break; 
        case 3:
            cout << "\033[33m";
            if (row == 1)      cout << "|     33333    |";
            else if (row == 2) cout << "|    33    33  |";
            else if (row == 3) cout << "|         33   |";
            else if (row == 4) cout << "|       333    |";
            else if (row == 5) cout << "|         33   |";
            else if (row == 6) cout << "|         33   |";
            else if (row == 7) cout << "|    33    33  |";
            else if (row == 8) cout << "|     33333    |";
            cout << "\033[0m";
            break;
        case 4:
            cout <<"\033[34m" ;
            if (row == 1)      cout << "|      44444   |";
            else if (row == 2) cout << "|     44  44   |";
            else if (row == 3) cout << "|    44   44   |";
            else if (row == 4) cout << "|   44    44   |";
            else if (row == 5) cout << "|  4444444444  |";            
            else if (row == 6) cout << "|         44   |";
            else if (row == 7) cout << "|         44   |";
            else if (row == 8) cout << "|         44   |";
            cout << "\033[0m";
            break;
        case 5:
            cout <<"\033[35m" ;
            if (row == 1)      cout << "|   55555555   |";
            else if (row == 2) cout << "|   55         |";
            else if (row == 3) cout << "|   55         |";
            else if (row == 4) cout << "|   55555555   |";
            else if (row == 5) cout << "|         55   |";
            else if (row == 6) cout << "|         55   |";
            else if (row == 7) cout << "|   55    55   |";
            else if (row == 8) cout << "|     5555     |";
            cout << "\033[0m";
            break;
        case 6:
            cout << "\033[36m";
            if (row == 1)      cout << "|    666666    |"   ;
            else if (row == 2) cout << "|   66         |"   ;
            else if (row == 3) cout << "|   66         |"   ;
            else if (row == 4) cout << "|   6666666    |"   ;
            else if (row == 5) cout << "|   66    66   |"   ;
            else if (row == 6) cout << "|   66     66  |"   ;
            else if (row == 7) cout << "|   66    66   |"   ;
            else if (row == 8) cout << "|     6666     |"   ;
            cout << "\033[0m";
            break;
        case 7:
            cout << "\033[37m";
            if (row == 1)      cout << "|   777777777  |"   ;
            else if (row == 2) cout << "|         77   |"   ;
            else if (row == 3) cout << "|        77    |"   ;
            else if (row == 4) cout << "|       77     |"   ;
            else if (row == 5) cout << "|      77      |"   ;
            else if (row == 6) cout << "|     77       |"   ;
            else if (row == 7) cout << "|    77        |"   ;
            else if (row == 8) cout << "|   77         |"   ;
            cout << "\033[0m";
            break;
        case 8:
            cout << "\033[1m\033[35m";
            if (row == 1)      cout << "|     88888    |"   ;
            else if (row == 2) cout << "|    88   88   |"   ;
            else if (row == 3) cout << "|   88     88  |"   ;
            else if (row == 4) cout << "|     88888    |"   ;
            else if (row == 5) cout << "|     88 88    |"   ;
            else if (row == 6) cout << "|    88   88   |"   ;
            else if (row == 7) cout << "|   88     88  |"   ;
            else if (row == 8) cout << "|     88888    |"   ;
            cout << "\033[0m";
            break;
        case 9:
            cout <<"\033[1m\033[31m" ;   
            if (row == 1)      cout << "|    9999999   |"   ;
            else if (row == 2) cout << "|   99    99   |"   ;
            else if (row == 3) cout << "|   99    99   |"   ;
            else if (row == 4) cout << "|   99    99   |"   ;
            else if (row == 5) cout << "|    9999999   |"   ;
            else if (row == 6) cout << "|         99   |"   ;
            else if (row == 7) cout << "|         99   |"   ;
            else if (row == 8) cout << "|   99999999   |" ;
            cout << "\033[0m";
            break;
        default:
            cout << "|               |";
    }
    cout << "  |";
}

void tampil_gacha(){
    garis();
    cout <<"|"<<"\033[31m"<<"      d8888b  "<<"\033[33m"<<"        d8888"<<"\033[32m"<<"   d8888b  "<<"\033[34m"<<" 888    888"<<"\033[35m"<<"        d8888"<<"\033[0m"<<"    |    ___ " << endl;
    cout <<"|"<<"\033[31m"<<"    d88P  Y88b"<<"\033[33m"<<"       d88888"<<"\033[32m"<<" d88P  Y88b"<<"\033[34m"<<" 888    888"<<"\033[35m"<<"       d88888"<<"\033[0m"<<"    |   [ - ]" << endl;
    cout <<"|"<<"\033[31m"<<"    888    888"<<"\033[33m"<<"      d88P888"<<"\033[32m"<<" 888    888"<<"\033[34m"<<" 888    888"<<"\033[35m"<<"      d88P888"<<"\033[0m"<<"    |    | |" << endl;
    cout <<"|"<<"\033[31m"<<"    888       "<<"\033[33m"<<"     d88P 888"<<"\033[32m"<<" 888       "<<"\033[34m"<<" 8888888888"<<"\033[35m"<<"     d88P 888"<<"\033[0m"<<"    |_   | |" << endl;
    cout <<"|"<<"\033[31m"<<"    888  88888"<<"\033[33m"<<"    d88P  888"<<"\033[32m"<<" 888       "<<"\033[34m"<<" 888    888"<<"\033[35m"<<"    d88P  888"<<"\033[0m"<<"    | |__| |" << endl;
    cout <<"|"<<"\033[31m"<<"    888    888"<<"\033[33m"<<"   d88P   888"<<"\033[32m"<<" 888    888"<<"\033[34m"<<" 888    888"<<"\033[35m"<<"   d88P   888"<<"\033[0m"<<"    | |____|" << endl;
    cout <<"|"<<"\033[31m"<<"    Y88b  d88P"<<"\033[33m"<<"  d8888888888"<<"\033[32m"<<" Y88b  d88P"<<"\033[34m"<<" 888    888"<<"\033[35m"<<"  d8888888888"<<"\033[0m"<<"    |_|" << endl;
    cout <<"|"<<"\033[31m"<<"     Y8888P88 "<<"\033[33m"<<" d88P     888"<<"\033[32m"<<"   Y8888P  "<<"\033[34m"<<" 888    888"<<"\033[35m"<<" d88P     888"<<"\033[0m"<<"    |" << endl;
    garis();
    cout << "\033[1m\033[30m";
}

// Penggunaan array
void display_numbers(int angka_acak[3]) {
    for (int row = 1; row <= 8; row++) {
        for (int i = 0; i < 3; i++) {
            gacha(angka_acak[i], row);
            if (i < 2) cout << " ";
        }
        cout << endl;
    }
    garis();
}

void spin_animation(int angka_acak[3], int duration_ms) {
    // Penggunaan Array
    int temp[3];
    for (int i = 0; i < duration_ms; i += 100) {
        for (int j = 0; j < 3; j++) {
            temp[j] = rand() % 10; 
        }
         system("cls");
        tampil_gacha();
        display_numbers(temp);
        usleep(100000);
    }
}

void slot() {
    string pil;
    // Penggunaan Array
    int angka_acak[3];
    game game1;
    game1.nama =  "\033[31m""S""\033[0m""\033[33m""L""\033[0m""\033[32m""O""\033[0m""\033[34m""T""\033[0m";
    game1.petunjuk = "1. Harga Token untuk sekali tarik adalah 10 koin\n2. Pemain Akan Mendapatkan JACKPOT Jika Terdapat Ketiga Angka Bernilai Sama. Untuk Semua Angka\n3. Jika JACKPOT pemain akan mendapatkan +100 koin";
    
    b:
    system("cls");
        tampil_gacha();
        cout << "\033[0m";
    for (int row = 1; row <= 8; ++row) {
        if (row == 1)      cout << "|  |              |  |";
        else if (row == 2) cout << "|  |              |  |";
        else if (row == 3) cout << "|  |              |  |";
        else if (row == 4) cout << "|  |              |  |";
        else if (row == 5) cout << "|  |              |  |";
        else if (row == 6) cout << "|  |              |  |";
        else if (row == 7) cout << "|  |              |  |";
        else if (row == 8) cout << "|  |              |  |";
        if (row == 1)      cout << " |  |              |  |";
        else if (row == 2) cout << " |  |              |  |";
        else if (row == 3) cout << " |  |              |  |";
        else if (row == 4) cout << " |  |              |  |";
        else if (row == 5) cout << " |  |              |  |";
        else if (row == 6) cout << " |  |              |  |";
        else if (row == 7) cout << " |  |              |  |";
        else if (row == 8) cout << " |  |              |  |";
        if (row == 1)      cout << " |  |              |  |";
        else if (row == 2) cout << " |  |              |  |";
        else if (row == 3) cout << " |  |              |  |";
        else if (row == 4) cout << " |  |              |  |";
        else if (row == 5) cout << " |  |              |  |";
        else if (row == 6) cout << " |  |              |  |";
        else if (row == 7) cout << " |  |              |  |";
        else if (row == 8) cout << " |  |              |  |";
        cout << endl;    
    }
        cout << "====================================================================" << endl;
        cout << "\033[0m";
        cout << "Nama Game: "<< game1.nama << endl;
        cout << "Petunjuk Permainan: \n" << game1.petunjuk << endl << endl;

        cout << "Koin Anda: " << "\033[33m" << koin << "\033[0m"  << endl;
        cout << "Pilihan anda!" << endl;
        cout << "\033[32m"<<"'y'" << "\033[0m" << " untuk bermain, "<< "\033[31m" << "'n' " << "\033[0m" << "untuk kembali ke Menu Utama: ";
        cin >> pil;
        cout << "====================================================================" << endl;
        
        while (true) {
        if (pil == "n" || pil == "N") {
            return;
        } else if (pil == "y" || pil == "Y") {
            if (koin < 10) {
                cout << "\nKoin Anda Tidak Cukup Untuk Bermain Lagi" << endl;
                break;
            }

            koin -= 10;
            tampil_gacha();
            srand(time(0));

            // ANIMASI UNTUK SPIN
            spin_animation(angka_acak, 2000);

            for (int i = 0; i < 3; i++) {
                angka_acak[i] = rand() % 10;
            }
            system("cls");

            tampil_gacha();
            display_numbers(angka_acak);
            
            ukuran1++; ukuran2++; g++; 
            if (angka_acak[0] == angka_acak[1] && angka_acak[0] == angka_acak[2]) {
                cout << "\033[1m\033[37m";
                cout << "888   888888      888888  dP8888b  888   888 8888888   d88888b  8888888  888" << endl;
                cout << "888      888     888 888 d88   888 888  888  888  888 d88   88b   888    888" << endl;
                cout << "888      888    888  888 d88       888DBP    88888888 d88   88b   888    888" << endl;
                cout << "888      888   888888888 d88       888 dP8   888      d88   88b   888    888" << endl;
                cout << "888  88  888  888    888 d88   888 888  Yb8  888      d88   88b   888    888" << endl;
                cout << " 8   8888888 888     888  888888P  888   Yb8 888       d88888b    888     B" << endl;
                cout << "\033[0m";
                cout << endl;
                cout << "!!! SELAMAT ANDA MENANG !!!" << endl;
                koin += 1000;
                riwayat_koin.push_back(100);
                riwayat_game.push_back("Slot");
                cout << "Koin" << "\033[32m" << " +100" << endl;
                cout << "\033[0m";
            } else {
                g--; ukuran1--; ukuran2--;  
            }
        } else {
            cout << "Error: Masukkan Tidak Valid" << endl;
            cout << "Harap Input Ulang" << endl;
            getchar(); getchar();
            goto b;
        }
        
        cout << "Koin: " << "\033[33m" << koin << endl << endl;
        cout << "\033[0m";
        a:
        cout << "Tarik Lagi [-" << "\033[31m" << "10 " << "\033[0m" << "koin]? (y/n): ";
        cin >> pil;
        if (pil == "y" || pil == "Y") {
            if (koin < 10) {
                cout << "\nKoin Anda Tidak Cukup Untuk Bermain Lagi" << endl;
                break;
            }
        } else if (pil == "n" || pil == "N") {
            break;
        } else {
            cout << "\nError: Masukkan Tidak Valid" << endl;
            cout << "Harap Input Ulang" << endl;
            getchar(); getchar();
            goto a;
        }
    }
}



void gelas(){
    cout << "Koin: " << "\033[33m" << koin << endl << endl;
    cout << "\033[1m\033[34m";
    cout << "\033[1m\033[34m"<<"           88888888 8888888 d8888b.  88888  88   88"<< "\033[1;37m" <<"      8888888 8888888 88       88888   888888 " << endl;
    cout << "\033[1m\033[34m"<<"              88    88      88   88 88   88 88  88" << "\033[1;37m" <<"       88   88 88      88      88   88 88    " << endl;
    cout << "\033[1m\033[34m"<<"              88    8888888 888888  8888888 88888"  << "\033[1;37m" <<"        88      8888888 88      8888888 8888888   " << endl;
    cout << "\033[1m\033[34m"<<"              88    88      88   88 88   88 88 88"  << "\033[1;37m" <<"        88  888 88      88      88   88      88 " << endl;
    cout << "\033[1m\033[34m"<<"              88    88      88   88 88   88 88  88" << "\033[1;37m" <<"       88   88 88      88      88   88 88   88 " << endl;
    cout << "\033[1m\033[34m"<<"              88    8888888 888888  88   88 88   88"<< "\033[1;37m" <<"      8888888 8888888 8888888 88   88  88888 " << endl << endl;
    cout << "\033[0m" << "\033[1;37m";
    cout << "             _______                    _______                    _______                    _______         " << endl;
    cout << "            /       \\                  /       \\                  /       \\                  /       \\        " << endl;
    cout << "           /         \\                /         \\                /         \\                /         \\       " << endl;
    cout << "          /           \\              /           \\              /           \\              /           \\      " << endl;
    cout << "         /             \\            /             \\            /             \\            /             \\     " << endl;
    cout << "        /               \\          /               \\          /               \\          /               \\    " << endl;
    cout << "       /                 \\        /                 \\        /                 \\        /                 \\   " << endl;
    cout <<"\033[33m"<< "   ---""\033[0m" "/                   \\""\033[33m""------""\033[0m""/                   \\""\033[0m" "\033[33m""------""\033[0m""/                   \\""\033[0m" "\033[33m""------""\033[0m""/                   \\""\033[0m" "\033[33m""---"<< endl;
    cout <<"\033[33m"<< "  /  ""\033[0m" "/         (1)         \\    /         (2)         \\    /         (3)         \\    /         (4)         \\""\033[33m""  \\" << endl;
    cout <<"\033[33m"<< " /  ""\033[0m" "/_______________________\\  /_______________________\\  /_______________________\\  /_______________________\\""\033[33m""  \\" << endl;
    cout <<"\033[33m"<< "-----------------------------------------------------------------------------------------------------------------""\033[0m" << endl;
    cout << "\033[0m";
}

void tampil_gelas(int acak) {
    vector<string> isigelas(4, "X");
    isigelas[acak - 1] = "O";
    
    cout << "Koin: " << "\033[33m" << koin << endl << endl;
    cout << "\033[1m\033[34m";
    cout << "\033[1m\033[34m"<<"           88888888 8888888 d8888b.  88888  88   88"<< "\033[1;37m" <<"      8888888 8888888 88       88888   888888 " << endl;
    cout << "\033[1m\033[34m"<<"              88    88      88   88 88   88 88  88" << "\033[1;37m" <<"       88   88 88      88      88   88 88    " << endl;
    cout << "\033[1m\033[34m"<<"              88    8888888 888888  8888888 88888"  << "\033[1;37m" <<"        88      8888888 88      8888888 8888888   " << endl;
    cout << "\033[1m\033[34m"<<"              88    88      88   88 88   88 88 88"  << "\033[1;37m" <<"        88  888 88      88      88   88      88 " << endl;
    cout << "\033[1m\033[34m"<<"              88    88      88   88 88   88 88  88" << "\033[1;37m" <<"       88   88 88      88      88   88 88   88 " << endl;
    cout << "\033[1m\033[34m"<<"              88    8888888 888888  88   88 88   88"<< "\033[1;37m" <<"      8888888 8888888 8888888 88   88  88888 " << endl << endl;
    cout << "\033[0m" << "\033[1;37m";
    cout << "             _______                    _______                    _______                    _______         " << endl;
    cout << "            /       \\                  /       \\                  /       \\                  /       \\        " << endl;
    cout << "           /         \\                /         \\                /         \\                /         \\       " << endl;
    cout << "          /           \\              /           \\              /           \\              /           \\      " << endl;
    cout << "         /      " << isigelas[0] << "      \\            /      " << isigelas[1] << "      \\            /      " << isigelas[2] << "      \\            /      " << isigelas[3] << "      \\     " << endl;
    cout << "        /               \\          /               \\          /               \\          /               \\    " << endl;
    cout << "       /                 \\        /                 \\        /                 \\        /                 \\   " << endl;
    cout <<"\033[33m"<< "   ---""\033[0m" "/                   \\""\033[33m""------""\033[0m""/                   \\""\033[0m" "\033[33m""------""\033[0m""/                   \\""\033[0m" "\033[33m""------""\033[0m""/                   \\""\033[0m" "\033[33m""---"<< endl;
    cout <<"\033[33m"<< "  /  ""\033[0m" "/         (1)         \\    /         (2)         \\    /         (3)         \\    /         (4)         \\""\033[33m""  \\" << endl;
    cout <<"\033[33m"<< " /  ""\033[0m" "/_______________________\\  /_______________________\\  /_______________________\\  /_______________________\\""\033[33m""  \\" << endl;
    cout <<"\033[33m"<< "-----------------------------------------------------------------------------------------------------------------""\033[0m" << endl;
    cout << "\033[0m";
}

void acak_gelas() {
system("cls");
    int tebakan, acak;
    string pil;
    string pil1, pil3;
    game game2;
    game2.nama = "\033[34m""TEBAK""\033[0m"" GELAS""\033[33m""\033[0m"; 
    game2.petunjuk = "Pemain Menebak Keempat Gelas Untuk Mendapatkan Bola Yang Terdapat Di Gelas Yang Tepat, Sebanyak 3x Percobaan";
    srand(time(0));
    bool kondisi = true;
    
    a:
    while (kondisi) {
        acak = 1 + (rand() % 4);
        system("cls");
        tampil_gelas(acak);
        cout<<"Nama Game: " << game2.nama << endl;
        cout<<"Petunjuk Permainan: "<<game2.petunjuk<<endl<<endl;
        cout<<"Pilihan anda!" << endl;
        cout << "\033[32m" << "'y'" << "\033[0m" << " untuk bermain, "<< "\033[31m" << "'n' " << "\033[0m" << "untuk kembali ke Menu Utama: ";
        cin>>pil3;
        
        if(pil3 == "n" || pil3 == "N"){
            return;
        }
        else if(pil3 == "y" || pil3 == "Y"){
        system("cls");
        
        c:
        tampil_gelas(acak);
        cout << "Apakah Omae Siap? Tekan Enter!" << endl;
        cin.ignore();
        system("cls");

        while (true) {
            gelas();
            cout << "Acak? (y/n [Jika sudah selesai mengacak ketik n]) : "; cin >> pil;
            if (pil == "n" || pil == "N") break;
            acak = 1 + (rand() % 4);
            system("cls");
        }
        bool tebakan_benar = false;
        
        ukuran1++; ukuran2++; g++; 
        for (int i = 1; i <= 3; i++) {
            cout << "Tebakan Ke-" << i << " (1-4): "; cin >> tebakan;
            if (tebakan == acak) {
                tampil_gelas(tebakan);
                cout << "\033[32m" << endl;
                cout << "Tebakan Anda Benar" << endl;
                cout << "\033[0m" << endl;
                koin += 25;
                riwayat_koin.push_back(25);  
                riwayat_game.push_back("Tebak Gelas");
                cout << "Koin" << "\033[32m" << " +25" << endl;
                cout << "\033[0m";
                tebakan_benar = true;
                break;
            }
        }

        if (!tebakan_benar) {
            cout << "\033[31m";
            cout << "Tebakan Anda Salah 3x Berturut-turut" << endl;
            cout << "\033[0m";
           g--; ukuran1--; ukuran2--;  
        }
        
        do{
        cout << "Ingin Main Lagi [-" <<  "\033[33m" << "10 " << "\033[0m" << "koin]? (y/n): "; cin >> pil1;
        if (pil1 == "y" || pil1 == "Y") {
            if (koin < 10) {
                return;
            } else {
                koin -= 10;
                cout << "Koin" << "\033[31m" << " -10" << endl;
                cout << "\033[0m";
                cout << "Tekan Enter Untuk Bermain Lagi" << endl;
                goto c;
                cin.ignore(); cin.get();
            }
        } else if(pil1 == "n" || pil1 == "N"){
            return;
        }
        cout<<"\nError: Masukkan Tidak Valid"<<endl;
        cout<<"Harap Input Ulang"<<endl<<endl;
        getchar();
        }while(pil1 != "n" || pil1 != "N" || pil1 != "y" || pil1 != "Y");
    }else{
        cout<<"\nError: Masukkan Tidak Valid"<<endl;
        cout<<"Harap Input Ulang"<<endl;
        getchar();getchar();
        goto a;
    }
    }
}

void gachak(int digit, int row) {
    cout << "\033[1;37m";
    switch (digit) {
        case 1:
            if (row == 1)      cout << "I---------------I";
            else if (row == 2) cout << "|       11      |";
            else if (row == 3) cout << "|      111      |";
            else if (row == 4) cout << "|     1111      |";
            else if (row == 5) cout << "|       11      |";
            else if (row == 6) cout << "|       11      |";
            else if (row == 7) cout << "|       11      |";
            else if (row == 8) cout << "|       11      |";
            else if (row == 9) cout << "|      1111     |";
            else if (row == 10) cout << "I---------------I";
            break;
        case 2:
            if (row == 1)      cout << "I---------------I";
            else if (row == 2) cout << "|     22222     |";
            else if (row == 3) cout << "|    22   22    |";
            else if (row == 4) cout << "|         22    |";
            else if (row == 5) cout << "|        22     |";
            else if (row == 6) cout << "|      222      |";
            else if (row == 7) cout << "|    22         |";
            else if (row == 8) cout << "|   22          |";
            else if (row == 9) cout << "|   222222222   |";
            else if (row == 10) cout << "I---------------I";
            break; 
        case 3:
            if (row == 1)      cout << "I---------------I";
            else if (row == 2) cout << "|     33333     |";
            else if (row == 3) cout << "|    33    33   |";
            else if (row == 4) cout << "|         33    |";
            else if (row == 5) cout << "|       333     |";
            else if (row == 6) cout << "|         33    |";
            else if (row == 7) cout << "|         33    |";
            else if (row == 8) cout << "|    33    33   |";
            else if (row == 9) cout << "|     33333     |";
            else if (row == 10) cout << "I---------------I";
            break;
        case 4:
            if (row == 1)      cout << "I---------------I";
            else if (row == 2) cout << "|      44444    |";
            else if (row == 3) cout << "|     44  44    |";
            else if (row == 4) cout << "|    44   44    |";
            else if (row == 5) cout << "|   44    44    |";
            else if (row == 6) cout << "|  4444444444   |";
            else if (row == 7) cout << "|         44    |";
            else if (row == 8) cout << "|         44    |";
            else if (row == 9) cout << "|         44    |";
            else if (row == 10) cout << "I---------------I";
            break;
        case 5:
            if (row == 1)      cout << "I---------------I";
            else if (row == 2) cout << "|    55555555   |";
            else if (row == 3) cout << "|    55         |";
            else if (row == 4) cout << "|    55         |";
            else if (row == 5) cout << "|    55555555   |";
            else if (row == 6) cout << "|          55   |";
            else if (row == 7) cout << "|          55   |";
            else if (row == 8) cout << "|    55    55   |";
            else if (row == 9) cout << "|      5555     |";
            else if (row == 10) cout << "I---------------I";
            break;
        case 6:
            if (row == 1)      cout << "I---------------I";
            else if (row == 2) cout << "|    666666     |"   ;
            else if (row == 3) cout << "|   66          |"   ;
            else if (row == 4) cout << "|   66          |"   ;
            else if (row == 5) cout << "|   6666666     |"   ;
            else if (row == 6) cout << "|   66    66    |"   ;
            else if (row == 7) cout << "|   66     66   |"   ;
            else if (row == 8) cout << "|   66    66    |"   ;
            else if (row == 9) cout << "|     6666      |"   ;
            else if (row == 10) cout << "I---------------I";
            break;
        case 7:
            if (row == 1)      cout << "I---------------I";
            else if (row == 2) cout << "|    777777777  |"   ;
            else if (row == 3) cout << "|          77   |"   ;
            else if (row == 4) cout << "|         77    |"   ;
            else if (row == 5) cout << "|        77     |"   ;
            else if (row == 6) cout << "|       77      |"   ;
            else if (row == 7) cout << "|      77       |"   ;
            else if (row == 8) cout << "|     77        |"   ;
            else if (row == 9) cout << "|    77         |"   ;
            else if (row == 10) cout << "I---------------I";
            break;
        case 8:
            if (row == 1)      cout << "I---------------I";
            else if (row == 2) cout << "|     88888     |"   ;
            else if (row == 3) cout << "|    88   88    |"   ;
            else if (row == 4) cout << "|   88     88   |"   ;
            else if (row == 5) cout << "|     88888     |"   ;
            else if (row == 6) cout << "|     88 88     |"   ;
            else if (row == 7) cout << "|    88   88    |"   ;
            else if (row == 8) cout << "|   88     88   |"   ;
            else if (row == 9) cout << "|     88888     |"   ;
            else if (row == 10) cout << "I---------------I";
            break;
        case 9:   
            if (row == 1)      cout << "I---------------I";
            else if (row == 2) cout << "|     9999999   |"   ;
            else if (row == 3) cout << "|    99    99   |"   ;
            else if (row == 4) cout << "|    99    99   |"   ;
            else if (row == 5) cout << "|    99    99   |"   ;
            else if (row == 6) cout << "|     9999999   |"   ;
            else if (row == 7) cout << "|          99   |"   ;
            else if (row == 8) cout << "|          99   |"   ;
            else if (row == 9) cout << "|    99999999   |"   ;
            else if (row == 10) cout << "I---------------I";
            break;
        case 10:   
            if (row == 1)      cout << "I---------------I";
            else if (row == 2) cout << "|   11    00000 |" ; 
            else if (row == 3) cout << "|  111    0|-|0 |" ; 
            else if (row == 4) cout << "| 1111    0| |0 |" ;
            else if (row == 5) cout << "|   11    0| |0 |" ;
            else if (row == 6) cout << "|   11    0| |0 |" ;
            else if (row == 7) cout << "|   11    0| |0 |" ;
            else if (row == 8) cout << "|   11    0|-|0 |" ;
            else if (row == 9) cout << "|  1111   00000 |" ;
            else if (row == 10) cout << "I---------------I";
            break;
        case 11:    
            if (row == 1)      cout << "I---------------I";
            else if (row == 2) cout << "|   11      11  |"  ;
            else if (row == 3) cout << "|  111     111  |"  ;
            else if (row == 4) cout << "| 1111    1111  |"  ;
            else if (row == 5) cout << "|   11      11  |"  ;
            else if (row == 6) cout << "|   11      11  |"  ;
            else if (row == 7) cout << "|   11      11  |"  ; 
            else if (row == 8) cout << "|   11      11  |"  ;
            else if (row == 9) cout << "|  1111    1111 |"  ;
            else if (row == 10) cout << "I---------------I";
            break;
        default:
        break;
    }
cout <<"\033[0m" ;
}

void kartu(int kartu[], int size) {
    for (int baris = 1; baris <= 10; baris++) {
        for (int j = 0; j < size; j++) {
            gachak(kartu[j], baris);
            if (j < size - 1) cout << " ";
        }
        cout << endl;
    }
}

void blackjack() {
    string pil, pil1,balek;
    int poin_pemain = 0, poin_dealer = 0, angka_acak1, angka_acak2;
    int kartu_pemain[100] = {0};
    int kartu_dealer[100] = {0};
    int i = 0, j = 0, bet;
    game game3;
    game3.nama = "\033[1m\033[30m""BLACK""\033[0m""JACK!""\033[33m""\033[0m"; 
    game3.petunjuk = "\n1. Masukkan jumlah koin yang ingin anda mainkan\n2. Blackjack kali ini sama seperti pada umumnya dimana ketika pemain mendapatkan total 21 akan mendpatakan blackjack\n3. Disini pemain akan melawan dealer untuk mendapatkan kemenangan\n4. Untuk blackjack ini memiliki peraturan khusus dimana pemain hanya bisa menarik 4 kartu saja\n5. Jika menang pemain akan mendapatkan 2x dari koin yang dimainkan (10 = 20), jika kalah koin yang dimainkan akan hangus, jika seri pemain akan mendapatkan koinnya kembali\n";
    
    ulang:
    cabutlu:
    system ("cls");
    srand(time(0));
    cout << "---------------------------------------------------------------------------" << endl;   
    cout <<"\033[1m\033[30m"<< "888888  88       88888   888888 88   88 " << "\033[37m" <<"   8888  88888   888888 88   88 88 " << endl;
    cout <<"\033[1m\033[30m"<< "88  88  88      88   88 888  88 88  88  " << "\033[37m" <<"    88  88   88 888  88 88  88  88 " << endl;
    cout <<"\033[1m\033[30m"<< "888888  88      8888888 88      88888   " << "\033[37m" <<"    88  8888888 88      88888   88 " << endl;
    cout <<"\033[1m\033[30m"<< "88   88 88      88   88 8       88 88   " << "\033[37m" <<"    88  88   88 88      88 88   88 " << endl;
    cout <<"\033[1m\033[30m"<< "88   88 88      88   88 888  88 88  88  " << "\033[37m" <<"    88  88   88 888  88 88  88      " << endl;
    cout <<"\033[1m\033[30m"<< "8888888 8888888 88   88  888888 88   88 " << "\033[37m" <<"888888  88   88  888888 88   88 88 " << endl;
    cout <<"\033[0m" << "---------------------------------------------------------------------------" << endl;                                                                   
    cout<<"Nama Game: "<< game3.nama << endl;
    cout<<"Petunjuk Permainan: "<<game3.petunjuk<<endl;
    cout<<"Pilihan anda!" << endl;
    cout << "\033[32m"<<"'y'" << "\033[0m" << " untuk bermain, "<< "\033[31m" << "'n' " << "\033[0m" << "untuk kembali ke Menu Utama: "; cin>>balek;
        if (balek == "n" || balek == "n"){
            return;
            }
    else if(balek == "y" || balek == "Y"){
        main:
    cout << "\nKoin: " << "\033[33m" << koin << endl;
    cout << "\033[1;37m";
    cout <<"Masukan Jumlah Koin: "; cin >> bet;
        if (bet > koin){
            system ("cls");
            cout << "Sayang sekali koin anda tidak cukup untuk melakukanya\n";
            cout << "Tekan Enter Untuk Bermain Lagi" << endl;
                cin.ignore(); cin.get();
            goto cabutlu;
        }
    
    ukuran1++; ukuran2++; g++; 
    while (true) {
        system("cls");
        cout << "---------------------------------------------------------------------------" << endl;   
        cout <<"\033[1m\033[30m"<< "888888  88       88888   888888 88   88 " << "\033[37m" <<"   8888  88888   888888 88   88 88 " << endl;
        cout <<"\033[1m\033[30m"<< "88  88  88      88   88 888  88 88  88  " << "\033[37m" <<"    88  88   88 888  88 88  88  88 " << endl;
        cout <<"\033[1m\033[30m"<< "888888  88      8888888 88      88888   " << "\033[37m" <<"    88  8888888 88      88888   88 " << endl;
        cout <<"\033[1m\033[30m"<< "88   88 88      88   88 8       88 88   " << "\033[37m" <<"    88  88   88 88      88 88   88 " << endl;
        cout <<"\033[1m\033[30m"<< "88   88 88      88   88 888  88 88  88  " << "\033[37m" <<"    88  88   88 888  88 88  88      " << endl;
        cout <<"\033[1m\033[30m"<< "8888888 8888888 88   88  888888 88   88 " << "\033[37m" <<"888888  88   88  888888 88   88 88 " << endl;
        cout <<"\033[0m" << "---------------------------------------------------------------------------" << endl;                                                                   
        cout << "\033[31m" << "Kartu Dealer: " "\033[0m" << endl;
        kartu(kartu_dealer, j);
        cout << "\033[31m" << "Dealer: " << "\033[0m" << poin_dealer << endl <<endl;

        cout << "\033[32m" << "Kartu Anda: " << "\033[0m" << endl;
        kartu(kartu_pemain, i);
        cout << "\033[32m" << "Anda: " << "\033[0m" << poin_pemain << endl << endl;
        cout << "Tekan 'p' Untuk Tarik Kartu!" << endl;
        cout << "Tekan 's' Untuk Skip/Lewat!" << endl << "Pilihan anda: ";
        getline(cin, pil);

        if (pil == "p" || pil == "P") {
            angka_acak1 = 1 + (rand() % 11);
            if(poin_pemain > 10 && angka_acak1 == 11){
                angka_acak1 -= 10;
            }
            kartu_pemain[i] = angka_acak1; i++;
            poin_pemain += angka_acak1;
            if(poin_dealer <= 16){
                angka_acak2 = 1 + (rand() % 11);
            }else{
                angka_acak2 = 0;
            }
            if(poin_dealer > 10 && angka_acak2 == 11){
                angka_acak2 -= 10;
            }
            kartu_dealer[j] = angka_acak2; j++;
            poin_dealer += angka_acak2;
        } else if (pil == "s" || pil == "S") {
            
                angka_acak2 = 1 + (rand() % 11);
                if(poin_dealer > 10 && angka_acak2 == 11){
                    angka_acak2 -= 10;
                }
                kartu_dealer[j] = angka_acak2; j++;
                poin_dealer += angka_acak2;      
        } 

        system("cls");
        cout << "---------------------------------------------------------------------------" << endl;   
        cout <<"\033[1m\033[30m"<< "888888  88       88888   888888 88   88 " << "\033[37m" <<"   8888  88888   888888 88   88 88 " << endl;
        cout <<"\033[1m\033[30m"<< "88  88  88      88   88 888  88 88  88  " << "\033[37m" <<"    88  88   88 888  88 88  88  88 " << endl;
        cout <<"\033[1m\033[30m"<< "888888  88      8888888 88      88888   " << "\033[37m" <<"    88  8888888 88      88888   88 " << endl;
        cout <<"\033[1m\033[30m"<< "88   88 88      88   88 8       88 88   " << "\033[37m" <<"    88  88   88 88      88 88   88 " << endl;
        cout <<"\033[1m\033[30m"<< "88   88 88      88   88 888  88 88  88  " << "\033[37m" <<"    88  88   88 888  88 88  88      " << endl;
        cout <<"\033[1m\033[30m"<< "8888888 8888888 88   88  888888 88   88 " << "\033[37m" <<"888888  88   88  888888 88   88 88 " << endl;
        cout <<"\033[0m" << "---------------------------------------------------------------------------" << endl;       

        cout << "\033[31m" << "Kartu Dealer: " "\033[0m" << endl;
        kartu(kartu_dealer, j);
        cout << "\033[31m" << "Dealer: " << "\033[0m" << poin_dealer << endl <<endl;

        cout << "\033[32m" << "Kartu Anda: " << "\033[0m" << endl;
        kartu(kartu_pemain, i);
        cout << "\033[32m" << "Anda: " << "\033[0m" << poin_pemain << endl;
        
        if((poin_pemain > 21 && poin_dealer > 21) || (poin_pemain == 21 && poin_dealer == 21)){
            cout << "\nSeri!" << endl;
            koin += 0;
            break;
        } else if (poin_pemain > 21){
            cout << "\033[32m" << "\nAnda" << "\033[0m" << " BUST! Melebihi 21," << "\033[31m" <<" Dealer" << "\033[0m" << " Menang!" << endl;
            koin -= bet;
            g--; ukuran1--; ukuran2--;  
            break;
        } else if(poin_dealer > 21){
            cout << "\033[31m" << "\nDealer " << "\033[0m" << "BUST! Melebihi 21," << "\033[32m" << "Anda " << "\033[0m" << "Menang!" << endl;
            koin -= bet;
            koin = koin + bet * 2;
            riwayat_koin.push_back(bet);  
            riwayat_game.push_back("BlackJack");
            cout << "Koin" << "\033[32m" << " +"<<bet << endl;
            cout << "\033[0m";
            break;
        } else if(poin_pemain == 21){
            cout << "\033[32m" << "\nAnda " << "\033[0m" << "Mendapatkan BLACKJACK," << "\033[32m" <<" Anda " << "\033[0m" << "Menang!" << endl;
            koin -= bet;
            koin = koin + bet * 2;
            riwayat_koin.push_back(bet);  
            riwayat_game.push_back("BlackJack");
            cout << "Koin" << "\033[32m" << " +"<<bet << endl;
            cout << "\033[0m";
            break;
        } else if(poin_dealer == 21){
            cout << "\033[31m" << "\nDealer " << "\033[0m" << "Mendapatkan BLACKJACK, " << "\033[31m" << "Dealer " << "\033[0m" << "Menang!" << endl;
            koin -= bet;
            g--; ukuran1--; ukuran2--;  
            break;
        } else if(poin_pemain > poin_dealer && j >= 4){
            cout << "\033[32m" << "\nAnda " << "\033[0m" << "Mendapatkan Poin Lebih Tinggi," << "\033[32m" << " Anda " << "\033[0m" << "Menang!" << endl;
            koin -= bet;
            koin = koin + bet * 2;
            riwayat_koin.push_back(bet);  
            riwayat_game.push_back("BlackJack");
            cout << "Koin" << "\033[32m" << " +"<<bet << endl;
            cout << "\033[0m";
            break;
        } else if(poin_pemain < poin_dealer && j >= 4){
            cout << "\033[31m" << "\nDealer " << "\033[0m" << "Mendapatkan Poin Lebih Tinggi, " << "\033[31m" << "Dealer " << "\033[0m" << "Menang!" << endl;
            koin -= bet;
            g--; ukuran1--; ukuran2--;  
            break;
        }else if(j >= 4 && poin_pemain == poin_dealer){
            cout<<"\nSeri!"<<endl;
            koin += 0;
            break;
        }
    }

    cout  << "\nPoin " << "\033[32m" << "Anda   : " << "\033[0m" << poin_pemain << endl;
    cout <<  "Poin " << "\033[31m" << "Dealer : " << "\033[0m" << poin_dealer << endl;
    cout << "\nPermainan Selesai" << endl;
    cout << "Koin: " << "\033[33m" << koin << endl << endl;
    cout << "\033[1;37m";
    while (true) {
        cout << "Ingin Main Lagi? (y/n): "; 
        cin >> pil1;
        if (pil1 == "y" || pil1 == "Y") {
            cout << "Tekan Enter Untuk Bermain Lagi" << endl;
            cin.ignore(); cin.get();
            poin_pemain = 0;
            poin_dealer = 0;
            i = 0;
            j = 0;
            goto main;
            break;
            
        } else if (pil1 == "n" || pil1 == "N") {
            cout << "Terima Kasih Telah Bermain!" << endl;
            break;
        } else {
            cout << "Pilihan Tidak Valid, Harap Coba Lagi" << endl;
        }
    }
}
else{
    cout<<"\nError: Masukkan Tidak Valid"<<endl;
    cout<<"Harap Input Ulang"<<endl;
    getchar(); getchar();
    goto ulang;
}
}
