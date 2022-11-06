#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#pragma warning(disable : 4996) 



void q1p3() {
	char str[100];
	char* strPtr = str;
	char* strPtrStart = str;
	char* strPtrEnd = str;
	int strLength = 0;
	int strLenHalf = 0;
	printf("Enter a string: ");
	scanf("%s", str);
	strLength = strlen(str);
	strLenHalf = strLength / 2;
	strPtrEnd = strPtrStart + strLenHalf;
	printf("The first part of the string is: ");
	while (strPtrStart < strPtrEnd) {
		printf("%c", *strPtrStart);
		strPtrStart++;
	}
	printf("\nThe second part of the string is: ");
	while (strPtrEnd < strPtr + strLength) {
		printf("%c", *strPtrEnd);
		strPtrEnd++;
	}
}



void printFirstHalf(char* start, char* end) {
	if (strlen(start) - strlen(end) == 1) {
		printf("Done");
		return;
	}
	int strLength = 0;
	int strLenHalf = 0;
	if (strlen(start) == strlen(end)) {
		strLength = strlen(start);
	}
	else {
		strLength = strlen(start) - strlen(end);
	}
	strLenHalf = strLength / 2;
	end = start + strLenHalf;
	printf("The first part of the string is: ");
	while (start < end) {
		printf("%c", *start);
		start++;
	}
	printf("\n");
	start = start - strLenHalf;
	printFirstHalf(start, end);
}

q2p3() {
	char str[100];
	char* strPtr = str;
	char* strPtrStart = str;
	char* strPtrEnd = str;
	printf("Enter a string: ");
	scanf("%s", str);
	printFirstHalf(strPtrStart, strPtrEnd);
}


q3p3(int num) {
	
	printf("%d\t", num);
	return num == 100 ? NULL :  q3p3(num + 1);
	
}


struct lot {
	int lotNum;
	char lotDate[50];
	struct lot* next;
	struct lot* prev;
};

struct lot* head = NULL;
struct lot* tail = NULL;

addToList(int lotNum, char lotDate[50]) {
		struct lot* lotentLot;
		lotentLot = (struct lot*)malloc(sizeof(struct lot));
		lotentLot->lotNum = lotNum;
		strcpy(lotentLot->lotDate, lotDate);
		if (head == NULL) {
			head = lotentLot;
			tail = lotentLot;
			lotentLot->prev = NULL;
		}
		else {
			tail->next = lotentLot;
			lotentLot->prev = tail;
			tail = lotentLot;
		}
		lotentLot->next = NULL;
	}


struct lot* search(int lotNum) {
		struct lot* lot = head;
	while (lot != NULL) {
		if (lot->lotNum == lotNum) {
			return lot;		
		}
		lot = lot->next;
	}	printf("lottery isn't found");
		return NULL;
	}

void userResponse() {
	printf("*********MENU*********\ntype charachter for execution\n'N'.Search item\n'Q' for exit: ");
char ind = getch();
	printf("\n\n");
	switch (ind)
	{
	case 'N':
		printf("What lottery num do you want:\n");
		printf("Enter lot number: ");
		int lotNum;
		scanf("%d", &lotNum);
		struct lot* foundLot = search(lotNum);
		printf("%s", foundLot->lotDate);
		break;
	case 'Q':
		printf("done!");
				printf("\n\n");
			break;

	default:
		printf("invalid char");
		printf("\n\n");
		break;
	}
}



q4p3() {
	FILE* fp;
	char str[100];
	int lotteryNum;
	char lotteryDate[100];
	char* token;
	fp = fopen("Lotto.txt", "r");
	if (fp == NULL) {
		printf("Error opening file");
		return;
	}
	fgets(str, 100, fp);
	while (fgets(str, 100, fp) != NULL) {
		token = strtok(str, ",");
		lotteryNum = atoi(token);
		token = strtok(NULL, ",");
		strcpy(lotteryDate, token);
		token = strtok(NULL, ",");
		addToList(lotteryNum, lotteryDate);
	}
	fclose(fp);
	userResponse();
}




int main() {
	//q1p3();
	//q2p3();
	//q3p3(0);
	//q4p3();
}
