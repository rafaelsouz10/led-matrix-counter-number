// Converte um código hexadecimal gerado no site: https://www.piskelapp.com/
// Para decimal em no padrão RGB.
// O código gerado será utilizado para exibir imagens na matriz de leds neopixel.
#include <stdio.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 5
#define MATRIX_DEPTH 3

// Função para converter valores ARGB (0xAARRGGBB) para RGB
void convertToRGB(int argb, int rgb[3]) {
    rgb[0] = argb & 0xFF;          // Blue
    rgb[2] = (argb >> 16) & 0xFF;  // Red
    rgb[1] = (argb >> 8) & 0xFF;   // Green
}

void input_values(int argb_values[MATRIX_ROWS * MATRIX_COLS]){

    // Matriz 5x5x3 para armazenar os valores RGB
    int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH];

    // Preencher a matriz RGB com a conversão dos valores ARGB
    for (int i = 0; i < MATRIX_ROWS * MATRIX_COLS; i++) {
        int rgb[3];
        convertToRGB(argb_values[i], rgb);
        
        int row = i / MATRIX_COLS;    // Cálculo da linha
        int col = i % MATRIX_COLS;    // Cálculo da coluna
        
        // Armazenar os valores RGB na matriz 5x5x3
        rgb_matrix[row][col][0] = rgb[0];  // Red
        rgb_matrix[row][col][1] = rgb[1];  // Green
        rgb_matrix[row][col][2] = rgb[2];  // Blue
    }

    // Exibir a matriz RGB resultante
    printf("{\n");
    for (int i = 0; i < MATRIX_ROWS; i++) {
        printf("    {");
        for (int j = 0; j < MATRIX_COLS; j++) {
            printf("{%d, %d, %d}", rgb_matrix[i][j][0], rgb_matrix[i][j][1], rgb_matrix[i][j][2]);
            if (j < MATRIX_COLS - 1) {
                printf(", ");
            }
        }
        printf("}");
        if (i < MATRIX_ROWS - 1) {
            printf(",");
        }
        printf("\n");
    }
    printf("}\n\n");

}

