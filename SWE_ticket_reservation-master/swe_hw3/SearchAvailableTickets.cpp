#include "stdafx.h"
#include "SearchAvailableTickets.h"
#include "SearchAvailableTicketsUI.h"
#include "HomeTeam.h"

SearchAvailableTickets::SearchAvailableTickets()
{
}


SearchAvailableTickets::~SearchAvailableTickets()
{
}

// Function : vector<Ticket *> SearchAvailableTickets::showAvailableTickets(HomeTeam * homeTeam)
// Description:
// �Ѱ��� Ȩ���� ���� ��� Ƽ�� ������ ���͸� ��ȯ�մϴ�
// Parameters : HomeTeam * homeTeam - Ȩ�� ������
// Return Value : �˻��� Ƽ���� �����Ͱ� ��� ����
//
// Created: 2019/05/28 23:15 pm
// Author: �赵��
vector<Ticket *> SearchAvailableTickets::showAvailableTickets(HomeTeam * homeTeam) {
	return homeTeam->listAvailableTickets();
}

SearchAvailableTickets * SearchAvailableTickets::inst;