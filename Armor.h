
class Armor
{

public:
	Armor(int nStrength = 0, int nDex = 0, std::string nName1 = "Armor", std::string nName2 = "");
	int GetStrength() const;
	int GetMaxDex() const;
	std::string GetName() const;

private:
	int strength;
	int max_dex;
	std::string name1;
	std::string name2;

	

};
