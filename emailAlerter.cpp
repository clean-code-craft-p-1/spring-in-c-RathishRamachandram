#include <stdio.h>
#include "emailAlerter.h"

int emailAlertCallCount = 0;

void emailAlerter()
{
	emailAlertCallCount = 1;
	printf("EMAIL,ALERT\n");
}
