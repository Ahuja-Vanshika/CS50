#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string);
int count_words(string);
int count_sentences(string);

int main(void)
{
    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    int letters = count_letters(text);
    int words = count_words(text);
    int sent = count_sentences(text);

    float l = (float) letters / words * 100;
    float s = (float) sent / words * 100;

    float index = 0.0588 * l - 0.296 * s - 15.8;
    int index1 = round(index);

    if (index1 < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index1 >= 2 && index1 <= 15)
    {
        printf("Grade %d\n", index1);
    }
    else if (index1 >= 16)
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            count++;
            while (isspace(text[i]))
            {
                i++;
            }
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}
