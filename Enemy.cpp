#include "Library.h"

Enemy::Enemy(string nName1, string nName2, int nLvl): name1(nName1), name2(nName2), lvl(nLvl)
{
	int weapon;
	int armor;
	
	SetStats();

	if (lvl == 1 || lvl == 2)
	{
		itsWeapon = new Weapon(3, "Normal ", "Clot");
		itsArmor = new Armor(0, 35, "Unarmored", "");
	}

	if (lvl == 3 || lvl == 4 || lvl == 5)
	{
		weapon = rand() % 2 + 1;
		
		if (weapon == 1)
			itsWeapon = new Weapon(4, "Special ", "Clot");

		else
			itsWeapon = new Weapon(4, "Advanced ", "Clot");

		if (lvl == 3)
			itsArmor = new Armor(1, 8, "Protection ", "Shield");
		if (lvl == 4)
			itsArmor = new Armor(2, 6, "Body ", "Blocker");
		if (lvl == 5)
			itsArmor = new Armor(3, 4, "Another ", "Blocker");
	}

	if (lvl == 6 || lvl == 7 || lvl == 8)
	{
		weapon == rand() % 4 + 1;

		if (weapon == 1)
			itsWeapon = new Weapon(6, "Stomach ", "Ulcer");

		if (weapon == 2)
			itsWeapon = new Weapon(6, "Immune ", "Destruction");

		if (weapon == 3)
			itsWeapon = new Weapon(6, "Heart ", "Penetration");

		if (weapon == 4)
			itsWeapon = new Weapon(6, "More ", "Penetration");

		if (lvl == 6)
			itsArmor = new Armor(3, 5, "Bacterial ", "Shield");
		if (lvl == 7)
			itsArmor = new Armor(4, 3, "Fat ", "Stuff");
		if (lvl == 8)
			itsArmor = new Armor(4, 4, "Oil ", "Armor");
	}

	if (lvl == 9 || lvl == 10 || lvl == 11)
	{
		weapon == rand() % 3 + 1;

		if (weapon == 1)
			itsWeapon = new Weapon(8, "Bacterial ", "Release");

		if (weapon == 2)
			itsWeapon = new Weapon(8, "Infection", "");

		if (weapon == 3)
			itsWeapon = new Weapon(8, "Fat ", "Clot");

		if (lvl == 9)
			itsArmor = new Armor(5, 2, "More ", "Fat");
		if (lvl == 10)
			itsArmor = new Armor(5, 3, "Superfat", "");
		if (lvl == 11)
			itsArmor = new Armor(6, 0, "Intense ", "Fat");
	}

	if (lvl == 12 || lvl == 13 || lvl == 14)
	{
		weapon == rand() % 3 + 1;

		if (weapon == 1)
			itsWeapon = new Weapon(10, "Heart ", "Attack");

		if (weapon == 2)
			itsWeapon = new Weapon(10, "Cardiac ", "Arrest");

		if (weapon == 3)
			itsWeapon = new Weapon(10, "Super ", "Infection");

			itsArmor = new Armor(6, 1, "Inpenetrable ", "Armor");		
	}

	if (lvl == 15 || lvl == 16 || lvl == 17)
	{
		itsWeapon == new Weapon(12, "Superduper ", "Infection");
		itsArmor = new Armor(7, 0, "Superduper ", "Armor");
	}

	if (lvl == 18 || lvl == 19 || lvl == 20)
	{
		itsWeapon == new Weapon(16, "Deadly ", "Infection");
		itsArmor = new Armor(8, 1, "Awesome ", "Armor");
	}
}

Enemy::~Enemy()
{
	delete itsWeapon;
	itsWeapon = 0;
	delete itsArmor;
	itsArmor = 0;
}

int Enemy::AttackRole(int d20)
{
	int attack_role;
	int str_mod = ((str + itsWeapon->GetStrength()) - 10) / 2;
	attack_role = d20 + lvl + str_mod;
	return attack_role;
}

int Enemy::Attack()
{
	int str_mod = (str - 10)/2;
	if (str_mod < 0)
		str_mod = 0;
	return itsWeapon->GetStrength() + str_mod;
}

int Enemy::CalculateArmor()
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

void Enemy::TakeDamage(Character* &theCharacter)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 10); //set color to light green(character attack color)

	int defense = CalculateArmor();
	int d20 = rand() % 20 + 1;

	if (theCharacter->AttackRole(d20) >= defense)
	{
		int damage = theCharacter->Attack();
		if (d20 == 20)
			damage *= 2;

		hp -= damage;

		if (hp <= 0)
			cout << theCharacter->GetName() << " uses " << theCharacter->GetWeapon() << " and devours " << GetName() << "'s skull!\n\n";

		else
		{

		if (damage <= 3)
			cout << theCharacter->GetName() << " uses " << theCharacter->GetWeapon() << " and chomps the " << GetName() << " for " << damage << " damage!\n\n";
		
		if (damage > 3 && damage <= 6)
			cout << theCharacter->GetName() << " bites " << GetName() << " using " << theCharacter->GetWeapon() << " for " << damage << " damage!\n\n";

		if (damage > 6 && damage <= 9)
			cout << theCharacter->GetName() << " delivers a powerful munch " << GetName() << " for " << damage << " damage!\n\n";

		if (damage > 9)
			cout << theCharacter->GetName() << " eats the " << GetName() << " for " << damage << " damage!\n\n";
		}
	}

	else
	{
		int miss_message = rand() % 3 + 1;
		
		if (miss_message == 1)
			cout << theCharacter->GetName() << " attempts to eat with " << theCharacter->GetWeapon() << " at the " << GetName() << " but misses!\n\n";
		if (miss_message == 2)
			cout << theCharacter->GetName() << " uses his " << theCharacter->GetWeapon() << " but.. nothing happens!\n\n";
		if (miss_message == 3)
			cout << theCharacter->GetName() << " lunges forward with his " << theCharacter->GetWeapon() << " and falls!\n\n";
	}

	 SetConsoleTextAttribute(handle, 14); // Reset the color of the text to light cyan
}

std::string Enemy::GetName() const
{
	return (name1 + name2);
}

string Enemy::GetWeapon() const
{
	return itsWeapon->GetName();
}

string Enemy::GetArmor() const
{
	return itsArmor->GetName();
}

bool Enemy::isDead()
{
	return (hp <= 0);
}

void Enemy::SetStats()
{
	//generates stats
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

	if (stat == 1)
		highStat = &hp;

	if (stat == 2)
		highStat = &str;

	if (stat == 3)
		highStat = &dex;

	if (stat == 4)
		highStat = &con;
	
	while ((hp + str + dex + con) < total)
	{
		*highStat += 1;	
	}

	while ((hp + str + dex + con) > total)
	{
		*highStat -= 1;	
	}

	con = 0;
	hp+=2;
}

int Enemy::GetLevel() const
{
	return lvl;
}

int Enemy::GetHP() const
{
	return hp;
}
