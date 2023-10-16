#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float rgbVar = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;

            image[i][j].rgbtBlue = round(rgbVar);
            image[i][j].rgbtGreen = round(rgbVar);
            image[i][j].rgbtRed = round(rgbVar);
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int ogBlue = image[i][j].rgbtBlue;
            int ogGreen = image[i][j].rgbtGreen;
            int ogRed = image[i][j].rgbtRed;

            float sepiaBlue = 0.272 * ogRed + 0.534 * ogGreen + 0.131 * ogBlue;
            float sepiaGreen = 0.349 * ogRed + 0.686 * ogGreen + 0.168 * ogBlue;
            float sepiaRed = 0.393 * ogRed + 0.769 * ogGreen + 0.189 * ogBlue;

            image[i][j].rgbtBlue = fmin(round(sepiaBlue), 255);
            image[i][j].rgbtGreen = fmin(round(sepiaGreen), 255);
            image[i][j].rgbtRed = fmin(round(sepiaRed), 255);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int halvedVal = width / 2;
    // RGBTRIPLE(*container)[halvedVal] = calloc(height, halvedVal * sizeof(RGBTRIPLE));
    RGBTRIPLE container[height][halvedVal];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < halvedVal; j++)
        {
            container[i][j] = image[i][j];

            int otherSideIndexWidth = width - j - 1;
            image[i][j] = image[i][otherSideIndexWidth];
            image[i][otherSideIndexWidth] = container[i][j];
        }
    }
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
            int counter = 0;
            float sumRed = 0;
            float sumBlue = 0;
            float sumGreen = 0;

            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        sumRed += copy[k][l].rgbtRed;
                        sumBlue += copy[k][l].rgbtBlue;
                        sumGreen += copy[k][l].rgbtGreen;
                        counter++;
                    }
                }
            }

            image[i][j].rgbtRed = fmin(round(sumRed / counter), 255);
            image[i][j].rgbtBlue = fmin(round(sumBlue / counter), 255);
            image[i][j].rgbtGreen = fmin(round(sumGreen / counter), 255);
        }
    }

    return;
}
