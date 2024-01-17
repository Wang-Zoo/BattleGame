#pragma once
//Ӣ������
struct SAttribute
{
	int hp;
	int def;
	int ad;
	int bj;
};
//Ӣ�ۻ���
class CHero {
protected:
	SAttribute mAttribute;
	int mState;
public:
	virtual void Init();
	virtual void Run();
	virtual void Action(CHero* tag);
	virtual const char* GetName();
	SAttribute* GetAttribute();
	int getState();
	void setState(int state);
};
//Ӣ�ۼ��ܽӿ�
class CSkill {
public:
 	virtual void QSkill(SAttribute* attribute) = 0;
	virtual void RSkill(SAttribute* attribute) = 0;
	virtual void NormalAttack(SAttribute* attribute) = 0;
};