#pragma once
#include "stdafx.h"
#include "memberManagement.h"

// Class : TimerUI
// Description: �Է¹��� ����ð��� MemberManagement ������ ��ü�� TimerController���� �����ϴ� �ٿ���� Ŭ����
// Created: 2019/06/2 21:00 pm
// Author: ���μ�
// mail: his9989@naver.com
class TimerUI {
public:
	// �����ڿ� �Ҹ��ڴ� ������ �ʽ��ϴ�.
	TimerUI();
	~TimerUI();
	// �ð� ������(string)�� �Ľ��ϰ� intŸ������ ����ȯ
	void checkTicket(string inputData, MemberManagement *);
};