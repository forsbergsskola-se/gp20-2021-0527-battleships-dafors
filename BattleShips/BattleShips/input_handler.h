#pragma once
// for anyone peeking =) https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/

#pragma once
#include <iostream>
#include "coordinate.h"

class InputHandler {
public:
    template <typename T>
    static T GetInput()
    {
        while (true)
        {
            T t{};
            std::cin >> t;

            if (std::cin.fail())
            {
                std::cin.clear(); 
                IgnoreLine();
                std::cout << "Invalid input.\n";
            }
            else
            {
                IgnoreLine(); 
                return t;
            }
        }
    }

    static Coordinate GetCoordinate() {
        int x = -1;
        int y = -1;
        while (true) {
            std::cout << "input row \n >";
            std::cin >> y;
            std::cout << "input col \n >";
            std::cin >> x;
            if (std::cin.fail()) {
                std::cin.clear(); 
                IgnoreLine(); 
                std::cout << "Invalid input.\n";
            }
            else {
                IgnoreLine();
                return Coordinate{ x,y };
            }
        }
    }

    static bool ConfirmSelection() {
        char input;
        while (true)
        {
            std::cout << "choose y or n \n";
            input = InputHandler::GetInput<char>();
            if (input == 'y')
                return true;
            else if (input == 'n')
                return false;
        }
    }

private:
    static void IgnoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
};