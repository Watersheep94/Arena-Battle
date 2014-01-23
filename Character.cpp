#include "Library.h"

Character::Character(std::string nName): name(nName) 
{
	itsWeapon = new Weapon(3, "Munch ", "");
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
			cout << "The " << theEnemy->GetName() << " raises his " << theEnemy->GetWeapon() << " and clots " << GetName() << "'s artery!\n\n";

		else
		{

		if (damage <= 3)
			cout << theEnemy->GetName() << " uses its " << theEnemy->GetWeapon() << " and clots " << GetName() << " for " << damage << " damage!\n\n";
		
		if (damage <= 6 && damage > 3)
			cout << theEnemy->GetName() << " clots " << GetName() << " with its " << theEnemy->GetWeapon() << " for " << damage << " damage!\n\n";


		if (damage <= 9 && damage > 6)
			cout << "The " << theEnemy->GetName() << " clots a lot of " << GetName() << " for " << damage << " damage!\n\n";

		if (damage > 9)
			cout << "The " << theEnemy->GetName() << " clots " << GetName() << " immensely for " << damage << " damage!\n\n";
		}
	}

	else
	{
		int miss_message = rand() % 3 + 1;
		
		if (miss_message == 1)
			cout << "The " << theEnemy->GetName() << " tries to clot with " << theEnemy->GetWeapon() << " at " << GetName() << " but misses!\n\n";
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
	cout << "Meals Devoured: " << victories << endl;
	cout << "Fat: " << gold << endl;
	cout << "Health: " << hp << endl;
	cout << "Eating Power: " << str << endl;
	cout << "Eating Accuracy: " << dex << endl;
	cout << "Clot Resistance: " << con << endl;
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
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(4, "Mouth ", "Straighteners");
			gold -= 1;
			cout << "Weapon purchased.\n";
		}
	}
	
	if (weapon == 2)
	{
		if (gold < 2)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(4, "Harder ", "Teeth");
			gold -= 2;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 3)
	{
		if (gold < 5)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(6, "Stronger ", "Stomach");
			gold -= 5;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 4)
	{
		if (gold < 6)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(6, "Steel ", "Teeth");
			gold -= 6;
			cout << "Weapon purchased.\n";
		}
	}
	
	if (weapon == 5)
	{
		if (gold < 6.5f)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(6, "Superdigestive ", "Fluids");
			gold -= 6.5f;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 6)
	{
		if (gold < 7)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(6, "Steel ", "Stomach");
			gold -= 7;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 7)
	{
		if (gold < 8)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(8, "Gold ", "Teeth");
			gold -= 8;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 8)
	{
		if (gold < 9)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(8, "Heart ", "Resistance");
			gold -= 9;
				cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 9)
	{
		if (gold < 9.5f)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(8, "Super ", "Stomach");
			gold -= 9.5f;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 10)
	{
		if (gold < 11)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(10, "Super ", "Teeth");
			gold -= 11;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 11)
	{
		if (gold < 12)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(10, "Super ", "Heart");
			gold -= 12;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 12)
	{
		if (gold < 12.5f)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(10, "Artery ", "Defenses");
			gold -= 12.5f;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 13)
	{
		if (gold < 16)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(12, "Prescription ", "Drugs");
			gold -= 16;
			cout << "Weapon purchased.\n";
		}
	}

	if (weapon == 14)
	{
		if (gold < 20)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsWeapon;
			itsWeapon = new Weapon(16, "Pure ", "Body");
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
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(1, 8, "Immune ", "System");
			gold -= 5;
			cout << "Armor purchased.\n";
		}
	}
	
	if (armor == 2)
	{
		if (gold < 10)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(2, 6, "Stomach ", "Shields");
			gold -= 10;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 3)
	{
		if (gold < 15)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(3, 4, "Power ", "Belly");
			gold -= 15;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 4)
	{
		if (gold < 25)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(3, 5, "Helpful ", "Bacteria");
			gold -= 25;
			cout << "Armor purchased.\n";
		}
	}
	
	if (armor == 5)
	{
		if (gold < 50)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(4, 3, "Heart ", "Shield");
			gold -= 50;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 6)
	{
		if (gold < 100)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(4, 4, "Artery ", "Free");
			gold -= 100;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 7)
	{
		if (gold < 150)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(5, 2, "Cardiac ", "Surgery");
			gold -= 150;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 8)
	{
		if (gold < 200)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(5, 3, "Extra ", "Vein");
			gold -= 200;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 9)
	{
		if (gold < 225)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(6, 0, "Super ", "Defense");
			gold -= 225;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 10)
	{
		if (gold < 250)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(6, 1, "Heart ", "Strong");
			gold -= 250;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 11)
	{
		if (gold < 600)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(7, 0, "Super ", "Surgery");
			gold -= 600;
			cout << "Armor purchased.\n";
		}
	}

	if (armor == 12)
	{
		if (gold < 1000)
			cout << "Not enough fat!\n";
		
		else
		{
			delete itsArmor;
			itsArmor = new Armor(8, 1, "Superawesome ", "Defense");
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
	cout << GetName() << " earns " << earned_exp << " exp and " << earned_gold << "fat.\n\n";
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
