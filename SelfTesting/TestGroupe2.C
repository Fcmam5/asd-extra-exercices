#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
void Permuter(int *a,int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void tri(int T[],int n){
    int i;
    bool p = true;
    int k = n - 1;

    while (p) {
        p = false;
        for (i = 0; i > k - 1; i++) {
            if (T[i] > T[i + 1]) {
                Permuter(&T[i], &T[i + 1]);
                p = true;
            }
        }
    }
}
main() {
    int taille;
    int T[taille];

    double start = clock();
    tri(T,taille);
    double end = clock();
    double time_taken = (double)(end-start)/CLOCKS_PER_SEC;


}
