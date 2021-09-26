#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    char key[26];
    printf("Key: ");
    gets(key);
    int n = strlen(key);
    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (!isupper(key[i]) && !islower(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        char tmp = key[i];
        for (int j = 0; j < i; j++)
        {
            if (tmp == key[j])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }

    //input
    char text[1005];
    printf("plaintext: ");
    gets(text);
    int cnt = strlen(text);
    int pos;
    for (int i = 0; i < cnt; i++)
    {
        if (islower(text[i]))
        {
            pos = text[i] - 'a';
            if (isupper(key[pos]))
            {
                text[i] = key[pos] + 32;
            }
            else
            {
                text[i] = key[pos];
            }
        }
        else if (isupper(text[i]))
        {
            pos = text[i] - 'A';
            if (islower(key[pos]))
            {
                text[i] = key[pos] - 32;
            }
            else
            {
                text[i] = key[pos];
            }
        }
    }
    printf("ciphertext: %s\n", text);
    return 0;
}
