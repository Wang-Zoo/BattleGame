#pragma once
//Ӣ������
struct SAttribute
{
	int hp = 0;
	int def = 0;
	int ad = 0;
	int ap = 0;
	int bj = 0;
	int bjValue = 0;
};
//Ӣ�ۻ���
class CHero {
protected:
	CHero();
	SAttribute mAttribute;
	int mState = 0;
	bool alive = true;
	const char* name = 0;
public:
	virtual	void Run();
	virtual void Action(CHero* tag);
	const char* GetName();
	void SetAD(int ad);
	void SetAP(int ad);
	void SetBJ(int bj);
	void SetHp(int hp);
	void SetDef(int def);
	int subDef(int gj);
	int getDef();
	void SetName(const char *);
	void damage(int hp);
	void healing(int hp);
	void dead();
	bool isAlive();
	int getHp();
	int getState();
	void setState(int state);
};
//Ӣ�ۼ��ܽӿ�
class CSkill {
protected:
	int qcd;
	int cqcd;
	int rcd;
	int crcd;
public:
	void changeCD();
 	virtual void QSkill(CHero* enemy) = 0;
	virtual void RSkill(CHero* enemy) = 0;
	virtual void NormalAttack(CHero* enemy) = 0;
};