#pragma once
#include "stdafx.h"
#include "seller.h"
#include "buyer.h"
#include "memberManagement.h"

class Timer {
public:
	Timer();
	~Timer();
	// Ƽ���� ��ġ �ð��� ����ð��� ������ ��, 1���� �ʰ��ϸ� �����ϱ� ���� �Լ�
	void checkDeleteTicket(int, int, int, int, int, MemberManagement*);
	// Ƽ���� ��ġ �ð��� ���� �ð��� ���ϱ� ���� �Լ�
	bool compare(int, int, int, int, int, string);
};