int main() {

    // Matriz de entrada com os valores ARGB
    int matriz0[MATRIX_ROWS * MATRIX_COLS] = {
    0xff000000, 0xffcafaf2, 0xffcafaf2, 0xffcafaf2, 0xff000000, 
    0xff000000, 0xffcafaf2, 0xff000000, 0xffcafaf2, 0xff000000, 
    0xff000000, 0xffcafaf2, 0xff000000, 0xffcafaf2, 0xff000000, 
    0xff000000, 0xffcafaf2, 0xff000000, 0xffcafaf2, 0xff000000, 
    0xff000000, 0xffcafaf2, 0xffcafaf2, 0xffcafaf2, 0xff000000
    };
    printf("Matriz 0:\n");
    input_values(matriz0);

    int matriz1[MATRIX_ROWS * MATRIX_COLS] = {
    0xff000000, 0xff7af8e3, 0xff7af8e3, 0xff000000, 0xff000000, 
    0xff000000, 0xff000000, 0xff7af8e3, 0xff000000, 0xff000000, 
    0xff000000, 0xff000000, 0xff7af8e3, 0xff000000, 0xff000000, 
    0xff000000, 0xff000000, 0xff7af8e3, 0xff000000, 0xff000000, 
    0xff000000, 0xff7af8e3, 0xff7af8e3, 0xff7af8e3, 0xff000000
    };
    printf("Matriz 1:\n");
    input_values(matriz1);

    int matriz2[MATRIX_ROWS * MATRIX_COLS] = {
    0xff000000, 0xff00e7ff, 0xff00e7ff, 0xff00e7ff, 0xff000000, 
    0xff000000, 0xff000000, 0xff000000, 0xff00e7ff, 0xff000000, 
    0xff000000, 0xff00e7ff, 0xff00e7ff, 0xff00e7ff, 0xff000000, 
    0xff000000, 0xff00e7ff, 0xff000000, 0xff000000, 0xff000000, 
    0xff000000, 0xff00e7ff, 0xff00e7ff, 0xff00e7ff, 0xff000000
};
printf("Matriz 2:\n");
input_values(matriz2);

int matriz3[MATRIX_ROWS * MATRIX_COLS] = {
    0xff000000, 0xff00ff85, 0xff00ff85, 0xff00ff85, 0xff000000, 
    0xff000000, 0xff000000, 0xff000000, 0xff00ff85, 0xff000000, 
    0xff000000, 0xff00ff85, 0xff00ff85, 0xff00ff85, 0xff000000, 
    0xff000000, 0xff000000, 0xff000000, 0xff00ff85, 0xff000000, 
    0xff000000, 0xff00ff85, 0xff00ff85, 0xff00ff85, 0xff000000
};
printf("Matriz 3:\n");
input_values(matriz3);

int matriz4[MATRIX_ROWS * MATRIX_COLS] = {
    0xff000000, 0xff3aff00, 0xff000000, 0xff3aff00, 0xff000000, 
    0xff000000, 0xff3aff00, 0xff000000, 0xff3aff00, 0xff000000, 
    0xff000000, 0xff3aff00, 0xff3aff00, 0xff3aff00, 0xff000000, 
    0xff000000, 0xff000000, 0xff000000, 0xff3aff00, 0xff000000, 
    0xff000000, 0xff000000, 0xff000000, 0xff3aff00, 0xff000000
};
printf("Matriz 4:\n");
input_values(matriz4);

int matriz5[MATRIX_ROWS * MATRIX_COLS] = {
    0xff000000, 0xffabff00, 0xffabff00, 0xffabff00, 0xff000000, 
    0xff000000, 0xffabff00, 0xff000000, 0xff000000, 0xff000000, 
    0xff000000, 0xffabff00, 0xffabff00, 0xffabff00, 0xff000000, 
    0xff000000, 0xff000000, 0xff000000, 0xffabff00, 0xff000000, 
    0xff000000, 0xffabff00, 0xffabff00, 0xffabff00, 0xff000000
};
printf("Matriz 5:\n");
input_values(matriz5);

int matriz6[MATRIX_ROWS * MATRIX_COLS] = {
    0xff000000, 0xffffcc00, 0xffffcc00, 0xffffcc00, 0xff000000, 
    0xff000000, 0xffffcc00, 0xff000000, 0xff000000, 0xff000000, 
    0xff000000, 0xffffcc00, 0xffffcc00, 0xffffcc00, 0xff000000, 
    0xff000000, 0xffffcc00, 0xff000000, 0xffffcc00, 0xff000000, 
    0xff000000, 0xffffcc00, 0xffffcc00, 0xffffcc00, 0xff000000
};
printf("Matriz 6:\n");
input_values(matriz6);

int matriz7[MATRIX_ROWS * MATRIX_COLS] = {
    0xff000000, 0xffb10a18, 0xffb10a18, 0xffb10a18, 0xff000000, 
    0xff000000, 0xff000000, 0xff000000, 0xffb10a18, 0xff000000, 
    0xff000000, 0xff000000, 0xff000000, 0xffb10a18, 0xff000000, 
    0xff000000, 0xff000000, 0xff000000, 0xffb10a18, 0xff000000, 
    0xff000000, 0xff000000, 0xff000000, 0xffb10a18, 0xff000000
};
printf("Matriz 7:\n");
input_values(matriz7);

int matriz8[MATRIX_ROWS * MATRIX_COLS] = {
    0xff000000, 0xffb10a69, 0xffb10a69, 0xffb10a69, 0xff000000, 
    0xff000000, 0xffb10a69, 0xff000000, 0xffb10a69, 0xff000000, 
    0xff000000, 0xffb10a69, 0xffb10a69, 0xffb10a69, 0xff000000, 
    0xff000000, 0xffb10a69, 0xff000000, 0xffb10a69, 0xff000000, 
    0xff000000, 0xffb10a69, 0xffb10a69, 0xffb10a69, 0xff000000
};
printf("Matriz 8:\n");
input_values(matriz8);

int matriz9[MATRIX_ROWS * MATRIX_COLS] = {
    0xff000000, 0xff330ab1, 0xff330ab1, 0xff330ab1, 0xff000000, 
    0xff000000, 0xff330ab1, 0xff000000, 0xff330ab1, 0xff000000, 
    0xff000000, 0xff330ab1, 0xff330ab1, 0xff330ab1, 0xff000000, 
    0xff000000, 0xff000000, 0xff000000, 0xff330ab1, 0xff000000, 
    0xff000000, 0xff330ab1, 0xff330ab1, 0xff330ab1, 0xff000000
};
printf("Matriz 9:\n");
input_values(matriz9);
    
    return 0;
}