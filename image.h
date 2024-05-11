//User
/**
 * @file image.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef IMAGE_H
#define IMAGE_H

#include<stdio.h>

typedef struct pixel
{
    int red;
    int green;
    int blue;
} PixelRGB;


typedef struct image
{
    int altura;
    int largura;
    PixelRGB *pixel;
} Image;


typedef struct pixelgray
{
    int media_pixel;
} Pixelgray;

typedef struct imagegray
{
    int altura;
    int largura;
    Pixelgray *pixel;
} ImageGray;


//nova
// typedef struct pixelgray ;
// typedef struct imagegray ;

/*
Novas funcoes
- ler txt e converter em imagem -> Image
- Converter imagem RGB para nivel de cinza, isto é, com um único valor de pixel -> ImageGray
	a conversão de RGB para cinza será: PixelGray = (soma PixelRGB / 3) // parametro uma Image (RGB)
- exportar imagem em cinza, isto é, com um unico valor para txt -> txt salvo
- aplicar clusterizacao na imagem a partir de um arquivo txt com sementes, 
	adtaptar a funcao da distancia euclidiana para considerar apenas os valores do pixel -> salvar txt com o resultado da clusterizacao
*/



/**
 * @brief Estrutura que representa um pixel RGB.
 *
 */
//typedef struct pixel PixelRGB;

/**
 * @brief Estrutura que representa uma imagem.
 *
 */
//typedef struct image Image;

/**
 * @brief Função que cria uma imagem.
 *
 * @param altura
 * @param largura
 * @return Image*
 */

void ler_imagem_arkv(FILE *arq, Image *img);

void converter_imagem(Image *img, ImageGray *imgray);

Image *createImage(int altura, int largura);

/**
 * @brief Função que imprime as dimensões da imagem.
 *
 * @param img
 */
void printDimensoesImage(Image *img);

/**
 * @brief Função que imprime um pixel da imagem.
 *
 * @param lin
 * @param col
 * @param img
 */
void printPixel(int lin, int col, Image *img);

/**
 * @brief Função que retorna um pixel da imagem.
 *
 * @param lin
 * @param col
 * @param img
 * @return PixelRGB
 */
PixelRGB getPixel(int lin, int col, Image *img);

/**
 * @brief Função que seta um pixel da imagem.
 *
 * @param lin
 * @param col
 * @param img
 */
void setPixel(int lin, int col, Image *img);

/**
 * @brief Função que imprime a imagem.
 *
 * @param img
 */
void printImage(Image *img);

#endif // IMAGE_H
