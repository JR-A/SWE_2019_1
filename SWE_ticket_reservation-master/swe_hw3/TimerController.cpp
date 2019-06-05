#include "stdafx.h"
#include "TimerController.h"
#include "Timer.h"
#include "memberManagement.h"

TimerController::TimerController() {}
TimerController::~TimerController() {}

// Function : void TimerController::checkToDeleteTicket(int year, int month, int day, int hour, int minute, MemberManagement *mm)
// Description : �Ű������� ���� [��, ��, ��, �ð�, ��]�� MemberManagement ��ü �����͸� Ÿ�̸ӿ��� �����Ѵ�.
// Parameters : int year, int month, int day, int hour, int minute, MemberManagement *mm
// Return Value : None
// Created: 2019/06/2 21:00 pm
// Author: ���μ�
// mail: his9989@naver.com
void TimerController::checkToDeleteTicket(int year, int month, int day, int hour, int minute, MemberManagement *mm) {
	Timer timer;
	timer.checkDeleteTicket(year, month, day, hour, minute, mm);
}