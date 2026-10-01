#ifndef INC_ARM_H_
#define INC_ARM_H_

#include <stdint.h>
#include "stm32h7xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

//extern UART_HandleTypeDef huart3;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim12;
extern TIM_HandleTypeDef htim13;
extern TIM_HandleTypeDef htim15;
extern TIM_HandleTypeDef htim23;
extern TIM_HandleTypeDef htim24;


// C 函數宣告

void arm_init(void);                        // init arm
void arm_timer_callback(void);              // arm timer callback
void arm_cascade_set_to_zero(void* pvParameters);         // set arm to zero position
void arm_homing(void);
void servo_moving(float *now,float target,float speed);
void sieve_mission_homing(void);
void fork_mission_homing(void);


extern volatile int lower_pwm;
extern volatile int upper_pwm;
extern volatile int intake_pwm;
extern volatile int fork_pwm;
extern volatile int sieve_pwm;

extern volatile int lower_cnt;
extern volatile int upper_cnt;
extern volatile int intake_cnt;
extern volatile int fork_cnt;
extern volatile int sieve_cnt;

extern volatile float lower_deg;
extern volatile float upper_deg;
extern volatile float intake_deg;

extern volatile float lower_test;
extern volatile float upper_test;
extern volatile float intake_test;
extern volatile float fork_test;
extern volatile float sieve_test;

extern volatile int servo1_gobilda_pulse;
extern volatile int servo2_wrist_deg;
extern volatile int servo3_claw_deg;
extern volatile int servo4_slewing_deg;
extern volatile int servo5_outside_deg;
extern volatile int servo6_inside_deg;
extern volatile int servo7_cascade_rotate;
extern volatile int servo8_cascade_lengthen;

extern volatile int roller_pwm;
extern volatile int roller_switch;

#ifdef __cplusplus
}

// C++ 標頭檔和類別定義
#include "UART_servo.h"

#endif /* __cplusplus */

#endif /* INC_ARM_H_ */
