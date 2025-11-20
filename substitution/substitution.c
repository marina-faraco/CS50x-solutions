#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_argc(int c);
int check_len_argv(string key);
int argv_isalpha(string key);
int argv_repetition(string key);
void ciphertext(string plaintext, string key);

int main(int argc, char *argv[])
{
    int c = argc;
    string key = argv[1];

    if (check_argc(c) != 0 || check_len_argv(key) != 0 || argv_isalpha(key) != 0 ||
        argv_repetition(key) != 0)
    {
        return 1;
    }
    else
    {
        string plain = get_string("Plaintext: ");
        ciphertext(plain, key);
        return 0;
    }
}

int check_argc(int c)
{
    if (c < 2)
    {
        printf("Missing command line argument\n");
        return 1;
    }
    else if (c > 2)
    {
        printf("Too many command line arguments\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_len_argv(string key)
{
    int len = strlen(key);

    if (len < 26 || len > 26)
    {
        printf("The key must have 26 characters\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int argv_isalpha(string key)
{
    int len = strlen(key);

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("The key must have only alphabetical charcters\n");
            return 1;
        }
    }
    return 0;
}

int argv_repetition(string key)
{
    int len = strlen(key);

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i != j && tolower(key[i]) == tolower(key[j]))
            {
                printf("The key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    return 0;
}

void ciphertext(string plaintext, string key)
{
    int len = strlen(plaintext);

    printf("ciphertext: ");
    for (int i = 0; i < len; i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            if (isupper(c))
            {
                int pos = c - 'A';
                char cipher = toupper(key[pos]);
                printf("%c", cipher);
            }
            else
            {
                int pos = c - 'a';
                char cipher = tolower(key[pos]);
                printf("%c", cipher);
            }
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}
