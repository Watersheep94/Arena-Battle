#include "Library.h"

Enemy* theEnemy = 0;

bool* pLvl = 0;
bool bProgress = false;  //saves the number of levels unlocked
bool bLevels[20];

void checkEnemy(Character* &theCharacter, int enemy);
void determineEnemy(Character* &theCharacter, int enemy);
void battle(Character* &theCharacter, Enemy* &theEnemy);

//time function
void wait(int seconds);

void FightMenu(Character* &theCharacter)
{
	if (!bProgress)
	{
		bLevels[0] = true;
		int i;
		for (i = 1; i != 20; ++i)
		bLevels[i] = false;
		bProgress = true;
	}
	bool bQuit = false;
	int enemy = 0;
	while (!bQuit)
	{
	cout << "\n==============================\n";
	cout << "Battlegrounds\n";
	cout << "==============================\n";
	
	if(bLevels[0])
		cout << "1.Thief\n";

	if(bLevels[1])
		cout << "2.Orc\n";

	if(bLevels[2])
		cout << "3.Troll\n";

	if(bLevels[3])
		cout << "4.Wizard\n";

	if(bLevels[4])
		cout << "5.Dark Wizard\n";

	if(bLevels[5])
		cout << "6.Dark Knight\n";

	if(bLevels[6])
		cout << "7.General\n";

	if(bLevels[7])
		cout << "8.Legendard Swordsman\n";

	if(bLevels[8])
		cout << "9.Giant\n";

	if(bLevels[9])
		cout << "10.Demon\n";
	
	if(bLevels[10])
		cout << "11.Jaime Lannister\n";

	if(bLevels[11])
		cout << "12.White Walker\n";
	
	if(bLevels[12])
		cout << "13.Dark Angel\n";

	if(bLevels[13])
		cout << "14.Lucifer\n";
	
	if(bLevels[14])
		cout << "15.Tywin Lannister\n";

	if(bLevels[15])
		cout << "16.Genghis Khan\n";

	if(bLevels[16])
		cout << "17.Vladmir Putin\n";

	if(bLevels[17])
		cout << "18.Anti-Christ\n";
	
	if(bLevels[18])
		cout << "19.Joseph Stalin\n";
	
	if(bLevels[19])
		cout << "20.Adolf Hitler\n";

	cout << "21. Exit Feeding Grounds\n\n";

	cout << "Choose your opponent: ";
	cin >> enemy;
	system("cls");

	if(enemy == 21)
		bQuit = true;

	else if(enemy > 21)
		cout << "No such enemy\n";

	else
		checkEnemy(theCharacter, enemy);
	}	
}

void checkEnemy(Character* &theCharacter, int enemy)
{
	if (bLevels[enemy - 1] == true)
		determineEnemy(theCharacter, enemy);

	else
	cout << "Selected enemy not unlocked yet.\n";
}

void determineEnemy(Character* &theCharacter, int enemy)
{
	if (enemy == 1)
		theEnemy = new Enemy("The ", "Thief", 1);
	
	if (enemy == 2)
		theEnemy = new Enemy("The ", "Orc", 2);

	if (enemy == 3)
		theEnemy = new Enemy("The ", "Troll", 3);

	if (enemy == 4)
		theEnemy = new Enemy("The ", "Wizard", 4);

	if (enemy == 5)
		theEnemy = new Enemy("The ", "Dark Wizard", 5);

	if (enemy == 6)
		theEnemy = new Enemy("The ", "Dark Knight", 6);

	if (enemy == 7)
		theEnemy = new Enemy("The ", "General", 7);

	if (enemy == 8)
		theEnemy = new Enemy("The ", "Lengendard Swordsman", 8);

	if (enemy == 9)
		theEnemy = new Enemy("The ", "Giant", 9);

	if (enemy == 10)
		theEnemy = new Enemy("The ", "Demon", 10);

	if (enemy == 11)
		theEnemy = new Enemy("Jaime ", "Lannister", 11);

	if (enemy == 12)
		theEnemy = new Enemy("The ", "White Walker", 12);

	if (enemy == 13)
		theEnemy = new Enemy("The ", "Dark Angel", 13);

	if (enemy == 14)
		theEnemy = new Enemy("Lucifer", "", 14);

	if (enemy == 15)
		theEnemy = new Enemy("Tywin ", "Lannister", 15);

	if (enemy == 16)
		theEnemy = new Enemy("Genghis ", "Khan", 16);

	if (enemy == 17)
		theEnemy = new Enemy("Vladmir ", "Putin", 17);

	if (enemy == 18)
		theEnemy = new Enemy("The ", "Anti-Christ", 18);

	if (enemy == 19)
		theEnemy = new Enemy("Joseph ", "Stalin", 19);

	if (enemy == 20)
		theEnemy = new Enemy("Adolf ", "Hitler", 20);


	battle(theCharacter, theEnemy);
}

void battle(Character* &theCharacter, Enemy* &theEnemy)
{
	cout << "\t=========================================\n";
	cout << "\t\t" << theCharacter->GetName() << "\t vs. \t" << theEnemy->GetName() << endl;
	cout << "\t\tHP: " << theCharacter->GetHP() << " \t\t HP: " << theEnemy->GetHP() << endl;
	cout << "\t=========================================\n\n";

	while (!theCharacter->isDead() && !theEnemy->isDead())
	{
		theEnemy->TakeDamage(theCharacter);
		if (theEnemy->isDead())
			break;
		wait(2);
		theCharacter->TakeDamage(theEnemy);
		wait(2);
	}
	
	if (theCharacter->isDead())
		cout << "You have fallen. " << theCharacter->GetName() << " now joins the souls lost in overeating.\n\n";
	
	if(theEnemy->isDead())
	{
		cout << theCharacter->GetName() << " has has emerged victorious!\n";
		theCharacter->DetermineRewards();
		bLevels[theEnemy->GetLevel()] = true;
		theCharacter->CheckLevelUp();
	}
	
	delete theEnemy;
	theEnemy = 0;
	theCharacter->Recover();
	system("PAUSE");
	system("cls");
}

void wait (int seconds)
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}
