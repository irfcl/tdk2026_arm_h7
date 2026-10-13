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
void mission_2(void *pvParameters);
void mission_200(void *pvParameters); //篩網下+掃蛤蜊
void mission_210(void *pvParameters); //鏡像 200
void mission_201(void *pvParameters); //不掃蛤蜊
void mission_202(void *pvParameters); //扣篩網
void mission_203(void *pvParameters); //翻篩網
void mission_204(void *pvParameters); //放篩網
void mission_3(void *pvParameters);
void mission_301(void *pvParameters); //稻草捲1-4
void mission_302(void *pvParameters);
void mission_303(void *pvParameters);
void mission_304(void *pvParameters);
void mission_300(void *pvParameters); //四根後轉下
void mission_305(void *pvParameters); //稻草捲5-8
void mission_306(void *pvParameters);
void mission_307(void *pvParameters);
void mission_308(void *pvParameters);
void mission_309(void *pvParameters); //X
void mission_310(void *pvParameters); //X
void mission_311(void *pvParameters); //集滿後抬起
void mission_312(void *pvParameters); //集滿後放下
void mission_399(void *pvParameters); //給intake來一拳
void mission_99(void *pvParameters);  //手臂歸零
void mission_91(void *pvParameters);  //篩網歸零
void mission_92(void *pvParameters);  //叉子歸零
void mission_991(void *pvParameters); //所有歸零(lower=0或靠叉子
void mission_992(void *pvParameters); //所有歸零(lower靠intake
void mission_967(void *pvParameters); //intake線鬆開
void mission_976(void *pvParameters); //收起intake




#ifdef __cplusplus
}
#endif

#endif // UROS_MISSION_HPP
