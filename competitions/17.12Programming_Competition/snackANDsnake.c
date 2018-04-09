/* THIS FILE IS USING ONLY FOR PROGRAMING COMPETITION(BEIJING, BJUT, BDIC)
 * snackANDsnake.c - source file of a little game which is called in same name
 * Forbid revising in principal
 * Could connect me by mitchellax2333@outlook.com
 */

/* Cos I don`t know if WIN32 frame is accepted
 * I don`t write with GDI API but use only crude symbols
 * Orignally, I want to make this game have lots differences with Retro Snaker
 * Limiting by cmd (can only output by stream but draw on window)
 * In fact, there are also some little bugs but I have no time to fix it
 * This work is just so so
 * Hope you could have a good time with this little game
 */

/* EXPRESSING TABLE
 * Using '*' to express the nodes of snake
 * Using '@' to express the foods
 * Using '#' to express the foods which is overdued
 * Using '$' to express the wall
 * Pressing left arrow '<-' to turn snake left
 * Pressing right arrow '->' to turn snake right
 * Pressing ESC to quit game
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>


#define SIDE_LOOG 30
#define DISTANCE 1
#define MAXLEVEL 10
#define LEFT 75
#define RIGHT 77
#define ESC 27

typedef short status;

const double PI = 3.1415926;

const int ORIGINSPEED = 30;
const int ORIGINLEVEL = 1;
const int ORIGINFOODVALUE = 10;
const int ORIGINFOODAPP = 4;
const int ORIGINFOODOVER = 20;
const int ORIGINFOODDIS = 16;

const int HEIGHT_TEXT = 5;
//const int NODESIZE = 2;
//const int ONEPRESS = 90;


int i;
int NoWrong;
int snake_direction;
int score;
int level;
int speed;
int situation;
int _node;
status _END;
//status ErrorHappen = 0;
status GameOver;
char StrStream[SIDE_LOOG * (SIDE_LOOG + 1)];

struct snakenode
{
	int x;
	int y;
	short if_exsit;
}snake[SIDE_LOOG * SIDE_LOOG];

struct food
{
	int x;
	int y;
	int time;
	short if_exsit;
}foods[MAXLEVEL];

void PreGameWords(void);//status: 0

void PutInStream(int x, int y, char ch);//status: 1

void IniSnake(void);//status: 2

void IniFood(void);//status: 3

void IniWall(void);//status: 4

void SnakeMove(void);//status: 5

void FoodApDisap(void);//status: 6

void test(void);//status: 7

void PutOutStream(void);//status: 8

void KeyPress(void);

//void CastWrong(void);


int main(int argc, char const *argv[])
{ 
	while(1)
	{
		system("cls");
		snake_direction = 90;
		score = 0;
		level = ORIGINLEVEL;
		speed = ORIGINSPEED;
		situation = 0;
		_node = 3;
		GameOver = 0;
		_END = 0;
		//int NoWrong = 1;
		srand((int)time(NULL));
		char Request = NULL;
		for (i = 0; i < SIDE_LOOG * SIDE_LOOG; ++i)
			StrStream[i] = ' ';
		while(!_END)
		{
			switch(situation)
			{
				case 0:
					PreGameWords();
					situation = 1;
					break;
				case 1:
					system("cls");
					IniSnake();
					IniWall();
					IniFood();
					situation = 2;
					break;
				case 2:
					system("cls");
					FoodApDisap();
					SnakeMove();
					PutOutStream();
					if(GameOver)
						_END = 1;
					Sleep(10000 / speed);
					break;
			}
		}
		system("cls");
		printf("Your score is: %d\n", score);
		printf("Game Over\n");
		printf("Do you want to play angin? (y / n)    \n");
		while(!scanf("%c", &Request) && (Request != 'y' || Request != 'n'))
			printf("Maybe you input a wrong thing, try angin.\n");
		if(Request == 'n')
			break;
	}
	return 0;
}

void PreGameWords(void)
{
	int i, i_t;
	char array[4] = "-/|\\";
	printf("Using '*' to express the snake of snake\n");
	printf("Using '@' to express the foods\n");
 	printf("Using '#' to express the foods which is overdued\n");
	printf("Using '$' to express the wall\n\n");
	printf("Press the left arrow (<-) to make snake turn left\n");
	printf("Press the right arrow (->) to make snake turn right\n\n");
	printf("Please click the maximization button of cmd/exe\n");
	printf("----------------------------------------------------\n");
	printf("                 snackANDsnake.exe             -|_|X\n");
	printf("----------------------------------------------------\n");
	printf("                                                 ^\n");
	printf("                                                 |\n");
	printf("                                            click here\n\n");
 	printf("Tip: Don`t make a food feel lonely\n\n");
	for (i = 1; i <= 50; i++)
	{
		printf("Waiting for your reading   ");
		printf(" %c  ", array[i % 4]);
		for (i_t = 0; i_t < i / 5; i_t++)
			printf("*");
		for (i_t = 0; i_t < 10 - (i / 5); i_t++)
			printf("-");
		Sleep(100);
		printf("\r");
	}
	//return 0;
}

void PutInStream(int x, int y, char ch)
{
	StrStream[(SIDE_LOOG + 1) * y + x] = ch;
	//return 1;
}


void IniSnake(void)
{
	snake[0].x = SIDE_LOOG / 2;
	snake[0].y = SIDE_LOOG / 2;
	for (i = 0; i < _node; i++)
		snake[i].if_exsit = 1;
	for (i = 1; i < _node; i++)
	{
		//snake_direction = rand() % 180;
		//snake[i].x = snake[i - 1].x + (int)(DISTANCE * sin((snake_direction / 180) * PI));
		//snake[i].y = snake[i - 1].y + (int)(DISTANCE * cos((snake_direction / 180) * PI));
		snake_direction = rand() % 4;
		if(snake_direction == 0)
			snake[i].y = snake[i - 1].y + DISTANCE;//DOWN
		else if(snake_direction == 1)
			snake[i].x = snake[i - 1].x - DISTANCE;//LEFT
		else if(snake_direction == 2)
			snake[i].y = snake[i - 1].y - DISTANCE;//UP
		else
			snake[i].x = snake[i - 1].x + DISTANCE;//RIGHT
	}
	//return 2;
}

void IniFood(void)
{
	for (i = 0; i < level; i++)
	{
		foods[i].x = rand() % (SIDE_LOOG - 2) + 1;
		foods[i].y = rand() % (SIDE_LOOG - 2) + 1;
		foods[i].if_exsit = 1;
	}
	//return 3;
}

void IniWall(void)
{
	for(i = 0; i < SIDE_LOOG; i++)
	{
		PutInStream(i, 0, '$');
		PutInStream(i, SIDE_LOOG - 1, '$');
		
	}
	for (i = 0; i < SIDE_LOOG - 1; ++i)
	{
		PutInStream(0, i, '$');
		PutInStream(SIDE_LOOG - 1, i, '$');
		PutInStream(SIDE_LOOG, i, '\n');
	}
	//return 4;
}

void SnakeMove(void)
{
	KeyPress();
	PutInStream(snake[_node - 1].x, snake[_node - 1].y, ' ');
	for(i = _node; i > 0; i--)
	{
		snake[i].x = snake[i-1].x;
		snake[i].y = snake[i-1].y;
	}
	test();
	KeyPress();
	//snake[0].x = snake[1].x + (int)(DISTANCE * cos(snake_direction / 180) * PI);
	//snake[0].y = snake[1].y + (int)(DISTANCE * sin(snake_direction / 180) * PI);
	if(!GameOver)
	{
		if(snake_direction == 0)
			snake[0].y = snake[1].y + DISTANCE;
		else if(snake_direction == 1)
			snake[0].x = snake[1].x - DISTANCE;
		else if(snake_direction == 2)
			snake[0].y = snake[1].y - DISTANCE;
		else
			snake[0].x = snake[1].x + DISTANCE;
		for(i = 1; i < _node; i++)
			PutInStream(snake[i].x, snake[i].y, '*');
	}
	switch(snake_direction)
	{
		case 1:
			PutInStream(snake[0].x, snake[0].y, '<');
			break;
		case 2:
			PutInStream(snake[0].x, snake[0].y, '^');
			break;
		case 3:
			PutInStream(snake[0].x, snake[0].y, '>');
			break;
		case 0:
			PutInStream(snake[0].x, snake[0].y, '.');
			break;
	}
	snake[_node - 1].if_exsit = 1;
	//return 5;
}

void FoodApDisap(void)
{
	for (i = 0; i < level; ++i)
	{
		if(foods[i].if_exsit == 1)
		{
			PutInStream(foods[i].x, foods[i].y, '@');
			if(rand() % (ORIGINFOODOVER - level) == 0)
				foods[i].if_exsit = -1;
		}
		else if(foods[i].if_exsit == -1)
		{
			PutInStream(foods[i].x, foods[i].y, '#');
			if(rand() % (ORIGINFOODDIS + level) == 0)
				foods[i].if_exsit = 0;
		}
		else
		{
			PutInStream(foods[i].x, foods[i].y, ' ');
			foods[i].x = rand() % (SIDE_LOOG - 2) + 1;
			foods[i].y = rand() % (SIDE_LOOG - 2) + 1;
			if(rand() % (int)(ORIGINFOODAPP - level / 2) == 0)
				foods[i].if_exsit = 1;
		}
	}
	//return 6;	
}

void test(void)
{
	//test with food
	for (i = 0; i < level; i++)
	{
		//if((foods[i].x - snake[1].x) * (snake[0].y - snake[1].y) - (foods[i].y - snake[1].y) * (snake[0].x - snake[1].x) == 0)
		if(foods[i].x == snake[0].x && foods[i].y == snake[0].y)
		{
			if(foods[i].if_exsit == 1)
			{
				foods[i].if_exsit = 0;
				foods[i].x = rand() % (SIDE_LOOG - 2) + 1;
				foods[i].y = rand() % (SIDE_LOOG - 2) + 1;
				score += ORIGINFOODVALUE;
				_node++;
			}
			else if(foods[i].if_exsit == -1)
			{
				foods[i].if_exsit = 0;
				foods[i].x = rand() % (SIDE_LOOG - 2) + 1;
				foods[i].y = rand() % (SIDE_LOOG - 2) + 1;
				score -= level * ORIGINFOODVALUE;
				level++;
				_node++;
				speed = level * ORIGINSPEED;
			}
		}
	}
	//test with wall
	if(snake[0].x < 1 || snake[0].x > SIDE_LOOG - 2 || snake[0].y < 1 || snake[0].y > SIDE_LOOG - 2)
		GameOver = 1;
	//test with snack
	for (i = 2; i < _node; i++)
	{
		//if((snake[i].x - snake[1].x) * (snake[0].y - snake[1].y) - (snake[i].y - snake[1].y) * (snake[0].x - snake[1].x))
			//GameOver = 1;
		if(snake[i].x == snake[0].x && snake[i].y == snake[0].y)
			GameOver = 1;
	}
	//test with level
	if(ORIGINFOODOVER <= level)
		GameOver = 1;
	//return 7;
}

void PutOutStream(void)
{
	printf("Level:  %d\n", level);
	printf("Score:  %d\n", score);
	for (i = 0; i < HEIGHT_TEXT - 1; ++i)
		putchar('\n');
	for (i = 0; i < SIDE_LOOG * (SIDE_LOOG + 1) - 1; ++i)
	{
		putchar(StrStream[i]);
		putchar(' ');
	}
	//return 8;
}

void KeyPress(void)
{
	if(kbhit())
	{
		char ch = getch();
		switch(ch)
		{
			case LEFT:
				snake_direction--;
				if(snake_direction < 0)
					snake_direction = 3;
				break;
			case RIGHT:
				snake_direction++;
				if(snake_direction > 3)
					snake_direction = 0;
				break;
			case ESC:
				GameOver = 1;
				break;
		}
	}
}