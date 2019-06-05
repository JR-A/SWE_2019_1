#include "stdafx.h"
#include "HomeTeamCollection.h"
#include "HomeTeam.h"
#include "TicketCollection.h"
#include "AuctionTicketCollection.h"

// Function : HomeTeamCollection::HomeTeamCollection()
// Description:
// Ȩ�� �ݷ��� �������Դϴ�. Ȩ���� Ƽ���ݷ����� �Ҵ��� �ݴϴ�
//
// Created: 2019/05/28 15:23 pm
// Author: �����, �赵��
//
// Revisions :
// 1. 2019/06/01 15:23 pm ����� : ����Ƽ�� �ݷ��� �Ҵ� �߰�
HomeTeamCollection::HomeTeamCollection() {
	// Ȩ�� �ʱ�ȭ
	TicketCollection* tc1 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc2 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc3 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc4 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc5 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc6 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc7 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc8 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc9 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc10 = new TicketCollection();// = new TicketCollection();
	
	AuctionTicketCollection * tc11 = new AuctionTicketCollection();
	AuctionTicketCollection * tc22 = new AuctionTicketCollection();
	AuctionTicketCollection * tc33 = new AuctionTicketCollection();
	AuctionTicketCollection * tc44 = new AuctionTicketCollection();
	AuctionTicketCollection * tc55 = new AuctionTicketCollection();
	AuctionTicketCollection * tc66 = new AuctionTicketCollection();
	AuctionTicketCollection * tc77 = new AuctionTicketCollection();
	AuctionTicketCollection * tc88 = new AuctionTicketCollection();
	AuctionTicketCollection * tc99 = new AuctionTicketCollection();
	AuctionTicketCollection * tc1010 = new AuctionTicketCollection();
	
	HomeTeam* a = new HomeTeam("sk", "Incheon");
	HomeTeam* b = new HomeTeam("doosan", "Seoul");
	HomeTeam* c = new HomeTeam("lg", "Seoul");
	HomeTeam* d = new HomeTeam("nc", "Changwon");
	HomeTeam* e = new HomeTeam("kiwoom", "Seoul");
	HomeTeam* f = new HomeTeam("hanwha", "Daejeon");
	HomeTeam* g = new HomeTeam("samsung", "Daegu");
	HomeTeam* h = new HomeTeam("lotte", "Busan");
	HomeTeam* i = new HomeTeam("kt", "Suwon");
	HomeTeam* j = new HomeTeam("kia", "Gwangju");

	a->setTicketCollection(tc1);
	b->setTicketCollection(tc2);
	c->setTicketCollection(tc3);
	d->setTicketCollection(tc4);
	e->setTicketCollection(tc5);
	f->setTicketCollection(tc6);
	g->setTicketCollection(tc7);
	h->setTicketCollection(tc8);
	i->setTicketCollection(tc9);
	j->setTicketCollection(tc10);

	a->setAuctionTicketCollection(tc11);
	b->setAuctionTicketCollection(tc22);
	c->setAuctionTicketCollection(tc33);
	d->setAuctionTicketCollection(tc44);
	e->setAuctionTicketCollection(tc55);
	f->setAuctionTicketCollection(tc66);
	g->setAuctionTicketCollection(tc77);
	h->setAuctionTicketCollection(tc88);
	i->setAuctionTicketCollection(tc99);
	j->setAuctionTicketCollection(tc1010);

	this->add(a);
	this->add(b);
	this->add(c);
	this->add(d);
	this->add(e);
	this->add(f);
	this->add(g);
	this->add(h);
	this->add(i);
	this->add(j);
}

HomeTeamCollection::~HomeTeamCollection() {
	// TODO Auto-generated destructor stub
}

// Function : vector<HomeTeam *> HomeTeamCollection::getHomeTeams()
// Description:
// ���� ��ϵǾ��ִ� ��� Ȩ���� ����� ���ͷ� ��ȯ�մϴ�
// Return Value : Ȩ���� �����Ͱ� ��� ����
//
// Created: 2019/05/28 18:01 pm
// Author: �赵��
vector<HomeTeam *> HomeTeamCollection::getHomeTeams() {
	return homeTeams;
}


// Function : vector<HomeTeam *> HomeTeamCollection::add(HomeTeam * homeTeam)
// Description:
// Ȩ���� �߰��մϴ�.
//
// Created: 2019/05/28 17:30 pm
// Author: �赵��
void HomeTeamCollection::add(HomeTeam * homeTeam) {
	homeTeams.push_back(homeTeam);
}

// Function : HomeTeam * HomeTeamCollection::getHomeTeamByName(string teamName)
// Description:
// Ȩ���� �̸��� �Ķ���ͷ� �����ϸ�, �ش�Ǵ� Ȩ���� ����Ű�� �����͸� ��ȯ�մϴ�.
// Return Value : Ȩ�� ������
// Parameters : string teamName - Ȩ���� �̸�
// Created: 2019/05/28 18:30 pm
// Author: �赵��
HomeTeam * HomeTeamCollection::getHomeTeamByName(string teamName) {
	vector<HomeTeam *> homeTeams = this->getHomeTeams();
	for (int i = 0; i < homeTeams.size(); i++) {
		if (teamName.compare(homeTeams[i]->getName()) == 0) {
			return homeTeams[i];
		}
	}
	return NULL;
}

HomeTeamCollection* HomeTeamCollection::inst = nullptr;