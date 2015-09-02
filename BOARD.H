//void Play2();
//--------------------------------------------------------------

/* this is the board function that creates the board with the memory
   implementation and click and move option */

class BOARD
{ int i,j,rad,color;
  public:
     BOARD(int x,int y,int col)
      {  i=x;
	 j=y;
	 rad=15;
	 color=col;
      }

     void insert()
      {
	fillellipse( i* 50 + 25, j * 50 + 25, rad, rad ) ;
	BoardMemory[j][i] = color ;
      }

};



void Board(int flag)
{


  cleardevice();
  for(int x=0;x<8;x++)             //initialising BoardMemory to 0
     for(int y=0;y<8;y++)
	 BoardMemory[x][y]=0;


  setcolor(WHITE);
  for(  x = 0 ; x < 8 ; x++ )
    {
     for(int  y = 0 ; y < 8 ; y++ )
       {
	if( x %2 == 0 && y%2 == 0)	//BLACK AREA
	  {
	   setfillstyle( SOLID_FILL, BLACK);
	   bar( x*50, y*50, x*50+50, y*50+50 ) ;
	   if( y<3 )                 //Green Coin
	   {
		setfillstyle( HATCH_FILL, GREEN);
		BOARD coin(x,y,Green);
		coin.insert();         	//Green Coin

			   // [y][x] because y is in the inner for loop
	   }//End of y < 3

	    if( y>=5 )                 //Red Coin
	    {
		setfillstyle( HATCH_FILL, RED);
		BOARD coin(x,y,Red);
		coin.insert();          //Red Coin

	    }//End of y >= 5
	  }  ///end of if for black area

	  else
	  if( x%2 == 1 && y % 2 == 1 )
	  {
	    setfillstyle( SOLID_FILL, BLACK);
	    bar( x*50, y*50, x*50+50, y*50+50 ) ;
	    if( y ==1)                 //Green Coin
	     {
		setfillstyle( HATCH_FILL, GREEN);
		BOARD coin(x,y,Green);
		coin.insert();          //Coin
	      }
	    if( y >= 5 )                 //Red Coin
	     {
		setfillstyle( HATCH_FILL, RED);
		BOARD coin(x,y,	Red);
		coin.insert();   	//Coin
	     }//End of y ==6

	   } //end of if(x%2==1...)...
	  else
	  {
	  setfillstyle( SOLID_FILL, RED);
	  bar( x*50, y*50, x*50+50, y*50+50 ) ;
	  BoardMemory[y][x] = Empty ;		//Empty
	  }

	}//End of x
    } //End of y

	//Border
	setcolor(WHITE) ;
	rectangle ( 0, 0, 400, 400 );
	rectangle ( 0, 0, 408, 408 );
	line(0,400,8,408);
	line(400,0,408,8);
	line(400,400,408,408);

	setcolor(BLACK);
	line(0,408,8,408);
	line(408,0,408,8);
	line(0,400,0,408);
	line(400,0,408,0);



	mouse.initmouse();            //INITIALISES MOUSE OPTION

	while(1)           //this is for the endless process of playing
	 { settextstyle(3,0,2);
	   setcolor(WHITE);
	   outtextxy(410,70," TURN  - ");         //for turn status
	   setfillstyle(1,BLACK);
	   bar(520,70,650,120);
	   settextstyle(4,0,3);

	   if(turn==Red)                            //to display turn status
	     setfillstyle( HATCH_FILL, RED);

	   if(turn==Comp || turn==Green)
	     setfillstyle( HATCH_FILL, GREEN);

	    fillellipse( 530, 80 , 15, 15 ) ;
	    circle(530,80,18);

	     setfillstyle( SOLID_FILL, BLACK);
	     bar(560,130,600,200);
	     setcolor(RED);
	     outtextxy(430,132,Name1);   //player 1 is displayed
	     gotoxy(74,10);cout<<Rcount;

	     setcolor(LIGHTGRAY);                     //error messages
	     rectangle(420,300,630,450);
	     for(int i=0;i<1000;i++)
		{
		 putpixel(421+random(210),301+random(15),random(13));
		 putpixel(421+random(15),301+random(150),random(13));
		 putpixel(421+random(210),435+random(15),random(13));
		 putpixel(615+random(15),301+random(150),random(13));
		}

	     bar(435,315,615,435);




	     setcolor(GREEN);
			 // either player 2 or computer is displayed
	     if(flag==1 ||flag==2)                    //for count status
	       outtextxy(430,165,Name2);
	     gotoxy(74,12);cout<<Gcount;
	     outtextxy(560,135,":");
	     outtextxy(560,165,":");

	   check.Play2(flag) ;          //function call gets transferred to play2()
				  //which is in Play.CPP
	}
}
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
