#pragma once
//Ӣ������
struct SAttribute
{
	int hp;
	int def;
	int ad;
	int bj;
	int bjValue;
};
//Ӣ�ۻ���
class CHero {
protected:
	SAttribute mAttribute;
	int mState;
	const char* name = 0;
public:
	virtual	void Run();
	virtual void Action(CHero* tag);
	SAttribute* GetAttribute();
	const char* GetName();
	void SetAD(int ad);
	void SetBJ(int bj);
	void SetName(const char *);
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