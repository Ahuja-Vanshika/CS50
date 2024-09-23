#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height : ");
    }
    while (height < 1 || height > 8);

    int row;
    for (row = 1; row <= height; row++) // printing rows
    {
        int space;
        for (space = 0; space < height - row; space++) // printing spaces
        {
            printf(" ");
        }

        int column;
        for (column = 1; column <= row; column++) // print left side
        {
            printf("#");
        }
        printf("\n"); // bringing cursor to new line
    }
}