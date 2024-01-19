#pragma once
#include<vector>

class CHero;
class CSkill;

//英雄属性
struct SAttribute
{
	int hp = 0;
	int def = 0;
	int ad = 0;
	int ap = 0;
	int bj = 0;
	int bjValue = 0;
};
//英雄基类
class CHero {
protected:
	CHero();
	SAttribute mAttribute;
	std::vector<CSkill*> skills;
	int mState = 0;
	bool alive = true;
	const char* name = 0;
public:
	~CHero();
	virtual	void Run();
	virtual void Action(CHero* tag);
	const char* GetName();
	void SetAD(int ad);
	int getAD();
	int getAP();
	int getBJ();
	int getBJValue();
	void SetAP(int ad);
	void SetBJ(int bj);
	void SetHp(int hp);
	void SetDef(int def);
	int subDef(int gj);
	int getDef();
	std::vector<CSkill*>* getSkills();
	void addSkill(CSkill *s);
	void SetName(const char *);
	void damage(int hp);
	void healing(int hp);
	void dead();
	bool isAlive();
	int getHp();
	int getState();
	void setState(int state);
};
//技能
class CSkill
{
protected:
	int cd;
	int ccd;
	void calculate(int tempGj, int gj, CHero* enemy);
public:
	int getCCD();
	void resetCD();
	virtual void Action(CHero* ally, CHero* enemy);
	virtual const char* getName();
	void changeCD();
};

class CNormalAttack : CSkill {
public:
	CNormalAttack();
	void Action(CHero* ally, CHero* enemy);
	const char* getName();
};
//赵云技能
class CWarriorSkillNumber1 : CSkill {
public:
	CWarriorSkillNumber1();
	void Action(CHero* ally, CHero* enemy);
	const char* getName();
};

class CWarriorSkillNumber2 : CSkill {
public:
	CWarriorSkillNumber2();
	void Action(CHero* ally, CHero* enemy);
	const char* getName();
};
//马超技能
class CWarriorSkillNumber3 : CSkill {
public:
	CWarriorSkillNumber3();
	void Action(CHero* ally, CHero* enemy);
	const char* getName();
};

class CWarriorSkillNumber4 : CSkill {
public:
	CWarriorSkillNumber4();
	void Action(CHero* ally, CHero* enemy);
	const char* getName();
};

//张辽技能
class CWarriorSkillNumber5 : CSkill {
public:
	CWarriorSkillNumber5();
	void Action(CHero* ally, CHero* enemy);
	const char* getName();
};

class CWarriorSkillNumber6 : CSkill {
public:
	CWarriorSkillNumber6();
	void Action(CHero* ally, CHero* enemy);
	const char* getName();
};

//典韦技能
class CWarriorSkillNumber7 : CSkill {
public:
	CWarriorSkillNumber7();
	void Action(CHero* ally, CHero* enemy);
	const char* getName();
};

class CWarriorSkillNumber8 : CSkill {
public:
	CWarriorSkillNumber8();
	void Action(CHero* ally, CHero* enemy);
	const char* getName();
};

//庞统技能
class CHealingSkillNumberOne :CSkill {
public:
	CHealingSkillNumberOne();
	void Action(CHero* ally, CHero* enemy);
	const char* getName();
};

class CHealingSkillNumberTwo :CSkill {
public:
	CHealingSkillNumberTwo();
	void Action(CHero* ally, CHero* enemy);
	const char* getName();
};

//贾诩技能
class CHealingSkillNumberThree :CSkill {
public:
	CHealingSkillNumberThree();
	void Action(CHero* ally, CHero* enemy);
	const char* getName();
};

class CHealingSkillNumberFour :CSkill {
public:
	CHealingSkillNumberFour();
	void Action(CHero* ally, CHero* enemy);
	const char* getName();
};
