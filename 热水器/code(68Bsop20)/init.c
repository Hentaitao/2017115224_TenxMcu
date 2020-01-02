#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
	F_clearWDT();
  //时钟初�?�化
  CLKCON = 0x03; // Clock div 1  7.3728Mhz
  STPPCK = 0;
  STPFCK = 0;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  SELFCK = 1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  // IO 模式初�?�化
	P1MODL = 0xaa;		//将模式置为推挽输�?
	P1MODH = 0xaa;
	//P1MODL = 0xa8;		//将模式置为上拉输�?
	P1_2 = 1;

  smg_init();
	
	//T2初�?�化
	TH2 = (65536 - 3686) / 256;
  RCP2H = TH2;
  TL2 = (65536 - 3686) % 256;
  RCP2L = TL2;
  TR2 = 1;
  ET2 = 1;
  EA = 1; 
}
//=============================================================================
void VarsInit() {}

/*����ܳ�ʼ������a~dg��Ϊ�������*/
void smg_init(){
  /*a 1.4 || d 1.7 */
  P1MODH &= 0x3c;
  P1MODH |= 0x82;
  /*b 3.4 || c 3.5 || e 3.6*/
  P3MODH &= 0x00;
  P3MODH |= 0x2a;
  /*f 1.2||dg 1.3 */
  P1MODL &= 0x0f;
  P1MODL |= 0xa0;
  /*g 3.2*/
  P3MODL &= 0xcf;
  P3MODL |= 0x20;
}