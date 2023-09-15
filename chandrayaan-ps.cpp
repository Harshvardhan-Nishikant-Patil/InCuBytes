#include <bits/stdc++.h>
using namespace std;

class LunarCraftControl {
private:
    struct Position {
        int x, y, z;
    };

    Position position;
    std::vector<std::string> directions;
    std::string currentDirection;

public:
    LunarCraftControl() : position({0, 0, 0}), directions({"N", "E", "S", "W", "Up", "Down"}), currentDirection("N") {}

    void moveForward() {
        switch (currentDirection[0]) {
            case 'N':
                position.y++;
                break;
            case 'E':
                position.x++;
                break;
            case 'S':
                position.y--;
                break;
            case 'W':
                position.x--;
                break;
            case 'U':
                position.z++;
                break;
            case 'D':
                position.z--;
                break;
        }
    }

    void moveBackward() {
        switch (currentDirection[0]) {
            case 'N':
                position.y--;
                break;
            case 'E':
                position.x--;
                break;
            case 'S':
                position.y++;
                break;
            case 'W':
                position.x++;
                break;
            case 'U':
                position.z--;
                break;
            case 'D':
                position.z++;
                break;
        }
    }

    void turnLeft() {
        if (currentDirection == "N")
            currentDirection = "W";
        else if (currentDirection == "E")
            currentDirection = "N";
        else if (currentDirection == "S")
            currentDirection = "E";
        else if (currentDirection == "W")
            currentDirection = "S";
        else if (currentDirection == "Up")
            currentDirection = "N";
        else if (currentDirection == "Down")
            currentDirection = "N";
    }

    void turnRight() {
        if (currentDirection == "N")
            currentDirection = "E";
        else if (currentDirection == "E")
            currentDirection = "S";
        else if (currentDirection == "S")
            currentDirection = "W";
        else if (currentDirection == "W")
            currentDirection = "N";
        else if (currentDirection == "Up")
            currentDirection = "N";
        else if (currentDirection == "Down")
            currentDirection = "N";
    }

    void turnUp() {
        if (currentDirection != "Up" && currentDirection != "Down")
            currentDirection = "Up";
    }

    void turnDown() {
        if (currentDirection != "Up" && currentDirection != "Down")
            currentDirection = "Down";
    }

    void executeCommands(const std::vector<char>& commands) {
        for (char command : commands) {
            switch (command) {
                case 'f':
                    moveForward();
                    break;
                case 'b':
                    moveBackward();
                    break;
                case 'l':
                    turnLeft();
                    break;
                case 'r':
                    turnRight();
                    break;
                case 'u':
                    turnUp();
                    break;
                case 'd':
                    turnDown();
                    break;
                default:
                    // Invalid command, ignore it
                    break;
            }
            std::cout << '"' << command << "\" - (" << position.x << ", " << position.y << ", " << position.z << ") - " << currentDirection << std::endl;
        }
    }

    std::pair<Position, std::string> getFinalState() {
        return {position, currentDirection};
    }
};

int main() {
    LunarCraftControl craftControl;
    std::vector<char> commands = {'f', 'r', 'u', 'b', 'l'};
    std::cout << "Initial Direction: " << craftControl.getFinalState().second << std::endl;
    craftControl.executeCommands(commands);
    auto finalState = craftControl.getFinalState();
    std::cout << "Final Position: (" << finalState.first.x << ", " << finalState.first.y << ", " << finalState.first.z << ")" << std::endl;
    std::cout << "Final Direction: " << finalState.second << std::endl;

    return 0;
}
