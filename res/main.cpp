#include "fairy_tail.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Fairyland world; // инициализация мира

int walk() {

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

*/

	for (int i = 0; i < 23; i++) { // находит за 23 цикла

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

			world.go(frontDirection, Direction::Pass);

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

			reservDirection = frontDirection;
			frontDirection = rightDirection;
			rightDirection = backDirection;
			backDirection = leftDirection;
			leftDirection = reservDirection;

		}

		cout << world.getTurnCount() << endl;
		
	}
	cout << world.getTurnCount() << endl;
	return 0;
}

int main()
{

	if (const int turns = walk())
		std::cout << "Found in " << turns << " turns" << std::endl;
	else
		std::cout << "Not found" << std::endl;

	return 0;
}