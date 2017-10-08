#include < stdio.h >
	#include < conio.h >
	#include < dos.h >
	#include < graphics.h >
	#include < iostream.h >
	//#include < stdlib.h >

// ***  declaration of select class  *** //
	class select
	{
		
			public:
			char name[20];
			void getname();
			void difflevel();
	};
// ***  declaration of level class  *** //
	class level
	{
		
			public:
			int d;
			int x, y;
			int j; // width
			int k; // height
			int l, t, r, b;
			//void easy_level();
			void mid_level();
			void diff_level();
	};
// ***  declaration of win class  *** //
	class win
	{
		
			public:
			int d;
			int x, y;
			int j; // width
			int k; // height
			int l, t, r, b;
			//void won_easy();
			void won_mid();
			void won_diff();
			void tune();
	};
// ***  declaration of check class  *** //
	class check
	{
		public:
		void voilate();
	};
	
	
// ***  declaration of main function starts here  *** //
	void main() 
	{
		clrscr();
		int gd, gm;
		detectgraph( & gd, & gm);
		initgraph( & gd, & gm, "C:\\TC\\BGI"); // initializing graphics
		
		// ***  front page code starts here   *** //
		setcolor(BLUE);
		rectangle(5, 5, 630, 475);
		setcolor(RED);
		rectangle(10, 10, 625, 470);
		setcolor(RED);
		settextstyle(4, 0, 6);
		char a[] = {"MAZE RUNNER"};
		outtextxy(120, 170, a);
		settextstyle(0, 0, 0);
		outtextxy(230, 20, "LETS SEE HOW TRICKY YOU ARE");
		setcolor(RED);
		rectangle(225, 350, 426, 370);
		int i = 0;
		while (i < 200)
		{
			sound(8 + i * 50);
			setcolor(BLUE);
			line(226 + i, 351, 226 + i, 369);
			setcolor(GREEN);
			outtextxy(295, 375, "LOADING...");
			delay(10);
			i++;
		}
		nosound();
		
		while (!kbhit()) 
		{
			nosound();
			sound(100);
			setcolor(RED);
			outtextxy(257, 307, "CLICK  TO CONTINUE");
			rectangle(250, 300, 410, 320);
			delay(200);
			nosound();
			sound(150);
			setcolor(BLUE);
			outtextxy(257, 307, "CLICK  TO CONTINUE");
			rectangle(250, 300, 410, 320);
			delay(200);
		}
		nosound();
		
		select sel;		// creating object of select class
		level lvl;		// creating object of level class

		if (getch() != 0) 
		{
			cleardevice();
			sel.getname();
			
			cleardevice();
			sel.difflevel();
			char level;
			level = getch();
			
			if (level == '1') 
			{
				cleardevice();
				//lvl.easy_level();
			} 
			else if (level == '2') 
			{
				cleardevice();
				lvl.mid_level();
			} 
			else if (level == '3') 
			{
				cleardevice();
				lvl.diff_level();
			}

		}
		getch();
	}
