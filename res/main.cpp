#include "fairy_tail.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Fairyland world; // инициализация мира

int move() {

	for (int i = 0; i < 1; i++) {

		Direction leftDirection; // переменная левого направления

		// Назначаем левое направление, исходя из того, куда можем пойти

		if (world.canGo(Character::Ivan, Direction::Down)) {
			leftDirection = Direction::Right;
		}
		else if (world.canGo(Character::Ivan, Direction::Left)) {
			leftDirection = Direction::Down;
		}
		else if (world.canGo(Character::Ivan, Direction::Up)) {
			leftDirection = Direction::Left;
		}
		else if (world.canGo(Character::Ivan, Direction::Right)) {
			leftDirection = Direction::Up;
		}

		Direction frontDirection; // переменная прямого направления

		// Назначаем прямое направление, исходя из того, куда можем пойти

		if (world.canGo(Character::Ivan, Direction::Down)) {
			frontDirection = Direction::Down;
		}
		else if (world.canGo(Character::Ivan, Direction::Left)) {
			frontDirection = Direction::Left;
		}
		else if (world.canGo(Character::Ivan, Direction::Up)) {
			frontDirection = Direction::Up;
		}
		else if (world.canGo(Character::Ivan, Direction::Right)) {
			frontDirection = Direction::Right;
		}

		Direction rightDirection; // переменная правого направления

		// Назначаем правое направление, исходя из того, куда можем пойти

		if (world.canGo(Character::Ivan, Direction::Down)) {
			rightDirection = Direction::Left;
		}
		else if (world.canGo(Character::Ivan, Direction::Left)) {
			rightDirection = Direction::Up;
		}
		else if (world.canGo(Character::Ivan, Direction::Up)) {
			rightDirection = Direction::Right;
		}
		else if (world.canGo(Character::Ivan, Direction::Right)) {
			rightDirection = Direction::Down;
		}

		Direction backDirection; // переменная заднего направления

		// Назначаем заднее направление, исходя из того, куда можем пойти

		if (world.canGo(Character::Ivan, Direction::Down)) {
			backDirection = Direction::Up;
		}
		else if (world.canGo(Character::Ivan, Direction::Left)) {
			backDirection = Direction::Right;
		}
		else if (world.canGo(Character::Ivan, Direction::Up)) {
			backDirection = Direction::Down;
		}
		else if (world.canGo(Character::Ivan, Direction::Right)) {
			backDirection = Direction::Left;
		}

		// пока не можем пойти налево, идем прямо

		while (!world.canGo(Character::Ivan, leftDirection)) {
			world.go(frontDirection, Direction::Pass);
		}

		if (world.canGo(Character::Ivan, leftDirection)) {
			world.go(leftDirection, Direction::Pass);
		}

		Direction reservDirection = rightDirection;
		rightDirection = frontDirection;
		frontDirection = leftDirection;
		leftDirection = backDirection;
		backDirection = reservDirection;

		// хочу запретить ему рассматривать поворот направо и назад. но у меня не получается понять как это сделать. Ниже по логике написал, как думал можно. Но Visual Studio выебывается.
		// функцию canGo() типа bool нельзя изменить, потому что как я понял, она является константой. Но как тогда запретить ему проверять, может ли он пойти назад или вправо? 

		if (world.canGo(Character::Ivan, rightDirection)) {
			world.canGo(Character::Ivan, rightDirection) = false;

		}

			

	}
	return 0;
}

int main() {

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