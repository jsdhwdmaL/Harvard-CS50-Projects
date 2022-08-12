#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //input
    char sentence[2005];
    printf("Text: ");
    gets(sentence);
    int len = strlen(sentence);
    int letternum = 0;
    int wordnum = 0;
    int sentencenum = 0;
    for (int i = 0; i < len; i++)
    {
        if (sentence[i] == ' ')
        {
            wordnum++;
        }
        else if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            sentencenum++;
        }
        else if (isupper(sentence[i]) || islower(sentence[i]))
        {
            letternum++;
        }
    }
    wordnum++;
    double tmp = 0.0588 * ((double)letternum * 100 / wordnum) - 0.296 * ((double)sentencenum * 100 / wordnum) - 15.8;
    int index = (int)(tmp + 0.5);
    //printf("%s", sentence);
    //printf("%d %d %d\n", wordnum, letternum, sentencenum);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
