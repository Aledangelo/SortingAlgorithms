#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Partition(int*,int,int);
void swap(int*,int,int);
void QuickSort(int*,int,int);

int main() {
    clock_t start, end;
    double timer;

    srand(time(NULL));

    //int N = 1 + rand() % 10001;
    int N = 1000000;
    int k = 1000;
    int vet[N];
    int i;


    cout<<"Vettore A:           ";
    for(i = 1; i<=N; i++){
        vet[i] = rand() % (k + 1);
        cout<<vet[i]<<"|";
    }

    cout<<endl;

    start = clock();
    QuickSort(vet,1,N);
    end = clock();

    timer = ((double) (end-start))/CLOCKS_PER_SEC;

    cout<<"VETTORE ORDINATO:    ";
    for(i = 1; i<=N; i++){
        cout<<vet[i]<<"|";
    }
    cout<<endl;
    cout<<"T(n):                "<<timer<<endl;
    cout<<"DIM:                 "<<N<<endl;

    return 0;
}


int Partition(int* A, int p, int r){
    int pivot = A[r];
    int i = p-1;

    int j;

    for(j = p; j < r; j++){
        if(A[j] <= pivot) {
            i++;
            swap(A, i, j);
        }
    }

    swap(A,i+1,r);
    return i+1;
}

void QuickSort(int* A, int p, int r){
    if(p<r){
        int indice = Partition(A,p,r);
        QuickSort(A,p,indice-1);
        QuickSort(A,indice+1,r);
    }
}
void swap(int* A, int p, int r) {
    int temp;
    temp = A[p];
    A[p] = A[r];
    A[r] = temp;
}
