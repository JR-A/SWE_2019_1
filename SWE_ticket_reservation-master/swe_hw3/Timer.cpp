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

// Ƽ���� ��ġ �ð��� ����ð��� ������ ��, 1���� �ʰ��ϸ� �����ϱ� ���� �Լ�
void Timer::checkDeleteTicket(int year, int month, int day, int hour, int minute, MemberManagement *mm) {
	// Membermanagement���� ��� Seller�� ��ü �����͸� vector�� ������
	vector<Seller*> sellers = mm->getMembers()->getAllSeller();
	// ������ ��� Seller�� ����Ǿ� �ִ� vector���� iterator�� �̿��Ͽ� ������ Seller ��ü �����Ϳ� ����
	for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
		// �� Seller ������ ��ü�� ����� Ƽ���� ��ü �����͸� getTickets()�� �̿��Ͽ� vector�� ������
		vector<Ticket*> temp = (*it)->getRegisteredTickets()->getTickets();
		// �� Seller�� Ƽ�� vector���� iterator�� �̿��Ͽ� ������ Seller�� Ƽ�� ��ü �����Ϳ� ����
		for (vector<Ticket*>::iterator itt = temp.begin(); itt != temp.end(); itt++) {
			bool check = true;
			// ������ Seller�� Ƽ�� ��ü �������� ��ġ �ð��� �����ͼ� compare�� ���� ��
			check = compare(year, month, day, hour, minute, (*itt)->getMatchDate());
			if (check == false) {
				// 1���� �ʰ��ϴ� ���
				// ��ϵ� Ƽ���� �����ϴ� getRegisteredTickets()�� deleteTicket(Ticket*)�� ȣ��
				(*it)->getRegisteredTickets()->deleteTicket(*itt);
			}
		}
	}

	// Membermanagement���� ��� Buyer�� ��ü �����͸� vector�� ������
	vector<Buyer*> buyers = mm->getMembers()->getAllBuyer();
	// ������ ��� Buyer�� ����Ǿ� �ִ� vector���� iterator�� �̿��Ͽ� ������ Buyer ��ü �����Ϳ� ����
	for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
		// �� Buyer ������ ��ü�� ����� Ƽ���� ��ü �����͸� getTickets()�� �̿��Ͽ� vector�� ������
		vector<Ticket*> temp = (*it)->getBookedTickets()->getTickets();
		// �� Buyer�� Ƽ�� vector���� iterator�� �̿��Ͽ� ������ Buyer�� Ƽ�� ��ü �����Ϳ� ����
		for (vector<Ticket*>::iterator itt = temp.begin(); itt != temp.end(); itt++) {
			bool check = true;
			// ������ Buyer�� Ƽ�� ��ü �������� ��ġ �ð��� �����ͼ� compare�� ���� ��
			check = compare(year, month, day, hour, minute, (*itt)->getMatchDate());
			if (check == false) {
				// 1���� �ʰ��ϴ� ���
				// ��ϵ� Ƽ���� �����ϴ� getBookedTickets()�� deleteTicket(Ticket*)�� ȣ��
				(*it)->getBookedTickets()->deleteTicket(*itt);
			}
		}
	}

	// HomeTeamCollection���� ��� Ȩ���� ��ü �����͸� vector�� ������
	vector<HomeTeam *> homeTeams = HomeTeamCollection::getInstance()->getHomeTeams();
	// ��� Ȩ���� ����Ǿ� �ִ� vector���� iterator�� �̿��Ͽ� ������ Ȩ�� ��ü �����Ϳ� ����
	for (int i = 0; i < homeTeams.size(); i++) {
		// �� Ȩ�� ������ ��ü�� ��ϵ� Ƽ���� ��ü �����͸� getTickets()�� �̿��Ͽ� vector�� ������
		vector<Ticket*> temp = homeTeams[i]->getTicketCollection()->getTickets();
		// �� Ȩ���� Ƽ�� vector���� iterator�� �̿��Ͽ� ������ Ȩ���� Ƽ�� ��ü �����Ϳ� ����
		for (vector<Ticket*>::iterator it = temp.begin(); it != temp.end(); it++) {
			bool check = true;
			// ������ Ȩ���� Ƽ�� ��ü �������� ��ġ �ð��� �����ͼ� compare�� ���� ��
			check = compare(year, month, day, hour, minute, (*it)->getRegistrationDate());
			if (check == false) {
				// 1���� �ʰ��ϴ� ���
				// ��ϵ� Ƽ���� �����ϴ� getTicketCollection()�� deleteTicket(Ticket*)�� ȣ��
				homeTeams[i]->getTicketCollection()->deleteTicket(*it);
			}
		}
	}
}

// Ƽ���� ��ġ �ð��� ���� �ð��� ���ϱ� ���� �Լ�
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