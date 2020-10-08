#include <stdio.h>

void PromptAndGetInteger(char *prompt, int *i)
{
    printf("%s", prompt);
    scanf("%d", i);
    printf("\n");
}

void PromptAndGetFloat(char *prompt, float *f)
{
    printf("%s", prompt);
    scanf("%f", f);
    printf("\n");
}

void PromptAndGetString(char *prompt, char *s)
{
    printf("%s", prompt);
    scanf("%s", s);
    printf("\n");
}

void PromptAndGetArray(char *prompt, int *a)
{
    printf("%s\n", prompt);
    for(int i = 0; i<10 && (a[i-1] != -1 || a[-1] == -1); i++) // a[-1] == -1 is to disregard the first value since a[i-1] indexes out of bounds
    {
        printf("\tArray location %d: ", i);
        scanf("%d", &a[i]);
    }
}

void PrintArray(int *a)
{
    for(int i = 0; i<10 && a[i] != -1; i++)
    {
        printf("Entry %d = %d\n", i, a[i]);
    }
}

int main(void)
{
    int i;
    float f;
    char s[11];
    int a[11];
    
    printf("\n***********************\n");
    printf("* Welcome to Prelab 6 *\n");
    printf("***********************\n\n");
    
    PromptAndGetInteger("Please enter an integer and hit enter: ", &i);
    PromptAndGetFloat("Please enter a float and hit enter: ", &f);
    PromptAndGetString("Please enter a string with no spaces and hit enter: ", s);
    PromptAndGetArray("Please enter up to 10 positive integers, entering -1 to end: ", a);
    
    printf("\n************************\n");
    printf("You entered %d,%f,%s\n", i, f, s);
    PrintArray(a);
}

