/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

std::vector<int> createSecret()
{
    std::vector<int> answer;
    for (int input = 0; input < 4; input++)
    {
        answer.push_back((std::rand() % 10)+1);
    }
    // std::cout << "In here\n";
    // display(answer);
    return answer;
}

std::string getHint(std::vector<int> secret, std::vector<int> guess) 
{
    if (secret.size() != guess.size()) 
    {
    std::cout << "Error: Lists are of different sizes!";
    }
    
    std::string result = ""; // Compare the elements of both lists
    for (int i = 0; i < secret.size(); ++i) 
    {
        if (secret[i] == guess[i]) {
            result += "O";  // Correct match
        } else {
            result += "X";  // Incorrect match
        }
    }

    return result;   
}


bool winGame(std::vector<int> secret, std::vector<int> guess) 
{
    return secret == guess;
}

int main()
{
    // Seeding the random number generator
    // Uncomment the code when you are finished testing your program
    // and want to have the program run for real
    srand(time(0));
    
    std::vector<int> secret_code = createSecret();
    std::vector<int> user_guess = {-1, -1, -1, -1};
    std::string hint = "";    // an empty list

    int secret_code_length = 4;
    int num_guesses = 0;

    std::cout << "Welcome to Number Wordle!\n";
    
    while (!winGame(secret_code, user_guess))    // while you have not won the game yet
    {
        std::cout << "\nEnter your guess: ";
        user_guess = {};    // reset the hint for the next guess
        for (int counter = 0; counter < secret_code_length; counter = counter + 1)
        {
            int input;
            std::cin >> input;
            user_guess.push_back(input);    // can also do append(guess, input);
        }

        // display(secret_code);
        // display(user_guess);
        hint = getHint(secret_code, user_guess);
        std::cout << hint << "\n";
        num_guesses = num_guesses + 1;
    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
