#pragma once
class Plugin
{
public:
	// ��ʼ�� ֻ����һ��
	virtual void Init() = 0;

	// ��ʾ����
	virtual void Window() = 0;

	// �ں��߼�
	virtual void Run() = 0;

};