// ***  declaration of main function ends here  *** //

	void select::getname() 
	{
		
		setcolor(BLUE);
		rectangle(200, 180, 450, 280);
		outtextxy(265, 200, "ENTER YOUR NAME");
		rectangle(220, 220, 430, 240);
		rectangle(310, 250, 340, 270);
		outtextxy(317, 257, "OK");
		delay(200);
		gotoxy(32, 15);
		cin>>name;
	}
	void select::difflevel() 
	{
		settextstyle(0, 0, 0);
		outtextxy(210, 130, "ENTER THE DIFFICULTY LEVEL");
		rectangle(250, 140, 380, 300);
		rectangle(253, 153, 377, 183);
		rectangle(253, 203, 377, 233);
		rectangle(253, 253, 377, 283);
		setcolor(RED);
		outtextxy(285, 165, "BEGINEER");
		outtextxy(268, 215, "INTERMEDIATE");
		outtextxy(300, 265, "HARD");
		
		setcolor(WHITE);
		rectangle(100,350,520,450);
		outtextxy(210,360,"move up      : w");
		outtextxy(210,380,"move down    : s");
		outtextxy(210,400,"move left    : a");
		outtextxy(210,420,"move right   : d");
		outtextxy(210,440,"exit anytime : 00");
	}
	/*
	void level::easy_level() 
	{
		select sel1;
		win w;
		check chk;
		setcolor(WHITE);
		
		outtextxy(300, 10, "LEVEL 1");
		
		//outtextxy(10,10,sel1.name);
		setcolor(RED);
		int d = 30;
		int x = 0, y = 0;
		int j = 40; // width
		int k = 40; // height
		int l, t, r, b;
		l = (615 - 10 * j) / 2;
		t = (460 - 8 * k) / 2;
		r = (615 - 10 * j) / 2 + 10 * j;
		b = (460 - 8 * k) / 2 + 8 * k;
		rectangle(l, t, r, b);
		line(l + 1 * j, t + 1 * k, l + 9 * j, t + 1 * k); delay(d);
		line(l + 2 * j, t + 2 * k, l + 3 * j, t + 2 * k); delay(d);
		line(l + 4 * j, t + 2 * k, l + 5 * j, t + 2 * k);delay(d);
		line(l + 7 * j, t + 2 * k, l + 9 * j, t + 2 * k);delay(d);
		line(l + 3 * j, t + 3 * k, l + 4 * j, t + 3 * k);delay(d);
		line(l + 6 * j, t + 3 * k, l + 7 * j, t + 3 * k);delay(d);
		line(l + 8 * j, t + 3 * k, l + 9 * j, t + 3 * k);delay(d);
		line(l + 4 * j, t + 4 * k, l + 8 * j, t + 4 * k);delay(d);
		line(l + 9 * j, t + 4 * k, l + 10 * j, t + 4 * k);delay(d);
		line(l + 5 * j, t + 5 * k, l + 6 * j, t + 5 * k); delay(d);
		line(l + 8 * j, t + 5 * k, l + 9 * j, t + 5 * k); delay(d);
		line(l + 1 * j, t + 6 * k, l + 2 * j, t + 6 * k); delay(d);
		line(l + 3 * j, t + 6 * k, l + 4 * j, t + 6 * k); delay(d);
		line(l + 5 * j, t + 6 * k, l + 9 * j, t + 6 * k); delay(d);
		line(l + 0 * j, t + 7 * k, l + 6 * j, t + 7 * k); delay(d);
		line(l + 7 * j, t + 7 * k, l + 8 * j, t + 7 * k); delay(d);
		line(l + 1 * j, t + 1 * k, l + 1 * j, t + 6 * k); delay(d);
		line(l + 2 * j, t + 3 * k, l + 2 * j, t + 6 * k); delay(d);delay(d);
		line(l + 3 * j, t + 2 * k, l + 3 * j, t + 6 * k);
		line(l + 4 * j, t + 4 * k, l + 4 * j, t + 5 * k); delay(d);
		line(l + 4 * j, t + 6 * k, l + 4 * j, t + 7 * k); delay(d);
		line(l + 5 * j, t + 2 * k, l + 5 * j, t + 4 * k); delay(d);
		line(l + 5 * j, t + 5 * k, l + 5 * j, t + 6 * k); delay(d);
		line(l + 6 * j, t + 1 * k, l + 6 * j, t + 3 * k); delay(d);
		line(l + 7 * j, t + 4 * k, l + 7 * j, t + 8 * k); delay(d);
		line(l + 8 * j, t + 2 * k, l + 8 * j, t + 4 * k); delay(d);
		line(l + 9 * j, t + 5 * k, l + 9 * j, t + 7 * k); delay(d);
		setcolor(GREEN);
		line(l + 0 * j, t + 7 * k, l + 0 * j, t+ 8 * k);
		
	//ball blinking code starts from here
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		delay(100);
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		 sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		delay(100);
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		 sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		delay(100);
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		 sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		delay(100);
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		 sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
	//ball blinking code ends here
		char play = 'g';
		while (play != '0') {
		if (play == 'a') {
			
		if(((l+x)==l) &&  ((t+y)>=(t+7*k-6)&&(t+y)<(t+8*k)))
		{
			setcolor(GREEN);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			sound(300);
			delay(100);
			nosound();
			setcolor(YELLOW);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			delay(100);
			setcolor(GREEN);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			sound(300);
			delay(100);
			nosound();
			setcolor(YELLOW);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			delay(100);
			setcolor(GREEN);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			sound(300);
			delay(100);
			nosound();
			setcolor(YELLOW);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			delay(100);
			setcolor(GREEN);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			sound(300);
			delay(100);
			nosound();
			setcolor(YELLOW);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			delay(100);
			setcolor(GREEN);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			sound(300);
			delay(100);
			nosound();
			setcolor(YELLOW);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		
			w.won_easy();   // calling of win function
			break;
		}
		else if((l+x)==l)
		{
			chk.voilate();
		}
		else if(((l+x)==(l+1*j))&&  (    (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  6*k)     ))
		{
			chk.voilate();
		}
		else if(((l+x)==(l+2*j))&&  (    (t+y+k-6)>=(t+  3*k)&&(t+y)<(t+  6*k)     ))
		{
			chk.voilate();
		}
		else if(((l+x)==(l+3*j))&&  (    (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  6*k)     ))
		{
			chk.voilate();
		}
		else if(((l+x)==(l+4*j))&&  (    (t+y+k-6)>=(t+  4*k)&&(t+y)<(t+  5*k)  ||   (t+y+k-6)>=(t+  6*k)&&(t+y)<(t+  7*k)   ))
		{
			chk.voilate();
		}
		else if(((l+x)==(l+5*j))&&  (    (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  4*k)  ||   (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  6*k)   ))
		{
			chk.voilate();
		}
		else if(((l+x)==(l+6*j))&&  (    (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  3*k)     ))
		{
			chk.voilate();
		}
		else if(((l+x)==(l+7*j))&&  (    (t+y+k-6)>=(t+  4*k)&&(t+y)<(t+  8*k)     ))
		{
			chk.voilate();
		}
		else if(((l+x)==(l+8*j))&&  (    (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  4*k)     ))
		{
			chk.voilate();
		}
		else if(((l+x)==(l+9*j))&&  (    (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  7*k)     ))
		{
			chk.voilate();
		}	
		
		else
		{
			setcolor(BLACK);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			x = x - 5;
			setcolor(YELLOW);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		}
		}
		if (play == 'd') {
		if((l+j+x)==l+10*j)
		{
			chk.voilate();
		}
		else if(((l+x+k)==(l+1*j))&&  (    (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  6*k)     ))
		{
			chk.voilate();
		}
		else if(((l+x+k)==(l+2*j))&&  (    (t+y+k-6)>=(t+  3*k)&&(t+y)<(t+  6*k)     ))
		{
			chk.voilate();
		}
		else if(((l+x+k)==(l+3*j))&&  (    (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  6*k)     ))
		{
			chk.voilate();
		}
		else if(((l+x+k)==(l+4*j))&&  (    (t+y+k-6)>=(t+  4*k)&&(t+y)<(t+  5*k)  ||   (t+y+k-6)>=(t+  6*k)&&(t+y)<(t+  7*k)   ))
		{
			chk.voilate();
		}
		else if(((l+x+k)==(l+5*j))&&  (    (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  4*k)  ||   (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  6*k)   ))
		{
			chk.voilate();
		}
		else if(((l+x+k)==(l+6*j))&&  (    (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  3*k)     ))
		{
			chk.voilate();
		}
		else if(((l+x+k)==(l+7*j))&&  (    (t+y+k-6)>=(t+  4*k)&&(t+y)<(t+  8*k)     ))
		{
			chk.voilate();
		}
		else if(((l+x+k)==(l+8*j))&&  (    (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  4*k)     ))
		{
			chk.voilate();
		}
		else if(((l+x+k)==(l+9*j))&&  (    (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  7*k)     ))
		{
			chk.voilate();
		}	
		
	  //else if(((l+x+k)==(l+*j))&&  (    (t+y+k-6)>=(t+  *k)&&(t+y)<(t+  *k)     ))
		
		else
		{
			setcolor(BLACK);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			x = x + 5;
			setcolor(YELLOW);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		}
		}
		if (play == 'w') {
			if((t+y)==(t))
			{
				chk.voilate();
			}
		else if(  ((t+y)==(t+1*k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+  9*j)    ))
		{
				chk.voilate();
		}
		else if(  ((t+y)==(t+2*k)) &&   (    (l+x)>=(l+  2*j-6)&&(l+x)<(l+  3*j)  ||  (l+x)>=(l+  4*j-6)&&(l+x)<(l+  5*j)   ||  (l+x)>=(l+  7*j-6)&&(l+x)<(l+  9*j)   ))
		{
				chk.voilate();
		}
		else if(  ((t+y)==(t+3*k)) &&   (    (l+x)>=(l+  3*j-6)&&(l+x)<(l+  4*j)  ||  (l+x)>=(l+   6*j-6)&&(l+x)<(l+  7*j)  ||  (l+x)>=(l+  8*j-6)&&(l+x)<(l+  9*j)   ))
		{
				chk.voilate();
		}
		else if(  ((t+y)==(t+4*k)) &&   (    (l+x)>=(l+  4*j-6)&&(l+x)<(l+  8*j)  ||  (l+x)>=(l+  9*j-6)&&(l+x)<(l+  10*j)   ))
		{
				chk.voilate();
		}
		else if(  ((t+y)==(t+5*k)) &&   (    (l+x)>=(l+  5*j-6)&&(l+x)<(l+  6*j)  ||  (l+x)>=(l+  8*j-6)&&(l+x)<(l+  9*j)   ))
		{
				chk.voilate();
		}
		else if(  ((t+y)==(t+6*k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+  2*j)  ||  (l+x)>=(l+  3*j-6)&&(l+x)<(l+  4*j)   ||  (l+x)>=(l+  5*j-6)&&(l+x)<(l+  9*j)   ))
		{
				chk.voilate();
		}
		else if(  ((t+y)==(t+7*k)) &&   (    (l+x)>=(l+  0*j-6)&&(l+x)<(l+  6*j)  ||  (l+x)>=(l+  7*j-6)&&(l+x)<(l+  8*j)  ))
		{
				chk.voilate();
		}
			else
			{
			setcolor(BLACK);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			y = y - 5;
			setcolor(YELLOW);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			}
		}
		if (play == 's') {
		if((t+y+j)==(t+8*k))
			{
				chk.voilate();
			}
		else if(  ((t+y+j)==(t+1*k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+  9*j)    ))
		{
				chk.voilate();
		}
		else if(  ((t+y+j)==(t+2*k)) &&   (    (l+x)>=(l+  2*j-6)&&(l+x)<(l+  3*j)  ||  (l+x)>=(l+  4*j-6)&&(l+x)<(l+  5*j)   ||  (l+x)>=(l+  7*j-6)&&(l+x)<(l+  9*j)   ))
		{
				chk.voilate();
		}
		else if(  ((t+y+j)==(t+3*k)) &&   (    (l+x)>=(l+  3*j-6)&&(l+x)<(l+  4*j)  ||  (l+x)>=(l+   6*j-6)&&(l+x)<(l+  7*j)  ||  (l+x)>=(l+  8*j-6)&&(l+x)<(l+  9*j)   ))
		{
				chk.voilate();
		}
		else if(  ((t+y+j)==(t+4*k)) &&   (    (l+x)>=(l+  4*j-6)&&(l+x)<(l+  8*j)  ||  (l+x)>=(l+  9*j-6)&&(l+x)<(l+  10*j)   ))
		{
				chk.voilate();
		}
		else if(  ((t+y+j)==(t+5*k)) &&   (    (l+x)>=(l+  5*j-6)&&(l+x)<(l+  6*j)  ||  (l+x)>=(l+  8*j-6)&&(l+x)<(l+  9*j)   ))
		{
				chk.voilate();
		}
		else if(  ((t+y+j)==(t+6*k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+  2*j)  ||  (l+x)>=(l+  3*j-6)&&(l+x)<(l+  4*j)   ||  (l+x)>=(l+  5*j-6)&&(l+x)<(l+  9*j)   ))
		{
				chk.voilate();
		}
		else if(  ((t+y+j)==(t+7*k)) &&   (    (l+x)>=(l+  0*j-6)&&(l+x)<(l+  6*j)  ||  (l+x)>=(l+  7*j-6)&&(l+x)<(l+  8*j)  ))
		{
				chk.voilate();
		}
		else	
		{  
			setcolor(BLACK);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			y = y + 5;
			setcolor(YELLOW);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		}
		}
		play = getch();
		}
	}
	*/
	
	void level::mid_level() 
	{
		win w;
		check chk;
		x = 0, y = 0;
		setcolor(WHITE);
		outtextxy(300, 10, "LEVEL 2");
		setcolor(RED);
		j = 40; // width     keep j & k equal or change the boundary matching codes for error free running
		k = 40; // height
		l, t, r, b;
		l = (615 - 15 * j) / 2;
		t = (460 - 8 * k) / 2;
		r = (615 - 15 * j) / 2 + 15 * j;
		b = (460 - 8 * k) / 2 + 8 * k;
		
		rectangle(l, t, r, b);

		setcolor(BLUE);
		line(l, t + 1, l, t + k);
		setcolor(RED);

		line(l, t + 1 * k, l + 3 * j, t + 1 * k);
		delay(50);
		line(l + 4 * j, t, l + 4 * j, t + 2 * k);
		delay(50);
		line(l + 4 * j, t + k, l + 5 * j, t + k);
		delay(50);
		line(l + 4 * j, t + 2 * k, l + j, t + 2 * k);
		delay(50);
		line(l + 3 * j, t + 2 * k, l + 3 * j, t + 7 * k);
		delay(50);
		line(l + j, t + 7 * k, l + 3 * j, t + 7 * k);
		delay(50);
		line(l, t + 3 * k, l + 2 * j, t + 3 * k);
		delay(50);
		line(l + 2 * j, t + 3 * k, l + 2 * j, t + 4 * k);
		delay(50);
		line(l + j, t + 4 * k, l + 2 * j, t + 4 * k);
		delay(50);
		line(l + j, t + 4 * k, l + j, t + 6 * k);
		delay(50);
		line(l + j, t + 6 * k, l + 2 * j, t + 6 * k);
		delay(50);
		line(l + 3 * j, t + 4 * k, l + 4 * j, t + 4 * k);
		delay(50);
		line(l + 3 * j, t + 6 * k, l + 4 * j, t + 6 * k);
		delay(50);
		line(l + 2 * j, t + 5 * k, l + 3 * j, t + 5 * k);
		delay(50);
		line(l + 6 * j, t + k, l + 6 * j, t + 2 * k);
		delay(50);
		line(l + 5 * j, t + 2 * k, l + 6 * j, t + 2 * k);
		delay(50);
		line(l + 5 * j, t + 2 * k, l + 5 * j, t + 7 * k);
		delay(50);
		line(l + 4 * j, t + 7 * k, l + 5 * j, t + 7 * k);
		delay(50);
		line(l + 4 * j, t + 7 * k, l + 4 * j, t + 8 * k);
		delay(50);
		line(l + 4 * j, t + 3 * k, l + 5 * j, t + 3 * k);
		delay(50);
		line(l + 5 * j, t + 4 * k, l + 7 * j, t + 4 * k);
		delay(50);
		line(l + 4 * j, t + 5 * k, l + 5 * j, t + 5 * k);
		delay(50);

		line(l + 7 * j, t, l + 7 * j, t + 3 * k);
		delay(50);
		line(l + 6 * j, t + 3 * k, l + 8 * j, t + 3 * k);
		delay(50);
		line(l + 8 * j, t + 2 * k, l + 8 * j, t + 5 * k);
		delay(50);
		line(l + 6 * j, t + 5 * k, l + 10 * j, t + 5 * k);
		delay(50);
		line(l + 6 * j, t + 5 * k, l + 6 * j, t + 7 * k);
		delay(50);
		line(l + 6 * j, t + 7 * k, l + 7 * j, t + 7 * k);
		delay(50);
		line(l + 7 * j, t + 7 * k, l + 7 * j, t + 6 * k);
		delay(50);
		line(l + 9 * j, t + 5 * k, l + 9 * j, t + 6 * k);
		delay(50);
		line(l + 10 * j, t + 5 * k, l + 10 * j, t + 4 * k);
		delay(50);
		line(l + 10 * j, t + 4 * k, l + 11 * j, t + 4 * k);
		delay(50);

		line(l + 8 * j, t + k, l + 10 * j, t + k);
		delay(50);
		line(l + 9 * j, t + k, l + 9 * j, t + 4 * k);
		delay(50);
		line(l + 10 * j, t + k, l + 10 * j, t + 2 * k);
		delay(50);
		line(l + 9 * j, t + 3 * k, l + 12 * j, t + 3 * k);
		delay(50);
		line(l + 12 * j, t + k, l + 12 * j, t + 5 * k);
		delay(50);
		line(l + 12 * j, t + 5 * k, l + 11 * j, t + 5 * k);
		delay(50);
		line(l + 11 * j, t + 5 * k, l + 11 * j, t + 6 * k);
		delay(50);
		line(l + 11 * j, t + 6 * k, l + 10 * j, t + 6 * k);
		delay(50);
		line(l + 10 * j, t + 6 * k, l + 10 * j, t + 7 * k);
		delay(50);
		line(l + 10 * j, t + 7 * k, l + 8 * j, t + 7 * k);
		delay(50);
		line(l + 8 * j, t + 6 * k, l + 8 * j, t + 8 * k);
		delay(50);

		line(l + 11 * j, t, l + 11 * j, t + 2 * k);
		delay(50);

		line(l + 13 * j, t, l + 13 * j, t + k);
		delay(50);
		line(l + 13 * j, t + k, l + 14 * j, t + k);
		delay(50);

		line(l + 12 * j, t + 4 * k, l + 13 * j, t + 4 * k);
		delay(50);
		line(l + 13 * j, t + 4 * k, l + 13 * j, t + 3 * k);
		delay(50);

		line(l + 12 * j, t + 2 * k, l + 14 * j, t + 2 * k);
		delay(50);
		line(l + 14 * j, t + 2 * k, l + 14 * j, t + 5 * k);
		delay(50);
		line(l + 14 * j, t + 5 * k, l + 13 * j, t + 5 * k);
		delay(50);
		line(l + 13 * j, t + 5 * k, l + 13 * j, t + 7 * k);
		delay(50);
		line(l + 14 * j, t + 7 * k, l + 12 * j, t + 7 * k);
		delay(50);
		line(l + 12 * j, t + 7 * k, l + 12 * j, t + 6 * k);
		delay(50);

		line(l + 14 * j, t + 6 * k, l + 15 * j, t + 6 * k);
		delay(50);

		line(l + 11 * j, t + 7 * k, l + 11 * j, t + 8 * k);
		delay(50);

		setcolor(GREEN);
		line(l + 15 * j, t + 7 * k, l + 15 * j, t + 8 * k - 1);

		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		
	//ball blinking code starts from here
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		delay(100);
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		 sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		delay(100);
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		 sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		delay(100);
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		 sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		delay(100);
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		 sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
	//ball blinking code ends here

		char play = 'g';

		while (play != '0') {
		if (play == 'a') {
			if((l+x)==l)
			{
				chk.voilate();
			}
			else if(((l+x)==(l+j))&&  (    (t+y+k-6)>=(t+  4*k)&&(t+y)<(t+  6*k)     ))
			{
				chk.voilate();
			}
			
			else if(((l+x)==(l+2*j)) &&  (    (t+y+k-6)>=(t+  3*k)&&(t+y)<(t+  4*k)    ))
				
			{
				chk.voilate();
			}
			else if(((l+x)==(l+3*j)) && (      (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  7*k)  ))
			{
				chk.voilate();
			}
			else if(((l+x)==(l+4*j)) && (      (t+y+k-6)>=(t+  0*k)&&(t+y)<(t+  2*k)    ||   (t+y+k-6)>=(t+  7*k)&&(t+y)<(t+  8*k)      ))
			{
				chk.voilate();
			}
			else if(((l+x)==(l+5*j)) && (      (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  7*k)     ))
			{
				chk.voilate();
			}
			else if(((l+x)==(l+6*j)) && (      (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  2*k) ||   (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  7*k)       ))	
			{
				chk.voilate();
			}
			else if(((l+x)==(l+7*j)) && (      (t+y+k-6)>=(t+  0*k)&&(t+y)<(t+  3*k)  ||   (t+y+k-6)>=(t+  6*k)&&(t+y)<(t+  7*k)     ))				
			{
				chk.voilate();
			}
			else if(((l+x)==(l+8*j)) && (      (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  5*k)  ||    (t+y+k-6)>=(t+  6*k)&&(t+y)<(t+  8*k)    ))
			{
				chk.voilate();
			}
			else if(((l+x)==(l+9*j)) && (      (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  4*k)  ||    (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  6*k)   ))
			{
				chk.voilate();
			}
			else if(((l+x)==(l+10*j)) && (      (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  2*k) ||    (t+y+k-6)>=(t+  4*k)&&(t+y)<(t+  5*k)  ||    (t+y+k-6)>=(t+  6*k)&&(t+y)<(t+  7*k)     ))
			{
				chk.voilate();
			}
			else if(((l+x)==(l+11*j)) && (      (t+y+k-6)>=(t+  0*k)&&(t+y)<(t+  2*k) ||    (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  6*k)  ||    (t+y+k-6)>=(t+  7*k)&&(t+y)<(t+  8*k)     ))
			{
				chk.voilate();
			}
			else if(((l+x)==(l+12*j)) && (      (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  5*k) ||    (t+y+k-6)>=(t+  6*k)&&(t+y)<(t+  7*k)      ))
			{
				chk.voilate();
			}
			else if(((l+x)==(l+13*j)) && (      (t+y+k-6)>=(t+  0*k)&&(t+y)<(t+  1*k) ||    (t+y+k-6)>=(t+  3*k)&&(t+y)<(t+  4*k)  ||    (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  7*k)       ))
			{
				chk.voilate();
			}
			else if(((l+x)==(l+14*j)) && (      (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  5*k)     ))
			{
				chk.voilate();
			}
			else
			{
				setcolor(BLACK);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				x = x - 5;
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			}
		}
		if (play == 'd') {
			
			if(((l+x+k)==(l+15*k)) && (t+y)>=(t+7*k-6) && (t+y)<(t+8*k))
		       {

				setcolor(GREEN);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				sound(300);
				delay(100);
				nosound();
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				delay(100);
				setcolor(GREEN);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				sound(300);
				delay(100);
				nosound();
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				delay(100);
				setcolor(GREEN);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				sound(300);
				delay(100);
				nosound();
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				delay(100);
				setcolor(GREEN);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				sound(300);
				delay(100);
				nosound();
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				delay(100);
				setcolor(GREEN);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				sound(300);
				delay(100);
				nosound();
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);

				w.won_mid();
				}


		    else if((l+x+k)==(l+15*j))
			{
				chk.voilate();
			}
			else if(((l+x+k)==(l+j))&&  (    (t+y+k-6)>=(t+  4*k)&&(t+y)<(t+  6*k)     ))
			{
				chk.voilate();
			}
			
			else if(((l+x+k)==(l+2*j)) &&  (    (t+y+k-6)>=(t+  3*k)&&(t+y)<(t+  4*k)    ))
				
			{
				chk.voilate();
			}
			else if(((l+x+k)==(l+3*j)) && (      (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  7*k)  ))
			{
				chk.voilate();
			}
			else if(((l+x+k)==(l+4*j)) && (      (t+y+k-6)>=(t+  0*k)&&(t+y)<(t+  2*k)    ||   (t+y+k-6)>=(t+  7*k)&&(t+y)<(t+  8*k)      ))
			{
				chk.voilate();
			}
			else if(((l+x+k)==(l+5*j)) && (      (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  7*k)     ))
			{
				chk.voilate();
			}
			else if(((l+x+k)==(l+6*j)) && (      (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  2*k) ||   (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  7*k)       ))	
			{
				chk.voilate();
			}
			else if(((l+x+k)==(l+7*j)) && (      (t+y+k-6)>=(t+  0*k)&&(t+y)<(t+  3*k)  ||   (t+y+k-6)>=(t+  6*k)&&(t+y)<(t+  7*k)     ))				
			{
				chk.voilate();
			}
			else if(((l+x+k)==(l+8*j)) && (      (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  5*k)  ||    (t+y+k-6)>=(t+  6*k)&&(t+y)<(t+  8*k)    ))
			{
				chk.voilate();
			}
			else if(((l+x+k)==(l+9*j)) && (      (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  4*k)  ||    (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  6*k)   ))
			{
				chk.voilate();
			}
			else if(((l+x+k)==(l+10*j)) && (      (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  2*k) ||    (t+y+k-6)>=(t+  4*k)&&(t+y)<(t+  5*k)  ||    (t+y+k-6)>=(t+  6*k)&&(t+y)<(t+  7*k)     ))
			{
				chk.voilate();
			}
			else if(((l+x+k)==(l+11*j)) && (      (t+y+k-6)>=(t+  0*k)&&(t+y)<(t+  2*k) ||    (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  6*k)  ||    (t+y+k-6)>=(t+  7*k)&&(t+y)<(t+  8*k)     ))
			{
				chk.voilate();
			}
			else if(((l+x+k)==(l+12*j)) && (      (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  5*k) ||    (t+y+k-6)>=(t+  6*k)&&(t+y)<(t+  7*k)      ))
			{
				chk.voilate();
			}
			else if(((l+x+k)==(l+13*j)) && (      (t+y+k-6)>=(t+  0*k)&&(t+y)<(t+  1*k) ||    (t+y+k-6)>=(t+  3*k)&&(t+y)<(t+  4*k)  ||    (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  7*k)       ))
			{
				chk.voilate();
			}
			else if(((l+x+k)==(l+14*j)) && (      (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  5*k)     ))
			{
				chk.voilate();
			}
		//else if(((l+x+k)==(l+6*j)) && (      (t+y+k-6)>=(t+  *k)&&(t+y)<(t+  *k)     ))
			else
			{	
				setcolor(BLACK);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				x = x + 5;
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			}
		}
		if (play == 'w') {
			if((t+y)==(t))
			{
				chk.voilate();
			}
			else if(  ((t+y)==(t+1*k)) &&   (    (l+x)>=(l+  0*j-6)&&(l+x)<(l+  3*j)  ||   (l+x)>=(l+  4*j-6)&&(l+x)<(l+  5*j) ||   (l+x)>=(l+  8*j-6)&&(l+x)<(l+  10*j)  ||   (l+x)>=(l+  13*j-6)&&(l+x)<(l+  14*j)   ))
			{
				chk.voilate();
			}
			else if(  ((t+y)==(t+2*k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+  4*j)  ||   (l+x)>=(l+  5*j-6)&&(l+x)<(l+  6*j) ||   (l+x)>=(l+  12*j-6)&&(l+x)<(l+  14*j)  ))
			{
				chk.voilate();
			}
			else if(  ((t+y)==(t+3*k)) &&   (    (l+x)>=(l+  0*j-6)&&(l+x)<(l+  2*j)  ||   (l+x)>=(l+  4*j-6)&&(l+x)<(l+  5*j) ||   (l+x)>=(l+  6*j-6)&&(l+x)<(l+  8*j)   ||   (l+x)>=(l+  9*j-6)&&(l+x)<(l+  12*j) ))
			{
				chk.voilate();
			}
			else if(  ((t+y)==(t+4*k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+  2*j)  ||   (l+x)>=(l+  3*j-6)&&(l+x)<(l+  4*j) ||   (l+x)>=(l+  5*j-6)&&(l+x)<(l+  7*j)   ||   (l+x)>=(l+  10*j-6)&&(l+x)<(l+  11*j)  ||   (l+x)>=(l+  12*j-6)&&(l+x)<(l+  13*j)  ))
			{
				chk.voilate();
			}
			else if(  ((t+y)==(t+5*k)) &&   (    (l+x)>=(l+  2*j-6)&&(l+x)<(l+  3*j)  ||   (l+x)>=(l+  4*j-6)&&(l+x)<(l+  5*j) ||   (l+x)>=(l+  6*j-6)&&(l+x)<(l+  10*j)  ||   (l+x)>=(l+  11*j-6)&&(l+x)<(l+  12*j)  ||   (l+x)>=(l+  13*j-6)&&(l+x)<(l+  14*j) ))
			{
				chk.voilate();
			}
			else if(  ((t+y)==(t+6*k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+  2*j)  ||   (l+x)>=(l+  3*j-6)&&(l+x)<(l+  4*j) ||   (l+x)>=(l+  10*j-6)&&(l+x)<(l+  11*j) ||   (l+x)>=(l+  14*j-6)&&(l+x)<(l+  15*j) ))
			{
				chk.voilate();
			}
			else if(  ((t+y)==(t+7*k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+  3*j)  ||   (l+x)>=(l+  4*j-6)&&(l+x)<(l+  5*j) ||   (l+x)>=(l+   6*j-6)&&(l+x)<(l+  7*j)  ||   (l+x)>=(l+  8*j-6)&&(l+x)<(l+  10*j)   ||   (l+x)>=(l+  12*j-6)&&(l+x)<(l+  14*j) ))
			{
				chk.voilate();
			}
			else
			{
				setcolor(BLACK);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				y = y - 5;
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			}
		}

		if (play == 's') {
			if((t+y+j)==(t+8*k))
			{
				chk.voilate();
			}
			else if(  ((t+y+j)==(t+1*k)) &&   (    (l+x)>=(l+  0*j-6)&&(l+x)<(l+  3*j)  ||   (l+x)>=(l+  4*j-6)&&(l+x)<(l+  5*j) ||   (l+x)>=(l+  8*j-6)&&(l+x)<(l+  10*j)  ||   (l+x)>=(l+  13*j-6)&&(l+x)<(l+  14*j)   ))
			{
				chk.voilate();
			}
			else if(  ((t+y+j)==(t+2*k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+  4*j)  ||   (l+x)>=(l+  5*j-6)&&(l+x)<(l+  6*j) ||   (l+x)>=(l+  12*j-6)&&(l+x)<(l+  14*j)  ))
			{
				chk.voilate();
			}
			else if(  ((t+y+j)==(t+3*k)) &&   (    (l+x)>=(l+  0*j-6)&&(l+x)<(l+  2*j)  ||   (l+x)>=(l+  4*j-6)&&(l+x)<(l+  5*j) ||   (l+x)>=(l+  6*j-6)&&(l+x)<(l+  8*j)   ||   (l+x)>=(l+  9*j-6)&&(l+x)<(l+  12*j) ))
			{
				chk.voilate();
			}
			else if(  ((t+y+j)==(t+4*k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+  2*j)  ||   (l+x)>=(l+  3*j-6)&&(l+x)<(l+  4*j) ||   (l+x)>=(l+  5*j-6)&&(l+x)<(l+  7*j)   ||   (l+x)>=(l+  10*j-6)&&(l+x)<(l+  11*j)  ||   (l+x)>=(l+  12*j-6)&&(l+x)<(l+  13*j)  ))
			{
				chk.voilate();
			}
			else if(  ((t+y+j)==(t+5*k)) &&   (    (l+x)>=(l+  2*j-6)&&(l+x)<(l+  3*j)  ||   (l+x)>=(l+  4*j-6)&&(l+x)<(l+  5*j) ||   (l+x)>=(l+  6*j-6)&&(l+x)<(l+  10*j)  ||   (l+x)>=(l+  11*j-6)&&(l+x)<(l+  12*j)  ||   (l+x)>=(l+  13*j-6)&&(l+x)<(l+  14*j) ))
			{
				chk.voilate();
			}
			else if(  ((t+y+j)==(t+6*k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+  2*j)  ||   (l+x)>=(l+  3*j-6)&&(l+x)<(l+  4*j) ||   (l+x)>=(l+  10*j-6)&&(l+x)<(l+  11*j) ||   (l+x)>=(l+  14*j-6)&&(l+x)<(l+  15*j) ))
			{
				chk.voilate();
			}
			else if(  ((t+y+j)==(t+7*k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+  3*j)  ||   (l+x)>=(l+  4*j-6)&&(l+x)<(l+  5*j) ||   (l+x)>=(l+   6*j-6)&&(l+x)<(l+  7*j)  ||   (l+x)>=(l+  8*j-6)&&(l+x)<(l+  10*j)   ||   (l+x)>=(l+  12*j-6)&&(l+x)<(l+  14*j) ))
			{
				chk.voilate();
			}
		  //else if(  ((t+y+j)==(t+*k)) &&   (    (l+x)>=(l+  *j-6)&&(l+x)<(l+  *j)     ))
			
			
			else
			{
				setcolor(BLACK);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				y = y + 5;
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			}
		}
		play = getch();
		}
	}
	
	void level::diff_level() 
	{
		win w;
		check chk;
		setcolor(WHITE);
		outtextxy(300, 10, "LEVEL 3");
		setcolor(RED);
		x = 0, y = 0;		
		d = 30;
		j = 25; // width
		k = 25; // height
		l, t, r, b;
		l = (615 - 16 * j) / 2;
		t = (460 - 16 * k) / 2;
		r = (615 - 16 * j) / 2 + 16 * j;
		b = (460 - 16 * k) / 2 + 16 * k;

		rectangle(l, t, r, b);
		delay(d);

		line(l + j, t + 14 * k, l + j, t + 16 * k);
		delay(d);
		line(l + 2 * j, t + 15 * k, l + 15 * j, t + 15 * k);
		delay(d);
		line(l + 2 * j, t + 13 * k, l + 2 * j, t + 15 * k);
		delay(d);
		line(l + j, t + 13 * k, l + 6 * j, t + 13 * k);
		delay(d);
		line(l + j, t + k, l + j, t + 13 * k);
		delay(d);
		line(l + 3 * j, t + 11 * k, l + 3 * j, t + 13 * k);
		delay(d);
		line(l + 4 * j, t + 12 * k, l + 4 * j, t + 13 * j);
		delay(d);
		line(l + 5 * j, t + 13 * k, l + 5 * j, t + 12 * k);
		delay(d);
		line(l + 5 * j, t + 12 * k, l + 6 * j, t + 12 * k);
		delay(d);
		line(l + 6 * j, t + 12 * k, l + 6 * j, t + 11 * k);
		delay(d);
		line(l + 5 * j, t + 10 * k, l + 5 * j, t + 11 * k);
		delay(d);
		line(l + 5 * j, t + 11 * k, l + 7 * j, t + 11 * k);
		delay(d);
		line(l + 7 * j, t + 11 * k, l + 7 * j, t + 10 * k);
		delay(d);
		line(l + 7 * j, t + 10 * k, l + 9 * j, t + 10 * k);
		delay(d);
		line(l + 9 * j, t + 7 * k, l + 9 * j, t + 11 * k);
		delay(d);
		line(l + 8 * j, t + 9 * k, l + 9 * j, t + 9 * k);
		delay(d);
		line(l + 9 * j, t + 11 * k, l + 11 * j, t + 11 * k);
		delay(d);
		line(l + 7 * j, t + 7 * k, l + 9 * j, t + 7 * k);
		delay(d);
		line(l + 7 * j, t + 7 * k, l + 7 * j, t + 9 * k);
		delay(d);
		line(l + j, t + 6 * k, l + 3 * j, t + 6 * k);
		delay(d);
		line(l + 2 * j, t + 6 * k, l + 2 * j, t + 7 * k);
		delay(d);
		line(l + 3 * j, t + 6 * k, l + 3 * j, t + 7 * k);
		delay(d);
		line(l + 3 * j, t + 7 * k, l + 5 * j, t + 7 * k);
		delay(d);
		line(l + 5 * j, t + 6 * k, l + 5 * j, t + 8 * k);
		delay(d);
		line(l + 4 * j, t + 7 * k, l + 4 * j, t + 8 * k);
		delay(d);
		line(l + 3 * j, t + 8 * k, l + 4 * j, t + 8 * k);
		delay(d);
		line(l + 3 * j, t + 8 * k, l + 3 * j, t + 9 * k);
		delay(d);
		line(l + j, t + 3 * k, l + 2 * j, t + 3 * k);
		delay(d);
		line(l + j, t + k, l + 14 * j, t + k);
		delay(d);
		line(l + 4 * j, t + k, l + 4 * j, t + 4 * k);
		delay(d);
		line(l + 4 * j, t + 4 * k, l + 5 * j, t + 4 * k);
		delay(d);
		line(l + 7 * j, t + k, l + 7 * j, t + 2 * k);
		delay(d);
		line(l + 7 * j, t + 2 * k, l + 8 * j, t + 2 * k);
		delay(d);
		line(l + 8 * j, t + 2 * k, l + 8 * j, t + 5 * k);
		delay(d);
		line(l + 7 * j, t + 5 * k, l + 9 * j, t + 5 * k);
		delay(d);
		line(l + 10 * j, t + k, l + 10 * j, t + 2 * k);
		delay(d);
		line(l + 10 * j, t + 2 * k, l + 11 * j, t + 2 * k);
		delay(d);
		line(l + 11 * j, t + 2 * k, l + 11 * j, t + 3 * k);
		delay(d);
		line(l + 11 * j, t + 3 * k, l + 12 * j, t + 3 * k);
		delay(d);

		line(l + 10 * j, t + 15 * k, l + 10 * j, t + 14 * k);
		delay(d);
		line(l + 9 * j, t + 14 * k, l + 10 * j, t + 14 * k);
		delay(d);
		line(l + 9 * j, t + 14 * k, l + 9 * j, t + 13 * k);
		delay(d);
		line(l + 8 * j, t + 13 * k, l + 9 * j, t + 13 * k);
		delay(d);
		line(l + 11 * j, t + 15 * k, l + 11 * j, t + 14 * k);
		delay(d);
		line(l + 13 * j, t + 15 * k, l + 13 * j, t + 14 * k);
		delay(d);
		line(l + 14 * j, t + 15 * k, l + 14 * j, t + 14 * k);
		delay(d);

		line(l + 15 * j, t + 15 * k, l + 15 * j, t + 5 * k);
		delay(d);
		line(l + 15 * j, t + 9 * k, l + 14 * j, t + 9 * k);
		delay(d);
		line(l + 14 * j, t + 9 * k, l + 14 * j, t + 10 * k);
		delay(d);
		line(l + 14 * j, t + 10 * k, l + 13 * j, t + 10 * k);
		delay(d);
		line(l + 13 * j, t + 10 * k, l + 13 * j, t + 9 * k);
		delay(d);
		line(l + 14 * j, t + 8 * k, l + 15 * k, t + 8 * k);
		delay(d);

		line(l + 15 * j, t + 6 * k, l + 12 * j, t + 6 * k);
		delay(d);
		line(l + 14 * j, t + 6 * k, l + 14 * j, t + 5 * k);
		delay(d);
		line(l + 12 * j, t + 5 * k, l + 12 * j, t + 7 * k);
		delay(d);
		line(l + 11 * j, t + 7 * k, l + 12 * k, t + 7 * k);
		delay(d);
		line(l + 11 * j, t + 7 * k, l + 11 * j, t + 9 * k);
		delay(d);

		line(l + 15 * j, t + k, l + 16 * j, t + k);
		delay(d);
		line(l + 13 * j, t + 3 * k, l + 15 * j, t + 3 * k);
		delay(d);
		line(l + 15 * j, t + 2 * k, l + 15 * j, t + 4 * k);
		delay(d);
		line(l + 14 * j, t + 2 * k, l + 14 * j, t + 3 * k);
		delay(d);
		line(l + 12 * j, t + 2 * k, l + 14 * j, t + 2 * k);
		delay(d);
		line(l + 13 * j, t + 3 * k, l + 13 * j, t + 5 * k);
		delay(d);
		line(l + 11 * j, t + 4 * k, l + 14 * j, t + 4 * k);
		delay(d);
		line(l + 11 * j, t + 4 * k, l + 11 * j, t + 6 * k);
		delay(d);
		line(l + 10 * j, t + 5 * k, l + 11 * j, t + 5 * k);
		delay(d);
		line(l + 10 * j, t + 4 * k, l + 10 * j, t + 5 * k);
		delay(d);
		line(l + 9 * j, t + 4 * k, l + 10 * j, t + 4 * k);
		delay(d);
		line(l + 9 * j, t + 2 * k, l + 9 * j, t + 4 * k);
		delay(d);
		line(l + 9 * j, t + 3 * k, l + 10 * j, t + 3 * k);
		delay(d);

		line(l + 6 * j, t + 6 * k, l + 11 * j, t + 6 * k);
		delay(d);
		line(l + 6 * j, t + 3 * k, l + 6 * j, t + 10 * k);
		delay(d);
		line(l + 6 * j, t + 4 * k, l + 7 * j, t + 4 * k);
		delay(d);
		line(l + 7 * j, t + 3 * k, l + 7 * j, t + 4 * k);
		delay(d);
		line(l + 5 * j, t + 3 * k, l + 6 * j, t + 3 * k);
		delay(d);
		line(l + 5 * j, t + 2 * k, l + 5 * j, t + 3 * k);
		delay(d);
		line(l + 5 * j, t + 2 * k, l + 6 * j, t + 2 * k);
		delay(d);
		line(l + 2 * j, t + 5 * k, l + 6 * j, t + 5 * k);
		delay(d);
		line(l + 2 * j, t + 4 * k, l + 2 * j, t + 5 * k);
		delay(d);
		line(l + 2 * j, t + 4 * k, l + 3 * j, t + 4 * k);
		delay(d);
		line(l + 3 * j, t + 2 * k, l + 3 * j, t + 4 * k);
		delay(d);
		line(l + 2 * j, t + 2 * k, l + 3 * j, t + 2 * k);
		delay(d);
		line(l + 4 * j, t + 5 * k, l + 4 * j, t + 6 * k);
		delay(d);

		line(l + 4 * j, t + 9 * k, l + 6 * j, t + 9 * k);
		delay(d);
		line(l + 4 * j, t + 9 * k, l + 4 * j, t + 11 * k);
		delay(d);
		line(l + 2 * j, t + 10 * k, l + 4 * j, t + 10 * k);
		delay(d);
		line(l + 2 * j, t + 8 * k, l + 2 * j, t + 12 * k);
		delay(d);

		line(l + 10 * j, t + 6 * k, l + 10 * j, t + 10 * k);
		delay(d);
		line(l + 10 * j, t + 10 * k, l + 12 * j, t + 10 * k);
		delay(d);
		line(l + 12 * j, t + 8 * k, l + 12 * j, t + 11 * k);
		delay(d);
		line(l + 12 * j, t + 8 * k, l + 13 * j, t + 8 * k);
		delay(d);
		line(l + 13 * j, t + 7 * k, l + 13 * j, t + 8 * k);
		delay(d);
		line(l + 13 * j, t + 7 * k, l + 14 * j, t + 7 * k);
		delay(d);

		line(l + 12 * j, t + 11 * k, l + 14 * j, t + 11 * k);
		delay(d);
		line(l + 14 * j, t + 11 * k, l + 14 * j, t + 13 * k);
		delay(d);
		line(l + 13 * j, t + 11 * k, l + 13 * j, t + 13 * k);
		delay(d);
		line(l + 12 * j, t + 12 * k, l + 13 * j, t + 12 * k);
		delay(d);
		line(l + 12 * j, t + 12 * k, l + 12 * j, t + 14 * k);
		delay(d);

		line(l + 11 * j, t + 13 * k, l + 12 * j, t + 13 * k);
		delay(d);
		line(l + 11 * j, t + 12 * k, l + 11 * j, t + 13 * k);
		delay(d);
		line(l + 11 * j, t + 12 * k, l + 7 * j, t + 12 * k);
		delay(d);
		line(l + 10 * j, t + 12 * k, l + 10 * j, t + 13 * k);
		delay(d);
		line(l + 8 * j, t + 11 * k, l + 8 * j, t + 12 * k);
		delay(d);
		line(l + 7 * j, t + 12 * k, l + 7 * j, t + 14 * k);
		delay(d);
		line(l + 3 * j, t + 14 * k, l + 8 * j, t + 14 * k);
		delay(d);




		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		delay(100);
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		 sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		delay(100);
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		 sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		delay(100);
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		 sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		delay(100);
		setcolor(GREEN);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		 sound(300);
		delay(100);
		nosound();
		setcolor(YELLOW);
		circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);

		//sound(300);
	   // delay(50);
		//nosound();
		//delay(50);
		//sound(300);
		//delay(50);
		//nosound();


		char play = 'g';
		
			

		while (play != '0') {
		if (play == 'a')
		{
			if((l+x)==l)
			{
				chk.voilate();
			}
			else if(((l+x)==l+j) && (((t+y+k-6)>=(t+k) && (t+y)<(t+13*k)) || (((t+y+k-6)>=(t+14*k) ) && (t+y)<(t+16*k))  ))
			{
				chk.voilate();
			}
			
			else if(        ((l+x)==(l+2*j)) &&    (  (t+y+k-6)>=(t+4*k) && (t+y)<(t+5*k)  || (t+y+k-6)>=(t+6*k)&&(t+y)<(t+7*k)  || (t+y+k-6)>=(t+8*k)&&(t+y)<(t+12*k)  || (t+y+k-6)>=(t+13*k)&&(t+y)<(t+15*k) )      )
			{
				chk.voilate();	
			}
			
			else if(  ((l+x)==(l+3*j)) && ((t+y+k-6)>=(t+2*k) && (t+y)<(t+4*k) || (t+y+k-6)>=(t+6*k) && (t+y)<(t+7*k) ||    (t+y+k-6)>=(t+8*k) && (t+y)<(t+9*k)   ||  (t+y+k-6)>=(t+11*k) &&  (t+y)<(t+13*k) )    )
			{
				chk.voilate();
			}
			
			else if(     ((l+x)==(l+4*j))   && (     (t+y+k-6)>=(t+1*k) && (t+y)<(t+4*k)  ||  (t+y+k-6)>=(t+5*k) && (t+y)<(t+6*k)  ||   (t+y+k-6)>=(t+7*k) && (t+y)<(t+8*k)  ||  (t+y+k-6)>=(t+9*k) &&  (t+y)<(t+11*k)  ||  (t+y+k-6)>=(t+12*k) &&  (t+y)<(t+13*k) ))
			{
				chk.voilate();
			}
			
			else if(        ((l+x)==(l+5*j))  &&    (    (t+y+k-6)>=(t+2*k)&&(t+y)<(t+3*k)  ||   (t+y+k-6)>=(t+6*k)&&(t+y)<(t+8*k)   ||  (t+y+k-6)>=(t+10*k)&&(t+y)<(t+11*k)   ||  (t+y+k-6)>=(t+12*k)&&(t+y)<(t+13*k)   ) )
			{
				chk.voilate();
			}
			
			
			else if(   ((l+x)==(l+6*j))  &&  (      (t+y+k-6)>=(t+3*k)&&(t+y)<(t+10*k)   ||   (t+y+k-6)>=(t+11*k)&&(t+y)<(t+12*k)   ) )
			{
				chk.voilate();
			}
			
			else if(        ((l+x)==(l+7*j)) &&    (       (t+y+k-6)>=(t+k)&&(t+y)<(t+2*k)  ||  (t+y+k-6)>=(t+3*k)&&(t+y)<(t+4*k)  || (t+y+k-6)>=(t+ 7*k)&&(t+y)<(t+ 9*k)   || (t+y+k-6)>=(t+ 10*k)&&(t+y)<(t+ 11*k)   || (t+y+k-6)>=(t+ 12*k)&&(t+y)<(t+ 14*k)       ) )
			{
				chk.voilate();
				
			}
			
			
			else if(        ((l+x)==(l+8*j)) &&  (   (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  5*k)  ||  (t+y+k-6)>=(t+  11*k)&&(t+y)<(t+  12*k)    ) )
			{
				chk.voilate();
			}
			
			else if(     ((l+x)==(l+9*j)) && (    (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  4*k)  ||  (t+y+k-6)>=(t+  7*k)&&(t+y)<(t+  11*k)   ||  (t+y+k-6)>=(t+  13*k)&&(t+y)<(t+  14*k)  ) )
			{
				chk.voilate();
			}
			
			else if( ((l+x)==(l+10*j)) && (  (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  2*k) ||  (t+y+k-6)>=(t+  4*k)&&(t+y)<(t+  5*k)  ||  (t+y+k-6)>=(t+  6*k)&&(t+y)<(t+  10*k)  ||  (t+y+k-6)>=(t+  12*k)&&(t+y)<(t+  13*k) ||  (t+y+k-6)>=(t+  14*k)&&(t+y)<(t+  15*k)  )  )
			{
				chk.voilate();
			}
			
			
			else if(((l+x)==(l+11*j)) &&  (   (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  3*k) ||  (t+y+k-6)>=(t+  4*k)&&(t+y)<(t+  6*k) ||  (t+y+k-6)>=(t+  7*k)&&(t+y)<(t+  9*k) ||  (t+y+k-6)>=(t+  12*k)&&(t+y)<(t+  13*k)  ||  (t+y+k-6)>=(t+  14*k)&&(t+y)<(t+  15*k)  ))
			{
				chk.voilate();
			}
			
			else if(  ((l+x)==(l+12*j))  &&  (  (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  7*k)  ||  (t+y+k-6)>=(t+  8*k)&&(t+y)<(t+  11*k)  ||  (t+y+k-6)>=(t+  12*k)&&(t+y)<(t+  14*k)   ))
			{
				chk.voilate();
			}
			
			else if( ((l+x)==(l+13*j)) &&  (   (t+y+k-6)>=(t+  3*k)&&(t+y)<(t+  5*k)    ||  (t+y+k-6)>=(t+  7*k)&&(t+y)<(t+  8*k)    ||  (t+y+k-6)>=(t+  9*k)&&(t+y)<(t+  10*k)   ||  (t+y+k-6)>=(t+  11*k)&&(t+y)<(t+  13*k)    ||  (t+y+k-6)>=(t+  14*k)&&(t+y)<(t+  15*k)    ) )
			{
				chk.voilate();
			}
			
			else if(  ((l+x)==(l+14*j)) &&   (    (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  3*k)    ||  (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  6*k)   ||  (t+y+k-6)>=(t+  9*k)&&(t+y)<(t+  10*k)   ||  (t+y+k-6)>=(t+  11*k)&&(t+y)<(t+  13*k)     ||  (t+y+k-6)>=(t+  14*k)&&(t+y)<(t+  15*k)  )  )
			{
				chk.voilate();
			}
			
			else if(  ((l+x)==(l+15*j)) &&   (   (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  4*k)   ||  (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  15*k)    )  )
			{
				chk.voilate();
			}
			
			
			
			else
			{
			setcolor(BLACK);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			x = x - 5;
			setcolor(YELLOW);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			}
			
		}
		
		if (play == 'd') {
			
			if((l+x+k)==(l+16*j))
			{
				chk.voilate();
			}
			else if(((l+x+k)==l+j) && (((t+y+k-6)>=(t+k) && (t+y)<(t+13*k)) || (((t+y+k-6)>=(t+14*k) ) && (t+y)<(t+16*k))  ))
			{
				chk.voilate();
			}
			
			else if(        ((l+x+k)==(l+2*j)) &&    (  (t+y+k-6)>=(t+4*k) && (t+y)<(t+5*k)  || (t+y+k-6)>=(t+6*k)&&(t+y)<(t+7*k)  || (t+y+k-6)>=(t+8*k)&&(t+y)<(t+12*k)  || (t+y+k-6)>=(t+13*k)&&(t+y)<(t+15*k) )      )
			{
				chk.voilate();
			}
			
			else if(  ((l+x+k)==(l+3*j)) && ((t+y+k-6)>=(t+2*k) && (t+y)<(t+4*k) || (t+y+k-6)>=(t+6*k) && (t+y)<(t+7*k) ||    (t+y+k-6)>=(t+8*k) && (t+y)<(t+9*k)   ||  (t+y+k-6)>=(t+11*k) &&  (t+y)<(t+13*k) )    )
			{
				chk.voilate();
			}
			
			else if(     ((l+x+k)==(l+4*j))   && (     (t+y+k-6)>=(t+1*k) && (t+y)<(t+4*k)  ||  (t+y+k-6)>=(t+5*k) && (t+y)<(t+6*k)  ||   (t+y+k-6)>=(t+7*k) && (t+y)<(t+8*k)  ||  (t+y+k-6)>=(t+9*k) &&  (t+y)<(t+11*k)  ||  (t+y+k-6)>=(t+12*k) &&  (t+y)<(t+13*k) ))
			{
				chk.voilate();
			}
			
			else if(        ((l+x+k)==(l+5*j))  &&    (    (t+y+k-6)>=(t+2*k)&&(t+y)<(t+3*k)  ||   (t+y+k-6)>=(t+6*k)&&(t+y)<(t+8*k)   ||  (t+y+k-6)>=(t+10*k)&&(t+y)<(t+11*k)   ||  (t+y+k-6)>=(t+12*k)&&(t+y)<(t+13*k)   ) )
			{
				chk.voilate();
			}
			
			
			else if(   ((l+x+k)==(l+6*j))  &&  (      (t+y+k-6)>=(t+3*k)&&(t+y)<(t+10*k)   ||   (t+y+k-6)>=(t+11*k)&&(t+y)<(t+12*k)   ) )
			{
				chk.voilate();
			}
			
			else if(        ((l+x+k)==(l+7*j)) &&    (       (t+y+k-6)>=(t+k)&&(t+y)<(t+2*k)  ||  (t+y+k-6)>=(t+3*k)&&(t+y)<(t+4*k)  || (t+y+k-6)>=(t+ 7*k)&&(t+y)<(t+ 9*k)   || (t+y+k-6)>=(t+ 10*k)&&(t+y)<(t+ 11*k)   || (t+y+k-6)>=(t+ 12*k)&&(t+y)<(t+ 14*k)       ) )
			{
				chk.voilate();
				
			}
			
			
			else if(        ((l+x+k)==(l+8*j)) &&  (   (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  5*k)  ||  (t+y+k-6)>=(t+  11*k)&&(t+y)<(t+  12*k)    ) )
			{
				chk.voilate();
				
			}
			
			else if(     ((l+x+k)==(l+9*j)) && (    (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  4*k)  ||  (t+y+k-6)>=(t+  7*k)&&(t+y)<(t+  11*k)   ||  (t+y+k-6)>=(t+  13*k)&&(t+y)<(t+  14*k)  ) )
			{
				chk.voilate();
				
			}
			
			else if( ((l+x+k)==(l+10*j)) && (  (t+y+k-6)>=(t+  1*k)&&(t+y)<(t+  2*k) ||  (t+y+k-6)>=(t+  4*k)&&(t+y)<(t+  5*k)  ||  (t+y+k-6)>=(t+  6*k)&&(t+y)<(t+  10*k)  ||  (t+y+k-6)>=(t+  12*k)&&(t+y)<(t+  13*k) ||  (t+y+k-6)>=(t+  14*k)&&(t+y)<(t+  15*k)  )  )
			{
				chk.voilate();
				
			}
			
			
			else if(((l+x+k)==(l+11*j)) &&  (   (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  3*k) ||  (t+y+k-6)>=(t+  4*k)&&(t+y)<(t+  6*k) ||  (t+y+k-6)>=(t+  7*k)&&(t+y)<(t+  9*k) ||  (t+y+k-6)>=(t+  12*k)&&(t+y)<(t+  13*k)  ||  (t+y+k-6)>=(t+  14*k)&&(t+y)<(t+  15*k)  ))
			{
				chk.voilate();
				
			}
			
			else if(  ((l+x+k)==(l+12*j))  &&  (  (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  7*k)  ||  (t+y+k-6)>=(t+  8*k)&&(t+y)<(t+  11*k)  ||  (t+y+k-6)>=(t+  12*k)&&(t+y)<(t+  14*k)   ))
			{
				chk.voilate();
			}
			
			else if( ((l+x+k)==(l+13*j)) &&  (   (t+y+k-6)>=(t+  3*k)&&(t+y)<(t+  5*k)    ||  (t+y+k-6)>=(t+  7*k)&&(t+y)<(t+  8*k)    ||  (t+y+k-6)>=(t+  9*k)&&(t+y)<(t+  10*k)   ||  (t+y+k-6)>=(t+  11*k)&&(t+y)<(t+  13*k)    ||  (t+y+k-6)>=(t+  14*k)&&(t+y)<(t+  15*k)    ) )
			{
				chk.voilate();
			}
			
			else if(  ((l+x+k)==(l+14*j)) &&   (    (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  3*k)    ||  (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  6*k)   ||  (t+y+k-6)>=(t+  9*k)&&(t+y)<(t+  10*k)   ||  (t+y+k-6)>=(t+  11*k)&&(t+y)<(t+  13*k)     ||  (t+y+k-6)>=(t+  14*k)&&(t+y)<(t+  15*k)  )  )
			{
				chk.voilate();
			}
			
			else if(  ((l+x+k)==(l+15*j)) &&   (   (t+y+k-6)>=(t+  2*k)&&(t+y)<(t+  4*k)   ||  (t+y+k-6)>=(t+  5*k)&&(t+y)<(t+  15*k)    )  )
			{
				chk.voilate();
			}
			
			else{
			setcolor(BLACK);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			x = x + 5;
			setcolor(YELLOW);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			}
		}
		if (play == 'w')
		{
			 if(((t+y)==(t+9*k)) && ((l+x)>=(l+7*j-6) && (l+x)<(l+8*j)))
		      {
				setcolor(GREEN);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				sound(300);
				delay(100);
				nosound();
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				delay(100);
				setcolor(GREEN);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				sound(300);
				delay(100);
				nosound();
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				delay(100);
				setcolor(GREEN);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				sound(300);
				delay(100);
				nosound();
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				delay(100);
				setcolor(GREEN);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				sound(300);
				delay(100);
				nosound();
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				delay(100);
				setcolor(GREEN);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				sound(300);
				delay(100);
				nosound();
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
		
				w.won_diff();   // calling of win function
			
		      }
		      else if((t+y)==t)
			{
				chk.voilate();
			}
				
			else if(  ((t+y)==(t+k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+ 14*j)    || (l+x)>=(l+  15*j-6)&&(l+x)<(l+ 16*j)    ))
			{
				chk.voilate();
			}
		   	else if(   ((t+y)==(t+2*k)) && (     (l+x)>=(l+  2*j-6)&&(l+x)<(l+ 3*j)    || (l+x)>=(l+  5*j-6)&&(l+x)<(l+ 6*j)    || (l+x)>=(l+  7*j-6)&&(l+x)<(l+ 8*j)   || (l+x)>=(l+  10*j-6)&&(l+x)<(l+ 11*j)    || (l+x)>=(l+  12*j-6)&&(l+x)<(l+ 14*j)         ) )
			{
				chk.voilate();
		   	}
			
			else if(   ((t+y)==(t+3*k)) &&  (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+ 2*j)    || (l+x)>=(l+  5*j-6)&&(l+x)<(l+ 6*j)    || (l+x)>=(l+  9*j-6)&&(l+x)<(l+ 10*j)    || (l+x)>=(l+  11*j-6)&&(l+x)<(l+ 12*j)    || (l+x)>=(l+  13*j-6)&&(l+x)<(l+ 15*j)      ) )
			{
				chk.voilate();
		   	}
			
			else if(   ((t+y)==(t+4*k)) &&   (    (l+x)>=(l+  2*j-6)&&(l+x)<(l+ 3*j)   || (l+x)>=(l+  4*j-6)&&(l+x)<(l+ 5*j)   || (l+x)>=(l+  6*j-6)&&(l+x)<(l+ 7*j)     || (l+x)>=(l+  9*j-6)&&(l+x)<(l+ 10*j)   || (l+x)>=(l+  11*j-6)&&(l+x)<(l+ 14*j)      ) )
			{
				chk.voilate();
		   	}
			else if(   ((t+y)==(t+5*k))  && (     (l+x)>=(l+  2*j-6)&&(l+x)<(l+ 6*j)     || (l+x)>=(l+  7*j-6)&&(l+x)<(l+ 9*j)    || (l+x)>=(l+  10*j-6)&&(l+x)<(l+ 11*j)        ) )
			{
				chk.voilate();
		   	}
			
			else if(((t+y)==(t+6*k)) &&  (   (l+x)>=(l+  1*j-6)&&(l+x)<(l+ 3*j)    || (l+x)>=(l+  6*j-6)&&(l+x)<(l+ 11*j)   || (l+x)>=(l+  12*j-6)&&(l+x)<(l+ 15*j)      ))
			{
				chk.voilate();
		   	}
			
			else if(((t+y)==(t+7*k)) && (   (l+x)>=(l+  3*j-6)&&(l+x)<(l+ 5*j)    || (l+x)>=(l+  7*j-6)&&(l+x)<(l+ 9*j)    || (l+x)>=(l+  11*j-6)&&(l+x)<(l+ 12*j)   || (l+x)>=(l+  13*j-6)&&(l+x)<(l+ 14*j)        ))
			{
				chk.voilate();
		   	}
			
			else if(((t+y)==(t+8*k))  &&  (     (l+x)>=(l+  3*j-6)&&(l+x)<(l+ 4*j)    || (l+x)>=(l+  12*j-6)&&(l+x)<(l+ 13*j)     || (l+x)>=(l+  14*j-6)&&(l+x)<(l+ 15*j)   ))
			{
				chk.voilate();
			}
			 
			else if(((t+y)==(t+9*k)) &&  (    (l+x)>=(l+  4*j-6)&&(l+x)<(l+ 6*j)    || (l+x)>=(l+  8*j-6)&&(l+x)<(l+ 9*j)     || (l+x)>=(l+  14*j-6)&&(l+x)<(l+ 15*j)   ))
			{
				chk.voilate();
			}
			else if(((t+y)==(t+10*k)) &&  (     (l+x)>=(l+  2*j-6)&&(l+x)<(l+ 4*j)     || (l+x)>=(l+  7*j-6)&&(l+x)<(l+ 9*j)   || (l+x)>=(l+  10*j-6)&&(l+x)<(l+ 12*j)    || (l+x)>=(l+  13*j-6)&&(l+x)<(l+ 14*j)    ))
			{
				chk.voilate();
			}
			else if(((t+y)==(t+11*k)) && (    (l+x)>=(l+  5*j-6)&&(l+x)<(l+ 7*j)   || (l+x)>=(l+  9*j-6)&&(l+x)<(l+ 11*j)    || (l+x)>=(l+  12*j-6)&&(l+x)<(l+ 14*j)   ))
			{
				chk.voilate();
			}
			else if(((t+y)==(t+12*k)) && (    (l+x)>=(l+  5*j-6)&&(l+x)<(l+ 6*j)   || (l+x)>=(l+  7*j-6)&&(l+x)<(l+ 11*j)    || (l+x)>=(l+  12*j-6)&&(l+x)<(l+ 13*j)   ))
			{
				chk.voilate();
			}
			else if(((t+y)==(t+13*k)) && (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+ 6*j)   || (l+x)>=(l+  8*j-6)&&(l+x)<(l+ 9*j)    || (l+x)>=(l+  11*j-6)&&(l+x)<(l+ 12*j)   ))
			{
				chk.voilate();
			}
			else if(((t+y)==(t+14*k)) && (    (l+x)>=(l+  3*j-6)&&(l+x)<(l+ 8*j)   || (l+x)>=(l+  9*j-6)&&(l+x)<(l+ 10*j)   ))
			{
				chk.voilate();
			}
			else if(((t+y)==(t+15*k)) && (  (l+x)>=(l+  2*j-6)&&(l+x)<(l+ 15*j)  ))
			{
				chk.voilate();
			}
		
			//  || (l+x)>=(l+  *j-6)&&(l+x)<(l+ *j)  
			else
			{
				setcolor(BLACK);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
				y = y - 5;
				setcolor(YELLOW);
				circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			}
		}

		if (play == 's') 
		{
			if((t+y+j)==(t+16*k))
			{
				chk.voilate();
			}
			else if(  ((t+y+j)==(t+k)) &&   (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+ 14*j)    || (l+x)>=(l+  15*j-6)&&(l+x)<(l+ 16*j)    ))
			{
				chk.voilate();
			}
		   	else if(   ((t+y+j)==(t+2*k)) && (     (l+x)>=(l+  2*j-6)&&(l+x)<(l+ 3*j)    || (l+x)>=(l+  5*j-6)&&(l+x)<(l+ 6*j)    || (l+x)>=(l+  7*j-6)&&(l+x)<(l+ 8*j)   || (l+x)>=(l+  10*j-6)&&(l+x)<(l+ 11*j)    || (l+x)>=(l+  12*j-6)&&(l+x)<(l+ 14*j)         ) )
			{
				chk.voilate();
		   	}
			
			else if(   ((t+y+j)==(t+3*k)) &&  (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+ 2*j)    || (l+x)>=(l+  5*j-6)&&(l+x)<(l+ 6*j)    || (l+x)>=(l+  9*j-6)&&(l+x)<(l+ 10*j)    || (l+x)>=(l+  11*j-6)&&(l+x)<(l+ 12*j)    || (l+x)>=(l+  13*j-6)&&(l+x)<(l+ 15*j)      ) )
			{
				chk.voilate();
		   	}
			
			else if(   ((t+y+j)==(t+4*k)) &&   (    (l+x)>=(l+  2*j-6)&&(l+x)<(l+ 3*j)   || (l+x)>=(l+  4*j-6)&&(l+x)<(l+ 5*j)   || (l+x)>=(l+  6*j-6)&&(l+x)<(l+ 7*j)     || (l+x)>=(l+  9*j-6)&&(l+x)<(l+ 10*j)   || (l+x)>=(l+  11*j-6)&&(l+x)<(l+ 14*j)      ) )
			{
				chk.voilate();
		   	}
			else if(   ((t+y+j)==(t+5*k))  && (     (l+x)>=(l+  2*j-6)&&(l+x)<(l+ 6*j)     || (l+x)>=(l+  7*j-6)&&(l+x)<(l+ 9*j)    || (l+x)>=(l+  10*j-6)&&(l+x)<(l+ 11*j)        ) )
			{
				chk.voilate();
		   	}
			
			else if(((t+y+j)==(t+6*k)) &&  (   (l+x)>=(l+  1*j-6)&&(l+x)<(l+ 3*j)    || (l+x)>=(l+  6*j-6)&&(l+x)<(l+ 11*j)   || (l+x)>=(l+  12*j-6)&&(l+x)<(l+ 15*j)      ))
			{
				chk.voilate();
		   	}
			
			else if(((t+y+j)==(t+7*k)) && (   (l+x)>=(l+  3*j-6)&&(l+x)<(l+ 5*j)    || (l+x)>=(l+  7*j-6)&&(l+x)<(l+ 9*j)    || (l+x)>=(l+  11*j-6)&&(l+x)<(l+ 12*j)   || (l+x)>=(l+  13*j-6)&&(l+x)<(l+ 14*j)        ))
			{
				chk.voilate();
		   	}
			
			else if(((t+y+j)==(t+8*k))  &&  (     (l+x)>=(l+  3*j-6)&&(l+x)<(l+ 4*j)    || (l+x)>=(l+  12*j-6)&&(l+x)<(l+ 13*j)     || (l+x)>=(l+  14*j-6)&&(l+x)<(l+ 15*j)   ))
			{
				chk.voilate();
			}
			 
			else if(((t+y+j)==(t+9*k)) &&  (    (l+x)>=(l+  4*j-6)&&(l+x)<(l+ 6*j)    || (l+x)>=(l+  8*j-6)&&(l+x)<(l+ 9*j)     || (l+x)>=(l+  14*j-6)&&(l+x)<(l+ 15*j)   ))
			{
				chk.voilate();
			}
			else if(((t+y+j)==(t+10*k)) &&  (     (l+x)>=(l+  2*j-6)&&(l+x)<(l+ 4*j)     || (l+x)>=(l+  7*j-6)&&(l+x)<(l+ 9*j)   || (l+x)>=(l+  10*j-6)&&(l+x)<(l+ 12*j)    || (l+x)>=(l+  13*j-6)&&(l+x)<(l+ 14*j)    ))
			{
				chk.voilate();
			}
			else if(((t+y+j)==(t+11*k)) && (    (l+x)>=(l+  5*j-6)&&(l+x)<(l+ 7*j)   || (l+x)>=(l+  9*j-6)&&(l+x)<(l+ 11*j)    || (l+x)>=(l+  12*j-6)&&(l+x)<(l+ 14*j)   ))
			{
				chk.voilate();
			}
			else if(((t+y+j)==(t+12*k)) && (    (l+x)>=(l+  5*j-6)&&(l+x)<(l+ 6*j)   || (l+x)>=(l+  7*j-6)&&(l+x)<(l+ 11*j)    || (l+x)>=(l+  12*j-6)&&(l+x)<(l+ 13*j)   ))
			{
				chk.voilate();
			}
			else if(((t+y+j)==(t+13*k)) && (    (l+x)>=(l+  1*j-6)&&(l+x)<(l+ 6*j)   || (l+x)>=(l+  8*j-6)&&(l+x)<(l+ 9*j)    || (l+x)>=(l+  11*j-6)&&(l+x)<(l+ 12*j)   ))
			{
				chk.voilate();
			}
			else if(((t+y+j)==(t+14*k)) && (    (l+x)>=(l+  3*j-6)&&(l+x)<(l+ 8*j)   || (l+x)>=(l+  9*j-6)&&(l+x)<(l+ 10*j)   ))
			{
				chk.voilate();
			}
			else if(((t+y+j)==(t+15*k)) && (  (l+x)>=(l+  2*j-6)&&(l+x)<(l+ 15*j)  ))
			{
				chk.voilate();
			}
			else
			{
			setcolor(BLACK);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			y = y + 5;
			setcolor(YELLOW);
			circle(l + j / 2 + x, t + k / 2 + y, j / 2 - 5);
			}
		}
		play = getch();
		}



	}
	void win::won_diff()
	{
		select sell;
		win w1;
		setcolor(BLACK);
		d = 30;
		j = 25; // width
		k = 25; // height
		l, t, r, b;
		l = (615 - 16 * j) / 2;
		t = (460 - 16 * k) / 2;
		r = (615 - 16 * j) / 2 + 16 * j;
		b = (460 - 16 * k) / 2 + 16 * k;

		rectangle(l, t, r, b);
		delay(d);

		line(l + j, t + 14 * k, l + j, t + 16 * k);
		delay(d);
		line(l + 2 * j, t + 15 * k, l + 15 * j, t + 15 * k);
		delay(d);
		line(l + 2 * j, t + 13 * k, l + 2 * j, t + 15 * k);
		delay(d);
		line(l + j, t + 13 * k, l + 6 * j, t + 13 * k);
		delay(d);
		line(l + j, t + k, l + j, t + 13 * k);
		delay(d);
		line(l + 3 * j, t + 11 * k, l + 3 * j, t + 13 * k);
		delay(d);
		line(l + 4 * j, t + 12 * k, l + 4 * j, t + 13 * j);
		delay(d);
		line(l + 5 * j, t + 13 * k, l + 5 * j, t + 12 * k);
		delay(d);
		line(l + 5 * j, t + 12 * k, l + 6 * j, t + 12 * k);
		delay(d);
		line(l + 6 * j, t + 12 * k, l + 6 * j, t + 11 * k);
		delay(d);
		line(l + 5 * j, t + 10 * k, l + 5 * j, t + 11 * k);
		delay(d);
		line(l + 5 * j, t + 11 * k, l + 7 * j, t + 11 * k);
		delay(d);
		line(l + 7 * j, t + 11 * k, l + 7 * j, t + 10 * k);
		delay(d);
		line(l + 7 * j, t + 10 * k, l + 9 * j, t + 10 * k);
		delay(d);
		line(l + 9 * j, t + 7 * k, l + 9 * j, t + 11 * k);
		delay(d);
		line(l + 8 * j, t + 9 * k, l + 9 * j, t + 9 * k);
		delay(d);
		line(l + 9 * j, t + 11 * k, l + 11 * j, t + 11 * k);
		delay(d);
		line(l + 7 * j, t + 7 * k, l + 9 * j, t + 7 * k);
		delay(d);
		line(l + 7 * j, t + 7 * k, l + 7 * j, t + 9 * k);
		delay(d);
		line(l + j, t + 6 * k, l + 3 * j, t + 6 * k);
		delay(d);
		line(l + 2 * j, t + 6 * k, l + 2 * j, t + 7 * k);
		delay(d);
		line(l + 3 * j, t + 6 * k, l + 3 * j, t + 7 * k);
		delay(d);
		line(l + 3 * j, t + 7 * k, l + 5 * j, t + 7 * k);
		delay(d);
		line(l + 5 * j, t + 6 * k, l + 5 * j, t + 8 * k);
		delay(d);
		line(l + 4 * j, t + 7 * k, l + 4 * j, t + 8 * k);
		delay(d);
		line(l + 3 * j, t + 8 * k, l + 4 * j, t + 8 * k);
		delay(d);
		line(l + 3 * j, t + 8 * k, l + 3 * j, t + 9 * k);
		delay(d);
		line(l + j, t + 3 * k, l + 2 * j, t + 3 * k);
		delay(d);
		line(l + j, t + k, l + 14 * j, t + k);
		delay(d);
		line(l + 4 * j, t + k, l + 4 * j, t + 4 * k);
		delay(d);
		line(l + 4 * j, t + 4 * k, l + 5 * j, t + 4 * k);
		delay(d);
		line(l + 7 * j, t + k, l + 7 * j, t + 2 * k);
		delay(d);
		line(l + 7 * j, t + 2 * k, l + 8 * j, t + 2 * k);
		delay(d);
		line(l + 8 * j, t + 2 * k, l + 8 * j, t + 5 * k);
		delay(d);
		line(l + 7 * j, t + 5 * k, l + 9 * j, t + 5 * k);
		delay(d);
		line(l + 10 * j, t + k, l + 10 * j, t + 2 * k);
		delay(d);
		line(l + 10 * j, t + 2 * k, l + 11 * j, t + 2 * k);
		delay(d);
		line(l + 11 * j, t + 2 * k, l + 11 * j, t + 3 * k);
		delay(d);
		line(l + 11 * j, t + 3 * k, l + 12 * j, t + 3 * k);
		delay(d);

		line(l + 10 * j, t + 15 * k, l + 10 * j, t + 14 * k);
		delay(d);
		line(l + 9 * j, t + 14 * k, l + 10 * j, t + 14 * k);
		delay(d);
		line(l + 9 * j, t + 14 * k, l + 9 * j, t + 13 * k);
		delay(d);
		line(l + 8 * j, t + 13 * k, l + 9 * j, t + 13 * k);
		delay(d);
		line(l + 11 * j, t + 15 * k, l + 11 * j, t + 14 * k);
		delay(d);
		line(l + 13 * j, t + 15 * k, l + 13 * j, t + 14 * k);
		delay(d);
		line(l + 14 * j, t + 15 * k, l + 14 * j, t + 14 * k);
		delay(d);

		line(l + 15 * j, t + 15 * k, l + 15 * j, t + 5 * k);
		delay(d);
		line(l + 15 * j, t + 9 * k, l + 14 * j, t + 9 * k);
		delay(d);
		line(l + 14 * j, t + 9 * k, l + 14 * j, t + 10 * k);
		delay(d);
		line(l + 14 * j, t + 10 * k, l + 13 * j, t + 10 * k);
		delay(d);
		line(l + 13 * j, t + 10 * k, l + 13 * j, t + 9 * k);
		delay(d);
		line(l + 14 * j, t + 8 * k, l + 15 * k, t + 8 * k);
		delay(d);

		line(l + 15 * j, t + 6 * k, l + 12 * j, t + 6 * k);
		delay(d);
		line(l + 14 * j, t + 6 * k, l + 14 * j, t + 5 * k);
		delay(d);
		line(l + 12 * j, t + 5 * k, l + 12 * j, t + 7 * k);
		delay(d);
		line(l + 11 * j, t + 7 * k, l + 12 * k, t + 7 * k);
		delay(d);
		line(l + 11 * j, t + 7 * k, l + 11 * j, t + 9 * k);
		delay(d);

		line(l + 15 * j, t + k, l + 16 * j, t + k);
		delay(d);
		line(l + 13 * j, t + 3 * k, l + 15 * j, t + 3 * k);
		delay(d);
		line(l + 15 * j, t + 2 * k, l + 15 * j, t + 4 * k);
		delay(d);
		line(l + 14 * j, t + 2 * k, l + 14 * j, t + 3 * k);
		delay(d);
		line(l + 12 * j, t + 2 * k, l + 14 * j, t + 2 * k);
		delay(d);
		line(l + 13 * j, t + 3 * k, l + 13 * j, t + 5 * k);
		delay(d);
		line(l + 11 * j, t + 4 * k, l + 14 * j, t + 4 * k);
		delay(d);
		line(l + 11 * j, t + 4 * k, l + 11 * j, t + 6 * k);
		delay(d);
		line(l + 10 * j, t + 5 * k, l + 11 * j, t + 5 * k);
		delay(d);
		line(l + 10 * j, t + 4 * k, l + 10 * j, t + 5 * k);
		delay(d);
		line(l + 9 * j, t + 4 * k, l + 10 * j, t + 4 * k);
		delay(d);
		line(l + 9 * j, t + 2 * k, l + 9 * j, t + 4 * k);
		delay(d);
		line(l + 9 * j, t + 3 * k, l + 10 * j, t + 3 * k);
		delay(d);

		line(l + 6 * j, t + 6 * k, l + 11 * j, t + 6 * k);
		delay(d);
		line(l + 6 * j, t + 3 * k, l + 6 * j, t + 10 * k);
		delay(d);
		line(l + 6 * j, t + 4 * k, l + 7 * j, t + 4 * k);
		delay(d);
		line(l + 7 * j, t + 3 * k, l + 7 * j, t + 4 * k);
		delay(d);
		line(l + 5 * j, t + 3 * k, l + 6 * j, t + 3 * k);
		delay(d);
		line(l + 5 * j, t + 2 * k, l + 5 * j, t + 3 * k);
		delay(d);
		line(l + 5 * j, t + 2 * k, l + 6 * j, t + 2 * k);
		delay(d);
		line(l + 2 * j, t + 5 * k, l + 6 * j, t + 5 * k);
		delay(d);
		line(l + 2 * j, t + 4 * k, l + 2 * j, t + 5 * k);
		delay(d);
		line(l + 2 * j, t + 4 * k, l + 3 * j, t + 4 * k);
		delay(d);
		line(l + 3 * j, t + 2 * k, l + 3 * j, t + 4 * k);
		delay(d);
		line(l + 2 * j, t + 2 * k, l + 3 * j, t + 2 * k);
		delay(d);
		line(l + 4 * j, t + 5 * k, l + 4 * j, t + 6 * k);
		delay(d);

		line(l + 4 * j, t + 9 * k, l + 6 * j, t + 9 * k);
		delay(d);
		line(l + 4 * j, t + 9 * k, l + 4 * j, t + 11 * k);
		delay(d);
		line(l + 2 * j, t + 10 * k, l + 4 * j, t + 10 * k);
		delay(d);
		line(l + 2 * j, t + 8 * k, l + 2 * j, t + 12 * k);
		delay(d);

		line(l + 10 * j, t + 6 * k, l + 10 * j, t + 10 * k);
		delay(d);
		line(l + 10 * j, t + 10 * k, l + 12 * j, t + 10 * k);
		delay(d);
		line(l + 12 * j, t + 8 * k, l + 12 * j, t + 11 * k);
		delay(d);
		line(l + 12 * j, t + 8 * k, l + 13 * j, t + 8 * k);
		delay(d);
		line(l + 13 * j, t + 7 * k, l + 13 * j, t + 8 * k);
		delay(d);
		line(l + 13 * j, t + 7 * k, l + 14 * j, t + 7 * k);
		delay(d);

		line(l + 12 * j, t + 11 * k, l + 14 * j, t + 11 * k);
		delay(d);
		line(l + 14 * j, t + 11 * k, l + 14 * j, t + 13 * k);
		delay(d);
		line(l + 13 * j, t + 11 * k, l + 13 * j, t + 13 * k);
		delay(d);
		line(l + 12 * j, t + 12 * k, l + 13 * j, t + 12 * k);
		delay(d);
		line(l + 12 * j, t + 12 * k, l + 12 * j, t + 14 * k);
		delay(d);

		line(l + 11 * j, t + 13 * k, l + 12 * j, t + 13 * k);
		delay(d);
		line(l + 11 * j, t + 12 * k, l + 11 * j, t + 13 * k);
		delay(d);
		line(l + 11 * j, t + 12 * k, l + 7 * j, t + 12 * k);
		delay(d);
		line(l + 10 * j, t + 12 * k, l + 10 * j, t + 13 * k);
		delay(d);
		line(l + 8 * j, t + 11 * k, l + 8 * j, t + 12 * k);
		delay(d);
		line(l + 7 * j, t + 12 * k, l + 7 * j, t + 14 * k);
		delay(d);
		line(l + 3 * j, t + 14 * k, l + 8 * j, t + 14 * k);
		delay(d);

	cleardevice();
	settextstyle(4,0,6);	
	setcolor(BLUE);
	outtextxy(200,200,"YOU WON");
	w1.tune();
	cleardevice();
	sell.difflevel();
   
	}
	
	void win::won_mid()
      {
		 select sell;
		win w1;
		j = 40; // width     keep j & k equal or change the boundary matching codes for error free running
		k = 40; // height
		l, t, r, b;
		l = (615 - 15 * j) / 2;
		t = (460 - 8 * k) / 2;
		r = (615 - 15 * j) / 2 + 15 * j;
		b = (460 - 8 * k) / 2 + 8 * k;
		setcolor(BLACK);
		rectangle(l, t, r, b);

		
		line(l, t + 1, l, t + k);
		setcolor(BLACK);

		line(l, t + 1 * k, l + 3 * j, t + 1 * k);
		delay(50);
		line(l + 4 * j, t, l + 4 * j, t + 2 * k);
		delay(50);
		line(l + 4 * j, t + k, l + 5 * j, t + k);
		delay(50);
		line(l + 4 * j, t + 2 * k, l + j, t + 2 * k);
		delay(50);
		line(l + 3 * j, t + 2 * k, l + 3 * j, t + 7 * k);
		delay(50);
		line(l + j, t + 7 * k, l + 3 * j, t + 7 * k);
		delay(50);
		line(l, t + 3 * k, l + 2 * j, t + 3 * k);
		delay(50);
		line(l + 2 * j, t + 3 * k, l + 2 * j, t + 4 * k);
		delay(50);
		line(l + j, t + 4 * k, l + 2 * j, t + 4 * k);
		delay(50);
		line(l + j, t + 4 * k, l + j, t + 6 * k);
		delay(50);
		line(l + j, t + 6 * k, l + 2 * j, t + 6 * k);
		delay(50);
		line(l + 3 * j, t + 4 * k, l + 4 * j, t + 4 * k);
		delay(50);
		line(l + 3 * j, t + 6 * k, l + 4 * j, t + 6 * k);
		delay(50);
		line(l + 2 * j, t + 5 * k, l + 3 * j, t + 5 * k);
		delay(50);
		line(l + 6 * j, t + k, l + 6 * j, t + 2 * k);
		delay(50);
		line(l + 5 * j, t + 2 * k, l + 6 * j, t + 2 * k);
		delay(50);
		line(l + 5 * j, t + 2 * k, l + 5 * j, t + 7 * k);
		delay(50);
		line(l + 4 * j, t + 7 * k, l + 5 * j, t + 7 * k);
		delay(50);
		line(l + 4 * j, t + 7 * k, l + 4 * j, t + 8 * k);
		delay(50);
		line(l + 4 * j, t + 3 * k, l + 5 * j, t + 3 * k);
		delay(50);
		line(l + 5 * j, t + 4 * k, l + 7 * j, t + 4 * k);
		delay(50);
		line(l + 4 * j, t + 5 * k, l + 5 * j, t + 5 * k);
		delay(50);
		line(l + 7 * j, t, l + 7 * j, t + 3 * k);
		delay(50);
		line(l + 6 * j, t + 3 * k, l + 8 * j, t + 3 * k);
		delay(50);
		line(l + 8 * j, t + 2 * k, l + 8 * j, t + 5 * k);
		delay(50);
		line(l + 6 * j, t + 5 * k, l + 10 * j, t + 5 * k);
		delay(50);
		line(l + 6 * j, t + 5 * k, l + 6 * j, t + 7 * k);
		delay(50);
		line(l + 6 * j, t + 7 * k, l + 7 * j, t + 7 * k);
		delay(50);
		line(l + 7 * j, t + 7 * k, l + 7 * j, t + 6 * k);
		delay(50);
		line(l + 9 * j, t + 5 * k, l + 9 * j, t + 6 * k);
		delay(50);
		line(l + 10 * j, t + 5 * k, l + 10 * j, t + 4 * k);
		delay(50);
		line(l + 10 * j, t + 4 * k, l + 11 * j, t + 4 * k);
		delay(50);
		line(l + 8 * j, t + k, l + 10 * j, t + k);
		delay(50);
		line(l + 9 * j, t + k, l + 9 * j, t + 4 * k);
		delay(50);
		line(l + 10 * j, t + k, l + 10 * j, t + 2 * k);
		delay(50);
		line(l + 9 * j, t + 3 * k, l + 12 * j, t + 3 * k);
		delay(50);
		line(l + 12 * j, t + k, l + 12 * j, t + 5 * k);
		delay(50);
		line(l + 12 * j, t + 5 * k, l + 11 * j, t + 5 * k);
		delay(50);
		line(l + 11 * j, t + 5 * k, l + 11 * j, t + 6 * k);
		delay(50);
		line(l + 11 * j, t + 6 * k, l + 10 * j, t + 6 * k);
		delay(50);
		line(l + 10 * j, t + 6 * k, l + 10 * j, t + 7 * k);
		delay(50);
		line(l + 10 * j, t + 7 * k, l + 8 * j, t + 7 * k);
		delay(50);
		line(l + 8 * j, t + 6 * k, l + 8 * j, t + 8 * k);
		delay(50);
		line(l + 11 * j, t, l + 11 * j, t + 2 * k);
		delay(50);
		line(l + 13 * j, t, l + 13 * j, t + k);
		delay(50);
		line(l + 13 * j, t + k, l + 14 * j, t + k);
		delay(50);
		line(l + 12 * j, t + 4 * k, l + 13 * j, t + 4 * k);
		delay(50);
		line(l + 13 * j, t + 4 * k, l + 13 * j, t + 3 * k);
		delay(50);
		line(l + 12 * j, t + 2 * k, l + 14 * j, t + 2 * k);
		delay(50);
		line(l + 14 * j, t + 2 * k, l + 14 * j, t + 5 * k);
		delay(50);
		line(l + 14 * j, t + 5 * k, l + 13 * j, t + 5 * k);
		delay(50);
		line(l + 13 * j, t + 5 * k, l + 13 * j, t + 7 * k);
		delay(50);
		line(l + 14 * j, t + 7 * k, l + 12 * j, t + 7 * k);
		delay(50);
		line(l + 12 * j, t + 7 * k, l + 12 * j, t + 6 * k);
		delay(50);
		line(l + 14 * j, t + 6 * k, l + 15 * j, t + 6 * k);
		delay(50);
		line(l + 11 * j, t + 7 * k, l + 11 * j, t + 8 * k);
		delay(50);
		line(l + 15 * j, t + 7 * k, l + 15 * j, t + 8 * k - 1);

		cleardevice();
		settextstyle(4,0,6);
		setcolor(BLUE);
		outtextxy(200,200,"YOU WON");
		w1.tune();			// calling winning tune
		cleardevice();
		sell.difflevel();
  }   
  /*
  void win::won_easy()
	{
		select sell;
		win w1;
		setcolor(BLACK);
		d = 30;
		x = 0, y = 0;
		j = 40; 
		k = 40; 
		l, t, r, b;
		l = (615 - 10 * j) / 2;
		t = (460 - 8 * k) / 2;
		r = (615 - 10 * j) / 2 + 10 * j;
		b = (460 - 8 * k) / 2 + 8 * k;
		rectangle(l, t, r, b);
		line(l + 1 * j, t + 1 * k, l + 9 * j, t + 1 * k); delay(d);
		line(l + 2 * j, t + 2 * k, l + 3 * j, t + 2 * k); delay(d);
		line(l + 4 * j, t + 2 * k, l + 5 * j, t + 2 * k);delay(d);
		line(l + 7 * j, t + 2 * k, l + 9 * j, t + 2 * k);delay(d);
		line(l + 3 * j, t + 3 * k, l + 4 * j, t + 3 * k);delay(d);
		line(l + 6 * j, t + 3 * k, l + 7 * j, t + 3 * k);delay(d);
		line(l + 8 * j, t + 3 * k, l + 9 * j, t + 3 * k);delay(d);
		line(l + 4 * j, t + 4 * k, l + 8 * j, t + 4 * k);delay(d);
		line(l + 9 * j, t + 4 * k, l + 10 * j, t + 4 * k);delay(d);
		line(l + 5 * j, t + 5 * k, l + 6 * j, t + 5 * k); delay(d);
		line(l + 8 * j, t + 5 * k, l + 9 * j, t + 5 * k); delay(d);
		line(l + 1 * j, t + 6 * k, l + 2 * j, t + 6 * k); delay(d);
		line(l + 3 * j, t + 6 * k, l + 4 * j, t + 6 * k); delay(d);
		line(l + 5 * j, t + 6 * k, l + 9 * j, t + 6 * k); delay(d);
		line(l + 0 * j, t + 7 * k, l + 6 * j, t + 7 * k); delay(d);
		line(l + 7 * j, t + 7 * k, l + 8 * j, t + 7 * k); delay(d);
		line(l + 1 * j, t + 1 * k, l + 1 * j, t + 6 * k); delay(d);
		line(l + 2 * j, t + 3 * k, l + 2 * j, t + 6 * k); delay(d);delay(d);
		line(l + 3 * j, t + 2 * k, l + 3 * j, t + 6 * k);
		line(l + 4 * j, t + 4 * k, l + 4 * j, t + 5 * k); delay(d);
		line(l + 4 * j, t + 6 * k, l + 4 * j, t + 7 * k); delay(d);
		line(l + 5 * j, t + 2 * k, l + 5 * j, t + 4 * k); delay(d);
		line(l + 5 * j, t + 5 * k, l + 5 * j, t + 6 * k); delay(d);
		line(l + 6 * j, t + 1 * k, l + 6 * j, t + 3 * k); delay(d);
		line(l + 7 * j, t + 4 * k, l + 7 * j, t + 8 * k); delay(d);
		line(l + 8 * j, t + 2 * k, l + 8 * j, t + 4 * k); delay(d);
		line(l + 9 * j, t + 5 * k, l + 9 * j, t + 7 * k); delay(d);
		setcolor(GREEN);
		line(l + 0 * j, t + 7 * k, l + 0 * j, t+ 8 * k);
		cleardevice();
		settextstyle(4,0,6);	
		setcolor(BLUE);
		outtextxy(200,200,"YOU WON");
		w1.tune();
		cleardevice();
		sell.difflevel();
	}
*/
// ***  Winning Tune Starts From Here *** //
    void win::tune()
	{
		sound(1480);delay(200);nosound();
		sound(1568);delay(200);nosound();
		sound(1568);delay(200);nosound();
		sound(1568);delay(200);nosound();
		sound(739.99);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(369.99);delay(200);nosound();
		sound(392);delay(200);nosound();
		sound(369.99);delay(200);nosound();
		sound(392);delay(200);nosound();
		sound(392);delay(200);nosound();
		sound(196);delay(200);nosound();
		sound(739.99);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(739.99);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(739.99);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(880);delay(200);nosound();
		sound(830.61);delay(200);nosound();
		sound(880);delay(200);nosound();
		sound(987.77);delay(400);nosound();
		sound(880);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(698.46);delay(200);nosound();
		sound(739.99);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(739.99);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(739.99);delay(200);nosound();
		sound(783.99);delay(200);nosound();
		sound(880);delay(200);nosound();
		sound(830.61);delay(200);nosound();
		sound(880);delay(200);nosound();
		sound(987.77);delay(400);nosound();
	}
// ***  Winning Tune Ends From Here *** //
	
// *** Boundary voilation tone starts here *** //
	void check::voilate()
	{
				sound(200);
				delay(50);
				nosound();
	}
// *** Boundary voilation tone Ends here *** //
