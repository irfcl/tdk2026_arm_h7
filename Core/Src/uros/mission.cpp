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

        BaseType_t ret;

    task_created = 1;

    switch (mission_type){

    case 3:
    	arm_mode = ARM_MISSION;
    	ret = xTaskCreate(mission_3, "mission_3", 512, NULL, 2, NULL);
    	if(ret != pdPASS)
    	{
    	    task_created = -1;
    	}
    	break;

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
    }
}

void readyForRoll() {
    //初始
	upper_joint.setSpeedRatio(1);
    roller_switch =0;
    servo2_wrist_deg = 56;
    servo3_claw_deg = 110;
    servo4_slewing_deg = 755;
    upper_test = 0;
    lower_test = 0;
    osDelay(750);
    servo4_slewing_deg = 791;
    osDelay(750);

    //往稻草卷伸
    lower_test = -90;
    osDelay(500);
    upper_test = -50;
    osDelay(3000);
    servo3_claw_deg = 120;
}

void getRoll() {
    upper_test = -70;
    lower_test = -100;
    osDelay(1000);
    //roller_pwm = 0;
    //夾+抬
    servo3_claw_deg = 60;
	osDelay(1000);
    lower_test = -30;
	osDelay(1000);
	//upper_test = 0;
	roller_pwm = 0;
	osDelay(2000);
	//橫放到對面叉子上
	//移動
	upper_test = -130;
	osDelay(1500);
	servo2_wrist_deg = 120;
	osDelay(3000);
}

