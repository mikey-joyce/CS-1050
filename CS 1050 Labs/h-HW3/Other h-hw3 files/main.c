#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Random.h"
#include "DandDCharacter.h"

void Menu(void);

int main(int argc, char *argv[])
{
    Character * pCharacter;
    pCharacter = (Character*)malloc(sizeof(Character));

    if(argc > 1)
    {
        LoadCharacter(pCharacter, argv[1]);
        Menu();
    }
    else
    {
        Menu();
    }
    free(pCharacter);
    return 0;
}

void Menu(void)
{
    Character * pCharacter;
    int x, selection, i;
    char filename[256];

    pCharacter = (Character*)malloc(sizeof(Character));
    pCharacter->charname[0] = '\0';
    pCharacter->playername[0] = '\0';
    pCharacter->strength = 0;
    pCharacter->dexterity = 0;
    pCharacter->constitution = 0;
    pCharacter->intelligence = 0;
    pCharacter->wisdom = 0;
    pCharacter->charisma = 0;
    pCharacter->ancestry = human;

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
            selection = DisplayMenu();
        }while(selection<1 || selection>5);

    if(selection==1)
    {
        GenerateCharacter(pCharacter);

        x=1;
    }
    if(selection==2)
    {
        SaveCharacter(pCharacter);

        x=1;
    }
    if(selection==3)
    {
        char charext[] = ".character";
        printf("\nEnter name of file to load (extension will automatically be .character): ");
        scanf("%s", filename);
        strcat(filename, charext);
        LoadCharacter(pCharacter, filename);
        x=1;
    }
    if(selection==4)
    {
        DisplayCharacter(pCharacter);

        x=1;
    }
    if(selection==5)
    {
        printf("\n\nThanks for Playing!!\n");
        x=0;
    }

    }while(x==1);
    free(pCharacter);
}
