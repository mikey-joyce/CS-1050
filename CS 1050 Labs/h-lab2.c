#include<stdio.h>

int main(void){
    int a, b, c, temp;

    //User input
    printf("Enter 2 integers separated by a space:\n");
    scanf("%d %d", &a, &b);
    printf("Enter an integer other than 0:\n");
    scanf("%d", &c);
    while(c==0){
        printf("0 in not acceptable! Enter a different integer:\n");
        scanf("%d", &c);
    }

    //Prints all user input values
    printf("A: %d\nB: %d\nC: %d\n", a, b, c);

    //Prints all user input values added together
    temp = a+b+c;
    printf("\nA+B+C= %d", temp);

    //Prints value of a minus b
    temp = a-b;
    printf("\nA-B= %d", temp);

    //Prints value of (a-b)+c
    temp = (a-b)+c;
    printf("\n(A-B)+C= %d", temp);

    //Prints value of (a*b)-c
    temp = (a*b)-c;
    printf("\n(A*B)-C= %d", temp);

    //Prints values of a/c
    temp = a/c;
    printf("\nA/C= %d", temp);

    //Prints value of (a*b)/c
    temp = (a*b)/c;
    printf("\n(A*B)/C= %d", temp);

    //Prints the integer remainder of a/c
    temp = a%c;
    printf("\nA%%C= %d", temp);

    //Bonus smallest absolute value of the 3 integers
    int val_a, val_b, val_c, smallest;
    
    //Finds the absolute value of all 3 integers
    switch(a>=0){
        case 0:
            val_a=a*-1;
            break;
        default:
            val_a=a;
            break;
    }
    switch(b>=0){
        case 0:
            val_b=b*-1;
            break;
        default:
            val_b=b;
            break;
    }
    switch(c>=0){
        case 0:
            val_c=c*-1;
            break;
        default:
            val_c=c;
            break;
    }

    //Finds the smallest
    smallest=val_a;
    if(val_a>val_b && val_c>val_b){
        smallest=val_b;
    }
    if(val_a>val_c && val_b>val_c){
        smallest=val_c;
    }

    //Prints the smallest
    printf("\nSmallest absolute value: %d\n", smallest);
}
