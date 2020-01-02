#define __keys_c
#include "includeAll.h"
//=============================================================================
//按键信息获取
void GetKeys() {
	static uint8_t tempKeyValue = D_keyNull;
	P1MODL = 0x8a;
//	delayMs(10); //去抖，提高按�?的稳定�?
	if(P_key4 == 0){
		tempKeyValue = D_keyValue1;
	}	else{
		keyValue = tempKeyValue;
		tempKeyValue = D_keyNull;
	}
	P1MODL = 0xaa;
}