#pragma once
class COutput {
	//��Ҫ��Ƴɵ���ģʽ������Ĭ�Ϲ��죬�������죬ͬ�ำֵ��Ҫ������
private:
	COutput();
	COutput(const COutput&) = delete;
	COutput& operator=(const COutput&) = delete;

public:
	//���þ�̬��������ʾһ��������ÿ�ζ��������������󣬴ﵽ����Ч��
	static COutput& getInstance();
};