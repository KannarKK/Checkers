void Page1()
{cleardevice();
int pal=1,flag=0;
while(!kbhit())
{
 for(int y=0;y<500;y++)
 {
	for(int x=0;x<300;x++)
	{
	   if(flag==0)
	     {
	       putpixel( random(y+100),random(y+100), YELLOW);
	       putpixel( getmaxx()-random(100+y),getmaxy()-random(100+y), RED);
	       putpixel( getmaxx()-random(100+y),random(y+100), GREEN);
	       putpixel( random(y+100),getmaxy()-random(y+100), BLUE);

	     }
	   else
	     {
	       putpixel( random(y+x),random(y+x), YELLOW);
	       putpixel( getmaxx()-random(y+x),getmaxy()-random(y+x), RED);
	       putpixel( getmaxx()-random(y+x),random(y+x), GREEN);
	       putpixel( random(y+x),getmaxy()-random(y+x), BLUE);
	     }
	}
 }


  flag=1;
  setbkcolor(BLACK);
  pal++;
  setcolor(pal);

 {
		  //PAGE 1
  setfillstyle(SOLID_FILL,BLACK);
  bar(154,144,467,300);
  settextstyle(4,0,4);
  outtextxy(160,170," KP PRODUCTION ");
  outtextxy(190,230,"   PRESENTS ");
  }




 { for(int i=155;i<460; i+=10)
  {

   outtextxy(i,123, "-");
   delay(20);
  }
 for( i=135;i<275; i+=10)
 {
  outtextxy(455,i, "$");
  delay(20);
 }
 for( i=455;i>153; i-=10)
 {
  outtextxy(i,275, "-");
  delay(20);
 }
  for( i=265;i>132; i-=10)
  {
   outtextxy(154,i, "$");
   delay(20);
   }
  }
 }
//getch();
} //end of page1()

