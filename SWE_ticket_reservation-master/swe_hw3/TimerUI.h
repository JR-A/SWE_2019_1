#pragma once
#include "stdafx.h"
#include "memberManagement.h"

class TimerUI {
public:
	// �����ڿ� �Ҹ��ڴ� ������ �ʽ��ϴ�.
	TimerUI();
	~TimerUI();
	// �ð� ������(string)�� �Ľ��ϰ� intŸ������ ����ȯ
	void checkTicket(string inputData, MemberManagement *);
};