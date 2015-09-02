void Page2()
{
  cleardevice();
  setbkcolor(BLACK);                                        //PAGE 2
  settextstyle(4,0,7);
  setcolor(WHITE);
  outtextxy(0,125,"DEVELOPED BY");
  delay(500);
  settextstyle(6,0,7);
  for(int i=0;i<525; i++)
  {
   setcolor(CYAN);
   outtextxy(i,185, "!");
   delay(2);
  }
  delay(500);
  setcolor(WHITE);
  settextstyle(4,0,7);
  outtextxy(0,260,"KIRAN && ");
  outtextxy(340,330,"PRATHIK ");
  getch();
  getch();




}  //end of page2()


