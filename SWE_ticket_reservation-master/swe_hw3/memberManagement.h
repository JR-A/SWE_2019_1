#pragma once
#include "stdafx.h"
#include "member.h"
#include "memberCollection.h"
using namespace std;

//Class : MemberManagement
//Description:    This is Management Class. ��� �׷��� �����ϴ� Ŭ�����̴�.
//				���� ����Ʈ�� ��� �׷��� ������ ������, use case�� ������ ���������� �����ϴ� �Լ����� �����̴�.
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
class MemberManagement {

private:
	set<string> session;
	MemberCollection *member;

public:
	MemberManagement();
	~MemberManagement();
	void createAccount(string, string, string, string, string);
	bool login(string, string);
	void logout(string);
	bool deleteAccount(string);
	MemberCollection* getMembers();
};

