class Character;

class Enemy
{
public:
	Enemy(std::string nName1, std::string nName2, int nLvl);
	~Enemy();
	int AttackRole(int d20);
	int Attack();
	void TakeDamage(Character* &theCharacter);
	bool isDead();

	//accessor functions
	std::string GetWeapon() const;
	std::string GetArmor() const;
	std::string GetName() const;
	int GetLevel() const;
	int GetHP() const;

private:
	int CalculateArmor();
	void SetStats();
	Weapon* itsWeapon;
	Armor* itsArmor;
	std::string name1;
	std::string name2;
	int hp;
	int str;
	int dex;
	int lvl;
	int con; //only used for generating stats; not used in actual combat
};
