#include<stdio.h>

int main(void){
    int constant=5;

    for(int num=1; num<31; num++){
        int test = num%constant;
        switch(test){
            case 0:
                //Deals with if the number % const = 0
                printf("%d is divisible by %d\n", num, constant);
                break;
            default:
                //Deals with if the num % const != 0
                printf("%d is not divisible by %d\n", num, constant);
                break;
        }
    }
}
