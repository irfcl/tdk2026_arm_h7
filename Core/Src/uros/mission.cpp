#include "mission.hpp"
#include "arm.h"
#include "cmsis_os.h"
#include "motor_ctrl.hpp"

int mission_type = 0;
int prev_mission_type = 0;
int mission_status = 0;
int task_created = 0;

int mission_3_task = 301;

//0724
volatile ArmMode arm_mode = ARM_MISSION;
//

//0728
extern volatile bool lower_homing;
extern volatile bool upper_homing;
extern volatile bool intake_homing;
extern volatile bool fork_homing;
extern volatile bool sieve_homing;

extern JointMotor_polulu lower_joint;
extern JointMotor_polulu upper_joint;
extern JointMotor_polulu intake_joint;
extern JointMotor_polulu fork_joint;
extern JointMotor_polulu sieve_joint;

void mission_init(void)
{
    arm_init();
}

void mission_ctrl(void)
{
//    if (prev_mission_type == mission_type)
//        return;
//
//    prev_mission_type = mission_type;

    if (task_created)
        return;

    if(mission_type == 0)
            return;

    if (mission_type == 3) {
            mission_type = mission_3_task;
            if (mission_3_task < 310) {
                mission_3_task++;
            } else {
                mission_3_task = 301;
            }
        }

        BaseType_t ret;

    task_created = 1;

    switch (mission_type){

//    case 3:
//    	arm_mode = ARM_MISSION;
//    	ret = xTaskCreate(mission_3, "mission_3", 512, NULL, 2, NULL);
//    	if(ret != pdPASS)
//    	{
//    	    task_created = -1;
//    	}
//    	break;

//    BaseType_t ret;
    case 301:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_301, "mission_301", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 302:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_302, "mission_302", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 303:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_303, "mission_303", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 304:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_304, "mission_304", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 305:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_305, "mission_305", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 306:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_306, "mission_306", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 307:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_307, "mission_307", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 308:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_308, "mission_308", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 309:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_309, "mission_309", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 310:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_310, "mission_310", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 300:
		arm_mode = ARM_MISSION;
		ret = xTaskCreate(mission_300, "mission_300", 512, NULL, 2, NULL);
		if(ret != pdPASS)
		{
			task_created = -1;
		}
		break;

    case 311:
		arm_mode = ARM_MISSION;
		ret = xTaskCreate(mission_311, "mission_311", 512, NULL, 2, NULL);
		if(ret != pdPASS)
		{
			task_created = -1;
		}
		break;

    case 312:
		arm_mode = ARM_MISSION;
		ret = xTaskCreate(mission_312, "mission_312", 512, NULL, 2, NULL);
		if(ret != pdPASS)
		{
			task_created = -1;
		}
		break;

    case 399:
		arm_mode = ARM_MISSION;
		ret = xTaskCreate(mission_399, "mission_399", 512, NULL, 2, NULL);
		if(ret != pdPASS)
		{
			task_created = -1;
		}
		break;

    case 2:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_2, "mission_2", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 200:
		arm_mode = ARM_MISSION;
		ret = xTaskCreate(mission_200, "mission_200", 512, NULL, 2, NULL);
		if(ret != pdPASS)
		{
			task_created = -1;
		}
		break;

    case 210:
		arm_mode = ARM_MISSION;
		ret = xTaskCreate(mission_210, "mission_210", 512, NULL, 2, NULL);
		if(ret != pdPASS)
		{
			task_created = -1;
		}
		break;

    case 201:
		arm_mode = ARM_MISSION;
		ret = xTaskCreate(mission_201, "mission_201", 512, NULL, 2, NULL);
		if(ret != pdPASS)
		{
			task_created = -1;
		}
		break;

    case 202:
		arm_mode = ARM_MISSION;
		ret = xTaskCreate(mission_202, "mission_202", 512, NULL, 2, NULL);
		if(ret != pdPASS)
		{
			task_created = -1;
		}
		break;

    case 203:
		arm_mode = ARM_MISSION;
		ret = xTaskCreate(mission_203, "mission_203", 512, NULL, 2, NULL);
		if(ret != pdPASS)
		{
			task_created = -1;
		}
		break;

    case 204:
		arm_mode = ARM_MISSION;
		ret = xTaskCreate(mission_204, "mission_204", 512, NULL, 2, NULL);
		if(ret != pdPASS)
		{
			task_created = -1;
		}
		break;

    case 99:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_99, "mission_99", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 91:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_91, "mission_91", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 92:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_92, "mission_92", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 991:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_991, "mission_991", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 992:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_992, "mission_992", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

    case 967:
		arm_mode = ARM_MISSION;
		ret = xTaskCreate(mission_967, "mission_967", 512, NULL, 2, NULL);
		if(ret != pdPASS)
		{
			task_created = -1;
		}
		break;

    case 976:
		arm_mode = ARM_MISSION;
		ret = xTaskCreate(mission_976, "mission_976", 512, NULL, 2, NULL);
		if(ret != pdPASS)
		{
			task_created = -1;
		}
		break;
    }
}

