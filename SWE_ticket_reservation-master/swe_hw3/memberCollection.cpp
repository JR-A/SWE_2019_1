#include "stdafx.h"
#include "member.h"
#include "memberCollection.h"

//Function: MemberCollection()
//Description: MemberCollection class�� �⺻ ������
//Parameters: None
//Return Value: None
//Created: 2019/06/02
MemberCollection::MemberCollection() {
}

//Function: void insertSeller(Seller*)
//Description: seller�� ���� ��ü�� �߰��Ѵ�.
//Parameters: Seller *m
//Return Value: void
//Created: 2019/06/02
void MemberCollection::insertSeller(Seller *m) {
	sellers.push_back(m);

}

//Function: void insertBuyer(Buyer*)
//Description: Buyer�� ���� ��ü�� �߰��Ѵ�.
//Parameters: Buyer *m
//Return Value: void
//Created: 2019/06/02
void MemberCollection::insertBuyer(Buyer *m) {
	buyers.push_back(m);

}

//Function: string getType(string id)
//Description: ���� id�� ���� �׷�� ���̾� �׷��� Ȯ���Ͽ� �������� ���̾����� �Ǻ��Ѵ�.
//Parameters: string id
//Return Value: string
//Created: 2019/06/02
string MemberCollection::getType(string id) {
	for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
		if ((*it)->getID() == id) {
			return "seller";
		}
	}
	for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
		if ((*it)->getID() == id) {
			return "buyer";
		}
	}

}

//Function: Seller* getSeller(string id)
//Description: ���� �׷��� Ȯ���Ͽ� ���� id�� ���� ���� ��ü�� ��ȯ�Ѵ�.
//Parameters: string id
//Return Value: Seller*
//Created: 2019/06/02
Seller* MemberCollection::getSeller(string id) {
	for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
		if ((*it)->getID() == id) {
			return *it;
		}
	}
}

//Function: Buyer* getBuyer(string id)
//Description: ���̾� �׷��� Ȯ���Ͽ� ���� id�� ���� ���̾� ��ü�� ��ȯ�Ѵ�.
//Parameters: string id
//Return Value: Buyer*
//Created: 2019/06/02
Buyer* MemberCollection::getBuyer(string id) {
	for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
		if ((*it)->getID() == id) {
			return *it;
		}
	}
}

//Function: vector<Seller*> getAllSeller()
//Description: ���� �׷� ��ü�� ��ȯ�Ѵ�.
//Parameters: None
//Return Value: vector<Seller*>
//Created: 2019/06/02
vector<Seller*> MemberCollection::getAllSeller() {
	return sellers;
}



//Function: vector<Buyer*> getAllBuyer()
//Description: ���̾� �׷� ��ü�� ��ȯ�Ѵ�.
//Parameters: None
//Return Value: vector<Buyer*>
//Created: 2019/06/02
vector<Buyer*>MemberCollection::getAllBuyer() {
	return buyers;
}

//Function: bool match(string type, string id, string password)
//Description: ��� Ÿ���� Ȯ���ϰ�, �ش� id�� ���� ��ü�� password�� ���ڰ����� ���� password�� ��ġ�ϸ� true�� ��ȯ�ϰ� �ƴϸ� false�� ��ȯ�Ѵ�.
//Parameters: string type, string id, string password
//Return Value: bool
//Created: 2019/06/02
bool MemberCollection::match(string type, string id, string password) {
	if (type == "seller") {
		for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
			if ((*it)->getID() == id) {
				if ((*it)->getPassword() == password) {
					return true;
				}
			}
		}
		return false;
	}
	else if (type == "buyer") {
		for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
			if ((*it)->getID() == id) {
				if ((*it)->getPassword() == password) {
					return true;
				}
			}
		}
		return false;
	}

}

//Function: void deleteSeller(string id)
//Description: ���� �׷쿡�� �ش� id�� ���� ������ �����Ѵ�.
//Parameters: string id
//Return Value: void
//Created: 2019/06/02
void MemberCollection::deleteSeller(string id) {
	for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
		if ((*it)->getID() == id) {
			sellers.erase(it);
			break;
		}
	}

}

//Function: void deleteBuyer(string id)
//Description: ���̾� �׷쿡�� �ش� id�� ���� ���̾ �����Ѵ�.
//Parameters: string id
//Return Value: void
//Created: 2019/06/02
void MemberCollection::deleteBuyer(string id) {
	for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
		if ((*it)->getID() == id) {
			buyers.erase(it);
			break;
		}
	}

}


