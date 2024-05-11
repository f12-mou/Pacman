#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# include "iGraphics.h"
void changemukh(void);
void change1speed(void);
void change(void);
void changeghosts(void);
void eatfunc(void);
void changepacman(void);
void lvldrw(int L);
int cons(int r,int s);
void fillfood(void);
void randomize(void);
void f(void);
void gp(void);
void diefunc(void);

int checking(int _x,int _y);
void drw(int gx,int gy,int grad,int mode,int R,int G ,int B,int num);
FILE *fp,*fp1,*fp2,*fp3,*fp4;

int foodx[1075],foody[1075],srad1=7,fmode=0,state=1,m1=0,m2=0,m3=0,m4=0,dx=25,dy=25,validity,q=0,gpmode=0,clrE=1;
int i,temp,trace=75,clrstate=1,foodstate[1075],ii,jj,kk,timer=8000,slow,prev;
double x=600.0,y=275.0,rad=20.0,a[3],b[3];
int g1x=600,g1y=350,grad=20,g1m1=0,g1m2,g1m3,g1m4,g1sm1=1,g1sm2=1,g1sm3=1,g1sm4=1,g1state=0,RE=255,GE=0,BE=0,g1mode=0;
int g2x=650,g2y=350,g2m1,g2m2,g2m3,g2m4,g2sm1=1,g2sm2=1,g2sm3=1,g2sm4=1,g2start=0,g2state=0;
int g3x=550,g3y=350,g3m1,g3m2,g3m4,g3m3,g3sm1=1,g3sm2=1,g3sm3=1,g3sm4=1,g3start=0,g3state=0;
int g4x=500,g4y=350,g4m1,g4m2,g4m4,g4m3,g4sm1=1,g4sm2=1,g4sm3=1,g4sm4=1,g4start=0,g4state=0;
int L=-1,lx[20][21],ly[20][21],arm1[20][21],arm2[20][21],eaten[4];
float fb=0;
int lives[4],livesx,livesy,j,len=0,gameover=0;
double la[3],lb[3],aa[3],bb[3];
int replicate=0,g5m1=0,g5m2=0,g5m3=0,g5m4=0,g5sm1=0,g5sm2=0,g5sm3=0,g5sm4=0,g5x=450,g5y=350;
int game=0,t,koita=1,h=1,score=0,number[100],number2[100];char str[10],lvl[3];char charnum[5];
char str1[20],str2[20],str3[20];
char names[50][20],names2[50][20];
int highscore,msg=1;char hs[8];
int hpx1=480,hpmode=0,hpmukh1=1,hpkhawa=0,hpx2=230,tm=0;char ctm[3],ctm2[3];int acidmode=0,acid=0;
double hpa[3],hpb[3];
int koytaeaten=0,d=0,dragon=0,resume=1,die=0,upto=6,maxup,music=1,prevtm,printeat=0,bonus,f1,f2,f3,f4;char eatch[4];
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
    iClear();
    if(game==12)
    {
        iShowBMP(350,250,"gameover3.bmp");
        iSetColor(255,0,0);
        iRectangle(1050,30,80,30);
        iText(1060,37,"NEXT",GLUT_BITMAP_HELVETICA_18);
    }
    if(game==8)
    {
        iShowBMP(250,0,"black3.bmp");
        for(i=300;i<800;i+=100)
        {
            for(j=500;j>=200;j-=100)
            {
                iShowBMP(i,j,"lock.bmp");
            }
        }
          iSetColor(255,0,255);
        iRectangle(1050,30,80,30);
        iText(1060,37,"BACK",GLUT_BITMAP_HELVETICA_18);
    if(upto>=1){iSetColor(150,0,255);iFilledRectangle(300,500,80,70);
            iSetColor(0,0,255);iText(330,525,"1",GLUT_BITMAP_TIMES_ROMAN_24);}
    if(upto>=2){iSetColor(150,0,255);iFilledRectangle(300,400,80,70);
            iSetColor(0,0,255);iText(330,425,"2",GLUT_BITMAP_TIMES_ROMAN_24);}
            if(upto>=3){iSetColor(150,0,255);iFilledRectangle(300,300,80,70);
            iSetColor(0,0,255);iText(330,325,"3",GLUT_BITMAP_TIMES_ROMAN_24);}
            if(upto>=4){iSetColor(150,0,255);iFilledRectangle(300,200,80,70);
            iSetColor(0,0,255);iText(330,225,"4",GLUT_BITMAP_TIMES_ROMAN_24);}
             if(upto>=5){iSetColor(150,0,255);iFilledRectangle(400,500,80,70);
            iSetColor(0,0,255);iText(430,525,"5",GLUT_BITMAP_TIMES_ROMAN_24);}
            if(upto>=6){iSetColor(150,0,255);iFilledRectangle(400,400,80,70);
            iSetColor(0,0,255);iText(430,425,"6",GLUT_BITMAP_TIMES_ROMAN_24);}
            if(upto>=7){iSetColor(150,0,255);iFilledRectangle(400,300,80,70);
            iSetColor(0,0,255);iText(430,325,"7",GLUT_BITMAP_TIMES_ROMAN_24);}
            if(upto>=8){iSetColor(150,0,255);iFilledRectangle(400,200,80,70);
            iSetColor(0,0,255);iText(430,225,"8",GLUT_BITMAP_TIMES_ROMAN_24);}

    }
    if(game==7)
    {
        iShowBMP(0,0,"dekhi2.bmp");
         iSetColor(255,0,255);
        iRectangle(1050,30,80,30);
        iText(1060,37,"BACK",GLUT_BITMAP_HELVETICA_18);
    }
    if(game==6)
    {
        iShowBMP(0,0,"credit.bmp");
          iSetColor(255,0,0);
        iRectangle(1050,30,80,30);
        iText(1060,37,"BACK",GLUT_BITMAP_HELVETICA_18);
        iSetColor(255,0,255);
        iText(70,600,"FOR LEARNING PROPERLY IN CSE-102 COURSE,I WHOLE-HEARTEDLY OWE TO MY TEACHERS :",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,500,"1. SHADMAN SAQUIB EUSUF ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,450,"2. SHUKARNA BARUA",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,400,"3. MD. TOUFIKUZZAMAN  ",GLUT_BITMAP_TIMES_ROMAN_24);

    }
    if(game==0)
    {
        iShowBMP(0,0,"bg1.bmp");
        iSetColor(255,0,255);
        iText(230,570,"LIFE IS LIKE A GAME OF PACMAN....",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(230,500,"STAY  AWAY  OF  WRONG_DOERS  AND  LEVEL  UP",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(230,450,"NO  NEED  TO  WAIT  TILL  THE  BEGINNING  OF  THE  YEAR",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(230,400,"SET  THAT  AS  YOUR DAILY  GOAL  ALL  YEAR  LONG",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(85,20,255);
        iFilledRectangle(500,270,80,40);
        iSetColor(255,0,0);
        iText(510,280,"NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(game==5)
    {
        iShowBMP(0,0,"front3.bmp");
        iSetColor(255,255,0);
        iText(750,150,"YOUR SCORE IS :",GLUT_BITMAP_TIMES_ROMAN_24);
        sprintf(charnum,"%d",score);
        iText(1000,150,charnum,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(750,100,"ENTER YOUR NAME :",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,0,255);
        iText(1000,100,str1,GLUT_BITMAP_TIMES_ROMAN_24);

    }
    if(game==4)
    {
        iShowBMP(0,0,"bg21.bmp");
        iSetColor(0,255,255);
        iText(500,750,"HIGH SCORES",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(220,640,"SL NO",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(300,640,"NAMES",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(700,640,"SCORES",GLUT_BITMAP_TIMES_ROMAN_24);

         iSetColor(255,0,0);
        iRectangle(1050,30,80,30);
        iText(1060,37,"BACK",GLUT_BITMAP_HELVETICA_18);
        for(i=0;i<h && i<10;i++)
        {
            sprintf(charnum,"%d",number[i]);
            iSetColor(0,0,255);
            iText(700,600-(i*50),charnum,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(300,600-(i*50),names[i],GLUT_BITMAP_TIMES_ROMAN_24);
            sprintf(charnum,"%d",i+1);iSetColor(0,255,0);
            iText(225,600-(i*50),charnum,GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }
    if(game==3)
    {


        iSetColor(255,0,0);
        iRectangle(1050,30,80,30);
        iText(1060,37,"BACK",GLUT_BITMAP_HELVETICA_18);
          for(i=0;i<10;i++)
            {
                iSetColor(255-i*20,0,0);
                iRectangle(50-i,25-i,1100+i*2,750+i*2);//exterior box
            }iSetColor(255,0,0);iText(500,730,"HELP PAGE",GLUT_BITMAP_TIMES_ROMAN_24);
       iSetColor(0,0,255);
        iText(80,700,"YOU HAVE TO CONTROL PACMAN WHO MUST EAT ALL THE DOTS WHILE AVOIDING 4 COLORED GHOSTS",GLUT_BITMAP_HELVETICA_18);
        iRectangle(400,600,400,60);//helpx1 helpy1
        drw(hpx1+60,630,20,4,255,0,0,1);
        drw(hpx1+120,630,20,4,0,255,0,2);
        drw(hpx1+180,630,20,4,255,0,255,3);
        drw(hpx1+240,630,20,4,255,255,0,4);
        iSetColor(255,255,0);iFilledCircle(hpx1,630,20); iSetColor(255,0,0);iFilledCircle(hpx1+13,637,4);
        aa[0]=hpx1;bb[0]=630;aa[1]=hpx1-20;bb[1]=650;aa[2]=hpx1-20;bb[2]=610;
        if(hpmukh1==1){
        iSetColor(0,0,0);
        iFilledPolygon(aa,bb,3);}iSetColor(0,0,0);
        iFilledRectangle(130,600,268,60); iFilledRectangle(801,600,300,60);
        iSetColor(0,0,255);
        iText(80,570,"EATING LARGE FLASING PINK DOTS OR 'ENERGIZERS' CAUSES THE GHOSTS TURN BLUE",GLUT_BITMAP_HELVETICA_18);
        iRectangle(200,500,800,50);
        iSetColor(255,255,0);iFilledCircle(hpx2,525,20);iSetColor(255,0,0);
          iFilledCircle(hpx2-10,525,4);if(hpmukh1==1){
              iSetColor(0,0,0);
              hpa[0]=hpx2;hpa[1]=hpx2+20;hpa[2]=hpx2+20;hpb[0]=525;hpb[1]=545;hpb[2]=505;
              iFilledPolygon(hpa,hpb,3);
              }
          if(hpkhawa==0){
                iSetColor(255,0,255);iFilledCircle(500,525,10);
                drw(600,525,20,4,255,0,0,1);
                drw(680,525,20,4,255,0,255,2);
                drw(760,525,20,4,0,255,0,3);
                drw(840,525,20,4,0,0,255,4);}
                else if(hpkhawa==1)
                {
                drw(600,525,20,3,0,0,255,1);
                drw(680,525,20,3,0,0,255,2);
                drw(760,525,20,3,0,0,255,3);
                drw(840,525,20,3,0,0,255,4);}

        iSetColor(255,0,255);
        iText(80,450,"YOU HAVE TO PRESS THE ARROW KEYS TO CONTROL PACMAN'S DIRECTION.",GLUT_BITMAP_HELVETICA_18);
        iText(80,410,"IN THE EVEN NUMBERED LEVELS,ACID WILL BLOW UP UNTIL YOU REACH THE TOP REGION.",GLUT_BITMAP_HELVETICA_18);
        iSetColor(255,0,0);
        iText(80,370,"PACMAN WILL DIE IF HE TOUCHES THE ACID LEVEL !!!.",GLUT_BITMAP_HELVETICA_18);
        iSetColor(0,255,0);
        iText(80,330,"YOU CAN GET AN EXTRA LIFE EATING THE GOLDEN COIN.",GLUT_BITMAP_HELVETICA_18);
        iText(80,290,"YOU WILL GET BONUS POINTS IF YOU EAT THE FRUITS.",GLUT_BITMAP_HELVETICA_18);
        iText(80,250,"IF YOU EAT DRAGON FRUIT,THE GHOSTS WILL BE PAUSED FOR A BRIEF AMOUNT OF TIME.",GLUT_BITMAP_HELVETICA_18);
        iShowBMP(900,250,"dragon.bmp"); iShowBMP(700,330,"coin.bmp");
        iSetColor(0,0,255);
        iText(80,210,"PINKY WILL MAKE IT'S REPLICATE AFTER EVERY 12 SECONDS.",GLUT_BITMAP_HELVETICA_18);
        drw(750,210,20,4,255,0,255,3);iSetColor(255,0,0);
        iText(80,170,"BLINKY TRIES TO REACH YOUR POSITION.BE AWARE !!!",GLUT_BITMAP_HELVETICA_18);
        drw(700,170,20,4,255,0,0,1);iSetColor(0,255,255);
        iText(80,120,"ENJOY THE GAME.UNLOCK NEW LEVELS AND EXPLORE.ALL THE BEST!!!",GLUT_BITMAP_HELVETICA_18);
        iSetColor(255,255,0);iFilledCircle(63,125,5);iFilledCircle(63,175,5);iFilledCircle(63,215,5);
        iFilledCircle(63,255,5); iFilledCircle(63,295,5); iFilledCircle(63,335,5); iFilledCircle(63,375,5);
        iFilledCircle(63,415,5);iFilledCircle(63,455,5);iFilledCircle(63,575,5);iFilledCircle(63,705,5);
        iText(810,630,"(CLICK IN THE BOXES)",GLUT_BITMAP_HELVETICA_18);
}



    if(game==2)
    {
            iShowBMP(0,0,"front2.bmp");
            iSetColor(0,0,25);
            for(i=1;i<=4;i++)
            {
                iFilledRectangle(400,i*50,200,35);
                iFilledRectangle(700,i*50,200,35);
            }
            iSetColor(255,0,0);
            iText(405,210,"NEW GAME",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(405,160,"RELOAD_GAME",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(405,110,"LEVELS",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(405,60,"HIGH_SCORES",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(705,210,"HELP_PAGE",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(705,160,"ABOUT_GAME",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(705,110,"CREDIT",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(705,60,"QUIT GAME",GLUT_BITMAP_TIMES_ROMAN_24);


    }
  if(game==1)
    {
        if(music==1){iShowBMP(810,755,"sound.bmp");}
        else if(music==0){iShowBMP(810,755,"mute.bmp");}
         if(f1==0)iShowBMP(1165,200,"fruits1.bmp");
        if(f2==0) iShowBMP(1160,250,"fruits2.bmp");if(f3==0)iShowBMP(1165,300,"fruits3.bmp");
         if(f4==0){ iShowBMP(1160,350,"dragon.bmp");}
         if(f1==1){  iShowBMP(550,420,"fruits1.bmp");}
         if(f2==1){  iShowBMP(550,420,"fruits2.bmp");}
         if(f3==1){  iShowBMP(550,420,"fruits3.bmp");}
          if(f4==1){ iShowBMP(550,420,"dragon.bmp");}

        iSetColor(255,255,0);
        iRectangle(50,760,750,35);
    if(msg==1){iSetColor(255,0,0);iText(53,766,"HEY,PACMAN.WHY ARE YOU RUNNING,COWARD?COME TO ME.MUHAHAH !-Blinky",GLUT_BITMAP_HELVETICA_18);}
    else if(msg==2){iSetColor(0,255,255);iText(53,766,"TEASING YOU,I FEEL SO COOL.SORRY NOT SORRY--Inky *_*",GLUT_BITMAP_HELVETICA_18);}
    else if(msg==3){iSetColor(255,0,255);iText(53,766,"I WILL NEVER LET YOU WIN PACMAN ,HUHAHAHAHAA ! -Pinky $_$",GLUT_BITMAP_HELVETICA_18);}
    else if(msg==4){iSetColor(255,70,0);iText(53,766,"HEY,COME AND MEET US BUDDY.WE 4 ARE SO COOL GHOSTS!-Clyde ^_^",GLUT_BITMAP_HELVETICA_18);}
            if(printeat==1)
            {
                sprintf(eatch,"%d",bonus);
                iSetColor(255,255,255);iText(550,350,eatch,GLUT_BITMAP_TIMES_ROMAN_24);
            }


        iSetColor(255,0,0);iText(550,60,"LEVEL",GLUT_BITMAP_TIMES_ROMAN_24);
            for(i=0;i<10;i++)
            {
                iSetColor(0,0,255-i*20);
                iRectangle(50-i,100-i,1100+i*2,650+i*2);//exterior box
            }
            sprintf(str,"%d",score);iSetColor(255,0,0);
            iRectangle(1130,760,60,30);iText(1132,769,"EXIT",GLUT_BITMAP_HELVETICA_18);
            iSetColor(0,255,0);iRectangle(1040,760,65,30);
            iText(1042,769,"MENU",GLUT_BITMAP_HELVETICA_18);
            iSetColor(255,255,0);iRectangle(900,760,120,30);
            iText(902,769,"HELP PAGE",GLUT_BITMAP_HELVETICA_18);
             if(resume==1)iShowBMP(855,760,"pause.bmp");
             else {iShowBMP(855,760,"pause2.bmp");}
             //iSetColor(255,255,0);iRectangle(990,760,58,30);
           // iText(993,763,"HELP PAGE",GLUT_BITMAP_TIMES_ROMAN_24);
           sprintf(ctm,"%d",tm/60); sprintf(ctm2,"%d",tm%60);
           iText(280,25,ctm,GLUT_BITMAP_TIMES_ROMAN_24);
           iText(305,25,ctm2,GLUT_BITMAP_TIMES_ROMAN_24);
           iText(295,25,":",GLUT_BITMAP_TIMES_ROMAN_24);



            iText(400,25,str,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(375,60,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(275,60,"CLOCK",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(650,60,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
            sprintf(hs,"%d",highscore);iText(650,25,hs,GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(255,0,0);
            iText(850,38,"PROGRESS STATUS",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(50,70,"LIVES OF PACMAN",GLUT_BITMAP_HELVETICA_18);
            for(i=0;i<4;i++)
            {
                if(lives[i]==1)
                {
                    iSetColor(255,255,0);
                    livesx=60+i*50;
                    livesy=40;
                    iFilledCircle(livesx,livesy,15);iSetColor(255,0,0);iFilledCircle(livesx-7,livesy+3,4);
                    la[0]=livesx;la[1]=la[2]=livesx+15;
                    lb[0]=livesy;lb[1]=livesy+15;
                    lb[2]=livesy-15;
                    iSetColor(0,0,0);
                    iFilledPolygon(la,lb,3);
                }
            }
           /* if(lives[3]==0){
            iSetColor(255,255,255);
            iFilledCircle(800,350,9);}*/
             if(lives[3]==0){iShowBMP(760,350,"coin.bmp");}

            for(i=0;i<4;i++)
            {
                iSetColor(255,0,0);
                iRectangle(850+i,60+i,300-2*i,30-2*i);
            }
            for(i=0;i<(fb*0.85) && i<295;i++)
            {
                iSetColor(0,255,0);iLine(854+i,63,854+i,87);
            }
            if(L==-1)
            {
                iSetColor(255,0,0);sprintf(lvl,"%d",1);
                iText(550,25,lvl,GLUT_BITMAP_TIMES_ROMAN_24);

                    for(i=0;i<20;i++)
                    {
                        iSetColor(0,0,255-i*15);//define blue
                        iRectangle(350+i,180+i,50-2*i,70-2*i);
                        iRectangle(800+i,180+i,50-2*i,70-2*i);
                        iRectangle(550+i,450+i,100-2*i,50-2*i);
                        iRectangle(100+i,600+i,150-2*i,100-i*2);
                        iRectangle(350+i,600+i,100-2*i,100-i*2);//2nd box
                        iRectangle(550+i,650+i,100-2*i,100-i*2);//3rd box
                        iRectangle(750+i,600+i,100-2*i,100-i*2);//4th box
                        iRectangle(950+i,600+i,150-2*i,100-i*2);//5th box
                        iRectangle(550+i,150+i,100-2*i,100-i*2);//6thbox
                        iRectangle(50+i,250+i,100-2*i,50-i*2);//7th box
                        iRectangle(1050+i,250+i,100-2*i,50-i*2);//8th box
                        iRectangle(450+i,300+i,300-2*i,100-i*2);//main box
                        iSetColor(200-i*3,0,255-i*10);
                        iEllipse(300,400,50-i,100-i);//left illipse
                        iEllipse(900,400,50-i,100-i);
                        iSetColor(0,0,255-i*15);//right ellipse
                        iRectangle(100+i,150+i,400-2*i,30-i*2);//
                        iRectangle(100+i,150+i,400-2*i,30-i*2);//vanga box1
                        iRectangle(700+i,150+i,400-2*i,30-i*2);//vanga box 2
                        iRectangle(450+i,520+i,300-2*i,30-i*2);//
                    }
                    iSetColor(0,0,0);iFilledRectangle(40,400,15,50);
                    iFilledRectangle(1145,400,15,50);
                    for(i=0;i<10;i++)
                    {
                        iSetColor(0,0,255-i*20);
                        iLine(50,450-i,200,450-i);iLine(1000,450-i,1150,450-i);
                    }
                     for(i=0;i<10;i++)
                    {
                        iSetColor(0,0,255-i*20);
                        iLine(50,400+i,200,400+i);iLine(1000,400+i,1150,400+i);
                    }//enter exit
                   iSetColor(200,0,255);
                   iFilledCircle(175,525,25);//frst circle
                   iSetColor(255,0,255);
                   iFilledCircle(1025,525,25);//second circle
                   for(i=0;i<1075;i++)
                   {
                       if(q==0)
                      {

                       if(i%4==0)
                       iSetColor(255,0,0);
                       else if(i%4==1)
                        iSetColor(0,255,0);
                       else if(i%4==2)
                        iSetColor(200,0,255);
                        else
                            iSetColor(255,255,0);
                      }
                       else if(q==1)
                      {

                       if(i%4==0)
                       iSetColor(255,255,0);
                       else if(i%4==1)
                        iSetColor(255,0,0);
                       else if(i%4==2)
                        iSetColor(0,255,0);
                        else
                            iSetColor(200,0,255);
                      }
                        else if(q==2)
                      {

                       if(i%4==0)
                       iSetColor(200,0,255);
                       else if(i%4==1)
                        iSetColor(255,255,0);
                       else if(i%4==2)
                        iSetColor(255,0,0);
                        else
                            iSetColor(0,255,0);
                      }
                        if(foodstate[i]==1){
                             if(i==0 || i==24 || i==1074 || i==1050)
                    {
                      iSetColor(255,0,255);iFilledCircle(foodx[i],foody[i],srad1);
                    }else
                          iFilledCircle(foodx[i],foody[i],5);
                        }
                   }






                   //our ghost 1
                       iSetColor(255,0,0);//check
                       if(g1m1==1)
                        drw(g1x,g1y,20,1,255,0,0,1);
                        else if(g1m3==1)
                        drw(g1x,g1y,20,3,255,0,0,1);
                        else if(g1m2==1)
                           // iFilledCircle(100,100,30);
                        drw(g1x,g1y,20,2,255,0,0,1);
                        else if(g1m4==1)
                        drw(g1x,g1y,20,4,255,0,0,1);
                        else
                            drw(g1x,g1y,20,1,255,0,0,1);
                    //ghost-2
                        if(g2m1==1)
                        drw(g2x,g2y,20,1,0,255,0,2);
                    else if(g2m3==1)
                        drw(g2x,g2y,20,3,0,255,0,2);
                        else if(g2m2==1)
                            drw(g2x,g2y,20,2,0,255,0,2);
                        else if(g2m4==1)
                        drw(g2x,g2y,20,4,0,255,0,2);
                        else drw(g2x,g2y,20,4,0,255,0,2);
                        // iSetColor(255,0,0);
             //iFilledCircle(g1x,g1y,20);
                if(g3m1==1)
                        drw(g3x,g3y,20,1,0,0,255,3);
                    else if(g3m3==1)
                        drw(g3x,g3y,20,3,0,0,255,3);
                        else if(g3m2==1)
                            drw(g3x,g3y,20,2,0,0,255,3);
                        else if(g3m4==1)
                        drw(g3x,g3y,20,4,0,0,255,3);
                        else drw(g3x,g3y,20,3,0,0,255,3);
              /*ghst 4 */          if(g4m1==1)
                        drw(g4x,g4y,20,1,255,0,255,4);
                    else if(g4m3==1)
                        drw(g4x,g4y,20,3,255,0,255,4);
                        else if(g4m2==1)
                            drw(g4x,g4y,20,2,255,0,255,4);
                        else if(g4m4==1)
                        drw(g4x,g4y,20,4,255,0,255,4);
                        else drw(g4x,g4y,20,2,255,0,255,4);
            }
             iSetColor(255,255,0);
                   iFilledCircle(x,y,rad);
                   iSetColor(0,0,0);

                   if(state==1)
                   {    iSetColor(0,0,0);
                    iFilledPolygon(a,b,3);
                   }
                   if(m1==1)
                    {   iSetColor(0,255,255);
                        iFilledCircle(x-10,y+7,7);iSetColor(255,0,0);
                        iFilledCircle(x-10,y+7,4);
                    }
                    else if(m2==1)
                    {
                        iSetColor(0,255,255);
                        iFilledCircle(x+10,y+7,7);iSetColor(255,0,0);
                        iFilledCircle(x+10,y+7,4);
                    }
                     else if(m3==1)
                    {
                        iSetColor(0,255,255);
                        iFilledCircle(x-10,y-7,7);iSetColor(255,0,0);
                        iFilledCircle(x-10,y-7,4);
                    }
                    else if(m4==1)
                    {
                        iSetColor(0,255,255);
                        iFilledCircle(x+10,y+7,7);iSetColor(255,0,0);
                        iFilledCircle(x+10,y+7,4);
                    }//ends here the pacman code yo

                if(die==1)
                {
                    iShowBMP(x-25,y-25,"fire.bmp");
                }

           if(L==0)
           lvldrw(0);
            if(L==1)

                lvldrw(1);
                if(L==2)
                    lvldrw(2);
                     if(L==3)
                    lvldrw(3);
                     if(L==4)
                    lvldrw(4);
                       if(L==5)
                    lvldrw(5);
                      if(L==6)
                    lvldrw(6);
                      if(L==7)
                    lvldrw(7);
                    if(L==8)
                    lvldrw(8);
                     if(L==9)
                    lvldrw(9);
                    if(L==10)
                    lvldrw(10);
                    if(L==11)
                    lvldrw(11);
    }

}

void f(void)
{       if(game==1){
            if(dragon==1){dragon=0;iResumeTimer(2);}
          if(fmode==1)
            fmode=0;
           for(i=0;i<4;i++)
           {
               if( eaten[i]==-1){eaten[i]=0;}
           }

                if(replicate==1)
                    replicate=0;
                else {replicate=1;g5m1=1;}

                if(msg==1)msg=2;
                else if(msg==2)msg=3;
                else if(msg==3)msg=4;
                else if(msg==4)msg=1;
     }
}

int cons(int r,int s)
{
    int ok=1;
    for(i=0;i<4;i++)
    {
        if( r<=(lx[L][i]+arm1[L][i]) && r>=(lx[L][i]-arm1[L][i])&& s<=(ly[L][i]+arm2[L][i])&& s>=(ly[L][i]-arm2[L][i]))
            ok=0;
    }
    for(i=4;i<21;i++)
    {
        if(r>=lx[L][i] && r<=(lx[L][i]+arm1[L][i])&& s>=ly[L][i] && s<=(ly[L][i]+arm2[L][i]))
            ok=0;
    }
    if(r>=1150 || r<=50 || s>=750 ||s<=100)ok=0;

    //delete here
     else if((r>=50 && r<=200)&&((s)<=450 && (s)>=400))ok=0;
     else if((r>=1000 && r<=1150)&&((s)<=450 && (s)>=400))ok=0;
     else if((r>=1000 && r<=1150)&&((s)>=450 && (s)<=400))ok=0;
     else if((r>=50 && r<=200)&&((s)>=450 && (s)<=400))ok=0;


     if(s==425 && (r<=200 && r>=50))ok=1;
      if(s==425 && (r<=1175 && r>=1000))ok=1;

    return ok;

}

void diefunc(void)
{
    if(game==1){
    if(gameover==1)
        {gameover=0;iResumeTimer(1);iResumeTimer(2);iResumeTimer(4);game=12;}
        if(die==1)
        {
            die=0;iResumeTimer(1);iResumeTimer(2);iResumeTimer(4);/*game=12;*/
            x=600;y=275;

        }
    }

}
void randomize(void)
{
    if(game==1){
                //if(gameover==1){gameover=0;iResumeTimer(1);iResumeTimer(2);iResumeTimer(4);game=12;}

        if(clrE==1){clrE=2;RE=0;GE=0;BE=255;}
     else if(clrE==2){clrE=3;RE=255;GE=0;BE=230;}
      else if(clrE==3){clrE=4;RE=0;GE=255;BE=20;}
       else if(clrE==4){clrE=5;RE=255;GE=160;BE=150;}
        else if(clrE==5){clrE=6;RE=40;GE=0;BE=190;}
         else if(clrE==6){clrE=7;RE=250;GE=0;BE=7;}
          else if(clrE==7){clrE=8;RE=0;GE=0;BE=255;}
           else if(clrE==8){clrE=1;RE=0;GE=240;BE=240;}

           /* if(die==1){
            //if(gameover==1){gameover=0;game=11;}
            die=0;if(lives[3]==1){lives[3]=-1;}
            else if(lives[2]==1){lives[2]=-1;}
            else if(lives[1]==1){lives[1]=-1;}
            else if(lives[0]==1){lives[0]=-1;}
    x=600;y=275;iResumeTimer(1);iResumeTimer(2);iResumeTimer(4);}*/

    }
    if(game==1){
            tm+=1;if(printeat==1){printeat=0;koytaeaten=0;}
           /* if(eaten[0]==1 || eaten[1]==1 || eaten[2]==1 || eaten[3]==1)
            {
                for(i=0;i<4;i++)
                {
                    if(eaten[i]==1)koytaeaten+=1;
                }
                printf("%d",koytaeaten);
                printeat=1;
                //prevtm=tm;
            }*/
    if(eaten[0]==1)return;
    if(g1x==x)
    {
        if(g1y>y){g1m2=1;g1m1=g1m3=g1m4=0;}
         if(g1y<y){g1m1=1;g1m2=g1m3=g1m4=0;}
    }
    else if(g1x!=x)
    {
        if(g1x>x){g1m4=1;g1m1=g1m2=g1m3=0;}
         if(g1x<x){g1m3=1;g1m1=g1m2=g1m4=0;}
    }
    else if(g1y==y)
    {
        if(g1x>x){g1m4=1;g1m1=g1m2=g1m3=0;}
        if(g1x<x){g1m3=1;g1m1=g1m2=g1m4=0;}
    }
   else if(g1y!=y)
    {
        if(g1y>y){g1m2=1;g1m1=g1m3=g1m4=0;}
         if(g1y<y){g1m1=1;g1m2=g1m3=g1m4=0;}
    }

     }
}

void drw(int g1x,int g1y,int grad,int mode,int R,int G,int B,int num)
{
   if(eaten[num-1]==1){ mode=1;
        if(mode==1){
           iSetColor(255,255,255);iFilledCircle(g1x-9,g1y+8,8);iFilledCircle(g1x+9,g1y+8,8);
            iSetColor(0,0,0);iFilledCircle(g1x-9,g1y+10,5);iFilledCircle(g1x+9,g1y+10,5);
        }
        if(mode==2)
        {
             iSetColor(255,255,255);iFilledCircle(g1x-9,g1y-9,8);iFilledCircle(g1x+9,g1y-9,8);
                iSetColor(0,0,0);iFilledCircle(g1x-9,g1y-12,5);iFilledCircle(g1x+9,g1y-12,5);
        }
        if(mode==3)
        {
          iSetColor(255,255,255);iFilledCircle(g1x-9,g1y,8);iFilledCircle(g1x+9,g1y,8);
                iSetColor(0,0,0);iFilledCircle(g1x-6,g1y,5);iFilledCircle(g1x+12,g1y,5);
        }
        if(mode==4)
        {
             iSetColor(255,255,255);iFilledCircle(g1x-9,g1y,8);iFilledCircle(g1x+9,g1y,8);
            iSetColor(0,0,0);iFilledCircle(g1x-11,g1y,5);iFilledCircle(g1x+7,g1y,5);
        }
        }
   else{
   if(fmode==1 && eaten[num-1]==0 )
   {
    R=G=0;B=255;iFilledCircle(g1x,g1y,grad);iFilledRectangle(g1x-20,g1y-15,40,15);
    if(gpmode==1)
        {
                iSetColor(R,G,B);
                iFilledEllipse(g1x-15,g1y-15,5,8);
                iFilledEllipse(g1x-5,g1y-15,5,8);
                iFilledEllipse(g1x+5,g1y-15,5,8);
                iFilledEllipse(g1x+15,g1y-15,5,8);

        }

   }
        iSetColor(R,G,B);
            iFilledCircle(g1x,g1y,grad);
            iSetColor(R,G,B);
            iFilledRectangle(g1x-20,g1y-15,40,15);
            if(gpmode==1)
            {
                iSetColor(R,G,B);iFilledEllipse(g1x-15,g1y-15,5,8);iFilledEllipse(g1x-5,g1y-15,5,8);
                iFilledEllipse(g1x+5,g1y-15,5,8);
                iFilledEllipse(g1x+15,g1y-15,5,8);
            }
            if(mode==1)
            {
                if(fmode==0 || eaten[num-1]==-1){
                iSetColor(255,255,255);iFilledCircle(g1x-9,g1y+8,8);iFilledCircle(g1x+9,g1y+8,8);}
                iSetColor(0,0,0);iFilledCircle(g1x-9,g1y+10,5);iFilledCircle(g1x+9,g1y+10,5);
            }
             if(mode==3)
            {

                if(fmode==0 || eaten[num-1]==-1){
                iSetColor(255,255,255);iFilledCircle(g1x-9,g1y,8);iFilledCircle(g1x+9,g1y,8);}
                iSetColor(0,0,0);iFilledCircle(g1x-6,g1y,5);iFilledCircle(g1x+12,g1y,5);
            }
               if(mode==2)
            {
                if(fmode==0 || eaten[num-1]==-1){
                iSetColor(255,255,255);iFilledCircle(g1x-9,g1y-9,8);iFilledCircle(g1x+9,g1y-9,8);}
                iSetColor(0,0,0);iFilledCircle(g1x-9,g1y-12,5);iFilledCircle(g1x+9,g1y-12,5);
            }
               if(mode==4)
            {
            if(fmode==0 || eaten[num-1]==-1){
                iSetColor(255,255,255);iFilledCircle(g1x-9,g1y,8);iFilledCircle(g1x+9,g1y,8);}
                iSetColor(0,0,0);iFilledCircle(g1x-11,g1y,5);iFilledCircle(g1x+7,g1y,5);
            }
   }

}
void lvldrw(int L)
{   if(game==1){
                if((L+2)%2==0){

                for(i=0;i<acid;i+=1)
                {
                    iSetColor(255,145,175);
                    iLine(52,i+100,1148,i+100);
                }
                }

     sprintf(str,"%d",score);iSetColor(255,0,0);sprintf(lvl,"%d",L+2);
     iText(550,25,lvl,GLUT_BITMAP_TIMES_ROMAN_24);
    iText(400,25,str,GLUT_BITMAP_TIMES_ROMAN_24);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<50;j++)
        {
            iSetColor(RE,GE,BE);
            iFilledEllipse(lx[L][i],ly[L][i],arm1[L][i]-j,arm2[L][i]-j);
        }
    }
    for(i=2;i<4;i++)
    {
        iSetColor(255,0,0);iFilledCircle(lx[L][i],ly[L][i],arm1[L][i]);
    }
    for(i=4;i<21;i++)
    {
        if(i==6 ||i==7)
        {
            iSetColor(0,250,0);iFilledRectangle(lx[L][i],ly[L][i],arm1[L][i],arm2[L][i]);
            continue;
        }
        for(int j=0;j<16;j++)
        {
            iSetColor((fb/9),0,255-j*13);
            iRectangle(lx[L][i]+j,ly[L][i]+j,arm1[L][i]-j*2,arm2[L][i]-j*2);
        }
    }
    iSetColor(0,0,0);iFilledRectangle(40,400,15,50);
            iFilledRectangle(1145,400,15,50);
            for(i=0;i<10;i++)
            {
                iSetColor(0,0,255-i*20);
                iLine(50,450-i,200,450-i);iLine(1000,450-i,1150,450-i);
            }
             for(i=0;i<10;i++)
            {
                iSetColor(0,0,255-i*20);
                iLine(50,400+i,200,400+i);iLine(1000,400+i,1150,400+i);
            }//enter exit
 for(i=0;i<=1075;i++)
           {
               if(i%4==0)
               iSetColor(255,0,0);
               else if(i%4==1)
                iSetColor(0,255,0);
               else if(i%4==2)
                iSetColor(0,0,255);
                else
                    iSetColor(255,255,0);


                    if(foodstate[i]==1)
                  {     if(i==0 || i==24 || i==1074 || i==1050)
                    {
                      iSetColor(255,0,255);iFilledCircle(foodx[i],foody[i],srad1);
                    }
                  else

                      iFilledCircle(foodx[i],foody[i],4);
                  }


           }


             if(g1m1==1)
                drw(g1x,g1y,20,1,255,0,0,1);
                else if(g1m3==1)
                drw(g1x,g1y,20,3,255,0,0,1);
                else if(g1m2==1)
                   // iFilledCircle(100,100,30);
                drw(g1x,g1y,20,2,255,0,0,1);
                else if(g1m4==1)
                drw(g1x,g1y,20,4,255,0,0,1);
                else drw(g1x,g1y,20,1,255,0,0,1);
            //ghost-2
                if(g2m1==1)
                drw(g2x,g2y,20,1,0,255,0,2);
            else if(g2m3==1)
                drw(g2x,g2y,20,3,0,255,0,2);
                else if(g2m2==1)
                    drw(g2x,g2y,20,2,0,255,0,2);
                else if(g2m4==1)
                drw(g2x,g2y,20,4,0,255,0,2);
                else drw(g2x,g2y,20,4,0,255,0,2);
                //ghst-3
                if(g3m1==1)
                drw(g3x,g3y,20,1,0,0,255,3);
            else if(g3m3==1)
                drw(g3x,g3y,20,3,0,0,255,3);
                else if(g3m2==1)
                    drw(g3x,g3y,20,2,0,0,255,3);
                else if(g3m4==1)
                drw(g3x,g3y,20,4,0,0,255,3);
                else drw(g3x,g3y,20,3,0,0,255,3);
                 if(g4m1==1)
                drw(g4x,g4y,20,1,255,0,255,4);
            else if(g4m3==1)
                drw(g4x,g4y,20,3,255,0,255,4);
                else if(g4m2==1)
                    drw(g4x,g4y,20,2,255,0,255,4);
                else if(g4m4==1)
                drw(g4x,g4y,20,4,255,0,255,4);
                else drw(g4x,g4y,20,3,255,0,255,4);
                if(replicate==1){
                 if(g5m1==1)
                drw(g5x,g5y,20,1,255,0,255,5);
            else if(g5m3==1)
                drw(g5x,g5y,20,3,255,0,255,5);
                else if(g5m2==1)
                    drw(g5x,g5y,20,2,255,0,255,5);
                else if(g5m4==1)
                drw(g5x,g5y,20,4,255,0,255,5);
                }
                if(die==1)
                {
                    iShowBMP(x-25,y-25,"fire.bmp");
                }

    }
}




void changeghosts(void)
{
    if(game==3){if(gpmode==1)gpmode=0;else gpmode=1;}
    if(game==1){

      int bar1=1;
    if(srad1==7)srad1=12;
    else srad1=7;//rad of special ghost
    if(eaten[0]==1)
    { if(g1x==600 && g1y==425)eaten[0]=-1;
         if(g1x==975 || g1x==225)g1x=775;
        if(bar1==1)
        {
            bar1=2;if((g1x==975 || g1x==225)){g1x=775;g1y=325;}
            if(g1y<425)
            {
                if(cons(g1x,g1y+25)==1)g1y+=25;
                else if(g1x>600 && cons(g1x-25,g1y)==1)g1x-=25;
                else if(g1x<600 && cons(g1x+25,g1y)==1)g1x+=25;
                else {g1x=425;g1y=325;}
            }
            else if(g1y>425)
            {
                if(cons(g1x,g1y-25)==1)g1y-=25;
                else if(g1x>600 && cons(g1x-25,g1y)==1)g1x-=25;
                else if(g1x<600 && cons(g1x+25,g1y)==1)g1x+=25;
                else {g1x=425;g1y=425;}
            }
            else
            {
                if(g1x>600 && cons(g1x-25,g1y)==1)g1x-=25;
                else if(g1x<600 && cons(g1x+25,g1y)==1)g1x+=25;
                else if((g1x==975 || g1x==225)){g1x=775;}
            }
        }
        else if(bar1==2)
        {
            bar1=1;
            if(g1x>600)
            {
                if(cons(g1x-25,g1y)==1)g1x-=25;
                else if(g1y>425 && cons(g1x,g1y-25)==1)g1y-=25;
                else if(g1y<425 && cons(g1x,g1y+25)==1)g1y+=25;
            }
            else if(g1x<600)
            {
                if(cons(g1x+25,g1y)==1)g1x+=25;
                else if(g1y>425 && cons(g1x,g1y-25)==1)g1y-=25;
                else if(g1y<425 && cons(g1x,g1y+25)==1)g1y+=25;
            }
            else
            {   g1x=425;    g1y=325;}

        }
        //return;



    }
    else {
    int opt1;
    if(g1state==1)
    {
        if(g1x==x)
        {
            if(g1y>y){g1m2=1;g1m1=g1m3=g1m4=0;}
             if(g1y<y){g1m1=1;g1m2=g1m3=g1m4=0;}
        }
    }
    if(g1m1==1)
    {
        //g1m2=g1m3=g1m4=0;
        g1y+=dy;
        if(g1mode==0)
        {
            if(g1y>=425)
            {
                //g1y=425;
                g1state=1;g1mode=1;
                g2m4=1;
            }
        }
        if(g1state==1)
        {

                   if(L==-1) opt1=checking(g1x,g1y+20);
                   else opt1=cons(g1x,g1y+20);

        if(opt1==0)
        {
            g1y-=dy;

            if(g1sm1==1)
            {
                g1sm1=0;g1m4=1;g1m1=g1m2=g1m3=0;

            }
            else if(g1sm1==0)
            {
                g1sm1=2;g1m2=1;g1m1=g1m4=g1m3=0;
            }
             else if(g1sm1==2)
            {
                g1sm1=1;g1m3=1;g1m1=g1m2=g1m4=0;
            }
            if(g1x==x)
            {
                g1m1=0;g1m2=1;g1m3=0;g1m4=0;
            }
            else
            {
                if(g1x>x)
                {
                   g1m4=1;g1m1=g1m2=g1m3=0;
                }
                else
                {
                    g1m3=1;g1m1=g1m2=g1m4=0;
                }
            }



        }
        }
    }
   else if(g1m3==1)
    {
        //g1m2=g1m1=g1m4=0;
        g1x+=dx;
        //delete here
        if(g1y==425 && (g1x>=1150))g1x=75;
        if(g1state==1)
        {
            if(L==-1)opt1=checking(g1x+5,g1y);
            else opt1=cons(g1x,g1y);
            if(g1y==425 && (g1x<=1150)&&(g1x>=1000))opt1=1;

        if(opt1==0)
        {
            g1x-=dx;
            if(g1sm3==1)
            {
                g1sm3=0;g1m1=1;g1m2=g1m3=g1m4=0;

            }
            else if(g1sm3==0)
            {
                g1sm3=2;g1m4=1;g1m2=g1m3=g1m1=0;
            }
            else if(g1sm3==2)
            {
                g1sm3=1;g1m2=1;g1m1=g1m3=g1m4=0;
            }





        }
        }
    }
    else if(g1m2==1)
    {
        //g1m3=g1m1=g1m4=0;
        g1y-=dy;
        if(L==-1)
        opt1=checking(g1x,g1y-20);
        else
            opt1=cons(g1x,g1y-20);
       // if(opt==1)
           // iFilledCircle(100,100,40);
       if(opt1==0)
        {
           g1y+=dy;
            if(g1sm2==1)
            {
                g1sm2=0;g1m1=1;g1m4=g1m3=g1m2=0;

            }
            else if(g1sm2==0)
            {
                g1sm2=2;g1m3=1;g1m2=g1m1=g1m4=0;
            }
            else if(g1sm2==2)
            {
                g1sm2=1;g1m4=1;g1m2=g1m3=g1m1=0;
            }




        }
    }
     else if(g1m4==1)
    {
       // g1m3=g1m1=g1m2=0;
        g1x-=dx;
        if(L==-1)
        opt1=checking(g1x-20,g1y);
        else
            opt1=cons(g1x-20,g1y);

        if(opt1==0)
        {
            g1x+=dx;
            if(g1sm4==1)
            {
                g1sm4=0;g1m1=1;g1m2=g1m3=g1m4=0;

            }
            else if(g1sm4==0)
            {
                g1sm4=2;g1m2=1;g1m1=g1m3=g1m4=0;
            }
            else if(g1sm4==2)
            {
                g1sm4=1;g1m3=1;g1m1=g1m2=g1m4=0;
            }




        }
    }
    }
}


//second ghost BISMILLAH


  if(game==1){


     int bar2=1;
    //if(srad1==7)srad1=12;
    //else srad1=7;//rad of special ghost
    if(eaten[1]==1)
    {   /*if(g2x==975 || g2x==225)bar=2;*/if(g2x==600 && g2y==425)eaten[1]=-1;
        if(bar2==1)
        {
            bar2=2;if(g2x==225){g2x=425;g2y=325;}
            if(g2x==975){g2x=775;g2y=325;}
            if(g2y<425)
            {
                if(cons(g2x,g2y+25)==1)g2y+=25;
                else if(g2x>600 && cons(g2x-25,g2y)==1)g2x-=25;
                else if(g2x<600 && cons(g2x+25,g2y)==1)g2x+=25;
                 else {g2x=425;g2y=325;}
            }
            else if(g2y>425)
            {
                if(cons(g2x,g2y-25)==1)g2y-=25;
                else if(g2x>600 && cons(g2x-25,g2y)==1)g2x-=25;
                else if(g2x<600 && cons(g2x+25,g2y)==1)g2x+=25;
                else {g2x=425;g2y=425;}
            }
            else
            {
                if(g2x>600 && cons(g2x-25,g2y)==1)g2x-=25;
               else if(g2x<600 && cons(g2x+25,g2y)==1)g2x+=25;
               else if(g2x==975 || g2x==225){g2x=775;}
            }
        }
        else if(bar2==2)
        {
            bar2=1;
            if(g2x>600)
            {
                if(cons(g2x-25,g2y)==1)g2x-=25;
                else if(g2y>425 && cons(g2x,g2y-25)==1)g2y-=25;
                else if(g2y<425 && cons(g2x,g2y+25)==1)g2y+=25;
            }
             else if(g2x<600)
            {
                if(cons(g2x+25,g2y)==1)g2x+=25;
                else if(g2y>425 && cons(g2x,g2y-25)==1)g2y-=25;
                else if(g2y<425 && cons(g2x,g2y+25)==1)g2y+=25;
            }
            else
            {g2x=425;g2y=325;}
        }




    } else{
    int opt2;

    if(g2m1==1)
    {
        g2m2=g2m3=g2m4=0;
        g2y+=dy;

            if(g2state==0){
            if(g2y>=425)
            {
                //g1y=425;
                g2state=1;
                g3m3=1;
            }
            }//hre

         if(g2state==1)
        {
            if(L==-1) opt2=checking(g2x,g2y+20);
            else opt2=cons(g2x,g2y+20);


            if(opt2==0)
            {
                g2y-=dy;
                if(g2sm1==1)
                {
                    g2sm1=0;g2m3=1;g2m1=g2m4=g2m2=0;

                }
                else if(g2sm1==0)
                {
                    g2sm1=2;g2m2=1;g2m1=g2m4=g2m3=0;
                }
                 else if(g2sm1==2)
                {
                    g2sm1=1;g2m4=1;g2m1=g2m3=g2m2=0;
                }
            }
        }

    }
   else if(g2m3==1)
    {
        g2m2=g2m1=g2m4=0;
        g2x+=dx;
        if(g2y==425 && g2x>=1150)g2x=75;
        if(g2state==1)
        {
            if(L==-1) opt2=checking(g2x+5,g2y);
            else opt2=cons(g2x+5,g2y);
            if(g2y==425 && (g2x<=1175)&&(g2x>=1000))opt2=1;

        if(opt2==0)
        {
            g2x-=dx;
            if(g2sm3==1)
            {
                g2sm3=0;g2m4=1;g2m1=g2m3=g2m2=0;
            }
            else if(g2sm3==0)
            {
                g2sm3=2;g2m2=1;g2m1=g2m4=g2m3=0;
            }
            else if(g2sm3==2)
            {
                g2sm3=1;g2m1=1;g2m3=g2m4=g2m2=0;
            }
        }
        }
    }
    else if(g2m2==1)
    {
        g2m3=g2m1=g2m4=0;
        g2y-=dy;
        if(L==-1)
        {

        opt2=checking(g2x,g2y-20);
        }
        else opt2=cons(g2x,g2y-20);

       if(opt2==0)
        {
            g2y+=dy;
            if(g2sm2==1)
            {
                g2sm2=0;g2m4=1;g2m1=g2m3=g2m2=0;

            }
            else if(g2sm2==0)
            {
                g2sm2=2;g2m3=1;g2m1=g2m4=g2m2=0;
            }
            else if(g2sm2==2)
            {
                g2sm2=1;g2m1=1;g2m3=g2m4=g2m2=0;
            }
        }
    }
     else if(g2m4==1)
    {
        g2m3=g2m1=g2m2=0;
        g2x-=dx;
        if(g2start==0)
        {
            if(g2x==600)
            {
                g2m1=1;
                g2start=1;
            }
        }
        if(L==-1)
        opt2=checking(g2x-20,g2y);
        else
            opt2=cons(g2x-20,g2y);
        if(opt2==0)
        {
            g2x+=dx;
            if(g2sm4==1)
            {
                g2sm4=0;g2m1=1;g2m3=g2m4=g2m2=0;

            }
            else if(g2sm4==0)
            {
                g2sm4=2;g2m2=1;g2m1=g2m4=g2m3=0;
            }
            else if(g2sm4==2)
            {
                g2sm4=1;g2m3=1;g2m1=g2m4=g2m2=0;
            }
        }
    }
   }
  }


if(game==1){
     int bar3=1;
    //if(srad1==7)srad1=12;
    //else srad1=7;//rad of special ghost
    if(eaten[2]==1)
    {   //if(g2x==975 || g2x==225)bar=2;
        if(g3x==600 && g3y==425)eaten[2]=-1;
        if(bar3==1)
        {
            bar3=2;if((g3x==975 || g3x==225)){g3x=425;g3y=325;}
            if(g3y<425)
            {
                if(cons(g3x,g3y+25)==1)g3y+=25;
                else if(g3x>600 && cons(g3x-25,g3y)==1)g3x-=25;
                else if(g3x<600 && cons(g3x+25,g3y)==1)g3x+=25;
                else {g3x=425;g3y=325;}
            }
            else if(g3y>425)
            {
                if(cons(g3x,g3y-25)==1)g3y-=25;
                else if(g3x>600 && cons(g3x-25,g3y)==1)g3x-=25;
                else if(g3x<600 && cons(g3x+25,g3y)==1)g3x+=25;
                else{g3x=425;g3y=325;}
            }
            else
            {
                if(g3x>600 && cons(g3x-25,g3y)==1)g3x-=25;
                else if(g3x<600 && cons(g3x+25,g3y)==1)g3x+=25;
                else if(g3x==975 || g3x==225){g3x=775;}
            }
        }
        else if(bar3==2)
        {
            bar3=1;
            if(g3x>600)
            {
                if(cons(g3x-25,g3y)==1)g3x-=25;
                else if(g3y>425 && cons(g3x,g3y-25)==1)g3y-=25;
                else if(g3y<425 && cons(g3x,g3y+25)==1)g3y+=25;
            }
             else if(g3x<600)
            {
                if(cons(g3x+25,g3y)==1)g3x+=25;
                else if(g3y>425 && cons(g3x,g3y-25)==1)g3y-=25;
                else if(g3y<425 && cons(g3x,g3y+25)==1)g3y+=25;
            }
            else
            {g3x=425;g3y=325;}
        }




    } else{
    int opt3;


    if(g3m1==1)
    {
        g3m2=g3m3=g3m4=0;
        g3y+=dy;



        if(g3y==425)
        {
            g3state=1;
            g4m3=1;
        }

        if(g3state==1)
        {
            if(L==-1) opt3=checking(g3x,g3y+20);
            else opt3=cons(g3x,g3y+20);
        }

        if(opt3==0)
        {
            g3y-=dy;
            if(g3sm1==1)
            {
                g3sm1=0;g3m4=1;g3m1=g3m2=g3m3=0;

            }
            else if(g3sm1==0)
            {
                g3sm1=2;g3m3=1;g3m1=g3m2=g3m4=0;
            }
             else if(g3sm1==2)
            {
                g3sm1=1;g3m4=1;g3m1=g3m2=g3m3=0;
            }

        }
    }
   else if(g3m3==1)
    {
        g3m2=g3m1=g3m4=0;
        g3x+=dx;
        if(g3y==425 && g3x>=1150)g3x=75;


            if(g3x==600)
            {
                g3m1=1;g3start=1;

            }

        if(g3state==1)
        {
            if(L==-1) opt3=checking(g3x+5,g3y);
            else opt3=cons(g3x+5,g3y);
             if(g3y==425 && (g3x<=1175)&&(g3x>=1000))opt3=1;

        if(opt3==0)
        {
            g3x-=dx;
            if(g3sm3==1)
            {
                g3sm3=0;g3m4=1;g3m1=g3m2=g3m3=0;

            }
            else if(g3sm3==0)
            {
                g3sm3=2;g3m3=1;g3m1=g3m2=g3m4=0;
            }
            else if(g3sm3==2)
            {
                g3sm3=1;g3m2=1;g3m1=g3m4=g3m3=0;
            }
        }
        }
    }
    else if(g3m2==1)
    {
        g3m3=g3m1=g3m4=0;
        g3y-=dy;
        if(L==-1)
        {

        opt3=checking(g3x,g3y-20);
        }
        else opt3=cons(g3x,g3y-20);
       // if(opt==1)
           // iFilledCircle(100,100,40);
       if(opt3==0)
        {
            g3y+=dy;
            if(g3sm2==1)
            {
                g3sm2=0;g3m3=1;g3m1=g3m2=g3m4=0;

            }
            else if(g3sm2==0)
            {
                g3sm2=2;g3m4=1;g3m1=g3m2=g3m3=0;
            }
            else if(g3sm2==2)
            {
                g3sm2=1;g3m1=1;g3m4=g3m2=g3m3=0;
            }
        }
    }
     else if(g3m4==1)
    {
        g3m3=g3m1=g3m2=0;
        g3x-=dx;
        if(g3x==650)
        {
            g3m1=1;
        }
        if(L==-1)
        opt3=checking(g3x-20,g3y);
        else
            opt3=cons(g3x-20,g3y);
        if(opt3==0)
        {
            g3x+=dx;
            if(g3sm4==1)
            {
                g3sm4=0;g3m2=1;g3m1=g3m4=g3m3=0;

            }
            else if(g3sm4==0)
            {
                g3sm4=2;g3m3=1;g3m1=g3m2=g3m4=0;
            }
            else if(g3sm4==2)
            {
                g3sm4=1;g3m1=1;g3m4=g3m2=g3m3=0;
            }
        }
    }
}
}



if(game==1){
       int bar4=1;
    //if(srad1==7)srad1=12;
    //else srad1=7;//rad of special ghost
    if(eaten[3]==1)
    {   //if(g2x==975 || g2x==225)bar=2;
        if(g4x==600 && g4y==425)eaten[3]=-1;
        if(bar4==1)
        {
            bar4=2;if((g4x==975 || g4x==225)){g4x=775;}
            if(g4y<425)
            {
                if(cons(g4x,g4y+25)==1)g4y+=25;
                else if(g4x>600 && cons(g4x-25,g4y)==1)g4x-=25;
                else if(g4x<600 && cons(g4x+25,g4y)==1)g4x+=25;
                else{g4x=425;g4y=325;}
            }
            else if(g4y>425)
            {
                if(cons(g4x,g4y-25)==1)g4y-=25;
                else if(g4x>600 && cons(g4x-25,g4y)==1)g4x-=25;
                else if(g4x<600 && cons(g4x+25,g4y)==1)g4x+=25;
                else{g4x=425;g4y=325;}
            }
            else
            {
                if(g4x>600 && cons(g4x-25,g4y)==1)g4x-=25;
                else if(g4x<600 && cons(g4x+25,g4y)==1)g4x+=25;
                else if(g4x==975 || g4x==225){g4x=775;}
            }
        }
        else if(bar4==2)
        {
            bar4=1;
            if(g4x>600)
            {
                if(cons(g4x-25,g4y)==1)g4x-=25;
                else if(g4y>425 && cons(g4x,g4y-25)==1)g4y-=25;
                else if(g4y<425 && cons(g4x,g4y+25)==1)g4y+=25;
            }
             else if(g4x<600)
            {
                if(cons(g4x+25,g4y)==1)g4x+=25;
                else if(g4y>425 && cons(g4x,g4y-25)==1)g4y-=25;
                else if(g4y<425 && cons(g4x,g4y+25)==1)g4y+=25;
            }
            else
            {g4x=425;g4y=325;}
        }
}  else {
     int opt4;
    if(gpmode==0)gpmode=1;
    else
        gpmode=0;


    if(g4m1==1)
    {
        g4m2=g4m3=g4m4=0;
        g4y+=dy;
        if(g4y==425)
        {
            g4state=1;
        }
        if(g4state==1)
        {
            if(L==-1) opt4=checking(g4x,g4y+20);
            else opt4=cons(g4x,g4y+20);
        }
        if(opt4==0)
        {
            g4y-=dy;
            if(g4sm1==1)
            {
                g4sm1=0;g4m3=1;g4m1=g4m2=g4m4=0;

            }
            else if(g4sm1==0)
            {
                g4sm1=2;g4m2=1;g4m1=g4m4=g4m3=0;
            }
             else if(g4sm1==2)
            {
                g4sm1=1;g4m4=1;g4m1=g4m2=g4m3=0;
            }
        }
    }
   else if(g4m3==1)
    {
        g4m2=g4m1=g4m4=0;
        g4x+=dx;


            if(g4x==600 && g4start==0)
            {
                g4m1=1;g4start=1;

            }
            if(g4y==425 && g4x>=1150)g4x=75;

        if(g4state==1)
        {
            if(L==-1) opt4=checking(g4x+5,g4y);
            else opt4=cons(g4x+5,g4y);
            if(g4y==425 && (g4x<=1175)&&(g4x>=1000))opt4=1;
        }
        if(opt4==0)
        {
            g4x-=dx;
            if(g4sm3==1)
            {
                g4sm3=0;g4m2=1;g4m1=g4m3=g4m4=0;

            }
            else if(g4sm3==0)
            {
                g4sm3=2;g4m4=1;g4m2=g4m3=g4m1=0;
            }
            else if(g4sm3==2)
            {
                g4sm3=1;g4m1=1;g4m2=g4m3=g4m4=0;
            }
        }
    }
    else if(g4m2==1)
    {
        g4m3=g4m1=g4m4=0;
        g4y-=dy;
        if(L==-1)
        {

        opt4=checking(g4x,g4y-20);
        }
        else opt4=cons(g4x,g4y-20);
       // if(opt==1)
           // iFilledCircle(100,100,40);
       if(opt4==0)
        {
            g4y+=dy;
            if(g4sm2==1)
            {
                g4sm2=0;g4m4=1;g4m1=g4m3=g4m2=0;

            }
            else if(g4sm2==0)
            {
                g4sm2=2;g4m3=1;g4m2=g4m1=g4m4=0;
            }
            else if(g4sm2==2)
            {
                g4sm2=1;g4m1=1;g4m2=g4m3=g4m4=0;
            }
        }
    }
     else if(g4m4==1)
    {
        g4m3=g4m1=g4m2=0;
        g4x-=dx;
        if(g4x==650)
        {
            g4m1=1;
        }
        if(L==-1)
        opt4=checking(g4x-20,g4y);
        else
            opt4=cons(g4x-20,g4y);
        if(opt4==0)
        {
            g4x+=dx;
            if(g4sm4==1)
            {
                g4sm4=0;g4m1=1;g4m2=g4m3=g4m4=0;

            }
            else if(g4sm4==0)
            {
                g4sm4=2;g4m2=1;g4m1=g4m3=g4m4=0;
            }
            else if(g4sm4==2)
            {
                g4sm4=1;g4m3=1;g4m1=g4m2=g4m4=0;
            }
        }
    }
}
}

    if(game==1){
    if(replicate==1)
    {


     int opt5;
    if(g5m1==1)
    {
        g5m2=g5m3=g5m4=0;
        g5y+=dy;

            if(L==-1) opt5=checking(g5x,g5y+20);
            else opt5=cons(g5x,g5y+20);

        if(opt5==0)
        {
            g5y-=dy;
            if(g5sm1==1)
            {
                g5sm1=0;g5m3=1;g5m1=g5m2=g5m4=0;

            }
            else if(g5sm1==0)
            {
                g5sm1=2;g5m2=1;g5m1=g5m4=g5m3=0;
            }
             else if(g5sm1==2)
            {
                g5sm1=1;g5m4=1;g5m1=g5m2=g5m3=0;
            }
        }
    }
   else if(g5m3==1)
    {
        g5m2=g5m1=g5m4=0;
        g5x+=dx;
            if(g5y==425 && g5x>=1150)g5x=75;


            if(L==-1) opt5=checking(g5x+5,g5y);
            else opt5=cons(g5x+5,g5y);
            if(g5y==425 && (g5x<=1175)&&(g5x>=1000))opt5=1;

        if(opt5==0)
        {
            g5x-=dx;
            if(g5sm3==1)
            {
                g5sm3=0;g5m2=1;g5m1=g5m3=g5m4=0;

            }
            else if(g5sm3==0)
            {
                g5sm3=2;g5m4=1;g5m2=g5m3=g5m1=0;
            }
            else if(g5sm3==2)
            {
                g5sm3=1;g5m1=1;g5m2=g5m3=g5m4=0;
            }
        }
    }
    else if(g5m2==1)
    {
        g5m3=g5m1=g5m4=0;
        g5y-=dy;
        if(L==-1)
        {

        opt5=checking(g5x,g5y-20);
        }
        else opt5=cons(g5x,g5y-20);
       // if(opt==1)
           // iFilledCircle(100,100,40);
       if(opt5==0)
        {
            g5y+=dy;
            if(g5sm2==1)
            {
                g5sm2=0;g5m4=1;g5m1=g5m3=g5m2=0;

            }
            else if(g5sm2==0)
            {
                g5sm2=2;g5m3=1;g5m2=g5m1=g5m4=0;
            }
            else if(g5sm2==2)
            {
                g5sm2=1;g5m1=1;g5m2=g5m3=g5m4=0;
            }
        }
    }
     else if(g5m4==1)
    {
        g5m3=g5m1=g5m2=0;
        g5x-=dx;
        if(g5x==650)
        {
            g5m1=1;
        }
        if(L==-1)
        opt5=checking(g5x-20,g5y);
        else
            opt5=cons(g5x-20,g5y);
        if(opt5==0)
        {
            g5x+=dx;
            if(g5sm4==1)
            {
                g5sm4=0;g5m1=1;g5m2=g5m3=g5m4=0;

            }
            else if(g5sm4==0)
            {
                g5sm4=2;g5m2=1;g5m1=g5m3=g5m4=0;
            }
            else if(g5sm4==2)
            {
                g5sm4=1;g5m3=1;g5m1=g5m2=g5m4=0;
            }
        }
    }
    }
    }

}

/*void gp(void)
{
     if(gpmode==1)gpmode=0;
        else gpmode=1;
}*/
void changemukh(void)
{
    if(game==3)
    {
        if(hpmode==1){hpx1-=3;
        if(hpx1==150){hpx1=750;}}
        if(hpmukh1==1)hpmukh1=0;
        else hpmukh1=1;
        if(hpmode==2 && hpkhawa==0)
        {
            hpx2+=3;
            if(hpx2==500)
            {
                hpkhawa=1;
            }
        }
    }//frst box er kahini

    if(state==1)
        state=0;
    else
        state=1;

        if(game==1){
        if(lives[0]==-1 && lives[1]==-1 && lives[2]==-1 && (lives[3]==-1|| lives[3]==0))
            {gameover=1;iPauseTimer(1);iPauseTimer(2);iPauseTimer(4);
        }}
       if(game==1 && die==0)
        {
            if(fmode==0){
            if(abs(g1x-x)<=15 && abs(g1y-y)<=15){die=1;d=d+1;}
             if(abs(g2x-x)<=15 && abs(g2y-y)<=15){die=1;d=d+1;}
            if(abs(g3x-x)<=15 && abs(g3y-y)<=15){die=1;d=d+1;}
            if(abs(g4x-x)<=15 && abs(g4y-y)<=15){die=1;d=d+1;}
            if(replicate==1){if(abs(g5x-x)<=15 && abs(g5y-y)<=15){die=1;d=d+1;}}}
            if(die==1)
                {
                   iPauseTimer(1);iPauseTimer(2);iPauseTimer(4);
                   for(i=0;i<d;i++)
                   {
                       if(lives[i]==1)
                       {
                           lives[i]=-1;
                       }
                   }
                }
        }


        if(game==1){
                if(acidmode==1)
                {
                    if((acid+100)>y)
                    {
                        printf("acid here.\n");
                        //game=12;
                        iPauseTimer(1);iPauseTimer(2);iPauseTimer(4);
                        gameover=1;
                    }
                }


        for(i=0;i<1075;i++)
        {
           // if(foodx[i]<(x+4+rad)&&foodx[i]>=(x-(4+rad))&& foody[i]<=(y+4+rad)&&foody[i]>=(y-(4+rad)))
           if(abs(foodx[i]-x)<=20 && abs(foody[i]-y)<=20)
              {
                  if(foodstate[i]==1){
                    fb=fb+1;score=score+5;
                  foodstate[i]=0;
                  if(foodstate[0]==0)
                {foodstate[0]=-1;fmode=1;replicate=0;f1=1;for(j=0;j<4;j++)eaten[j]=0;score+=100;}
                if(foodstate[24]==0){foodstate[24]=-1;fmode=1;replicate=0;f2=1;for(j=0;j<4;j++)eaten[j]=0;score+=100;}

        if(foodstate[1074]==0){foodstate[1074]=-1;replicate=0;fmode=1;f4=1;for(j=0;j<4;j++)eaten[j]=0;score+=100;}

                  if(foodstate[1050]==0){foodstate[1050]=-1;replicate=0;fmode=1;f3=1;for(j=0;j<4;j++)eaten[j]=0;score+=100;}
                  }

                  //foodstate[i]=0;

              }
        }
       if(abs(x-770)<=20 && abs(y-350)<=20)lives[3]=1;
        if(fmode==1)
        {
            if((abs(x-g1x)<=25 && abs(y-g1y)<=25)&&(eaten[0]!=-1)) eaten[0]=1;
            if((abs(x-g2x)<=25 && abs(y-g2y)<=25)&&eaten[1]!=-1) eaten[1]=1;
            if((abs(x-g3x)<=25 && abs(y-g3y)<=25)&&eaten[2]!=-1) eaten[2]=1;
            if((abs(x-g4x)<=25 && abs(y-g4y)<=25)&&eaten[3]!=-1) eaten[3]=1;

        }
        if(f1==1){if(abs(x-525)<=30 &&(abs(y-425)<=20)){score=score+50;f1=-1;}}
        if(f2==1){if(abs(x-525)<=30 &&(abs(y-425)<=20)){score=score+50;f2=-1;}}
        if(f3==1){if(abs(x-525)<=30 &&(abs(y-425)<=20)){score=score+50;f3=-1;}}//here
         if(f4==1){if(abs(x-525)<=30 &&(abs(y-425)<=20)){score=score+50;dragon=1;iPauseTimer(2);f4=-1;}}
}
}

int checking(int _x,int _y)
{
    int ok=1;
    if((_x>=100 && _x<=250 )&&(_y>=600 && _y<=700 )) ok=0;
    else if((_x>=350  && _x<=450 )&&(_y>= 600&& _y<=700)) ok=0;
    else if((_x>=550  && _x<=650 )&&(_y>=650 && _y<=750 )) ok=0;
    else if((_x>=750  && _x<=850 )&&(_y>=600 && _y<= 700)) ok=0;
    else if((_x>=950  && _x<=1100 )&&(_y>=600 && _y<=700 )) ok=0;
    else if((_x>=150  && _x<=200 )&&(_y>=500&& _y<=550 )) ok=0;
    //else if((_x>=450  && x<=750 )&&(_y>=500 && _y<=550 )) ok=0;
    else if((_x>=550  && _x<=650 )&&(_y>=450 && _y<=550 )) ok=0;
    else if((_x>=1000  && _x<=1050 )&&(_y>=500 && _y<=550)) ok=0;
    else if((_x>=250  && _x<=350 )&&(_y>=300 && _y<=500 )) ok=0;
    else if((_x>=850  && _x<=950 )&&(_y>=300 && _y<=500 )) ok=0;
    else if((_x>=450  && _x<=750 )&&(_y>=300 && _y<=400 )) ok=0;
    else if((_x>= 50 && _x<=150 )&&(_y>=250 && _y<=300 )) ok=0;
    else if((_x>= 1050 && _x<=1150 )&&(_y>=250 && _y<=300 )) ok=0;
    else if((_x>=550 && _x<=650 )&&(_y>=150 && _y<=250 )) ok=0;
        else if((_x>=800 && _x<=850 )&&(_y>=200 && _y<=250 )) ok=0;
    else if((_x>=350 && _x<=400 )&&(_y>=200 && _y<=250 )) ok=0;
    else if (_x<=50 || _x>=1150 || _y<=100 || _y>=750) ok=0;
    else if((_x>=100 && _x<=500 )&&(_y>=150 && _y<=200 )) ok=0;
    else if((_x>=700 && _x<=1100 )&&(_y>=150 && _y<=200 )) ok=0;
    else if((_x>=450 && _x<=750) && (_y>=500 && _y<=550)) ok=0;
    else if((_x>=50 && _x<=200)&&((_y)<=450 && (_y)>=400))ok=0;
     else if((_x>=1000 && _x<=1150)&&((_y)<=450 && (_y)>=400))ok=0;
     else if((_x>=1000 && _x<=1150)&&((_y)>=450 && (_y)<=400))ok=0;
     else if((_x>=50 && _x<=200)&&((_y)>=450 && (_y)<=400))ok=0;


     if(_y==425 && (_x<=200 && _x>=50))ok=1;
      if(_y==425 && (_x<=1175 && _x>=1000))ok=1;




    return ok;
}


/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(game==12)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx<=(1050+80) && mx>=1050 && my<=60 && my>=30){
                    if((fp2=fopen("countscr.bin","rb"))==NULL)
        {
            printf("error in this");
        }
        fread(&h,sizeof(int),1,fp2);
        h=h+1;
        fclose(fp2);
        fp2=fopen("countscr.bin","wb");
        fwrite(&h,sizeof(int),1,fp2);
        fclose(fp2);
        if((fp1=fopen("scores.bin","ab"))==NULL)
        {
            printf("error opening file.");
        }

        fwrite(&score,sizeof(int),1,fp1);
        fclose(fp1);
        printf("H IS NOW %d\n",h);

                   game=5;

        }
    }
    }

    if(game==8)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx<=(1050+80) && mx>=1050 && my<=60 && my>=30){game=2;}
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {   int okk=0;
            if(mx<=380 && mx>=300 && my<=570 && my>=500){if(upto>=1){game=1;L=-1;okk=1;}}
            if(mx<=380 && mx>=300 && my<=470 && my>=400){if(upto>=2){game=1;L=0;okk=1;}}
            if(mx<=380 && mx>=300 && my<=370 && my>=300){if(upto>=3){game=1;L=1;okk=1;}}
            if(mx<=380 && mx>=300 && my<=270 && my>=200){if(upto>=4){game=1;L=2;okk=1;}}
             if(mx<=480 && mx>=400 && my<=570 && my>=500){if(upto>=5){game=1;L=3;okk=1;}}
            if(mx<=480 && mx>=400 && my<=470 && my>=400){if(upto>=6){game=1;L=4;okk=1;}}
            if(mx<=480 && mx>=400 && my<=370 && my>=300){if(upto>=7){game=1;L=5;okk=1;}}
            if(mx<=480 && mx>=400 && my<=270 && my>=200){if(upto>=8){game=1;L=6;okk=1;}}
            if(mx<=580 && mx>=500 && my<=570 && my>=500){if(upto>=9){game=1;L=7;okk=1;}}
            if(mx<=580 && mx>=500 && my<=470 && my>=400){if(upto>=10){game=1;L=8;okk=1;}}
            if(mx<=580 && mx>=500 && my<=370 && my>=300){if(upto>=11){game=1;L=9;okk=1;}}
            if(mx<=580 && mx>=500 && my<=270 && my>=200){if(upto>=12){game=1;L=10;okk=1;}}
               if(mx<=680 && mx>=600 && my<=570 && my>=500){if(upto>=13){game=1;L=11;okk=1;}}
            if(mx<=680 && mx>=600 && my<=470 && my>=400){if(upto>=14){game=1;L=12;okk=1;}}
            if(mx<=680 && mx>=600 && my<=370 && my>=300){if(upto>=15){game=1;L=13;okk=1;}}
            if(mx<=680 && mx>=600 && my<=270 && my>=200){if(upto>=16){game=1;L=14;okk=1;}}
        if(okk==1){
        if(L==-1)
        {
            i=0;

            for(ii=75;ii<1150;ii=ii+25){
            for(jj=125;jj<750;jj+=25){
                        foodx[i]=ii;foody[i]=jj;
                        if(checking(foodx[i],foody[i])==1)
                        foodstate[i]=1;
                        else foodstate[i]=0;
        if(foodx[i]<=850 && foodx[i]>=375 && foody[i]>=250 && foody[i]<=450)foodstate[i]=0;
        if(foodx[i]<=200 && foodx[i]>=50 && foody[i]>=375 && foody[i]<=500)foodstate[i]=0;
        if(foodx[i]<=1150 && foodx[i]>=950 && foody[i]>=375 && foody[i]<=500)foodstate[i]=0;
                        i++;

                        }}

        }

    else{   if((L+2)%2==0){acidmode=1;}

            i=0;
                for(ii=75;ii<1150;ii=ii+25){
                    for(jj=125;jj<750;jj+=25){
                        foodx[i]=ii;foody[i]=jj;foodstate[i]=1;i++;}}

    for(int j=0;j<1075;j++)
    {int ok=1;int r=foodx[j],s=foody[j];
        for(i=0;i<4;i++){
        if( r<=(lx[L][i]+arm1[L][i]) && r>=(lx[L][i]-arm1[L][i])&& s<=(ly[L][i]+arm2[L][i])&& s>=(ly[L][i]-arm2[L][i]))
        ok=0;}
    for(i=4;i<21;i++){
                if(r>=lx[L][i] && r<=(lx[L][i]+arm1[L][i])&& s>=ly[L][i] && s<=(ly[L][i]+arm2[L][i]))
                    ok=0;}
            if(r>=1150 || r<=50 || s>=750 ||s<=100)ok=0;
            if(ok==0)
                foodstate[j]=0;
          if(foodx[j]<=850 && foodx[j]>=375 && foody[j]>=250 && foody[j]<=450)foodstate[j]=0;
        if(foodx[j]<=200 && foodx[j]>=50 && foody[j]>=375 && foody[j]<=500)foodstate[j]=0;
        if(foodx[j]<=1150 && foodx[j]>=950 && foody[j]>=375 && foody[j]<=500)foodstate[j]=0;}
       }



         x=600;y=275;f1=f2=f3=0;f1=f2=f3=f4=0;
        //ghost1ke box e pathai
        g1x=600;g1y=350;g1state=g2start=g2state=g3state=g3start=g4start=g4state=g1mode=0;
        g1sm1=g1sm2=g1sm3=g1sm4=g2sm1=g2sm2=g2sm3=g2sm4=1;
        g3sm1=g3sm2=g3sm3=g3sm4=g4sm1=g4sm2=g4sm3=g4sm4=1;
        g2x=650;g2y=350;
        g3x=550;g3y=350;
        g4x=500;
        g4y=350;fb=0;lives[3]=0;
        g1m1=1;g1m2=g1m3=g1m4=g2m1=g2m2=g2m3=g2m4=g3m1=g3m2=g3m3=g3m4=0;
        g4m1=g4m2=g4m3=g4m4=0;replicate=0;
        for(i=0;i<4;i++)eaten[i]=0;fmode=0;
        g5m1=0;g5m2=0;g5m3=0;g5m4=0;g5sm1=0;g5sm2=0;g5sm3=0;g5sm4=0;g5x=450;g5y=350;}}
}

    if(game==3)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx<=800 && mx>=400 && my<=660 && my>=600){
            hpmode=1;hpx2=230;hpkhawa=0;}
             if(mx<=1000 && mx>=200 && my<=550 && my>=500)
             {
                 hpmode=2;hpx1=480;

             }
             if(mx<=(1050+80) && mx>=1050 && my<=60 && my>=30){game=prev;}
        }

    }
    if(game==4)
    {   if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        if(mx<=(1050+80) && mx>=1050 && my<=60 && my>=30){game=2;}
    }
    if(game==7)
    {   if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        if(mx<=(1050+80) && mx>=1050 && my<=60 && my>=30){game=2;}
    }
     if(game==6)
    {   if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        if(mx<=(1050+80) && mx>=1050 && my<=60 && my>=30){game=2;}
    }
    if(game==1)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx<=1190 && mx>=1130 && my<=790 && my>=760)
            {
                if( (fp=fopen("mfile.bin","wb"))==NULL){printf("cant open");}
                    if(fwrite(&L,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&x,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&y,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g1x,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g1y,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g2x,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g2y,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g3x,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g3y,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g4x,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g4y,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&fb,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&score,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g1m1,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g1m2,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g1m3,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g1m4,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g2m1,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g2m2,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g2m3,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g2m4,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g3m1,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g3m2,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g3m3,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g3m4,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g4m1,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g4m2,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g4m3,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g4m4,sizeof(int),1,fp)!=1){printf("prb");}
                            if(fwrite(&g1state,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g2start,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g2state,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g3state,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g3start,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g4start,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g4state,sizeof(int),1,fp)!=1){printf("prb");}
                    if(fwrite(&g1mode,sizeof(int),1,fp)!=1){printf("prb");}
                     //if(fwrite(&g1mode,sizeof(int),1,fp)!=1){printf("prb");}
                     if(fwrite(&fmode,sizeof(int),1,fp)!=1){printf("prb");}
                       if(fwrite(&eaten[0],sizeof(int),1,fp)!=1){printf("prb");}
                        if(fwrite(&eaten[1],sizeof(int),1,fp)!=1){printf("prb");}
                         if(fwrite(&eaten[2],sizeof(int),1,fp)!=1){printf("prb");}
                         if(fwrite(&eaten[3],sizeof(int),1,fp)!=1){printf("prb");}
                          if(fwrite(&f1,sizeof(int),1,fp)!=1){printf("prb");}
                         if(fwrite(&f2,sizeof(int),1,fp)!=1){printf("prb");}
                         if(fwrite(&f3,sizeof(int),1,fp)!=1){printf("prb");}
                          if(fwrite(&resume,sizeof(int),1,fp)!=1){printf("prb");}
                           if(fwrite(&f4,sizeof(int),1,fp)!=1){printf("prb");}
                    for(i=0;i<1074;i++)
                    {
                        fwrite(&foodstate[i],sizeof(int),1,fp);
                    }

                   fclose(fp);//ekhan thk delete koro
           if((fp2=fopen("countscr.bin","rb"))==NULL)
        {
            printf("error in this");
        }
        fread(&h,sizeof(int),1,fp2);
        h=h+1;
        fclose(fp2);
        fp2=fopen("countscr.bin","wb");
        fwrite(&h,sizeof(int),1,fp2);
        fclose(fp2);
        if((fp1=fopen("scores.bin","ab"))==NULL)
        {
            printf("error opening file.");
        }

        fwrite(&score,sizeof(int),1,fp1);
        fclose(fp1);
        printf("H IS NOW %d\n",h);

                   game=5;

            }
            if(mx>=1040 && mx<=1105 && my<=790 && my>=760){game=2;}//manu
            if(mx>=900 && mx<=1020 && my<=790 && my>=760){prev=game;game=3;}//help page
             if(mx>=810 && mx<=841 && my<=790 && my>=760){music=0;PlaySound(NULL,0,0);}
        }
    }
    if(game==0)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx<=580 && mx>=500 && my<=310 && my>=270)
            {
                game=2;
            }

        }//next e click e front page 2
    }

    if(game==2)
    {
         if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        if(mx>=400 && mx<=600 && my>=100 && my<=130){game=8;}
        if(mx>=400 && mx<=600 && my>=200 && my<=235){game=1;}
        if(mx>=400 && mx<=600 && my>=150 && my<=180)
        {
                     fp=fopen("mfile.bin","rb");
        if(fread(&L,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&x,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&y,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g1x,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g1y,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g2x,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g2y,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g3x,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g3y,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g4x,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g4y,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&fb,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&score,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g1m1,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g1m2,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g1m3,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g1m4,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g2m1,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g2m2,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g2m3,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g2m4,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g3m1,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g3m2,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g3m3,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g3m4,sizeof(int),1,fp)!=1){printf("prb");}
         if(fread(&g4m1,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g4m2,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g4m3,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g4m4,sizeof(int),1,fp)!=1){printf("prb");}
         if(fread(&g1state,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g2start,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g2state,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g3state,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g3start,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g4start,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g4state,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&g1mode,sizeof(int),1,fp)!=1){printf("prb");}
        //if(fread(&score,sizeof(int),1,fp)!=1){printf("prb");}
        if(fread(&fmode,sizeof(int),1,fp)!=1){printf("prb");}
           if(fread(&eaten[0],sizeof(int),1,fp)!=1){printf("prb");}
            if(fread(&eaten[1],sizeof(int),1,fp)!=1){printf("prb");}
             if(fread(&eaten[2],sizeof(int),1,fp)!=1){printf("prb");}
             if(fread(&eaten[3],sizeof(int),1,fp)!=1){printf("prb");}
              if(fread(&f1,sizeof(int),1,fp)!=1){printf("prb");}
                if(fread(&f2,sizeof(int),1,fp)!=1){printf("prb");}
                if(fread(&f3,sizeof(int),1,fp)!=1){printf("prb");}
                if(fread(&resume,sizeof(int),1,fp)!=1){printf("prb");}
                if(fread(&f4,sizeof(int),1,fp)!=1){printf("prb");}

        for(i=0;i<1074;i++)
        {
            fread(&foodstate[i],sizeof(int),1,fp);
        }
        game=1;


       fclose(fp);//works just fin
                    //fclose(fp);//works just fin

         }
         if(mx>=400 && mx<=700 && my<=85 && my>=50 )
         {
             fp2=fopen("countscr.bin","rb");
            if (fread(&h,sizeof(int),1,fp2)!=1){printf("error here 1749");}
             printf("the value is %d",h);
             fclose(fp2);
             fp1=fopen("scores.bin","rb");

                 for(i=0;i<h;i++)
                 {
                     fread(&number[i],sizeof(int),1,fp1);
                     printf("numbers are %d\n",number[i]);
                     number2[i]=number[i];
                 }

            // printf("this is %d",number[0]);
             fclose(fp1);
             for(i=0;i<h;i++)
             {
                 for(j=i+1;j<h;j++)
                 {
                     if(number[j]>=number[i])
                     {
                         t=number[j];
                         number[j]=number[i];
                         number[i]=t;
                     }
                 }
             }
             if((fp3=fopen("names.txt","r"))==NULL)
             {
                 printf("error");
             }
             /*fgets(str3,20,fp3);
             fclose(fp3);
             printf("\n");
             printf("%s",str3);*/
             for(i=0;i<h;i++)
             {
                 //fgets(&names[i],20,fp3);
                //fscanf(fp3,"%s",names[i]);
                fgets(names[i],20,fp3);
                printf("%s\n",names[i]);
                strcpy(names2[i],names[i]);
             }
             //printf("the scorer are %s\n %s",names[0],names[1]);
             fclose(fp3);
             for(i=0;i<h && i<10;i++)
             {
                 for(j=0;j<h;j++)
                 {
                    if(number[i]==number2[j])
                    {
                        strcpy(names[i],names2[j]);
                    }
                 }
             }
             game=4;
        }

         if(mx>=700 && mx<=900 && my>=200 && my<=235){prev=game;game=3;}
          if(mx>=700 && mx<=900 && my>=150 && my<=180){game=7;}
           if(mx>=700 && mx<=900 && my>=100 && my<=130){game=6;}
            if(mx>=700 && mx<=900 && my>=50 && my<=85){exit(0);}

    }
    }
    if(game==1){
            if(resume==1)
            {
                if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx<=885 && mx>=855 && my<=790 && my>=760)
                {
                    resume=0;for(i=1;i<5;i++){iPauseTimer(i);}
                }
            }
           else if(resume==0)
            {
                if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx<=885 && mx>=855 && my<=790 && my>=760)
                {
                    resume=1;for(i=1;i<5;i++){iResumeTimer(i);}
                }
            }

    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{   //int d=0;
    if(game==5)
    {
        if(key=='\r')
        {
            if(len<19)
            {
                while(len<=19)
                {
                    str1[len]=' ';
                    if(len==19)
                    {
                        str1[len]='\0';
                        break;
                    }
                    len++;
                }
            }
            game=2;
            strcpy(str2,str1);
            printf("%d",strlen(str2));
            for(i=0;i<len;i++)
            {
                str1[i]=0;
            }
            len=0;
            if((fp3=fopen("names.txt","a"))==NULL){printf("error names");}
            fputs(str2,fp3);
            fclose(fp3);

        }
        else
        {
            str1[len]=key;
            len=len+1;
        }
    }
    if(key=='a' && game==1)
    {
        L=L+1;if(L>13){L=0;}if((L+2)%2==0){acidmode=1;}else{acidmode=0;}
        x=600;y=275;f1=f2=f3=f4=0;m1=m2=m3=m4=0;replicate=0;
        //ghost1ke box e pathai
        g1x=600;g1y=350;g1state=g2start=g2state=g3state=g3start=g4start=g4state=g1mode=0;
        g1sm1=g1sm2=g1sm3=g1sm4=g2sm1=g2sm2=g2sm3=g2sm4=1;
        g3sm1=g3sm2=g3sm3=g3sm4=g4sm1=g4sm2=g4sm3=g4sm4=1;
        g2x=650;g2y=350;
        g3x=550;g3y=350;
        g4x=500;
        g4y=350;fb=0;lives[3]=0;
        g1m1=1;g1m2=g1m3=g1m4=g2m1=g2m2=g2m3=g2m4=g3m1=g3m2=g3m3=g3m4=0;
        g4m1=g4m2=g4m3=g4m4=0;replicate=0;
        for(i=0;i<4;i++)eaten[i]=0;fmode=0;
        g5m1=0;g5m2=0;g5m3=0;g5m4=0;g5sm1=0;g5sm2=0;g5sm3=0;g5sm4=0;g5x=450;g5y=350;


for(i=0;i<1075;i++)
{
    foodstate[i]=1;
    if(foodx[i]<850 && foodx[i]>350 && foody[i]<500&&foody[i]>250)
        foodstate[i]=0;
            if(foodx[i]<250 && foodx[i]>50 && foody[i]<475&&foody[i]>375)
        foodstate[i]=0;
         if(foodx[i]<1150 && foodx[i]>975 && foody[i]<475&&foody[i]>375)
        foodstate[i]=0;
}
        fillfood();



    }

    //place your codes for other keys here
}
void fillfood(void)
{

    if(L>-1)
    {



    for(int j=0;j<1075;j++)
    {
        int ok=1;
        int r=foodx[j],s=foody[j];
      for(i=0;i<4;i++)
    {
        if( r<=(lx[L][i]+arm1[L][i]) && r>=(lx[L][i]-arm1[L][i])&& s<=(ly[L][i]+arm2[L][i])&& s>=(ly[L][i]-arm2[L][i]))
            ok=0;
    }
    for(i=4;i<21;i++)
    {
        if(r>=lx[L][i] && r<=(lx[L][i]+arm1[L][i])&& s>=ly[L][i] && s<=(ly[L][i]+arm2[L][i]))
            ok=0;
    }
    if(r>=1150 || r<=50 || s>=750 ||s<=100)ok=0;
    if(ok==0)
        foodstate[j]=0;

    }
    }



}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_RIGHT)
    {
       m1=1;
       m2=m3=m4=0;
       while(((int)y)%25!=0)
       y=y+1;

    }
    if(key == GLUT_KEY_LEFT)
    {
       m2=1;
       m1=m3=m4=0;
        while(((int)y)%25!=0)
       y=y+1;
    }
        if(key == GLUT_KEY_UP)
    {
       m3=1;
       m1=m2=m4=0;
        while(((int)x)%25!=0)
       x=x+1;
    }
        if(key == GLUT_KEY_DOWN)
    {
       m4=1;
       m1=m3=m2=0;
        while(((int)x)%25!=0)
       x=x+1;
    }

}
void change(void)
{   if(dragon==0){
    if(y==425 && ( x>=1150))x=75;

    if(acidmode==1)
    {

        if(y>600)
        {
            acidmode=0;
        }
        acid=acid+2;
       // if(acid>=y){acidmode=0;game=11;}
    }

     else if(acidmode==0){acid=acid-2;if(acid<0){acid=0;}}
       if(eaten[0]==1 || eaten[1]==1 || eaten[2]==1 || eaten[3]==1)
            {
                for(i=0;i<4;i++)
                {
                    if(eaten[i]==1)koytaeaten+=1;
                }
               if(koytaeaten==1){bonus=200;}
               if(koytaeaten==2){bonus=400;}
               if(koytaeaten==3){bonus=500;}
               if(koytaeaten==4){bonus=800;}
                printf("%d",koytaeaten);
                printeat=1;koytaeaten=0;
                //prevtm=tm;
            }

    if(m1==1)
    {
        //if(y==425 && (x<=1175 && x>=1000))x=60;
        x=x+dx;
        if(L==-1)
        validity=checking(x+5,y);
        else
            validity=cons(x,y);
        if(y==425 && (x<=1175 && x>=1000))validity=1;
        if(validity==0)
            x=x-dx;
        a[0]=x;b[0]=y;
        a[1]=x+rad;b[1]=y+rad;
        a[2]=x+rad;b[2]=y-rad;

    }
        if(m2==1)
    {
        //if(y==425 && ( x<50))x=1150;
        x=x-dx;
        if(y==425 && ( x<50))x=1100;
        if(L==-1)
        validity=checking(x-5,y);
        else
            validity=cons(x,y);
        if(y==425 && ((x<=200 && x>=25)||(x<=1100 && x>=1000)))validity=1;
        //if(y==425 ) validity=1;
        if(validity==0)
            x=x+dx;
        a[0]=x;b[0]=y;
        a[1]=x-rad;b[1]=y+rad;
        a[2]=x-rad;b[2]=y-rad;

    }
    if(m3==1)
    {
        y=y+dy;
        if(L==-1)
        validity=checking(x,y+5);
        else
            validity=cons(x,y);
        if(validity==0)
            y=y-dy;
        a[0]=x;b[0]=y;
        a[1]=x+rad;b[1]=y+rad;
        a[2]=x-rad;b[2]=y+rad;

    }
    if(m4==1)
    {
        y=y-dy;
        if(L==-1)
        validity=checking(x,y-5);
        else
            validity=cons(x,y);
        if(validity==0)
            y=y+dy;
        a[0]=x;b[0]=y;
        a[1]=x+rad;b[1]=y-rad;
        a[2]=x-rad;b[2]=y-rad;

    }

    int levelup=1;
    for(i=0;i<1075;i++)
    {
        if(foodstate[i]==1)levelup=0;
    }

    if(levelup==1)
    {
         L=L+1;/*if((L+2)%2==0){acidmode=1;}*/m1=m2=m3=m4=0;
         fp4=fopen("uptowhat.bin","rb");
         fread(&upto,sizeof(int),1,fp4);
         if(L>upto){upto=L;}
         fclose(fp4);
         fp4=fopen("uptowhat.bin","wb");
          fwrite(&upto,sizeof(int),1,fp4);fclose(fp4);

        x=600;y=275;f1=f2=f3=0;f1=f2=f3=f4=0;
        //ghost1ke box e pathai
        g1x=600;g1y=350;g1state=g2start=g2state=g3state=g3start=g4start=g4state=g1mode=0;
        g1sm1=g1sm2=g1sm3=g1sm4=g2sm1=g2sm2=g2sm3=g2sm4=1;
        g3sm1=g3sm2=g3sm3=g3sm4=g4sm1=g4sm2=g4sm3=g4sm4=1;
        g2x=650;g2y=350;
        g3x=550;g3y=350;
        g4x=500;
        g4y=350;fb=0;lives[3]=0;
        g1m1=1;g1m2=g1m3=g1m4=g2m1=g2m2=g2m3=g2m4=g3m1=g3m2=g3m3=g3m4=0;
        g4m1=g4m2=g4m3=g4m4=0;replicate=0;
        for(i=0;i<4;i++)eaten[i]=0;fmode=0;
        g5m1=0;g5m2=0;g5m3=0;g5m4=0;g5sm1=0;g5sm2=0;g5sm3=0;g5sm4=0;g5x=450;g5y=350;


            for(i=0;i<1075;i++)
            {
                foodstate[i]=1;
                if(foodx[i]<850 && foodx[i]>350 && foody[i]<500&&foody[i]>250)
                    foodstate[i]=0;
                        if(foodx[i]<250 && foodx[i]>50 && foody[i]<475&&foody[i]>375)
                    foodstate[i]=0;
                     if(foodx[i]<1150 && foodx[i]>975 && foody[i]<475&&foody[i]>375)
                    foodstate[i]=0;
            }
        fillfood();
    }
}
}


void changepacman(void)
{   if(dragon==1){
    if(y==425 && ( x>=1150))x=75;

    if(acidmode==1)
    {
        if(y>600)
        {
            acidmode=0;
        }
        acid=acid+2;
    }

     else if(acidmode==0){acid=acid-2;if(acid<0){acid=0;}}
       if(eaten[0]==1 || eaten[1]==1 || eaten[2]==1 || eaten[3]==1)
            {
                for(i=0;i<4;i++)
                {
                    if(eaten[i]==1)koytaeaten+=1;
                }
               if(koytaeaten==1){bonus=200;}
               if(koytaeaten==2){bonus=400;}
               if(koytaeaten==3){bonus=500;}
               if(koytaeaten==4){bonus=800;}
                printf("%d",koytaeaten);
                printeat=1;koytaeaten=0;
                //prevtm=tm;
            }

    if(m1==1)
    {
        //if(y==425 && (x<=1175 && x>=1000))x=60;
        x=x+dx;
        if(L==-1)
        validity=checking(x+5,y);
        else
            validity=cons(x,y);
        if(y==425 && (x<=1175 && x>=1000))validity=1;
        if(validity==0)
            x=x-dx;
        a[0]=x;b[0]=y;
        a[1]=x+rad;b[1]=y+rad;
        a[2]=x+rad;b[2]=y-rad;

    }
        if(m2==1)
    {
        //if(y==425 && ( x<50))x=1150;
        x=x-dx;
        if(y==425 && ( x<50))x=1100;
        if(L==-1)
        validity=checking(x-5,y);
        else
            validity=cons(x,y);
        if(y==425 && ((x<=200 && x>=25)||(x<=1100 && x>=1000)))validity=1;
        //if(y==425 ) validity=1;
        if(validity==0)
            x=x+dx;
        a[0]=x;b[0]=y;
        a[1]=x-rad;b[1]=y+rad;
        a[2]=x-rad;b[2]=y-rad;

    }
    if(m3==1)
    {
        y=y+dy;
        if(L==-1)
        validity=checking(x,y+5);
        else
            validity=cons(x,y);
        if(validity==0)
            y=y-dy;
        a[0]=x;b[0]=y;
        a[1]=x+rad;b[1]=y+rad;
        a[2]=x-rad;b[2]=y+rad;

    }
    if(m4==1)
    {
        y=y-dy;
        if(L==-1)
        validity=checking(x,y-5);
        else
            validity=cons(x,y);
        if(validity==0)
            y=y+dy;
        a[0]=x;b[0]=y;
        a[1]=x+rad;b[1]=y-rad;
        a[2]=x-rad;b[2]=y-rad;

    }

    int levelup=1;
    for(i=0;i<1075;i++)
    {
        if(foodstate[i]==1)levelup=0;
    }

    if(levelup==1)
    {
         L=L+1;/*if((L+2)%2==0){acidmode=1;}*/
         fp4=fopen("uptowhat.bin","rb");
         fread(&upto,sizeof(int),1,fp4);
         if(L>upto){upto=L;}
         fclose(fp4);
         fp4=fopen("uptowhat.bin","wb");
          fwrite(&upto,sizeof(int),1,fp4);fclose(fp4);

        x=600;y=275;f1=f2=f3=0;f1=f2=f3=f4=0;
        //ghost1ke box e pathai
        g1x=600;g1y=350;g1state=g2start=g2state=g3state=g3start=g4start=g4state=g1mode=0;
        g1sm1=g1sm2=g1sm3=g1sm4=g2sm1=g2sm2=g2sm3=g2sm4=1;
        g3sm1=g3sm2=g3sm3=g3sm4=g4sm1=g4sm2=g4sm3=g4sm4=1;
        g2x=650;g2y=350;
        g3x=550;g3y=350;
        g4x=500;
        g4y=350;fb=0;lives[3]=0;
        g1m1=1;g1m2=g1m3=g1m4=g2m1=g2m2=g2m3=g2m4=g3m1=g3m2=g3m3=g3m4=0;
        g4m1=g4m2=g4m3=g4m4=0;replicate=0;
        for(i=0;i<4;i++)eaten[i]=0;fmode=0;
        g5m1=0;g5m2=0;g5m3=0;g5m4=0;g5sm1=0;g5sm2=0;g5sm3=0;g5sm4=0;g5x=450;g5y=350;


            for(i=0;i<1075;i++)
            {
                foodstate[i]=1;
                if(foodx[i]<850 && foodx[i]>350 && foody[i]<500&&foody[i]>250)
                    foodstate[i]=0;
                        if(foodx[i]<250 && foodx[i]>50 && foody[i]<475&&foody[i]>375)
                    foodstate[i]=0;
                     if(foodx[i]<1150 && foodx[i]>975 && foody[i]<475&&foody[i]>375)
                    foodstate[i]=0;
            }
        fillfood();
    }
}
}

int main()
{
    for(i=0;i<4;i++)
    {
        lives[i]=1;eaten[i]=0;
        if(i==3)
        lives[i]=0;
    }
    a[0]=x;b[0]=y;
    a[1]=x+rad;b[1]=y+rad;
    a[2]=x+rad;b[2]=y-rad;
i=0;

for(ii=75;ii<1150;ii=ii+25)
{
    for(jj=125;jj<750;jj+=25)
    {
        foodx[i]=ii;
        foody[i]=jj;
        if(checking(foodx[i],foody[i])==1)
        foodstate[i]=1;
        else
            foodstate[i]=0;

        i++;
    }
}
if((fp1=fopen("scores.bin","rb"))==NULL){printf("cant open srry");}
while(!feof(fp1))
{
    fread(&t,sizeof(int),1,fp1);
    if(t>highscore)
        highscore=t;
}
fclose(fp1);
for(i=0;i<1075;i++)
{
    if(foodx[i]<850 && foodx[i]>350 && foody[i]<500&&foody[i]>250)
        foodstate[i]=0;
    if(foodx[i]<250 && foodx[i]>50 && foody[i]<475&&foody[i]>375)
        foodstate[i]=0;
         if(foodx[i]<1150 && foodx[i]>975 && foody[i]<475&&foody[i]>375)
        foodstate[i]=0;
}

//level initialize here
lx[0][0]=200; lx[0][1]=900; lx[0][2]=750; lx[0][3]=975; lx[0][4]=100; lx[0][5]=900; lx[0][6]=1000; lx[0][7]=550;
lx[0][8]=700; lx[0][9]=250; lx[0][10]=350; lx[0][11]=550; lx[0][12]=1050; lx[0][13]=50; lx[0][14]=450; lx[0][15]=500;
lx[0][16]=50;lx[0][17]=200;lx[0][18]=750;lx[0][19]=1000;lx[0][20]=800;
ly[0][0]=650;ly[0][1]=400;ly[0][2]=650;ly[0][3]=175;ly[0][4]=150;ly[0][5]=600;ly[0][6]=500;ly[0][7]=150;ly[0][8]=150;
ly[0][9]=300;ly[0][10]=600;ly[0][11]=650;ly[0][12]=150;ly[0][13]=250;ly[0][14]=300;ly[0][15]=500;
ly[0][16]=500;ly[0][17]=200;ly[0][18]=200;ly[0][19]=300;ly[0][20]=500;
arm1[0][0]=100; arm1[0][1]=50;arm1[0][2]=50;arm1[0][3]=25;arm1[0][4]=400;arm1[0][5]=200;arm1[0][6]=100;arm1[0][7]=100;
arm1[0][8]=200;arm1[0][9]=150;arm1[0][10]=100;arm1[0][11]=100;arm1[0][12]=50;arm1[0][13]=100;arm1[0][14]=300;arm1[0][15]=250;
arm1[0][16]=150;arm1[0][17]=150;arm1[0][18]=100;arm1[0][19]=50;arm1[0][20]=50;
arm2[0][0]=50;arm2[0][1]=100;arm2[0][2]=50;arm2[0][3]=25;arm2[0][4]=50;arm2[0][5]=100;arm2[0][6]=100;arm2[0][7]=100;
arm2[0][8]=50;arm2[0][9]=200;arm2[0][10]=100;arm2[0][11]=100;arm2[0][12]=150;arm2[0][13]=50;arm2[0][14]=100;arm2[0][15]=50;
arm2[0][16]=50;arm2[0][17]=50;arm2[0][18]=50;arm2[0][19]=50;arm2[0][20]=50;
//maze for level-1
lx[1][0]=200;lx[1][1]=1050;lx[1][2]=250;lx[1][3]=450;lx[1][4]=100;lx[1][5]=300;lx[1][6]=350;lx[1][7]=600;
lx[1][8]=500;lx[1][9]=350;lx[1][10]=750;lx[1][11]=850;lx[1][12]=1000;lx[1][13]=1000;lx[1][14]=700;lx[1][15]=450;
lx[1][16]=300;lx[1][17]=550;lx[1][18]=450;lx[1][19]=800;lx[1][20]=50;
ly[1][0]=600;ly[1][1]=225;ly[1][2]=300;ly[1][3]=500;ly[1][4]=150;ly[1][5]=350;ly[1][6]=600;ly[1][7]=450;
ly[1][8]=550;ly[1][9]=200;ly[1][10]=150;ly[1][11]=200;ly[1][12]=600;ly[1][13]=500;ly[1][14]=600;ly[1][15]=300;
ly[1][16]=100;ly[1][17]=100;ly[1][18]=700;ly[1][19]=700;ly[1][20]=300;
arm1[1][0]=50;arm1[1][1]=50;arm1[1][2]=50;arm1[1][3]=50;arm1[1][4]=100;arm1[1][5]=100;arm1[1][6]=50;arm1[1][7]=200;
arm1[1][8]=100;arm1[1][9]=350;arm1[1][10]=50;arm1[1][11]=100;arm1[1][12]=100;arm1[1][13]=100;arm1[1][14]=50;arm1[1][15]=300;
arm1[1][16]=150;arm1[1][17]=100;arm1[1][18]=150;arm1[1][19]=150;arm1[1][20]=100;
arm2[1][0]=100;arm2[1][1]=75;arm2[1][2]=50;arm2[1][3]=50;arm2[1][4]=100;arm2[1][5]=100;arm2[1][6]=150;arm2[1][7]=50;
arm2[1][8]=100;arm2[1][9]=50;arm2[1][10]=50;arm2[1][11]=450;arm2[1][12]=100;arm2[1][13]=50;arm2[1][14]=150;arm2[1][15]=100;
arm2[1][16]=50;arm2[1][17]=50;arm2[1][18]=50;arm2[1][19]=50;arm2[1][20]=50;
lx[2][0]=150;lx[2][1]=1050;lx[2][2]=600;lx[2][3]=1050;lx[2][4]=100;lx[2][5]=200;lx[2][6]=350;lx[2][7]=800;lx[2][8]=300;
lx[2][9]=300;lx[2][10]=350;lx[2][11]=400;lx[2][12]=550;lx[2][13]=750;lx[2][14]=850;lx[2][15]=250;lx[2][16]=250;lx[2][17]=600;
lx[2][18]=700;lx[2][19]=450;lx[2][20]=450;
ly[2][0]=250;ly[2][1]=600;ly[2][2]=550;ly[2][3]=200;ly[2][4]=600;ly[2][5]=500;ly[2][6]=150;ly[2][7]=200;ly[2][8]=400;
ly[2][9]=700;ly[2][10]=650;ly[2][11]=600;ly[2][12]=700;ly[2][13]=500;ly[2][14]=600;ly[2][15]=250;ly[2][16]=100;ly[2][17]=150;
ly[2][18]=100;ly[2][19]=200;ly[2][20]=300;
arm1[2][0]=50;arm1[2][1]=50;arm1[2][2]=100;arm1[2][3]=50;arm1[2][4]=100;arm1[2][5]=100;arm1[2][6]=100;arm1[2][7]=150;
arm1[2][8]=100;arm1[2][9]=50;arm1[2][10]=50;arm1[2][11]=50;arm1[2][12]=200;arm1[2][13]=100;arm1[2][14]=100;arm1[2][15]=150;
arm1[2][16]=100;arm1[2][17]=100;arm1[2][18]=100;arm1[2][19]=100;arm1[2][20]=300;
arm2[2][0]=100;arm2[2][1]=100;arm2[2][2]=100;arm2[2][3]=50;arm2[2][4]=100;arm2[2][5]=100;arm2[2][6]=50;arm2[2][7]=200;
arm2[2][8]=100;arm2[2][9]=50;arm2[2][10]=50;arm2[2][11]=50;arm2[2][12]=50;arm2[2][13]=100;arm2[2][14]=100;arm2[2][15]=100;
arm2[2][16]=50;arm2[2][17]=50;arm2[2][18]=50;arm2[2][19]=50;arm2[2][20]=100;
lx[3][0]=150;lx[3][1]=950;lx[3][2]=950;lx[3][3]=600;lx[3][4]=450;lx[3][5]=250;lx[3][6]=100;lx[3][7]=750;lx[3][8]=450;lx[3][9]=550;
lx[3][10]=650;lx[3][11]=250;lx[3][12]=350;lx[3][13]=700;lx[3][14]=800;lx[3][15]=1050;lx[3][16]=1100;lx[3][17]=800;lx[3][18]=550;
lx[3][19]=550;lx[3][20]=150;
ly[3][0]=225;ly[3][1]=625;ly[3][2]=250;ly[3][3]=600;ly[3][4]=300;ly[3][5]=100;ly[3][6]=600;ly[3][7]=100;ly[3][8]=100;ly[3][9]=100;
ly[3][10]=100;ly[3][11]=200;ly[3][12]=200;ly[3][13]=450;ly[3][14]=350;ly[3][15]=500;ly[3][16]=150;ly[3][17]=450;ly[3][18]=200;
ly[3][19]=450;ly[3][20]=500;
arm1[3][0]=50;arm1[3][1]=50;arm1[3][2]=100;arm1[3][3]=75;arm1[3][4]=300;arm1[3][5]=100;arm1[3][6]=300;arm1[3][7]=100;
arm1[3][8]=50;arm1[3][9]=50;arm1[3][10]=50;arm1[3][11]=50;arm1[3][12]=50;arm1[3][13]=50;arm1[3][14]=50;arm1[3][15]=50;arm1[3][16]=50;
arm1[3][17]=50;arm1[3][18]=250;arm1[3][19]=100;arm1[3][20]=200;
arm2[3][0]=75;arm2[3][1]=75;arm2[3][2]=100;arm2[3][3]=75;arm2[3][4]=100;arm2[3][5]=50;arm2[3][6]=100;arm2[3][7]=50;
arm2[3][8]=150;arm2[3][9]=50;arm2[3][10]=100;arm2[3][11]=250;arm2[3][12]=200;arm2[3][13]=100;arm2[3][14]=50;arm2[3][15]=200;
arm2[3][16]=200;arm2[3][17]=200;arm2[3][18]=50;arm2[3][19]=50;arm2[3][20]=50;
lx[4][0]=600;lx[4][1]=1050;lx[4][2]=225;lx[4][3]=1000;lx[4][4]=450;lx[4][5]=100;lx[4][6]=350;lx[4][7]=450;lx[4][8]=250;
lx[4][9]=550;lx[4][10]=50;lx[4][11]=100;lx[4][12]=300;lx[4][13]=100;lx[4][14]=400;lx[4][15]=750;lx[4][16]=1100;lx[4][17]=850;
lx[4][18]=900;lx[4][19]=850;lx[4][20]=900;
ly[4][0]=600;ly[4][1]=225;ly[4][2]=225;ly[4][3]=600;ly[4][4]=300;ly[4][5]=150;ly[4][6]=150;ly[4][7]=450;ly[4][8]=100;
ly[4][9]=150;ly[4][10]=300;ly[4][11]=500;ly[4][12]=400;ly[4][13]=600;ly[4][14]=700;ly[4][15]=450;ly[4][16]=300;ly[4][17]=450;
ly[4][18]=450;ly[4][19]=300;ly[4][20]=300;
arm1[4][0]=200;arm1[4][1]=50;arm1[4][2]=25;arm1[4][3]=50;arm1[4][4]=300;arm1[4][5]=100;arm1[4][6]=150;arm1[4][7]=50;
arm1[4][8]=50;arm1[4][9]=400;arm1[4][10]=300;arm1[4][11]=200;arm1[4][12]=50;arm1[4][13]=150;arm1[4][14]=100;arm1[4][15]=50;
arm1[4][16]=50;arm1[4][17]=50;arm1[4][18]=50;arm1[4][19]=50;arm1[4][20]=100;
arm2[4][0]=100;arm2[4][1]=75;arm2[4][2]=25;arm2[4][3]=50;arm2[4][4]=100;arm2[4][5]=50;arm2[4][6]=100;arm2[4][7]=50;
arm2[4][8]=150;arm2[4][9]=100;arm2[4][10]=50;arm2[4][11]=50;arm2[4][12]=300;arm2[4][13]=150;arm2[4][14]=50;arm2[4][15]=50;
arm2[4][16]=50;arm2[4][17]=250;arm2[4][18]=50;arm2[4][19]=100;arm2[4][20]=50;
lx[5][0]=500;lx[5][1]=750;lx[5][2]=150;lx[5][3]=200;lx[5][4]=450;lx[5][5]=650;lx[5][6]=900;lx[5][7]=1000;lx[5][8]=300;
lx[5][9]=250;lx[5][10]=350;lx[5][11]=350;lx[5][12]=650;lx[5][13]=800;lx[5][14]=900;lx[5][15]=1000;lx[5][16]=1100;lx[5][17]=450;
lx[5][18]=400;lx[5][19]=350;lx[5][20]=100;
ly[5][0]=700;ly[5][1]=200;ly[5][2]=600;ly[5][3]=250;ly[5][4]=300;ly[5][5]=650;ly[5][6]=150;ly[5][7]=500;ly[5][8]=550;
ly[5][9]=450;ly[5][10]=450;ly[5][11]=350;ly[5][12]=450;ly[5][13]=800;ly[5][14]=900;ly[5][15]=300;ly[5][16]=150;ly[5][17]=100;
ly[5][18]=200;ly[5][19]=150;ly[5][20]=700;
arm1[5][0]=100;arm1[5][1]=100;arm1[5][2]=50;arm1[5][3]=100;arm1[5][4]=300;arm1[5][5]=150;arm1[5][6]=150;arm1[5][7]=150;
arm1[5][8]=650;arm1[5][9]=50;arm1[5][10]=200;arm1[5][11]=50;arm1[5][12]=200;arm1[5][13]=50;arm1[5][14]=50;arm1[5][15]=100;
arm1[5][16]=50;arm1[5][17]=200;arm1[5][18]=200;arm1[5][19]=50;arm1[5][20]=100;
arm2[5][0]=50;arm2[5][1]=50;arm2[5][2]=50;arm2[5][3]=100;arm2[5][4]=100;arm2[5][5]=100;arm2[5][6]=100;arm2[5][7]=250;
arm2[5][8]=50;arm2[5][9]=250;arm2[5][10]=50;arm2[5][11]=100;arm2[5][12]=50;arm2[5][13]=100;arm2[5][14]=200;arm2[5][15]=50;
arm2[5][16]=150;arm2[5][17]=50;arm2[5][18]=50;arm2[5][19]=150;arm2[5][20]=50;
lx[6][0]=550;lx[6][1]=1025;lx[6][2]=300;lx[6][3]=900;lx[6][4]=450;lx[6][5]=100;lx[6][6]=350;lx[6][7]=750;lx[6][8]=50;
lx[6][9]=150;lx[6][10]=250;lx[6][11]=100;lx[6][12]=200;lx[6][13]=450;lx[6][14]=650;lx[6][15]=950;lx[6][16]=1100;lx[6][17]=1000;
lx[6][18]=800;lx[6][19]=850;lx[6][20]=700;
ly[6][0]=125;ly[6][1]=300;ly[6][2]=400;ly[6][3]=400;ly[6][4]=300;ly[6][5]=500;ly[6][6]=500;ly[6][7]=500;ly[6][8]=250;
ly[6][9]=200;ly[6][10]=250;ly[6][11]=150;ly[6][12]=150;ly[6][13]=200;ly[6][14]=100;ly[6][15]=150;ly[6][16]=150;ly[6][17]=400;
ly[6][18]=250;ly[6][19]=150;ly[6][20]=200;
arm1[6][0]=50;arm1[6][1]=75;arm1[6][2]=50;arm1[6][3]=50;arm1[6][4]=300;arm1[6][5]=150;arm1[6][6]=350;arm1[6][7]=350;
arm1[6][8]=50;arm1[6][9]=50;arm1[6][10]=150;arm1[6][11]=50;arm1[6][12]=250;arm1[6][13]=150;arm1[6][14]=150;arm1[6][15]=100;
arm1[6][16]=50;arm1[6][17]=150;arm1[6][18]=100;arm1[6][19]=50;arm1[6][20]=50;
arm2[6][0]=25;arm2[6][1]=50;arm2[6][2]=50;arm2[6][3]=50;arm2[6][4]=100;arm2[6][5]=200;arm2[6][6]=200;arm2[6][7]=200;
arm2[6][8]=100;arm2[6][9]=150;arm2[6][10]=50;arm2[6][11]=50;arm2[6][12]=50;arm2[6][13]=50;arm2[6][14]=100;arm2[6][15]=50;
arm2[6][16]=100;arm2[6][17]=50;arm2[6][18]=50;arm2[6][19]=50;arm2[6][20]=50;
lx[7][0]=350;lx[7][1]=850;lx[7][2]=150;lx[7][3]=1000;lx[7][4]=450;lx[7][5]=100;lx[7][6]=200;lx[7][7]=500;lx[7][8]=250;
lx[7][9]=400;lx[7][10]=450;lx[7][11]=500;lx[7][12]=1000;lx[7][13]=800;lx[7][14]=650;lx[7][15]=1000;lx[7][16]=850;lx[7][17]=250;
lx[7][18]=500;lx[7][19]=1100;lx[7][20]=300;
ly[7][0]=500;ly[7][1]=200;ly[7][2]=650;ly[7][3]=650;ly[7][4]=300;ly[7][5]=100;ly[7][6]=100;ly[7][7]=600;ly[7][8]=300;
ly[7][9]=200;ly[7][10]=100;ly[7][11]=200;ly[7][12]=150;ly[7][13]=300;ly[7][14]=450;ly[7][15]=500;ly[7][16]=600;ly[7][17]=600;
ly[7][18]=450;ly[7][19]=250;ly[7][20]=100;
arm1[7][0]=100;arm1[7][1]=100;arm1[7][2]=50;arm1[7][3]=50;arm1[7][4]=300;arm1[7][5]=50;arm1[7][6]=50;arm1[7][7]=300;
arm1[7][8]=100;arm1[7][9]=50;arm1[7][10]=250;arm1[7][11]=150;arm1[7][12]=150;arm1[7][13]=250;arm1[7][14]=300;arm1[7][15]=100;
arm1[7][16]=50;arm1[7][17]=150;arm1[7][18]=100;arm1[7][19]=50;arm1[7][20]=50;
arm2[7][0]=50;arm2[7][1]=50;arm2[7][2]=50;arm2[7][3]=50;arm2[7][4]=100;arm2[7][5]=250;arm2[7][6]=150;arm2[7][7]=100;
arm2[7][8]=100;arm2[7][9]=50;arm2[7][10]=50;arm2[7][11]=50;arm2[7][12]=50;arm2[7][13]=50;arm2[7][14]=100;arm2[7][15]=100;
arm2[7][16]=150;arm2[7][17]=150;arm2[7][18]=100;arm2[7][19]=50;arm2[7][20]=100;
lx[8][0]=250;lx[8][1]=950;lx[8][2]=500;lx[8][3]=900;lx[8][4]=450;lx[8][5]=1050;lx[8][6]=1050;lx[8][7]=300;
lx[8][8]=100;lx[8][9]=100;lx[8][10]=250;lx[8][11]=250;lx[8][12]=600;lx[8][13]=500;lx[8][14]=400;lx[8][15]=600;
lx[8][16]=800;lx[8][17]=650;lx[8][18]=700;lx[8][19]=800;lx[8][20]=350;
ly[8][0]=250;ly[8][1]=250;ly[8][2]=200;ly[8][3]=600;ly[8][4]=300;ly[8][5]=500;ly[8][6]=150;ly[8][7]=400;
ly[8][8]=500;ly[8][9]=150;ly[8][10]=650;ly[8][11]=550;ly[8][12]=650;ly[8][13]=550;ly[8][14]=500;ly[8][15]=450;
ly[8][16]=200;ly[8][17]=150;ly[8][18]=550;ly[8][19]=100;ly[8][20]=150;
arm1[8][0]=50;arm1[8][1]=50;arm1[8][2]=50;arm1[8][3]=100;arm1[8][4]=300;arm1[8][5]=100;arm1[8][6]=100;arm1[8][7]=50;
arm1[8][8]=100;arm1[8][9]=50;arm1[8][10]=300;arm1[8][11]=100;arm1[8][12]=50;arm1[8][13]=150;arm1[8][14]=50;arm1[8][15]=200;
arm1[8][16]=50;arm1[8][17]=100;arm1[8][18]=50;arm1[8][19]=100;arm1[8][20]=50;
arm2[8][0]=100;arm2[8][1]=100;arm2[8][2]=50;arm2[8][3]=100;arm2[8][4]=100;arm2[8][5]=150;arm2[8][6]=200;arm2[8][7]=100;
arm2[8][8]=200;arm2[8][9]=200;arm2[8][10]=50;arm2[8][11]=50;arm2[8][12]=50;arm2[8][13]=50;arm2[8][14]=50;arm2[8][15]=50;
arm2[8][16]=200;arm2[8][17]=100;arm2[8][18]=200;arm2[8][19]=50;arm2[8][20]=200;
lx[9][0]=300;lx[9][1]=900;lx[9][2]=650;lx[9][3]=1050;lx[9][4]=450;lx[9][5]=900;lx[9][6]=750;lx[9][7]=300;
lx[9][8]=450;lx[9][9]=1050;lx[9][10]=800;lx[9][11]=900;lx[9][12]=750;lx[9][13]=600;lx[9][14]=450;lx[9][15]=300;
lx[9][16]=150;lx[9][17]=150;lx[9][18]=100;lx[9][19]=550;lx[9][20]=50;
ly[9][0]=600;ly[9][1]=200;ly[9][2]=200;ly[9][3]=300;ly[9][4]=300;ly[9][5]=650;ly[9][6]=550;ly[9][7]=200;
ly[9][8]=100;ly[9][9]=100;ly[9][10]=350;ly[9][11]=500;ly[9][12]=700;ly[9][13]=600;ly[9][14]=450;ly[9][15]=350;
ly[9][16]=250;ly[9][17]=100;ly[9][18]=700;ly[9][19]=450;ly[9][20]=200;
arm1[9][0]=200;arm1[9][1]=150;arm1[9][2]=50;arm1[9][3]=50;arm1[9][4]=300;arm1[9][5]=150;arm1[9][6]=100;arm1[9][7]=100;
arm1[9][8]=100;arm1[9][9]=50;arm1[9][10]=100;arm1[9][11]=200;arm1[9][12]=100;arm1[9][13]=100;arm1[9][14]=50;arm1[9][15]=100;
arm1[9][16]=100;arm1[9][17]=100;arm1[9][18]=50;arm1[9][19]=150;arm1[9][20]=50;
arm2[9][0]=100;arm2[9][1]=50;arm2[9][2]=50;arm2[9][3]=50;arm2[9][4]=100;arm2[9][5]=100;arm2[9][6]=100;arm2[9][7]=100;
arm2[9][8]=100;arm2[9][9]=50;arm2[9][10]=100;arm2[9][11]=100;arm2[9][12]=50;arm2[9][13]=100;arm2[9][14]=50;arm2[9][15]=50;
arm2[9][16]=100;arm2[9][17]=100;arm2[9][18]=50;arm2[9][19]=100;arm2[9][20]=150;
lx[10][0]=250;lx[10][1]=1050;lx[10][2]=350;lx[10][3]=850;lx[10][4]=450;lx[10][5]=150;lx[10][6]=800;lx[10][7]=750;
lx[10][8]=650;lx[10][9]=550;lx[10][10]=450;lx[10][11]=500;lx[10][12]=600;lx[10][13]=650;lx[10][14]=550;lx[10][15]=700;
lx[10][16]=800;lx[10][17]=650;lx[10][18]=500;lx[10][19]=450;lx[10][20]=450;
ly[10][0]=600;ly[10][1]=250;ly[10][2]=400;ly[10][3]=400;ly[10][4]=300;ly[10][5]=150;ly[10][6]=550;ly[10][7]=700;
ly[10][8]=650;ly[10][9]=650;ly[10][10]=650;ly[10][11]=550;ly[10][12]=600;ly[10][13]=550;ly[10][14]=450;ly[10][15]=450;
ly[10][16]=250;ly[10][17]=200;ly[10][18]=150;ly[10][19]=100;ly[10][20]=450;
arm1[10][0]=150;arm1[10][1]=50;arm1[10][2]=50;arm1[10][3]=50;arm1[10][4]=300;arm1[10][5]=250;arm1[10][6]=300;arm1[10][7]=50;
arm1[10][8]=50;arm1[10][9]=50;arm1[10][10]=50;arm1[10][11]=50;arm1[10][12]=50;arm1[10][13]=100;arm1[10][14]=100;arm1[10][15]=100;
arm1[10][16]=150;arm1[10][17]=250;arm1[10][18]=350;arm1[10][19]=350;arm1[10][20]=50;
arm2[10][0]=100;arm2[10][1]=100;arm2[10][2]=50;arm2[10][3]=50;arm2[10][4]=100;arm2[10][5]=150;arm2[10][6]=150;arm2[10][7]=50;
arm2[10][8]=50;arm2[10][9]=50;arm2[10][10]=50;arm2[10][11]=50;arm2[10][12]=50;arm2[10][13]=50;arm2[10][14]=100;arm2[10][15]=50;
arm2[10][16]=50;arm2[10][17]=50;arm2[10][18]=50;arm2[10][19]=50;arm2[10][20]=50;

lx[11][0]=300;lx[11][1]=900;lx[11][2]=650;lx[11][3]=1050;lx[11][4]=450;lx[11][5]=900;lx[11][6]=750;lx[11][7]=300;
lx[11][8]=450;lx[11][9]=1050;lx[11][10]=800;lx[11][11]=900;lx[11][12]=750;lx[11][13]=600;lx[11][14]=450;lx[11][15]=300;
lx[11][16]=150;lx[11][17]=150;lx[11][18]=100;lx[11][19]=550;lx[11][20]=50;
ly[11][0]=600;ly[11][1]=200;ly[11][2]=200;ly[11][3]=300;ly[11][4]=300;ly[11][5]=650;ly[11][6]=550;ly[11][7]=200;
ly[11][8]=100;ly[11][9]=100;ly[11][10]=350;ly[11][11]=500;ly[11][12]=700;ly[11][13]=600;ly[11][14]=450;ly[11][15]=350;
ly[11][16]=250;ly[11][17]=100;ly[11][18]=700;ly[11][19]=450;ly[11][20]=200;
arm1[11][0]=200;arm1[11][1]=150;arm1[11][2]=50;arm1[11][3]=50;arm1[11][4]=300;arm1[11][5]=150;arm1[11][6]=100;arm1[11][7]=100;
arm1[11][8]=100;arm1[11][9]=50;arm1[11][10]=100;arm1[11][11]=200;arm1[11][12]=100;arm1[11][13]=100;arm1[11][14]=50;arm1[11][15]=100;
arm1[11][16]=100;arm1[11][17]=100;arm1[11][18]=50;arm1[11][19]=150;arm1[11][20]=50;
arm2[11][0]=100;arm2[11][1]=50;arm2[11][2]=50;arm2[11][3]=50;arm2[11][4]=100;arm2[11][5]=100;arm2[11][6]=100;arm2[11][7]=100;
arm2[11][8]=100;arm2[11][9]=50;arm2[11][10]=100;arm2[11][11]=100;arm2[11][12]=50;arm2[11][13]=100;arm2[11][14]=50;arm2[11][15]=50;
arm2[11][16]=100;arm2[11][17]=100;arm2[11][18]=50;arm2[11][19]=100;arm2[11][20]=150;


lx[12][0]=350;lx[12][1]=850;lx[12][2]=150;lx[12][3]=1000;lx[12][4]=450;lx[12][5]=100;lx[12][6]=200;lx[12][7]=500;lx[12][8]=250;
lx[12][9]=400;lx[12][10]=450;lx[12][11]=500;lx[12][12]=1000;lx[12][13]=800;lx[12][14]=650;lx[12][15]=1000;lx[12][16]=850;lx[12][17]=250;
lx[12][18]=500;lx[12][19]=1100;lx[12][20]=300;
ly[12][0]=500;ly[12][1]=200;ly[12][2]=650;ly[12][3]=650;ly[12][4]=300;ly[12][5]=100;ly[12][6]=100;ly[12][7]=600;ly[12][8]=300;
ly[12][9]=200;ly[12][10]=100;ly[12][11]=200;ly[12][12]=150;ly[12][13]=300;ly[12][14]=450;ly[12][15]=500;ly[12][16]=600;ly[12][17]=600;
ly[12][18]=450;ly[12][19]=250;ly[12][20]=100;
arm1[12][0]=100;arm1[12][1]=100;arm1[12][2]=50;arm1[12][3]=50;arm1[12][4]=300;arm1[12][5]=50;arm1[12][6]=50;arm1[12][7]=300;
arm1[12][8]=100;arm1[12][9]=50;arm1[12][10]=250;arm1[12][11]=150;arm1[12][12]=150;arm1[12][13]=250;arm1[12][14]=300;arm1[12][15]=100;
arm1[12][16]=50;arm1[12][17]=150;arm1[12][18]=100;arm1[12][19]=50;arm1[12][20]=50;
arm2[12][0]=50;arm2[12][1]=50;arm2[12][2]=50;arm2[12][3]=50;arm2[12][4]=100;arm2[12][5]=250;arm2[12][6]=150;arm2[12][7]=100;
arm2[12][8]=100;arm2[12][9]=50;arm2[12][10]=50;arm2[12][11]=50;arm2[12][12]=50;arm2[12][13]=50;arm2[12][14]=100;arm2[12][15]=100;
arm2[12][16]=150;arm2[12][17]=150;arm2[12][18]=100;arm2[12][19]=50;arm2[12][20]=100;



iSetTimer(150,changemukh);

    iSetTimer(150,change);
     iSetTimer(200,changeghosts);

iSetTimer(2000,randomize);
iSetTimer(15000,f);
iSetTimer(120,changepacman);
iSetTimer(3000,diefunc);

PlaySound("project.wav",NULL,SND_ASYNC|SND_LOOP);

iInitialize(1200, 800, "Demo!");
    return 0;
}