void readyForRoll() {
	mission_status = mission_type * 10 + 1;
	//初始
	upper_joint.setSpeedRatio(1);
    roller_switch =0;
    servo2_wrist_deg = 52;
    servo3_claw_deg = 100;
    servo4_slewing_deg = 734;
    upper_test = 0;
    lower_test = 0;
    roller_pwm = -500;
    osDelay(400);
    servo4_slewing_deg = 724;
    osDelay(200);
    roller_pwm = 0;
    osDelay(600);

    //往稻草卷伸
    lower_test = -95;
    osDelay(500);
    upper_test = -60;
    osDelay(2100);
    servo3_claw_deg = 120;
}

void getRoll() {
    upper_test = -75;
    lower_test = -105;
    osDelay(800);
    //roller_pwm = 0;
    //夾+抬
    servo3_claw_deg = 60;
	osDelay(500);
    lower_test = -30;
	osDelay(1200);
	//upper_test = 0;
	roller_pwm = 0;
	osDelay(1000);
	//橫放到對面叉子上
	//移動
	upper_test = -130;
	servo7_cascade_rotate = 620;
	osDelay(1000);
	servo2_wrist_deg = 105;
	osDelay(1000);
}

static void finishMission()
{
	arm_mode = ARM_MANUAL;
    mission_status = -mission_type;
    mission_type = 0;
    task_created = 0;
    vTaskDelete(NULL);
}

void mission_967(void *pvParameters) {
	mission_status = mission_type;
	reel_pwm =1;
	osDelay(1300);
	reel_pwm =0;

	finishMission();
}

void mission_976(void *pvParameters) {
	mission_status = mission_type;
	reel_pwm =-1;
	osDelay(2200);
	reel_pwm =0;

	finishMission();
}

void mission_991(void *pvParameters) {
	mission_status = mission_type;
	lower_test +=40;
	upper_test -=20;
	sieve_test -=10;
	fork_test -= 50;
	osDelay(2000);

	arm_homing();
	sieve_mission_homing();
	fork_mission_homing();
	while(lower_homing||upper_homing||sieve_homing||fork_homing){
		osDelay(20);
	}
	sieve_test = -5;
	finishMission();
}

void mission_992(void *pvParameters) {
	mission_status = mission_type;
	lower_switch =0;
	upper_test -=20;
	sieve_test -=10;
	fork_test -= 50;
	osDelay(2000);
	arm_homing();
	sieve_mission_homing();
	fork_mission_homing();
	while(lower_homing||upper_homing||sieve_homing||fork_homing){
		osDelay(20);
	}
	lower_test +=40;
	upper_test = -20;
	osDelay(1500);
	lower_switch = 67;
	arm_homing();
	while(lower_homing||upper_homing) {
		osDelay(20);
	}
	sieve_test = -5;
	lower_switch = 0;
	finishMission();
}

//homing
void mission_99(void *pvParameters)
{
    mission_status = mission_type;
    arm_homing();
    while(lower_homing || upper_homing){
        osDelay(20);
    }
    finishMission();
}

void mission_91(void *pvParameters)
{
    mission_status = mission_type;
    sieve_mission_homing();
    while(sieve_homing){
        osDelay(20);
    }
    sieve_test = -5;
    finishMission();
}

void mission_92(void *pvParameters)
{
    mission_status = mission_type;
    fork_mission_homing();
    while(fork_homing){
        osDelay(20);
    }
    finishMission();
}

const int sieve_horizontal = -108;
const int sieve_lifted = -83;

void mission_200(void *pvParameters) //篩子放低 掃
{
	mission_status = mission_type;
	servo7_cascade_rotate = 590;
	servo8_cascade_lengthen = 90;

	sieve_test = sieve_horizontal;
	osDelay(100);
	sieve_test = sieve_horizontal;
	osDelay(100);
	sieve_test = sieve_horizontal;
	osDelay(100);
	servo7_cascade_rotate = 690;
	servo5_outside_deg = 30;
	servo6_inside_deg = 150;
	osDelay(1000);
	for (int i =0; i <9; i++) {
		servo8_cascade_lengthen += 10;
	}

	finishMission();
}

