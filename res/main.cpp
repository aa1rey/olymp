#include "fairy_tail.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Fairyland world; // ������������� ����

int move() {

	for (int i = 0; i < 1; i++) {

		Direction leftDirection; // ���������� ������ �����������

		// ��������� ����� �����������, ������ �� ����, ���� ����� �����

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

		Direction frontDirection; // ���������� ������� �����������

		// ��������� ������ �����������, ������ �� ����, ���� ����� �����

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

		Direction rightDirection; // ���������� ������� �����������

		// ��������� ������ �����������, ������ �� ����, ���� ����� �����

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

		Direction backDirection; // ���������� ������� �����������

		// ��������� ������ �����������, ������ �� ����, ���� ����� �����

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

		// ���� �� ����� ����� ������, ���� �����

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

		// ���� ��������� ��� ������������� ������� ������� � �����. �� � ���� �� ���������� ������ ��� ��� �������. ���� �� ������ �������, ��� ����� �����. �� Visual Studio �����������.
		// ������� canGo() ���� bool ������ ��������, ������ ��� ��� � �����, ��� �������� ����������. �� ��� ����� ��������� ��� ���������, ����� �� �� ����� ����� ��� ������? 

		if (world.canGo(Character::Ivan, rightDirection)) {
			world.canGo(Character::Ivan, rightDirection) = false;

		}

			

	}
	return 0;
}

int main() {

	// ��������� ����� �� Ivan � Elena ���� �����

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