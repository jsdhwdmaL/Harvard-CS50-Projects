#include <stdio.h>

int main(void)
{
    //input
    int height;
    do
    {
        printf("Height: ");
        scanf("%d", &height);
    }
    while (height < 1 || height > 8);


    //print
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for (int x = 1; x <= i; x++)
        {
            printf("#");
        }
        printf("  ");
        for (int y = 1; y <= i; y++)
        {
            printf("#");
        }
        printf("\n");
    }
}
