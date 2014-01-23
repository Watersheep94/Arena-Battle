class Enemy;

class Character
{
public:
	Character(std::string nName);
	~Character();
	int AttackRole(int d20);
	int Attack();
	void DetermineRewards();
	void CheckLevelUp();
	void TakeDamage(Enemy* &theEnemy);
	void SetStats(int nHp, int nStr, int nDex, int nCon);
	void ChangeWeapon(int weapon);
	void ChangeArmor(int armor);
	void ChangeArmor();
	bool isDead();
	void Recover();
	
	//accessor functions
	float GetGold() const;
	std::string GetWeapon() const;
	std::string GetArmor() const;
	void GetStats() const;
	std::string GetName() const;
	int GetLevel() const;
	int GetHP() const;

private:
	int CalculateArmor();
	Weapon* itsWeapon;
	Armor* itsArmor;
	std::string name;
	int lvl;
	int str;
	int dex;
	int con;
	int max_hp;
	int hp;
	float exp;
	int expLvlAdvance;
	float gold;
	int victories;

};
