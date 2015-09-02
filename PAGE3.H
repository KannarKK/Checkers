/*page 3 for showing the options to the user
  whether he wants to play or read instruction manual or exit */

void Page3()
	{

	     int y=0;

	     while(y<637)
		{
			setcolor(RED);
			line(y+3,0,y+3,600);
			line(y+2,0,y+2,600);
			line(y+1,0,y+1,600);
			setcolor(BLACK);
			line(y,0,y,600);
			setfillstyle(SOLID_FILL,RED);
			bar(0,0,y+3,10);
			bar(0,getmaxy()-10,y+3,getmaxy());
			setcolor(BLACK);
			line(0,5,y+3,5);
			line(0,getmaxy()-5,y+3,getmaxy()-5);
			y++;
			delay(2);

		}
	     bar(0,6,3,getmaxy()-6);
	     bar(getmaxx()-3,6,getmaxx(),getmaxy()-6);





	   settextstyle(5,0, 7) ;
	   for(int i=0;i<10; i++)
	   { setcolor(BLINK+RED);
	     outtextxy(110+i/2,90-i/2, " CHECKERS");
	     delay(100);
	   }

	   settextstyle(4,0, 7) ;
	   for( i=0;i<440;i++)
	   { setcolor(YELLOW+128);
	     outtextxy(510-i,150, "-");
	     delay(2);
	   }

	   setfillstyle(1,WHITE);
	   for(i=0;i<200;i++)
	   { bar(210,250,210+i,280);
	     bar(210,310,210+i,340);
	     bar(210,370,210+i,400);
	     delay(5);
	   }
	   rectangle(205,245,415,285);
	   rectangle(205,305,415,345);
	   rectangle(205,365,415,405);

	   setcolor(RED);
	   settextstyle(11,0,4) ;
	   outtextxy(290,260,"PLAY");
	   outtextxy(290,320,"HELP");
	   outtextxy(290,380,"EXIT");

	   mouse.initmouse();

	   int button,m,n,flag1=1,flag2=1,flag3=1;

	   while(1)
	   { mouse.showmouseptr();
	     mouse.getmousepos(&button,&m,&n);
	     if(m>210&&m<410&&n>250&&n<280)
	      {
		if(flag1==1)
		  {  mouse.hidemouseptr();
		     setfillstyle(1,9);
		     setcolor(14);
		     bar(210,250,410,280);
		     rectangle(205,245,415,285);
		     setcolor(WHITE);
		     outtextxy(290,263,"PLAY");
		     flag1=0;

		  }
	      }
	     else
	     {
	       if(flag1==0)
	       {  mouse.hidemouseptr();
		  setfillstyle(1,WHITE);
		  setcolor(WHITE);
		  rectangle(205,245,415,285);
		  bar(210,250,410,280);
		  setcolor(RED);
		  outtextxy(290,260,"PLAY");
		  flag1=1;
	       }
	     }

	     if(m>210&&m<410&&n>310&&n<340)
	     {
	      if(flag2==1)
	       {  mouse.hidemouseptr();
		  setfillstyle(1,9);
		  setcolor(14);
		  rectangle(205,305,415,345);
		  bar(210,310,410,340);
		  setcolor(WHITE);
		  outtextxy(290,323,"HELP");
		  flag2=0;
	       }
	     }
	     else
	     {
	      if(flag2==0)
	       {  mouse.hidemouseptr();
		  setfillstyle(1,WHITE);
		  setcolor(WHITE);
		  rectangle(205,305,415,345);
		  bar(210,310,410,340);
		  setcolor(RED);
		  outtextxy(290,320,"HELP");
		  flag2=1;
	       }
	     }

	     if(m>210&&m<410&&n>370&&n<400)
	     {
	       if(flag3==1)
		{ mouse.hidemouseptr();
		  setfillstyle(1,9);
		  setcolor(14);
		  rectangle(205,365,415,405);
		  bar(210,370,410,400);
		  setcolor(WHITE);
		  outtextxy(290,383,"EXIT");
		  flag3=0;
		}
	     }
	     else
	     {
	       if(flag3==0)

		{ mouse.hidemouseptr();
		  setfillstyle(1,WHITE);
		  setcolor(WHITE);
		  rectangle(205,365,415,405);
		  bar(210,370,410,400);
		  setcolor(RED);
		  outtextxy(290,380,"EXIT");
		  flag3=1;
	       }
	      }

	      if(button==1)
	      {
		mouse.hidemouseptr();
		if(m>210&&m<410&&n>250&&n<280)
		   Playby();     //in the program PLAY.CPP
		if(m>210&&m<410&&n>310&&n<340)
		   help();
		if(m>210&&m<410&&n>370&&n<400)
		   Exitnext() ;
	      }

	  }  //end of while
}    //end of page3()
