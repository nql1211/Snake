#include "console.h"
#include "Snake.h"
#include "Menu.h"


void playGame()
{
	srand(time(NULL)); // khởi tạo bộ sinh số ngẫu nhiên

	Snake snake;
	Fruit fruit;
	int sc = 0, score = 0;
	SetUp(snake, fruit, score);
	int timeSleep = 10;
	bool gameOver = false;
	//int score = 0;

	while (!gameOver)
	{
		anConTro();

		Draw(snake, fruit, score);

		Input_Control(snake);

		Logic(snake, fruit, timeSleep, gameOver, score);

		Sleep(timeSleep);

		if (gameOver)
		{
			gotoXY(2, 25);
			cout << "Game over. Your score: " << score << endl;
			cout << "  Press ENTER to exit" << endl;
			while (_getch() != 13);
			break;
		}
	}
}



int main()
{
	menuDisplay();
	clrscr();
	playGame();
	//system("pause");
	return 0;
}
