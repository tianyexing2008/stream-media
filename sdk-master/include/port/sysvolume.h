#ifndef _sysvolume_h_
#define _sysvolume_h_

// ��ȡ/����ϵͳ������, ȡֵ��Χ: 0-0xFFFF
// ��8λΪ������, ��8λΪ������
int GetMasterVolume(int* v);
int SetMasterVolume(int v);

// ��ȡ/����ϵͳ����������, 1-����, 0-ȡ������
int SetMasterVolumeMute(int mute);
int GetMasterVolumeMute(int* mute);

// ��ȡ/����ϵͳ¼������, ȡֵ��Χ��0-0xFFFF
// ��8λΪ������, ��8λΪ������
int GetRecordVolume(int* v);
int SetRecordVolume(int v);

// ��ȡ/����ϵͳ¼����������, 1-����, 0-ȡ������
int GetRecordVolumeMute(int* mute);
int SetRecordVolumeMute(int mute);

#endif /* !_sysvolume_h_ */
