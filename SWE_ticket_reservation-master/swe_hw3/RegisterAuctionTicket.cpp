//RegisterAuctionTicket.cpp
#include "RegisterAuctionTicket.h"
#include "SearchAuctionTicketsUI.h"
#include "HomeTeamCollection.h"
#include "TicketCollection.h"
#include "AuctionTicketCollection.h"
#include "HomeTeam.h"
#include "Ticket.h"
#include "AuctionTicket.h"
#include "HomeTeam.h"
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

RegisterAuctionTicket* RegisterAuctionTicket::instance;

RegisterAuctionTicket::RegisterAuctionTicket() {
	this->homeTeamCollection = HomeTeamCollection::getInstance();
}

RegisterAuctionTicket::~RegisterAuctionTicket() {
}

// Function : RegisterAuctionTicket* RegisterAuctionTicket::getInstance()
// Description: �̱��� ������ ���� �Լ� 
// Parameters :   None
// Return Value :  RegisterAuctionTicket�� ������
// Created: 2019/06/29  
// Author: �����
RegisterAuctionTicket* RegisterAuctionTicket::getInstance() {
	RegisterAuctionTicket *newInstance;
	if (instance == nullptr) {
		instance = new RegisterAuctionTicket();
	}
	newInstance = instance;
	return newInstance;
}

// Function : string RegisterAuctionTicket::registerAuctionTickets(string currentTime) 
// Description: ����ð��� Ƽ���� ���ð��� ���Ͽ� ����Ƽ�� ��ü�� �����ϴ� �Լ�
// Parameters :  string currentTime - ���� �ð�
// Return Value :  string - ���� ����Ƽ������ ��ϵ� Ƽ�ϵ��� ���� ���ڿ�
// Created: 2019/06/29
// Author: �����
vector<string> split(string str, char delimiter);
string RegisterAuctionTicket::registerAuctionTickets(string currentTime) {
	string out;

	vector<string> current = split(currentTime, ':');
	int year = stoi(current[0]);
	int month = stoi(current[1]);
	int day = stoi(current[2]);
	int hour = stoi(current[3]);
	int min = stoi(current[4]);

	struct tm currentDate = {};
	currentDate.tm_year = year - 1900;
	currentDate.tm_mon = month - 1;
	currentDate.tm_mday = day;
	currentDate.tm_hour = hour;
	currentDate.tm_min = min;
	time_t currentDateT = mktime(&currentDate);

	vector<HomeTeam*> homeTeams = homeTeamCollection->getHomeTeams();
	vector<Ticket*> tickets;

	int i = 0;
	bool flag;
	for (i = 0; i < homeTeams.size(); i++) {

		tickets = homeTeams[i]->getTicketCollection()->getTickets();

		for (vector<Ticket*>::iterator it = tickets.begin(); it != tickets.end();it++) {

			flag = false;
			string matchDate = (*it)->getMatchDate();
			vector<string> vMatchDate = split(matchDate, ':');
			year = stoi(vMatchDate[0]);
			month = stoi(vMatchDate[1]);
			day = stoi(vMatchDate[2]);
			hour = stoi(vMatchDate[3]);
			min = stoi(vMatchDate[4]);

			struct tm ticketDate = {};
			ticketDate.tm_year = year - 1900;
			ticketDate.tm_mon = month - 1;
			ticketDate.tm_mday = day;
			ticketDate.tm_hour = hour;
			ticketDate.tm_min = min;
			time_t ticketDateT = mktime(&ticketDate);

			//����ð�-Ƽ�Ͻð� �ð��� ���ϱ�
			double     d_diff;
			d_diff = difftime(ticketDateT, currentDateT);		//double difftime( time_t timeEnd, time_t timeStart );

			if (d_diff < (double)86400 && d_diff > (double)21600) {		//�ð����� 6�ð� �̻� 24�ð� �̳� (���� �����ð��� ticket�� matchDate - 6 �ð��̹Ƿ�)
				flag = true;
			}

			if ((*it)->getLimitedTimeAuction() == true && flag == true) {
				struct tm startTime = {};		//���� ���۽ð�
				startTime.tm_year = year - 1900;
				startTime.tm_mon = month - 1;
				startTime.tm_mday = day;
				startTime.tm_hour = hour - 24;		//������ 24�ð� ��
				startTime.tm_min = min;
				time_t startTimeT = mktime(&startTime);

				int printYear = startTime.tm_year + 1900;
				int printMonth = startTime.tm_mon + 1;
				int printDay = startTime.tm_mday;
				int printHour = startTime.tm_hour;		//������ 24�ð� ��
				int printMin = startTime.tm_min;

				string startTimeString;
				startTimeString.append(to_string(printYear)); startTimeString.append(":");
				startTimeString.append(to_string(printMonth)); startTimeString.append(":");
				startTimeString.append(to_string(printDay)); startTimeString.append(":");
				startTimeString.append(to_string(printHour)); startTimeString.append(":");
				startTimeString.append(to_string(printMin));


				struct tm closingTime = {};	//���� �����ð�
				closingTime.tm_year = year - 1900;
				closingTime.tm_mon = month - 1;
				closingTime.tm_mday = day;
				closingTime.tm_hour = hour - 6;	//��� �ð� 6�ð� ��
				closingTime.tm_min = min;
				time_t closingTimeT = mktime(&closingTime);

				printYear = closingTime.tm_year + 1900;
				printMonth = closingTime.tm_mon + 1;
				printDay = closingTime.tm_mday;
				printHour = closingTime.tm_hour;		//������ 6�ð� ��
				printMin = closingTime.tm_min;

				string closingTimeString;
				closingTimeString.append(to_string(printYear)); closingTimeString.append(":");
				closingTimeString.append(to_string(printMonth)); closingTimeString.append(":");
				closingTimeString.append(to_string(printDay)); closingTimeString.append(":");
				closingTimeString.append(to_string(printHour)); closingTimeString.append(":");
				closingTimeString.append(to_string(printMin));

				//���� Ƽ�� ����
				AuctionTicket *auctionTicket = new AuctionTicket((*it)->getPrice(), (*it)->getMatchDate(), (*it)->getHomeTeam(), (*it)->getAwayTeam(), (*it)->getSeat(), (*it)->getLimitedTimeAuction(),(*it)->getSellerID(),(*it)->getBuyerID(),currentTime , startTimeString, closingTimeString, (int)0.5*((*it)->getPrice()));
				homeTeams[i]->getAuctionTicketCollection()->add(auctionTicket);		//���� Ƽ�� �߰�

				//it = homeTeams.at(i)->getTicketCollection()->getTickets().erase(it);	//���� �ִ� Ƽ�� �����
				homeTeams[i]->getTicketCollection()->deleteTicket(*it);

				out.append(to_string(auctionTicket->getPrice())); out.append(" ");
				out.append(auctionTicket->getMatchDate()); out.append(" ");
				out.append(auctionTicket->getHomeTeam()); out.append(" ");
				out.append(auctionTicket->getAwayTeam()); out.append(" ");
				out.append(auctionTicket->getSeat()); out.append(" ");
				out.append(auctionTicket->getClosingTime());
				out.append("\n");
			}

		}
	}
	return out;
}
