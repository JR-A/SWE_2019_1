#pragma once
#include "stdafx.h"
#include "seller.h"
#include "buyer.h"
#include "memberManagement.h"

// Class : Timer
// Description: �Է¹��� ����ð��� �������� 1���� �ʰ��ϴ� Ƽ���� �����ϴ��� Ȯ���ϴ� Ŭ���� ���
// Created: 2019/06/2 21:00 pm
// Author: ���μ�
// mail: his9989@naver.com
class Timer {
public:
	Timer();
	~Timer();
	// Ƽ���� ��ġ �ð��� ����ð��� ������ ��, 1���� �ʰ��ϸ� �����ϱ� ���� �Լ�
	void checkDeleteTicket(int, int, int, int, int, MemberManagement*);
	// Ƽ���� ��ġ �ð��� ���� �ð��� ���ϱ� ���� �Լ�
	bool compare(int, int, int, int, int, string);
};