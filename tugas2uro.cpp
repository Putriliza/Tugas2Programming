/* NAMA : PUTRI NURHALIZA
NIM : 16520063
TUGAS 2 URO */

/* PROGRAM KALKULATOR */

#include <iostream>
using namespace std;


double tambah(double x,double y) {return x+y;}

double kurang(double x,double y) {return x-y;}

double kali(double x,double y) {return x*y;}

double bagi(double x,double y) {return x/y;}

double pangkat(double x,int y) {
    double pow=1; 
    for(int i=1; i<=y; i++){
        pow *= x;
    }
    return pow;
}

double f(double x)  // INTEGRAL
{
    return x*x + 2*x - 1;  // test case fungsi yang akan diintegralkan
}

int main(){
    cout << "---------------KALKULATOR---------------\n";

    string calc = "ya";
    while (calc == "ya"){
        cout << "\n1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n4. Pembagian\n5. Perpangkatan\n6. Integral\n";
        cout << "Pilih operasi : ";
        int opsi;
        cin >> opsi;
        cout << "\n" ;

        if (opsi >= 0 && opsi <=5) {
            double x, y;
            cout << "Masukkan angka pertama  : ";
            cin >> x;
            cout << "Masukkan angka kedua    : ";
            cin >> y;
            cout << "Hasil                   = ";

            switch (opsi) {
                case 1:
                    cout << tambah(x,y) << endl;
                    break;
                case 2:
                    cout << kurang(x,y) << endl;
                    break;
                case 3:
                    cout << kali(x,y) << endl;
                    break;
                case 4:
                    cout << bagi(x,y) << endl;
                    break;
                case 5:
                    cout << pangkat(x,y) << endl;
                    break;
            }
        }

        else if (opsi==6) {
            double a,b,h,x,area;
            int n;
            cout << "Batas bawah    : ";
            cin >> a;
            cout << "Batas atas     : ";
            cin >> b;
            cout << "Subinterval    : "; 
            cin >> n;

            h=(b-a)/n;              // lebar subinterval (tinggi trapesium)
            
            // area = h/2 * ((f(a)+f(a+1)) + ((f(a+1)+f(a+2)) + ... + (f(b-1)+f(b))) 
            // area = h/2 * (f(a) + f(b) + 2(f(a+1) + f(a+2) + ... + f(b-1)))
            
            area = f(a) + f(b);
            for (int i=1; i<n; i++){
                x = a + i*h;
                area += 2*f(x);
            }
            area = (area*h)/2;
            cout<<"Hasil integral tentu = "<< area << endl;
        }

        else{
            cout <<"invalid input" << endl;
        }

        cout << "\nIngin melakukan operasi lagi? (ya/tidak)" << endl;
        cin >> calc;
    }
    cout << "---------------Terima Kasih---------------" << endl;
    return 0;
}