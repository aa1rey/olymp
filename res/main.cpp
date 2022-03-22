#include "fairy_tail.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Fairyland world; // инициализация мира

int walk() {
	int s = 0;
	Direction reservDirection;
	Direction frontDirection; // переменная прямого направления
	Direction leftDirection; // переменная левого направления
	Direction rightDirection; // переменная правого направления
	Direction backDirection; // переменная заднего направления

		// Назначаем прямое, левое, правое и заднее направления, исходя из того, куда можем пойти

	if (world.canGo(Character::Ivan, Direction::Right) == true && world.canGo(Character::Ivan, Direction::Up) == true && world.canGo(Character::Ivan, Direction::Down) == true) {
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

	while (world.go(Direction::Pass, Direction::Pass) == false) {

		s++;

		if (!world.canGo(Character::Ivan, leftDirection) == true && world.canGo(Character::Ivan, frontDirection) == true) { // слева занято, прямо свободно

			world.go(frontDirection, Direction::Pass);

			while (!world.canGo(Character::Ivan, leftDirection) == true && world.canGo(Character::Ivan, frontDirection) == true) {
				world.go(frontDirection, Direction::Pass);
			}

			// разворачиваемся влево:

			reservDirection = frontDirection;
			frontDirection = leftDirection;
			leftDirection = backDirection;
			backDirection = rightDirection;
			rightDirection = reservDirection;

		}

		else if (world.canGo(Character::Ivan, leftDirection) == true && world.canGo(Character::Ivan, frontDirection) == true) {  // слева свободно, прямо свободно



			world.go(frontDirection, Direction::Pass);

			while (!world.canGo(Character::Ivan, leftDirection) == true && world.canGo(Character::Ivan, frontDirection) == true) {
				world.go(frontDirection, Direction::Pass);
			}

			// разворачиваемся влево:

			reservDirection = frontDirection;
			frontDirection = leftDirection;
			leftDirection = backDirection;
			backDirection = rightDirection;
			rightDirection = reservDirection;

			if (world.canGo(Character::Ivan, frontDirection) == true) {
				world.go(frontDirection, Direction::Pass);
			}
		}

		else if (world.canGo(Character::Ivan, leftDirection) == true && !world.canGo(Character::Ivan, frontDirection) == true) { // слева свободно, прямо занято

			reservDirection = frontDirection;
			frontDirection = backDirection;
			backDirection = reservDirection;

			reservDirection = leftDirection;
			leftDirection = rightDirection;
			rightDirection = reservDirection;
		}

		else if (!world.canGo(Character::Ivan, leftDirection) == true && !world.canGo(Character::Ivan, frontDirection) == true) { // слева занято, прямо занято

					// разворот влево на 270 градусов

			reservDirection = frontDirection;
			frontDirection = rightDirection;
			rightDirection = backDirection;
			backDirection = leftDirection;
			leftDirection = reservDirection;


		}
	}
	if ((world.getTurnCount() - (s + 1)) > 250)
		return 0;
	else
		return world.getTurnCount() - (s + 1);
}

int main()
{


	if (const int turns = walk())
		cout << "Found in " << turns << " turns" << endl;
	else if (walk() == 0)
		cout << "Not found" << endl;

	return 0;
}
