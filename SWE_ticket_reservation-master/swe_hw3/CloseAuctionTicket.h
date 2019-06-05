//CloseAuctionTicket.h
#ifndef _CLOSEAUCTIONTICKET_H
#define _CLOSEAUCTIONTICKET_H
#include "memberManagement.h"
#include <string>
using namespace std;

class HomeTeamCollection;

// Class : CloseAuctionTicket
// Description:  CloseAuctionTicketŬ�����̴�. ���� Ƽ���� �����ϱ� ���� Ŭ����.
// Created: 2019/06/29
// Author: �����
// mail: kn043143@naver.com
class CloseAuctionTicket {
private:
	static CloseAuctionTicket *instance;
	CloseAuctionTicket();

	HomeTeamCollection *homeTeamCollection;
public:
	~CloseAuctionTicket();
	static CloseAuctionTicket *getInstance();

	string closeAuction(MemberManagement *mm, string currentTime);
};

#endif // !_CLOSEAUCTIONTICKET_H