void mission_210(void *pvParameters) //鏡像場地 篩子放低 掃
{
	mission_status = mission_type;
	servo7_cascade_rotate = 590;
	servo8_cascade_lengthen = 90;

	sieve_test = sieve_horizontal;
	osDelay(100);
	sieve_test = sieve_horizontal;
	osDelay(100);
	sieve_test = sieve_horizontal;
	osDelay(100);
	servo7_cascade_rotate = 690;
	servo5_outside_deg = 30;
	servo6_inside_deg = 150;
	osDelay(1000);
	for (int i =0; i <9; i++) {
		servo8_cascade_lengthen -= 10;
	}

	finishMission();
}

void mission_201(void *pvParameters) //掃的收起來
{
	mission_status = mission_type;
	servo7_cascade_rotate = 590;
	servo8_cascade_lengthen =90;
	osDelay(1000);
	finishMission();
}

void mission_202(void *pvParameters) //夾住篩網
{
	mission_status = mission_type;
	servo5_outside_deg = 180;
	servo6_inside_deg = 0;
	osDelay(2000);
	sieve_test = sieve_lifted;
	osDelay(1000);
	finishMission();
}

void mission_203(void *pvParameters) //翻篩網+搖晃
{
	mission_status = mission_type;
	sieve_test = 0;
	osDelay(2500);
	////搖晃
	//for (int i =0; i<2; i++) {
	//	sieve_test = -54;
	//	osDelay(2400);
	//	sieve_test = -4;
	//	osDelay(1200);
	//}
	sieve_test = sieve_horizontal;
	osDelay(100);
	sieve_test = sieve_horizontal;
	osDelay(100);
	sieve_test = sieve_horizontal;
	osDelay(100);
	osDelay(3500);
	sieve_test = sieve_lifted;
	osDelay(500);
	finishMission();
}

void mission_204(void *pvParameters)
{
	mission_status = mission_type;
	sieve_test = sieve_horizontal;
	osDelay(1000);
	servo5_outside_deg = 30;
	servo6_inside_deg = 150;
	finishMission();
}

//void mission_301(void *pvParameters)
//{
//	mission_status = mission_type;
//	readyForRoll();
//
//	roller_pwm = 750;
//	while (roller_switch <3) {
//		osDelay(10);
//	}
//	getRoll();
//
//	servo4_slewing_deg = 740;
//	osDelay(500);
//	upper_joint.setSpeedRatio(0.4);
//	upper_test = -180;
//	osDelay(3000);
//
//	//插入 0.4x speed
//	upper_test = -220;
//	osDelay(3500);
//	//放手
//	servo3_claw_deg = 80;
//	osDelay(1000);
//	for (int i=0; i<20; i++){
//		servo3_claw_deg++;
//		osDelay(100);
//	}
//
//	//抽離+回正
//	upper_joint.setSpeedRatio(1);
//	upper_test = -80;
//	osDelay(1000);
//	servo4_slewing_deg = 720;
//	servo2_wrist_deg = 52;
//	osDelay(1000);
//	servo3_claw_deg = 80;
//	upper_test = 0;
//	lower_test = 0;
//
//	osDelay(1000);
//	servo7_cascade_rotate = 590;
//
//	finishMission();
//}

void mission_301(void *pvParameters) //這個是optimized版
{
	mission_status = mission_type;
	roller_pwm = 1000;
	roller_switch =0;
	while (roller_switch <3) {
		osDelay(10);
	}
	readyForRoll();

	roller_pwm = 1000;
	while (roller_switch <3) {
		osDelay(10);
	}
	getRoll();

	servo4_slewing_deg = 740;
	osDelay(500);
	upper_joint.setSpeedRatio(0.8);
	upper_test = -180;
	osDelay(1500);

	//插入 0.8x speed
	upper_test = -220;
	osDelay(1500);
	//放手
	servo3_claw_deg = 80;
	osDelay(500);
	for (int i=0; i<4; i++){
		servo3_claw_deg+=5;
		osDelay(100);
	}

	//抽離+回正
	upper_joint.setSpeedRatio(1);
	upper_test = -80;
	osDelay(1000);
	servo4_slewing_deg = 720;
	servo2_wrist_deg = 52;
	osDelay(1000);
	servo3_claw_deg = 80;
	upper_test = 0;
	lower_test = 0;

	osDelay(1000);
	servo7_cascade_rotate = 590;

	finishMission();
}



