#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/timer.h"

#define LED_PIN_RED 12
#define LED_PIN_GREEN 13
#define LEND_PIN_YELLOW 11
#define TEMPO 3000  // Tempo do semáforo em ms

int estado = 0;  // Estado do semáforo (0 = vermelho, 1 = verde, 2 = azul)

bool repeating_timer_callback_semaforo(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de ligar o próximo
    gpio_put(LED_PIN_RED, 0);
    gpio_put(LED_PIN_GREEN, 0);
    gpio_put(LEND_PIN_YELLOW, 0);

    // Alterna os LEDs conforme o estado
    if (estado == 0) {
        gpio_put(LED_PIN_RED, 1);  // Liga vermelho
        estado = 1;  // Próximo: verde
    } else if (estado == 1) {
        gpio_put(LEND_PIN_YELLOW, 1); // Liga azul
        estado = 2;  // Próximo: verde
    } else {
        gpio_put(LED_PIN_GREEN, 1); // Liga verde
        estado = 0;  // Próximo: vermelho
    }
    return true;  // Continua repetindo
}

int main() {
    stdio_init_all();

    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);

    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    gpio_init(LEND_PIN_YELLOW);
    gpio_set_dir(LEND_PIN_YELLOW, GPIO_OUT);

    struct repeating_timer timer;
    
    add_repeating_timer_ms(TEMPO, repeating_timer_callback_semaforo, NULL, &timer);
    
    while (true) {
        printf("Sistema funcionando...\n");
        sleep_ms(1000);
    }
    
    return 0;
}