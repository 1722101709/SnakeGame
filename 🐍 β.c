#include<iostream>
#include<conio.h>
using namespace std;
bool gameover;
int x,y,fruitx,fruity,score;
const int width=25;
const int height=25;
enum eDirections{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirections dir;
int tailx[100];
int taily[100];
int tailnum;
void setup()
{
	gameover=false;
	x=width/2;
	y=height/2;
	fruitx=rand() % width;
	fruity=rand() % height;
	score=0;
}
void draw()
{
	system("cls");
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(i==0 || j==0 || j==width-1|| i==height-1 )
			{
				cout<<"X";
			}
		else	if(i==y && j==x)
			{
				cout<<"O";
			}
			else if(i==fruity && j==fruitx)
				{
					cout<<"F";
				}
				else
				{
					bool print =false;
					for(int k=0;k<tailnum;k++)
					{
						if(j==tailx[k] && i==tailx[k])
						{
				          cout<<"O";
				          print=true;
				        }
	             	}
	             	if(!print)
	             	{
				     	cout<<" ";
				     }
				}
	        	}
			cout<<endl;
	}
	cout<<"SCORE="<<score<<endl;
}
void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'l' :
			{
			dir=LEFT;
			break;
			}
			case 'r' :
			{
			dir=RIGHT;
			break;
			}
			case 'u' :
			{
			dir=UP;
			break;
			}
			case 'd' :
			{
			dir=DOWN;
			break;
			}
			case 'q' :
			{
			gameover=true;
			break;
			}
		}
	}
}
void logic()
{
	tailx[0]=x;
	taily[0]=y;
	int prevx=tailx[0];
	int prevy=taily[0];
	
	for(int i=1;i<tailnum;i++)
	{
		int prev2x=tailx[i];
		int prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
	switch(dir)
	{
		case LEFT :
		x--;
		break;
		case RIGHT :
		x++;
		break;
		case UP :
		y--;
		break;
		case DOWN :
		y++;
		break;
		default :
		break;
	}
	if(x>=width || x<=0 || y>=height || y<=0)
	{
		gameover=true;
	}
	if(fruitx==x && y==fruity)
	{
		score++;
		fruitx=rand() % width;
	    fruity=rand() % height;
	     tailnum++;
	}
}
int main()
{
	setup();
	while(!gameover)
	{
		draw();
		input();
		logic();
		sleep(1);
	}
	return 0;
}
