  void Exitnext()
  {
    /* request auto detection */
    int gdriver = DETECT, gmode, errorcode;
    int maxx, maxy;

    /* initialize graphics, local variables
*/
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

    /* read result of initialization */
    errorcode = graphresult();
    if (errorcode != grOk)
    /* an error occurred */
    {
       printf("Graphics error: %s\n", grapherrormsg(errorcode));
       printf("Press any key to halt:");
       getch();
       exit(1);
       /* terminate with an error code */
    }

    maxx = getmaxx();
    maxy = getmaxy();

    /* select drawing color */
    setcolor(getmaxcolor());

    /* select fill color */
    setfillstyle(SOLID_FILL,6); //getmaxcolor());

    /* draw a border around the screen */
    rectangle(0, 0, maxx, maxy);
 //  circle(maxx/3, maxy/2, 50);
   circle(maxx /2, 20, 100);

    rectangle(maxx/2-120,maxy/2-30,430,300);
  //  circle(maxx-20, maxy-50, 75);
  // circle(20, maxy-20, 25);

    getch();
    settextstyle(1,0,5);

    /* fill in bounded region */

    floodfill(2, 2,getmaxcolor());
    sound(2000);
    delay(100);
    nosound();
       outtextxy(200,225,"THANK YOU");
       for(int i=0; i<153;i++)
       {
	  setcolor(RED);
	  if(i<100)
	  circle(maxx / 2, 20, i);
	  setcolor(WHITE);
      //  linerel(200+i,100-i);
      // /**/ circle(maxx+30-i, maxy-i, 5+i);
	// circle(20, maxy-10, 25);
	// circle(maxx+10-i, maxy-i, 30);
	 delay(10);
	 linerel(200+i,100-i);
	 delay(10);
	 linerel(200+i,133-i);

	  circle(maxx / 2, 20, 100);

      //*/*  circle(maxx+30-i, maxy-i, 5+i);
	// circle(20, maxy-i, 25);
	// circle(maxx+10-i, maxy-i, 30);
       }

getch();
 {
    int gd= DETECT, gm;
  initgraph(&gd,&gm, "C:\\TC\\BGI  ");
  struct palettetype pal;

  getpalette(&pal);

/* create gray scale */
for (int i=0; i<pal.size; i++)
   setrgbpalette(pal.colors[i], i*3, i*2, i*4);
settextstyle(3,0,4);

for(i=0;i< pal.size ;i++)
{setcolor(i);
outtextxy(100+i,100,"COPY RIGHTS RESERVED");
}
getch();



    setfillstyle(SOLID_FILL,3);
    circle(maxx/10,maxy/10,20);
    setfillstyle(SOLID_FILL,10);
    fillellipse(maxx/10, maxy/10,20,20);
    circle(maxx/10,maxy/10+50,30);
    setfillstyle(SOLID_FILL,14);
     fillellipse(maxx/10,maxy/10+50,30,30);

    setfillstyle(SOLID_FILL,0);
    circle(maxx/10-7,maxy/10-5,4);
     fillellipse(maxx/10-7,maxy/10-5,4,4);
    circle(maxx/10+7,maxy/10-5,4);
    fillellipse(maxx/10+7, maxy/10-5,4,4);
}
    getch();
    closegraph();
 }
