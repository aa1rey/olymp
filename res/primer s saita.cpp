#include "fairy_tail.hpp"

#include <cstdlib>
#include <ctime>

int walk() {
    Fairyland world;
    Direction direction;

    for (int i = 0; i < 1000; ++i) {
        

        for (int j = 0; j < 4; j++) {
            
            switch (j) {
            case 0:
                direction = Direction::Up;
                break;

            case 1:
                direction = Direction::Down;
                break;

            case 2:
                direction = Direction::Left;
                break;

            case 3:
                direction = Direction::Right;
                break;
            }

            if (world.canGo(Character::Ivan, direction)) {
                world.go(direction, Direction::Pass);
            }

            if (world.canGo(Character::Elena, direction)) {
                world.go(Direction::Pass, direction);
            }
            break;
        }
        
    return world.getTurnCount();

    }

    return 0;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    if (const int turns = walk())
        std::cout << "Found in " << turns << " turns" << std::endl;
    else
        std::cout << "Not found" << turns << std::endl;

    return 0;
}
