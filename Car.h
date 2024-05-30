#ifndef CAR_H
#define CAR_H

class Car {
private:
    int x1, y1;
    char dir;

public:
    Car(int x1, int y1, char dir);

    int get_x1() const;
    int get_y1() const;
    char get_direction() const;

    bool did_car_crash(int x, int y) const;
    void move_forward();
    void move_backward();
    void turn_right();
    void turn_left();
};

#endif // CAR_H
