#pragma once
#include "stdafx.h"
#include "seller.h"
#include "buyer.h"

//Class : MemberCollection
//Description:    This is Collection Class. This is group of members. But the members are divided into sellers and buyers.
//				��� �׷쿡 ���� �߰�, ����, �������� ���� action�� �Ѵ�.
//				
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
class MemberCollection {
private:
	vector<Seller*> sellers;
	vector<Buyer*> buyers;

public:
	MemberCollection();
	void insertSeller(Seller*);
	void insertBuyer(Buyer*);
	void deleteSeller(string);
	void deleteBuyer(string);
	string getType(string id);
	Buyer* getBuyer(string);
	Seller* getSeller(string);
	vector<Seller*> getAllSeller();
	vector<Buyer*> getAllBuyer();
	bool match(string, string, string);
};