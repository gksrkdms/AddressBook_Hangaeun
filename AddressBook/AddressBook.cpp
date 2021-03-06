// doublyLinkedList.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

typedef struct node {
	std::string name;
	std::string number;
	std::string address;

	struct node *prev;
	struct node *next;

}NODE;
NODE *head = NULL;
NODE *newdata;
NODE *tail;

void Init();
void Data();
void Input();
void Output();
void Search();
void Delete();
void Sort();


int main()
{
	Init();

	char btnNum;

	while (true)
	{
		std::cout << "1. 입력" << std::endl;
		std::cout << "2. 출력" << std::endl;
		std::cout << "3. 이름검색" << std::endl;
		std::cout << "4. 삭제" << std::endl;
		std::cout << "5. 알파벳순 정렬" << std::endl;
		std::cout << "6. 종료" << std::endl;

		std::cin >> btnNum;

		if (isdigit(btnNum))
		{
			switch (btnNum)
			{
				// 입력
			case '1':
				Input();
				break;
				// 출력
			case '2':
				Output();
				break;
				// 이름검색
			case '3':
				Search();
				break;
				// 삭제
			case '4':
				Delete();
				break;
				// 정렬
			case '5':
				Sort();
				break;
				// 종료
			case '6':
				return 0;
			default:
				std::cout << "알맞은 숫자를 입력해주세요" << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "알맞은 숫자를 입력해주세요" << std::endl;
		}		
	}

	return 0;
}

void Init()
{
	head = new NODE;
	tail = new NODE;
	head->next = tail;
	head->prev = head;
	tail->prev = head;
	tail->next = tail;
}

void Data()
{
	newdata = new NODE;
	std::cout << "이름 : ";
	std::cin >> newdata->name;

	std::cout << "전화번호 : ";
	std::cin >> newdata->number;

	std::cout << "주소 : ";
	std::cin >> newdata->address;
}

// 입력
void Input()
{
	Data();
	if (head->next == tail)
	{
		head->next = newdata;
		newdata->prev = head;
		newdata->next = tail;
		tail->prev = newdata;
		return;
	}
	else
	{
		tail->prev->next = newdata;
		newdata->prev = tail->prev;
		newdata->next = tail;
		tail->prev = newdata;
		return;
	}
}

// 출력
void Output()
{
	NODE *temp = head->next;
	while (temp != tail)
	{
		std::cout << temp->name << std::endl;
		std::cout << temp->number << std::endl;
		std::cout << temp->address << std::endl;
		temp = temp->next;
	}
}

// 검색
void Search()
{
	NODE *temp;
	temp = head->next;
	std::string name;
	std::cout << "검색할 이름을 입력하세요." << std::endl;
	std::cin >> name;
	while (temp->name != name && temp != tail)
	{
		temp = temp->next;
	}
	if (temp == tail)
	{
		std::cout << "이름이 존재하지 않습니다." << std::endl;
	}
	else
	{
		std::cout << temp->name << std::endl;
		std::cout << temp->number << std::endl;
		std::cout << temp->address << std::endl;
	}
}

// 삭제
void Delete()
{
	NODE *temp;
	std::string name;
	std::cout << "삭제할 이름을 입력하세요." << std::endl;
	std::cin >> name;

	temp = head->next;
	while (temp->name != name && temp != tail)
	{
		temp = temp->next;
	}
	if (temp == tail)
	{
		std::cout << "찾는 이름이 존재하지 않습니다." << std::endl;
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
}

// 정렬
void Sort()
{
	NODE *temp = head->next;

	while (temp != tail->prev)
	{
		NODE *temp2 = temp->next;
		bool isFalse = false;

		while (temp2 != tail)
		{
			if (temp->name > temp2->name)
			{
				std::string tempName;
				std::string tempNumber;
				std::string tempAddress;

				tempName = temp->name;
				tempNumber = temp->number;
				tempAddress = temp->address;

				temp->name = temp2->name;
				temp->number = temp2->number;
				temp->address = temp2->address;

				temp2->name = tempName;
				temp2->number = tempNumber;
				temp2->address = tempAddress;
				isFalse = true;
			}
			temp2 = temp2->next;
		}
		if (isFalse == false)
		{
			break;
		}

		temp = temp->next;
	}

}