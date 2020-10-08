#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Random.h"
#include "DandDCharacter.h"

void mainMenu(void);

int main(int arg1, char *arg2[])
{
    //tries to deal with the command line load but doesnt seem to work
    Character * rpgCharacter;
    rpgCharacter = (Character*)malloc(sizeof(Character));

    if(arg1 > 1)
    {
        LoadCharacter(rpgCharacter, arg2[1]);
        mainMenu();
    }
    else
    {
        mainMenu();
    }
    free(rpgCharacter);
    return 0;
}

void mainMenu(void)
{
    //Declare my variables
    Character * rpgCharacter;
    int i, flag, choice;
    char fileName[256];

    //Set everything to 0 for my dummy data
    rpgCharacter = (Character*)malloc(sizeof(Character));
    rpgCharacter->charname[0] = '\0';
    rpgCharacter->playername[0] = '\0';
    rpgCharacter->strength = 0;
    rpgCharacter->dexterity = 0;
    rpgCharacter->constitution = 0;
    rpgCharacter->intelligence = 0;
    rpgCharacter->wisdom = 0;
    rpgCharacter->charisma = 0;
    rpgCharacter->ancestry = human;

    //Menu operator
    do{
        do{
            printf("Main Menu\n");
            printf("---------\n");
            printf("\n1) Generate a New Character\n");
            printf("2) Save Current Character\n");
            printf("3) Load a Previously Saved Character\n");
            printf("4) Display Current Character\n");
            printf("5) Exit\n");
            printf("\nEnter a selection: ");
            choice = DisplayMenu();
        }while(choice<1 || choice>5);

    //Could've opted for the switch but decided to use if statements
    if(choice==1)
    {
        GenerateCharacter(rpgCharacter);

        flag=1;
    }
    if(choice==2)
    {
        SaveCharacter(rpgCharacter);

        flag=1;
    }
    if(choice==3)
    {
        char charext[] = ".character";
        printf("\nEnter name of file to load (extension will automatically be .character): ");
        scanf("%s", fileName);
        strcat(fileName, charext);
        LoadCharacter(rpgCharacter, fileName);
        flag=1;
    }
    if(choice==4)
    {
        DisplayCharacter(rpgCharacter);

        flag=1;
    }
    if(choice==5)
    {
        printf("\n\nThanks for Playing!!\n");
        flag=0;
    }

  }while(flag==1);
    free(rpgCharacter);
}
