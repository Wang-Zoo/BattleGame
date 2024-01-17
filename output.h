#pragma once
class COutput {
	//需要设计成单例模式，所以默认构造，拷贝构造，同类赋值都要被禁用
private:
	COutput();
	COutput(const COutput&) = delete;
	COutput& operator=(const COutput&) = delete;

public:
	//采用静态数据来表示一个单例，每次都返回这个输出对象，达到单例效果
	static COutput& getInstance();
};