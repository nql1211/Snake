#pragma once

#include "console.h"


enum trangThai { UP, DOWN, LEFT, RIGHT};


struct toaDo
{
	int x, y;	// y là tung độ, x là hoành độ
};

struct Fruit
{
	toaDo td;
};
struct Snake
{
	toaDo dot[100];
	int soDot;
	trangThai tt;
	int score;
};

void SetUp(Snake &snake, Fruit &fruit, int &score);
void Draw(Snake snake, Fruit fruit, int score);
void Input_Control(Snake &snake);
void Logic(Snake &snake, Fruit &fruit, int &timeSleep, bool &gameOver, int &score);
