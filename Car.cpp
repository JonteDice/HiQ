#include "Car.h"

Car::Car(int x1, int y1, char dir) : x1(x1), y1(y1), dir(dir) {}

int Car::get_x1() const {
    return x1;
}

int Car::get_y1() const {
    return y1;
}

char Car::get_direction() const {
    return dir;
}

bool Car::did_car_crash(int x, int y) const {
    return (x1 > x || y1 > y || x1 < 0 || y1 < 0);
}

void Car::move_forward() {
    if (dir == 'N') y1++;
    else if (dir == 'E') x1++;
    else if (dir == 'S') y1--;
    else if (dir == 'W') x1--;
}

void Car::move_backward() {
    if (dir == 'N') y1--;
    else if (dir == 'E') x1--;
    else if (dir == 'S') y1++;
    else if (dir == 'W') x1++;
}

void Car::turn_right() {
    if (dir == 'N') dir = 'E';
    else if (dir == 'E') dir = 'S';
    else if (dir == 'S') dir = 'W';
    else if (dir == 'W') dir = 'N';
}

void Car::turn_left() {
    if (dir == 'N') dir = 'W';
    else if (dir == 'E') dir = 'N';
    else if (dir == 'S') dir = 'E';
    else if (dir == 'W') dir = 'S';
}
