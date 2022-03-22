#include "fairy_tail.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Fairyland world; // ������������� ����

int walk() {

	Direction reservDirection;
	Direction frontDirection; // ���������� ������� �����������
	Direction leftDirection; // ���������� ������ �����������
	Direction rightDirection; // ���������� ������� �����������
	Direction backDirection; // ���������� ������� �����������

		// ��������� ������, �����, ������ � ������ �����������, ������ �� ����, ���� ����� �����

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
����� ���������:

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

	for (int i = 0; i < 23; i++) { // ������� �� 23 �����

		if (!world.canGo(Character::Ivan, leftDirection) == true && world.canGo(Character::Ivan, frontDirection) == true) { // ����� ������, ����� ��������

			world.go(frontDirection, Direction::Pass);

			while (!world.canGo(Character::Ivan, leftDirection) == true && world.canGo(Character::Ivan, frontDirection) == true) {
				world.go(frontDirection, Direction::Pass);
			}

			// ��������������� �����:

			reservDirection = frontDirection;
			frontDirection = leftDirection;
			leftDirection = backDirection;
			backDirection = rightDirection;
			rightDirection = reservDirection;

		}

		else if (world.canGo(Character::Ivan, leftDirection) == true && world.canGo(Character::Ivan, frontDirection) == true) {  // ����� ��������, ����� ��������

			

			world.go(frontDirection, Direction::Pass);

			while (!world.canGo(Character::Ivan, leftDirection) == true && world.canGo(Character::Ivan, frontDirection) == true) { 
				world.go(frontDirection, Direction::Pass);
			}

			// ��������������� �����:

			reservDirection = frontDirection;
			frontDirection = leftDirection;
			leftDirection = backDirection;
			backDirection = rightDirection;
			rightDirection = reservDirection;

			world.go(frontDirection, Direction::Pass);

		}

		else if (world.canGo(Character::Ivan, leftDirection) == true && !world.canGo(Character::Ivan, frontDirection) == true) { // ����� ��������, ����� ������

				reservDirection = frontDirection;
				frontDirection = backDirection;
				backDirection = reservDirection;

				reservDirection = leftDirection;
				leftDirection = rightDirection;
				rightDirection = reservDirection;
		}

		else if (!world.canGo(Character::Ivan, leftDirection) == true && !world.canGo(Character::Ivan, frontDirection) == true) { // ����� ������, ����� ������

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