/***
 *											My application =)
 *                                                                                                                                                                                                                                                                                                   
 *    8 8888888888       ,o888888o.     8 888888888o. 8888888 8888888888   .8.            d888888o.                      .8.          8 888888888o   8 888888888o.      8 8888888888   8 8888         8 888888888o.                 8 8888       .8.          8 8888          8 8888 8 8888         
 *    8 8888          . 8888     `88.   8 8888    `88.      8 8888        .888.         .`8888:' `88.                   .888.         8 8888    `88. 8 8888    `^888.   8 8888         8 8888         8 8888    `^888.              8 8888      .888.         8 8888          8 8888 8 8888         
 *    8 8888         ,8 8888       `8b  8 8888     `88      8 8888       :88888.        8.`8888.   Y8                  :88888.        8 8888     `88 8 8888        `88. 8 8888         8 8888         8 8888        `88.            8 8888     :88888.        8 8888          8 8888 8 8888         
 *    8 8888         88 8888        `8b 8 8888     ,88      8 8888      . `88888.       `8.`8888.                     . `88888.       8 8888     ,88 8 8888         `88 8 8888         8 8888         8 8888         `88            8 8888    . `88888.       8 8888          8 8888 8 8888         
 *    8 888888888888 88 8888         88 8 8888.   ,88'      8 8888     .8. `88888.       `8.`8888.                   .8. `88888.      8 8888.   ,88' 8 8888          88 8 888888888888 8 8888         8 8888          88            8 8888   .8. `88888.      8 8888          8 8888 8 8888         
 *    8 8888         88 8888         88 8 888888888P'       8 8888    .8`8. `88888.       `8.`8888.                 .8`8. `88888.     8 8888888888   8 8888          88 8 8888         8 8888         8 8888          88            8 8888  .8`8. `88888.     8 8888          8 8888 8 8888         
 *    8 8888         88 8888        ,8P 8 8888`8b           8 8888   .8' `8. `88888.       `8.`8888.               .8' `8. `88888.    8 8888    `88. 8 8888         ,88 8 8888         8 8888         8 8888         ,88 88.        8 8888 .8' `8. `88888.    8 8888          8 8888 8 8888         
 *    8 8888         `8 8888       ,8P  8 8888 `8b.         8 8888  .8'   `8. `88888.  8b   `8.`8888.             .8'   `8. `88888.   8 8888      88 8 8888        ,88' 8 8888         8 8888         8 8888        ,88' `88.       8 888'.8'   `8. `88888.   8 8888          8 8888 8 8888         
 *    8 8888          ` 8888     ,88'   8 8888   `8b.       8 8888 .888888888. `88888. `8b.  ;8.`8888            .888888888. `88888.  8 8888    ,88' 8 8888    ,o88P'   8 8888         8 8888         8 8888    ,o88P'     `88o.    8 88'.888888888. `88888.  8 8888          8 8888 8 8888         
 *    8 8888             `8888888P'     8 8888     `88.     8 8888.8'       `8. `88888. `Y8888P ,88P'           .8'       `8. `88888. 8 888888888P   8 888888888P'      8 888888888888 8 888888888888 8 888888888P'          `Y888888 ' .8'       `8. `88888. 8 888888888888  8 8888 8 888888888888 
 */


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int calcul1(int n){
static int call1=0;
call1++;

    if(n==0) 
    return 1;
    else 
    return 2*calcul1(n-1);
    
}

int calcul2(int n){   
    if(n==0)
		return 1;
    else return (calcul2(n-1)+calcul2(n-1));
	
}


main(){
double start;
double end;
double time_taken;
int n;
int ans;
int cl1;
int cl2;

//Dealing with file
FILE *log1;
FILE *log2;
FILE *htmlPage; 
log1 = fopen("mylog1.txt","w");
log2 = fopen("mylog2.txt","w");
htmlPage = fopen("LikeABossLog.html","w");
fprintf(htmlPage,"<!DOCTYPE html> \n<html> \n<head></head> \n<body> \n<table border=\"2\" width=\"100%\" bordercolor=\"green\">\n <table>\n    <tr>\n    \n<th>N value </th>\n    <th>Temps(s)</th>\n    </tr> ");
do{

    printf("Donner n: ");
    scanf("%d",&n);
    
    //Calcul1 Starts :
    start = clock();
    cl1= calcul1(n);
    end = (double) clock();
    time_taken=(double)((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n1-Le resultat est= %d with %f second",cl1,time_taken);
	fprintf(log1,"%d\t%f \n",n,time_taken);
	fprintf(htmlPage,"<tr>\n<td><center>%d</center></td>\n<td>%f</td>\n</tr>",n,time_taken);
    //Calcul1 Ends </>
    
    //Calcul1 Starts :
    start = clock();
    cl2= calcul2(n);
    end = (double) clock();
    time_taken=(double)((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n2-Le resultat est= %d with %f second",cl2,time_taken); //Add raw to table
	fprintf(log2,"%d\t%f \n",n,time_taken); 

    //Calcul1 Ends </>
    printf("\n\n\nType 0 to exit");
    scanf("%d",&ans);
}
    while(ans!=0);
	fprintf(htmlPage,"   </table>\n</td>\n</tr>\n</table>\n</body>\n</html>"); //Html page footer
	system("firefox LikeABossLog.html "); //Open the table in Firefox
}
