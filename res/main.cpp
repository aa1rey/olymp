#include "fairy_tail.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;



Fairyland world; // ������������� ����



int move() {
	system("chcp 1251>nul");

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




��� � �����, �� ���������:

�������(@) ���������� ��� �����������.

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

��� �� ���� ����������:

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

			// ��������������� �����:

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

			// ��������������� �����:

			reservDirection = rightDirection;
			rightDirection = frontDirection;
			frontDirection = leftDirection;
			leftDirection = backDirection;
			backDirection = reservDirection;

			world.go(leftDirection, Direction::Pass);

		}

		// � �����, ��� ����� ������� ������� ���������� ����������� ����������, �� ��� ������ ����� ����� �������� ����������� �� ���������, �.�. ��, ������� ������ ��� �����.

	}
	return 0;
}

int main() {
	system("chcp 1251>nul");

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