#define __main_c
#include "includeAll.h"
//=============================================================================
uint8_t ledValue2=0;//led2亮与否1/0
void main() {
  
  SysInit();
  VarsInit();
	//使能看门狗
	F_turnOnWDT();

	P_buzz = 0;

	delayMs(500);

	P_ledcom=0;
	F_ledOff1();
	F_ledOff2();
	
	while(1){
		//清看门狗
		F_clearWDT();
		//业务代码
		TimeProcess();
		TaskSetting();
		TaskProcess();
		DisplayProcess();
	   // smg_double(0x3f,0x71);
	}
}

//=============================================================================
	void TimeProcess(){
		static uint8_t timer5ms = 0;
		
		if (b1ms) {
			// 1ms 执行一次
			b1ms = 0;
			timer5ms++;
		}
		if (timer5ms >= 5) {
            
			GetKeys();
		}
	}
//=============================================================================
	void TaskSetting(){	
		if(D_keyValue1==keyValue3){
			
			F_ledNeg2();
            buzzCounter=1000;
		}
	/*	else if (D_keyValue1==keyValue&&ledValue2==0)
		{
			F_ledOn2();
			ledValue2=1;
			buzzCounter=100;
		}
		else
		{
			;
		}*/
		
		keyValue3=D_keyNull;
	} 
//=============================================================================
	void TaskProcess(){

	}
//=============================================================================
	void DisplayProcess(){
	
	}
//=============================================================================
//延时函数
void delayMs(uint16_t time){
	uint16_t i,j;
	for(i=0; i<time; i++){
		for(j=0; j<1000; j++){
			F_clearWDT();
		}
	}
}

