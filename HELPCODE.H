void help1();
void help2();

void help()               // Intruction manual for the game:
{
 clrscr();
 cleardevice();
 // bar3d(5,20,600,600,20,0);
 setbkcolor(BLUE);
 outtextxy(200,6,"CHECKERS");
 fstream help;
 char ch;
 help.open("h:\\kk12\\HELP.txt",ios::in|ios::binary);

 help.get(ch);
 while(!help.eof())
   {

     cout<<ch;
     help.get(ch);
     delay(1);
   } //end of while

    bar(400,400,440,440);
    bar(500,400,540,440);
    mouse.initmouse();
    int button,m,n;

   while(1)
   {

     mouse.showmouseptr();
     mouse.getmousepos(&button,&m,&n);
     if(m>400&&m<440&&n>400&&n<440)
      {
       setcolor(WHITE);
       outtextxy(400,400,"BACK");
      }
    else
     { setcolor(BLUE);
      outtextxy(400,400,"BACK");
     }

    if(m>500&&m<540&&n>400&&n<440)
     {
      setcolor(WHITE);
      outtextxy(500,400,"NEXT");
     }
    else
     { setcolor(BLUE);
       outtextxy(500,400,"NEXT");
     }
    if(button &1== 1)
    {
      if(m>400&&m<440&&n>400&&n<440)
       { mouse.hidemouseptr();
	 cleardevice();
	 Page3();
       }
       if(m>500&&m<540&&n>400&&n<440)
       { mouse.hidemouseptr();
	 cleardevice();
	 help1();
	 }
    }
   } //end of while

 } //end of help()

//next page
void help1()
 {
 clrscr();
 cleardevice();
 setbkcolor(BROWN);
 setcolor(MAGENTA);
 outtextxy(200,6,"CHECKERS");
 fstream helpme;
 char ch;
 helpme.open("H:\\kk12\\HELP1.txt",ios::in|ios::binary);

 helpme.get(ch);
 while(!helpme.eof())
   {
     cout<<ch;
     helpme.get(ch);
     delay(1);
   }
  bar(400,400,440,440);
    bar(500,400,540,440);
    mouse.initmouse();
    int button,m,n;
   while(1)
   {
     mouse.showmouseptr();
     mouse.getmousepos(&button,&m,&n);
     if(m>400&&m<440&&n>400&&n<440)
      {
       setcolor(WHITE);
       outtextxy(400,400,"BACK");
      }
    else
     { setcolor(BLUE);
      outtextxy(400,400,"BACK");
     }

    if(m>500&&m<540&&n>400&&n<440)
     {
      setcolor(WHITE);
      outtextxy(500,400,"NEXT");
     }
    else
     { setcolor(BLUE);
       outtextxy(500,400,"NEXT");
     }
    if(button &1== 1)
    {
      if(m>400&&m<440&&n>400&&n<440)
       { mouse.hidemouseptr();
	 cleardevice();
	 help();
       }
       if(m>500&&m<540&&n>400&&n<440)
       { mouse.hidemouseptr();
	 cleardevice();
	 help2();
	 }
     }
  } //end of while
 } //end of help1()

 void help2()               // Intruction manual for the game:
{
 clrscr();
 cleardevice();
 setbkcolor(BLACK);
 settextstyle(1,0,4);
 outtextxy(200,6,"CHECKERS");
 fstream help;
 char ch;
 help.open("H:\\kk12\\HELP2.txt",ios::in|ios::binary);

 help.get(ch);
 while(!help.eof())
   {

     cout<<ch;
     help.get(ch);
     delay(1);
   } //end of while
 bar(400,400,440,440);
    bar(500,400,540,440);
    mouse.initmouse();
    int button,m,n;
     settextjustify(100,10);
      settextstyle(1,0,1);
   while(1)
   {
     mouse.showmouseptr();
     mouse.getmousepos(&button,&m,&n);
     if(m>400&&m<440&&n>400&&n<440)
      {
       setcolor(WHITE);

       outtextxy(400,400,"BACK");
      }
    else
     { setcolor(BLUE);
      outtextxy(400,400,"BACK");
     }

    if(m>500&&m<540&&n>400&&n<440)
     {
      setcolor(WHITE);
      outtextxy(500,400,"NEXT");
     }
    else
     { setcolor(BLUE);
       outtextxy(500,400,"NEXT");
     }
    if(button &1== 1)
    {
      if(m>400&&m<440&&n>400&&n<440)
       { mouse.hidemouseptr();
	 cleardevice();
	 help1();
       }
       if(m>500&&m<540&&n>400&&n<440)
       { mouse.hidemouseptr();

	 Page3();
	 help2();
	 }
     }
  } //end of while

 }