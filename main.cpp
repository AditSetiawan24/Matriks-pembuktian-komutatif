#include <iostream>

using namespace std;

const int max_size = 100;

class matrix {
public:
    int data[max_size][max_size];
    int baris, kolom;

    matrix(int b, int k) {
        baris = b;
        kolom = k;
        for(int i = 0; i < baris; i++) {
            for(int j = 0; j < kolom; j++) {
                data[i][j]=0;
            }
        }
    }

    void input() {
        for(int i = 0; i < baris; i++) {
            for(int j = 0; j < kolom; j++) {
                cout << "Elemen baris" << i+1 << " Elemen kolom" << j+1 << ": ";
                cin >> data[i][j];
            }
        }
    }

    void print() {
        for(int i = 0; i < baris; i++) {
            for(int j = 0; j < kolom; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    matrix add(const matrix& B) {
        matrix result(baris, kolom);
        for(int i = 0; i < baris; i++) {
            for(int j = 0; j < kolom; j++) {
                result.data[i][j] = data[i][j] + B.data[i][j];
            }
        }
        return result;
    }

    bool equals(const matrix& B) {
        if(baris != B.baris || kolom != B.kolom) {
            return false;
        }
        for(int i = 0; i < baris; i++) {
            for(int j = 0; j < kolom; j++) {
                if(data[i][j] != B.data[i][j]) return false;
            }
        }
        return true;
    }
};

int main () {
    int barisA, kolomA, barisB, kolomB;
    
    cout << "\nMasukan dimensi matrix A\n";
    cout << "Baris: ";
    cin >> barisA;
    cout << "kolom: ";
    cin >> kolomA;
    
    cout << "\nMasukan dimensi matrix B\n";
    cout << "Baris: ";
    cin >> barisB;
    cout << "kolom: ";
    cin >> kolomB;
    
    matrix A(barisA, kolomA);
    matrix B(barisB, kolomB);
    
    cout << endl << "\nMasukan elemen matrix A: \n";
    A.input();
    
    cout << endl << "\nMasukan elemen matrix B: \n";
    B.input();
    
    cout << "\nMatrix A\n";
    A.print();
    
    cout << "\nMatrix B\n";
    B.print();
    
    if(barisA == barisB && kolomA == kolomB) {
        matrix AplusB = A.add(B);
        matrix BplusA = B.add(A);
        
        cout << "\nHasil A+B: \n";
        AplusB.print();
        
        cout << "\nHasil B+A: \n";
        BplusA.print();
        
        if(AplusB.equals(BplusA)) {
            cout << "\nKomutatif terbukti A + B = B + A \n";
        } else {
            cout << "Komutatif tidak terbukti.\n";
        }
    } else {
        cout << "Penjumlahan tidak dapat dilakukan karena dimensi matriks tidak sesuai.\n";
    }

    return 0;
}
