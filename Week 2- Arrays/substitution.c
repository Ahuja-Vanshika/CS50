#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(const char *);

int main(int argc, char *argv[])
{
    int index;
    if (argc != 2)
    {
        printf("Usage : ./substitution key\n");
        return 1;
    }
    else
    {
        if (check(argv[1]) == 0)
        {
            char *cip = argv[1];
            char text[100];
            printf("plaintext:  ");
            fgets(text, sizeof(text), stdin);
            int length = strlen(text);
            char cipher[length + 1];
            for (int i = 0; i < length; i++)
            {
                if (islower(text[i]))
                {
                    index = text[i] - 97;
                    cipher[i] = cip[index];
                    if (isupper(cipher[i]))
                    {
                        cipher[i] += 32;
                    }
                }
                else if (isupper(text[i]))
                {
                    index = text[i] - 65;
                    cipher[i] = cip[index];
                    if (islower(cipher[i]))
                    {
                        cipher[i] -= 32;
                    }
                }
                else
                {
                    cipher[i] = text[i];
                }
            }
            cipher[length] = '\0';
            printf("ciphertext: %s\n", cipher);
        }
        else
        {
            return 1;
        }
    }
}

int check(const char *str)
{
    int length = strlen(str);
    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(str[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        for (int j = i + 1; j < length; j++) // Removed nested loop for duplicate check
        {
            if (str[i] == str[j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    return 0;
}
