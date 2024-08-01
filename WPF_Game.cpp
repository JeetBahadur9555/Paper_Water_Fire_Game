 #include <iostream>
#include <cstdlib>
#include <ctime>

enum Choice { PAPER, WATER, FIRE };

std::string choiceToString(Choice choice) {
    switch (choice) {
        case PAPER: return "Paper";
        case WATER: return "Water";
        case FIRE: return "Fire";
        default: return "";
    }
}

Choice getComputerChoice() {
    return static_cast<Choice>(std::rand() % 3);
}

Choice getPlayerChoice() {
    int choice;
    std::cout << "Choose one: \n";
    std::cout << "0: Paper\n";
    std::cout << "1: Water\n";
    std::cout << "2: Fire\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return static_cast<Choice>(choice);
}

void determineWinner(Choice player, Choice computer) {
    std::cout << "You chose: " << choiceToString(player) << "\n";
    std::cout << "Computer chose: " << choiceToString(computer) << "\n";

    if (player == computer) {
        std::cout << "It's a tie!\n";
    } else if ((player == PAPER && computer == WATER) ||
               (player == WATER && computer == FIRE) ||
               (player == FIRE && computer == PAPER)) {
        std::cout << "You win!\n";
    } else {
        std::cout << "You lose!\n";
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed for random number generation

    Choice playerChoice = getPlayerChoice();
    Choice computerChoice = getComputerChoice();

    determineWinner(playerChoice, computerChoice);

    return 0;
}

