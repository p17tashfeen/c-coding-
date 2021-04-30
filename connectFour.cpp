#include "connectFour.h"

using namespace std;

ConnectFour::ConnectFour(){
	if (!boardTexture.loadFromFile("connectbg.png"))
		cout << "Board Not Loaded!" << endl;

	if (!yTokenTexture.loadFromFile("token_0.png"))
		cout << "Yellow Token Not Loaded!" << endl;

	if (!rTokenTexture.loadFromFile("token_1.png"))
		cout << "Red Token Not Loaded!" << endl;

	if (!startTexture.loadFromFile("start.png"))
		cout << "Start Button Not loaded" << endl;

	if (!saveTexture.loadFromFile("save.png"))
		cout << "Save Button Not loaded" << endl;

	if (!loadTexture.loadFromFile("load.png"))
		cout << "Load Button Not loaded" << endl;

	if (!restartTexture.loadFromFile("restart.png"))
		cout << "Restart Button Not loaded" << endl;

	if (!exitTexture.loadFromFile("exit.png"))
		cout << "Exit Button Not loaded" << endl;

	if (!headingTexture.loadFromFile("heading.png"))
		cout << "Heading Not Loaded!" << endl;

	if (!rPlayerTurnTexture.loadFromFile("rPlayerTurn.png"))
		cout << "Red Player Turn Not Loaded!" << endl;

	if (!yPlayerTurnTexture.loadFromFile("yPlayerTurn.png"))
		cout << "Yellow Player Turn Not Loaded!" << endl;

	if (!rPlayerWinsTexture.loadFromFile("rPlayerWins.png"))
		cout << "Red Player Wins Not Loaded!" << endl;

	if (!yPlayerWinsTexture.loadFromFile("yPlayerWins.png"))
		cout << "Yellow Player Wins Not Loaded!" << endl;

	if (!drawTexture.loadFromFile("draw.png"))
		cout << "Draw Not Loaded!" << endl;

	if (!gameSavedTexture.loadFromFile("gameSaved.png"))
		cout << "GameSaved Not Loaded!" << endl;

	if (!wowTexture.loadFromFile("wow.png"))
		cout << "Wow Not Loaded!" << endl;

	if (!oopsTexture.loadFromFile("oops.png"))
		cout << "Oops Not Loaded!" << endl;


	yTokenTexture.setSmooth(true);
	rTokenTexture.setSmooth(true);
	boardTexture.setSmooth(true);
	board.setTexture(boardTexture);

	for (int i = 0; i < 21; i++) {
		yellowToken[i].setTexture(yTokenTexture);
		yellowToken[i].setScale(sf::Vector2f(0.95,0.95));
		redToken[i].setTexture(rTokenTexture);
		redToken[i].setScale(sf::Vector2f(0.95,0.95));
	}


	startButton.setTexture(startTexture);

	drawGame.setTexture(drawTexture);

	gameSaved.setTexture(gameSavedTexture);

	rPlayerTurn.setTexture(rPlayerTurnTexture);

	yPlayerTurn.setTexture(yPlayerTurnTexture);

	rPlayerWins.setTexture(rPlayerWinsTexture);
	yPlayerWins.setTexture(yPlayerWinsTexture);


	saveButton.setTexture(saveTexture);

	loadButton.setTexture(loadTexture);

	restartButton.setTexture(restartTexture);

	exitButton.setTexture(exitTexture);

	heading.setTexture(headingTexture);

	wow.setTexture(wowTexture);

	oops.setTexture(oopsTexture);

	gameSaved.setPosition(sf::Vector2f(525,5));

	Player = '-';
	for(int row = 0; row < 6; row++)
	{
		for(int column = 0; column < 7; column++)
		{
			Board[row][column] = '-';
		}
	}
	ValidRow = 0;
	ValidColumn = 0;
	ColumnNumber = 0;
	Row = 0;
	Column = 0;
	WinnerFound = false;
	BlankFound = false;
	Valid = false;
	GameFinished = false;
	flag = false;

	for (int i = 0; i < 6; i++) {
		if (i == 5) {
			y[i] = 76;
		}
		else if (i == 4) {
			y[i] = 146;
		}
		else if (i == 3) {
			y[i] = 216;
		}
		else if (i == 2) {
			y[i] = 286;
		}
		else if (i == 1) {
			y[i] = 356;
		}
		else if (i == 0) {
			y[i] = 426;
		}
	}

	for (int i = 0; i < 7; i++) {
		if (i == 6) {
			x[i] = 428;
		}
		else if (i == 5) {
			x[i] = 358;
		}
		else if (i == 4) {
			x[i] = 288;
		}
		else if (i == 3) {
			x[i] = 218;
		}
		else if (i == 2) {
			x[i] = 148;
		}
		else if (i == 1) {
			x[i] = 78;
		}
		else if (i == 0) {
			x[i] = 8;
		}			
	}
}

