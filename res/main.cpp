#include "fairy_tail.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Fairyland world; // ������������� ����

int walk() {
	int s = 0;
	Direction reservDirection;
	Direction frontDirection; // ���������� ������� �����������
	Direction leftDirection; // ���������� ������ �����������
	Direction rightDirection; // ���������� ������� �����������
	Direction backDirection; // ���������� ������� �����������

		// ��������� ������, �����, ������ � ������ �����������, ������ �� ����, ���� ����� �����

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

	while (world.go(Direction::Pass, Direction::Pass) == false) {

		s++;

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

			if (world.canGo(Character::Ivan, frontDirection) == true) {
				world.go(frontDirection, Direction::Pass);
			}
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

					// �������� ����� �� 270 ��������

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
