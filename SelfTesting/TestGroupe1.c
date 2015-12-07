#include<stdio.h>
#include<stdlib.h>
typedef struct indice{int i;int j};

void lire(int **M,int n,int m){
    int i,j;

    for(j=0;j<m;j++){
        //Lecture du tableau
        for(i=0;i<n;i++){
            printf("Donner T[%d][%d]",i,j);
            scanf("%d",&M[i][j]);
            }
        }
}

struct indice indice_min(int **T,int n,int m,int the_i,int the_j){
    int i,j;
    struct indice min;

    //Inistially = 0,0;
      min.i = the_i;
      min.j = the_j;

    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            if(T[min.i][min.j]>T[i][j]){
                min.i=i;
                min.j=j;
            }
        }
        }
    return min;
    }


void Permuter(int *a,int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void tri(int **T,int n,int m){
    int i,j;
    struct indice the_min;
    struct indice k;
        for(i=0;i<n-1;i++){
            for(j=0;j<m-1;i++){
            the_min=indice_min(T,n,m,i,j);
            k.i = the_min.i;
            k.j = the_min.j; //int **T,int n,int m,int the_i,int the_j
            if((k.i!=i)&&(k.j!=j))
            Permuter(&T[k.i][k.j],&T[i][j]);
        }
        }
};


void main(){
int n,m;
int M[n][m];
int i,j;

lire(M,n,m);

tri(M,n,m);
}
