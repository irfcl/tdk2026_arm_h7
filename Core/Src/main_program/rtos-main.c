/*stm32 include*/
#include "stm32h723xx.h"
#include "stm32h7xx_hal.h"
#include "cmsis_os.h"

#include "timers.h"
#include "uros/uros_init.h"
#include "Control_Lib/arm/Inc/arm.h"
#include "uros/mission_ctrl.h"

extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim6;


uint16_t adcRead[7] = {0};

extern int code;
double LastCNT = 0;
double CNT = 500;
int pulse =0;
int currentsp = 0;
int sec = 0;
int sec_x1= 0;

void StartDefaultTask_rtos(void *argument)
{
//	arm_init();
	HAL_TIM_Base_Start_IT(&htim7);
	uros_init();
	arm_init();

    for(;;){
        uros_agent_status_check();
		//0710測試
		mission_set();
		mission_ctrl();
		//
        osDelay(50);
		currentsp ++;
    }
}

void HAL_TIM_PeriodElapsedCallback_rtos(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */
	if (htim->Instance == TIM7)
	{
		arm_timer_callback();
		send_mission();
		reset_x1();
		sec ++;
		sec_x1++;
	}
  /* USER CODE END Callback 0 */
	if (htim->Instance == TIM6)
	{
		HAL_IncTick();
	}
  /* USER CODE BEGIN Callback 1 */
  /* USER CODE END Callback 1 */
}

// ==========================================
// micro-ROS 系統層與原子操作模擬補丁 (終極合體版)
// ==========================================
#include <sys/time.h>
#include <unistd.h>
#include <stdint.h>
#include "cmsis_os.h"
#include "stm32h7xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

// ===== 1. POSIX 時間函數模擬 =====

int _gettimeofday(struct timeval *tv, void *tzvp) {
    (void)tzvp;
    uint32_t ticks = osKernelGetTickCount(); // 取得 FreeRTOS 毫秒數
    tv->tv_sec = ticks / 1000;
    tv->tv_usec = (ticks % 1000) * 1000;
    return 0;
}

int usleep(useconds_t usec) {
    uint32_t ms = usec / 1000;
    // 確保即使延遲小於 1ms，也會讓出一次 CPU 執行權
    osDelay(ms > 0 ? ms : 1);
    return 0;
}

// ===== 2. GCC 原子操作模擬 =====

void __sync_synchronize(void) {
    __asm__ volatile ("dmb sy" ::: "memory");
}

uint32_t __atomic_exchange_4(volatile void *ptr, uint32_t val, int memorder) {
    uint32_t old;
    uint32_t primask = __get_PRIMASK();
    __disable_irq();
    old = *(volatile uint32_t *)ptr;
    *(volatile uint32_t *)ptr = val;
    if (!primask) __enable_irq();
    return old;
}

uint64_t __atomic_load_8(const volatile void *ptr, int memorder) {
    uint64_t val;
    uint32_t primask = __get_PRIMASK();
    __disable_irq();
    val = *(const volatile uint64_t *)ptr;
    if (!primask) __enable_irq();
    return val;
}

void __atomic_store_8(volatile void *ptr, uint64_t val, int memorder) {
    uint32_t primask = __get_PRIMASK();
    __disable_irq();
    *(volatile uint64_t *)ptr = val;
    if (!primask) __enable_irq();
}

uint64_t __atomic_exchange_8(volatile void *ptr, uint64_t val, int memorder) {
    uint64_t old;
    uint32_t primask = __get_PRIMASK();
    __disable_irq();
    old = *(volatile uint64_t *)ptr;
    *(volatile uint64_t *)ptr = val;
    if (!primask) __enable_irq();
    return old;
}

uint64_t __atomic_fetch_add_8(volatile void *ptr, uint64_t val, int memorder) {
    uint64_t old;
    uint32_t primask = __get_PRIMASK();
    __disable_irq();
    old = *(volatile uint64_t *)ptr;
    *(volatile uint64_t *)ptr = old + val;
    if (!primask) __enable_irq();
    return old;
}

#ifdef __cplusplus
}
#endif
// ==========================================

#ifdef __cplusplus
}
#endif
