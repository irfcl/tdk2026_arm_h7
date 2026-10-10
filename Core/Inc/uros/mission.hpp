#ifndef UROS_MISSION_HPP
#define UROS_MISSION_HPP

#ifdef __cplusplus
extern "C" {
#endif

// Include statements
//0724
typedef enum
{
    ARM_MANUAL = 0,
    ARM_MISSION
} ArmMode;
//
extern volatile ArmMode arm_mode;

extern int mission_type;
extern int prev_mission_type;
extern int mission_status;
extern int task_created;
extern int mission_3_task;
extern int getRoll_triggered;

void mission_init(void);
void mission_ctrl(void);
void mission_301(void *pvParameters);
void mission_2(void *pvParameters);
void mission_200(void *pvParameters);
void mission_210(void *pvParameters);
void mission_201(void *pvParameters);
void mission_202(void *pvParameters);
void mission_203(void *pvParameters);
void mission_204(void *pvParameters);
void mission_3(void *pvParameters);
void mission_301(void *pvParameters);
void mission_302(void *pvParameters);
void mission_303(void *pvParameters);
void mission_304(void *pvParameters);
void mission_300(void *pvParameters);
void mission_305(void *pvParameters);
void mission_306(void *pvParameters);
void mission_307(void *pvParameters);
void mission_308(void *pvParameters);
void mission_309(void *pvParameters);
void mission_310(void *pvParameters);
void mission_311(void *pvParameters);
void mission_312(void *pvParameters);
void mission_99(void *pvParameters);
void mission_91(void *pvParameters);
void mission_92(void *pvParameters);



#ifdef __cplusplus
}
#endif

#endif // UROS_MISSION_HPP
