#define _LED_ALERT_
#ifdef __cplusplus
static int ledAlertCallCount = 0;

extern "C" {
#endif
	void ledAlerter();
#ifdef __cplusplus
}
#endif
