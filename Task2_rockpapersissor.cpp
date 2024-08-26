#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
    
    srand(static_cast<unsigned int>(time(0)));

    int userChoice;
    int computerChoice;
    string choices[3] = {"Rock", "Paper", "Scissors"};

    cout << "Welcome to Rock-Paper-Scissors!" << endl;
    cout << "1) Rock" << endl;
    cout << "2) Paper" << endl;
    cout << "3) Scissors" << endl;
    cout << "Choose your option (1, 2, or 3): ";
    cin >> userChoice;

    userChoice -= 1;

    computerChoice = rand() % 3;

    cout << "You chose: " << choices[userChoice] << endl;
    cout << "Computer chose: " << choices[computerChoice] << endl;

    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((userChoice == 0 && computerChoice == 2) || 
               (userChoice == 1 && computerChoice == 0) ||
               (userChoice == 2 && computerChoice == 1)) { 
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }

    return 0;
}