void mission_302(void *pvParameters)
{
	mission_status = mission_type;
	roller_pwm = 1000;
	roller_switch =0;
	while (roller_switch <3) {
		osDelay(10);
	}
	readyForRoll();

	roller_pwm = 1000;
	while (roller_switch <3) {
		osDelay(10);
	}
	getRoll();

	servo4_slewing_deg = 709;
	osDelay(500);
	lower_test = -20;
	upper_joint.setSpeedRatio(0.8);
	upper_test = -170;
	osDelay(1500);

	//插入 0.8x speed
	upper_test = -220;
	osDelay(1500);
	//放手
	servo3_claw_deg = 80;
	osDelay(500);
	for (int i=0; i<4; i++){
		servo3_claw_deg+=5;
		osDelay(100);
	}

	//抽離+回正
	upper_joint.setSpeedRatio(1);
	upper_test = -80;
	osDelay(1000);
	servo4_slewing_deg = 720;
	servo2_wrist_deg = 52;
	osDelay(1000);
	servo3_claw_deg = 80;
	upper_test = 0;
	lower_test = 0;

	osDelay(1000);
	servo7_cascade_rotate = 590;

	finishMission();
}

void mission_303(void *pvParameters)
{
	mission_status = mission_type;
	roller_pwm = 1000;
	roller_switch =0;
	while (roller_switch <3) {
		osDelay(10);
	}
	readyForRoll();

	roller_pwm = 1000;
	while (roller_switch <3) {
		osDelay(10);
	}
	getRoll();

	servo4_slewing_deg = 690;
	osDelay(500);
	lower_test = 5;
	osDelay(1000);
	upper_joint.setSpeedRatio(0.8);
	upper_test = -155;
	osDelay(1800);

	//插入 0.4x speed
	upper_test = -200;
	osDelay(1800);
	//放手
	servo3_claw_deg = 80;
	osDelay(1000);
	for (int i=0; i<4; i++){
		servo3_claw_deg+=5;
		osDelay(100);
	}

	//抽離+回正
	upper_joint.setSpeedRatio(1);
	upper_test = -80;
	osDelay(1000);
	servo4_slewing_deg = 720;
	servo2_wrist_deg = 52;
	osDelay(1000);
	servo3_claw_deg = 80;
	upper_test = 0;
	lower_test = 0;

	osDelay(1000);
	servo7_cascade_rotate = 590;

	finishMission();
}

void mission_304(void *pvParameters)
{
	mission_status = mission_type;
	roller_pwm = 1000;
	roller_switch =0;
	while (roller_switch <3) {
		osDelay(10);
	}
	readyForRoll();

	roller_pwm = 1000;
	while (roller_switch <3) {
		osDelay(10);
	}
	getRoll();

	servo7_cascade_rotate = 680;
	servo4_slewing_deg = 754;
	osDelay(500);
	lower_test = 25;
	osDelay(1000);
	upper_joint.setSpeedRatio(0.8);
	upper_test = -140;
	osDelay(1800);

	//插入 0.4x speed
	upper_test = -200;
	osDelay(1800);
	//放手
	servo3_claw_deg = 80;
	osDelay(1000);
	for (int i=0; i<4; i++){
		servo3_claw_deg+=5;
		osDelay(100);
	}

	//抽離+回正
	upper_joint.setSpeedRatio(1);
	upper_test = -80;
	osDelay(1000);
	servo4_slewing_deg = 722;
	servo2_wrist_deg = 52;
	osDelay(1000);
	servo7_cascade_rotate = 590;
	servo3_claw_deg = 80;
	upper_test = 0;
	lower_test = 0;

	osDelay(1500);
	servo7_cascade_rotate = 590;

	finishMission();
}

void mission_300(void *pvParameters)
{
	mission_status = mission_type;

	fork_test = -300;

    finishMission();
}

void mission_307(void *pvParameters)
{
	mission_status = mission_type;
	roller_pwm = 1000;
	roller_switch =0;
	while (roller_switch <3) {
		osDelay(10);
	}
	readyForRoll();

	roller_pwm = 1000;
	while (roller_switch <3) {
		osDelay(10);
	}
	getRoll();

	lower_test = 10;
	osDelay(400);
	upper_test = -205;
	osDelay(3500);
	for (int i =0; i<8; i++) {
		servo3_claw_deg += 5;
		osDelay(200);
	}
	osDelay(400);
	upper_test = -80;
	osDelay(1000);
	servo4_slewing_deg = 720;
	servo2_wrist_deg = 52;
	osDelay(1000);
	servo7_cascade_rotate = 590;
	servo3_claw_deg = 80;
	upper_test = 0;
	lower_test = 0;

	osDelay(1000);
	servo7_cascade_rotate = 590;

    finishMission();
}