void ConnectFour :: drawMenu(sf::RenderWindow &window) {
	heading.setPosition(sf::Vector2f(250, 100));
	startButton.setPosition(sf::Vector2f(280, 185));
	loadButton.setPosition(sf::Vector2f(280, 270));
	exitButton.setPosition(sf::Vector2f(280, 355));

	window.draw(heading);
	window.draw(startButton);
	window.draw(loadButton);
	window.draw(exitButton);
}

void ConnectFour :: draw(sf::RenderWindow &window) {
	heading.setPosition(sf::Vector2f(225, 10));
	restartButton.setPosition(sf::Vector2f(525, 75));
	saveButton.setPosition(sf::Vector2f(525, 160));

	wow.setPosition(sf::Vector2f(525, 160));
	oops.setPosition(sf::Vector2f(525, 160));



	exitButton.setPosition(sf::Vector2f(525, 245));
	rPlayerWins.setPosition(sf::Vector2f(520, 330));
	yPlayerWins.setPosition(sf::Vector2f(520, 330));
	rPlayerTurn.setPosition(sf::Vector2f(520, 330));
	yPlayerTurn.setPosition(sf::Vector2f(520, 330));
	drawGame.setPosition(sf::Vector2f(520, 330));


	if (GameFinished == true) {
		if (WinnerFound == true) {
			if (Player == 'Y') {
				window.draw(rPlayerWins);
			}
			else if(Player == 'R') {
				window.draw(yPlayerWins);
			}	
		}
		else {
			window.draw(drawGame);
		}
	}
	else {
		if (Player == 'Y') {
			window.draw(yPlayerTurn);
		}
		else if(Player == 'R') {
			window.draw(rPlayerTurn);
		}
	}

	window.draw(heading);
	window.draw(exitButton);
	window.draw(restartButton);
	if(GameFinished == false){
		window.draw(saveButton);
	}
	if(GameFinished == true){
		window.draw(wow);
	}
	if(GameFinished == true && WinnerFound == false){
		window.draw(oops);
	}
	window.draw(board);

	int yellowIndex = 0;
	int redIndex = 0;


	for (int r = 0; r < 6; r++) {
		for (int c = 0; c < 7; c++) {
			if (Board[r][c] == 'Y'){
				yellowToken[yellowIndex].setPosition(sf::Vector2f(x[c], y[r]));
				window.draw(yellowToken[yellowIndex]);
				yellowIndex++;
			}
			else if (Board[r][c] == 'R'){
				redToken[redIndex].setPosition(sf::Vector2f(x[c], y[r]));
				window.draw(redToken[redIndex]);
				redIndex++;
			}
		}
	}
}

void ConnectFour :: SetUPGame()
{
	Player = 'Y';
	cout << "Game Start" << endl;
	GameFinished = false;
	WinnerFound = false;
}

void ConnectFour :: Restart()
{
	for(int row = 0; row < 6; row++)
	{
		for(int column = 0; column < 7; column++)
		{
			Board[row][column] = '-';
		}
	}
	SetUPGame();
}


void ConnectFour :: OutputBoard()
{
	for(int row = 5; row >= 0; row--)
	{
		for(int column = 0; column < 7; column++)
		{
			cout << Board[row][column] << "   ";
		}
		cout << " " << endl;
		cout << endl;
	}
}

void ConnectFour :: SaveData()
{
	ofstream out;
	out.open("savefile.txt");
	if(out.is_open())
	{
		for(int row = 0; row < 6; row++)
		{
			for(int column = 0; column < 7; column++)
			{
				out << Board[row][column];
			}
			out << endl;
		}
	}
	else
	{
		cout << "file is not open" << endl;
	}
	out.close();
}

