#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void ler_imagem_arkv(FILE *arq, Image *img){
    fscanf(arq, "%d", &img->altura);
    fscanf(arq, "%d", &img->largura);
    img->pixel = (PixelRGB*)calloc(sizeof(PixelRGB), img->altura*img->largura);
    for(int i=0;i<img->altura;i++){
        for(int x = 0; x < img->largura; x++){
            fscanf(arq,"%d %d %d,", &img->pixel[(i * img->largura) + x].red, &img->pixel[(i * img->largura) + x].green, &img->pixel[(i * img->largura) + x].blue);
        }
    }
    fclose(arq);
}

//========================================================================================================================================================================

void alocarGray(int altura, int largura, Pixelgray **pixel)
{
    *pixel = (Pixelgray*)calloc(sizeof(Pixelgray), altura*largura);
}

void converter_imagem(Image *img, ImageGray *imgray)
{
    imgray->altura = img->altura;
    imgray->largura = img->largura;
    
    alocarGray(imgray->altura, imgray->largura,&(imgray->pixel));
    
    for (int i = 0; i < img->altura; i++){
        for (int j = 0; j < img->largura; j++) {

            int gray = (img->pixel[i * img->largura +j].red + img->pixel[i * img->largura +j].green + img->pixel[i * img->largura +j].blue) / 3;

            imgray->pixel[i * img->largura +j].media_pixel = gray;
        }
     }
}
void salvar_imagem_arkv(ImageGray *img, FILE *gray_image)
{
    fprintf(gray_image, "%d\n", img->altura);
    fprintf(gray_image, "%d\n", img->largura);

    for(int i=0;i<img->altura;i++){
        for(int x = 0; x < img->largura; x++){
            fprintf(gray_image,"%d %d %d,", img->pixel[(i * img->largura) + x].media_pixel, img->pixel[(i * img->largura) + x].media_pixel, img->pixel[(i * img->largura) + x].media_pixel);
        }
        fprintf(gray_image,"\n");
    }
    
    
    fclose(gray_image);
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
    printf("\033[38;2;%d;%d;%dm**\033[0m", img->pixel[lin*img->largura+col].red, img->pixel[lin*img->largura+col].green, img->pixel[lin*img->largura+col].blue);
}

void printImage(Image *img)
{
    for (int i = 0; i < img->altura; i++)
    {
        for (int j = 0; j < img->largura; j++)
        {
            printPixel(i, j, img);
        }
        printf("\n");
    }
}

void printGrayImage(ImageGray *img) {
    for (int i = 0; i < img->altura; i++) {
        for (int j = 0; j < img->largura; j++) {
            printf("\033[38;2;%d;%d;%dm**\033[0m", img->pixel[i * img->largura + j].media_pixel, img->pixel[i * img->largura + j].media_pixel, img->pixel[i * img->largura + j].media_pixel);
        }
        printf("\n");
    }
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

void printValoresImage(Image *img)
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

//========================================================================================================================================================================

