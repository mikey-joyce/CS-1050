#include <stdio.h>
#include <string.h>

void getPromptString(char *output){
  const char *str1 = "Dividend";
  const char *str2 = "Divisor";
  scanf("%s", output);

  //If they don't enter the values the way I want it
  while(*output!=*str1&&*output!=*str2){
    printf("\nEnter 'Dividend' or 'Divisor': ");
    scanf("%s", output);
  }
}

void promptAndGetFloat(char *prompt, float *output, float lowerlimit, float upperlimit){
  printf("\n%s (range %f to %f): ", prompt, lowerlimit, upperlimit);
  scanf("%f", output);

  while(*output<lowerlimit||*output>upperlimit){
    printf("***Error: you must enter a value in the range %f to %f ***", lowerlimit, upperlimit);
    printf("\n%s (range %f to %f): ", prompt, lowerlimit, upperlimit);
    scanf("%f", output);
  }
}

void getQuotient(float dividend, float divisor, float *quotient){
  *quotient = (dividend/divisor);
  printf("The quotient of %f and %f is %f\n", dividend, divisor, *quotient);
}

int main(void){
  //declare needed variables
  char promptOne[9];
  char promptTwo[9];
  float numOne, numTwo, final;

  //get prompts
  printf("Enter the prompt for the first variable: ");
  getPromptString(promptOne);
  printf("\nEnter the prompt for the second variable: ");
  getPromptString(promptTwo);

  //My comparison values
  const char *str = "Dividend";
  const char *mid = promptOne;

  //get my floats
  if(*mid==*str){
    promptAndGetFloat(promptOne, &numOne, -130.7, 62.9);
    promptAndGetFloat(promptTwo, &numTwo, -4.2, 6.1);
  }
  else{
    promptAndGetFloat(promptTwo, &numTwo, -130.7, 62.9);
    promptAndGetFloat(promptOne, &numOne, -4.2, 6.1);
  }
  //get the final float
  if(*mid==*str){
    getQuotient(numOne, numTwo, &final);
  }
  else{
    getQuotient(numTwo, numOne, &final);
  }
}