void ConnectFour :: ResumeData()
{
	ifstream in;
	in.open("savefile.txt");
	for(int row = 0; row < 6; row++)
	{
		for(int column = 0; column < 7; column++)
		{

			in >> Board[row][column];
			if(Board[row][column] == 'Y'){
				Player = 'R';
			}
			else if(Board[row][column] == 'R'){
				Player = 'Y';
			}
		}
	}
	in.close();
}

void ConnectFour :: PlayerMakesMove(sf::RenderWindow &window)
{
	ValidColumn = PlayerChoosesColumn(window);
	ValidRow = NextFreePositionInColumn();
	Board[ValidRow][ValidColumn] = Player;
}

void ConnectFour :: CheckPlayerHasWon()
{
	if(WinnerFound == false)
	{
		CheckDiagonalRowAndColumn();
	}
	if(WinnerFound == false)
	{
		CheckHorizontalLineValidRow();
	}
	if(WinnerFound == false)
	{
		CheckVerticalLineValidColumn();
	}

	if(WinnerFound == true)
	{
		cout << Player << " is the winner" << endl;
		GameFinished = true;
	}
	else
	{
		CheckFullBoard();
	}
}

void ConnectFour :: CheckFullBoard()
{
	BlankFound = false;
	for(Row = 0; Row < 6; Row++)
	{
		for(Column = 0; Column < 7; Column++)
		{
			if(Board[Row][Column] == '-')
			{
				BlankFound = true;
			}
		}

	}
	if(BlankFound == false)
	{
		cout << " It is Draw" << endl;
		GameFinished = true;
	}

}

void ConnectFour :: CheckDiagonalRowAndColumn()
{

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(Board[i][j] == Player &&
				Board[i+1][j+1] == Player &&
				Board[i+2][j+2] == Player &&
				Board[i+3][j+3] == Player)
			{
				WinnerFound = true;
			}	
		}
	}

	for(int i = 5; i > 2; i--)
	{
		for(int j = 0; j < 4; j++)
		{
			if(Board[i][j] == Player &&
				Board[i-1][j+1] == Player &&
				Board[i-2][j+2] == Player &&
				Board[i-3][j+3] == Player)
			{
				WinnerFound = true;
			}	
		}
	}
	

}
void ConnectFour :: CheckHorizontalLineValidRow()
{
	for(int i = 0; i < 4; i++)
	{
		if(Board[ValidRow][i] == Player &&
			Board[ValidRow][i+1] == Player &&
			Board[ValidRow][i+2] == Player &&
			Board[ValidRow][i+3] == Player)
		{
			WinnerFound = true;
		}
	}
}

void ConnectFour :: CheckVerticalLineValidColumn()
{
	if(ValidRow == 3  || ValidRow == 4 || ValidRow == 5)
	{
		if(Board[ValidRow][ValidColumn] == Player &&
			Board[ValidRow-1][ValidColumn] == Player &&
			Board[ValidRow-2][ValidColumn] == Player &&
			Board[ValidRow-3][ValidColumn] == Player)
		{
			WinnerFound = true;
		}
	}
}

void ConnectFour :: SwapPlayer()
{
	if(Player == 'Y')
	{
		Player = 'R';
	}
	else
	{
		Player = 'Y';
	}
}

