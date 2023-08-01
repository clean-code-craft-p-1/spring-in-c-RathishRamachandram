#include <stdio.h>
#include "ledAlerter.h"

int ledAlertCallCount = 0;

void ledAlerter()
{
	printf("LED,ALERT\n");
	ledAlertCallCount = 1;
}
