#include <stdio.h>
#include <stdlib.h>
#include "image.h"

// Implemntação realizada e testada em computadores Windows. Caso o senhor tenha dificuldade em compilar o código, verifique os caminhos.

int main()
{
    FILE *arq;
    arq = fopen("./img/input_image.txt","r");

    Image img;
    ImageGray img_gray;

    system("PAUSE");

    ler_imagem_arkv(arq, &img);
    printImage(&img);

    converter_imagem(&img, &img_gray);
    seedimagemGray(&img_gray);

    FILE *gray_image;
    gray_image = fopen("./output/imagem2.txt", "w");
    salvar_imagem_arkv(&img_gray, gray_image);

    gray_image = fopen("./output/imagem2.txt", "r");



    ler_imagem_arkv(gray_image, &img);
    printImage(&img);


    fclose(arq);
    fclose(gray_image);

    FILE *cluster_image;
    cluster_image = fopen("./saida.txt", "r");
    printcluster(cluster_image);

    free(img.pixel);
    free(img_gray.pixel);

    return 0;
}