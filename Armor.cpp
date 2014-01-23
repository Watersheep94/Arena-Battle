#include "Library.h"

Armor::Armor(int nStrength, int nDex, std::string nName1, std::string nName2): strength(nStrength), max_dex(nDex), name1(nName1), name2(nName2) {}

string Armor::GetName() const
{
	return (name1 + name2);
}

int Armor::GetStrength() const
{
	return strength;
}

int Armor::GetMaxDex() const
{
	return max_dex;
}
