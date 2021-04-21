#ifndef _dlog_h_
#define _dlog_h_

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/// д�ڴ���־
int dlog_log(int level, const char* format, ...);
int dlog_log_va(int level, const char* format, va_list args);

/// ������־ģ����
int dlog_setmodule(const char* module);

/// ������־�ܵ��ļ�ȫ·������
/// ע��: 
///		1. ��Linux��Ч
///		2. ������dlog_log����ǰ����
///@param[in] name ��־�ܵ��ļ���
int dlog_setpath(const char* name);

#ifdef __cplusplus
}
#endif
#endif
