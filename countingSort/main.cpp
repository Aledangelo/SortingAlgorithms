#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;
int N;

void CountingSort(int *, int *, int);

int main() {

    clock_t start, end;
    double timer = 0;

    srand(time(NULL));
    //N = 1 + rand() % 10001;
    N = 1000000;

    int vet[N];

    int i;
    int k = 1000;

    cout<<"VETTORE A:           ";
    for(i = 1; i <= N; i++){
        vet[i] = rand() % (k + 1);
        cout<<vet[i]<<"|";
    }

    int B[N];
    start = clock();
    CountingSort(vet,B,k);
    end = clock();

    timer = ((double)(end-start))/CLOCKS_PER_SEC;

    cout<<endl;

    cout<<"VETTORE A ORDINATO:  ";
    for(i = 1; i<=N; i++){
        cout<<B[i]<<"|";
    }
    cout<<endl;
    cout<<"T(n):                "<<timer<<endl;
    cout<<"DIM:                 "<<N<<endl;
    return 0;
}


void CountingSort(int *vet, int *B, int m) {
    int i;
    int C[m+1];

    for(i = 0; i <= m; i++){
        C[i] = 0;
    }

    for(i = 1; i <= N; i++) {
        C[vet[i]] = C[vet[i]] + 1;
    }

    for(i = 1; i <= m; i++){
        C[i] = C[i] + C[i-1];
    }

    for(i = N; i>0; i--) {
        B[C[vet[i]]] = vet[i];
        C[vet[i]] = C[vet[i]] - 1;
    }

}
