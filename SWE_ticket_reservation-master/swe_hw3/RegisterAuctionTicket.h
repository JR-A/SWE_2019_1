//RegisterAuctionTicket.h
#ifndef _REGISTERAUCTIONTICKET_H
#define _REGISTERAUCTIONTICKET_H
#include <string>
using namespace std;

class HomeTeamCollection;

// Class : RegisterAuctionTicket
// Description: RegisterAuctionTicketŬ�����̴�. ����Ƽ���� ����ϱ� ���� Ŭ����.
// Created: 2019/06/29
// Author: �����
// mail: kn043143@naver.com
class RegisterAuctionTicket {
private:
	static RegisterAuctionTicket *instance;
	RegisterAuctionTicket();

	HomeTeamCollection *homeTeamCollection;
public:
	~RegisterAuctionTicket();
	static RegisterAuctionTicket *getInstance();

	string registerAuctionTickets(string currentTime);
};

#endif // !_REGISTERAUCTIONTICKET_H
