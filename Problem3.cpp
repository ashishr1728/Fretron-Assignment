// Kill All And Return Home

#include <iostream>
#include <vector>
#include <string>

class SpecialCastle {
private:
    int boardSize;
    std::vector<std::pair<int, int>> soldiers;
    std::pair<int, int> castlePosition;
    std::vector<std::vector<std::string>> paths;

public:
    SpecialCastle(int boardSize, std::vector<std::pair<int, int>> soldiers, std::pair<int, int> castlePosition) {
        this->boardSize = boardSize;
        this->soldiers = soldiers;
        this->castlePosition = castlePosition;
    }

    bool isValidPosition(std::pair<int, int> position) {
        return position.first >= 1 && position.first <= boardSize && position.second >= 1 && position.second <= boardSize;
    }

    void moveCastle(std::pair<int, int> position, std::vector<std::string>& path) {
        for (auto it = soldiers.begin(); it != soldiers.end(); ++it) {
            if (*it == position) {
                path.push_back("Kill (" + std::to_string(position.first) + "," + std::to_string(position.second) + "). Turn Left");
                soldiers.erase(it);
                std::pair<int, int> newPosition = {position.first, position.second - 1};
                if (isValidPosition(newPosition)) {
                    path.push_back("Jump (" + std::to_string(newPosition.first) + "," + std::to_string(newPosition.second) + ")");
                    moveCastle(newPosition, path);
                }
                return;
            }
        }
    }

    void findPaths(std::pair<int, int> position, std::vector<std::string>& path) {
        if (position == castlePosition) {
            paths.push_back(path);
            return;
        }

        for (auto soldier : soldiers) {
            if (soldier.first >= position.first) {
                std::vector<std::string> newPath = path;
                moveCastle(soldier, newPath);
            }
        }
    }

    std::vector<std::vector<std::string>> run() {
        std::vector<std::string> path = {"Start (" + std::to_string(castlePosition.first) + "," + std::to_string(castlePosition.second) + ")"};
        findPaths(castlePosition, path);
        return paths;
    }
};

int main() {
    int boardSize = 8;
    std::vector<std::pair<int, int>> soldiers = {{1, 1}, {8, 9}, {1, 9}, {4, 1}, {4, 2}, {4, 8}, {2, 6}, {5, 6}, {8, 2}, {5, 9}, {2, 8}};
    std::pair<int, int> castlePosition = {1, 2};

    SpecialCastle game(boardSize, soldiers, castlePosition);
    std::vector<std::vector<std::string>> paths = game.run();

    std::cout << "Thanks. There are " << paths.size() << " unique paths for your 'special_castle'\n\n";
    for (int i = 0; i < paths.size(); i++) {
        std::cout << "Path " << i + 1 << "\n=======\n";
        for (const auto& step : paths[i]) {
            std::cout << step << "\n";
        }
        std::cout << "Arrive (" << castlePosition.first << "," << castlePosition.second << ")\n\n";
    }

    return 0;
}