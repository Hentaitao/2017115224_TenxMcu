#define __keys_c
#include "includeAll.h"
//=============================================================================
void GetKeys() {
  static uint8_t tempKeyValue = D_keyNull;

  //������ P10 ��Ϊ��������
  P1MODL = 0xa8;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  if (P_key1 == 0) {
    tempKeyValue = D_keyValue1;
  } else {
    keyValue = tempKeyValue;
    tempKeyValue = D_keyNull;
		
  }
  //������P10���ָ�Ϊ���
  P1MODL = 0xaa;
} 