#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
  //ʹ�ܿ��Ź�
  F_turnOnWDT();

  while (1) {
    //ι��
    F_clearWDT();
    //ҵ�����
    TimeProcess();
    TaskSetting();
    TaskProcess();
    DisplayProcess();
  }
}
//=============================================================================
void TimeProcess() {
  static uint8_t timer5ms = 0;
  static uint16_t second = 0;

  if (b1ms) {
    // 1ms ִ��һ��
    b1ms = 0;
    timer5ms++;
    second++;
  }
  if (timer5ms >= D_5ms) {
    GetKeys();
  }
  if (second >= D_1000ms) {
    // 1s ִ��һ��
    second = 0;
  }
}
//=============================================================================
void TaskProcess() {}
//=============================================================================
void TaskSetting() {
  if (D_keyValue1 == keyValue) {
    F_ledNeg();
  }
  keyValue = D_keyNull;
}
//=============================================================================
void DisplayProcess() {
  // F_ledOn();
}