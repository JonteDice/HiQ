#include <iostream>

using namespace std;
int main() {
    int x, y, x1, y1;
    char direction;
    string command;
    bool crash = false;
    cout << "What size should the room be?" << endl;
    cout << "Enter two integer numbers to represent the 2D environment: ";
    cin >> x >> y;
    cout << "The size is: " << x << " and " << y << endl;
    cout << "Now enter the cars starting position and "<< endl;
    cout << "direction the car should face at the start (N, E, S, W): ";
    cin >> x1 >> y1 >> direction;
    if (direction != 'N' && direction != 'E' && direction != 'S' && direction != 'W') {
        cout << "Wrong: Car can only point in 4 directions. N, E, S, W. Try again." << endl;
        return -1;
    }
    cout << "The car will be facing: " << direction << endl;
    cout << "now input how you want the car to move using a string of command " << endl;
    cout << "F: forward " << endl;
    cout << "B: backwards " << endl;
    cout << "R: turn 90 degrees clockwise " << endl;
    cout << "L: turn 90 degrees counter-clockwise " << endl;
    cout << "Enter string here: ";
    cin >> command;
    for (char c : command) {
        if (c == 'F') {
            if (direction == 'N') {
                y1++;
                continue;
            }
            if (direction == 'E') {
                x1++;
                continue;
            }
            if (direction == 'S') {
                y1--;
                continue;
            }
            if (direction == 'W') {
                x1--;
                continue;
            }
        }
        else if (c == 'R') {
            if (direction == 'N') {
                direction = 'E';
                continue;
            }
            if (direction == 'E') {
                direction = 'S';
                continue;
            }
            if (direction == 'S') {
                direction = 'W';
                continue;
            }
            if (direction == 'W') {
                direction = 'N';
                continue;
            }
        }  
        else if (c == 'B') {
            if (direction == 'N') {
                y1--;
                continue;
            }
            if (direction == 'E') {
                x1--;
                continue;
            }
            if (direction == 'S') {
                y1++;
                continue;
            }
            if (direction == 'W') {
                x1++;
                continue;
            }
        }
        else if (c == 'L') {
            if (direction == 'N') {
                direction = 'W';
                continue;
            }
            if (direction == 'E') {
                direction = 'N';
                continue;
            }
            if (direction == 'S') {
                direction = 'E';
                continue;
            }
            if (direction == 'W') {
                direction = 'S';
                continue;
            }
        }
        else {
            continue;
        }
        if (x1 > x || y1 > y || x1 < 0 || y1 < 0) {
            crash = true;
            break;
        }
    }
    if (!crash) {
        cout << "Everything went well and your car is currently at position: " << x1 << " " << y1 << endl;
        cout << "facing the direction: " << direction << endl;
        return 0;
    }
    cout << "Your car crashed at the position: " << x1 << " " << y1 << endl;
    return -2;
}