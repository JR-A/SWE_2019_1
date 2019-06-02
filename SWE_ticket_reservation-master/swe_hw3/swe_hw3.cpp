#include "stdafx.h"
#include "HomeTeam.h"
#include "HomeTeamCollection.h"
#include "SearchAvailableTicketsUI.h"
#include "SearchBookedTicketsUI.h"
#include "Buyer.h"
#include "Ticket.h"
#include "signUpUI.h"
#include "deleteUI.h"
#include "loginUI.h"
#include "logoutUI.h"
#include "memberManagement.h"
#include "RegisterTicketUI.h"
#include "SearchRegisteredTicketUI.h"

using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

void doTask();
string curSessionID;
vector<string> split(string, char);

int main() {
	doTask();
	return 0;
}

void doTask() {
	Buyer * buyer;
	string teamName;
	MemberManagement *mm = new MemberManagement();

	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;
	curSessionID = "guest session";

	ofstream outFile(OUTPUT_FILE_NAME);
	ifstream inFile(INPUT_FILE_NAME);

	while (!is_program_exit) {
		string inputString;
		getline(inFile, inputString);

		// split은 하단에 정의되어 있음 
		vector<string> lineData = split(inputString, ' ');

		// lineData 는 입력받은 한줄 데이터로 index 0,1은 각각 메뉴, 서브메뉴
		menu_level_1 = stoi(lineData[0]); // 메뉴 
		menu_level_2 = stoi(lineData[1]); // 서브메뉴

		switch (menu_level_1) {
		case 1: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("회원가입\n");
				// ytn testpwd yoo 112233 seller
				cout << lineData[2] + " " + lineData[3] + " " + lineData[4] + " " + lineData[5] + " " + lineData[6] << endl;

				SignUpUI *signUpUI = new SignUpUI(mm);
				signUpUI->createAccount(lineData[2], lineData[3], lineData[4], lineData[5], lineData[6]);
				cout << lineData[2] <<" " << lineData[3]<< " " << lineData[4] << " " << lineData[5]<< endl;

				break;
			}
			case 2: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("회원탈퇴\n");

				DeleteUI *deleteUI = new DeleteUI(mm);
				bool output = deleteUI->deleteAccount(curSessionID);
				if (output == true)
					cout << curSessionID << endl;
				else
					cout << "판매 중인 티켓이 남아있습니다. 탈퇴가 불가능 합니다." << endl;

				curSessionID = "guest session";
				break;
			}
			}
			break;
		}
		case 2: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("로그인\n");
				
				LoginUI *loginUI = new LoginUI(mm);
				bool output = loginUI->login(lineData[2], lineData[3]);
				if (output == true) {
					cout << lineData[2] << " " << lineData[3] << endl;
					curSessionID = lineData[2];
				}
				else {
					cout << "아이디 또는 비밀번호를 다시 확인하세요." << endl;
					cout << "등록되지 않은 아이디이거나, 아이디 또는 비밀번호를 잘못 입력하셨습니다." << endl;
				}
				cout << "login 정상" << endl;
				break;
			}
			case 2: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("로그아웃\n");

				LogoutUI *logoutUI = new LogoutUI(mm);
				logoutUI->logout(curSessionID);
				cout << curSessionID << endl;
				curSessionID = "guest session";
				break;
			}
			}
			break;
		}
		case 3: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("판매티켓 등록\n");

				bool _limitedTimeAuction;

				if (lineData[7] == "0")
					_limitedTimeAuction = true;
				else
					_limitedTimeAuction = false;
				cout << "main" << &mm << endl;
				RegisterTicketUI::getInstance()->putTicketInfo(lineData[2], lineData[3], lineData[4], lineData[5], lineData[6], _limitedTimeAuction, curSessionID, mm);

				// price, matchDate, homeTeam, awayTeam, seat, limitedTimeAuction
				cout << lineData[2] << " " << lineData[3] << " " << lineData[4] << " " << lineData[5] << " " << lineData[6] << " " << _limitedTimeAuction << endl;
				outFile << lineData[2] << " " << lineData[3] << " " << lineData[4] << " " << lineData[5] << " " << lineData[6] << " " << _limitedTimeAuction << endl;
			
				break;
			}
			case 2: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("등록티켓 조회\n");
				vector<Ticket*> tickets = SearchRegisteredTicketUI::getInstance()->searchTicket(mm, curSessionID);
				//sort(tickets.begin(), tickets.end(), Ticket::compare);

				for (int i = 0; i < tickets.size(); i++) {

					Ticket* ticket = tickets[i]->getTicket();

					outFile << to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() + " " + to_string(ticket->getLimitedTimeAuction()) + " " + to_string(ticket->getAvailability()) << endl;

					cout << to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() + " " + to_string(ticket->getLimitedTimeAuction()) + " " + to_string(ticket->getAvailability()) << endl;

				}
			}
			}
			break;
		}
		case 4: {
			switch (menu_level_2) {
			case 1: {
				buyer = (mm->getMembers())->getBuyer(curSessionID);
				teamName = lineData[2];
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				outFile << menu_level_1 << ", " << menu_level_2 << ".";
				printf("티켓 검색\n");
				outFile << "티켓 검색" << endl;

				vector<Ticket *> tickets = SearchAvailableTicketsUI::getInstance()->startInterface(buyer, teamName);
				sort(tickets.begin(), tickets.end(), Ticket::compare);
				for (int i = 0; i < tickets.size(); i++) {
					Ticket * ticket = tickets[i]->getTicket();
					if (ticket->getAvailability()) {
						// [희망가격] [날짜-시간] [홈팀] [어웨이팀] [좌석위치]
						outFile << to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() << endl;
						cout << to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() << endl;
					}
				}
				break;
			}
			case 2: {
				buyer = (mm->getMembers())->getBuyer(curSessionID);
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				outFile << menu_level_1 << ", " << menu_level_2 << "." << endl;
				printf("티켓 예약\n");
				outFile << "티켓 예약" << endl;
				HomeTeam * homeTeam = HomeTeamCollection::getInstance()->getHomeTeamByName(teamName);
				Ticket * bookedTicket = SearchAvailableTicketsUI::getInstance()->buyTicketInterface(buyer, homeTeam, lineData[2], lineData[3], lineData[4]);
				cout << to_string(bookedTicket->getPrice()) + " " + bookedTicket->getMatchDate() + " " + bookedTicket->getHomeTeam() + " " + bookedTicket->getAwayTeam() + " " + bookedTicket->getSeat() << endl;
				outFile << to_string(bookedTicket->getPrice()) + " " + bookedTicket->getMatchDate() + " " + bookedTicket->getHomeTeam() + " " + bookedTicket->getAwayTeam() + " " + bookedTicket->getSeat() << endl;
				break;
			}
			case 3: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("경매 중인 티켓 검색\n");
				break;
			}
			case 4: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("경매 참여\n");
				break;
			}
			case 5: {
			    buyer = (mm->getMembers())->getBuyer(curSessionID);
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				outFile << menu_level_1 << ", " << menu_level_2 << "." << endl;
				printf("예약 정보 조회\n");
				outFile << "예약 정보 조회" << endl;
				vector<Ticket *> tickets = SearchBookedTicketsUI::getInstance()->showBookedList(buyer);

				sort(tickets.begin(), tickets.end(), Ticket::compare);
				for (int i = 0; i < tickets.size(); i++) {
					Ticket * ticket = tickets[i]->getTicket();
					cout << to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() << endl;
					outFile << to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() << endl;
				}
			}
			}
			break;
		}
		case 5: {
			cout << menu_level_1 << ", " << menu_level_2 << ".";
			printf("현재시간 설정\n");
			break;
		}
		case 6: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("session 변경\n");
				curSessionID = lineData[2];
				cout << lineData[2] << endl;
				break;
			}
			case 2: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("guest session으로 변경\n");
				curSessionID = "guest session";
				break;
			}
			}
			break;
		}
		case 7: {
			cout << menu_level_1 << ", " << menu_level_2 << ".";
			printf("종료\n");
			cout << mm->getMembers()->num() << endl;
			is_program_exit = 1;
			break;
		}
		}
	}
}

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}
/*
void setHomeTeams() {
	vector<HomeTeam *> homeTeams = HomeTeamCollection::getInstance()->getHomeTeams();

	Ticket * a1 = new Ticket(10000, "2019:05:22:12:00", "sk", "lg", "001001", false);
	Ticket * a2 = new Ticket(20000, "2019:05:19:13:00", "sk", "doosan", "M4", false);
	Ticket * b1 = new Ticket(5000, "2019:05:02:18:00", "lg", "sk", "C1", false);
	Ticket * b2 = new Ticket(8000, "2019:05:01:11:00", "lg", "doosan", "K2", false);
	Ticket * c1 = new Ticket(4000, "2019:05:10:09:00", "doosan", "sk", "L11", false);
	Ticket * c2 = new Ticket(4000, "2019:05:08:18:00", "doosan", "lg", "B50", false);

	homeTeams[0]->getTicketCollection().add(a1);
	homeTeams[0]->getTicketCollection().add(a2);
	homeTeams[1]->getTicketCollection().add(b1);
	homeTeams[1]->getTicketCollection().add(b2);
	homeTeams[2]->getTicketCollection().add(c1);
	homeTeams[2]->getTicketCollection().add(c2);
}
*/