#include "DandDCharacter.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int RollTop3()
{
    int Roll1 = RollD6();
    int Roll2 = RollD6();
    int Roll3 = RollD6();
    int Roll4 = RollD6();
    int first=0;
    int second=0;
    int third=0;
    int total=0;
    int largest[4] = {Roll1, Roll2, Roll3, Roll4};
    int i;
    for(i=0; i<4; i++)
    {
        if(largest[i] > first)
        {
            third = second;
            second = first;
            first = largest[i];
        }
        else if(largest[i] > second)
        {
            third = second;
            second = largest[i];
        }
        else if(largest[i] > third)
        {
            third = largest[i];
        }
    }
        total = first + second + third;
        return total;
}

void GenerateCharacter(Character * pCharacter)
{
    int x;
    printf("\nSelect an ancestry from this list:\n");
    printf("0) human\n");
    printf("1) elf\n");
    printf("2) halfling\n");
    printf("3) dwarf\n");
    printf("4) half_elf\n");
    printf("5) half_orc\n");
    do{
    scanf("%d", &x);
    switch(x){
        case 0:
        pCharacter->ancestry = human;
        break;
        case 1:
        pCharacter->ancestry = elf;
        break;
        case 2:
        pCharacter->ancestry = halfling;
        break;
        case 3:
        pCharacter->ancestry = dwarf;
        break;
        case 4:
        pCharacter->ancestry = half_elf;
        break;
        case 5:
        pCharacter->ancestry = half_orc;
        break;
        default:
        printf("Please enter a selection between 0-5\n");
        break;
    }
    }while(x<0 || x>5);

    printf("Please Enter Your Character's Name (no spaces): ");
    scanf("%s", pCharacter->charname);
    printf("Please Enter Your Name (no spaces): ");
    scanf("%s", pCharacter->playername);

    SetSeed(-1);
    pCharacter->strength = RollTop3();
    pCharacter->dexterity = RollTop3();
    pCharacter->constitution = RollTop3();
    pCharacter->intelligence = RollTop3();
    pCharacter->wisdom = RollTop3();
    pCharacter->charisma = RollTop3();
}

void DisplayCharacter(Character * pCharacter)
{
    static char *ancestry[60] = {"human", "elf", "halfling", "dwarf", "half_elf", "half_orc"};
    printf("\n*************************\n");
    printf("*                      %s *\n", pCharacter->charname);
    printf("* By                   %s *\n", pCharacter->playername);
    printf("*************************\n");
    printf("* Strength:           %d *\n", pCharacter->strength);
    printf("* Dexterity:          %d *\n", pCharacter->dexterity);
    printf("* Constitution:       %d *\n", pCharacter->constitution);
    printf("* Intelligence:       %d *\n", pCharacter->intelligence);
    printf("* Wisdom:             %d *\n", pCharacter->wisdom);
    printf("* Charisma:           %d *\n", pCharacter->charisma);
    printf("* Ancestry:       %s *\n", ancestry[pCharacter->ancestry]);
    printf("*************************\n\n\n");
}

void SaveCharacter(Character * pCharacter)
{
    FILE * fp = NULL;
    char charext[] = ".character";
    char filename[256];
    static char *ancestry[60] = {"human", "elf", "halfling", "dwarf", "half_elf", "half_orc"};
    
    printf("\nEnter name of file to save (extension will automatically be .character): ");
    scanf("%s", filename);  //Gets the filename from the user
    strcat(filename,charext);
    fp = fopen(filename, "w"); //opens the file

    /*Input vlaues to the file with stats/names*/
    fprintf(fp, "%s", pCharacter->charname); 
    fprintf(fp, " %s", pCharacter->playername);
    fprintf(fp, " %d", pCharacter->strength);
    fprintf(fp, " %d", pCharacter->dexterity);
    fprintf(fp, " %d", pCharacter->constitution);
    fprintf(fp, " %d", pCharacter->intelligence);
    fprintf(fp, " %d", pCharacter->wisdom);
    fprintf(fp, " %d", pCharacter->charisma);
    fprintf(fp, " %s", ancestry[pCharacter->ancestry]);
    fprintf(fp, " %d", pCharacter->ancestry);


    fclose(fp);
}

void LoadCharacter(Character * pCharacter, char * filename)
{
    FILE * fp = fopen(filename, "r");
    int strength[3], dexterity[3], constitution[3], intelligence[3], wisdom[3], charisma[3],  ancestry[20], ancestryy[2];
    printf("file is open, filename = %s\n", filename);

    if(fp == NULL)
    {
        printf("There is nothing in this file.\n");
    }
    else
    {
        fscanf(fp, "%s", pCharacter->charname);
        fscanf(fp, " %s", pCharacter->playername);
        fscanf(fp, " %s", strength);
        pCharacter->strength = atoi(strength);
        fscanf(fp, " %s", dexterity);
        pCharacter->dexterity = atoi(dexterity);
        fscanf(fp, " %s", constitution);
        pCharacter->constitution = atoi(constitution);
        fscanf(fp, " %s", intelligence);
        pCharacter->intelligence = atoi(constitution);
        fscanf(fp, " %s", wisdom);
        pCharacter->wisdom = atoi(wisdom);
        fscanf(fp, " %s", charisma);
        pCharacter->charisma = atoi(charisma);
        fscanf(fp, " %s", ancestry);
        fscanf(fp, " %s", ancestryy);
        pCharacter->ancestry = atoi(ancestryy);

    }
        fclose(fp);
}

int DisplayMenu()
{
    int selection;

    scanf("%d", &selection);
    if(selection<1 || selection>5)
    {
        printf("*** Error: selection must be 1-5 ***\n");
    }

    return selection;
}
