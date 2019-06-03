#include "stdafx.h"
#include "Timer.h"
#include "memberManagement.h"
#include "member.h"
#include "memberCollection.h"
#include "Ticket.h"
#include "HomeTeam.h"
#include "HomeTeamCollection.h"

Timer::Timer() {}
Timer::~Timer() {}

void Timer::checkDeleteTicket(int year, int month, int day, int hour, int minute, MemberManagement *mm) {
	//���⼭ Ÿ�̸ӿ��� �ش� ���� ������ �� ���ͷ����� ���� �ش��ϴ� �ֵ� ���쵵�� ����ؾߵ�

	vector<Seller*> sellers = mm->getMembers()->getAllSeller();
	for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
		//���⼭ ��� �������� �����ؼ� ������ �ݷ��� �����ߵ�
		vector<Ticket*> temp = (*it)->getRegisteredTickets()->getTickets();
		for (vector<Ticket*>::iterator itt = temp.begin(); itt != temp.end(); itt++) {
			bool check = true;
			check = compare(year, month, day, hour, minute, (*itt)->getMatchDate());
			if (check == false) {
				(*it)->getRegisteredTickets()->deleteTicket(*itt);
			}
		}
	}

	vector<Buyer*> buyers = mm->getMembers()->getAllBuyer();
	for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
		//���⼭ ��� ���̾�� �����ؼ� ������ �ݷ��� �����ߵ�
		vector<Ticket*> temp = (*it)->getBookedTickets()->getTickets();
		for (vector<Ticket*>::iterator itt = temp.begin(); itt != temp.end(); itt++) {
			bool check = true;
			check = compare(year, month, day, hour, minute, (*itt)->getMatchDate());
			if (check == false) {
				(*it)->getBookedTickets()->deleteTicket(*itt);
			}
		}
	}

	vector<HomeTeam *> homeTeams = HomeTeamCollection::getInstance()->getHomeTeams();
	for (int i = 0; i < homeTeams.size(); i++) {
		vector<Ticket*> temp = homeTeams[i]->getTicketCollection()->getTickets();
		for (vector<Ticket*>::iterator it = temp.begin(); it != temp.end(); it++) {
			cout << (*it)->getRegistrationDate() << endl;
			bool check = true;
			check = compare(year, month, day, hour, minute, (*it)->getRegistrationDate());
			if (check = false) {
				//homeTeams[i]->getTicketCollection()->getTickets().erase(it);
				cout << "delete" << endl;
			}
		}
	}
}

bool Timer::compare(int year, int month, int day, int hour, int minute, string MatchDate) {
	int matchYear = stoi(MatchDate.substr(0, 4));
	int matchMonth = stoi(MatchDate.substr(5, 7));
	int matchDay = stoi(MatchDate.substr(8, 10));
	int matchHour = stoi(MatchDate.substr(11, 13));
	int matchMinute = stoi(MatchDate.substr(14, 17));
	if (year > matchYear + 1) {
		return false;
	}
	else if (year == matchYear + 1) {
		if (month > matchMonth) {
			return false;
		}
		else if (month == matchMonth) {
			if (day > matchDay) {
				return false;
			}
			else if (day == matchDay) {
				if (hour > matchHour) {
					return false;
				}
				else if (hour == matchHour) {
					if (minute > matchMinute) {
						return false;
					}
				}
			}
		}
	}
	return true;
}