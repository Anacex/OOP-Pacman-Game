#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<vector>
#include<conio.h>
#include <cstring>
//#include"MMSystm.h"
#include<string>
#include<fstream>
using namespace std;
class Game;
class enitity;
class Pacman;
class Enemy;
class Player;
class map;
class Audio;
class ScoreBoard;
class PlayersData;
class losewinSound;
void Set_CONColor(int a)//COLOR CHANGING FUNCTIONS 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, a);
}

void gotoxy(short x, short y) //FUNCTION TO CHANGE CURSOR POSITION
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x,y };
	SetConsoleCursorPosition(hstdout, position);
}
void HideCursor()//FUNCTION TO HIDE CURSOR;
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void Set_CoinColor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);//TO green FOR coins '.', 10=code for green
}

//global scope points, set to score of player once the game ends
class ScoreBoard {
protected:
	int points = 0;
public:
	void Scoreplus()
	{
		points++;
	}
	void ShowScore()
	{
		cout << "Total Points : " << points;
	}
	int getpoints() {
		return points;
	}
};

//dots in each map to be eaten to win
const int getMediumTargetScore() {
	return 172;
}
const int getEasyTargetScore() {
	return 121;//121
}
const int getHardTargetScore() {
	return 358;
}


class Audio {
public:
	Audio() {}
	void virtual PlayAudio(char n)
	{

		if (n == '1')
		{
			PlaySound(TEXT("8-Bit-Cody-Rhodes.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		if (n == '2')
		{
			PlaySound(TEXT("Worlds Apart (Sami Zayn WWE Theme) [8 Bit Tribute to CFO$ and WWE] - 8 Bit Universe.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		if (n == '3')
		{
			PlaySound(TEXT("Cult of Personality (CM Punk Theme) [8 Bit Tribute to Living Colour & CM Punk].wav"), NULL, SND_FILENAME | SND_ASYNC);

		}
		if (n == '4')
		{
			PlaySound(TEXT("Next Big Thing [8 Bit Tribute to Brock Lesnar & WWE] - 8 Bit Universe.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
	}
};
class losewinSound : public Audio
{
public:
	losewinSound() :Audio() {}

	void virtual PlayAudio(string n)
	{
		if(n=="win"){
			PlaySound(TEXT("mixkit-video-game-win-2016.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		if(n=="lose"){
		PlaySound(TEXT("8-bit-video-game-lose-sound-version-4-145477.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		
	}

};

class map {//MAPCLASS

public:
	friend class Player;

	char map1[18][32] = {
	"###############################",
	"|   #                 #       |",
	"|... .................#.......|",
	"|   #                 ### ##  |",
	"|...####                 .....|",
	"|      ########  ########     |",
	"|                             |",
	"|      # ............. #      |",
	"|  ... #    .......       ... |",
	"|  ... ###  ####    ...#  ... |",
	"|        ............. # #####|",
	"|      #               #      |",
	"| .... ### #####   #####      |",
	"|......                #####  |",
	"|     ##############     #    |",
	"|........................#....|",
	"|                             |",
	"###############################" };


	//level 2 hardness map
	char map2[18][32] = {
	"+#############################+",
	"|    |    |    |    |    |    |",
	"|....|....|....|....|....|....|",
	"|.............................|",
	"| #    ################     # |",
	"|                             |",
	"|                             |",
	"|..########.........########..|",
	"|                             |",
	"|.....###################.....|",
	"|                             |",
	"|..########.........########..|",
	"|                             |",
	"|.............................|",
	"| #    ################     # |",
	"|.............................|",
	"|    |    |    |    |    |    |",
	"+#############################+" };

	//level 3 hardness map
	char map3[18][32] = {
	"+#############################+",
	"|                             |",
	"|.............................|",
	"|##..##########.##...#########|",
	"|...|.........................|",
	"|.|.|###.|..|...........|.....|",
	"|.|......|..|.|###..|...|..|..|",
	"|.|.#####|..|.|......##.|.....|",
	"|.|...........|###..|......|..|",
	"|.|#####.###.........##.......|",
	"|..........######..#######.###|",
	"|.............................|",
	"|#.###.####......###...#######|",
	"|.............................|",
	"|.............................|",
	"|.............................|",
	"|.............................|",
	"+#############################+" };


	void printmap(int level) {
		switch (level)
		{
		case 1:
			for (int i = 0;i < 18;i++)
			{
				for (int j = 0;j < 32;j++)
				{
					if (map1[i][j] == '#')
					{
						Set_HashColor();//COLOR FOR #
					}
					else if (map1[i][j] == '|')//COLOR FOR |
					{
						Set_BarColor();
					}
					else if (map1[i][j] == '.')//COLOR FOR .
					{
						Set_CoinColor();
					}
					cout << map1[i][j];

				}
				cout << "\n";
			}
			break;
		case 2:
			for (int i = 0;i < 18;i++)
			{
				for (int j = 0;j < 32;j++)
				{
					if (map2[i][j] == '#')
					{
						Set_HashColor();//COLOR FOR #
					}
					else if (map2[i][j] == '|')//COLOR FOR |
					{
						Set_BarColor();
					}
					else if (map2[i][j] == '.')//COLOR FOR .
					{
						Set_CoinColor();
					}
					cout << map2[i][j];

				}
				cout << "\n";
			}
			break;
		case 3:
			for (int i = 0;i < 18;i++)
			{
				for (int j = 0;j < 32;j++)
				{
					if (map3[i][j] == '#')
					{
						Set_HashColor();//COLOR FOR #
					}
					else if (map3[i][j] == '|')//COLOR FOR |
					{
						Set_BarColor();
					}
					else if (map3[i][j] == '.')//COLOR FOR .
					{
						Set_CoinColor();
					}
					cout << map3[i][j];

				}
				cout << "\n";
			}
			break;
		}//MAPPRINTING

	}
	bool checkPoint(int level, int xpos, int ypos) {
		switch (level) {
		case 1:
			if (map1[ypos][xpos] == '.') {
				return true;
			}
			else {
				return false;
			}
			break;
		case 2:
			if (map2[ypos][xpos] == '.') {
				return true;
			}
			else {
				return false;
			}
			break;
		case 3:
			if (map3[ypos][xpos] == '.') {
				return true;
			}
			else {
				return false;
			}
			break;
		default:
			return false;
		}
	}
	void Set_HashColor()//COLOR CHANGING FUNCTIONS 
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 1);//TO BLUE FOR '#', 1=code for blue
	}
	void Set_BarColor()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 3);//TO CYAN FOR '|', 3=code for cyan
	}

};
void SetMap(char tmp_map[][32], map obj, int maplevel)
{
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (maplevel == 1) {
				tmp_map[i][j] = obj.map1[i][j];
			}
			if (maplevel == 2) {
				tmp_map[i][j] = obj.map2[i][j];
			}
			if (maplevel == 3) {
				tmp_map[i][j] = obj.map3[i][j];
			}

		}
	}
}
class entity {//BASE OF PACMAN
protected:
	int Xpos, Ypos;
	char symbol;

public:
	entity() : Xpos(0), Ypos(0), symbol('U') {}//CONSTRUCTOR

	void setpos(int x, int y) {//POSITIONSETTING
		Xpos = x, Ypos = y;
	}
	void setsymbol(char c) {
		symbol = c;
	}

	void moveup() {//MOVEMENTSON X/Y axis through map
		Ypos--;
	}
	void movedown() {
		Ypos++;
	}
	void moveleft() {
		Xpos--;
	}
	void moveright() {
		Xpos++;
	}
	char getSymbol() {
		return symbol;
	}
	int getXpos() {//GETTERSFORPOSITIONS ON X AND Y AXIS
		return Xpos;
	}

	int getYpos() {
		return Ypos;
	}
};

class Pacman : public entity//PACMAN inherits entity 
{
	int goal;
	int level;
	friend Enemy;
public:
	map m2;
	Pacman() : goal(0), level(0) {
		setpos(17, 13);
		setsymbol('P');
	}
	void setGoalnMap(int mapnumber) {
		level = mapnumber;
		if (mapnumber == 1) {
			goal = getEasyTargetScore();
		}
		if (mapnumber == 2) {
			goal = getMediumTargetScore();
		}
		if (mapnumber == 3) {
			goal = getHardTargetScore();
		}
	}
	void SetPColor()//FUNCTION TO SET PACMANS COLOR TO YELLOW
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 6);
	}
	//override = operator
	Pacman& operator=(const Pacman& other) {
		// Check for self-assignment
		if (this != &other) {
			Xpos = other.Xpos;
			Ypos = other.Ypos;
			symbol = other.symbol;
		}
		return *this;
	}
};
class Enemy : public entity {
	Pacman P;
	int level;
	int old_x;
	int old_y;
	map m;
	char m1[18][32];
	friend Player;
public:
	map m2;
	void SetEColor(int color)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
	}

	void setEnemy(int x, int y, char c, Pacman p) {
		setpos(x, y);
		setsymbol(c);
		P = p;
		level = P.level;
		SetMap(m1, m2, level);
	}

};

struct walk
{
	short walk_count;
	short x;
	short y;
	short back;
};

struct target
{
	short x;
	short y;
};

vector<target> walk_queue_Red;
vector<target> walk_queue_Pink;
vector<target> walk_queue_Purple;

vector<walk> BFSArray_Pink;
vector<walk> BFSArray_Red;
vector<walk> BFSArray_Purple;
char tmp_map[18][32];
void AddArray(int x, int y, int wc, int back, string name)
{
	if (tmp_map[y][x] == ' ' || tmp_map[y][x] == '.')
	{
		tmp_map[y][x] = '*';
		walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = wc;
		tmp.back = back;
		if (name == "Red")
		{
			BFSArray_Red.push_back(tmp);
		}
		if (name == "Pink")
		{
			BFSArray_Pink.push_back(tmp);
		}
		if (name == "Purple")
		{
			BFSArray_Purple.push_back(tmp);
		}

	}
}
map global;
void FindPath(int sx, int sy, int x, int y, int level, string name)
{
	if (level == 1) {
		memcpy(tmp_map, global.map1, sizeof(global.map1));
	}
	if (level == 2) {
		memcpy(tmp_map, global.map2, sizeof(global.map2));
	}
	if (level == 3) {
		memcpy(tmp_map, global.map3, sizeof(global.map3));
	}
	if (name == "Red")
	{
		BFSArray_Red.clear();
		walk tmp;
		tmp.x = sx;
		tmp.y = sy;
		tmp.walk_count = 0;
		tmp.back = -1;
		BFSArray_Red.push_back(tmp);
		int i = 0;
		while (i < BFSArray_Red.size())
		{
			if (BFSArray_Red[i].x == x && BFSArray_Red[i].y == y)
			{
				walk_queue_Red.clear();
				target tmp2;
				while (BFSArray_Red[i].walk_count != 0)
				{
					tmp2.x = BFSArray_Red[i].x;
					tmp2.y = BFSArray_Red[i].y;
					walk_queue_Red.push_back(tmp2);

					i = BFSArray_Red[i].back;
				}

				break;
			}

			AddArray(BFSArray_Red[i].x + 1, BFSArray_Red[i].y, BFSArray_Red[i].walk_count + 1, i, "Red");
			AddArray(BFSArray_Red[i].x - 1, BFSArray_Red[i].y, BFSArray_Red[i].walk_count + 1, i, "Red");
			AddArray(BFSArray_Red[i].x, BFSArray_Red[i].y + 1, BFSArray_Red[i].walk_count + 1, i, "Red");
			AddArray(BFSArray_Red[i].x, BFSArray_Red[i].y - 1, BFSArray_Red[i].walk_count + 1, i, "Red");
			i++;
		}

		BFSArray_Red.clear();
	}
	if (name == "Pink")
	{
		BFSArray_Pink.clear();
		walk tmp;
		tmp.x = sx;
		tmp.y = sy;
		tmp.walk_count = 0;
		tmp.back = -1;
		BFSArray_Pink.push_back(tmp);
		int i = 0;
		while (i < BFSArray_Pink.size())
		{
			if (BFSArray_Pink[i].x == x && BFSArray_Pink[i].y == y)
			{
				walk_queue_Pink.clear();
				target tmp2;
				while (BFSArray_Pink[i].walk_count != 0)
				{
					tmp2.x = BFSArray_Pink[i].x;
					tmp2.y = BFSArray_Pink[i].y;
					walk_queue_Pink.push_back(tmp2);

					i = BFSArray_Pink[i].back;
				}

				break;
			}

			AddArray(BFSArray_Pink[i].x + 1, BFSArray_Pink[i].y + 1, BFSArray_Pink[i].walk_count + 1, i, "Pink");
			AddArray(BFSArray_Pink[i].x - 1, BFSArray_Pink[i].y + 1, BFSArray_Pink[i].walk_count + 1, i, "Pink");
			AddArray(BFSArray_Pink[i].x + 1, BFSArray_Pink[i].y + 1, BFSArray_Pink[i].walk_count + 1, i, "Pink");
			AddArray(BFSArray_Pink[i].x + 1, BFSArray_Pink[i].y - 1, BFSArray_Pink[i].walk_count + 1, i, "Pink");
			i++;
		}

		BFSArray_Pink.clear();
	}
	if (name == "Purple")
	{
		BFSArray_Purple.clear();
		walk tmp;
		tmp.x = sx;
		tmp.y = sy;
		tmp.walk_count = 0;
		tmp.back = -1;
		BFSArray_Purple.push_back(tmp);
		int i = 0;
		while (i < BFSArray_Purple.size())
		{
			if (BFSArray_Purple[i].x == x && BFSArray_Purple[i].y == y)
			{
				walk_queue_Purple.clear();
				target tmp2;
				while (BFSArray_Purple[i].walk_count != 0)
				{
					tmp2.x = BFSArray_Purple[i].x;
					tmp2.y = BFSArray_Purple[i].y;
					walk_queue_Purple.push_back(tmp2);

					i = BFSArray_Purple[i].back;
				}

				break;
			}

			AddArray(BFSArray_Purple[i].x + 1, BFSArray_Purple[i].y + 1, BFSArray_Purple[i].walk_count + 1, i, "Purple");
			AddArray(BFSArray_Purple[i].x - 1, BFSArray_Purple[i].y + 1, BFSArray_Purple[i].walk_count + 1, i, "Purple");
			AddArray(BFSArray_Purple[i].x + 1, BFSArray_Purple[i].y + 1, BFSArray_Purple[i].walk_count + 1, i, "Purple");
			AddArray(BFSArray_Purple[i].x + 1, BFSArray_Purple[i].y - 1, BFSArray_Purple[i].walk_count + 1, i, "Purple");

			AddArray(BFSArray_Purple[i].x + 1, BFSArray_Purple[i].y - 1, BFSArray_Purple[i].walk_count + 1, i, "Purple");
			AddArray(BFSArray_Purple[i].x - 1, BFSArray_Purple[i].y - 1, BFSArray_Purple[i].walk_count + 1, i, "Purple");
			AddArray(BFSArray_Purple[i].x - 1, BFSArray_Purple[i].y + 1, BFSArray_Purple[i].walk_count + 1, i, "Purple");
			AddArray(BFSArray_Purple[i].x - 1, BFSArray_Purple[i].y - 1, BFSArray_Purple[i].walk_count + 1, i, "Purple");

			i++;
		}

		BFSArray_Purple.clear();
	}
}

class Player//Player class controls the  
{
	losewinSound l1;
	string name;
	int score;
	int target;
	int level;
	int speed;
	map m2;
	ScoreBoard SB;
	Pacman P;
	Enemy Red;
	Enemy Pink;
	Enemy Purple;
	friend PlayersData;

public:

	void setTarget(int level) {
		if (level == 1)
		{
			target = getEasyTargetScore();
		}
		if (level == 2)
		{
			target = getMediumTargetScore();
		}
		if (level == 3)
		{
			target = getHardTargetScore();
		}
	}
	void setSpeed(int level) {
		speed = 3;
		if (level == 1) {
			speed = 1;
		}
		if (level == 2) {
			speed = 2;
		}
	}
	void setInfo(string n, int maplevel)
	{
		name = n;
		level = maplevel;
		score = 0;
		setTarget(maplevel);
		P.setGoalnMap(maplevel);
		//Hard coded and fixed ghosts
		Red.setEnemy(1, 1, 'G', P);
		Pink.setEnemy(16, 1, 'G', P);
		Purple.setEnemy(8, 1, 'G', P);
		setSpeed(maplevel);

	}
	void virtual move() {
		if (_kbhit()) {
			char presskey = _getch();
			if (presskey == 72)//UP arrow key ASCI
			{
				if (level == 1)
				{
					if (m2.map1[P.getYpos() - 1][P.getXpos()] == '.')//MOVEVALIDITYFOR UPWARD DIRECTION
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";
						m2.map1[P.getYpos() - 1][P.getXpos()] = ' ';
						P.moveup();
						SB.Scoreplus();
						//points++;
					}
					if (m2.map1[P.getYpos() - 1][P.getXpos()] == ' ')
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";
						P.moveup();
					}

	 			}
				if (level == 2)
				{
					if (m2.map2[P.getYpos() - 1][P.getXpos()] == '.')//MOVEVALIDITYFOR UPWARD DIRECTION
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";
						m2.map2[P.getYpos() - 1][P.getXpos()] = ' ';
						P.moveup();
						SB.Scoreplus();
						//points++;
					}
					if (m2.map2[P.getYpos() - 1][P.getXpos()] == ' ')
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";
						P.moveup();

					}
				}
				if (level == 3)
				{
					if (m2.map3[P.getYpos() - 1][P.getXpos()] == '.')//MOVEVALIDITYFOR UPWARD DIRECTION
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";
						m2.map3[P.getYpos() - 1][P.getXpos()] = ' ';
						P.moveup();
						SB.Scoreplus();//points++;
					}
					if (m2.map3[P.getYpos() - 1][P.getXpos()] == ' ')//MOVEVALIDITYFOR UPWARD DIRECTION
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";
						P.moveup();
					}
				}
			}
			if (presskey == 80)
			{
				if (level == 1)
				{
					if (m2.map1[P.getYpos() + 1][P.getXpos()] == ' ' || m2.map1[P.getYpos() + 1][P.getXpos()] == '.')//MOVEVALIDITYFOR DOWNWWARD DIRECTION
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";
						if (m2.map1[P.getYpos() + 1][P.getXpos()] == '.') {
							m2.map1[P.getYpos() + 1][P.getXpos()] = ' ';
							SB.Scoreplus();//points++;
						}
						P.movedown();
					}
				}
				if (level == 2)
				{
					if (m2.map2[P.getYpos() + 1][P.getXpos()] == ' ' || m2.map2[P.getYpos() + 1][P.getXpos()] == '.')//MOVEVALIDITYFOR DOWNWWARD DIRECTION
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";

						if (m2.map2[P.getYpos() + 1][P.getXpos()] == '.') {
							m2.map2[P.getYpos() + 1][P.getXpos()] = ' ';
							SB.Scoreplus();//points++;
						}
						P.movedown();
					}
				}
				if (level == 3)
				{
					if (m2.map3[P.getYpos() + 1][P.getXpos()] == ' ' || m2.map3[P.getYpos() + 1][P.getXpos()] == '.')//MOVEVALIDITYFOR DOWNWWARD DIRECTION
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";

						if (m2.map3[P.getYpos() + 1][P.getXpos()] == '.') {
							m2.map3[P.getYpos() + 1][P.getXpos()] = ' ';
							SB.Scoreplus();//points++;
						}
						P.movedown();
					}
				}

			}
			if (presskey == 75)
			{
				if (level == 1)
				{
					if (m2.map1[P.getYpos()][P.getXpos() - 1] == ' ' || m2.map1[P.getYpos()][P.getXpos() - 1] == '.')//MOVEVALIDITYFOR RIGHT DIRECTION
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";

						if (m2.map1[P.getYpos()][P.getXpos() - 1] == '.')
						{
							m2.map1[P.getYpos()][P.getXpos() - 1] = ' ';
							SB.Scoreplus();//points++;
						}
						P.moveleft();
					}
				}
				if (level == 2)
				{
					if (m2.map2[P.getYpos()][P.getXpos() - 1] == ' ' || m2.map2[P.getYpos()][P.getXpos() - 1] == '.')//MOVEVALIDITYFOR RIGHT DIRECTION
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";

						if (m2.map2[P.getYpos()][P.getXpos() - 1] == '.')
						{
							m2.map2[P.getYpos()][P.getXpos() - 1] = ' ';
							SB.Scoreplus();//points++;
						}
						P.moveleft();
					}
				}
				if (level == 3)
				{
					if (m2.map3[P.getYpos()][P.getXpos() - 1] == ' ' || m2.map3[P.getYpos()][P.getXpos() - 1] == '.')//MOVEVALIDITYFOR RIGHT DIRECTION
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";

						if (m2.map3[P.getYpos()][P.getXpos() - 1] == '.')
						{
							m2.map3[P.getYpos()][P.getXpos() - 1] = ' ';
							SB.Scoreplus();//points++;
						}
						P.moveleft();
					}
				}

			}
			if (presskey == 77)
			{
				if (level == 1)
				{
					if (m2.map1[P.getYpos()][P.getXpos() + 1] == ' ' || m2.map1[P.getYpos()][P.getXpos() + 1] == '.')//MOVEVALIDITYFOR LEFT DIRECTION
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";

						if (m2.map1[P.getYpos()][P.getXpos() + 1] == '.') {
							m2.map1[P.getYpos()][P.getXpos() + 1] = ' ';
							SB.Scoreplus();//points++;
						}
						P.moveright();
					}
				}
				if (level == 2)
				{
					if (m2.map2[P.getYpos()][P.getXpos() + 1] == ' ' || m2.map2[P.getYpos()][P.getXpos() + 1] == '.')//MOVEVALIDITYFOR LEFT DIRECTION
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";

						if (m2.map2[P.getYpos()][P.getXpos() + 1] == '.') {
							m2.map2[P.getYpos()][P.getXpos() + 1] = ' ';
							SB.Scoreplus();//points++;
						}
						P.moveright();
					}
				}
				if (level == 3)
				{
					if (m2.map3[P.getYpos()][P.getXpos() + 1] == ' ' || m2.map3[P.getYpos()][P.getXpos() + 1] == '.')//MOVEVALIDITYFOR LEFT DIRECTION
					{
						gotoxy(P.getXpos(), P.getYpos());
						cout << " ";

						if (m2.map3[P.getYpos()][P.getXpos() + 1] == '.') {
							m2.map3[P.getYpos()][P.getXpos() + 1] = ' ';
							SB.Scoreplus();//points++;
						}
						P.moveright();
					}
				}
			}
		}
	}
	void playercontroling()//PLAYER CONTROLS Pacman in the selected map
	{
		int win = 0;
		int old_x;
		int old_y;
		int frame = 0;
		int speedmod = 2;
		//bool represents that ghosts are not at any point containing position
		bool pink = false, red = false, purple = false;
		if (level == 2)
		{
			speedmod = 3;
		}
		if (level == 1)
		{
			speedmod = 4;
		}
		system("cls");
		P.m2.printmap(level);
		//Pacman initial position
		gotoxy(P.getXpos(), P.getYpos());
		P.SetPColor();
		cout << P.getSymbol();
		//Enemies(Red, Pink and Purple) initial positions
		gotoxy(Red.Xpos, Red.Ypos);
		Red.SetEColor(4);
		cout << Red.symbol;
		gotoxy(Pink.Xpos, Pink.Ypos);
		Pink.SetEColor(13);
		cout << Pink.symbol;
		gotoxy(Purple.Xpos, Purple.Ypos);
		Purple.SetEColor(5);
		cout << Purple.symbol;
		//CLEAR SCREEN FOR UPDATE;
		while (true) {
			gotoxy(P.getXpos(), P.getYpos());
			cout << " ";
			gotoxy(Red.Xpos, Red.Ypos);
			if (red == false) { cout << " "; }
			else {
				Set_CoinColor();
				cout << ".";
			}

			gotoxy(Pink.Xpos, Pink.Ypos);
			if (pink == false) { cout << " "; }
			else {
				Set_CoinColor();
				cout << ".";
			}

			gotoxy(Purple.Xpos, Purple.Ypos);
			if (purple == false) { cout << " "; }
			else {
				Set_CoinColor();
				cout << ".";
			}

			//passing the values to ghosts
			old_x = P.getXpos();
			old_y = P.getYpos();
			move();


			if (old_x != P.getXpos() || old_y != P.getYpos())
			{
				FindPath(Red.Xpos, Red.Ypos, P.getXpos(), P.getYpos(), level, "Red");
				FindPath(Pink.Xpos, Pink.Ypos, P.getXpos(), P.getYpos(), level, "Pink");
				FindPath(Purple.Xpos, Purple.Ypos, P.getXpos(), P.getYpos(), level, "Purple");
			}


			P.SetPColor();	               //P color has been changed here
			gotoxy(P.getXpos(), P.getYpos());
			cout << P.getSymbol();          //P for Pacman by default Printing at updated position
			if (frame % speedmod == 0 && walk_queue_Red.size() != 0)
			{
				Red.Xpos = walk_queue_Red.back().x;
				Red.Ypos = walk_queue_Red.back().y;
				walk_queue_Red.pop_back();
			}
			if (frame % speedmod == 0 && walk_queue_Pink.size() != 0)
			{
				Pink.Xpos = walk_queue_Pink.back().x;
				Pink.Ypos = walk_queue_Pink.back().y;
				walk_queue_Pink.pop_back();
			}
			if (frame % speedmod == 0 && walk_queue_Purple.size() != 0)
			{
				Purple.Xpos = walk_queue_Purple.back().x;
				Purple.Ypos = walk_queue_Purple.back().y;
				walk_queue_Purple.pop_back();
			}
			gotoxy(Red.Xpos, Red.Ypos);
			red = m2.checkPoint(level, Red.Xpos, Red.Ypos);
			Red.SetEColor(4);
			cout << Red.symbol;
			gotoxy(Pink.Xpos, Pink.Ypos);
			pink = m2.checkPoint(level, Pink.Xpos, Pink.Ypos);
			Pink.SetEColor(13);
			cout << Pink.symbol;
			gotoxy(Purple.Xpos, Purple.Ypos);
			purple = m2.checkPoint(level, Purple.Xpos, Purple.Ypos);
			Purple.SetEColor(5);
			cout << Purple.symbol;
			if (SB.getpoints() == target) {
				system("cls");
				l1.PlayAudio("win");
				Set_CONColor(10);
				cout << "CONGRATULATIONS CHAMPION !!";
				Set_CONColor(6);
				Sleep(1000);
				cout << "\n\n\n------------------------------------------------------------\n";
				cout << "*********\n";
				cout << "\n                      ~  YOU WON!   ~\n";
				cout << "\n*********\n";
				cout << "------------------------------------------------------------\n\n\n";
				gotoxy(17, 13);
				score = SB.getpoints();
				break;
			}
			if (Red.Xpos == P.getXpos() && Red.Ypos == P.getYpos())  //enemy caught the player
			{
				system("cls");
				Set_CONColor(4);
				l1.PlayAudio("lose");
				cout << "GAME OVER!";
				Sleep(1000);
				Set_CONColor(6);
				cout << "\n\n\n------------------------------------------------------------\n";
				cout << "*******************************************************************\n";
				cout << "\n                      ~  YOU GOT CAUGHT!   ~\n";
				cout << "\n*****************************************************************\n";
				cout << "------------------------------------------------------------\n\n\n";
				SB.ShowScore();
				score = SB.getpoints();
				break;
			}
			if (Pink.Xpos == P.getXpos() && Pink.Ypos == P.getYpos())  //enemy caught the player
			{
				system("cls");
				Set_CONColor(4);
				l1.PlayAudio("lose");
				cout << "GAME OVER!";
				Sleep(1000);
				Set_CONColor(6);
				cout << "\n\n\n------------------------------------------------------------\n";
				cout << "*******************************************************************\n";
				cout << "\n                      ~  YOU GOT CAUGHT!   ~\n";
				cout << "\n*****************************************************************\n";
				cout << "------------------------------------------------------------\n\n\n";
				SB.ShowScore();
				score = SB.getpoints();
				break;
			}
			if (Purple.Xpos == P.getXpos() && Purple.Ypos == P.getYpos())  //enemy caught the player
			{
				system("cls");
				Set_CONColor(4);
				l1.PlayAudio("lose");
				cout << "GAME OVER!";
				Sleep(1000);
				Set_CONColor(6);
				cout << "\n\n\n------------------------------------------------------------\n";
				cout << "*******************************************************************\n";
				cout << "\n                      ~  YOU GOT CAUGHT   ~\n";
				cout << "\n*****************************************************************\n";
				cout << "------------------------------------------------------------\n\n\n";
				SB.ShowScore();
				score = SB.getpoints();
				break;
			}
			gotoxy(35, 9);
			SB.ShowScore();
			Sleep(60);
			frame++;




		}//while

	}//player controlling
	string data() {

		return "Name: " + name + " Score: " + to_string(score) + " Level: " + to_string(level);
	}


};
class PlayersData {
	string filename = "PacmanGameRecordsList.txt";
public:
	void Entry(Player& p) {
		string Data = p.data();
		ofstream file(filename, ios::app);
		if (file.is_open()) {
			file<<"\n "<<Data;
			file<<"\n--------------------------------";
			cout << "Player Data added to game history\n";
			file.close();
		}
		else {
			cout << "Error opening file!\n";
		}
	}
	void ShowPlayers() {
		string data;
		ifstream file;
		if (file.good()) {
			file.open(filename, ios::in);
			if (file.is_open()) {
				while (getline(file, data)) {

					cout << data << endl;
				}
				file.close();
			}
			else {
				cout << "Error opening file!\n";
			}
		}

	}
};

