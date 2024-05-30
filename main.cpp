// #include <iostream>

// using namespace std;

// class Car {
// private:
//     int x1, y1;
//     char dir;

// public:
//     Car(int x1, int y1, char dir);

//     int get_x1() {
//         return x1;
//     }

//     int get_y1() {
//         return y1;
//     }

//     bool did_car_crash(int x, int y, int x1, int y1) {
//         return (x1 > x || y1 > y || x1 < 0 || y1 < 0);
//     }
//     void move_forward(int &x1, int &y1, char direction) {
//         if (direction == 'N') y1++;
//         else if (direction == 'E') x1++;
//         else if (direction == 'S') y1--;
//         else if (direction == 'W') x1--;
//     }
//     void move_backward(int &x1, int &y1, char direction) {
//         if (direction == 'N') y1--;
//         else if (direction == 'E') x1--;
//         else if (direction == 'S') y1++;
//         else if (direction == 'W') x1++;
//     }
//     void turn_right(char &direction) {
//         if (direction == 'N') direction = 'E';
//         else if (direction == 'E') direction = 'S';
//         else if (direction == 'S') direction = 'W';
//         else if (direction == 'W') direction = 'N';
//     }    
//     void turn_left(char &direction) {
//         if (direction == 'N') direction = 'W';
//         else if (direction == 'E') direction = 'N';
//         else if (direction == 'S') direction = 'E';
//         else if (direction == 'W') direction = 'S';
//     }
// };

// // This function only serves to simplify the readability of the main code.
// pair<int, int> create_space(int x, int y) {
//     cout << "What size should the room be?" << endl;
//     cout << "Enter two integer numbers to represent the 2D environment: ";
//     cin >> x >> y;
//     return make_pair(x, y);
// }

// // This function only serves to simplify the readability of the main code.
// tuple<int, int, char> start_space(int x1, int y1, char direction) {
//     cout << "Now enter the cars starting position and "<< endl;
//     cout << "direction the car should face at the start (N, E, S, W): ";
//     cin >> x1 >> y1 >> direction;
//     return make_tuple(x1, y1, direction);
// }

// // This function only serves to simplify the readability of the main code.
// string orders(string command) {
//     cout << "now input how you want the car to move using a string of command " << endl;
//     cout << "F: forward " << endl;
//     cout << "B: backwards " << endl;
//     cout << "R: turn 90 degrees clockwise " << endl;
//     cout << "L: turn 90 degrees counter-clockwise " << endl;
//     cout << "Enter string here: ";
//     cin >> command;
//     return command;
// }

// // bool did_car_crash(int x, int y, int x1, int y1) {
// //     return (x1 > x || y1 > y || x1 < 0 || y1 < 0);
// // }

// // void move_forward(int &x1, int &y1, char direction) {
// //     if (direction == 'N') y1++;
// //     else if (direction == 'E') x1++;
// //     else if (direction == 'S') y1--;
// //     else if (direction == 'W') x1--;
// // }

// // void move_backward(int &x1, int &y1, char direction) {
// //     if (direction == 'N') y1--;
// //     else if (direction == 'E') x1--;
// //     else if (direction == 'S') y1++;
// //     else if (direction == 'W') x1++;
// // }

// // void turn_right(char &direction) {
// //     if (direction == 'N') direction = 'E';
// //     else if (direction == 'E') direction = 'S';
// //     else if (direction == 'S') direction = 'W';
// //     else if (direction == 'W') direction = 'N';
// // }

// // void turn_left(char &direction) {
// //     if (direction == 'N') direction = 'W';
// //     else if (direction == 'E') direction = 'N';
// //     else if (direction == 'S') direction = 'E';
// //     else if (direction == 'W') direction = 'S';
// // }

// int main() {
//     int x, y, x1, y1;
//     char direction;
//     string command;
//     bool crash = false;

//     // Decides the space where the car will drive.
//     pair<int, int> coordinates = create_space(x, y);
//     x = coordinates.first;
//     y = coordinates.second;
//     cout << "The size is: " << x << " and " << y << endl;

//     // Decides the starting position and direction car will face.
//     tuple<int, int, char> start = start_space(x1, y1, direction);
//     x1 = get<0>(start);
//     y1 = get<1>(start);
//     direction = get<2>(start);
//     if (direction != 'N' && direction != 'E' && direction != 'S' && direction != 'W') {
//         cout << "Wrong: Car can only point in 4 directions. N, E, S, W. Try again." << endl;
//         return -1;
//     }
//     cout << "The car will be facing: " << direction << endl;

//     // Decides how we want the car to move.

//     Car car(x1, y1, direction);
//     command = orders(command);

//     for (char c : command) {
//         if (c == 'F') car.move_forward(x1, y1, direction);
//         else if (c == 'B') car.move_backward(x1, y1, direction);
//         else if (c == 'R') car.turn_right(direction);
//         else if (c == 'L') car.turn_left(direction);
        
//         crash = did_car_crash(x, y, x1, y1);
//         if (crash) break;
//     }    

//     crash = did_car_crash(x, y, x1, y1);
//     if (!crash) {
//         cout << "Everything went well and your car is currently at position: " << x1 << " " << y1 << endl;
//         cout << "facing the direction: " << direction << endl;
//         return 0;
//     }
//     cout << "Your car crashed at the position: " << x1 << " " << y1 << endl;
//     return -2;
// }

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
    cout << "The size is: " << x << " and " << y << endl;

    // Decides the starting position and direction car will face.
    tuple<int, int, char> start = start_space();
    int x1 = get<0>(start);
    int y1 = get<1>(start);
    char direction = get<2>(start);
    if (direction != 'N' && direction != 'E' && direction != 'S' && direction != 'W') {
        cout << "Wrong: Car can only point in 4 directions. N, E, S, W. Try again." << endl;
        system("pause");
        return -1;
    }
    cout << "The car will be facing: " << direction << endl;

    // Create a Car object
    Car car(x1, y1, direction);

    // Decides how we want the car to move.
    command = orders();

    for (char c : command) {
        if (c == 'F') car.move_forward();
        else if (c == 'B') car.move_backward();
        else if (c == 'R') car.turn_right();
        else if (c == 'L') car.turn_left();
        
        crash = car.did_car_crash(x, y);
        if (crash) break;
    }

    if (!crash) {
        cout << "Everything went well and your car is currently at position: " << car.get_x1() << " " << car.get_y1() << endl;
        cout << "Facing the direction: " << car.get_direction() << endl;
        system("pause");
        return 0;
    }
    cout << "Your car crashed at the position: " << car.get_x1() << " " << car.get_y1() << endl;
    system("pause");
    return -2;
}
