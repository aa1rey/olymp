#include "fairy_tail.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Fairyland world; // ������������� ����

int move() {
	Direction leftDirection; // ���������� ������ �����������
	Direction frontDirection; // ���������� ������� �����������
	for (int i = 0; i < 1000; i++) {

		// ��������� ����� �����������, ������ �� ����, ���� ����� �����

		if (world.canGo(Character::Ivan, Direction::Down)) {
			leftDirection = Direction::Right;
		}
		if (world.canGo(Character::Ivan, Direction::Left)) {
			leftDirection = Direction::Down;
		}
		if (world.canGo(Character::Ivan, Direction::Up)) {
			leftDirection = Direction::Left;
		}
		if (world.canGo(Character::Ivan, Direction::Right)) {
			leftDirection = Direction::Up;
		}
		
		// ��������� ������ �����������, ������ �� ����, ���� ����� �����

		if (world.canGo(Character::Ivan, Direction::Down)) {
			frontDirection = Direction::Down;
		}
		if (world.canGo(Character::Ivan, Direction::Left)) {
			frontDirection = Direction::Left;
		}
		if (world.canGo(Character::Ivan, Direction::Up)) {
			frontDirection = Direction::Up;
		}
		if (world.canGo(Character::Ivan, Direction::Right)) {
			frontDirection = Direction::Right;
		}

		// ���� �� ����� ����� ������, ���� �����

		while (!world.canGo(Character::Ivan, leftDirection)) {
			world.go(frontDirection, Direction::Pass);
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