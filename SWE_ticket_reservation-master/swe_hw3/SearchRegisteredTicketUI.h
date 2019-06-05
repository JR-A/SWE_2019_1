#pragma once
#include "stdafx.h"
#include "SearchRegisteredTicket.h"
#include "memberManagement.h"

// Class : SearchRegisteredTicketUI
// Description: boundary class�� ������ membermanagement�� ID�� seller �ν��Ͻ��� �޾ƿ´�.
// Created: 2019/5/29 12:00 pm
// Author: ��μ�
// mail: minseob17@naver.com
class SearchRegisteredTicketUI
{
private:
	SearchRegisteredTicketUI();
	static SearchRegisteredTicketUI* searchRegisteredTicketUIinst;
public:
	static SearchRegisteredTicketUI* getInstance();
	vector<Ticket*> searchTicket(MemberManagement*mm, string ID);
};

