#include <stdio.h>
#include <string.h>

int main(void)
{
    char ans[100];
    printf("What's your name? ");
    scanf("%s", &ans);
    printf("hello, %s\n", ans);
}
