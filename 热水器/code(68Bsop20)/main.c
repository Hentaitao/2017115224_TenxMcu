#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
	//使能看门�?
	F_turnOnWDT();

	P_buzz = 0;

	

	delayMs(500);
	//P_D=0;
	P_ledcom=1;
	SMG_COM1=0;
	SMG_COM2=1;
	SMG_A=1;
	SMG_B=1;
	SMG_C=1;
	SMG_D=1;
	SMG_F=1;
	SMG_E=1;
	SMG_G=0;
	SMG_DG=0;


	
	
	while(1){
		//清看门狗
		F_clearWDT();
		//业务代码
		TimeProcess();
		TaskSetting();
		TaskProcess();
		DisplayProcess();
		
	}
}

//=============================================================================
	void TimeProcess(){
		static uint8_t timer5ms = 0;

		if (b1ms) {
			// 1ms 执�?�一�?
			b1ms = 0;
			timer5ms++;
		}
		if (timer5ms >= 5) {
			P1MODL = 0x8a;
			delayMs(20);
			GetKeys();
      buzzCounter=100;
			
		}
	}
//=============================================================================
	void TaskSetting(){	
		if(D_keyValue1==keyValue){
			P1MODL = 0xaa;
			
		}
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

