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
typedef struct pixel PixelRGB;
typedef struct image Image;

//nova
typedef struct pixelgray Pixelgray;
typedef struct image ImageGray;
/*
Novas funcoes
- ler txt e converter em imagem -> Image
- exportar imagem para txt -> txt salvo
- Converter imagem RGB para nivel de cinza, isto é, com um único valor de pixel -> ImageGray
- aplicar clusterizacao na imagem a partir de um arquivo txt com sementes, 
	adtaptar a funcao da distancia euclidiana para considerar apenas os valores do pixel -> salvar txt com o resultado da clusterizacao
*/



/**
 * @brief Estrutura que representa um pixel RGB.
 *
 */
typedef struct pixel PixelRgb;

/**
 * @brief Estrutura que representa uma imagem.
 *
 */
typedef struct image Image;

/**
 * @brief Função que cria uma imagem.
 *
 * @param altura
 * @param largura
 * @return Image*
 */
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
 * @return PixelRgb
 */
PixelRgb getPixel(int lin, int col, Image *img);

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
