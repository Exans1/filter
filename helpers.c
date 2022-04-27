#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
        double temp = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen +image[i][j].rgbtRed)/3.0);
        image[i][j].rgbtBlue = temp;
        image[i][j].rgbtGreen = temp;
        image[i][j].rgbtRed = temp;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            double tempBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            double tempGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            double tempRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);

            if(tempBlue > 255)
            {
                tempBlue = 255;
            }
            if(tempGreen > 255)
            {
                tempGreen = 255;
            }
            if(tempRed > 255)
            {
                tempRed = 255;
            }
                image[i][j].rgbtBlue = tempBlue;
                image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtRed = tempRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < round(width/2); j++)
        {
            RGBTRIPLE temp = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = image[i][j];
            image[i][j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imageTemp[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            imageTemp[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            //corner
            if((i == 0 && j == 0))
            {
                double tempBlue  = round((imageTemp[i][j].rgbtBlue  + imageTemp[i][j + 1].rgbtBlue  + imageTemp[i + 1][j].rgbtBlue  + imageTemp[i + 1][j + 1].rgbtBlue)/4.0);
                double tempGreen = round((imageTemp[i][j].rgbtGreen + imageTemp[i][j + 1].rgbtGreen + imageTemp[i + 1][j].rgbtGreen + imageTemp[i + 1][j + 1].rgbtGreen)/4.0);
                double tempRed   = round((imageTemp[i][j].rgbtRed   + imageTemp[i][j + 1].rgbtRed   + imageTemp[i + 1][j].rgbtRed   + imageTemp[i + 1][j + 1].rgbtRed)/4.0);
                image[i][j].rgbtBlue = tempBlue;
                image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtRed = tempRed;
            }
            else if((i == 0 && j == width - 1))
            {
                double tempBlue  = round((imageTemp[i][j].rgbtBlue  + imageTemp[i][j - 1].rgbtBlue  + imageTemp[i + 1][j].rgbtBlue  + imageTemp[i + 1][j - 1].rgbtBlue)/4.0);
                double tempGreen = round((imageTemp[i][j].rgbtGreen + imageTemp[i][j - 1].rgbtGreen + imageTemp[i + 1][j].rgbtGreen + imageTemp[i + 1][j - 1].rgbtGreen)/4.0);
                double tempRed   = round((imageTemp[i][j].rgbtRed   + imageTemp[i][j - 1].rgbtRed   + imageTemp[i + 1][j].rgbtRed   + imageTemp[i + 1][j - 1].rgbtRed)/4.0);
                image[i][j].rgbtBlue  = tempBlue;
                image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtRed   = tempRed;
            }
            else if((i == height - 1 && j == 0))
            {
                double tempBlue  = round((imageTemp[i][j].rgbtBlue  + imageTemp[i][j + 1].rgbtBlue  + imageTemp[i - 1][j].rgbtBlue  + imageTemp[i - 1][j + 1].rgbtBlue)/4.0);
                double tempGreen = round((imageTemp[i][j].rgbtGreen + imageTemp[i][j + 1].rgbtGreen + imageTemp[i - 1][j].rgbtGreen + imageTemp[i - 1][j + 1].rgbtGreen)/4.0);
                double tempRed   = round((imageTemp[i][j].rgbtRed   + imageTemp[i][j + 1].rgbtRed   + imageTemp[i - 1][j].rgbtRed   + imageTemp[i - 1][j + 1].rgbtRed)/4.0);
                image[i][j].rgbtBlue = tempBlue;
                image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtRed = tempRed;
            }
            else if((i == height - 1 && j == width - 1))
            {
                double tempBlue  = round((imageTemp[i][j].rgbtBlue  + imageTemp[i][j - 1].rgbtBlue  + imageTemp[i - 1][j].rgbtBlue  + imageTemp[i - 1][j - 1].rgbtBlue)/4.0);
                double tempGreen = round((imageTemp[i][j].rgbtGreen + imageTemp[i][j - 1].rgbtGreen + imageTemp[i - 1][j].rgbtGreen + imageTemp[i - 1][j - 1].rgbtGreen)/4.0);
                double tempRed   = round((imageTemp[i][j].rgbtRed   + imageTemp[i][j - 1].rgbtRed   + imageTemp[i - 1][j].rgbtRed   + imageTemp[i - 1][j - 1].rgbtRed)/4.0);
                image[i][j].rgbtBlue = tempBlue;
                image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtRed = tempRed;
            }
            //sides
            else if(i == 0)
            {
                double tempBlue  = round((imageTemp[i][j].rgbtBlue  + imageTemp[i][j - 1].rgbtBlue  + imageTemp[i][j + 1].rgbtBlue  + imageTemp[i + 1][j - 1].rgbtBlue  + imageTemp[i + 1][j].rgbtBlue  + imageTemp[i + 1][j + 1].rgbtBlue)/6.0);
                double tempGreen = round((imageTemp[i][j].rgbtGreen + imageTemp[i][j - 1].rgbtGreen + imageTemp[i][j + 1].rgbtGreen + imageTemp[i + 1][j - 1].rgbtGreen + imageTemp[i + 1][j].rgbtGreen + imageTemp[i + 1][j + 1].rgbtGreen)/6.0);
                double tempRed   = round((imageTemp[i][j].rgbtRed   + imageTemp[i][j - 1].rgbtRed   + imageTemp[i][j + 1].rgbtRed   + imageTemp[i + 1][j - 1].rgbtRed   + imageTemp[i + 1][j].rgbtRed   + imageTemp[i + 1][j + 1].rgbtRed)/6.0);
                image[i][j].rgbtBlue  = tempBlue;
                image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtRed   = tempRed;
            }
            else if(i == height - 1)
            {
                double tempBlue = round((imageTemp[i][j].rgbtBlue + imageTemp[i][j - 1].rgbtBlue + imageTemp[i][j + 1].rgbtBlue + imageTemp[i - 1][j - 1].rgbtBlue + imageTemp[i - 1][j].rgbtBlue + imageTemp[i - 1][j + 1].rgbtBlue)/6.0);
                double tempGreen = round((imageTemp[i][j].rgbtGreen + imageTemp[i][j - 1].rgbtGreen + imageTemp[i][j + 1].rgbtGreen + imageTemp[i - 1][j - 1].rgbtGreen + imageTemp[i - 1][j].rgbtGreen + imageTemp[i - 1][j + 1].rgbtGreen)/6.0);
                double tempRed = round((imageTemp[i][j].rgbtRed + imageTemp[i][j - 1].rgbtRed + imageTemp[i][j + 1].rgbtRed + imageTemp[i - 1][j - 1].rgbtRed + imageTemp[i - 1][j].rgbtRed + imageTemp[i - 1][j + 1].rgbtRed)/6.0);
                image[i][j].rgbtBlue = tempBlue;
                image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtRed = tempRed;
            }
            else if(j == 0)
            {
                double tempBlue = round((imageTemp[i][j].rgbtBlue + imageTemp[i - 1][j].rgbtBlue + imageTemp[i + 1][j].rgbtBlue + imageTemp[i - 1][j + 1].rgbtBlue + imageTemp[i][j + 1].rgbtBlue + imageTemp[i + 1][j + 1].rgbtBlue)/6.0);
                double tempGreen = round((imageTemp[i][j].rgbtGreen + imageTemp[i - 1][j].rgbtGreen + imageTemp[i + 1][j].rgbtGreen + imageTemp[i - 1][j + 1].rgbtGreen + imageTemp[i][j + 1].rgbtGreen + imageTemp[i + 1][j + 1].rgbtGreen)/6.0);
                double tempRed = round((imageTemp[i][j].rgbtRed + imageTemp[i - 1][j].rgbtRed + imageTemp[i + 1][j].rgbtRed + imageTemp[i - 1][j + 1].rgbtRed + imageTemp[i][j + 1].rgbtRed + imageTemp[i + 1][j + 1].rgbtRed)/6.0);
                image[i][j].rgbtBlue = tempBlue;
                image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtRed = tempRed;
            }
            else if(j == width - 1)
            {
                double tempBlue = round((imageTemp[i][j].rgbtBlue + imageTemp[i - 1][j].rgbtBlue + imageTemp[i + 1][j].rgbtBlue + imageTemp[i - 1][j - 1].rgbtBlue + imageTemp[i][j - 1].rgbtBlue + imageTemp[i + 1][j - 1].rgbtBlue)/6.0);
                double tempGreen = round((imageTemp[i][j].rgbtGreen + imageTemp[i - 1][j].rgbtGreen + imageTemp[i + 1][j].rgbtGreen + imageTemp[i - 1][j - 1].rgbtGreen + imageTemp[i][j - 1].rgbtGreen + imageTemp[i + 1][j - 1].rgbtGreen)/6.0);
                double tempRed = round((imageTemp[i][j].rgbtRed + imageTemp[i - 1][j].rgbtRed + imageTemp[i + 1][j].rgbtRed + imageTemp[i - 1][j - 1].rgbtRed + imageTemp[i][j - 1].rgbtRed + imageTemp[i + 1][j - 1].rgbtRed)/6.0);
                image[i][j].rgbtBlue = tempBlue;
                image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtRed = tempRed;
            }
            //middle
            else
            {
                double tempBlue = round((imageTemp[i - 1][j - 1].rgbtBlue + imageTemp[i - 1][j].rgbtBlue + imageTemp[i - 1][j + 1].rgbtBlue + imageTemp[i][j - 1].rgbtBlue + imageTemp[i][j].rgbtBlue + imageTemp[i][j + 1].rgbtBlue + imageTemp[i + 1][j - 1].rgbtBlue + imageTemp[i + 1][j].rgbtBlue + imageTemp[i + 1][j + 1].rgbtBlue)/9.0);
                double tempGreen = round((imageTemp[i - 1][j - 1].rgbtGreen + imageTemp[i - 1][j].rgbtGreen + imageTemp[i - 1][j + 1].rgbtGreen + imageTemp[i][j - 1].rgbtGreen + imageTemp[i][j].rgbtGreen + imageTemp[i][j + 1].rgbtGreen + imageTemp[i + 1][j - 1].rgbtGreen + imageTemp[i + 1][j].rgbtGreen + imageTemp[i + 1][j + 1].rgbtGreen)/9.0);
                double tempRed = round((imageTemp[i - 1][j - 1].rgbtRed + imageTemp[i - 1][j].rgbtRed + imageTemp[i - 1][j + 1].rgbtRed + imageTemp[i][j - 1].rgbtRed + imageTemp[i][j].rgbtRed + imageTemp[i][j + 1].rgbtRed + imageTemp[i + 1][j - 1].rgbtRed + imageTemp[i + 1][j].rgbtRed + imageTemp[i + 1][j + 1].rgbtRed)/9.0);
                image[i][j].rgbtBlue = tempBlue;
                image[i][j].rgbtGreen = tempGreen;
                image[i][j].rgbtRed = tempRed;
            }
        }
    }
    return;
}
