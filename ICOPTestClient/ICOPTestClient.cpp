// ICOPTestClient.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Client.h"

int main()
{
	CClient client;
	string serverAddr;
	int port,numClients;

	cout << "��������ַ��";
	cin >> serverAddr;
	cout << "�˿ڣ�";
	cin >> port;
	cout << "�ͻ��˸�����";
	cin >> numClients;
	client.SetIP(serverAddr);
	client.SetnPort(port);
	client.SetClients(numClients);
	client.Start();
	while (1);
    return 0;
}

