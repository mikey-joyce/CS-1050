#include <stdio.h>
#include <malloc.h>

struct _Player
{
    char LastName[16];
    char FirstName[16];
    char Team[16];
    int Year;
    float BA;
    float OBP;
    float SLUG;
};

typedef struct _Player Player;

//Prototypes
void printPlayers(Player players[], int count, int filterYear);
void sortBattingAvg(Player players[], int count);
void sortOBP(Player players[], int count);
void sortSlug(Player players[], int count);
//void loadPlayer(Player players[], int count, char *fileName);

void printPlayers(Player players[], int count, int filterYear){
  printf("\tLast Name       First Name      Team        Year   BA       OBP    SLUG\n");
  for (int i=0;i<count;i++)
  {
      if(players[i].Year==filterYear){
        continue;
      }
      else{
        printf("%16s %16s %16s %5d %6f %6f %6f\n",
                players[i].FirstName,
                players[i].LastName,
                players[i].Team,
                players[i].Year,
                players[i].BA,
                players[i].OBP,
                players[i].SLUG);
      }
  }
}

void sortBattingAvg(Player players[], int count){
  for (int pass=1;pass<count;pass++)
  {
      for (int j=0;j<count-1;j++)
      {
          Player temp;
          if (players[j].BA<players[j+1].BA)
          {
              temp = players[j];
              players[j] = players[j+1];
              players[j+1]=temp;
          }
      }
  }
}

void sortOBP(Player players[], int count){
  for (int pass=1;pass<count;pass++)
  {
      for (int j=0;j<count-1;j++)
      {
          Player temp;
          if (players[j].OBP<players[j+1].OBP)
          {
              temp = players[j];
              players[j] = players[j+1];
              players[j+1]=temp;
          }
      }
  }
}

void sortSlug(Player players[], int count){
  for (int pass=1;pass<count;pass++)
  {
      for (int j=0;j<count-1;j++)
      {
          Player temp;
          if (players[j].SLUG<players[j+1].SLUG)
          {
              temp = players[j];
              players[j] = players[j+1];
              players[j+1]=temp;
          }
      }
  }
}

/*void loadPlayer(Player players[], int count, char *fileName){
  FILE * fp;

  fp = fopen(fileName, "r");
  if (fp){
    // Read everything in
    while (!feof(fp)){
      if (7==fscanf(fp,"%s %s %d %s %f %f %f",
                      players[count].LastName,
                      players[count].FirstName,
                      &(players[count].Year),
                      players[count].Team,
                      &(players[count].BA),
                      &(players[count].OBP),
                      &(players[count].SLUG)
                      )){
            count++;
        }
      }
    fclose(fp);
  }
}*/

void mainMenu(char *fileName){
  int menuChoice = 0, filterChoice=0;
  int flag=1, filterFlag=0;
  Player players[24];
  int count=0;
  FILE * fp;

  fp = fopen(fileName, "r");
  if (fp){
    // Read everything in
    while (!feof(fp)){
      if (7==fscanf(fp,"%s %s %d %s %f %f %f",
                      players[count].LastName,
                      players[count].FirstName,
                      &(players[count].Year),
                      players[count].Team,
                      &(players[count].BA),
                      &(players[count].OBP),
                      &(players[count].SLUG)
                      )){
            count++;
        }
      }
    fclose(fp);
  }

  printPlayers(players, count, 0);
  //Need to do this to get correct players and count due to no global variables
  //loadPlayer(players, count, fileName);

  //Starts the main menu right here
  do{
    do{
      printf("*** Menu ***\n");
      printf("1. Print Player Records\n2. Sort by Batting Average\n3. Sort by On-base Percentage\n4. Sort by Slugging Percentage\n5. Filter by Year\n6. Exit\n");
      scanf("%d", &menuChoice);
    }while(menuChoice<1 || menuChoice>6);
    if(filterFlag!=0){
      printf("Year: %d", filterFlag);
    }
    switch(menuChoice){
      case 1:
        printPlayers(players, count, filterFlag);
        break;
      case 2:
        sortBattingAvg(players, count);
        break;
      case 3:
        sortOBP(players, count);
        break;
      case 4:
        sortSlug(players, count);
        break;
      case 5:
        printf("Select which year: \n1. 2017\n2. 2018\n3. 2019\n");
        scanf("%d", &filterChoice);
        switch(filterChoice){
          case 1:
            filterFlag=2017;
            break;
          case 2:
            filterFlag=2018;
            break;
          case 3:
            filterFlag=2019;
            break;
        }
        break;
      default:
        printf("Have a nice day!\n");
        flag=0;
        break;
    }

  }while(flag==1);
}

int main(int argc, char *argv[]){
  Player  *myPlayer;
  //int count=0;
  myPlayer=(Player*)malloc(sizeof(Player));

  if(argc>1){
    mainMenu(argv[1]);
  }
  else{
    mainMenu("lab10.dat");
  }
  free(myPlayer);
  return 0;
}
