#include <stdio.h>
#include "pico/stdlib.h"
#include "include/matriz_led.h"
#include "include/config_btn.h"
#include "include/count_number.h"

//definição de GPIO LEDS
#define LED_RED 13
#define LED_GREEN 12
#define LED_BLUE 11

// Variáveis globais
int number_control = -1;

void setup_gpio_leds(){

  gpio_init(LED_RED);
  gpio_set_dir(LED_RED, GPIO_OUT);
  gpio_init(LED_GREEN);
  gpio_set_dir(LED_GREEN, GPIO_OUT);
  gpio_init(LED_BLUE);
  gpio_set_dir(LED_BLUE, GPIO_OUT);
}

//Led vermelho piscando 5 vezes por segundo com tempo_led = 100
void blink_led(int tempo_led){
  gpio_put(LED_RED, true);
  sleep_ms(tempo_led);
  gpio_put(LED_RED, false);
  sleep_ms(tempo_led);
}

int main() {

  stdio_init_all(); // Inicializa entradas e saídas.  
  npInit(LED_PIN); // Inicializa matriz de LEDs NeoPixel.

  setup_gpio_buttons(); // Configuração inicial ds botões

  setup_gpio_leds();  //Configuração incial dos leds

  gpio_set_irq_interrupt_btn();// Configuração da interrupção com callback para botão

  while (true) {
    if (BTN_A_PRESSIONADO) {
      if (number_control > 0) number_control--;
      printf("number: %d\n", number_control);
      controle_numero(number_control);
      BTN_A_PRESSIONADO = false;
    }

    if (BTN_B_PRESSIONADO) {
      if (number_control < 9) number_control++;
      printf("number: %d\n", number_control);
      controle_numero(number_control);
      BTN_B_PRESSIONADO = false;
    }

    blink_led(100); //led ligado a 100ms e desligado em 100ms, piscando 5 vezes por segundo
  }
}
