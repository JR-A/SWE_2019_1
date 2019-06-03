#include "stdafx.h"
#include "HomeTeam.h"
#include "HomeTeamCollection.h"
#include "DataSetter.h"
#include "Buyer.h"
#include "Ticket.h"

//����߰�
#include "SearchAuctionTickets.h"
#include "SearchAuctionTicketsUI.h"
#include "ParticipateAuction.h"
#include "RegisterAuctionTicket.h"

using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

void doTask();
void setHomeTeams();
vector<string> split(string, char);

int main() {
	doTask();
	return 0;
}

void doTask() {
	Buyer * buyer;
	string teamName;

	// Ƽ�� ��� / ���̾� ���� �Ǿ��ٰ� ����
	vector<Buyer *> buyers = DataSetter::getInstance()->getBuyers();
	setHomeTeams();

	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	ofstream outFile(OUTPUT_FILE_NAME);
	ifstream inFile(INPUT_FILE_NAME);

	while (!is_program_exit) {

		//while�� �������� ����ð� �޾ƿͼ� ����. ���ο� ����Ƽ�� �߰�
		RegisterAuctionTicket *registerAuctionTicket = RegisterAuctionTicket::getInstance();
		string result = registerAuctionTicket->registerAuctionTickets("2019:05:21:02:00");
		cout << result;

		string inputString;
		getline(inFile, inputString);

		// split�� �ϴܿ� ���ǵǾ� ���� 
		vector<string> lineData = split(inputString, ' ');

		// lineData �� �Է¹��� ���� �����ͷ� index 0,1�� ���� �޴�, ����޴�
		menu_level_1 = stoi(lineData[0]); // �޴�
		menu_level_2 = stoi(lineData[1]); // ����޴�

		switch (menu_level_1) {
		case 1: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("ȸ������\n");
				// ytn testpwd yoo 112233 seller
				cout << lineData[2] + " " + lineData[3] + " " + lineData[4] + " " + lineData[5] + " " + lineData[6] << endl;
				break;
			}
			case 2: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("ȸ��Ż��\n");
				break;
			}
			}
			break;
		}
		case 2: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("�α���\n");
				break;
			}
			case 2: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("�α׾ƿ�\n");
				break;
			}
			}
			break;
		}
		case 3: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("�Ǹ�Ƽ�� ���\n");
				break;
			}
			case 2: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("���Ƽ�� ��ȸ\n");
				break;
			}
			}
			break;
		}
		case 4: {
			switch (menu_level_2) {
			case 1: {
				buyer = buyers[0];
				teamName = lineData[2];
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				outFile << menu_level_1 << ", " << menu_level_2 << ".";
				printf("Ƽ�� �˻�\n");
				outFile << "Ƽ�� �˻�" << endl;
				/*
				vector<Ticket *> tickets = SearchAvailableTicketsUI::getInstance()->startInterface(buyer, teamName);
				sort(tickets.begin(), tickets.end(), Ticket::compare);
				for (int i = 0; i < tickets.size(); i++) {
					Ticket * ticket = tickets[i]->getTicket();
					if (ticket->getAvailability()) {
						// [�������] [��¥-�ð�] [Ȩ��] [�������] [�¼���ġ]
						outFile << to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() << endl;
						cout << to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() << endl;
					}
				}*/
				break;
			}
			case 2: {
				buyer = buyers[0];
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				outFile << menu_level_1 << ", " << menu_level_2 << "." << endl;
				printf("Ƽ�� ����\n");
				outFile << "Ƽ�� ����" << endl;
				/*
				HomeTeam * homeTeam = HomeTeamCollection::getInstance()->getHomeTeamByName(teamName);
				Ticket * bookedTicket = SearchAvailableTicketsUI::getInstance()->buyTicketInterface(buyer, homeTeam, lineData[2], lineData[3], lineData[4]);
				cout << to_string(bookedTicket->getPrice()) + " " + bookedTicket->getMatchDate() + " " + bookedTicket->getHomeTeam() + " " + bookedTicket->getAwayTeam() + " " + bookedTicket->getSeat() << endl;
				outFile << to_string(bookedTicket->getPrice()) + " " + bookedTicket->getMatchDate() + " " + bookedTicket->getHomeTeam() + " " + bookedTicket->getAwayTeam() + " " + bookedTicket->getSeat() << endl;
				*/
				break;
			}
			case 3: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("��� ���� Ƽ�� �˻�\n");
				
				SearchAuctionTicketsUI *searchAuctionTicketsUI = SearchAuctionTicketsUI::getInstance();
				string result = searchAuctionTicketsUI->selectHomeTeam(lineData[2],"2019:05:21:00:00");			//Ȩ��, ����ð� �Ѱ���
				outFile << result;
				
				break;
			}
			case 4: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("��� ����\n");
				break;
			}
			case 5: {
				buyer = buyers[0];
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				outFile << menu_level_1 << ", " << menu_level_2 << "." << endl;
				printf("���� ���� ��ȸ\n");
				outFile << "���� ���� ��ȸ" << endl;
				/*
				vector<Ticket *> tickets = SearchBookedTicketsUI::getInstance()->showBookedList(buyer);

				sort(tickets.begin(), tickets.end(), Ticket::compare);
				for (int i = 0; i < tickets.size(); i++) {
					Ticket * ticket = tickets[i]->getTicket();
					cout << to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() << endl;
					outFile << to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() << endl;
				}*/
			}
			}
			break;
		}
		case 5: {
			cout << menu_level_1 << ", " << menu_level_2 << ".";
			printf("����ð� ����\n");
			break;
		}
		case 6: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("session ����\n");
				break;
			}
			case 2: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("guest session���� ����\n");
				break;
			}
			}
			break;
		}
		case 7: {
			cout << menu_level_1 << ", " << menu_level_2 << ".";
			printf("����\n");
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

void setHomeTeams() {
	vector<HomeTeam *> homeTeams = HomeTeamCollection::getInstance()->getHomeTeams();

	Ticket * a1 = new Ticket(10000, "2019:05:21:12:00", "sk", "lg", "001001", true);
	Ticket * a2 = new Ticket(20000, "2019:05:21:13:00", "sk", "doosan", "M4",true);
	Ticket * a3 = new Ticket(25000, "2019:05:21:15:00", "sk", "lg", "M6", true);
	Ticket * a4 = new Ticket(15000, "2019:05:21:14:00", "sk", "lg", "M6", false);

	Ticket * b1 = new Ticket(5000, "2019:05:21:18:00", "lg", "sk", "C1", true);
	Ticket * b2 = new Ticket(8000, "2019:05:21:11:00", "lg", "doosan", "K2", true);
	Ticket * b3 = new Ticket(5000, "2019:05:21:12:00", "lg", "doosan", "B1", true);

	Ticket * c1 = new Ticket(4000, "2019:05:21:09:00", "doosan", "sk", "L11", true);
	Ticket * c2 = new Ticket(4000, "2019:05:21:12:00", "doosan", "lg", "B50", true);

	homeTeams[0]->getTicketCollection()->add(a1);
	homeTeams[0]->getTicketCollection()->add(a2);
	homeTeams[0]->getTicketCollection()->add(a3);
	homeTeams[0]->getTicketCollection()->add(a4);

	homeTeams[1]->getTicketCollection()->add(b1);
	homeTeams[1]->getTicketCollection()->add(b2);
	homeTeams[1]->getTicketCollection()->add(b3);

	homeTeams[2]->getTicketCollection()->add(c1);
	homeTeams[2]->getTicketCollection()->add(c2);
}