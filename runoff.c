#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    char name[100];
    int votes;
    int eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;
int tmpvoter;

// Function prototypes
int vote(int voter, int rank, char name[]);
void tabulate(void);
int print_winner(void);
int find_min(void);
int is_tie(int min);
void eliminate(int min);
int cmp(char ch1[], char ch2[]);

int main(void)
{
    // Populate array of candidates
    printf("Number of candidates: ");
    scanf("%d", &candidate_count);
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %d\n", MAX_CANDIDATES);
        return 1;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        scanf("%s", &candidates[i].name);
        candidates[i].votes = 0;
        candidates[i].eliminated = 0;
    }

    printf("Number of voters: ");
    scanf("%d", &voter_count);
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %d\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char name[100];
            printf("Rank %d: ", j + 1);
            scanf("%s", name);

            // Record vote, unless it's invalid
            if (vote(i, j, name) == 0)
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (1)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        int won = print_winner();
        if (won == 1)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        int tie = is_tie(min);

        // If tie, everyone wins
        if (tie == 1)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (candidates[i].eliminated == 0)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
int vote(int voter, int rank, char name[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (cmp(candidates[i].name, name) == 1)
        {
            preferences[voter][rank] = i;
            return 1;
        }
    }
    return 0;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        // calculate votes
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == 0)
            {
                candidates[preferences[i][j]].votes++;
                continue;
            }
        }
    }
}

// Print the winner of the election, if there is one
int print_winner(void)
{
    int mid = voter_count / 2;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > mid)
        {
            printf("%s\n", candidates[i].name);
            return 1;
        }
    }
    return 0;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int mini = voter_count + 1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == 0)
        {
            if (candidates[i].votes < mini)
            {
                mini = candidates[i].votes;
            }
        }
    }
    return mini;
}

// Return true if the election is tied between all candidates, false otherwise
int is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == 0)
        {
            if (min != candidates[i].votes)
            return 0;
        }
    }
    return 0;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (min == candidates[i].votes)
        candidates[i].eliminated = 1;
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
