#include<stdio.h>

int main(void){
    //Declare my variables
    int choice, choice2, flag;
    flag = 1;
    choice2 = 0;
    char end_prompt[43]="Enter 0 to quit, anything else to continue";

    //Start the menu
    while(flag!=0){
        do{
            printf("\nSelect an arist with a number:\n1: Bruce Springsteen\n2: Steve Earle\n3: The Clash\n4: The Sex Pistols\n5: P.J. Harvey\n");
            scanf("%d", &choice);
            if(choice<1 || choice>5){
                printf("Error: Choose a number from 1-5");
            }
        }while(choice<1 || choice>5);
        switch(choice){
            case 1:
                //Prompts to the Springsteen album menu
                ;
                float r1=3.0;
                float r2=3.5;
                float r3=4.5;
                float r4=5.0;
                float r5=4.5;
                float r6=5.0;

                do{
                    printf("\nSelect one of Bruce Springsteens albums:\n1: Greetings from Asbury Park\n2: The Wild, the Innocent, and the E-Street Shuffle\n3: Born to Run\n4: Darkness on the Edge of Town\n5: The River\n6: Nebraska\n7: All Albums by Artist\n");
                    scanf("%d", &choice2);
                    if(choice2<1 || choice2>7){
                        printf("Error: Choose a number from 1-7");
                    }
                }while(choice2<1 || choice2>7);
                switch(choice2){
                    case 1:
                        //Prints Bruce 1st album rating
                        printf("\nRating: 3 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 2:
                        //Prints Bruce 2nd album rating
                        printf("\nRating: 3.5 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 3:
                        //Prints Bruce 3rd album rating
                        printf("\nRating: 4.5 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 4:
                        //Prints Bruce 4th album rating
                        printf("\nRating: 5 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 5:
                        //Prints Bruce 5ths album rating
                        printf("\nRating: 4.5 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 6:
                        //Prints Bruce 6th album rating
                        printf("\nRating: 5 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 7:
                        //All albums by artist
                        ;
                        float aaba = (r1+r2+r3+r4+r5+r6)/6;
                        printf("\nOverall Rating: %f\n%s\n", aaba, end_prompt);
                        scanf("%d", &flag);
                        break;

                }
                break;
            case 2:
                //Prompts to the Earle album menu
                ;
                float e1=4.0;
                float e2=5.0;
                float e3=4.5;
                float e4=4.0;

                do{
                    printf("\nSelect one of Steve Earle's albums:\n1: Copperhead Road\n2: I Feel Alright\n3: El Corazon\n4: Transcendental Blues\n5: All Albums by Artist\n");
                    scanf("%d", &choice2);
                    if(choice2<1 || choice2>5){
                        printf("Error: Choose a number from 1 to 5");
                    }
                }while(choice2<1 || choice2>5);
                switch(choice2){
                    case 1:
                        //Prints Earle 1st album rating
                        printf("\nRating: 4 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 2:
                        //Prints Earle 2nd album rating
                        printf("\nRating: 5 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 3:
                        //Prints Earle 3rd album rating
                        printf("\nRating: 4.5 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 4:
                        //Prints Earle 4th album rating
                        printf("\nRating: 4 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 5:
                        ;
                        float aaba=(e1+e2+e3+e4)/4;
                        printf("\nOverall Rating: %f\n%s\n", aaba, end_prompt);
                        scanf("%d", &flag);
                        break;
                }
                break;
            case 3:
                //Prompts to the Clash album menu
                ;
                float c1=5.0;
                float c2=5.0;
                float c3=4.0;
                float c4=3.5;

                do{
                    printf("\nSelect one of the Clash's albums:\n1: The Clash\n2: London Calling\n3: Sandinista\n4: Combat Rock\n5: All Albums by Artist\n");
                    scanf("%d", &choice2);
                    if (choice2<1 || choice2>5){
                        printf("Error: Choose a number between 1 and 5");
                    }
                }while(choice2<1 || choice2>5);
                switch(choice2){
                    case 1:
                        //Clash album 1 rating
                        printf("\nRating: 5 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 2:
                        //Clash album 2 rating
                        printf("\nRating: 5 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 3:
                        //Clash album 3 rating
                        printf("\nRating: 4 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 4:
                        //Clash album 4 rating
                        printf("\nRating: 3.5 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 5:
                        ;
                        float aaba = (c1+c2+c3+c4)/4;
                        printf("\nOverall Rating: %f\n%s\n", aaba, end_prompt);
                        scanf("%d", &flag);
                        break;
                }
                break;
            case 4:
                //Prompts to the Pistols album menu
                do {
                    printf("\nSelect one of The Sex Pistols albums:\n1: Never Minds the Bollocks, Here's The Sex Pistols\n2: All Albums by Artist");
                    scanf("%d", &choice2);
                    if(choice2!=1 || choice2!=2){
                        printf("Error: Enter a number from 1 to 2");
                    }
                } while(choice2 != 1 || choice2 != 2);
                switch(choice2){
                    case 1:
                        //Print pistols 1st album rating
                        printf("\nRating: 5 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 2:
                        //Print pistols 1st album rating
                        printf("\nRating: 5 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                }
                break;
            case 5:
                //Prompts to the Harvey album menu
                ;
                float h1=3.0;
                float h2=3.0;
                float h3=5.0;

                do{
                    printf("\nSelect one of P.J. Harvey's albums:\n1: Dry\n2: Rid of Me\n3: Stories from the City, Stories from the Sea\n4: All Albums by Artist\n");
                    scanf("%d", &choice2);
                    if(choice2<1 || choice2>4){
                        printf("Error: Enter a number from 1 to 4");
                    }
                }while(choice2<1 || choice2>4);
                switch(choice2){
                    case 1:
                        //Print harvey 1st album rating
                        printf("\nRating: 3 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 2:
                        //Harvey 2nd album rating
                        printf("\nRating: 3 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 3:
                        //Harvey 3rd album rating
                        printf("\nRating: 5 Stars\n%s\n", end_prompt);
                        scanf("%d", &flag);
                        break;
                    case 4:
                        ;
                        float aaba=(h1+h2+h3)/3;
                        printf("\nOverall Rating: %f\n%s\n", aaba, end_prompt);
                        scanf("%d", &flag);
                        break;
                }
                break;
        }
    }
    return 0;
}
