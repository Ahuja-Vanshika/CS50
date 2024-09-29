#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            int avg = round((red + green + blue) / 3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalred = 0, totalgreen = 0, totalblue = 0;
            float counter = 0.00;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentx = i + x;
                    int currenty = j + y;

                    if (currentx < 0 || currentx > (height - 1) || currenty < 0 ||
                        currenty > (width - 1))
                    {
                        continue;
                    }

                    totalred += image[currentx][currenty].rgbtRed;
                    totalgreen += image[currentx][currenty].rgbtGreen;
                    totalblue += image[currentx][currenty].rgbtBlue;

                    counter++;
                }
            }

            copy[i][j].rgbtRed = round(totalred / counter);
            copy[i][j].rgbtGreen = round(totalgreen / counter);
            copy[i][j].rgbtBlue = round(totalblue / counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxred = 0;
            int gxgreen = 0;
            int gxblue = 0;
            int gyred = 0;
            int gygreen = 0;
            int gyblue = 0;

            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (i - 1 + x < 0 || i - 1 + x > height - 1 || j - 1 + y < 0 ||
                        j - 1 + y > width - 1)
                    {
                        continue;
                    }

                    gxred = gxred + (image[i - 1 + x][j - 1 + y].rgbtRed * gx[x][y]);
                    gxgreen = gxgreen + (image[i - 1 + x][j - 1 + y].rgbtGreen * gx[x][y]);
                    gxblue = gxblue + (image[i - 1 + x][j - 1 + y].rgbtBlue * gx[x][y]);

                    gyred = gyred + (image[i - 1 + x][j - 1 + y].rgbtRed * gy[x][y]);
                    gygreen = gygreen + (image[i - 1 + x][j - 1 + y].rgbtGreen * gy[x][y]);
                    gyblue = gyblue + (image[i - 1 + x][j - 1 + y].rgbtBlue * gy[x][y]);
                }
            }

            int red = round(sqrt((gxred * gxred) + (gyred * gyred)));
            int green = round(sqrt((gxgreen * gxgreen) + (gygreen * gygreen)));
            int blue = round(sqrt((gxblue * gxblue) + (gyblue * gyblue)));

            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            copy[i][j].rgbtRed = red;
            copy[i][j].rgbtGreen = green;
            copy[i][j].rgbtBlue = blue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}
