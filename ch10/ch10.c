#include <stdio.h>
#include "ch10-01.h"

//struct contact
//{
	//char name[50];
	//char pyone[50];
	//int ringtone;

//};


typedef struct contact
{
	char name[50];
	char phone[50];
	int ringtone;

}Contact;

Contact kim = { 0 };

int main()
{
	Contact lee = { "LEE", "010-1234-5678", 1 };

	Contact lee2 = { 0 };

	lee2 = lee;

	strcpy(lee2.name, "LEE2");
	strcpy(lee2.phone, "010-9876-5432");
	lee2.ringtone = 2;

	return 0;
}