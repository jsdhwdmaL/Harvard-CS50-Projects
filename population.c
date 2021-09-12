#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        printf("Start size: ");
        scanf("%d", &start);
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        printf("End size: ");
        scanf("%d", &end);
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int n = 0;
    while (start < end)
    {
        n++;
        start += start / 3 - start / 4;
    }

    // TODO: Print number of years
    printf("Years: %d\n", n);
}
