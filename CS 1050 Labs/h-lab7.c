#include<stdio.h>

void getString(char* str){
  scanf("%s", str);
}

int stringLength(char* chr){
  char* p;
  unsigned int length=0;
  for(p=chr; *p!='\0'; p++){
    length++;
  }
  return (length-1);
}

void replaceString(char* original, char* pattern, char* replace){
  char* temp1=original;
  char* temp2=pattern;
  char* temp3;
  char* x=original;
  char* y=replace;
  int flag = 0, j = 0;

  //Finds the pattern
  for(int i=0; i<stringLength(original); i++){
    if(*temp1==*temp2){
      temp3=temp1;
      for(j=0; j<stringLength(pattern); j++){
        if(*temp3==*temp2){
          temp3++;
          temp2++;
        }
        else{
          break;
        }
      }
      temp2=pattern;
      if(j==stringLength(pattern)){
        flag=1;
        printf("\nPattern found at index %d\n", i);
        //Replaces old values with new one
        int k=i;
        for(int mid=0; mid<=stringLength(replace); mid++){
          *(x+k)=*(y+mid);
          //Used for debugging :)
          //printf("Original val of where the pattern is: %d\n", *(x+k));
          //printf("Replace val: %d\n", *(y+mid));
          k++;
        }
      }
    }
    temp1++;
  }
  if(flag==0){
    printf("Pattern not found.\n");
  }
}

int main(void){
  char original[256], pattern[32], replace[32];

  printf("*** Welcome to Lab 7 ***\n");

  //Gets info for original string
  printf("Please enter the original string: \n");
  getString(original);
  printf("\nOriginal: %s\n\n", original);

  //Gets info for the pattern
  printf("Please enter the pattern: \n");
  getString(pattern);
  printf("Pattern: %s\n\n", pattern);

  //Gets info for the replacement
  printf("Please enter the replacement: \n");
  getString(replace);
  printf("Replacement: %s\n\n", replace);

  //Replaces string
  replaceString(original, pattern, replace);

  //Prints out the result and ending message
  printf("The result is '%s'\n", original);
  printf("*** Thanks for doing Lab 7 ***\n");
}
