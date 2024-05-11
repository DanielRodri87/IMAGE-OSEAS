#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pixel
{
    int red;
    int green;
    int blue;
};

struct image
{
    int altura;
    int largura;
    PixelRGB *pixel;
};

struct pixelgray
{
    int media_pixel;
};


struct imagegray
{
    int altura;
    int largura;
    Pixelgray *pixel;
};


void ler_imagem_arkv(FILE *arq, Image *img){
    int i = 0;
	fscanf(arq,"%d", &(img->altura));
	fscanf(arq,"%d", &(img->largura));

    while (fscanf(arq, "%d %d %d", &(img->pixel[i].red), &(img->pixel[i].green), &(img->pixel[i].blue)) == 3)
    {
        i++;
    }
    
}

//========================================================================================================================================================================

void converter_imagem(Image *img, ImageGray *imgray){
    int pixelGray;
    imgray->altura = img->altura;
    imgray->largura = img->largura;

    for (int i = 0; i < img->altura; i++)
    {
        for (int j = 0; j < img->largura; j++)
        {
            pixelGray = (img->pixel[(i * img->largura) + j].red + img->pixel[(i * img->largura) + j].green + img->pixel[(i * img->largura) + j].blue) / 3;
            imgray->pixel[i * img->largura + j].media_pixel = pixelGray;
        }        
    }

}

//========================================================================================================================================================================

Image *createImage(int altura, int largura)
{
    Image *img = calloc(1, sizeof(Image));
    img->altura = altura;
    img->largura = largura;
    img->pixel = calloc(altura * largura, sizeof(PixelRGB));
    return img;
}

//========================================================================================================================================================================

void printDimensoesImage(Image *img)
{
    printf("As dimensoes da imagem sao = altura: %d e a largura: %d\n", img->altura, img->largura);
}

//========================================================================================================================================================================

void printPixel(int lin, int col, Image *img)
{
    printf("O pixel na image[%d][%d] tem os valores RGB(%d, %d, %d)\n", lin, col, img->pixel[(lin * img->largura) + col].red, img->pixel[(lin * img->largura) + col].green, img->pixel[(lin * img->largura) + col].blue);
}

//========================================================================================================================================================================

PixelRGB getPixel(int lin, int col, Image *img)
{

    return img->pixel[(lin * img->largura) + col];
}

//========================================================================================================================================================================

void setPixel(int lin, int col, Image *img)
{
    srand(time(NULL));
    for (int i = 0; i < lin * img->largura + col; i++)
    {
        img->pixel[i].red = rand() % 256;
        img->pixel[i].green = rand() % 256;
        img->pixel[i].blue = rand() % 256;
    }
}

//========================================================================================================================================================================

void printImage(Image *img)
{
    for (int i = 0; i < img->altura; i++)
    {
        for (int j = 0; j < img->largura; j++)
        {
            printf("RGB(%d, %d, %d) ", img->pixel[(i * img->largura) + j].red, img->pixel[(i * img->largura) + j].green, img->pixel[(i * img->largura) + j].blue);
        }
        printf("\n");
    }
}
