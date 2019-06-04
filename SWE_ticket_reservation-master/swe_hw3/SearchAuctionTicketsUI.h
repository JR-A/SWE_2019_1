//SearchAuctionTicketsUI.h
#ifndef _SEARCHAUCTIONTICKETSUI_H
#define _SEARCHAUCTIONTICKETSUI_H
#include <vector>
#include <string>
using namespace std;

class HomeTeam;
class AuctionTicket;
class SearchAuctionTicketsUI {
private:
	static SearchAuctionTicketsUI *instance;
	SearchAuctionTicketsUI();
	string teamName;
public:
	~SearchAuctionTicketsUI();
	static SearchAuctionTicketsUI *getInstance();

	void startInterface(vector<HomeTeam*> homeTeams);
	string selectHomeTeam(string teamName, string currentTime);
	string selectParticipateAuction(string buyerID, string matchDate, string awayTeam, string seat, string bidAmount);	// �����ھ��̵� [��¥-�ð�] [�������] [�¼���ġ] [�����ݾ�] 

	string getTeamName();
};

#endif // !_SEARCHAUCTIONTICKETSUI_H