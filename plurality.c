#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char name[100];
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
int vote(char name[]);
void print_winner(void);
int cmp(char ch1[], char ch2[]);

int main(void)
{
    // Populate array of candidates
    printf("Number of candidates: ");
    scanf("%d", &candidate_count);
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 1;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        scanf("%s", &candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Number of voters: ");
    int voter_count;
    scanf("%d", &voter_count);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        printf("Vote: ");
        char name[100];
        scanf("%s", name);

        // Check for invalid vote
        if (vote(name) == 0)
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
int vote(char name[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (cmp(candidates[i].name, name) == 1)
        {
            //printf("%s\n", candidates[i].name);
            candidates[i].votes += 1;
            return 1;
        }
    }
    return 0;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

int cmp(char ch1[], char ch2[])
{
    int len1 = strlen(ch1);
    int len2 = strlen(ch2);
    if (len1 != len2)
    return 0;
    for (int i = 0; i < len1; i++)
    {
        if (ch1[i] != ch2[i])
        return 0;
    }
    return 1;
}
