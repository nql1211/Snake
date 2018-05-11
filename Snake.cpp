#include "Snake.h"

// khởi tạo rắn, thức ăn và điểm
void SetUp(Snake &snake, Fruit &fruit, int &score)
{

	snake.soDot = 3;
	snake.dot[0].x = 4;
	snake.dot[0].y = 2;
	snake.dot[1].x = 3;
	snake.dot[1].y = 2;
	snake.dot[2].x = 2;
	snake.dot[2].y = 2;
	score = 0;
	fruit.td.x = 20;
	fruit.td.y = 20;
	snake.tt = RIGHT;
	 bool gameOver = false;
}
void Draw(Snake snake, Fruit fruit, int score)
{
	// Vẽ Biên
	resizeConsole(700, 600);
	for (int i = 0; i < consoleWidth; i++)
	{
		for (int j = 0; j < consoleHeight; j++)
		{
			TextColor(ColorCode_DarkGreen);
			gotoXY(i, j);
			if (i == 0 || j == 0 || i == consoleWidth - 1 || j == consoleHeight - 1)
				cout << char(164);
		}
	}
	// in thức ăn
	TextColor(1 + rand() % 14);
	gotoXY(fruit.td.x, fruit.td.y);
	cout << char(64);
	// in con rắn
	for (int i = 0; i < snake.soDot; i++)
	{
		TextColor(ColorCode_Yellow);
		gotoXY(snake.dot[i].x, snake.dot[i].y);
		cout << char(169);
	}
	// xóa đuôi
	for (int i = snake.soDot; i > 0; i--)
	{
		gotoXY(snake.dot[i].x, snake.dot[i].y);
		cout << " ";
		break;
	}
	//in điểm và cách chơi
	TextColor(ColorCode_Cyan);
	gotoXY(2, 26);
	cout << "Score: " << score;
	TextColor(ColorCode_White);
	gotoXY(2, 27);
	cout << "Use four buttons: UP, DOWN, LEFT, RIGHT to control";
}

// hàm điểu khiển di chuyển
void Input_Control(Snake &snake)
{
	// truyền trạng thái cho đốt sau
	for (int i = snake.soDot; i > 0; i--)
	{
		snake.dot[i] = snake.dot[i - 1];
	}
	if (_kbhit())//phát hiện có phím nhấn vào
	{
		int key = _getch();
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (snake.tt != RIGHT)
				snake.tt = LEFT;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (snake.tt != UP)
				snake.tt = DOWN;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (snake.tt != LEFT)
				snake.tt = RIGHT;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			if (snake.tt != DOWN)
				snake.tt = UP;
		}

	}

	if (snake.tt == UP)
		snake.dot[0].y--;
	else if (snake.tt == DOWN)
		snake.dot[0].y++;
	else if (snake.tt == LEFT)
		snake.dot[0].x-=2;
	else if (snake.tt == RIGHT)
		snake.dot[0].x+=2;
}

void Logic(Snake &snake, Fruit &fruit, int &timeSleep, bool &gameOver, int &score)
{
	// rắn va chạm biên
	if (snake.dot[0].x <= 0 || snake.dot[0].x >= consoleWidth - 1 ||
		snake.dot[0].y <= 0 || snake.dot[0].y >= consoleHeight - 1)
		gameOver = true;
	// rắn cắn thân
	for (int i = 1; i < snake.soDot; i++)
		if (snake.dot[0].x == snake.dot[i].x &&
			snake.dot[0].y == snake.dot[i].y)
			gameOver = true;
	// rắn ăn quả
	if (snake.dot[0].x == fruit.td.x &&
		snake.dot[0].y == fruit.td.y)
	{
		snake.soDot++;
		score += 10;
		for (int i = snake.soDot; i > 0; i--)
			snake.dot[i] = snake.dot[i - 1];
		fruit.td.y = 1 + rand() % (consoleHeight - 2);
		fruit.td.x = 1 + rand() % (consoleWidth - 2);
	
	}
	if (score >= 50 && timeSleep >=2 )
	{
		timeSleep -= 2;
	}
}