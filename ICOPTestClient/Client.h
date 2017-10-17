/* 
ѹ�����Կͻ��� �ͻ���ʹ�õ�����򵥵Ķ��߳�����ʽSocket
*/

#pragma once
#include <iostream>
#include <string>
#include <winsock2.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")



#define MAX_BUFLEN 1024                       //����������
#define DEFAULT_PORT 9990                     //Ĭ�϶˿�
#define DEFAULT_IP "127.0.0.1"                //Ĭ��IP��ַ
#define DEFAULT_CLIENTS 100                   //Ĭ���߳�����


#define RELEASE_HANDLE(x) {if((x)!=NULL&&(x)!=INVALID_HANDLE_VALUE){CloseHandle(x); (x)=NULL;}}
#define RELEASE(x) {if((x)!=NULL){delete (x); (x)=NULL:}}

class CClient;


//�������߳�  ���շ�����Ϣ�Ĺ������̵߳Ĳ���
typedef struct _WORKER_THREAD_PARAM
{
	CClient *m_client;                        //���������ĺ���
	SOCKET m_socket;                          //socket
	int m_nThreadNo;                          //�̱߳��
	char m_buffer[MAX_BUFLEN];                //������
}WORKER_THREAD_PARAM,*PWORKER_THREAD_PARAM;

//����socket���ӵ��̵߳Ĳ���
typedef struct _CONNECTION_THREAD_PARAM
{
	CClient *m_client;                        //���������ĺ���
}CONNECTION_THREAD_PARAM;




class CClient
{
public:
	CClient();
	~CClient();
	void SetIP(const string& ip);             //����ip��ַ�Ͷ˿�
	void SetnPort(const int &port);
	void SetClients(const int &num);          //���ÿͻ�������

	bool Start();                             //���ÿͻ��˿�ʼ��ֹͣ      
	void Stop(); 

private:
	int m_numClients;                         //�ͻ�������
	int m_nPort;                              //�˿�
	string m_serverAddr;                      //��������ַ
	
	HANDLE m_hConnectionThread;               //���ӵ��߳�
	HANDLE *m_phWorkerThread;                 //�������߳̾��
	HANDLE *m_phWorkerThreadParam;            //�������̲߳���


	bool LoadSocketLib();                     //����socket��
	void UnloadSocketLib() { WSACleanup(); }  //ж��socket��

 

};

