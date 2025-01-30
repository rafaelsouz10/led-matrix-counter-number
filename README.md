## Sistema Integrado com Raspberry Pi Pico, 2 botões, matriz 5X5 de led RGB e um led RGB

---

## Descrição do Projeto

Projeto da atividade **EmbarcaTech**, Unidade 4, Capítulo 4, sobre interrupções em sistemas embarcados. O código controla uma **matriz de LEDs WS2812** para exibir números de 0 a 9, com interação por dois **botões (incremento e decremento)**. Um **LED RGB** (vermelho) pisca periodicamente 5 vezes por segundo, demonstrando o uso de interrupções e timers.

![image](https://github.com/user-attachments/assets/5ceb46ff-f0ff-4e1c-9532-17dc884a6ff9)


---

## Requisitos

- **Microcontrolador**: Raspberry Pi Pico ou Raspberry Pi Pico W (opcional)
- **Placa de Desenvolvimento:** BitDogLab (opcional).
- **Conta Criada no Wokwi Simulator**: [Wokwi](https://wokwi.com/).
- **Editor de Código**: Visual Studio Code (VS Code).
- **SDK do Raspberry Pi Pico** configurado no sistema.
- Ferramentas de build: **CMake** e **Ninja**.

---

## Instruções de Uso

### 1. Clone o Repositório

Clone o repositório para o seu computador:
```bash
git clone https://github.com/rafaelsouz10/led-matrix-animations.git
cd led-matrix-counter-number
code .
```
---

### 2. Instale as Dependências

Certifique-se de que o SDK do Raspberry Pi Pico está configurado corretamente no VS Code. As extensões recomendadas são:

- **C/C++** (Microsoft).
- **CMake Tools**.
- **Wokwi Simulator**.
- **Raspberry Pi Pico**.

---

### 3. Configure o VS Code

Abra o projeto no Visual Studio Code e siga as etapas abaixo:

1. Certifique-se de que as extensões mencionadas anteriormente estão instaladas.
2. No terminal do VS Code, compile o código clicando em "Compile Project" na interface da extensão do Raspberry Pi Pico.
3. O processo gerará o arquivo `.uf2` necessário para a execução no hardware real.

---

### 4. Teste no Simulador Wokwi Integrado ao VS Code

Após ter configurado o VS Code conforme descrito no item 3, siga os passos abaixo para simular o projeto:

1. Abra o arquivo `diagram.json` no Visual Studio Code.
2. Clique no botão "Play" disponível na interface.
3. Divirta-se interagindo com os componentes disponíveis no simulador integrado!

---

### 5. Teste no Hardware Real

#### Utilizando a Placa de Desenvolvimento BitDogLab com Raspberry Pi Pico W:

1. Conecte a placa ao computador no modo BOTSEEL:
   - Pressione o botão **BOOTSEL** (localizado na parte de trás da placa de desenvolvimento) e, em seguida, o botão **RESET** (localizado na frente da placa).
   - Após alguns segundos, solte o botão **RESET** e, logo depois, solte o botão **BOOTSEL**.
   - A placa entrará no modo de programação.

2. Compile o projeto no VS Code utilizando a extensão do [Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico):
   - Clique em **Compile Project**.

3. Execute o projeto clicando em **Run Project USB**, localizado abaixo do botão **Compile Project**.

---

### 6. Conexões e Esquemático

Abaixo está o mapeamento de conexões entre os componentes e a Raspberry Pi Pico W da placa BitDogLab:


   |     **Componentes**     |        **Pino Conectacos (GPIO)**       |
   |-------------------------|-----------------------------------------|
   | Matriz de LEDs Neopixel | GPIO 7                                  |
   | Botão A (Amarelo)       | GPIO 5                                  |
   | Botão B (Cinza)         | GPIO 6                                  |
   | LED RGB Vermelho        | GPIO 13                                 |

---

### 7. Funcionamento do Sistema

   1. **Botões de Controle**: Dois botões físicos (Botão A e Botão B) conectados à Raspberry Pi Pico W permitem interações e controle do sistema.
   
   2. **Matriz de LEDs Neopixel 5x5**: Utilizada para exibir animações de 0 a 9.
   
   3. **LED RGB**: com o led vermelho sendo piscado 5 vezes por segundo.
   

#### Funcionalidades Implementadas

   1. **Botão A (GPIO 5)**: Decrementa de 9 a 0 e acionando a animação respectiva na matriz de LEDs.

   2. **Botão B (GPIO 6)**: Incrementa de 0 a 9 e acionando a animação respectiva na matriz de LEDs.

   3. **LED RGB RED** (GPIO 13)**: pisca periodicamente 5 vezes por segundo, demonstrando o uso de interrupções e timers.

--- 
### 8. Vídeo Demonstrativo

O vídeo será adicionado aqui
