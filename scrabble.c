#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char word[]);

int main(void)
{
    // Get input words from both players
    char word1[100];
    printf("Player 1: ");
    scanf("%s", &word1);
    char word2[100];
    printf("Player 2: ");
    scanf("%s", &word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
        printf("Player 1 wins!");
    else if (score2 > score1)
        printf("Player 2 wins!");
    else
        printf("Tie!");
}

int compute_score(char word[])
{
    // TODO: Compute and return score for string
    int sum = 0;
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        if (isupper(word[i]))
        {
            sum += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            sum += POINTS[word[i] - 'a'];
        }
    }
    return sum;
}