class Game//GAME CONSISTS OF a player whos in control and the Map
{
	Player p1;
	PlayersData recorder;
	map M;
	Audio song;
public:
	void displayintro()
	{
		cout << "\n\n\n\n\n                                   (22K4347)-SABIH UDDIN\n                                   (22k4170)-ANAS KHAN\n                                   (22K4542)-ARHAM KHAN\n                                      PRESENT : " << endl;
		song.PlayAudio('2');
		Sleep(3000);
		gotoxy(22, 10);
		Set_CONColor(5);
		cout << "PPPPPPPP   AAAAAAAA  CCCCCCCC  MMM    MMM   AAAAAAAA  NNN        NN";
		gotoxy(22, 11);
		cout << "PP    PP   AA    AA  CC        MMMM  MMMM   AA    AA  NNNNNN     NN";
		gotoxy(22, 12);
		cout << "PP    PP   AA    AA  CC        MM  MM  MM   AA    AA  NN  NN     NN";
		gotoxy(22, 13);
		cout << "PP    PP   AA    AA  CC        MM  MM  MM   AA    AA  NN   NN    NN";
		gotoxy(22, 14);
		cout << "PP    PP   AA    AA  CC        MM  MM  MM   AA    AA  NN    NN   NN";
		gotoxy(22, 15);
		cout << "PP    PP   AA    AA  CC        MM  MM  MM   AA    AA  NN     NN  NN";
		gotoxy(22, 16);
		cout << "PPPPPPPP   AAAAAAAA  CC        MM      MM   AAAAAAAA  NN      NN NN";
		gotoxy(22, 17);
		cout << "PP         AA    AA  CC        MM      MM   AA    AA  NN        NNN";
		gotoxy(22, 18);
		cout << "PP         AA    AA  CC        MM      MM   AA    AA  NN         NN";
		gotoxy(22, 19);
		cout << "PP         AA    AA  CCCCCCCC  MM      MM   AA    AA  NN         NN ";
		Sleep(4000);
		system("cls");

	}
	void displaymainmenu(){//DISPLAY GAMES MAIN MENU
			gotoxy(44, 10);
			cout << "[ MAIN MENU ]";
			gotoxy(44, 13);
			cout << "[ PLAY GAME ]:";
			gotoxy(46, 14);
			cout << "(Press P)  ";
			gotoxy(44, 17);
			cout << "[ CHANGE MUSIC ]:";
			gotoxy(46, 18);
			cout << "(Press M)  ";
			gotoxy(44, 21);
			cout << "[ EXIT GAME ] : ";
			gotoxy(46, 22);
			cout << "(Press E)  ";
			gotoxy(44, 25);
			cout << "[ PLAYERS DATA ] : ";
			gotoxy(46, 26);
			cout << "(press D)    ";
			gotoxy(44, 29);
			cout << "CHOICE : ";		
	}
	void displaymusicmenu()//DISPLAY MUSIC MENU
	{
		cout << "\n[MUSIC MENU]";
		cout << "\n\t\t1-[THY KINGDOM] (DEFAULT) ";
		cout << "\n\t\t2-[WORLD'S APART] ";
		cout << "\n\t\t3-[CULT OF PERSONALITY]";
		cout << "\n\t\t4-[NEXT BIG THING]";
		cout << "\n\nChoice : ";		
	}
	void setInfo(string n, int map) {
		p1.setInfo(n, map);
	}
	void gamewind()//FUNCTION TO RUN GAME
	{
		char ck;
		char choice;
		string name;int levelnum;
		nocursor();//HIDES CURSOR

		displayintro();
		while (true)
		{
			char ck;
		gotoxy(32,1);	
	    cout << "######################################################################";
	    gotoxy(32,2);
       	cout << "#  PPPPPPPP   AAAAAAAA  CCCCCCCC  MMM    MMM   AAAAAAAA  NNN     NN  #";
		gotoxy(32,3);       	
		cout << "#  PP    PP   AA    AA  CC        MMMM  MMMM   AA    AA  NNNNN   NN  #";
		gotoxy(32,4);
		cout << "#  PP    PP   AA    AA  CC        MM  MM  MM   AA    AA  NN  NN  NN  #";
		gotoxy(32,5);
		cout << "#  PPPPPPPP   AAAAAAAA  CC        MM  MM  MM   AAAAAAAA  NN   NN NN  #";
		gotoxy(32,6);
		cout << "#  PP         AA    AA  CC        MM  MM  MM   AA    AA  NN    NNNN  #";
		gotoxy(32,7);
		cout << "#  PP         AA    AA  CCCCCCCC  MM  MM  MM   AA    AA  NN     NNN  #";
		gotoxy(32,8);
		cout << "######################################################################";
			Set_CONColor(11);
			displaymainmenu();//willdisplay games mainmenu;
			cin >> ck;
			ck =toupper(ck);
			if (ck == 'e' || ck == 'E')
			{
				cout << "GoodBye ! ";
				break;
			}
			else {
				system("cls");
				switch (ck) {
				case 'P':
				{
					gotoxy(44,10);
					cout<<"[Level Selection Menu]";
					gotoxy(44,12);
					cout << "Enter Name : ";
					cin>>name;
					gotoxy(44,14); 
					cout << "Select From Levels :" ;
					gotoxy(44,15);
					cout<<"1-Easy";
					gotoxy(44,16);
					cout<<"2-Medium";
					gotoxy(44,17);
					cout<< "3-Hard  ";
					gotoxy(44,18);
					cout<<"Choice : ";cin >> levelnum;
					if(levelnum>=1&&levelnum<=3){
					p1.setInfo(name, levelnum);
					p1.playercontroling();
					Sleep(5000);
					system("cls");
					recorder.Entry(p1);
					exit(0);
					}
					else{
					cout<<"Choose correct level ! ";
					Sleep(2000);
					system("cls");
					break;
					}
				}

				case 'M':
				{
					displaymusicmenu();
					cin >> choice;
					song.PlayAudio(choice);
					system("cls");
					break;
				}
				case 'D':
				{
					system("cls");
					recorder.ShowPlayers();
					break;
				}

				}//switch
			}//else


		}//while
	}


	void nocursor()//HIDECURSOR
	{
		HideCursor();
	}

};


int main() {//MAINFUCNTION

	Game g;
	g.gamewind();

}