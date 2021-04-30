#include "connectFour.h"

using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(750, 490), "Connect 4");

	sf::Event event;
	ConnectFour game;


	game.SetUPGame();
	game.OutputBoard();

	
	game.menu(window);
	

	window.clear();
	game.draw(window);
	window.display();

	while(window.isOpen())
	{
		if(game.GameFinished == false)
		{
			game.PlayerMakesMove(window);
			game.OutputBoard();
		

			game.CheckPlayerHasWon();
			game.SwapPlayer();
		}
		if (game.GameFinished == true){
			game.buttonSelect(window);
		}
		window.clear();

		game.draw(window);

		window.display();
	}

	return 0;
}