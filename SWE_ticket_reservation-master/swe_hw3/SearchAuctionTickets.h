//SearchAuctionTickets.h
#ifndef _SEARCHAUCTIONTICKETS_H
#define _SEARCHAUCTIONTICKETS_H
#include <vector>
using namespace std;

class HomeTeamCollection;
class AuctionTicket;

// Class : SearchAuctionTickets
// Description: SearchAuctionTickets Ŭ���� �̴�. ����Ƽ�� ����Ʈ�� ����ϱ� ���� Control�̴�.
// Created: 2019/06/29  
// Author: �����
// mail: kn043143@naver.com
class SearchAuctionTickets {
private:
	static SearchAuctionTickets *instance;
	SearchAuctionTickets();

	HomeTeamCollection *homeTeamCollection;
public:
	~SearchAuctionTickets();
	static SearchAuctionTickets *getInstance();
	vector<AuctionTicket*> showHomeTeamAuctionTickets(string name);

	HomeTeamCollection* getHomeTeamCollection();
};

#endif //!_SEARCHAUCTIONTICKETS_H