int ConnectFour :: PlayerChoosesColumn(sf::RenderWindow &window)
{
	bool columnEntered = false;

	if(Player == 'Y')
	{
		cout << "Player Yellow turn" << endl;
	}
	else
	{
		cout << "Player Red turn" << endl;
	}

	sf::Event event;


	while (columnEntered != true) {
		do
		{
			while(window.pollEvent(event))
			{
				if (event.type == sf::Event::MouseButtonPressed)
				{	
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						if (sf::Mouse::getPosition(window).y >= 70 && sf::Mouse::getPosition(window).y <= 490)
						{
							if (sf::Mouse::getPosition(window).x >= 8 && sf::Mouse::getPosition(window).x <= 65)
							{
								ColumnNumber = 0;
								columnEntered = true;
							}
							else if (sf::Mouse::getPosition(window).x >= 80 && sf::Mouse::getPosition(window).x <= 135)
							{
								ColumnNumber = 1;
								columnEntered = true;
							}
							else if (sf::Mouse::getPosition(window).x >= 150 && sf::Mouse::getPosition(window).x <= 205)
							{
								ColumnNumber = 2;
								columnEntered = true;
							}
							else if (sf::Mouse::getPosition(window).x >= 220 && sf::Mouse::getPosition(window).x <= 275)
							{
								ColumnNumber = 3;
								columnEntered = true;
							}
							else if (sf::Mouse::getPosition(window).x >= 290 && sf::Mouse::getPosition(window).x <= 345)
							{
								ColumnNumber = 4;
								columnEntered = true;
							}
							else if (sf::Mouse::getPosition(window).x >= 360 && sf::Mouse::getPosition(window).x <= 415)
							{
								ColumnNumber = 5;
								columnEntered = true;
							}
							else if (sf::Mouse::getPosition(window).x >= 430 && sf::Mouse::getPosition(window).x <= 485)
							{
								ColumnNumber = 6;
								columnEntered = true;
							}
						}

						if(sf::Mouse::getPosition(window).x >= 525 && sf::Mouse::getPosition(window).x <= 715){
							if(sf::Mouse::getPosition(window).y >= 75 && sf::Mouse::getPosition(window).y <= 110){
								Restart();

								window.clear();
								draw(window);
								window.display();
							}
							else if(GameFinished == false && sf::Mouse::getPosition(window).y >= 160 && sf::Mouse::getPosition(window).y <= 195){
								SaveData();
								window.draw(gameSaved);
								window.display();
								cout << "Save Button Pressed" << endl;
							}
							else if(sf::Mouse::getPosition(window).y >= 245 && sf::Mouse::getPosition(window).y <= 295){
								window.close();
								exit(1);
							}
						}	
					}
				}

				if (event.type == sf::Event::Closed)
				{
					window.close();
					exit(1);
				}
			}

		}
		while(ColumnNumberValid() == false);
	}


	return ColumnNumber;
}

void ConnectFour :: buttonSelect(sf::RenderWindow &window) {
	sf::Event event;
	while(window.pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{	
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if(sf::Mouse::getPosition(window).x >= 525 && sf::Mouse::getPosition(window).x <= 715){
					if(sf::Mouse::getPosition(window).y >= 75 && sf::Mouse::getPosition(window).y <= 110){
						Restart();

						window.clear();
						draw(window);
						window.display();
					}
					else if(GameFinished == false && sf::Mouse::getPosition(window).y >= 160 && sf::Mouse::getPosition(window).y <= 195){
						SaveData();
						window.draw(gameSaved);
						window.display();
						cout << "Save Button Pressed" << endl;
					}
					else if(sf::Mouse::getPosition(window).y >= 245 && sf::Mouse::getPosition(window).y <= 295){
						window.close();
						exit(1);
					}
				}
			}
		}

		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

int ConnectFour :: NextFreePositionInColumn()
{
	int row = 0;
	while(Board[row][ValidColumn] != '-' )
	{
		row += 1;
	}
	return row;	
}

bool ConnectFour :: ColumnNumberValid()
{
	Valid = false;
	if(ColumnNumber >= 0 && ColumnNumber <= 6)
	{
		if(Board[5][ColumnNumber] == '-')
		{
			Valid = true;
		}
	}
	
	return Valid;
}

void ConnectFour :: menu(sf::RenderWindow &window) {
	sf::Event event;
	bool start = false;

	window.clear();
	drawMenu(window);
	window.display();
	while(start == false) {
		while(window.pollEvent(event)) {

			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					if(sf::Mouse::getPosition(window).x >= 280 && sf::Mouse::getPosition(window).x <= 470){
						if(sf::Mouse::getPosition(window).y >= 185 && sf::Mouse::getPosition(window).y <= 235){
							start = true;
						}
						else if(sf::Mouse::getPosition(window).y >= 270 && sf::Mouse::getPosition(window).y <= 320){
							ResumeData();
							start = true;
						}
						else if(sf::Mouse::getPosition(window).y >= 355 && sf::Mouse::getPosition(window).y <= 405){
							window.close();
							exit(1);
						}
					}
				}
			}
			if (event.type == sf::Event::Closed) {
				window.close();
				exit(1);
			}
		}
	}
}