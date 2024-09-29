#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[512];
    bool found = false;
    int counter = 0;
    char filename[9];
    FILE *img = NULL;

    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check for JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If a JPEG file was already found, close it before starting a new one
            if (found)
            {
                fclose(img);
            }
            else
            {
                found = true;
            }

            // Create a new JPEG file
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create image file.\n");
                fclose(card);
                return 1;
            }

            counter++;
        }

        // If a JPEG file is open, write the buffer to it
        if (found)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Close any remaining open files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);

    return 0;
}
