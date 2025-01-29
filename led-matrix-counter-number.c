#include <stdio.h>
#include "pico/stdlib.h"
#include "include/matriz_led.h"
#include "include/count_number.h"
#include "include/config_btn.h"

//definição de GPIO
#define LED_RED 11
#define LED_GREEN 12
#define LED_BLUE 13
#define TEMPO_LED 100

// Variáveis globais
static int number_control = 0;


int main() {

  stdio_init_all(); // Inicializa entradas e saídas.  
  npInit(LED_PIN); // Inicializa matriz de LEDs NeoPixel.

  gpio_init(LED_RED);
  gpio_set_dir(LED_RED, GPIO_OUT);

  setup_gpio_buttons(); // Configuração inicial ds botões

  gpio_set_irq_interrupt_btn();// Configuração da interrupção com callback para botão

  while (true) {
    if (BTN_A_PRESSIONADO) {
      count_number_09(1000);
      
      BTN_A_PRESSIONADO = false;
      number_control++;
    }

    gpio_put(LED_RED, true);
    sleep_ms(TEMPO_LED);
    gpio_put(LED_RED, false);
    sleep_ms(TEMPO_LED);
  }
}
