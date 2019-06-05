#include "RegisterTicketUI.h"
#include "memberManagement.h"

RegisterTicketUI* RegisterTicketUI::registerTicketUIinst;

RegisterTicketUI::RegisterTicketUI()
{
}

RegisterTicketUI::~RegisterTicketUI()
{
}

// Function : static RegisterTicketUI* getInstance()
// Description: �̱����� ���� �ϳ��� instance�� �Ѱ��ִ� �Լ�
// Parameters : ����
// Return Value : registerTicketUIinst (RegisterTicketUI�� instance)
// Created: 2019/5/29 12:00 pm
// Author: ��μ�
RegisterTicketUI* RegisterTicketUI::getInstance()
{
	if (registerTicketUIinst == nullptr)
		registerTicketUIinst = new RegisterTicketUI();
	return registerTicketUIinst;
}

// Function : void RegisterTicketUI::putTicketInfo(string _price,string _matchDate,string _homeTeam,string _awayTeam,string _seat,bool _limitedTimeAuction,string ID,MemberManagement* mm, string currentTime)
// Description: ���Ϸκ��� �Էµ� Ƽ���� ������ main���� �޾ƿ´�.
// Description: ���ο��� �޾ƿ� membermanagement�� ID�� seller�� �ν��Ͻ��� �޾ƿ� �� Ƽ���� ������ �Բ� RegisterTicket(control class)�� �Ѱ��ش�.
// Parameters : string _price,string _matchDate,string _homeTeam,string _awayTeam,string _seat,bool _limitedTimeAuction,string ID,MemberManagement* mm, string currentTime
// Return Value : ����
// Created: 2019/5/29 12:00 pm
// Author: ��μ�
void RegisterTicketUI::putTicketInfo(string price,
	string matchDate,
	string homeTeam,
	string awayTeam,
	string seat,
	bool limitedTimeAuction,
	string ID,
	MemberManagement *mm,
	string currentTime){
	Seller *s = (mm->getMembers())->getSeller(ID);
	int intprice = atoi(price.c_str());
	RegisterTicket::getInstance()->registerNewTicket(intprice, matchDate, homeTeam, awayTeam, seat, limitedTimeAuction, s, currentTime);
}
