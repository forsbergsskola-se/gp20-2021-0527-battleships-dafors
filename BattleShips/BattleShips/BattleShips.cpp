#include <vector>
#include "game.h"

int main()
{
    // SETTINGS 
    const std::vector<int> ship_sizes{ 3, 1 };
    const int board_size{ 10 };
    
    Game game{ship_sizes, board_size};
    bool playing = true;
    while (playing)
    {
        playing = game.Play();
    }
}