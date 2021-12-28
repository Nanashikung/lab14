#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum,sumsd,sumg=1,sumh;
    for(int i=0;i<N;i++){
        sum += A[i];
        sumsd += pow(A[i],2);
        sumg *= A[i];
        sumh += 1/A[i];
    }

    B[0] = sum/N;
    B[1] = sqrt((sumsd/N)-pow(sum/N,2));
    B[2] = pow(sumg,(1.0/N));
    B[3] = N/sumh;
    B[5] = A[0];
    for(int i=0;i<N;i++){
        if (A[i] > B[4]) B[4] = A[i];
        if (A[i] < B[5]) B[5] = A[i];
    }

}