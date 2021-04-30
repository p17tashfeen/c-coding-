#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
using namespace std;


class ConnectFour
{
	private:
		char Player;
		char Board[6][7];
		bool WinnerFound;
		int ValidRow, ValidColumn;
		bool Valid;
		int ColumnNumber;
		bool BlankFound;
		int Row, Column;
		bool flag;
		int y[6];
		int x[7];

		sf::Texture boardTexture;
		sf::Texture rTokenTexture;
		sf::Texture yTokenTexture;
		sf::Texture startTexture;
		sf::Texture saveTexture;
		sf::Texture loadTexture;
		sf::Texture exitTexture;
		sf::Texture restartTexture;
		sf::Texture headingTexture;
		sf::Texture rPlayerTurnTexture;
		sf::Texture yPlayerTurnTexture;
		sf::Texture rPlayerWinsTexture;
		sf::Texture yPlayerWinsTexture;
		sf::Texture drawTexture;
		sf::Texture gameSavedTexture;
		sf::Texture wowTexture;
		sf::Texture oopsTexture;



		sf::Sprite board;
		sf::Sprite yellowToken[21];
		sf::Sprite redToken[21];
		sf::Sprite startButton;
		sf::Sprite saveButton;
		sf::Sprite loadButton;
		sf::Sprite exitButton;
		sf::Sprite restartButton;
		sf::Sprite heading;
		sf::Sprite rPlayerTurn;
		sf::Sprite yPlayerTurn;
		sf::Sprite rPlayerWins;
		sf::Sprite yPlayerWins;
		sf::Sprite drawGame;
		sf::Sprite gameSaved;
		sf::Sprite wow;
		sf::Sprite oops;


	public:
		bool GameFinished;
		ConnectFour();
		

		void drawMenu(sf::RenderWindow &window);
		void draw(sf::RenderWindow &window);
		
		void SetUPGame();

		void Restart();
		
		
		void OutputBoard();
		
		void SaveData();

		void ResumeData();
		
		
		void PlayerMakesMove(sf::RenderWindow &window);
		
		void CheckPlayerHasWon();
		
		void CheckFullBoard();
		
		void CheckDiagonalRowAndColumn();
		
		void CheckHorizontalLineValidRow();
		
		void CheckVerticalLineValidColumn();
		
		void SwapPlayer();
				
		int PlayerChoosesColumn(sf::RenderWindow &window);

		void buttonSelect(sf::RenderWindow &window);
		int NextFreePositionInColumn();
		
		bool ColumnNumberValid();

		void menu(sf::RenderWindow &window);
};