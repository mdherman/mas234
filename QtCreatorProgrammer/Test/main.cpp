#include <iostream>
#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cstring>
#include <cstdio>
#include <climits>
#include <limits>
#include <string>


void askUserForYesNoInput(){

    std::string input;
    bool answer;

    std::cout << "Yes or no? " << std::endl;

    std::cin >> input;

        if(input == "y" || input == "Y"){
            answer = true;
            std::cout << answer << std::endl;
        }

        else if (input=="n" ||input=="N"){
            answer = false;
            std::cout << answer << std::endl;
        }
            else{
                return askUserForYesNoInput();
            }

    }


int main()
{
    askUserForYesNoInput();

}

