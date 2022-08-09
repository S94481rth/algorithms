#include<stdio.h>
#define n 4
void findEchelon(float arr[][n]){
    for(int i=0;i<n-1;i++){
        for(int k=i;k<n-1;k++){
            float z = (arr[k+1][i]/arr[i][i]);
            for(int j=i;j<n;j++){
                arr[k+1][j] = arr[k+1][j] - z*arr[i][j];
            }
        }
    }
    return;
}

void printMatrix(float arr[][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%f ",arr[i][j]);   
        }printf("\n");
    }
}

int main(){

    printf("Enter matrix : ");
    float arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%f",&arr[i][j]);
        }
    }
    printf("Inital Matrix : \n");
    printMatrix(arr);
    findEchelon(arr);
    printf("Echelon form : \n");
    printMatrix(arr);
    return 0;
}


/*
Input : 
1 -1 -2 -4
2 3 -1 -1
3 1 3 -2
6 3 0 -7

Output : 
Inital Matrix : 
1.000000 -1.000000 -2.000000 -4.000000 
2.000000 3.000000 -1.000000 -1.000000 
3.000000 1.000000 3.000000 -2.000000 
6.000000 3.000000 0.000000 -7.000000 
Echelon form : 
1.000000 -1.000000 -2.000000 -4.000000 
0.000000 5.000000 3.000000 7.000000 
0.000000 0.000000 6.600000 4.400000 
0.000000 0.000000 -0.000000 0.000000 

Input 2 :
1 2 3 
1 5 2 
1 8 1

Output 2:
Inital Matrix : 
1.000000 2.000000 3.000000 
1.000000 5.000000 2.000000 
1.000000 8.000000 1.000000 
Echelon form : 
1.000000 2.000000 3.000000 
0.000000 3.000000 -1.000000 
0.000000 0.000000 0.000000
*/
