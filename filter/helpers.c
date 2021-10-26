#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE tmp = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed + 3 / 2) / 3;
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = tmp;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE r, g, b;
            r = image[i][j].rgbtRed;
            g = image[i][j].rgbtGreen;
            b = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = (BYTE)(0.393 * r + 0.769 * g + 0.189 * b + 0.5);
            if (image[i][j].rgbtRed > 255)
            image[i][j].rgbtRed = 255;

            image[i][j].rgbtGreen = (BYTE)(0.349 * r + 0.686 * g + 0.168 * b + 0.5);
            if (image[i][j].rgbtGreen > 255)
            image[i][j].rgbtGreen = 255;

            image[i][j].rgbtBlue = (BYTE)(0.272 * r + 0.534 * g + 0.131 * b + 0.5);
            if (image[i][j].rgbtBlue > 255)
            image[i][j].rgbtBlue = 255;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int mid = width / 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            BYTE r1, g1, b1, r2, g2, b2;
            r1 = image[i][j].rgbtRed;
            g1 = image[i][j].rgbtGreen;
            b1 = image[i][j].rgbtBlue;
            r2 = image[i][width - j - 1].rgbtRed;
            g2 = image[i][width - j - 1].rgbtGreen;
            b2 = image[i][width - j - 1].rgbtBlue;
            
            image[i][width - j - 1].rgbtRed = r1;
            image[i][width - j - 1].rgbtGreen = g1;
            image[i][width - j - 1].rgbtBlue = b1;
            image[i][j].rgbtRed = r2;
            image[i][j].rgbtGreen = g2;
            image[i][j].rgbtBlue = b2;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 1; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j+1].rgbtRed + image[i+1][j].rgbtRed + 4 / 2) / 4;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i+1][j].rgbtGreen + 4 / 2) / 4;
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i+1][j].rgbtBlue + 4 / 2) / 4;
            }
            
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + 4 / 2) / 4;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + 4 / 2) / 4;
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + 4 / 2) / 4;
            }
            
            else if (i == 0)
            {
                image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + 6 / 2) / 6;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + 6 / 2) / 6;
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + 6 / 2) / 6;
            }
            
            else if (j == 0)
            {
                image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j+1].rgbtRed + image[i+1][j].rgbtRed + 6 / 2) / 6;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i+1][j].rgbtGreen + 6 / 2) / 6;
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i+1][j].rgbtBlue + 6 / 2) / 6;
            }
            
            else if (i == height - 1)
            {
                image[i][j].rgbtRed = (image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + 6 / 2) / 6;
                image[i][j].rgbtGreen = (image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + 6 / 2) / 6;
                image[i][j].rgbtBlue = (image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + 6 / 2) / 6;
            }
            
            else if (i == width - 1)
            {
                image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + 6 / 2) / 6;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + 6 / 2) / 6;
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + 6 / 2) / 6;
            }
            
            else
            {
                image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + 9 / 2) / 9;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + 9 / 2) / 9;
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + 9 / 2) / 9;
            }
        }
    }
    /*
    int i, j;
    for (i = 1; i < height; i += 3)
    {
        for (j = 1; j < width; j += 3)
        {
            image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + 9 / 2) / 9;
            image[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + 9 / 2) / 9;
            image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + 9 / 2) / 9;
        }
    }
    int tmpi = i, tmpj = j;
    if (tmpi == height)
    {
        i = tmpi - 1;
        j = 1;
        for (; j < width; j += 3)
        {
            image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + 3 / 2) / 3;
            image[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + 3 / 2) / 3;
            image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + 3 / 2) / 3;
        }
    }
    if (tmpj == width)
    {
        j = tmpj - 1;
        i = 1;
        for (; i < height; i += 3)
        {
            image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i+1][j].rgbtRed + 3 / 2) / 3;
            image[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen + 3 / 2) / 3;
            image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue + 3 / 2) / 3;
        }
    }
    */
    return;
}
