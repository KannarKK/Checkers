/*This program part contains the following functions
   Playby(). win(), play2(), play1() */
void Page3();
void Page2();
///void PlayLogic(int ,int,int);
//void Exit();
void Board(int);
void Play1(int);
void Tossresult(int);


//-----------------------------------------------------


void Playby()
  {
    int y=0;
    setcolor(BLACK);
    while(y<600)
       {
	setcolor(RED);
	line(0,y,y,0);
	line(0,y+1,y+1,0);
	line(0,y-1,y-1,0);
	setcolor(BLACK);
	line(0,y-2,y-2,0);
	setcolor(RED);
	line(650,550-y,650-y,550);
	line(650,550-y+1,650-y+1,550);
	line(650,550-y+1,650-y-1,550);
	setcolor(BLACK);
	line(650,550-y+2,650-y+2,550);

	y++;
       }
    cleardevice();
    settextstyle(2,0,5);
    setfillstyle(SOLID_FILL,BLUE);
    int r=0;
    while(r<150)
    {
    fillellipse(0,0,r,r);
    fillellipse(0,getmaxy(),r,r);
    fillellipse(getmaxx(),getmaxy(),r,r);
    fillellipse(getmaxx(),0,r,r);
    r++;
    }

    setcolor(YELLOW);
    outtextxy(240,70,"WELCOME TO CHECKERS");

    outtextxy(130,180,"CHOOSE THE TYPE OF GAME YOU WOULD LIKE TO PLAY");
    setcolor(GREEN);
    outtextxy(250,215,"COMPUTER Vs HUMAN");
    outtextxy(250,245," HUMAN  Vs HUMAN");
    circle(230,223,8);
    circle(230,253,8);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(230,253,5,5);
    setfillstyle(SOLID_FILL, RED);
    setcolor(RED);
    fillellipse(230,223,5,5);
    bar(270,350,350,400);
    setcolor(GREEN);
    outtextxy(280,360,"CONTINUE");

   mouse.initmouse();
   int button,lx,ly,flag=1;


   while(1)
   {  mouse.getmousepos(&button,&lx, &ly );
      mouse.showmouseptr();
      if(button &1 == 1)
       {
	if(lx>225 && lx<380 && ly>218 && ly<228 )
	    {
		flag=1;
		mouse.hidemouseptr();
		setcolor(RED);
		setfillstyle(SOLID_FILL, RED);
		fillellipse(230,223,5,5);
		setfillstyle(SOLID_FILL, WHITE);
		setcolor(WHITE);
		fillellipse(230,253,5,5);
	    }
	if(lx>225 && lx<380 && ly>248 && ly<258 )
	    {   mouse.hidemouseptr();
		flag=2;
		setfillstyle(SOLID_FILL, RED);
		setcolor(RED);
		fillellipse(230,253,5,5);
		setfillstyle(SOLID_FILL, WHITE);
		setcolor(WHITE);
		fillellipse(230,223,5,5);
	    }
	if(lx>270 && lx<350 && ly>350 && ly<400 )
	   {
	    mouse.hidemouseptr();
	    Play1(flag);
	   }
	}  //end of if(..)
      }    //end of while(..)
   }      //end of Playby(...)

//----------------------------------------------------------------

/* This function is for the tossing of coin and selecting who
   plays first. */


