//void Play1();
//void Play2();
void help();
//-----------------------------------------------------------------------
//The creation of the king
 void GKING(int i,int j)
  {
    setfillstyle(HATCH_FILL, YELLOW);
    fillellipse(i*50+25, j*50+25, 7.5, 7.5);
    BoardMemory[j][i]=KGreen;
  }

 void RKING(int i,int j)
  {
    setfillstyle(HATCH_FILL, YELLOW);
    fillellipse(i*50+25, j*50+25, 7.5, 7.5);
    BoardMemory[j][i]=KRed;
  }


//extern long f;    //for time function

//function for the logic of the game (working)
void checkers::PlayLogic(int mx,int my,int Pick)
{
 int button,nx,ny;
 setcolor(WHITE);

 if( Pick==Green || Pick==Red ||Pick==KGreen || Pick==KRed)
 {
   BoardMemory[my / 50][mx / 50 ]=Empty;
   setfillstyle(HATCH_FILL, WHITE);// to show that the user has clicked
   mouse.hidemouseptr();
   fillellipse(mx/50*50+25, my/50*50+25, 15, 15 ) ;

   //next click  more casually the second click by the user
    while(1)
    {
      /* data variable f is of extern data type, hence its creation happen
      once even if the function Playlogic or while is repeatedly executed*/

      mouse.showmouseptr();
      mouse.getmousepos(&button,&nx,&ny);
      if(button&1==1)
      {
	if( nx >=0 && nx<=400 && ny >=0 && ny <=400 ) //Grid Area
	{
	 if(nx/50==mx/50 && ny/50==my/50)   //deselection
	  {
	     delay( 130 );
	     if(Pick==Red || Pick==KRed)
	     {
	       setcolor( WHITE ) ;
	       setfillstyle(HATCH_FILL, RED);
	       // to show that the user has clicked there itself again
	       mouse.hidemouseptr();
	       fillellipse(mx/50*50+25, my/50*50+25, 15, 15 );
	       BoardMemory[my/50][mx/50] =Red;
	       if(Pick==KRed)
		 RKING(mx/50,my/50);   //board memory is retrieved back

		turn=Red;              //turn must remain red!
		return;
	      }
	     if(Pick==Green || Pick==KGreen )
	     {
	       setcolor( WHITE ) ;
	       setfillstyle(HATCH_FILL, GREEN);
	       // to show that the user has clicked
	       mouse.hidemouseptr();
	       fillellipse(mx/50*50+25, my/50*50+25, 15, 15 ) ;
	       BoardMemory[my/50][mx/50]=Green;
	       if(Pick ==KGreen)
		GKING(mx/50,my/50);

		turn=Green;
		return;
	     }
	  }  //end of if(..) for deselection

     if(nx/50-mx/50!=ny/50-my/50 && nx/50-mx/50!=-(ny/50-my/50))
       {
	     settextstyle(4,0,3);
	     outtextxy(480,320,"ERROR");
	     settextstyle(11,0,9);
	     outtextxy(470,370,"Only diagonal  ");
	     outtextxy(431,380," movements are possible ");
	     delay(1000);
	     setfillstyle(0,BLACK);
	     bar(435,315,615,435);

       }

     else

     if((nx/50+ny/50)%2==0)                     //BLACK BLOCKS
       {
	 if(BoardMemory[ny/50][nx/50]!=Empty)
	   {
	     settextstyle(4,0,3);
	     outtextxy(480,320,"ERROR");
	     settextstyle(11,0,9);
	     outtextxy(450,370,"Cannot place a pon  ");
	     outtextxy(450,380,"in a block inhabited ");
	     outtextxy(450,390,"by another pon");
	     delay(1000);
	     setfillstyle(0,BLACK);
	     bar(435,315,615,435);

	   }


	 if(BoardMemory[ny/50][nx/50]==Empty)   //if empty square
	  {
	   if(Pick==Green || Pick==KGreen)
	   {
	     if((my/50+1==ny/50)&&((mx/50+1==nx/50)||(mx/50-1==nx/50)))
	     {             //one move either left/right forward

	      setcolor( WHITE ) ;
	      setfillstyle(HATCH_FILL, GREEN);
	      mouse.hidemouseptr();
	      fillellipse(nx/50*50+25, ny/50*50+25, 15, 15 );
	      setfillstyle(1,BLACK);
	      bar(mx/50*50+5,my/50*50+5,mx/50*50+45,my/50*50+45);
	      turn=Red;
	      BoardMemory[ny / 50][nx / 50 ]=Pick;
	      if(ny/50==7 || Pick==KGreen)
		GKING(nx/50,ny/50);

	      return;
	     }
	    if(Pick==KGreen)
	    {     //only KGreen has l/r backward movements.. SUPERPOWER!!!

	      if((my/50-1==ny/50)&&((mx/50+1==nx/50)||(mx/50-1==nx/50)))
	       {
		setcolor( WHITE ) ;
		setfillstyle(HATCH_FILL, GREEN);
		mouse.hidemouseptr();
		fillellipse(nx/50*50+25, ny/50*50+25, 15, 15 );
		setfillstyle(1,BLACK);
		bar(mx/50*50+5,my/50*50+5,mx/50*50+45,my/50*50+45);
		turn=Red;

		GKING(nx/50,ny/50);
		return;
	       }
	      }
      //jumps

	     if(mx/50>nx/50 && my/50<ny/50) //movement of KGReen
	     {                             //movement towards left
		 int i=mx/50-1,j=my/50+1;  //start checking from previous
		 int value= 0;

		 for(; j<ny/50; j++,i--)
		 {
		 //check whether from mx to nx we have every other pon
		  if(BoardMemory[j][i]==Red || BoardMemory[j][i]==KRed)
		   value=1;
		  else
		   {	value=0;
			break;
		   }
		 }

	      if(value==1)
		{
		 int i=mx/50,j=my/50;
		for(; j<ny/50; j++,i--)
		{
		 setcolor( WHITE ) ;
		 setfillstyle(HATCH_FILL, GREEN);
		 mouse.hidemouseptr();
		 fillellipse(nx/50*50+25, ny/50*50+25, 15, 15 );
		 BoardMemory[j][i]=Empty;
		 setfillstyle(1,BLACK);
		 bar(i*50+5,j*50+5,i*50+45,j*50+45);
		}
	       } //end of if(value==1)

	     else if(value==0)                     //ERROR
	     {
	       settextstyle(1,0,3);
	       setcolor( WHITE ) ;
	       settextstyle(4,0,3);
	       outtextxy(480,320,"ERROR");
	       settextstyle(11,0,9);
	       outtextxy(450,380,"Cannot jump over an ");
	       outtextxy(480,400,"empty block");


	      setcolor( WHITE ) ;
	      setfillstyle(HATCH_FILL, GREEN);
	      fillellipse(mx/50*50+25, my/50*50+25, 15, 15 );
	      if(Pick==KGreen)
	       GKING(mx/50,my/50);

	      BoardMemory[my / 50][mx / 50 ]=Pick;
	      turn=Green;
	      delay(1000);
	      return;
	      }

	      turn=Red;  //after all types of left jumps
	       if(ny/50==7 || Pick==KGreen)
		 { Pick=KGreen;
		   GKING(nx/50,ny/50);
		 }

	       BoardMemory[ny / 50][nx / 50 ]=Pick;
	       Rcount-=ny/50-my/50-1;    //coins get reduced
	       return;
	      }

	    if(mx/50<nx/50 && my/50<ny/50) //right movements for kgreen
	    {
	      int i=mx/50+1,j=my/50+1;
	      int value= 0;

	      for(; j<ny/50; j++,i++)
	      {
	       if(BoardMemory[j][i]==Red || BoardMemory[j][i]==KRed)
		value=1;
	       else
		value=0;
		break;
	      }

	      if(value==1)
	      {
	       int i=mx/50,j=my/50;
	       for(; j<ny/50; j++,i++)
	       {
		 setcolor( WHITE ) ;
		 setfillstyle(HATCH_FILL, GREEN);
		 mouse.hidemouseptr();
		 fillellipse(nx/50*50+25, ny/50*50+25, 15, 15 );
		 BoardMemory[j][i]=Empty;
		 setfillstyle(1,BLACK);
		 bar(i*50+5,j*50+5,i*50+45,j*50+45);
	       }
	      }

	     else if(value==0)                     //ERROR
	     {
	       settextstyle(1,0,3);
	       setcolor( WHITE ) ;
	       settextstyle(4,0,3);
	       outtextxy(480,320,"ERROR");
	       settextstyle(11,0,9);
	       outtextxy(450,380,"Cannot jump over an ");
	       outtextxy(480,400,"empty block");
	      setfillstyle(HATCH_FILL, GREEN);
	      setcolor( WHITE ) ;
	      fillellipse(mx/50*50+25, my/50*50+25, 15, 15 );
	      if(Pick==KGreen)
	      GKING(nx/50,ny/50);
	      BoardMemory[my / 50][mx / 50 ]=Pick;

	      turn=Green;
	      delay(1000);
	      return;
	     }     //end of right movements..


		if(ny/50==7 || Pick==KGreen) //if green coin reaches nx=7
		 { Pick=KGreen;
		   GKING(nx/50,ny/50);
		 }
		   turn=Red;
		   BoardMemory[ny / 50][nx / 50 ]=Pick;
		   Rcount-=ny/50-my/50-1;
		   return;
	    } //end of pick==KGreen

   if(Pick==KGreen)
   {
     if(mx/50>nx/50 && my/50>ny/50)
      {

       int i=mx/50-1,j=my/50-1;
       int value= 0;

	 for(; j>ny/50; j--,i--)
	 {
	   if(BoardMemory[j][i]==Red || BoardMemory[j][i]==KRed)
		value=1;

	     else
	       {	value=0;
			break;
	       }
	 }

	 if(value==1)
	 {
	    int i=mx/50,j=my/50;
	   for(; j>ny/50; j--,i--)
	   {
		 setcolor( WHITE ) ;
		 setfillstyle(HATCH_FILL, GREEN);
		 mouse.hidemouseptr();
		 fillellipse(nx/50*50+25, ny/50*50+25, 15, 15 );
		 BoardMemory[j][i]=Empty;
		 setfillstyle(1,BLACK);
		 bar(i*50+5,j*50+5,i*50+45,j*50+45);

	   }
	 }

	 else if(value==0)                     //ERROR
	 {
	      settextstyle(1,0,3);
	      setcolor( WHITE ) ;
	      settextstyle(4,0,3);
	      outtextxy(480,320,"ERROR");
	      settextstyle(11,0,9);
	      outtextxy(450,380,"Cannot jump over an ");
	      outtextxy(480,400,"empty block");
	    setfillstyle(HATCH_FILL, GREEN);
	    setcolor( WHITE ) ;
	    fillellipse(mx/50*50+25, my/50*50+25, 15, 15 );
	    GKING(mx/50,my/50);
	    BoardMemory[my / 50][mx / 50 ]=Pick;
	    turn=Green;
	    delay(1000);
	    return;
	 }

		   turn=Red;
		   GKING(nx/50,ny/50);
		   BoardMemory[ny / 50][nx / 50 ]=Pick;
		   Rcount-=my/50-ny/50-1;
		   return;
   }


     if(mx/50<nx/50 && my/50>ny/50)
      {

       int i=mx/50+1,j=my/50-1;
       int value= 0;

	 for(; j>ny/50; j--,i++)
	 {
	   if(BoardMemory[j][i]==Red || BoardMemory[j][i]==KRed)
		value=1;

	     else
		value=0;

	 }

	 if(value==1)
	 {
	    int i=mx/50,j=my/50;
	   for(; j>ny/50; j--,i++)
	   {
		 setcolor( WHITE ) ;
		 setfillstyle(HATCH_FILL, GREEN);
		 mouse.hidemouseptr();
		 fillellipse(nx/50*50+25, ny/50*50+25, 15, 15 );
		 GKING(nx/50,ny/50);
		 BoardMemory[j][i]=Empty;
		 setfillstyle(1,BLACK);
		 bar(i*50+5,j*50+5,i*50+45,j*50+45);

	   }
	 }

	 else if(value==0)                     //ERROR
	 {
	     settextstyle(1,0,3);
	     setcolor( WHITE ) ;
	     settextstyle(4,0,3);
	     outtextxy(480,320,"ERROR");
	     settextstyle(11,0,9);
	     outtextxy(450,380,"Cannot jump over an ");
	     outtextxy(480,400,"empty block");
	    setfillstyle(HATCH_FILL, GREEN);
	    setcolor( WHITE ) ;
	    fillellipse(mx/50*50+25, my/50*50+25, 15, 15 );
	    GKING(mx/50,my/50);
	    BoardMemory[my / 50][mx / 50 ]=Pick;
	    turn=Green;
	    delay(1000);
	    return;
	 }




		   GKING(nx/50,ny/50);
		   turn=Red;
		   BoardMemory[ny / 50][nx / 50 ]=Pick;
		   Rcount-=my/50-ny/50-1;
		   return;
   }

   }


     }//end of pick==green

		       if(Pick==Red || Pick==KRed)
			 {
			    if((my/50-1==ny/50)&&((mx/50+1==nx/50)||(mx/50-1==nx/50)))
			      { setcolor( WHITE ) ;
				setfillstyle(HATCH_FILL, RED);
				mouse.hidemouseptr();
				fillellipse(nx/50*50+25, ny/50*50+25, 15, 15 ) ;
				setfillstyle(1,BLACK);
				bar(mx/50*50+5,my/50*50+5,mx/50*50+45,my/50*50+45);
				BoardMemory[ny / 50][nx / 50 ]=Pick;
				if(ny/50==0 || Pick==KRed )
				   RKING(nx/50,ny/50);

				return;
			      }

			  if(Pick==KRed)
			   if((my/50+1==ny/50)&&((mx/50+1==nx/50)||(mx/50-1==nx/50)))
			      {
				setcolor( WHITE ) ;
				setfillstyle(HATCH_FILL, RED);
				mouse.hidemouseptr();
				fillellipse(nx/50*50+25, ny/50*50+25, 15, 15 );
				setfillstyle(1,BLACK);
				bar(mx/50*50+5,my/50*50+5,mx/50*50+45,my/50*50+45);
				RKING(nx/50,ny/50);

				return;
			      }





    if(mx/50>nx/50 && my/50>ny/50)
      {

       int i=mx/50-1,j=my/50-1;
       int value= 0;

	 for(; j>ny/50; j--,i--)
	 {
	   if(BoardMemory[j][i]==Green || BoardMemory[j][i]==KGreen)
		value=1;

	     else
	       {	value=0;   break;}

	 }

	 if(value==1)
	 {
	    int i=mx/50,j=my/50;
	   for(; j>ny/50; j--,i--)
	   {
		 setcolor( WHITE ) ;
		 setfillstyle(HATCH_FILL, RED);
		 mouse.hidemouseptr();
		 fillellipse(nx/50*50+25, ny/50*50+25, 15, 15 );
		 BoardMemory[j][i]=Empty;
		 setfillstyle(1,BLACK);
		 bar(i*50+5,j*50+5,i*50+45,j*50+45);

	   }
	 }

	 else if(value==0)                     //ERROR
	 {
	    settextstyle(1,0,3);
	    setcolor( WHITE ) ;
	    settextstyle(4,0,3);
	    outtextxy(480,320,"ERROR");
	    settextstyle(11,0,9);
	    outtextxy(450,380,"Cannot jump over an ");
	    outtextxy(480,400,"empty block");
	    setfillstyle(HATCH_FILL, RED);
	    setcolor( WHITE ) ;
	    fillellipse(mx/50*50+25, my/50*50+25, 15, 15 );
	    if(Pick==KRed)
		   RKING(mx/50,my/50);
	    BoardMemory[my / 50][mx / 50 ]=Pick;
	    turn=Red;
	    delay(1000);
	    return;
	 }

		 BoardMemory[ny / 50][nx / 50 ]=Pick;
		 if(ny/50==0 || Pick==KRed)
		    RKING(nx/50,ny/50);

		 Gcount-=my/50-ny/50-1;
		 return;
   }


     if(mx/50<nx/50 && my/50>ny/50)
      {

       int i=mx/50+1,j=my/50-1;
       int value= 0;

	 for(; j>ny/50; j--,i++)
	 {
	   if(BoardMemory[j][i]==Green || BoardMemory[j][i]==KGreen)
		value=1;

	     else
	      {	value=0;  break;}

	 }

	 if(value==1)
	 {
	    int i=mx/50,j=my/50;
	   for(; j>ny/50; j--,i++)
	   {
		 setcolor( WHITE ) ;
		 setfillstyle(HATCH_FILL, RED);
		 mouse.hidemouseptr();
		 fillellipse(nx/50*50+25, ny/50*50+25, 15, 15 );
		 BoardMemory[j][i]=Empty;
		 setfillstyle(1,BLACK);
		 bar(i*50+5,j*50+5,i*50+45,j*50+45);

	   }
	 }

	 else if(value==0)                     //ERROR
	 {

	    settextstyle(1,0,3);
	    setcolor( WHITE ) ;
	    settextstyle(4,0,3);
	    outtextxy(480,320,"ERROR");
	    settextstyle(11,0,9);
	    outtextxy(450,380,"Cannot jump over an ");
	    outtextxy(480,400,"empty block");
	    setfillstyle(HATCH_FILL, RED);
	    setcolor( WHITE ) ;
	    fillellipse(mx/50*50+25, my/50*50+25, 15, 15 );
	    if( Pick==KRed )
	      RKING(mx/50,my/50);
	    BoardMemory[my / 50][mx / 50 ]=Pick;
	    turn=Red;
	    delay(1000);
	    return;
	 }


		   BoardMemory[ny / 50][nx / 50 ]=Pick;
		   if(ny/50==0 || Pick==KRed )
		     RKING(nx/50,ny/50);
		   Gcount-=my/50-ny/50-1;
		   return;
   }

  if(Pick==KRed)
    {
      if(mx/50>nx/50 && my/50<ny/50)
      {

       int i=mx/50-1,j=my/50+1;
       int value= 0;

	 for(; j<ny/50; j++,i--)
	 {
	   if(BoardMemory[j][i]==Green || BoardMemory[j][i]==KGreen)
		value=1;

	     else
	       {	value=0;   break;}

	 }

	 if(value==1)
	 {
	    int i=mx/50,j=my/50;
	   for(; j<ny/50; j++,i--)
	   {
		 setcolor( WHITE ) ;
		 setfillstyle(HATCH_FILL, RED);
		 mouse.hidemouseptr();
		 fillellipse(nx/50*50+25, ny/50*50+25, 15, 15 );
		 BoardMemory[j][i]=Empty;
		 setfillstyle(1,BLACK);
		 bar(i*50+5,j*50+5,i*50+45,j*50+45);

	   }
	 }

	 else if(value==0)                     //ERROR
	 {
	    settextstyle(1,0,3);
	    setcolor( WHITE ) ;
	    settextstyle(4,0,3);
	    outtextxy(480,320,"ERROR");
	    settextstyle(11,0,9);
	    outtextxy(450,380,"Cannot jump over an ");
	    outtextxy(480,400,"empty block");
	    setfillstyle(HATCH_FILL, RED);
	    setcolor( WHITE ) ;
	    fillellipse(mx/50*50+25, my/50*50+25, 15, 15 );
	    RKING(mx/50,my/50);
	    BoardMemory[my / 50][mx / 50 ]=Pick;
	    turn=Red;
	    delay(1000);
	    return;
	 }


		 RKING(nx/50,ny/50);
		 Gcount-=ny/50-my/50-1;
		 return;
   }


     if(mx/50<nx/50 && my/50<ny/50)
      {

       int i=mx/50+1,j=my/50+1;
       int value= 0;

	 for(; j<ny/50; j++,i++)
	 {
	   if(BoardMemory[j][i]==Green || BoardMemory[j][i]==KGreen)
		value=1;

	     else
	      {	value=0;  break;}

	 }

	 if(value==1)
	 {
	    int i=mx/50,j=my/50;
	   for(; j<ny/50; j++,i++)
	   {
		 setcolor( WHITE ) ;
		 setfillstyle(HATCH_FILL, RED);
		 mouse.hidemouseptr();
		 fillellipse(nx/50*50+25, ny/50*50+25, 15, 15 );
		 BoardMemory[j][i]=Empty;
		 setfillstyle(1,BLACK);
		 bar(i*50+5,j*50+5,i*50+45,j*50+45);

	   }
	 }

	 else if(value==0)                     //ERROR
	 {
	    settextstyle(1,0,3);
	    setcolor( WHITE ) ;
	    settextstyle(4,0,3);
	    outtextxy(480,320,"ERROR");
	    settextstyle(11,0,9);
	    outtextxy(450,380,"Cannot jump over an ");
	    outtextxy(480,400,"empty block");
	    setfillstyle(HATCH_FILL, RED);
	    setcolor( WHITE ) ;
	    fillellipse(mx/50*50+25, my/50*50+25, 15, 15 );
	    RKING(mx/50,my/50);
	    BoardMemory[my / 50][mx / 50 ]=Pick;
	    turn=Red;
	    delay(1000);
	    return;
	 }


		   RKING(nx/50,ny/50);
		   Gcount-=ny/50-my/50-1;
		   return;
   }
    }
			 }//end of pick==red


		    }  //end of if(board........==Empty)
		 }//end of black blocks
	       } // End of the grid
	    }  //end of button
	 } //end of while
     } //end of if(Pick==.......)



}  //end of playlogic function

//---------------------------------------------------------------------
