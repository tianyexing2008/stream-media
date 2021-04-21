#ifndef _error_h_
#define _error_h_

#define ERROR_OK                    0       // ��ȷִ��
#define ERROR_PENDING				1		// ��ִ̨����
//add by tz 2012-11-23 for send signal to user to clear screen
#define ERROR_OK_LIVE_END           10       // ʵʱ�����̹߳ر�
#define ERROR_OK_DOWNLOAD_RECORD    11       // ¼���ļ��������
//add by tz 2012-11-23 for send signal to user to clear screen

#define ERROR_UNKOWN				-1		// δ֪����
#define ERROR_MEMORY				-26		// �����ڴ�ʧ��
#define ERROR_NO_PRIVILEGE			-88		// Ȩ�޴���
#define ERROR_USER_OR_PASSWORD		-89		// �û������������
#define ERROR_NO_OBJECT             -241    // ID��Ч
#define ERROR_OBJECT_EXISTS         -242    // �û���ע��
#define ERROR_STREAM_MISMATCH	    -254  //POSA����ʽ��ƥ��(�޷�ʶ������ʽ)
#define ERROR_PARAM					-501	// �Ƿ�����
#define ERROR_CONNECT				-502	// ���ӷ�����ʧ��
#define ERROR_NOT_CONNECT			-506	// δ���ӷ�����
#define ERROR_RECV					-507	// ����ʧ��
#define ERROR_SEND					-508	// ����ʧ��
#define ERROR_REPLY					-512	// ���յ������Ӧ��
#define ERROR_NOT_LOGIN				-522	// �û�û�е�¼
#define ERROR_RECV_TIMEOUT			-523	// ������ճ�ʱ
#define ERROR_SEND_TIMEOUT			-599	// ���緢�ͳ�ʱ
#define ERROR_HTTP_REDIRECT			-598	// HTTP�ض���
#define ERROR_NOTFOUND				-597	// XXX������
#define ERROR_NOT_EXIST				-596	// XXX������
#define ERROR_NOT_IMPLEMENT			-595	// ����δʵ��
#define ERROR_INVALID_INSTRUCTION	-594	// �Ƿ�ָ��
#define ERROR_OS_RESOURCE			-593	// ϵͳ��Դ����
#define ERROR_EXIST					-592	// XXX�Ѵ���


#endif /* !_error_h_ */
