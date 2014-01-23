#include "Library.h"

void ChooseName(Character* &theCharacter);
void RollStats(Character* &theCharacter);
void GenerateStats(int& hp, int& str, int& dex, int& con);

//Main character creation function
void CharacterMenu(Character* &theCharacter)
{
	ChooseName(theCharacter);
	RollStats(theCharacter);
}

void ChooseName(Character* &theCharacter)
{
	string name;
	cout << "Enter the name you would like for your Gong.\n";
	cout << "Name: ";
	cin >> name;

	system("cls");
	theCharacter = new Character(name);
	cout << "\nYour Gong, " << theCharacter->GetName() << ", has been created.\n\n";
	
}

void RollStats(Character* &theCharacter)
{
	char roll = 'y';
	int hp, str, dex, con;
	
	while (roll == 'y')
	{
		GenerateStats(hp, str, dex, con);
		cout << "Health: " << hp << endl;
		cout << "Eating Power: " << str << endl;
		cout << "Eating Accuracy: " << dex << endl;
		cout << "Clot Resistance: " << con << endl;
		cout << "\nRoll stats again? (y/n):";
		cin >> roll;
		system("cls");
	}
	system("cls");
	theCharacter->SetStats(hp, str, dex, con);
	cout << theCharacter->GetName() << "'s stats have been set.\n";
}

void GenerateStats(int& hp, int& str, int& dex, int& con)
{
	int total = 35;
	int* highStat;
	int statBalancer = 5;
	
	hp = rand() % total / 4;
	str = rand() % total / 4;
	dex = rand() % total / 4;
	con = rand() % total / 4;

	if (hp <= 5)
		hp += statBalancer;

	if (str <= 5)
		str += statBalancer;

	if (dex <= 5)
		dex += statBalancer;

	if (con <= 5)
		con += statBalancer;

	int stat = rand() % 4 + 1;
