#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para calcular a média dos valores RGB de um pixel
float calcular_media(char *pixel) {
    int r, g, b;
    sscanf(pixel, "%d %d %d", &r, &g, &b);
    return (r + g + b) / 3.0;
}

int main() {
    FILE *arquivo_orig, *arquivo_medias;
    char linha[1000];

    // Abrir o arquivo original para leitura
    arquivo_orig = fopen("C:\\Users\\danie\\OneDrive\\Documentos\\UFPI-2024.1\\PROJETOS\\IMAGE-OSEAS\\img\\input_image.txt", "r");
    if (arquivo_orig == NULL) {
        perror("Erro ao abrir o arquivo original");
        return EXIT_FAILURE;
    }

    // Ler a primeira linha e descartar
    fgets(linha, sizeof(linha), arquivo_orig);

    // Descartar a segunda linha
    fgets(linha, sizeof(linha), arquivo_orig);

    // Abrir o novo arquivo para escrita
    arquivo_medias = fopen("medias_pixels.txt", "w");
    if (arquivo_medias == NULL) {
        perror("Erro ao criar o arquivo de médias");
        fclose(arquivo_orig);
        return EXIT_FAILURE;
    }

    // Iterar pelas linhas do arquivo original
    while (fgets(linha, sizeof(linha), arquivo_orig) != NULL) {
        char *token;
        const char *delim = ","; // Corrigido para ser uma string literal
        char media[1000] = "";

        // Dividir a linha em pixels separados por vírgula
        token = strtok(linha, delim); // Corrigido para strtok
        while (token != NULL) {
            // Calcular a média dos valores RGB de cada pixel
            float media_pixel = calcular_media(token);
            // Adicionar a média calculada à string de médias
            sprintf(media + strlen(media), "%.2f,", media_pixel); // Corrigido sprintf
            token = strtok(NULL, delim);
        }

        // Escrever as médias calculadas no novo arquivo
        fprintf(arquivo_medias, "%s\n", media);
    }

    // Fechar os arquivos
    fclose(arquivo_orig);
    fclose(arquivo_medias);

    return EXIT_SUCCESS;
}
