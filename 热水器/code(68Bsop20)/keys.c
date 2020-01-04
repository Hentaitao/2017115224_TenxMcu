#define __keys_c
#include "includeAll.h"
//=============================================================================
//按键信息获取
void GetKeys() {
	static uint8_t tempKeyValue = D_keyNull;

    P1MODH &= P17MOD_Mask;
	_nop_();
	_nop_();
	_nop_();
    _nop_();
    _nop_();
	if(P_key3 == 0){
		tempKeyValue = D_keyValue1;
	}	else{
		keyValue = tempKeyValue;
		tempKeyValue = D_keyNull;
	}
	P1MODH |= P17MOD_2;
}