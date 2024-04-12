#include <Arduino.h>

// byte c[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
// byte d[]={0x08,0x04,0x56,0x54,0x7e,0x54,0x54,0x00};
// void setup() {
//   DDRB=0xFF;DDRC=0xFF;
// }
// void loop() {
//   for (int i=0 ;i<=7;i++){
//     PORTC=c[i];//位址
//     PORTB=d[i];//資料
//     delay(1);//delay(1)
//   }
// }
// byte c[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
// byte d[]={0,0,0,0,0,0,0,0,0,0,
// 0x08,0x04,0x56,0x54,0x7e,0x54,0x54,0x00
// ,0,0
// ,0x47,0x45,0x45,0x39,0,0,0,0x7c,
// 0x12,0x11,0x12,0x7c,0,0,0,0,0,0,0,0,0,0};
// int slen= 41;//此數字為以上d[]的長度
// byte a[8];
// void setup() {  
//   DDRB=0xFF;
//   DDRC=0xFF;
// }
// void loop() { 
//   //以跑馬燈左旋顯示文字
//     for (int k=0 ;k<=slen-8;k++){
//         for (int i=0;i<=7;i++){//依序每次抓8個
//           a[i]=d[i+k] ;
//         }  
//         for (int i=0;i<=50;i++){//停留時間
//           for (int j=0 ;j<=7;j++){
//                   PORTC=c[j];//位址
//                   PORTB=a[j];//資料
//                   delay(1);
//               }  
//        }
//   }
// }
byte i=0;
byte c[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};//位址
byte d[8];
byte e[4][8]={ { 0, 0,0xda,0x3d,0xda,0,0,0},
               { 0x20, 0x90, 0x4a, 0x3d, 0x4a,0x90,0x20,0},
               { 0x08, 0x88, 0x4a, 0x3d, 0x4a, 0x88,0x08,0},
               { 0x02, 0x84, 0x4a, 0x3d, 0x4a,0x84,0x02,0}};
               
long t,t1,t2;
void setup() {  
    DDRB=0xff;
    DDRC=0xff;
}
void loop() { 
 //   每次從e陣列抓8個，放到d陣列。
    for (int j=0 ;j<=7;j++)
        d[j]=e[i][j];
    //掃描輸出
    t1= millis();
    do{
        for (int j=0 ;j<=7;j++){
            PORTC=c[j];//位址
            PORTB=d[j];//資料
            delay(1);
        } 
        t2=millis();
        t=t2-t1;
    }while( (t<200)  );//0.4秒，根據需求調整
    i=(i+1) % 4;//本例共4個畫面
}