void Play1(int flag)
{


   cleardevice();
   setfillstyle(SOLID_FILL,BLUE);
   int r=0;
   while(r<150)
   {
   fillellipse(0,0,r,r);
   fillellipse(0,getmaxy(),r,r);
   fillellipse(getmaxx(),getmaxy(),r,r);
   fillellipse(getmaxx(),0,r,r);
   r++;
   delay(1);
   }

   settextstyle(7,0,4);
   setcolor(YELLOW);
   outtextxy(120,100,"WELCOME TO CHECKERS");
   settextstyle(3,0,2);

   setcolor(RED);
   outtextxy(220,200,"PLAYER 1 : ");
   rectangle(353,205,503,225);

   setcolor(GREEN);
   if(flag==1)
     {   outtextxy(220,250,"PLAYER 2 : Computer");
	 strcpy(Name2,"Computer");
     }
   if(flag==2)
      {   outtextxy(220,250,"PLAYER 2 : ");
	  rectangle(350,253,503,273);

      }
   setcolor(YELLOW);
   rectangle(190,330,430,420);
   settextstyle(3,0,2);
   outtextxy(220,340,"PLAYER 1 CHOOSE");

   setfillstyle(1,WHITE);
   bar(220,380,290,410);
   bar(330,380,400,410);
   setcolor(RED);

   rectangle(221,381,289,409);
   rectangle(331,381,399,409);
   rectangle(218,378,292,412);
   rectangle(328,378,402,412);


   setcolor(BLACK);
   outtextxy(225,380,"HEADS     TAILS");

   mouse.initmouse();
   int button,lx,ly,rand;
   randomize();          //to get either head or tails
   mouse.showmouseptr();
   while(1)
   {  mouse.getmousepos(&button,&lx, &ly );
      mouse.showmouseptr();
      if( button & 1  == 1)
       {

	if(((lx >=220 && lx<=290)||(lx >=330 && lx<=400))
	   && ly >=380 && ly <=410 )
	    {
		rand=random(10);
		setcolor(WHITE);
		if(rand%2==0)
		   {
		   mouse. hidemouseptr();

		    if(flag==1)
		      turn=Comp;
		    if(flag==2)
		      turn=Green;
		    }

		if(rand%2==1)
		    {
		     mouse. hidemouseptr();
		      turn=Red;
		    }

		Tossresult(flag);
	    }
	  if(lx>353 && lx<503 && ly>205 && ly<223)
	    {
	     mouse.hidemouseptr();
	     gotoxy(48,14);
	     cin>>Name1;
	     Name1[0]=toupper(Name1[0]);
	     for(int i=1;Name1[i]!='\0';i++)
		Name1[i]=tolower(Name1[i]);
	    }
	  if(lx>353 && lx<503 && ly>253 && ly<273 && flag==2)
	    {
	     mouse.hidemouseptr();
	     gotoxy(48,17);
	     cin>>Name2;
	     Name2[0]=toupper(Name2[0]);
	      for(int i=1;Name2[i]!='\0';i++)
		 Name2[i]=tolower(Name2[i]);
	    }





	}//end of button

     }//end of while

}//end of Play1
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

void win(int winner)           //GAME OVER
  {
     cleardevice();

     int button, mx, my  ;
     int r;
randomize();
setcolor(RED);
for(int i=0;i<370;i++)
{ delay(10);

   r=random(16);
  setcolor(r);
  cleardevice();
  line(i/2-5,500-i,i/2+25,480-i);          //w
  line(i/2+35,500-i,i/2+65,480-i);
  line(415-i/2,500-i,385-i/2,480-i);
  line(380-i/2,500-i,345-i/2,480-i);

  line(320,i-260,320,i-235);               //i

   line(i/2+200,500-i,i/2+230,480-i);
   line(i/2+240,500-i,i/2+270,480-i);

   line(620-i/2,500-i,590-i/2,480-i);


}

    setfillstyle(1,WHITE);

    bar(210,150,420,350);


    setfillstyle(1,BLACK);
    bar(230,250,400,280);
    bar(230,300,400,330);

    setcolor(RED);
    rectangle(211,151,419,349);
    rectangle(228,248,402,282);
    rectangle(228,298,402,332);

    rectangle(226,246,404,284);
    rectangle(226,296,404,334);



    //setcolor(3);
    settextstyle( 4, 0, 3 );
    if(winner==1)
    outtextxy(257,173,Name2);
    if(winner==2)
    outtextxy(257,173,Name1);
    outtextxy(230,175,"!!            !!");
     settextstyle( 2, 0, 5 );
    outtextxy(250,255,"BACK TO MAIN MENU");
    outtextxy(300,305,"EXIT");



 while( 1 )
  {
    mouse.showmouseptr();
    mouse.getmousepos(&button,&mx, &my );
    setcolor(14);
    settextstyle( 2, 0, 5 );
     if( mx> 230 && mx< 400 && my>250 && my<280 )
       outtextxy(250,255,"BACK TO MAIN MENU");
     else
       {setcolor(RED);
	outtextxy(250,255,"BACK TO MAIN MENU");
       }
     setcolor(14);
     if( mx> 230 && mx< 400 && my>300 && my<330 )
       outtextxy(300,305,"EXIT");
      else
       {setcolor(RED);
	outtextxy(300,305,"EXIT");
       }


  if( button & 1  == 1)


    if( mx> 230 && mx< 400 && my>250 && my<280 )
      {
       mouse.hidemouseptr();
       Rcount=Gcount=12;
       for(float k=0;k<500000;k++)
	  putpixel(150+random(330),80+random(300),BLACK);
       bar(150,80,480,380);

       Page3();
      }
    else
      if( mx> 230 && mx< 400 && my>300 && my<330 )
	{
	  mouse.hidemouseptr();
	  Page2();
	  float y=0;
	  while(!kbhit() && y<50000)
	    {  int randx=random(700);
	       int randy=80+random(400);
	       bar(randx,randy,randx+5,randy+5);
	       y++;
	    }

	  exit(0);
	}



    //getch();
    //exit(0);

  }

}





//*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*--*-*-*-*-*-

/* This is the function that begins the mouse usage and the function never
   will never come out since there is repeated call tranfer from this to
   another function  and from that function to this function */

 //long f=0;



//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
