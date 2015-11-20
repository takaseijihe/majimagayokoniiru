#define DDX_GCC_COMPILE
#define DDX_NON_INLINE_ASM
#include "DxLib.h"
#include <math.h>
#include <stdio.h>
#define ANGLE_MAX 90
#define ANGLE_ACCEL 2000
#define VELOCITY 500
#define PRE 10
#define FOL 10
#define ang1 30
#define ang2 60
#define ang3 90
#define LENGTH_TREAD_RIGHT 83
#define LENGTH_TREAD_LEFT  83.2
#define PAI 3.141592

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){


		SetMainWindowText("Slalom_Simurator_01");
		ChangeWindowMode(TRUE);
		SetGraphMode(640,480,32);

		if(DxLib_Init() == -1)
		{
			return -1;
		}
        int count_draw,count;
        float angle[1000];
        float angle_accel=2000;
        float angle_vel=0;
        float velocity_right=500;
        float velocity_left=500;
        float x[1000];
       	float y[1000];

        	angle[0]=0;

        for(count_draw = 1; count_draw<=999;count_draw++){

        	if((angle[count_draw-1]<ang1)&&(velocity_right>=150)){
        		angle_accel=ANGLE_ACCEL;
        	}
        	if(((angle[count_draw-1]>=ang1)&&(angle[count_draw-1]<=ang2))||(velocity_right<150)){
        		angle_accel=0;
        		if(velocity_right<150){
        			velocity_right = 150;
        		}
        	}
        	if((angle[count_draw-1]<=ang3)&&(angle[count_draw-1]>=ang2)&&(velocity_left>=500)){
        		angle_accel=(-ANGLE_ACCEL);
        	}
        	if(angle[count_draw-1]>=ang3){
        		angle_vel = 0.0;
        		angle_accel = 0.0;
        		break;
        	}
        	angle_vel = angle_vel + angle_accel*0.001;
        	angle[count_draw]=angle[count_draw-1] + angle_vel*0.001;
        	velocity_left= 500 -(angle_vel*LENGTH_TREAD_LEFT*PAI)/360;
        	velocity_right=500 +(angle_vel*LENGTH_TREAD_LEFT*PAI)/360;
        	
        }
            x[0]=0;
        	y[0]=0;
        for(count=1;count<count_draw;count++){
        	x[count] =x[count-1]+500*0.001*sin((angle[count]*PAI)/180);
        	y[count] =y[count-1]+500*0.001*cos((angle[count]*PAI)/180);

        }
    	DrawLine(186,280,186,280-PRE,GetColor(255,0,0));
	
        for(count=1;count<count_draw;count++){
    	    DrawLine(186+x[count-1],(280-PRE-y[count]),186+x[count],(280-PRE-y[count-1]),GetColor(255,0,0));
	
        
        }
		DrawLine(186+x[count],280-PRE-y[count],186+x[count]+FOL,280-PRE-y[count],GetColor(255,0,0));
		

		DrawBox(100,100,112,280,GetColor(255,12,0),TRUE);
		DrawBox(280,100,292,280,GetColor(255,12,0),FALSE);
		DrawBox(112,88,280,100,GetColor(255,12,0),TRUE);
		DrawBox(100,280,112,292,GetColor(198,60,0),TRUE);
		DrawBox(280,280,292,292,GetColor(198,60,0),TRUE);
		DrawBox(100,88,112,100,GetColor(198,60,0),TRUE);
		DrawBox(280,88,292,100,GetColor(198,60,0),TRUE);


        WaitKey();      // キー入力待ち
        DxLib_End();    // DXライブラリ終了処理konnitiha
        return 0;
}
