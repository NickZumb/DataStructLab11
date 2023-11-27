// TowerHannoiGame.cpp : Defines the entry point for the console application.
//

#include "StackQueue.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TowersOfHannoiGame
{
public:
	ArrayBasedStack towers[3];

	TowersOfHannoiGame() : m_GameEnded(false)
	{
		//Initialize the starting tower stack
		towers[0].push(4);
		towers[0].push(3);
		towers[0].push(2);
		towers[0].push(1);
	}

	bool IsGameEnded() { return m_GameEnded; }

	// Checks if the game has been completed and updates m_GameEnded
	void CheckIfGameEnded()
	{
		bool checkFailed = false;
		int expectedTower = 1;
		ArrayBasedStack finalTower = towers[2];

		while(!checkFailed && !finalTower.isEmpty())
		{
			if (finalTower.peek() == expectedTower)
			{
				expectedTower++;
				finalTower.pop();
			}
			else
			{
				checkFailed = true;
			}
		}

		if ((!checkFailed) && (expectedTower == 5))
		{
			m_GameEnded = true;
		}
		else
		{
			m_GameEnded = false;
		}
	}

	void PrintTowers()
	{
		cout << "Tower 1: " << towers[0].toString() << endl;
		cout << "Tower 2: " << towers[1].toString() << endl;
		cout << "Tower 3: " << towers[2].toString() << endl << endl;
	}

private:
	bool m_GameEnded;
	

};

int main()
{

	cout << "Enter in moves to make for Towers  of  Hannoi" << endl;
	cout << "Progam will exit once towers have  been successfully moved of" << endl;
	cout << "or string of -1 is entered. Moves must be entired in format of" << endl;
	cout << "<disk>,<column from>,<column to>   NOTE no spaces!!!!" << endl;

	TowersOfHannoiGame game;

	bool receivedEndToken = false;

	while (!receivedEndToken && !game.IsGameEnded())
	{
		std::string inputLine;
		game.PrintTowers();
		cout << "Enter Move " << endl;
		getline(cin, inputLine);
		if (inputLine == "-1")
		{
			receivedEndToken = true;
		}
		else
		{
			std::vector<std::string> output;
			std::string::size_type prev_pos = 0, pos = 0;
			// Snippet from https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
			// tokenizing a string
			while ((pos = inputLine.find(",", pos)) != std::string::npos)
			{
				std::string substring(inputLine.substr(prev_pos, pos - prev_pos));
				output.push_back(substring);
				prev_pos = ++pos;
			}
			//Need to get last token
			output.push_back(inputLine.substr(prev_pos, pos - prev_pos)); // Last word

			if (output.size() != 3)
			{
				receivedEndToken = true;
				cout << "Invalid input recieved = " + inputLine << endl;
			}
			else
			{
				std::string disk = output[0];
				std::string from = output[1];
				std::string to = output[2];

				if (disk.size() == 0 || from.size() == 0 || to.size() == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				int diskId = atoi(disk.c_str()); 
				int fromId = atoi(from.c_str());
				int toId = atoi(to.c_str());
				//if any number is zero we didn't have a integer
				if (diskId == 0 || fromId == 0 || toId == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;


				if (game.towers[fromId - 1].isEmpty())
				{
					cout << "Illegal move, from tower is empty" << endl;
				} 
				else 
				{

					// check if the top of the tower to move from is the same size as diskId.
					if (game.towers[fromId - 1].peek() == diskId)
					{
						// if the tower to move to is empty, or it's disk is larger than the disk to move, make the move
						if ((game.towers[toId - 1].isEmpty()) || (game.towers[toId - 1].peek() > diskId))
						{
							game.towers[fromId - 1].pop();
							game.towers[toId - 1].push(diskId);
							
							game.CheckIfGameEnded();
						}
						else
						{
							cout << "Illegal move, attempted to put larger disk on smaller disk" << endl;
						}
					}
					else
					{
						cout << "Disk to remove is not top disk on the stack to remove from" << endl;
					}
				}
			}
		}
	}

	if (game.IsGameEnded())
	{
		cout << "You WIN!" << endl;
		game.PrintTowers();
	}

    return 0;
}

