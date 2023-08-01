#define _EMAIL_ALERT_
#ifdef __cplusplus
static int emailAlertCallCount = 0;

extern "C" {
#endif{
	void emailAlerter();
#ifdef __cplusplus
	}
#endif