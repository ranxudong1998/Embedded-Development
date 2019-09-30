//data:2019.09.18
//author:ranxudong 2017051604115
#define GPFCON   (*(volatile unsigned long*)0x56000050)
#define GPFDAT   (*(volatile unsigned long*)0x56000054)

int main()
{
  GPFCON = GPFCON | 0x00001540;

  int i = 0;
  while(1){
    GPFDAT = 0x560000F7;
    
    GPFDAT = GPFDAT | 0x00000007;   //GPFDAT = 0x56000057
    for(i = 0; i < 30000;i++){}
    
    GPFDAT = GPFDAT & 0xFFFFFF0F;    
    GPFDAT = GPFDAT | 0x000000EF;   //GPFDAT = 0x560000EF
    for(i = 0; i < 30000; i++){}
    
    GPFDAT = GPFDAT & 0xFFFFFF0F;    
    GPFDAT = GPFDAT | 0x000000DF;   //GPFDAT = 0x560000DF
    for(i = 0; i < 30000; i++){}
    
    GPFDAT = GPFDAT & 0xFFFFFF0F;   
    GPFDAT = GPFDAT | 0x000000BF;   //GPFDAT = 0x560000BF
    for(i = 0; i < 30000; i++){}
  }
  return 0;
}
