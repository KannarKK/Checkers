/*
		 ***  *  *   ***    ***  *  *   ***   ***    ****
		|     |__|  |__    |     |_/   |__    |_|    |__
		|     |  |  |      |     | \   |      | \       |
		 ***  *  *   ***    ***  *  *   ***   *  *   ****

		   - THE  LITTLE ROCKERS' PROUD CREATION  -

     Role of Lris:
     Game Contract to       :  KP productions
     Game creators          :  Kiran K & Prathik M G
     Class                  :  12

			 /^^^\
			| @ @ |
		      --|  O  |--
			|  =  |
			 \___/

*/

#include<fstream>
#include<graphics>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>



enum COIN { Empty, Green, Red, KGreen, KRed, Comp } ;
int Pick ,turn,Rcount=12,Gcount=12;
char Name1[30]="Player 1",Name2[30]="Player 2";

int BoardMemory[8][8];

#include"E:\USB folders\12B projects\kk12\MOUSES.H"
#include"E:\USB folders\12B projects\kk12\PAGE1.H"
#include"E:\USB folders\12B projects\kk12\FLOODFIL.H"
#include"E:\USB folders\12B projects\kk12\COMP.H"
#include"E:\USB folders\12B projects\kk12\PLAY.H"
#include"E:\USB folders\12B projects\kk12\PLAY2.H"
#include"E:\USB folders\12B projects\kk12\BOARD.H"
#include"E:\USB folders\12B projects\kk12\TOSS.H"
#include"E:\USB folders\12B projects\kk12\PAGE2.H"
#include"E:\USB folders\12B projects\kk12\HELPCODE.H"
#include"E:\USB folders\12B projects\kk12\PAGE3.H"
#include"E:\USB folders\12B projects\kk12\INTRO.H"



 void main()
{
//Initialising the graphics

int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\TC\\BGI ");


Page1();
Page2();
Page3();

closegraph();


}

