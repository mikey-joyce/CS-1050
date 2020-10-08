#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getFixedField(char* in, int size, FILE* fp){
  //function that JimR gave to us to read a single field
  int i;
  for(i=0; i<size; i++){
    in[i]=fgetc(fp);
  }
  in[i]='\0';
}

int main(void){
  //declare my variables
  int points=0;
  //int num=0;
  float score=0;
  char keySN[12];
  char studentNum[12];
  char keyNum1[8];
  char keyNum2[8];
  char keyName[11];
  char lastName[11];
  char keyColor[12];
  char firstName[12];
  char answerKey[40];
  char answerSheet[40];
  FILE* fileF;

  //make sure the file can be opened
  fileF=fopen("lab9.txt", "r");
  if(NULL == fileF){
    printf("Error: Could not open file.\n");
  }
  else{
    while(!feof(fileF)){
      getFixedField(studentNum, 8, fileF);
      //if(!feof(fileF)){
        //determines if its an answer KEY or not
        char comparison1[8]="99999999";
        if(strcmp(studentNum, comparison1)==0){
          //gets the information of the answer key
          getFixedField(keySN, 12, fileF);
          //printf("%s\n", keySN);
          getFixedField(keyNum1, 8, fileF);
          //printf("%s\n", keyNum1);
          getFixedField(keyName, 11, fileF);
          //printf("%s\n", keyName);
          getFixedField(keyColor, 12, fileF);
          //printf("%s\n", keyColor);
          getFixedField(answerKey, 40, fileF);
          //printf("%s\n", answerKey);
          //char comparison2[8]="00000001";
          //if(strcmp(keyNum1, comparison2)==0){
            //num=1;
          //}
          //else{
            //num=2;
          //}
          printf("*** New Key=%s %s %s\n\t%s", keyColor, keyName, keyNum1, answerKey);
        }
        else{
          //gets data for the students
          getFixedField(studentNum, 12, fileF);
          getFixedField(keyNum2, 8, fileF);
          getFixedField(lastName, 11, fileF);
          getFixedField(firstName, 12, fileF);
          getFixedField(answerSheet, 40, fileF);
          for(int i=0; i<40; i++){
            //just incase they skipped a question
            if(isspace(answerSheet[i])!=0){
              continue;
            }
            else{
              if(answerSheet[i]==answerKey[i]){
                //gains the score of the test
                points++;
              }
            }
          }
          //calculate score
          score = (float)points/40;

          printf("%s %s:\n\t%s\n\tScore = %f", firstName, lastName, answerSheet, score);
        }
      //}
    }
    //close file
    fclose(fileF);
  }

}
