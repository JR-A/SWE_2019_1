#pragma once
#include "stdafx.h"
#include "memberManagement.h"

// Class : TimerController
// Description: �Է¹��� ��, ��, ��, �ð�, ��, MemberManagement ������ ��ü�� Timer���� �����ϴ� ��Ʈ�ѷ� Ŭ����
// Created: 2019/06/2 21:00 pm
// Author: ���μ�
// mail: his9989@naver.com
class TimerController {
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
public:
	// �����ڿ� �Ҹ��ڴ� ������ �ʽ��ϴ�.
	TimerController();
	~TimerController();
	void checkToDeleteTicket(int, int, int, int, int, MemberManagement*);
};