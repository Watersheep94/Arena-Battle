#include "Library.h"

Character::Character(std::string nName): name(nName) 
{
	itsWeapon = new Weapon(3, "Knife", "");
	itsArmor = new Armor(0, 35, "Unarmored", "");
	lvl = 1;
	exp = 0;
	gold = 0;
	victories = 0;
	expLvlAdvance = 1000;
}

int Character::AttackRole(int d20)
{
	int attack_role;
	int str_mod = (str - 10) / 2;
	attack_role = d20 + lvl + str_mod;
	return attack_role;
}

int Character::Attack()
{
	int str_mod = (str - 10)/2;
	if (str_mod < 0)
		str_mod = 0;
	return itsWeapon->GetStrength() + str_mod;
}

int Character::CalculateArmor()
{
	int defense;
	int temp_dex;

	if (dex > itsArmor->GetMaxDex())
		temp_dex = itsArmor->GetMaxDex();
	
	else
		temp_dex = dex;
	
	int dex_mod = (temp_dex - 10)/2;
	if (dex_mod < 0)
		dex_mod = 0;

	defense = itsArmor->GetStrength() + dex_mod + 10;
	return defense;
}

void Character::TakeDamage(Enemy* &theEnemy)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 12); //set color to light red(enemy attack color)

	int defense = CalculateArmor();
	int d20 = rand() % 20 + 1;

	if (theEnemy->AttackRole(d20) >= defense)
	{
		int damage = theEnemy->Attack();
		if (d20 == 20)
			damage *= 2;

		hp -= damage;

		if (hp <= 0)
			cout << "The " << theEnemy->GetName() << " raises his " << theEnemy->GetWeapon() << " and bashes " << GetName() << "'s skull in!\n\n";

		else
		{

		if (damage <= 3)
			cout << theEnemy->GetName() << " uses his " << theEnemy->GetWeapon() << " and strikes " << GetName() << " for " << damage << " damage!\n\n";
		
		if (damage <= 6 && damage > 3)
			cout << theEnemy->GetName() << " slashes at " << GetName() << " with his " << theEnemy->GetWeapon() << " for " << damage << " damage!\n\n";


		if (damage <= 9 && damage > 6)
			cout << "The " << theEnemy->GetName() << " wrecks " << GetName() << " for " << damage << " damage!\n\n";

		if (damage > 9)
			cout << "The " << theEnemy->GetName() << " stabs " << GetName() << " immensely for " << damage << " damage!\n\n";
		}
	}

	else
	{
		int miss_message = rand() % 3 + 1;
		
		if (miss_message == 1)
			cout << "The " << theEnemy->GetName() << " tries to hit with " << theEnemy->GetWeapon() << " at " << GetName() << " but misses!\n\n";
		if (miss_message == 2)
			cout << "The " << theEnemy->GetName() << " lifts his " << theEnemy->GetWeapon() << " over his head.. but nothing happens!\n\n";
		if (miss_message == 3)
			cout << "The " << theEnemy->GetName() << " lunges forward with its " << theEnemy->GetWeapon() << " and falls!\n\n";
	}

    SetConsoleTextAttribute(handle, 14); // Reset the color of the text to light cyan
}

std::string Character::GetName() const
{
	return name;
}

string Character::GetWeapon() const
{
	return itsWeapon->GetName();
}

string Character::GetArmor() const
{
	return itsArmor->GetName();
}


void Character::SetStats(int nHp, int nStr, int nDex, int nCon)
{
	hp = nHp;
	max_hp = hp;
	str = nStr;
	dex = nDex;
	con = nCon;
}

void Character::GetStats() const
{
	cout << "\n==============================\n";
	cout << name << "'s Stats\n";
	cout << "==============================\n"; 
	cout << "Level: " << lvl << endl;
	cout << "Enemies Vanquished: " << victories << endl;
	cout << "Gold: " << gold << endl;
	cout << "Health: " << hp << endl;
	cout << "Strength: " << str << endl;
	cout << "Dexterity: " << dex << endl;
	cout << "Resistance: " << con << endl;
	cout << "==============================\n\n"; 
	system("PAUSE");
	system("cls");
}

float Character::GetGold() const
{
	return gold;
}

