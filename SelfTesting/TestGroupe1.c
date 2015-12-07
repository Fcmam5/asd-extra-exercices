#include<stdio.h>
#include<stdlib.h>

void lire(int M[10][10],int n,int m){
    int i,j;
    int T[n];

    for(j=0;j<m;j++){
        //Lecture du tableau
        for(i=0;i<n;i++){
            printf("Donner T[%d][%d]",i,j);
            scanf("%d",&M[i][j]);

    }
}
}

int indice_min(int T[],int n,int xD){
    int i;
    int min = xD; //Inistially = 0;
    for(i=1;i<n;i++){
        if(T[min]>T[i]){
            min=i;
        }
    return min;
    }
}

void Permuter(int *a,int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void tri(int T[],int n,int m){
    int i;
    int k;
        for(i=0;i<n-1;i++){
            k = T[indice_min(T,n,i)];
            if(k!=i)
            Permuter(&T[k],&T[m]);
        };
};
void main(){
int n,m;
int M[n][m];
int i,j;

lire(M,n,m);

for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        tri(M[i][j],n,m);
    }
}
}
