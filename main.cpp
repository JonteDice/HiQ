#include <iostream>
#include <tuple>
#include <string>
#include "Car.h"

using namespace std;

// This function only serves to simplify the readability of the main code.
pair<int, int> create_space() {
    int x, y;
    cout << "What size should the room be?" << endl;
    cout << "Enter two integer numbers to represent the 2D environment: ";
    cin >> x >> y;
    return make_pair(x, y);
}

// This function only serves to simplify the readability of the main code.
tuple<int, int, char> start_space() {
    int x1, y1;
    char direction;
    cout << "Now enter the car's starting position and "<< endl;
    cout << "direction the car should face at the start (N, E, S, W): ";
    cin >> x1 >> y1 >> direction;
    return make_tuple(x1, y1, direction);
}

// This function only serves to simplify the readability of the main code.
string orders() {
    string command;
    cout << "Now input how you want the car to move using a string of commands " << endl;
    cout << "F: forward " << endl;
    cout << "B: backwards " << endl;
    cout << "R: turn 90 degrees clockwise " << endl;
    cout << "L: turn 90 degrees counter-clockwise " << endl;
    cout << "Enter string here: ";
    cin >> command;
    return command;
}

int main() {
    int x, y;
    string command;
    bool crash = false;

    // Decides the space where the car will drive.
    pair<int, int> coordinates = create_space();
    x = coordinates.first;
    y = coordinates.second;
    if (x <= 0 || y <= 0) {
        cout << "Space cannot be 0 or less than 0. Try again. " << endl;
        system("pause");
        return -1;
    }
    cout << "The size is: " << x << " and " << y << endl;

    // Decides the starting position and direction car will face.
    tuple<int, int, char> start = start_space();
    int x1 = get<0>(start);
    int y1 = get<1>(start);
    char direction = get<2>(start);
    direction = toupper(direction);
    if (direction != 'N' && direction != 'E' && direction != 'S' && direction != 'W') {
        cout << "Error: Car can only point in 4 directions. N, E, S, W. Try again." << endl;
        system("pause");
        return -1;
    }
    if (x1 < 0 || y1 < 0 || x1 > x || y1 > y) {
        cout << "Error: Car has to start at a position within the space created. Try again" << endl;
        system("pause");
        return -1;
    }
    cout << "The car will be facing: " << direction << endl;

    // Create a Car object
    Car car(x1, y1, direction);

    // Decides how we want the car to move.
    command = orders();

    // Looks at each command and moves the car.
    for (char c : command) {
        c = toupper(c);
        if (c == 'F') car.move_forward();
        else if (c == 'B') car.move_backward();
        else if (c == 'R') car.turn_right();
        else if (c == 'L') car.turn_left();
        
        crash = car.did_car_crash(x, y);
        if (crash) break;
    }

    // No crash!
    if (!crash) {
        cout << "Everything went well and your car is currently at position: " << car.get_x1() << " " << car.get_y1() << endl;
        cout << "Facing the direction: " << car.get_direction() << endl;
        system("pause");
        return 0;
    }
    // Car crashed!
    cout << "Your car crashed at the position: " << car.get_x1() << " " << car.get_y1() << endl;
    system("pause");
    return -2;
}
