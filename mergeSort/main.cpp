#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

void merge(int*,int,int,int);
void mergeSort(int*,int,int);
int N;
int main() {

    //variabili per il calcolo del tempo di esecuzione in secondi
    clock_t start,end;
    double tempo;
    N = 0;
    int i = 0;
    int max = 5;

    //srand(time(NULL));

    //cout<<"Inserire il numero di tentativi da eseguire: ";
    //cin>>max;
    //cout<<endl;

    double vet_tempo[max];
    int vet_N[max];
    int k = 1000;

    while(i < max){

        //N = N + (rand() % 2000);
        N = 1000;

        vet_N[i] = N;

        //start = clock();
        srand(i);

        int A[N];

        for(int i = 0; i < N; i++) {
            A[i] = rand() % (k + 1);
        }

        start = clock();

        mergeSort(A,0,N-1);

        end = clock();

        cout<<"Vettore A n° "<<i<<": ";
        for(int k = 0; k < N; k++) {
            cout<<A[k]<<"|";
        }
        cout<<endl;

        tempo = ((double) (end - start))/(CLOCKS_PER_SEC);

        vet_tempo[i] = tempo;

        i++;
    }

    cout<<""<<endl;
    cout<<"Tempo(sec)   -     DIM"<<endl;
    for(int j=0; j < max; j++){
        cout<<vet_tempo[j]<<"           "<<vet_N[j]<<"     "<<j<<"°"<<endl;
    }

    return 0;
}

void mergeSort(int* A, int p, int r) {
    int q;
    q = trunc((p+r)/2);
    if(p < r) {
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
    }
    merge(A,p,q,r);
}

void merge(int* A, int p, int q, int r) {
    //definisco le dimensioni dei due array
    int n1 = q - p + 1;
    int n2 = r - q;
    int inf = 65000; //elemento maggiore di qualunque elemento della sequenza
    int j, i;

    //creo gli array
    int L[n1+1];
    int R[n2+1];

    cout<<endl;
    //Riempio il vettore L
    for(i = 1; i <= n1; i++) {
        L[i] = A[p+i-1];
    }
    L[n1+1] = inf;

    cout<<endl;
    //Riempio il vettore R
    for(j = 1; j <= n2; j++){
        R[j] = A[q+j];
    }
    R[n2+1] = inf;

    i = 1;
    j = 1;
    for(int k = p; k <= r; k++) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}
