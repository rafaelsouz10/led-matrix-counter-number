#include <stdio.h>
#include "pico/stdlib.h"
#include "include/matriz_led.h"
#include "include/count-number.h"

#include "hardware/timer.h"

//definição de GPIO
#define LED_RED 11
#define LED_GREEN 12
#define LED_BLUE 13
#define TEMPO_LED 100
#define BTN_A 5
#define BTN_B 6

// Variáveis globais
static volatile uint32_t last_time = 0; // Armazena o tempo do último evento (em microssegundos)
static int number_control = 0;
volatile bool BTN_A_PRESSIONADO = false;
volatile bool BTN_B_PRESSIONADO = false;

// Configuração inicial ds botões
void setup_gpio_buttons() {
  //Botão A
  gpio_init(BTN_A);
  gpio_set_dir(BTN_A, GPIO_IN);
  gpio_pull_up(BTN_A);

  //Botão B
  gpio_init(BTN_B);
  gpio_set_dir(BTN_B, GPIO_IN);
  gpio_pull_up(BTN_B);
}

// Função de interrupção com debouncing
void gpio_irq_handler(uint gpio, uint32_t events){
  // Obtém o tempo atual em microssegundos
  uint32_t current_time = to_us_since_boot(get_absolute_time());
  
  // Verifica se passou tempo suficiente desde o último evento
  if (current_time - last_time > 200000) { // 200 ms de debouncing
    last_time = current_time; // Atualiza o tempo do último evento
    printf("Botão pressionado!");
    BTN_A_PRESSIONADO = true;
  }
}


int main() {

  stdio_init_all(); // Inicializa entradas e saídas.  
  npInit(LED_PIN); // Inicializa matriz de LEDs NeoPixel.

  gpio_init(LED_RED);
  gpio_set_dir(LED_RED, GPIO_OUT);

  setup_gpio_buttons(); // Configuração inicial ds botões

  // Configuração da interrupção com callback
    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

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
