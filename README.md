# 🚦 Projeto: Semáforo com Temporizador no Raspberry Pi Pico

## 📌 Descrição
Este projeto implementa um sistema de semáforo utilizando o microcontrolador **Raspberry Pi Pico** e a placa **BitDogLab**. Através de um **temporizador de repetição**, os LEDs RGB alternam entre as cores **vermelho, azul e verde** a cada **3 segundos**, simulando o funcionamento de um semáforo.

## 🎯 Objetivos
- Utilizar **timers repetitivos** para alternar entre os LEDs RGB.
- Manipular GPIOs do Raspberry Pi Pico.
- Aplicar conceitos de **tempo real** para controle de LEDs.

## 🛠️ Componentes Utilizados
- **Microcontrolador**: Raspberry Pi Pico (Placa BitDogLab)
- **LED RGB** (conectado às GPIOs 11, 12 e 13)
- **Linguagem**: C (Pico SDK)

## 🔌 Ligações dos Pinos
| Componente  | GPIO |
|------------|------|
| LED Azul   | 11   |
| LED Vermelho | 12   |
| LED Verde  | 13   |

## 📜 Funcionamento
1. O **LED vermelho** acende primeiro.
2. Após **3 segundos**, o LED vermelho apaga e o **LED azul acende**.
3. Após **3 segundos**, o LED azul apaga e o **LED verde acende**.
4. Após **3 segundos**, o LED verde apaga e o **LED vermelho acende novamente**, repetindo o ciclo.

## 🚀 Como Executar o Código
1. Clone este repositório ou copie o código para seu ambiente.
2. Compile o código utilizando o **Pico SDK**.
3. Transfira o arquivo **.uf2** gerado para a Raspberry Pi Pico.
4. Observe a alternância das cores no LED RGB.

## 📂 Estrutura do Projeto
```
/
├── src/
│   ├── main.c  # Código principal do projeto
│   ├── CMakeLists.txt  # Configuração do CMake para compilação
│
└── README.md  # Este arquivo com a documentação
```

## 🔧 Dependências
- **Raspberry Pi Pico SDK** (deve estar configurado no ambiente de desenvolvimento)
- **Compilador GCC ARM** para gerar o código binário

## 📑 Referências
- [Documentação oficial do Raspberry Pi Pico SDK](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)
- [GPIO e Temporizadores no RP2040](https://www.raspberrypi.com/documentation/microcontrollers/)



