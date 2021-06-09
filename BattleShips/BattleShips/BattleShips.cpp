#include <vector>
#include "game.h"

int main()
{
    // SETTINGS 
    const std::vector<int> ship_sizes{ 5, 3, 1 };
    const int board_size{ 10 };
    
    bool playing = true;
    while (playing)
    {
        Game game{ ship_sizes, board_size };
        playing = game.Play();
    }
}