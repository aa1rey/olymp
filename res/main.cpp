#include "fairy_tail.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;



Fairyland world; // инициализация мира



int move() {
	system("chcp 1251>nul");

	Direction reservDirection;
	Direction frontDirection; // переменная прямого направления
	Direction leftDirection; // переменная левого направления
	Direction rightDirection; // переменная правого направления
	Direction backDirection; // переменная заднего направления

		// Назначаем прямое, левое, правое и заднее направления, исходя из того, куда можем пойти

	if (world.canGo(Character::Ivan, Direction::Down)) {
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




Как я думал, он двигается:

Собакой(@) обозначено его перемещение.

@#####....
@#...#....
@#...#...#
@#.#.#.#.#
@#.#.#.#..
@#.#.#.##.
@#@#.#.#..
@@@#.#.#.#
...#.#.#..
...#...#.&

Как на деле получается:

@#####....
@#...#....
@#...#...#
@#.#.#.#.#
@#.#.#.#..
@#.#.#.##.
@#.#.#.#..
@..#.#.#.#
@@.#.#.#..
.@.#...#.&

*/

	for (int i = 0; i < 3; i++) {

		
		
		if (!world.canGo(Character::Ivan, leftDirection) == true && world.canGo(Character::Ivan, frontDirection) == true) {

			world.go(frontDirection, Direction::Pass);

			while (!world.canGo(Character::Ivan, leftDirection) == true && world.canGo(Character::Ivan, frontDirection) == true) {
				world.go(frontDirection, Direction::Pass);
			}

			// разворачиваемся влево:

			reservDirection = rightDirection;
			rightDirection = frontDirection;
			frontDirection = leftDirection;
			leftDirection = backDirection;
			backDirection = reservDirection;

		}

		else if (world.canGo(Character::Ivan, leftDirection) == true && world.canGo(Character::Ivan, frontDirection) == true) {

			

			world.go(frontDirection, Direction::Pass);

			while (!world.canGo(Character::Ivan, leftDirection) == true && world.canGo(Character::Ivan, frontDirection) == true) {
				world.go(frontDirection, Direction::Pass);
			}

			// разворачиваемся влево:

			reservDirection = rightDirection;
			rightDirection = frontDirection;
			frontDirection = leftDirection;
			leftDirection = backDirection;
			backDirection = reservDirection;

			world.go(leftDirection, Direction::Pass);

		}

		// я думал, что после каждого условия измененные направления сохрняются, но при каждом новом цикле значения обновляются до дефолтных, т.е. те, которые заданы вне цикла.

	}
	return 0;
}

int main() {
	system("chcp 1251>nul");

	// проверяем нашли ли Ivan и Elena друг друга

	bool meet = move();
	if (meet) {
		cout << "Found in: " << world.getTurnCount() << endl;
	}
	else {
		cout << "Not found. " << world.getTurnCount() << endl;
	}
	return 0;
}




/*

RLD
RLU
RDU

LDU

DU
DR
DL

UR
UL

RL

L
R
D
U


*/