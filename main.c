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
    
    printImage(img);

    printDimensoesImage(img);
    ImageGray *imgray = calloc(1, sizeof(ImageGray));
    converter_imagem(img, imgray);
    printGrayImage(imgray);
    FILE *arq2 = fopen("imagem2.txt", "w");
    salvar_imagem_arkv(imgray, arq2);
    
    // FILE *arq3 = fopen("imagem3.txt", "r");

    printf("Clica qualquer coisa para sair\n");
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