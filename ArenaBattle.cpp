/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2014 by Michael Liu                                   *
 *                                                                         *
 *                                                *
 *                                                                         *
 ***************************************************************************/



#include "Library.h"

int main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // Make a handle
    SetConsoleTextAttribute(handle, 14); // Set the color of the text to yellow
	Character* theCharacter = 0;
	srand(time(0));
	cout << "Welcome to Arena Battle!\n";
	cout << "Created by Michael Liu! (Now with updated text)\n\n";
	cout  << "Press ENTER to start the game.";
	cin.get();
	system("cls");
	CharacterMenu(theCharacter);
	MainMenu(theCharacter);
	cout << "\nThanks for playing!\n\n";
	system("PAUSE");
	return 0;
}
