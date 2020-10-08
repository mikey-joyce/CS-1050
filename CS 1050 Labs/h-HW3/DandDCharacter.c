#include "DandDCharacter.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//Prototypes
int rollAvg();
void GenerateCharacter(Character * pCharacter);
void DisplayCharacter(Character * pCharacter);
void SaveCharacter(Character * pCharacter);
void LoadCharacter(Character * pCharacter, char * fileName);
int DisplayMenu();

int rollAvg()
{
    //Adds together the top 3 rolls of the dice
    int firstRoll = RollD6();
    int secondRoll = RollD6();
    int thirdRoll = RollD6();
    int fourthRoll = RollD6();
    int one=0,two=0,three=0,final=0;
    int rolls[4] = {firstRoll, secondRoll, thirdRoll, fourthRoll};
    int i;
    for(i=0; i<4; i++)
    {
        if(rolls[i] > one)
        {
            three= two;
            two= one;
            one= rolls[i];
        }
        else if(rolls[i] > two)
        {
            three = two;
            two = rolls[i];
        }
        else if(rolls[i] > three)
        {
            three = rolls[i];
        }
    }
        final = one + two + three;

        return final;
}

void GenerateCharacter(Character * pCharacter)
{
    //Generates a new character
    int choice;
    //Menu item for ancestry
    printf("\nSelect an ancestry from this list:\n");
    printf("0) human\n");
    printf("1) elf\n");
    printf("2) halfling\n");
    printf("3) dwarf\n");
    printf("4) half_elf\n");
    printf("5) half_orc\n");
    do{
    scanf("%d", &choice);
    switch(choice){
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
  }while(choice<0 || choice>5);

    //Decides character and player names
    printf("Please Enter Your Character's Name (no spaces): ");
    scanf("%s", pCharacter->charname);
    printf("Please Enter Your Name (no spaces): ");
    scanf("%s", pCharacter->playername);

    //Have to set seed for rollAvg to work properly
    SetSeed(-1);
    pCharacter->strength = rollAvg();
    pCharacter->dexterity = rollAvg();
    pCharacter->constitution = rollAvg();
    pCharacter->intelligence = rollAvg();
    pCharacter->wisdom = rollAvg();
    pCharacter->charisma = rollAvg();
}

void DisplayCharacter(Character * pCharacter)
{
    //Displays the character the way JimR had it.
    static char *ancestry[60] = {"human", "elf", "halfling", "dwarf", "half_elf", "half_orc"};
    printf("\n*************************\n");
    printf("*                      %s *\n", pCharacter->charname);
    printf("* By                   %s *\n", pCharacter->playername);
    printf("-------------------------\n");
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
    //Declare my variables for the files
    FILE * rpgFile = NULL;
    char fileType[] = ".character";
    char fileName[256];
    static char *ancestry[60] = {"human", "elf", "halfling", "dwarf", "half_elf", "half_orc"};

    //Retreives the file name
    printf("\nEnter name of file to save (extension will automatically be .character): ");
    scanf("%s", fileName);
    strcat(fileName,fileType);
    //Open file
    rpgFile = fopen(fileName, "w");

    //Saves the structure elements to the file
    fprintf(rpgFile, "%s", pCharacter->charname);
    fprintf(rpgFile, " %s", pCharacter->playername);
    fprintf(rpgFile, " %d", pCharacter->strength);
    fprintf(rpgFile, " %d", pCharacter->dexterity);
    fprintf(rpgFile, " %d", pCharacter->constitution);
    fprintf(rpgFile, " %d", pCharacter->intelligence);
    fprintf(rpgFile, " %d", pCharacter->wisdom);
    fprintf(rpgFile, " %d", pCharacter->charisma);
    fprintf(rpgFile, " %s", ancestry[pCharacter->ancestry]);
    fprintf(rpgFile, " %d", pCharacter->ancestry);

    //Closes file
    fclose(rpgFile);
}

void LoadCharacter(Character * pCharacter, char * fileName)
{
    //Load the file
    FILE * loadFile = fopen(fileName, "r");
    int strength[3], dexterity[3], constitution[3], intelligence[3], wisdom[3], charisma[3],  ancestry[20], ancestryy[2];
    printf("file is open, filename = %s\n", fileName);

    if(loadFile == NULL)
    {
        printf("There is nothing in this file.\n");
    }
    else
    {
        fscanf(loadFile, "%s", pCharacter->charname);
        fscanf(loadFile, " %s", pCharacter->playername);
        fscanf(loadFile, " %s", strength);
        pCharacter->strength = atoi(strength);
        fscanf(loadFile, " %s", dexterity);
        pCharacter->dexterity = atoi(dexterity);
        fscanf(loadFile, " %s", constitution);
        pCharacter->constitution = atoi(constitution);
        fscanf(loadFile, " %s", intelligence);
        pCharacter->intelligence = atoi(constitution);
        fscanf(loadFile, " %s", wisdom);
        pCharacter->wisdom = atoi(wisdom);
        fscanf(loadFile, " %s", charisma);
        pCharacter->charisma = atoi(charisma);
        fscanf(loadFile, " %s", ancestry);
        fscanf(loadFile, " %s", ancestryy);
        pCharacter->ancestry = atoi(ancestryy);

    }
        fclose(loadFile);
}

int DisplayMenu()
{
    int choice;

    scanf("%d", &choice);
    if(choice<1 || choice>5)
    {
        printf("*** Error: choice must be 1-5 ***\n");
    }

    return choice;
}
