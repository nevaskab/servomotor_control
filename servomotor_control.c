#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22

//Descomente a linha abaixo e comente a linha acima que contém a porta 22 para testar utilizando a porta 12 da GPIO que é referente ao LED AZUL

//#define SERVO_PIN 12

#define WRAP_VALUE 25000
#define PULSO_ANGULO_180 1920 //usando esse valor, ao entrar na fórmula o valor atual de microsegundos torna-se 2400
#define PULSO_ANGULO_90 1190 //usando esse valor, ao entrar na fórmula o valor atual de microsegundos torna-se 1470
#define PULSO_ANGULO_0 400 //usando esse valor, ao entrar na fórmula o valor atual de microsegundos torna-se 500

#define SMOOTH_MOVE_STEP 5
#define SMOOTH_MOVE_DELAY 10

void set_servo_angle(uint gpio, uint16_t pulso){
    uint slice_num = pwm_gpio_to_slice_num(gpio);

    uint16_t level = (pulso * WRAP_VALUE) / 20000;
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(gpio), level);
}

void init_all_pins(){
    stdio_init_all();

    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    pwm_set_wrap(slice_num, WRAP_VALUE);
    pwm_set_clkdiv(slice_num, 125.0f);
    pwm_set_enabled(slice_num, true);
}

//função que define o movimento suave do servomotor
void move_smoothly(uint gpio, float pulso_inicial, float pulso_final, int step, int delay_ms){
    if (pulso_inicial < pulso_final) {
        for (uint16_t pulso = pulso_inicial; pulso <= pulso_final; pulso += step){
            set_servo_angle(gpio, pulso);
            sleep_ms(delay_ms);
        }
    }
    else {
        for (uint16_t pulso = pulso_inicial; pulso >= pulso_final; pulso -= step){
            set_servo_angle(gpio, pulso);
            sleep_ms(delay_ms);
        }
    }
}

int main() {
    init_all_pins();

    //0°
    set_servo_angle(SERVO_PIN, PULSO_ANGULO_0);
    sleep_ms(5000);

    //90°
    set_servo_angle(SERVO_PIN, PULSO_ANGULO_90);
    sleep_ms(5000);

    //180°
    set_servo_angle(SERVO_PIN, PULSO_ANGULO_180);
    sleep_ms(5000);

    while (true) {

        //sai de 180° para 0 suavemente
        move_smoothly(SERVO_PIN, PULSO_ANGULO_180, PULSO_ANGULO_0, SMOOTH_MOVE_STEP, SMOOTH_MOVE_DELAY);

        //sai de 0° para 180° suavemente
        move_smoothly(SERVO_PIN, PULSO_ANGULO_0, PULSO_ANGULO_180, SMOOTH_MOVE_STEP, SMOOTH_MOVE_DELAY);
    }
}
