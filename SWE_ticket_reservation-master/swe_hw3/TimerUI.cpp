#include "stdafx.h"
#include<cstdio>
#include "TimerUI.h"
#include "TimerController.h"
#include "memberManagement.h"


TimerUI::TimerUI() {}
TimerUI::~TimerUI() {}

void TimerUI::checkTicket(string inputData, MemberManagement *mm) {
	// inputData�� �ڷ����� �°� ��ȯ
	string year = inputData.substr(0, 4);
	string month = inputData.substr(5, 7);
	string day = inputData.substr(8, 10);
	string hour = inputData.substr(11, 13);
	string minute = inputData.substr(14, 17);
	TimerController timerC;
	// TimerController (Control Ŭ����)�� checkToDeleteTicket �Լ� ȣ��
	// �Ű������� ����ð��� ��, ��, ��, �ð�, ��, MemberManagement�� ������ ��ü�� ����.
	timerC.checkToDeleteTicket(stoi(year), stoi(month), stoi(day), stoi(hour), stoi(minute), mm);//����� �Ű����� �ѱ��� ����
}