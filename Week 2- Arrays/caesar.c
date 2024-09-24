#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int only_digits(const char *);
char rotate(char, int);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./caesar key\n");
        return 1;
    }
    else
    {
        if (only_digits(argv[1]))
        {
            string text = get_string("plaintext:  ");
            int key = atoi(argv[1]);
            int length = strlen(text);
            char cipher[length + 1];

            for (int i = 0; i < length; i++)
            {
                cipher[i] = rotate(text[i], key);
            }
            cipher[length] = '\0';
            printf("ciphertext: %s\n", cipher);
        }
        else
        {
            printf("Usage : ./caesar key\n");
            return 1;
        }
    }
    return 0;
}

int only_digits(const char *key)
{
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isdigit(key[i]))
        {
            return 0;
        }
    }
    return 1;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            return (c - 'A' + n) % 26 + 'A';
        }
        else if (islower(c))
        {
            return (c - 'a' + n) % 26 + 'a';
        }
    }
    return c;
}
