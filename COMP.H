//if the computer's coin reaches the other end of the grid
void king(int i,int j)
  {
    setfillstyle(HATCH_FILL, YELLOW);
    fillellipse(i*50+25, j*50+25, 7.5, 7.5);
    BoardMemory[j][i]=KGreen;
  }

//computer movements
void Computer()
{

 int high=0,count=0,flag=0;
 /*
   count = for checking how many removable coins can be removed
   high =  highest number of coins removable
   flag =  symbolises type of movement
  */
 int imax=0,jmax=0;

 for(int i=0;i<8;i++)                                //comp jumps
    for(int j=0;j<8;j++)
       {
	 if(BoardMemory[j][i]==Green||BoardMemory[j][i]==KGreen)
	  {  count=0;
	     for(int x=i-1, y=j+1;x>0,x<8,y<7; y++,x--)   //left forward
		{
		  //from every x , it checks for the number of reds
		   if(BoardMemory[y][x]==Red || BoardMemory[y][x]==KRed)
		     { count++;
		     }

		   else break;
		}
	    if(BoardMemory[y][x]==Empty && x>=0 && x<8 && y<8 && count>high)
	      {
		 flag=1;
		 high=count;       //assign high the count value
		 imax=i;           // initial coordinates
		 jmax=j;
	      }

	     count=0;
	     for( x=i+1, y=j+1;x>0,x<7,y<7; y++,x++) //right forward
		{
		   if(BoardMemory[y][x]==Red || BoardMemory[y][x]==KRed)
		     { count++;

		     }

		   else break;
		}

	     if(BoardMemory[y][x]==Empty && x>0 && x<8 && y<8 && count>high)
		{
		 flag=2;
		 high=count;
		 imax=i;
		 jmax=j;
		}

	      if(BoardMemory[j][i]==KGreen)
		{
		    count=0;
	     for(int x=i-1, y=j-1;x>0,x<8,y>0; y--,x--)  //left backward
		{
		   if(BoardMemory[y][x]==Red || BoardMemory[y][x]==KRed)
		     { count++;

		     }

		   else break;
		}
		if(BoardMemory[y][x]==Empty && x>=0 && x<8 && y>=0 && y<8 && count>high)
	      {
		 flag=4;
		 high=count;
		 imax=i;
		 jmax=j;
	      }


	     count=0;
	     for( x=i+1, y=j-1;x>0,x<8,y>0; y--,x++) //right backward
		{
		   if(BoardMemory[y][x]==Red || BoardMemory[y][x]==KRed)
		     { count++;

		     }

		   else break;
		}
		if(BoardMemory[y][x]==Empty && x>=0 && x<8 && y>=0 && y<8 && count>high)
	      {
		 flag=3;
		 high=count;
		 imax=i;
		 jmax=j;
	      }


		}
	  }

       }    //end of for(i=0....)   lop

 //empty the initial and all coins in between
 if(flag!=0)
   {     delay(200);
	 i=imax;
	 j=jmax;

	 if(flag==1)
	   for(; j<=jmax+high; j++,i--)
	   {

		 mouse.hidemouseptr();
		 if(BoardMemory[j][i]==KGreen)
		    flag=3;                      //reinitialisation

		 BoardMemory[j][i]=Empty;
		 setfillstyle(1,BLACK);
		 bar(i*50+5,j*50+5,i*50+45,j*50+45); //empty initial

	   }
	 else
	 if(flag==2)
	   for(; j<=jmax+high; j++,i++)
	   {

		 mouse.hidemouseptr();
		  if(BoardMemory[j][i]==KGreen)
		    flag=3;

		 BoardMemory[j][i]=Empty;
		 setfillstyle(1,BLACK);
		 bar(i*50+5,j*50+5,i*50+45,j*50+45);

	   }

	    else
	   if(flag==3)
	     for(; j>=jmax-high; j--,i++)
	       {

		 mouse.hidemouseptr();

		 BoardMemory[j][i]=Empty;
		 setfillstyle(1,BLACK);
		 bar(i*50+5,j*50+5,i*50+45,j*50+45);

	   }

	 else
	   if(flag==4)
	     for(; j>=jmax-high; j--,i--)
	       {

		 mouse.hidemouseptr();
		 BoardMemory[j][i]=Empty;
		 setfillstyle(1,BLACK);
		 bar(i*50+5,j*50+5,i*50+45,j*50+45);

	   }




	 //coin move
	   setcolor( WHITE ) ;
	   setfillstyle(HATCH_FILL, GREEN);
	   fillellipse(i*50+25,j*50+25, 15, 15 );
	   BoardMemory[j][i]=Green;
	   if(j==7 || flag==3 || flag==4)
	     king(i,j);
	   Rcount-=high;
	   turn=Red;
	   return;

   }                                       //end ofjump

   else                  //if none of the above condns are satisfied
    {if(flag==0)                       //single movement
       for(int i=0;i<8;i++)
	  for(int j=0;j<8;j++)
	     if(BoardMemory[j][i]==Green)
	       {                                        //special movements
		 if(BoardMemory[j+1][i-1]!=Empty &&
		    BoardMemory[j+1][i+1]!=Empty   )
		    continue;

		 if(BoardMemory[j+2][i-2]==Red &&
		    BoardMemory[j+2][i+2]==Red)
		    continue;


		 if(BoardMemory[j+1][i-1]==Red && BoardMemory[j+1][i+1]!=Red
		      && i<7 && j<7)
		   {  delay(500);
		      setcolor( WHITE ) ;
		      setfillstyle(HATCH_FILL, GREEN);
		      mouse.hidemouseptr();
		      BoardMemory[j+1][i+1]=Green;
		      fillellipse((i+1)*50+25,(j+1)*50+25, 15, 15 );
		      setfillstyle(1,BLACK);
		      bar(i*50+5,j*50+5,i*50+45,j*50+45);
		      if(j+1==7 || BoardMemory[j][i]==KGreen)
			 king(i+1,j+1);
		      turn=Red;
		      BoardMemory[j][i]=Empty;
		      return;
		   }

		 if(BoardMemory[j+1][i+1]==Red && BoardMemory[j+1][i-1]!=Red
		      && i>0 && i<7 && j<7)
		   {  delay(500);
		      setcolor( WHITE ) ;
		      setfillstyle(HATCH_FILL, GREEN);
		      mouse.hidemouseptr();

		      BoardMemory[j+1][i-1]=Green;
		      fillellipse((i-1)*50+25,(j+1)*50+25, 15, 15 );
		      setfillstyle(1,BLACK);
		      bar(i*50+5,j*50+5,i*50+45,j*50+45);
		      if(j+1==7 || BoardMemory[j][i]==KGreen)
			    king(i-1,j+1);
		       BoardMemory[j][i]=Empty;
		      turn=Red;
		      return;
		   }



		}

   int ctr=0;
   while(1 && ctr<5000)                                 //normal movement
    { ctr++;
    if(ctr==4900)
      exit(0);
      i=random(8);
      j=random(8);
       if(BoardMemory[j][i]==Green || BoardMemory[j][i]==KGreen
	  && i<9 && i>=0 && j<=7)

	 {  if(BoardMemory[j][i]==KGreen &&
	       BoardMemory[j+1][i-1]!=Empty &&
	       BoardMemory[j+1][i+1]!=Empty &&
	       BoardMemory[j-1][i-1]!=Empty &&
	       BoardMemory[j-1][i+1]!=Empty  )
	       continue;
	   else
	    if(BoardMemory[j][i]==Green &&
	       BoardMemory[j+1][i-1]!=Empty &&
	       BoardMemory[j+1][i+1]!=Empty   )
	       continue;


	    int k=random(10);

	     if(k%2==0 )
	      if(BoardMemory[j][i]==KGreen)
		{

		    k=random(10);


		    if(k%2==0 && BoardMemory[j-1][i-1]==Empty && j>0 && i>0 )
		    {     delay(500);
			  setcolor( WHITE ) ;
			  setfillstyle(HATCH_FILL, GREEN);
			  mouse.hidemouseptr();
			  fillellipse((i-1)*50+25,(j-1)*50+25, 15, 15 );
			  setfillstyle(1,BLACK);
			  bar(i*50+5,j*50+5,i*50+45,j*50+45);
			  turn=Red;
			  king(i-1,j-1);
			  BoardMemory[j][i]=Empty;
			  return;
		      }


		    if(k%2==1 && BoardMemory[j-1][i+1]==Empty &&j<8 && i<7 )
		      {    delay(500);
			   setcolor( WHITE ) ;
			   setfillstyle(HATCH_FILL, GREEN);
			   mouse.hidemouseptr();
			   fillellipse((i+1)*50+25,(j-1)*50+25, 15, 15 );
			   setfillstyle(1,BLACK);
			   bar(i*50+5,j*50+5,i*50+45,j*50+45);
			   king(i+1,j-1);
			   BoardMemory[j][i]=Empty;
			   turn=Red;
			   return;
			}

		}


	      k=random(100);


	      if(k%2==0 && BoardMemory[j+1][i-1]==Empty && j<7 && i>0 )
		{ 	 delay(500);
			setcolor( WHITE ) ;
			setfillstyle(HATCH_FILL, GREEN);
			mouse.hidemouseptr();
			fillellipse((i-1)*50+25,(j+1)*50+25, 15, 15 );
			setfillstyle(1,BLACK);
			bar(i*50+5,j*50+5,i*50+45,j*50+45);
			turn=Red;
			BoardMemory[j+1][i-1]=Green;
			if(j+1==7 ||  BoardMemory[j][i]==KGreen)
			   king(i-1,j+1);
			BoardMemory[j][i]=Empty;
			return;
		 }

	      else
	      if(k%2==1 && BoardMemory[j+1][i+1]==Empty &&j<7 && i<7 )
		{	delay(500);
			setcolor( WHITE ) ;
			setfillstyle(HATCH_FILL, GREEN);
			mouse.hidemouseptr();
			fillellipse((i+1)*50+25,(j+1)*50+25, 15, 15 );
			setfillstyle(1,BLACK);
			bar(i*50+5,j*50+5,i*50+45,j*50+45);
			BoardMemory[j+1][i+1]=Green;
			if(j+1==7 || BoardMemory[j][i]==KGreen)
			   king(i+1,j+1);
			BoardMemory[j][i]=Empty;
			turn=Red;
			return;
		}
	 }

      }//end of while(1)

    }//end of if(flag==0)

}//end of computer fn