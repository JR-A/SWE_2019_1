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
#include <atltime.h>  //CTime
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

RegisterAuctionTicket* RegisterAuctionTicket::getInstance() {
	RegisterAuctionTicket *newInstance;
	if (instance == nullptr) {
		instance = new RegisterAuctionTicket();
	}
	newInstance = instance;
	return newInstance;
}

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

	vector<HomeTeam*> homeTeams = this->homeTeamCollection->getHomeTeams();
	vector<Ticket*> tickets;
	//AuctionTicket *auctionTicket;

	int i = 0;
	vector<Ticket*>::iterator it;
	bool flag = false;
	while (i < homeTeams.size()) {
		tickets = homeTeams[i]->getTicketCollection()->getTickets();
		for (it = tickets.begin(); it != tickets.end();) {
			string matchDate =(*it)->getMatchDate();
			vector<string> vMatchDate = split(matchDate, ':');
			flag = false;
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

			//현재시간-티켓시간 시간차 구하기
			double     d_diff;
			d_diff = difftime(ticketDateT, currentDateT);		//double difftime( time_t timeEnd, time_t timeStart );
			cout << "d_diff : " << d_diff << endl;
			if (d_diff < (double)86400) {		//24시간 이내이면
				flag = true;
			}
			
			if ((*it)->getLimitedTimeAuction() == true && flag == true) {
				/*
				CTimeSpan hours24(0, -24, 0, 0);
				CTimeSpan hours6(0, -6, 0, 0);
				CTime startTime = ticketTime + hours24;
				CTime closingTime = ticketTime + hours6;
				*/
				//옥션티켓 시작시간, 종료시간 구하기
				struct tm startTime = {};
				startTime.tm_year = year - 1900;
				startTime.tm_mon = month - 1;
				startTime.tm_mday = day;
				startTime.tm_hour = hour - 24 ;		//경기시작 24시간 전
				startTime.tm_min = min;
				time_t startTimeT = mktime(&startTime);

				int printYear = startTime.tm_year + 1900;
				int printMonth = startTime.tm_mon + 1;
				int printDay = startTime.tm_mday;
				int printHour = startTime.tm_hour;		//경기시작 24시간 전
				int printMin = startTime.tm_min;

				string startTimeString;
				startTimeString.append(to_string(printYear)); startTimeString.append(":");
				startTimeString.append(to_string(printMonth)); startTimeString.append(":");
				startTimeString.append(to_string(printDay)); startTimeString.append(":");
				startTimeString.append(to_string(printHour)); startTimeString.append(":");
				startTimeString.append(to_string(printMin));

				//time(&startTimeT);
				//struct tm *tmpS = localtime(&startTimeT);


				struct tm closingTime = {};
				closingTime.tm_year = year - 1900;
				closingTime.tm_mon = month - 1;
				closingTime.tm_mday = day;
				closingTime.tm_hour = hour - 6;	//경기 시간 6시간 전
				closingTime.tm_min = min;
				time_t closingTimeT = mktime(&closingTime);

				printYear = closingTime.tm_year + 1900;
				printMonth = closingTime.tm_mon + 1;
				printDay = closingTime.tm_mday;
				printHour = closingTime.tm_hour;		//경기시작 6시간 전
				printMin = closingTime.tm_min;

				string closingTimeString;
				closingTimeString.append(to_string(printYear)); closingTimeString.append(":");
				closingTimeString.append(to_string(printMonth)); closingTimeString.append(":");
				closingTimeString.append(to_string(printDay)); closingTimeString.append(":");
				closingTimeString.append(to_string(printHour)); closingTimeString.append(":");
				closingTimeString.append(to_string(printMin));
				//time(&closingTimeT);
				//struct tm *tmpC = localtime(&closingTimeT);

				//const char* fmt = "%Y:%m:%d:%k:%M";

				/*
				char startbuf[50];
				char closingbuf[50];
				strftime(startbuf, sizeof(startbuf), fmt,tmpS);		//time_t to format char			에러ㅔ러에러에러에러에러에러에러에러에러
				strftime(closingbuf, sizeof(closingbuf), fmt, tmpC);
				*/
				//string startTimeString(startbuf);		//char to string
				//string closingTimeString(closingbuf);

				//string startTimeString = startTimeT.Format("%Y:%m:%d:%H:%M");
				//string closingTimeString = closingTimeT.Format("%Y:%m:%d:%H:%M");

				//옥션 티켓 생성
				AuctionTicket *auctionTicket = new AuctionTicket((*it)->getPrice(), (*it)->getMatchDate(), (*it)->getHomeTeam(), (*it)->getAwayTeam(), (*it)->getSeat(), (*it)->getLimitedTimeAuction(),startTimeString,closingTimeString, (int)0.5*((*it)->getPrice()));
				homeTeams[i]->getAuctionTicketCollection().add(auctionTicket); //옥션 티켓 추가
				it=tickets.erase(it);	 //원래 있던 티켓 지우기
				cout << auctionTicket->getMatchDate() << auctionTicket->getHomeTeam() << auctionTicket->getAwayTeam() << auctionTicket->getSeat() << auctionTicket->getClosingTime() << endl;

				out.append(to_string(auctionTicket->getPrice())); out.append(" ");
				out.append(auctionTicket->getMatchDate()); out.append(" ");
				out.append(auctionTicket->getHomeTeam()); out.append(" ");
				out.append(auctionTicket->getAwayTeam()); out.append(" ");
				out.append(auctionTicket->getSeat()); out.append(" ");
				out.append(auctionTicket->getClosingTime());
				out.append("\n");
			} 
			else {
				it++;
			}
		}
		i++;
	}
	return out;
}
