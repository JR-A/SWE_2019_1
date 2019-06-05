#pragma once
#include "stdafx.h"
class HomeTeam;

// Class : HomeTeamCollection
// Description: ��� Ȩ���� �����ϴ� �ݷ��� Ŭ�����Դϴ�.
// Created: 2019/5/28 16:30 pm
// Author: �赵��
// mail: donsdevko@gmail.com
//
// Revsions :
// 1. When & Who : 2019/05/29 20:30 pm by �赵��
// What : �̱��� �������� ���� 
class HomeTeamCollection {

private:
	vector<HomeTeam *> homeTeams;
	HomeTeamCollection();
	virtual ~HomeTeamCollection();
	static HomeTeamCollection* inst;
public:
	vector<HomeTeam *> getHomeTeams();
	HomeTeam * getHomeTeamByName(string);
	void add(HomeTeam *);
	static HomeTeamCollection * getInstance() {
		if (inst == NULL) inst = new HomeTeamCollection();
		return inst;
	}
};