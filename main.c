#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "image.c"

int main()
{
    FILE *arq = fopen("C:\\Users\\danie\\OneDrive\\Documentos\\UFPI-2024.1\\PROJETOS\\IMAGE-OSEAS\\IMAGE-OSEAS\\img\\input_image.txt", "r");
    Image *img = createImage(0, 0);
    ler_imagem_arkv(arq, img);
    printf("Imagem Colorida:\n");
    for (int i = 0; i < img->altura; i++)
    {
        for (int j = 0; j < img->largura; j++)
        {
            printPixel(i, j, img);
        }
        printf("\n");
    }

    printDimensoesImage(img);
    ImageGray *imgray = calloc(1, sizeof(ImageGray));
    converter_imagem(img, imgray);
    // printImage(imgray);
    FILE *arq2 = fopen("imagem2.txt", "w");
    salvar_imagem_arkv(imgray, arq2);


    printf("Quer sair? (s/n)\n");
    char c;
    scanf("%c", &c);
    if (c == 's')
    {
        return 0;
    }
    fclose(arq);
    fclose(arq2);
    return 0;
}