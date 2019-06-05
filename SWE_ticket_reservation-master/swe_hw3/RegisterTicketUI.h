#pragma once
#include "stdafx.h"
#include "RegisterTicket.h"

using namespace std;

// Class : RegisterTicketUI
// Description: boundary class�� Ƽ���� ����ϱ� ���� ������ �ް�, membermanagement �� curSessionID�� Ư�� Seller Instance�� �޾ƿ´�.
// Created: 2019/5/29 12:00 pm
// Author: ��μ�
// mail: minseob17@naver.com
class RegisterTicketUI
{
private:
	RegisterTicketUI();
	static RegisterTicketUI* registerTicketUIinst;
public:
	static RegisterTicketUI* getInstance();
	void putTicketInfo(string _price,
		string _matchDate,
		string _homeTeam,
		string _awayTeam,
		string _seat,
		bool _limitedTimeAuction,
		string ID,
		MemberManagement *mm,
		string currentTime);
	~RegisterTicketUI();
};

