#include<stdio.h>
#include<math.h>

double MyPower(double base, int exponent){
    //The power function
    double x=1, y=0;
    int i;
    //Gets correct values
    if(exponent < -5 || exponent>15){
        return y;
    }
    else{
        //Deals with negative exponent
        if(exponent<0){
            exponent *= -1;
            for(i=1; i<=exponent; i++){
                x *= base;
                y = 1/x;
            }
            return y;
        }
        //Deals with positive exponent
        else if(exponent>0){
            for(i=1; i<=exponent; i++){
                x *= base;
            }
            return x;
        }
        //Deals with exponent = 0
        else{
            return x;
        }
    }
}

int TestIsEqual(double result, double expected){
    //Tests to see if result and expected are the same
    if(result == expected){
        printf("Success: %lf == %lf\n", expected, result);
    }
    else{
        printf("Error: expected %lf, but got %lf\n", expected, result);
    }
    return 0;
}

void DoTest(double base, int exponent){
    //Tests the pow and mypower function and sends results to TestIsEqual
    double test1=0, test2=0;
    test1=pow(base, exponent);
    test2=MyPower(base, exponent);

    printf("Testing %lf ^ %d\n", base, exponent);
    TestIsEqual(test2, test1);
}

int main(void){
    //JimR's main function
    DoTest(-20, 11);
    DoTest(2.0d, 3);
    DoTest(-6, -1);
    DoTest(1.0d, 0);
    DoTest(4, 0);
    DoTest(-1, 3);
    DoTest(-2, -7);
    DoTest(-20, -1);
    DoTest(-5, -11);
    DoTest(4.5, 3);
    DoTest(4.5, -3);
    DoTest(-1, 11);
    DoTest(1, -11);
}
