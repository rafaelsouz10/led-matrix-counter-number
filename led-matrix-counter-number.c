#include <stdio.h>
#include "pico/stdlib.h"
#include "include/matriz_led.h"
#include "include/count-number.h"

int main() {

  stdio_init_all(); // Inicializa entradas e saídas.  
  npInit(LED_PIN); // Inicializa matriz de LEDs NeoPixel.

  npWrite(); // Escreve os dados nos LEDs.

  while (true) {
    count_number_09(1000);
  }
}
