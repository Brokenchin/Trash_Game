#include <memory>

#include "Game/Trash_Game.h"



int main()
{

	std::unique_ptr<Trash_Game> game = std::make_unique<Trash_Game>();
	game->Init(800,600);
    std::cout << "Hello World!\n";
}
