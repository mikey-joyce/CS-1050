#include<stdio.h>
#include<math.h>

double MyPower(double base, int exponent){
    double x=1;
    int i;
    for(i=1; i<=exponent; i++){
        x *= base;
    }
    return x;
}

void DoTest(double base, int exponent){
    printf("Testing %f to the power of %d\n", base, exponent);
    double test1, test2;
    test1 = pow(base, exponent);
    test2 = MyPower(base, exponent);
    if(test1!=test2){
        printf("Error: Expected %f but got %f\n", test1, test2);
    }
}

int main(void){
    int i, j;

    for(i=1; i<5; i++){
        for(j=1; j<5; j++){
            DoTest(i, j);
        }
    }
}
