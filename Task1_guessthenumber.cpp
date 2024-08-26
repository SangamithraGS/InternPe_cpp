#include <iostream>
#include <cstdlib>  
#include <ctime>    

int main() {
    
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    int randomNumber = std::rand() % 100 + 1;
    int guess = 0;
    int numberOfTries = 0;

    std::cout << "Welcome to the Guess a Number Game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;

    while (guess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        numberOfTries++;

        if (guess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the number in " << numberOfTries << " tries." << std::endl;
        }
    }

    return 0;
}