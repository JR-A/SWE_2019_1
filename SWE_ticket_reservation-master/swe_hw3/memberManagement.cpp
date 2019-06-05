#include "stdafx.h"
#include "memberManagement.h"
#include "member.h"
#include "seller.h"
#include "buyer.h"
using namespace std;

//Function: MemberManagement()
//Description: MemberManagement class�� �⺻ ������
//Parameters: None
//Return Value: None
//Created: 2019/06/02
MemberManagement::MemberManagement() {
	member = new MemberCollection();
}

//Function: ~MemberManagement()
//Description: MemberManagement class�� �Ҹ���
//Parameters: None
//Return Value: None
//Created: 2019/06/02
MemberManagement::~MemberManagement() {

}

//Function: void createAccount(string type, string id, string password, string name, string identificationNumber)
//Description: ���ο� ����� type�� Ȯ���ϰ� �ش� type�� ��� �׷쿡 ����� �߰��Ѵ�.
//Parameters: string type, string id, string password, string name, string identificationNumber
//Return Value: void
//Created: 2019/06/02
void MemberManagement::createAccount(string type, string id, string password, string name, string identificationNumber) {
	if (type == "seller") {
		member->insertSeller(new Seller(id, password, name, identificationNumber));
	}
	else if (type == "buyer") {
		member->insertBuyer(new Buyer(id, password, name, identificationNumber));
	}
	else {
		cout << "Invaild Type" << endl;
	}

}

//Function: bool login(string id, string password)
//Description: �α����ϴ� ȸ���� type�� Ȯ���ϰ� ����Ǿ� �ִ� id�� password�� ��ġ�� �ÿ� session �׷쿡 ȸ���� �߰��Ѵ�.
//Parameters: string id, string password
//Return Value: bool
//Created: 2019/06/02
bool MemberManagement::login(string id, string password) {
	if (!(member->match("seller", id, password))&&!(member->match("buyer", id, password))) {
		return false;
	}

	if (member->getType(id) == "seller") {
		if (member->match("seller", id, password)) {
			session.insert(id);
			return true;
		}
		else {
			return false;
		}
	}
	else if (member->getType(id) == "buyer") {
		if (member->match("buyer", id, password)) {
			session.insert(id);
			return true;
		}
		else {
			return false;
		}
	}
}


//Function: void logout(string id)
//Description: session �׷쿡 �α׾ƿ��ϴ� ȸ���� �����Ѵ�.
//Parameters: string id
//Return Value: void
//Created: 2019/06/02
void MemberManagement::logout(string id) {
	set<string>::iterator it;
	for (it = session.begin(); it != session.end(); ++it) {
		if (*it == id) {
			session.erase(it);
			break;
		}
	}
}

//Function: bool deleteAccount(string id)
//Description: ���� ���� ����� type�� Ȯ���ϰ� �ش� type�� ��� �׷�� ���ǿ��� ����� �����Ѵ�.
//			��, seller�� ���� �Ǹ����� Ƽ���� ���������� ��� �׷�� ���ǿ��� �ش� seller�� �������� �ʴ´�. 
//Parameters: string id
//Return Value: bool
//Created: 2019/06/02
bool MemberManagement::deleteAccount(string id) {
	
	if ((member->getType(id) == "seller")) {
		Seller *s = member->getSeller(id);
		if (s->existTicket()) {
			return false;
		}
		else {
			member->deleteSeller(id);
			set<string>::iterator it;
			for (it = session.begin(); it != session.end(); ++it) {
				if (*it == id) {
					session.erase(it);
					break;
				}
			}
		}
	}
	else if((member->getType(id) == "buyer")){

		member->deleteBuyer(id);
		set<string>::iterator it;
		for (it = session.begin(); it != session.end(); ++it) {
			if (*it == id) {
				session.erase(it);
				break;
			}
		}
		
	}
	return true;
}

//Function: MemberCollection* getMembers()
//Description: ����׷� �����͸� ��ȯ�Ѵ�.
//Parameters: None
//Return Value: MemberCollection*
//Created: 2019/06/02
MemberCollection* MemberManagement::getMembers() {
	return member;
}
