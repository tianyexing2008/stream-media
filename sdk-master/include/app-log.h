#ifndef _app_log_h_
#define _app_log_h_

// from sys/syslog.h
#define LOG_EMERG       0       /* system is unusable */
#define LOG_ALERT       1       /* action must be taken immediately */
#define LOG_CRIT        2       /* critical conditions */
#define LOG_ERROR       3       /* error conditions */
#define LOG_WARNING     4       /* warning conditions */
#define LOG_NOTICE      5       /* normal but significant condition */
#define LOG_INFO        6       /* informational */
#define LOG_DEBUG       7       /* debug-level messages */

#ifdef __cplusplus
extern "C" {
#endif

#define APP_LOG_WITH_LINE(level, fmt, ...)	app_log(level, "(%s:%d) " ## fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#define APP_LOG_ERROR(fmt, ...)				APP_LOG_WITH_LINE(LOG_ERROR, fmt, ##__VA_ARGS__)
#define APP_LOG_WARNING(fmt, ...)			APP_LOG_WITH_LINE(LOG_WARNING, fmt, ##__VA_ARGS__)
#define APP_LOG_NOTICE(fmt, ...)			APP_LOG_WITH_LINE(LOG_NOTICE, fmt, ##__VA_ARGS__)
#define APP_LOG_INFO(fmt, ...)				APP_LOG_WITH_LINE(LOG_INFO, fmt, ##__VA_ARGS__)
#define APP_LOG_DEBUG(fmt, ...)				APP_LOG_WITH_LINE(LOG_DEBUG, fmt, ##__VA_ARGS__)


void app_log(int level, const char* format, ...);

void app_log_setlevel(int level);

#ifdef __cplusplus
}
#endif
#endif /* !_app_log_h_ */