void mission_305(void *pvParameters)
{
	mission_status = mission_type;
	roller_pwm = 1000;
	roller_switch =0;
	while (roller_switch <3) {
		osDelay(10);
	}
	readyForRoll();

	roller_pwm = 1000;
	while (roller_switch <3) {
		osDelay(10);
	}
	getRoll();

	servo4_slewing_deg = 700;
	servo2_wrist_deg = 115;

	lower_test = 10;
	upper_test = -200;
	osDelay(3500);
	lower_test = 25;
	osDelay(800);
	for (int i =0; i<9; i++) {
		servo3_claw_deg +=5;
		osDelay(200);
	}
	osDelay(400);
	upper_test = -80;
	osDelay(1000);
	servo4_slewing_deg = 720;
	servo2_wrist_deg = 52;
	osDelay(1000);
	servo7_cascade_rotate = 590;
	servo3_claw_deg = 80;
	upper_test = 0;
	lower_test = 0;

	osDelay(1000);
	servo7_cascade_rotate = 590;

    finishMission();
}

void mission_306(void *pvParameters)
{
	mission_status = mission_type;
	roller_pwm = 1000;
	roller_switch =0;
	while (roller_switch <3) {
		osDelay(10);
	}
	readyForRoll();

	roller_pwm = 1000;
	while (roller_switch <3) {
		osDelay(10);
	}
	getRoll();

	servo4_slewing_deg = 745;
	servo2_wrist_deg = 95;

	lower_test = 10;
	upper_test = -200;
	osDelay(3500);
	lower_test = 22;
	osDelay(800);
	for (int i =0; i<9; i++) {
		servo3_claw_deg +=5;
		osDelay(200);
	}
	osDelay(400);
	upper_test = -80;
	osDelay(1000);
	servo4_slewing_deg = 720;
	servo2_wrist_deg = 52;
	osDelay(1000);
	servo7_cascade_rotate = 590;
	servo3_claw_deg = 80;
	upper_test = 0;
	lower_test = 0;

	osDelay(1000);
	servo7_cascade_rotate = 590;

    finishMission();
}

void mission_308(void *pvParameters)
{
	mission_status = mission_type;
	roller_pwm = 1000;
	roller_switch =0;
	while (roller_switch <3) {
		osDelay(10);
	}
	readyForRoll();

	roller_pwm = 1000;
	while (roller_switch <3) {
		osDelay(10);
	}
	getRoll();

	servo4_slewing_deg = 706;
	servo2_wrist_deg = 110;

	lower_test = -30;
	upper_test = -210;
	osDelay(3500);
	lower_test = -25;
	osDelay(800);
	//半開
	servo3_claw_deg = 90;

	osDelay(1000);
	//前推
	lower_test = 20;
	upper_test = -215;
	servo4_slewing_deg = 700;
	osDelay(1000);
	servo2_wrist_deg = 100;
	servo3_claw_deg = 95;
	osDelay(1000);
	servo3_claw_deg = 100;
	osDelay(800);
	servo3_claw_deg = 110;
	osDelay(800);

	osDelay(1000);
	upper_test = -80;
	osDelay(1000);
	servo2_wrist_deg = 52;
	osDelay(1000);
	servo4_slewing_deg = 720;
	servo7_cascade_rotate = 590;
	servo3_claw_deg = 80;
	upper_test = 0;
	lower_test = 0;

	osDelay(1000);
	servo7_cascade_rotate = 590;

    finishMission();
}

void mission_309(void *pvParameters)
{
	mission_status = mission_type;

    // TODO

    finishMission();
}

void mission_310(void *pvParameters)
{
	mission_status = mission_type;

    // TODO

    finishMission();
}

void mission_399(void *pvParameters)
{
	mission_status = mission_type;

    upper_test = -50;
    osDelay(600);
    servo4_slewing_deg = 638;
    osDelay(1300);
    upper_test = 0;
    osDelay(1000);
    servo4_slewing_deg = 740;
    osDelay(600);
    servo4_slewing_deg = 720;

    finishMission();
}

void mission_311(void *pvParameters)
{
	mission_status = mission_type;

	fork_test = 0;

    finishMission();
}

void mission_312(void *pvParameters)
{
	mission_status = mission_type;

	fork_test = -300;

    finishMission();
}

void mission_2(void *pvParameters)
{
    mission_status = mission_type;
    upper_joint.setSpeedRatio(0.3);
    upper_test = 20;
    osDelay(3000);
    upper_test = -20;
    osDelay(3000);
    upper_joint.setSpeedRatio(1);
    upper_test = 20;
    osDelay(3000);
    upper_test = -20;
    osDelay(3000);

    finishMission();
}
