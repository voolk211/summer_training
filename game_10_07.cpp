#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

//логика игры

namespace Model {
    using SlotSymbols = std::vector<std::string>;

    struct GameState {
        SlotSymbols slots;
        int score;
    };

    GameState createInitialState() {
        return { {"", "", ""}, 0 };
    }

    SlotSymbols generateSpin() {
        const std::vector<std::string> symbols = { "A", "B", "C", "D" };
        SlotSymbols result(3);
        for (int i = 0; i < 3; ++i) {
            result[i] = symbols[rand() % symbols.size()];
        }
        return result;
    }

    int calculateScoreChange(const SlotSymbols& spinResult) {
        return (spinResult[0] == spinResult[1] && spinResult[1] == spinResult[2]) ? 10 : -1;
    }

    void updateGameState(GameState& state, const SlotSymbols& spinResult) {
        state.slots = spinResult;
        state.score += calculateScoreChange(spinResult);
    }
}

//отображение

namespace View {
    void printMessage(const std::string& msg) {
        std::cout << msg << std::endl;
    }

    void printData(const std::vector<std::string>& data) {
        for (const auto& symbol : data) {
            std::cout << symbol << " ";
        }
        std::cout<< std::endl;
    }

    void printScore(int score) {
        std::cout << "Score: " << score << std::endl;
    }

    void printPrompt() {
        std::cout << "Press Enter to continue or type 'q' to quit: ";
    }
}

//контроллер 

namespace Controller {
    void gameLoop() {
        Model::GameState state = Model::createInitialState();
        std::string input;

        View::printMessage("Game");

        while (true) {
            View::printPrompt();
            std::getline(std::cin, input);

            if (input == "q") {
                View::printScore(state.score);
                break;
            }

            auto spin = Model::generateSpin();
            Model::updateGameState(state, spin);

            View::printData(spin);
            View::printScore(state.score);
        }
    }
}

//main

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Controller::gameLoop();
    return 0;
}
