#include<stdio.h>

int main(void){
    //Declare and instantiate my variables
    int one=0, two=0;
    int i = 1;
    int a=0, b=0, ab=0, not_ab=0;

    //Sentinel controlled for loop bc while loop not allowed...
    for(;i>0;){
        printf("Enter in two integers between 1-7 separated by a space\n");
        scanf("%d %d", &one, &two);
        //Excessive switch statement bc if statements not allowed...
        switch(one){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                switch(two){
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                        i=0;
                        break;
                    default:
                        printf("Error: 2nd number not between 1-7\n");
                }
                break;
            default:
                printf("Error: 1st number not between 1-7\n");

        }
    }

    //Loop that starts the test process
    for(int num=4; num<41; num+=2){
        //declare and instantiate my test variables
        int final_one=num%one;
        int final_two=num%two;

        //Tests to see if it is divisible or not and prints out the correct statement
        switch(final_one){
            case 0:
                printf("%d is divisible by %d\n", num, one);
                //Bonus
                a++;
                switch(final_two){
                    case 0:
                        ab++;
                        break;
                    default:
                        break;
                }
                break;
            default:
                printf("%d is not divisible by %d\n", num, one);
                //Bonus
                switch(final_two){
                    case 0:
                        break;
                    default:
                        not_ab++;
                        break;
                }
                break;
        }
        switch(final_two){
            case 0:
                printf("%d is divisible by %d\n", num, two);
                //Bonus
                b++;
                break;
            default:
                printf("%d is not divisible by %d\n", num, two);
                break;

        }
    }

    //Prints the bonus material
    printf("Bonus:\n%d were divisible by only A", a);
    printf("\n%d were divisible by only b", b);
    printf("\n%d were divisible by both A and B", ab);
    printf("\n%d were divisible by neither A or B\n", not_ab);

}
