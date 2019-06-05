#include "stdafx.h"
#include "SearchRegisteredTicketUI.h"
#include "memberManagement.h"

SearchRegisteredTicketUI* SearchRegisteredTicketUI::searchRegisteredTicketUIinst;

SearchRegisteredTicketUI::SearchRegisteredTicketUI() {}

// Function : static SearchRegisteredTicketUI* getInstance()
// Description: �̱����� ���� �ϳ��� instance�� �Ѱ��ִ� �Լ�
// Parameters : ����
// Return Value : SearchRegisteredTicketUIinst (SearchRegisteredTicketUI�� instance)
// Created: 2019/5/29 12:00 pm
// Author: ��μ�
SearchRegisteredTicketUI* SearchRegisteredTicketUI::getInstance()
{
	if (searchRegisteredTicketUIinst == nullptr)
		searchRegisteredTicketUIinst = new SearchRegisteredTicketUI;
	return searchRegisteredTicketUIinst;
}

// Function : vector<Ticket*> SearchRegisteredTicketUI::searchTicket(MemberManagement* mm, string ID)
// Description: membermanagement�� ID�� seller �ν��Ͻ��� �޾ƿ� �� SearchRegisteredTicket���� �Ѱ��ش�.
// Parameters : MemberManagement* mm, string ID
// Return Value : vector<Ticket*> (control class���� ricketcollection�� �ִ� vector �޾ƿ� ����)
// Created: 2019/5/29 12:00 pm
// Author: ��μ�
vector<Ticket*> SearchRegisteredTicketUI::searchTicket(MemberManagement* mm, string ID)
{
	Seller *s = (mm->getMembers())->getSeller(ID);
	return  SearchRegisteredTicket::getInstance()->listTIcket(s);
}
