#include "arm.h"
#include "math.h"
#include "UART_servo.h"
#include "stm32h7xx_hal.h"
#include "motor_monitor.hpp"
#include "motor_ctrl.hpp"
#include "cmsis_os.h"
#include <stdint.h>
#include <stdbool.h>
#include "../../../../Inc/uros/mission_ctrl.h"

int mis_set_time = 0;
int x1_reset_time = 0;
extern bool x1_reset_flag;
extern int sec;												// 在 rtos-main.c 中定義的時間計數器
extern int sec_x1;

JointMotor_polulu sieve_joint(&htim5, &htim23, TIM_CHANNEL_1, GPIOG, GPIO_PIN_0);
JointMotor_polulu fork_joint(&htim3, &htim23, TIM_CHANNEL_2, GPIOG, GPIO_PIN_1);
JointMotor_polulu intake_joint(&htim4, &htim23, TIM_CHANNEL_3, GPIOG, GPIO_PIN_2);
JointMotor_polulu upper_joint(&htim8, &htim23, TIM_CHANNEL_4, GPIOG, GPIO_PIN_3);
JointMotor_polulu lower_joint(&htim1, &htim13, TIM_CHANNEL_1, GPIOG, GPIO_PIN_4);

volatile int lower_pwm = 0;
volatile int upper_pwm = 0;
volatile int intake_pwm = 0;
volatile int fork_pwm = 0;
volatile int sieve_pwm = 0;

volatile int lower_cnt = 0;
volatile int upper_cnt = 0;
volatile int intake_cnt = 0;
volatile int fork_cnt = 0;
volatile int sieve_cnt = 0;

volatile float lower_deg = 0;
volatile float upper_deg = 0;
volatile float intake_deg = 0;
volatile float fork_deg = 0;
volatile float sieve_deg = 0;

volatile float lower_test = 0;
volatile float upper_test = 0;
volatile float intake_test = 0;
volatile float fork_test = 0;
volatile float sieve_test = 0;

volatile int servo1_gobilda_pulse = 1000;
volatile int servo2_wrist_deg = 54;
volatile int servo3_claw_deg = 80;
volatile int servo4_slewing_deg = 720;
volatile int servo5_outside_deg = 30;
volatile int servo6_inside_deg = 150;
volatile int servo7_cascade_rotate = 590;
volatile int servo8_cascade_lengthen = 90;

volatile int roller_pwm = 0;

volatile bool lower_homing = false;
volatile bool upper_homing = false;
volatile bool intake_homing = false;
volatile bool fork_homing = false;
volatile bool sieve_homing = false;

void arm_init(void) {
    lower_joint.init();
    lower_joint.stop();
    upper_joint.init();
    upper_joint.stop();
    intake_joint.init();
    intake_joint.stop();
    fork_joint.init();
    fork_joint.stop();
    sieve_joint.init();
    sieve_joint.stop();

    HAL_TIM_PWM_Start(&htim24, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim24, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim24, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim24, TIM_CHANNEL_4);

    HAL_TIM_PWM_Start(&htim15, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim15, TIM_CHANNEL_2);

    HAL_TIM_PWM_Start(&htim12, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim12, TIM_CHANNEL_2);

    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_RESET);
}


void arm_timer_callback(void) {							// constantly run the servo in timer callback
	lower_cnt = lower_joint.getCount();
	upper_cnt = upper_joint.getCount();
	intake_cnt = intake_joint.getCount();
	fork_cnt = fork_joint.getCount();
	sieve_cnt = sieve_joint.getCount();

	lower_deg = lower_joint.getAngle();
	upper_deg = upper_joint.getAngle();
	intake_deg = intake_joint.getAngle();
	fork_deg = fork_joint.getAngle();
	sieve_deg = sieve_joint.getAngle();

//	lower_joint.setPWM(lower_pwm);
//	upper_joint.setPWM(upper_pwm);
//	intake_joint.setPWM(intake_pwm);

//    lower_joint.setTarget(lower_test);
//    upper_joint.setTarget(upper_test);
//    intake_joint.setTarget(intake_test);
//
//	lower_joint.update();
//	upper_joint.update();
//	intake_joint.update();

	if(lower_homing){
	    lower_joint.setPWM(-250);     // 朝Home方向慢慢跑
	}
	else{
	    lower_joint.setTarget(lower_test);
	    lower_joint.update();
	}

	if(upper_homing){
	    upper_joint.setPWM(250);
	}
	else{
	    upper_joint.setTarget(upper_test);
	    upper_joint.update();
	}

	if(intake_homing){
	    intake_joint.setPWM(-250);
	}
	else{
	    intake_joint.setTarget(intake_test);
	    intake_joint.update();
	}

	if(fork_homing){
	    fork_joint.setPWM(600);
	}
	else{
	    fork_joint.setTarget(fork_test);
	    fork_joint.update();
	}

	if(sieve_homing){
	    sieve_joint.setPWM(600);
	}
	else{
	    sieve_joint.setTarget(sieve_test);
	    sieve_joint.update();
	}

    __HAL_TIM_SET_COMPARE(&htim24, TIM_CHANNEL_1, servo1_gobilda_pulse);
    __HAL_TIM_SET_COMPARE(&htim24, TIM_CHANNEL_2, 500 + ((int32_t)servo2_wrist_deg * 2000 / 180));
    __HAL_TIM_SET_COMPARE(&htim24, TIM_CHANNEL_3, 500 + ((int32_t)servo3_claw_deg * 2000 / 300));
    __HAL_TIM_SET_COMPARE(&htim24, TIM_CHANNEL_4, servo4_slewing_deg);

    __HAL_TIM_SET_COMPARE(&htim15, TIM_CHANNEL_1, 500 + ((int32_t)servo5_outside_deg * 2000 / 180));
    __HAL_TIM_SET_COMPARE(&htim15, TIM_CHANNEL_2, 500 + ((int32_t)servo6_inside_deg * 2000 / 180));

    __HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_1, servo7_cascade_rotate);
    __HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_2, 500 + ((int32_t)servo8_cascade_lengthen * 2000 / 180));

    if(roller_pwm>0){
    	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
    	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);
    }
    else if(roller_pwm<0){
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);
    }
    else{
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);
    }
}

volatile int roller_switch = 0;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_13 && lower_homing){
        lower_joint.stop();
        lower_joint.zero();
        lower_test = 0;
        lower_homing = false;
    }

    else if(GPIO_Pin == GPIO_PIN_0 && upper_homing){
        upper_joint.stop();
        upper_joint.zero();
        upper_test = 0;
        upper_homing = false;
    }

    else if(GPIO_Pin == GPIO_PIN_3 && fork_homing){
        fork_joint.stop();
        fork_joint.zero();
        fork_test = 0;
        fork_homing = false;
    }

    else if(GPIO_Pin == GPIO_PIN_2 && sieve_homing){
        sieve_joint.stop();
        sieve_joint.zero();
        sieve_test = 0;
        sieve_homing = false;
    }

    else if(GPIO_Pin == GPIO_PIN_1){
        intake_joint.stop();
        intake_joint.zero();
        intake_test = 0;
        intake_homing = false;
        roller_switch++;
    }
}

void arm_homing(void)
{
    lower_homing = true;
    upper_homing = true;
}

void sieve_mission_homing(void)
{
    sieve_homing = true;
}

void fork_mission_homing(void)
{
    fork_homing = true;
}