static void finishMission()
{
	arm_mode = ARM_MANUAL;
    mission_status = -mission_type;
    mission_type = 0;
    task_created = 0;
    vTaskDelete(NULL);
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

void mission_200(void *pvParameters)
{
	mission_status = mission_type;
	sieve_test = -95;
	osDelay(100);
	sieve_test = -95;
	osDelay(100);
	sieve_test = -95;
	osDelay(100);
	servo7_cascade_rotate = 90;
	osDelay(1000);
	for (int i =0; i <20; i++) {
		servo8_cascade_lengthen += 9;
	}

	finishMission();
}

void mission_201(void *pvParameters)
{
	mission_status = mission_type;
	servo8_cascade_lengthen =0;
	osDelay(1500);
	servo7_cascade_rotate = 0;
	osDelay(1000);
	servo5_outside_deg = 180;
	servo6_inside_deg = 0;
	osDelay(2000);
	sieve_test = -70;
	finishMission();
}

void mission_202(void *pvParameters)
{
	mission_status = mission_type;
	sieve_test = 10;
	osDelay(5000);
	sieve_test = -97;
	osDelay(100);
	sieve_test = -97;
	osDelay(100);
	sieve_test = -97;
	osDelay(100);
	osDelay(3500);
	sieve_test = -70;
	osDelay(500);
	finishMission();
}

void mission_203(void *pvParameters)
{
	mission_status = mission_type;
	sieve_test = -95;
	osDelay(1000);
	servo5_outside_deg = 30;
	servo6_inside_deg = 150;
	finishMission();
}

void mission_3(void *pvParameters)
{
	mission_type = mission_3_task;
    mission_status = 0;

    BaseType_t ret = pdFAIL;

    switch (mission_3_task)
    {
    case 301:
        ret = xTaskCreate(mission_301, "mission_301", 512, NULL, 2, NULL);
        break;

    case 302:
        ret = xTaskCreate(mission_302, "mission_302", 512, NULL, 2, NULL);
        break;

    case 303:
        ret = xTaskCreate(mission_303, "mission_303", 512, NULL, 2, NULL);
        break;

    case 304:
        ret = xTaskCreate(mission_304, "mission_304", 512, NULL, 2, NULL);
        break;

    case 305:
        ret = xTaskCreate(mission_305, "mission_305", 512, NULL, 2, NULL);
        break;

    case 306:
        ret = xTaskCreate(mission_306, "mission_306", 512, NULL, 2, NULL);
        break;

    case 307:
        ret = xTaskCreate(mission_307, "mission_307", 512, NULL, 2, NULL);
        break;

    case 308:
        ret = xTaskCreate(mission_308, "mission_308", 512, NULL, 2, NULL);
        break;

    case 309:
        ret = xTaskCreate(mission_309, "mission_309", 512, NULL, 2, NULL);
        break;

    case 310:
        ret = xTaskCreate(mission_310, "mission_310", 512, NULL, 2, NULL);
        break;

    default:
        mission_3_task = 301;
        ret = xTaskCreate(mission_301, "mission_301", 512, NULL, 2, NULL);
        break;
    }

    if(ret == pdPASS){
        if(mission_3_task < 310){
        	mission_3_task++;
        }
        else{
        	mission_3_task = 301;
        }
    }

    else{
        task_created = -1;
        vTaskDelete(NULL);
        return;
    }

    vTaskDelete(NULL);
}

void mission_301(void *pvParameters)
{
	mission_status = mission_type;
	readyForRoll();

	roller_pwm = 750;
	while (roller_switch <3) {
		osDelay(10);
	}
	getRoll();

	servo4_slewing_deg = 760;
	osDelay(500);
	upper_joint.setSpeedRatio(0.4);
	upper_test = -180;
	osDelay(5000);

	//插入 0.4x speed
	upper_test = -220;
	osDelay(2500);
	//放手
	servo3_claw_deg = 100;
	osDelay(1000);
	for (int i=0; i<20; i++){
		servo3_claw_deg++;
		osDelay(100);
	}

	//抽離+回正
	upper_joint.setSpeedRatio(1);
	upper_test = -80;
	osDelay(1000);
	servo4_slewing_deg = 790;
	osDelay(1000);
	servo3_claw_deg = 80;
	servo2_wrist_deg = 60;
	upper_test = 0;
	lower_test = 0;

	osDelay(1000);


	finishMission();
}

void mission_302(void *pvParameters)
{
	mission_status = mission_type;
	readyForRoll();

	roller_pwm = 750;
	while (roller_switch <3) {
		osDelay(10);
	}
	getRoll();

	servo4_slewing_deg = 820;
	osDelay(500);
	upper_joint.setSpeedRatio(0.4);
	upper_test = -180;
	osDelay(5000);

	//插入 0.4x speed
	upper_test = -220;
	osDelay(2500);
	//放手
	servo3_claw_deg = 100;
	osDelay(1000);
	for (int i=0; i<20; i++){
		servo3_claw_deg++;
		osDelay(100);
	}

	//抽離+回正
	upper_joint.setSpeedRatio(1);
	upper_test = -80;
	osDelay(1000);
	servo4_slewing_deg = 790;
	osDelay(1000);
	servo3_claw_deg = 80;
	servo2_wrist_deg = 60;
	upper_test = 0;
	lower_test = 0;

	osDelay(1000);


	finishMission();
}

void mission_303(void *pvParameters)
{
	mission_status = mission_type;
	readyForRoll();

	roller_pwm = 750;
	while (roller_switch <3) {
		osDelay(10);
	}
	getRoll();

	servo4_slewing_deg = 840;
	osDelay(500);
	lower_test = -10;
	osDelay(1000);
	upper_joint.setSpeedRatio(0.4);
	upper_test = -180;
	osDelay(5000);

	//插入 0.4x speed
	upper_test = -213;
	osDelay(2500);
	//放手
	servo3_claw_deg = 100;
	osDelay(1000);
	for (int i=0; i<10; i++){
		servo3_claw_deg+=2;
		osDelay(100);
	}

	//抽離+回正
	upper_joint.setSpeedRatio(1);
	upper_test = -100;
	osDelay(1000);
	servo4_slewing_deg = 790;
	osDelay(1000);
	servo3_claw_deg = 80;
	servo2_wrist_deg = 60;
	upper_test = 0;
	lower_test = 0;

	osDelay(1000);


	finishMission();
}

void mission_304(void *pvParameters)
{
	mission_status = mission_type;
	readyForRoll();

	roller_pwm = 750;
	while (roller_switch <3) {
		osDelay(10);
	}
	getRoll();

	servo4_slewing_deg = 740;
	osDelay(500);
	lower_test = -10;
	osDelay(1000);
	upper_joint.setSpeedRatio(0.4);
	upper_test = -180;
	osDelay(5000);

	//插入 0.4x speed
	upper_test = -213;
	osDelay(2500);
	//放手
	servo3_claw_deg = 100;
	osDelay(1000);
	for (int i=0; i<10; i++){
		servo3_claw_deg+=2;
		osDelay(100);
	}

	//抽離+回正
	upper_joint.setSpeedRatio(1);
	upper_test = -100;
	osDelay(1000);
	servo4_slewing_deg = 790;
	osDelay(1000);
	servo3_claw_deg = 80;
	servo2_wrist_deg = 60;
	upper_test = 0;
	lower_test = 0;

	osDelay(1000);


	finishMission();
}

void mission_305(void *pvParameters)
{
	mission_status = mission_type;

    // TODO

    finishMission();
}

void mission_306(void *pvParameters)
{
	mission_status = mission_type;

    // TODO

    finishMission();
}

void mission_307(void *pvParameters)
{
	mission_status = mission_type;

    // TODO

    finishMission();
}

void mission_308(void *pvParameters)
{
	mission_status = mission_type;

    // TODO

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
