#ifndef CAR_H
#define CAR_H

class Car {
private:
    int x1, y1;
    char dir;

public:
    Car(int x1, int y1, char dir);

    // Returns x coordinate of car
    int get_x1() const;
    // Returns y coordinate of car
    int get_y1() const;
    // Returns current car direction
    char get_direction() const;

    // Returns true if car has crashed
    bool did_car_crash(int x, int y) const;

    // Moves car forward
    void move_forward();

    // Moves car backward
    void move_backward();

    // Turns car right
    void turn_right();

    // Turns car left
    void turn_left();
};

#endif // CAR_H
