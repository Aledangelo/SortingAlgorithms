#include <iostream>
#include <time.h>

using namespace std;

void insertionSort(int*);

int N;

int main() {
    int i;
    clock_t inizio,fine;
    double tempo;

    srand(time(NULL));

    N = 1 + rand() % 10001;
    int A[N];

    for(i = 1; i <= N; i++) {
        A[i] = rand() % 65001;
    }
    cout<<"Vettore A:               ";
    for(i = 1; i <= N; i++) {
        cout<<A[i]<<"|";
    }
    cout<<endl;

    inizio = clock();
    insertionSort(A);
    fine = clock();

    tempo = ((double) (fine-inizio))/CLOCKS_PER_SEC;

    cout<<"Vettore A ordinato:      ";
    for(i = 1; i <= N; i++) {
        cout<<A[i]<<"|";
    }
    cout<<endl;

    cout<<"T(n):                    "<<tempo<<endl;
    cout<<"DIM:                     "<<N<<endl;

    return 0;
}

void insertionSort(int* A) {
    int key;
    int i;
    for(int j = 2; j <= N; j++) {
        key = A[j];
        i = j-1;
        while(i > 0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}