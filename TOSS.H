void Tossresult(int flag)
{
int r=0;
 while(r<(getmaxy()/2))
  {
    setcolor(RED);
    line(0,getmaxy()/2-1-r,getmaxx(),getmaxy()/2-1-r);
    line(0,getmaxy()/2-2-r,getmaxx(),getmaxy()/2-2-r);
    line(0,getmaxy()/2-3-r,getmaxx(),getmaxy()/2-3-r);
    line(0,getmaxy()/2-4-r,getmaxx(),getmaxy()/2-4-r);
    setcolor(BLACK);
    line(0,getmaxy()/2-r,getmaxx(),getmaxy()/2-r);

    setcolor(RED);
    line(0,getmaxy()/2+1+r,getmaxx(),getmaxy()/2+1+r);
    line(0,getmaxy()/2+2+r,getmaxx(),getmaxy()/2+2+r);
    line(0,getmaxy()/2+3+r,getmaxx(),getmaxy()/2+3+r);
    line(0,getmaxy()/2+4+r,getmaxx(),getmaxy()/2+4+r);
    setcolor(BLACK);
    line(0,getmaxy()/2+r,getmaxx(),getmaxy()/2+r);


    r++;

  }
  setfillstyle(SOLID_FILL,RED);
  bar(0,0,getmaxx(),10);
  bar(0,getmaxy()-10,getmaxx(),getmaxy());

  setcolor(WHITE);

  if(turn==Comp || turn==Green)
    outtextxy(200,getmaxy()/2-20,Name2);
  else
    outtextxy(200,getmaxy()/2-20,Name1);

  outtextxy(300,getmaxy()/2-20," WON THE TOSS ");


   getch();


   for(float p=0;p<40000;p++)
   putpixel(200+random(280),220+random(30),BLACK);


   Board(flag);
 }