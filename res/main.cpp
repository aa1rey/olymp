#include "fairy_tail.hpp"

#include <cstdlib>
#include <ctime>
#include "windows.h"
#include <iostream>

using namespace std;

Fairyland world;	// инициализация мира

Direction reservDirection; 
Direction frontDirection; // переменная прямого направления
Direction leftDirection; // переменная левого направления
Direction rightDirection; // переменная правого направления
Direction backDirection; // переменная заднего направления

const int width = 12;
const int height = 12;
char map[width][height];
int x = 1, y = 1;
int tailX[1000], tailY[1000];
int nTail;
int prevPosX = x, prevPosY = y - 1;

void rotateXY(Direction XY) {
	if (XY == Direction::Down) {
		prevPosY++;
		nTail++;
	}
	else if (XY == Direction::Right) {
		prevPosX++;
		nTail++;
	}
	else if (XY == Direction::Up) {
		prevPosY--;
		nTail++;
	}
	else if (XY == Direction::Left) {
		prevPosX--;
		nTail++;
	}
}

void DirXY(Direction XY) {
	if (XY == Direction::Down) {
		y++;
		prevPosY++;
		nTail++;
	}
	else if (XY == Direction::Right) {
		x++;
		prevPosX++;
		nTail++;
	}
	else if (XY == Direction::Up) {
		y--;
		prevPosY--;
		nTail++;
	}
	else if (XY == Direction::Left) {
		x--;
		prevPosX--;
		nTail++;
	}
}

void qqqDraw() {
	system("cls"); // обновление 

	// верхняя граница
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;

	// само поле
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			// отображаем вертикальные границы
			if (j == 0 || j == width - 1)
				cout << "#";

			// Иван
			else if (i == y && j == x)
				cout << '@';

			// Елена
			else if (i == 10 && j == 10)
				cout << '&';

			// отображаем хвост
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						print = true;
						cout << ".";
					}
				}
				if (!print)
					cout << "?";
			}
		}
		cout << endl;
	}

	// нижняя граница
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;
}

void Draw() {
	system("cls");

	// границы карты, неизвестные ячейки, персонажи и пройденый путь
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {

			// границы
			if (i == 0 || i == 11 || j == 0 || j == 11)
				map[i][j] = ' ';

			// Иван
			else if (i == y && j == x)
				map[y][x] = '@';

			// Елена
			else if (i == 10 && j == 10)
				map[i][j] = '&';

			// пройденый путь
			else if ((i != 0 || i != 11 || j != 0 || j != 11) || (i != y && j != x) || (i != 10 && j != 10))
				for (int k = 0; k < nTail; k++)
					if (tailX[k] == j && tailY[k] == i)
						map[i][j] = '.';

			cout.width(2);
			cout << map[i][j];
		}
		cout << endl;
	}

}

int walk() {
	int s = 0;
	
	// Назначаем прямое, левое, правое и заднее направления, исходя из того, куда можем пойти
	{
		if (world.canGo(Character::Ivan, Direction::Right) && world.canGo(Character::Ivan, Direction::Up) && world.canGo(Character::Ivan, Direction::Down)) {
			frontDirection = Direction::Up;
			leftDirection = Direction::Left;
			rightDirection = Direction::Right;
			backDirection = Direction::Down;
		}
		else if (world.canGo(Character::Ivan, Direction::Down)) {
			frontDirection = Direction::Down;
			leftDirection = Direction::Right;
			rightDirection = Direction::Left;
			backDirection = Direction::Up;
		}
		else if (world.canGo(Character::Ivan, Direction::Left)) {
			frontDirection = Direction::Left;
			leftDirection = Direction::Down;
			rightDirection = Direction::Up;
			backDirection = Direction::Right;
		}
		else if (world.canGo(Character::Ivan, Direction::Up)) {
			frontDirection = Direction::Up;
			leftDirection = Direction::Left;
			rightDirection = Direction::Right;
			backDirection = Direction::Down;
		}
		else if (world.canGo(Character::Ivan, Direction::Right)) {
			frontDirection = Direction::Right;
			leftDirection = Direction::Up;
			rightDirection = Direction::Down;
			backDirection = Direction::Left;
		}
	}
	/*
Карта лабиринта:

@#####....
.#...#....
.#...#...#
.#.#.#.#.#
.#.#.#.#..
.#.#.#.##.
.#.#.#.#..
...#.#.#.#
...#.#.#..
...#...#.&

*/

	while (!world.go(Direction::Pass, Direction::Pass)) {
		s++;
		Draw();
		{
			int prevX = tailX[0];
			int prevY = tailY[0];
			int prev2X, prev2Y;
			tailX[0] = x;
			tailY[0] = y;


			for (int i = 1; i < nTail; i++) {
				prev2X = tailX[i];
				prev2Y = tailY[i];
				tailX[i] = prevX;
				tailY[i] = prevY;
				prevX = prev2X;
				prevY = prev2Y;

			}
			

			if (!world.canGo(Character::Ivan, leftDirection) && world.canGo(Character::Ivan, frontDirection)) { // слева занято, прямо свободно
				
				world.go(frontDirection, Direction::Pass);

				DirXY(frontDirection);

				while (!world.canGo(Character::Ivan, leftDirection) && world.canGo(Character::Ivan, frontDirection)) {
					world.go(frontDirection, Direction::Pass);

					DirXY(frontDirection);
				}

				// разворачиваемся влево:

				rotateXY(frontDirection);

				reservDirection = frontDirection;
				frontDirection = leftDirection;
				leftDirection = backDirection;
				backDirection = rightDirection;
				rightDirection = reservDirection;

			}

			else if (world.canGo(Character::Ivan, leftDirection) && world.canGo(Character::Ivan, frontDirection)) {  // слева свободно, прямо свободно

				world.go(frontDirection, Direction::Pass);
				DirXY(frontDirection);

				while (!world.canGo(Character::Ivan, leftDirection) && world.canGo(Character::Ivan, frontDirection)) {
					world.go(frontDirection, Direction::Pass);
					DirXY(frontDirection);
				}

				// разворачиваемся влево:

				rotateXY(frontDirection);

				reservDirection = frontDirection;
				frontDirection = leftDirection;
				leftDirection = backDirection;
				backDirection = rightDirection;
				rightDirection = reservDirection;

				if (world.canGo(Character::Ivan, frontDirection)) {
					world.go(frontDirection, Direction::Pass);
					DirXY(frontDirection);
				}
			}

			else if (world.canGo(Character::Ivan, leftDirection) && !world.canGo(Character::Ivan, frontDirection)) { // слева свободно, прямо занято

				rotateXY(frontDirection);

				reservDirection = frontDirection;
				frontDirection = backDirection;
				backDirection = reservDirection;

				reservDirection = leftDirection;
				leftDirection = rightDirection;
				rightDirection = reservDirection;
			}

			else if (!world.canGo(Character::Ivan, leftDirection) && !world.canGo(Character::Ivan, frontDirection)) { // слева занято, прямо занято

				// разворот влево на 270 градусов

				rotateXY(frontDirection);

				reservDirection = frontDirection;
				frontDirection = rightDirection;
				rightDirection = backDirection;
				backDirection = leftDirection;
				leftDirection = reservDirection;

			}
		}
		Sleep(1);
	}
	if ((world.getTurnCount() - (s + 1)) > 250)
		return 0;
	else
		return world.getTurnCount() - (s + 1);
}

int main()
{
	setlocale(LC_ALL, "RUS");

	if (const int turns = walk())
		cout << "Found in " << turns << " turns" << endl;
	else if (walk() == 0)
		cout << "Not found" << endl;
	
	return 0;
}
