#include<stdio.h>

void PrintAtBats(int atbats[]){
    //Prints all at bats except for: atbat[i] == -1
    int i=0, flag=1;
    while(flag!=0){
        if(atbats[i]==-1){
            flag=0;
        }
        else{
            printf("%d ", atbats[i]);
            i++;
        }
    }
}

void CalculateBattingAverage(int atbats[], float avg[], int indexToCalculate){
    int i=0, flag=1, x=0;
    while(flag!=0){
        //When it reaches the end of the array it stops the loop
        if(atbats[i]==-1){
            flag=0;
        }
        else{
            //Determines how many hits the player got
            if(atbats[i]>0){
                x++;
            }
            i++;
        }
    }
    //Adds the average into avg[]
    //If slot is empty add average here
    float temp=0.0;
    if(avg[indexToCalculate]==-1){
        temp=(float)x/(float)i;
        avg[indexToCalculate]=(temp);
    }
}

void CalculateSluggingPercentage(int atbats[], float pct[], int indexToCalculate){
    int i=0, flag=1, x=0;
    while(flag!=0){
        //When it reaches the end of the array it stops the loop
        if(atbats[i]==-1){
            flag=0;
        }
        else{
            //Determines how many "slugs" the player got
            x += atbats[i];
            i++;
        }
    }
    //Adds the average into avg[]
    //If slot is empty add average here
    if(pct[indexToCalculate]==-1){
        pct[indexToCalculate]=((float)x/i);
    }
}

void PrintResult(float result[]){
    //Prints out average and slugging results
    for(int i=0;i<3;i++){
        printf("\tPlayer %d: %.3f\n", (i+1), result[i]);
    }
}

void DoCalculations(int atbats1[], int atbats2[], int atbats3[], float battingavg[], float sluggingpct[]){
    //Calculates the batting averages
    CalculateBattingAverage(atbats1, battingavg, 0);
    CalculateBattingAverage(atbats2, battingavg, 1);
    CalculateBattingAverage(atbats3, battingavg, 2);

    //calculates slugging percentages
    CalculateSluggingPercentage(atbats1, sluggingpct, 0);
    CalculateSluggingPercentage(atbats2, sluggingpct, 1);
    CalculateSluggingPercentage(atbats3, sluggingpct, 2);
}

int main(void){
    //Declare my data
    int player1[10]={0,1,0,1,2,0,0,0,0,-1};
    int player2[15]={3,0,1,0,0,4,0,0,1,0,0,0,0,0,-1};
    int player3[12]={0,0,0,4,2,0,0,0,0,0,1,-1};
    float battingavg[3]={-1, -1, -1};
    float sluggingpct[3]={-1, -1, -1};

    //Print out the initial data
    printf("Player 1: ");
    PrintAtBats(player1);
    printf("\n");
    printf("Player 2: ");
    PrintAtBats(player2);
    printf("\n");
    printf("Player 3: ");
    PrintAtBats(player3);

    //Do all calculations and print it out
    DoCalculations(player1, player2, player3, battingavg, sluggingpct);
    printf("\nBatting Averages:\n");
    PrintResult(battingavg);
    printf("Slugging Averages:\n");
    PrintResult(sluggingpct);

}