void Character::ChangeWeapon(int weapon)
{
	if (weapon == 1)
	{
		if (gold < 1)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(4, "Sword", "");
			gold -= 1;
			cout << "Weapon purchased.\n";
		}
	}
	
	if (weapon == 2)
	{
		if (gold < 2)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(4, "Long", "sword");
			gold -= 2;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 3)
	{
		if (gold < 5)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(6, "Battle ", "Axe");
			gold -= 5;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 4)
	{
		if (gold < 6)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(6, "Spear", "");
			gold -= 6;
			cout << "Weapon purchased.\n";
		}
	}
	
	if (weapon == 5)
	{
		if (gold < 6.5f)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(6, "Broad", "sword");
			gold -= 6.5f;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 6)
	{
		if (gold < 7)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(6, "Orc ", "Cleaver");
			gold -= 7;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 7)
	{
		if (gold < 8)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(8, "Dragonsbane", "");
			gold -= 8;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 8)
	{
		if (gold < 9)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(8, "Sword ", "of Light");
			gold -= 9;
				cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 9)
	{
		if (gold < 9.5f)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(8, "Sword ", "of Darkness");
			gold -= 9.5f;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 10)
	{
		if (gold < 11)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(10, "Trident ", "of Doom");
			gold -= 11;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 11)
	{
		if (gold < 12)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(10, "Crimson ", "Fury");
			gold -= 12;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 12)
	{
		if (gold < 12.5f)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(10, "Lightsaber", "");
			gold -= 12.5f;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 13)
	{
		if (gold < 16)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(12, "Thor's ", "Hammer");
			gold -= 16;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 14)
	{
		if (gold < 20)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(16, "Double-edged ", "Lightsaber");
			gold -= 20;
			cout << "Weapon purchased.\n";
		}
	}
}

void Character::ChangeArmor(int armor)
{
	if (armor == 1)
	{
		if (gold < 5)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(1, 8, "Rusty ", "Armor");
			gold -= 5;
			cout << "Armor purchased.\n";
		}
	}
	
	if (armor == 2)
	{
		if (gold < 10)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(2, 6, "Iron ", "Armor");
			gold -= 10;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 3)
	{
		if (gold < 15)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(3, 4, "Steel ", "Armor");
			gold -= 15;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 4)
	{
		if (gold < 25)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(3, 5, "Dragon's ", "Armor");
			gold -= 25;
			cout << "Armor purchased.\n";
		}
	}
	
	if (armor == 5)
	{
		if (gold < 50)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(4, 3, "Steel ", "Shield");
			gold -= 50;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 6)
	{
		if (gold < 100)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(4, 4, "Crystal ", "Shield");
			gold -= 100;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 7)
	{
		if (gold < 150)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(5, 2, "Holy ", "Shield");
			gold -= 150;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 8)
	{
		if (gold < 200)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(5, 3, "Shield ", "of Sorcery");
			gold -= 200;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 9)
	{
		if (gold < 225)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(6, 0, "Barrier", "");
			gold -= 225;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 10)
	{
		if (gold < 250)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(6, 1, "Magical ", "Barrier");
			gold -= 250;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 11)
	{
		if (gold < 600)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(7, 0, "Holy ", "Barrier");
			gold -= 600;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 12)
	{
		if (gold < 1000)
			cout << "Not enough gold!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(8, 1, "Iron Man ", "Suit");
			gold -= 1000;
			cout << "Armor purchased.\n";
		}
	}

}

bool Character::isDead()
{
	return (hp <= 0);
}

void Character::DetermineRewards()
{
	int earned_exp;
	int earned_gold;
	if (GetLevel() == 1)
	{
		earned_exp = 150;
		earned_gold = 12;
	}

	if (GetLevel() == 2)
	{
		earned_exp = 75;
		earned_gold = 6;
	}

	if (GetLevel() == 3)
	{
		earned_exp = 35;
		earned_gold = 3;
	}
	
	if (GetLevel() == 4)
	{
		earned_exp = 15;
		earned_gold = 1;
	}
	
	else
	{
		earned_exp = 5;
		earned_gold = 0.5f;
	}

	exp += earned_exp;
	gold += earned_gold;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 9); //set color to light blue
	cout << GetName() << " earns " << earned_exp << " exp and " << earned_gold << "gold.\n\n";
	++victories;
	SetConsoleTextAttribute(handle, 14); //reset color to yellow
}

void Character::CheckLevelUp()
{
	if (exp >= expLvlAdvance)
	{
		cout << GetName() << " has leveled up!\n";
		++lvl;
		expLvlAdvance += 2000;
	}
}

int Character::GetLevel() const
{
	return lvl;
}

void Character::Recover()
{
	hp = max_hp;
}

int Character::GetHP() const
{
	return hp;
}
