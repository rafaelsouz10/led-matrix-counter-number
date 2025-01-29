#ifndef CONFIG_BTN_H
#define CONFIG_BTN_H

#include "hardware/timer.h"

//definição de GPIO botões
#define BTN_A 5
#define BTN_B 6

// Variáveis globais 
static volatile uint32_t last_time_A = 0;// Armazena o tempo do último evento (em microssegundos)
static volatile uint32_t last_time_B = 0;
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

// Função de interrupção com debouncing do botão
void gpio_irq_handler(uint gpio, uint32_t events){

  // Obtém o tempo atual em microssegundos
  uint32_t current_time = to_us_since_boot(get_absolute_time());
  
  // Verifica se passou tempo suficiente desde o último evento
  if (current_time - last_time_A > 300000) { // 200 ms de debouncing
    last_time_A = current_time; // Atualiza o tempo do último evento

    if (gpio == BTN_A) {
      printf("Botão A pressionado! ");
      BTN_A_PRESSIONADO = true;
    } else if (gpio == BTN_B ) { // 200 ms de debouncing
      printf("Botão B pressionado! ");
      BTN_B_PRESSIONADO = true;
    }

  // if (gpio == BTN_A && current_time - last_time_A > 300000) { // 200 ms de debouncing
  //   last_time_A = current_time; // Atualiza o tempo do último evento

  //   printf("Botão A pressionado! ");
  //   BTN_A_PRESSIONADO = true;

  // } else if (gpio == BTN_B && current_time - last_time_B > 300000) { // 200 ms de debouncing
  //   last_time_B = current_time; // Atualiza o tempo do último evento
  //   printf("Botão B pressionado! ");
  //   BTN_B_PRESSIONADO = true;
  // }
  }
}

void gpio_set_irq_interrupt_btn(){
    // Configuração da interrupção com callback para botão A
    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    // Configuração da interrupção com callback para botão B
    gpio_set_irq_enabled_with_callback(BTN_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
}

#endif