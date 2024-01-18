#pragma once
class CRandom {
private:
	CRandom() {};
	CRandom(const CRandom&) = delete;
	CRandom& operator=(const CRandom&) = delete;
public:
	void Init();
	int getRandomInt();
	int getRandomIntRange(int max,int min);
	static CRandom& getInstance() {
		static CRandom random;
		return random;
	}

};