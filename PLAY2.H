//void Play2(int);
class checkers
{
 public:
 //void Page3();
//void Page2();
      void PlayLogic(int ,int,int);
//void Exit();
//void Board(int);
//void Play1(int);
     // void Tossresult(int);
      void Play2(int );

}check;
void checkers::Play2(int flag)
{
  int button, mx, my ,flag1=1;
  settextstyle( 4, 0, 3 );
  setcolor(WHITE);
  outtextxy( 570, 5,"Exit");

  setfillstyle(1,GREEN);
  bar(580,35,600,55);
  setcolor(WHITE);
  line(583,52,597,38);
  line(583,38,597,52);
  setcolor(BLACK);
  line(580,55,600,55);
  line(600,35,600,55);
  setcolor(WHITE);
  line(580,35,580,55);
  line(580,35,600,35);

 if(Rcount==0)
  {


     settextstyle(4,0,5);
     outtextxy(445,320,Name2);
     outtextxy(450,370," WINS ");
     int y=0;
     while(y<700 && !kbhit())
	       {delay(10);
		for(int i=0;i<50;i++)
		   putpixel(random(getmaxx()),random(50+y),random(13));
		y++;
	       }
     win(1);


  }

 if(Gcount==0)
  {
     settextstyle(4,0,5);
     outtextxy(445,320,Name1);
     outtextxy(450,370," WINS ");
     int y=0;
     while(y<700 && !kbhit())
	       {delay(10);
		for(int i=0;i<50;i++)
		   putpixel(random(getmaxx()),random(50+y),random(13));
		y++;
	       }
    win(2);

  }
  while( 1 )
  {
    mouse.showmouseptr();
    mouse.getmousepos(&button,&mx, &my );

    if( mx> 580 && mx< 600 && my>35 && my<55 && flag1==1)    //For exit
      {
       mouse.hidemouseptr();
       bar(580,35,600,55);
       setcolor(BLACK);
       line(584,53,598,39);
       line(584,39,598,53);
       setcolor(WHITE);
       line(580,55,600,55);
       line(600,35,600,55);
       setcolor(BLACK);
       line(580,35,580,55);
       line(580,35,600,35);
       delay(200);
       flag1=0;
       mouse.showmouseptr();

      }
    else
    if(flag1==0)
      { mouse.hidemouseptr();
	bar(580,35,600,55);
	setcolor(WHITE);
	line(583,52,597,38);
	line(583,38,597,52);
	setcolor(BLACK);
	line(580,55,600,55);
	line(600,35,600,55);
	setcolor(WHITE);
	line(580,35,580,55);
	line(580,35,600,35);
	flag1=1;
	mouse.showmouseptr();
      }


       if(turn==Comp)
		{ Computer();    //function call transferred to computer
		  turn=Red;      //  function in Comp.CPP and
		  return;        //    computer does its movements

		}

    settextstyle(1,0,2);
    if( button & 1  == 1)
      {
       if( mx >=0 && mx<=400 && my >=0 && my <=400 ) //Grid Area
	 {
	  if( BoardMemory[my / 50][mx / 50 ] == Empty ) //Click action
	    {
		setcolor(WHITE) ;
		settextstyle(4,0,4);
		outtextxy(450,340,"No Coin");
		delay( 150 );
		setcolor(BLACK) ;
		settextstyle(4,0,4);
		outtextxy(450,340,"No Coin");

	    }
	  if(turn==Green)
	    if( BoardMemory[my / 50][mx / 50 ] == Green )
	      {
		setcolor(WHITE) ;
		settextstyle(4,0,4);
		outtextxy(450,340,"Green Coin");
		delay( 150 );
		setcolor(BLACK) ;
		outtextxy(450,340,"Green Coin");
		Pick = Green ;
		PlayLogic(mx,my,Pick);
		return;
	      }
	    else
	    if( BoardMemory[my / 50][mx / 50 ] ==KGreen )
	      {
		setcolor(WHITE) ;
		settextstyle(4,0,4);
		outtextxy( 450, 340, "Green King");
		delay( 150 );
		setcolor(BLACK) ;
		outtextxy( 450,340, "Green King");
		Pick = KGreen ;
		PlayLogic(mx,my,Pick);
		return;
	      }


	  if(turn==Red)
	    {
	     if( BoardMemory[my / 50][mx / 50 ] == Red )
	      {
		setcolor(WHITE) ;
		settextstyle(4,0,4);
		outtextxy( 450, 340, "Red Coin");
		delay( 150 );
		setcolor(BLACK) ;
		outtextxy( 450, 340, "Red Coin");
		Pick = Red ;
		if(flag==1)
		  turn=Comp;
		if(flag==2)
		  turn=Green;
		PlayLogic(mx,my,Pick);
		return;
	      }
	      else
	     if( BoardMemory[my / 50][mx / 50 ] ==KRed )
	      {
		setcolor(WHITE) ;
		settextstyle(4,0,4);
		outtextxy( 450, 340, "Red King");
		delay( 150 );
		setcolor(BLACK) ;
		outtextxy( 450, 340, "Red King");
		Pick = KRed ;
		if(flag==1)
		  turn=Comp;
		if(flag==2)
		  turn=Green;
		PlayLogic(mx,my,Pick);
		return;
	      }
	    }  // end of if(turn=red)....
	 }//End of Grid Area

	 if( mx> 580 && mx< 600 && my>35 && my<55 )    //For exit
	   Exitnext() ;

      }//Button &1==1


  }//End of while
}//End of Play2()
