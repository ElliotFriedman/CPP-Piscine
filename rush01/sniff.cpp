#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int thisSocket;
	struct sockaddr_in destination;

	destination.sin_family = AF_INET;
	thisSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
	if (thisSocket < 0)
	{
		printf("\nSocket Creation FAILED!");
		return 0;
	}

	close(thisSocket);

	destination.sin_port = htons (13374);
	destination.sin_addr.s_addr = INADDR_ANY;
	if (bind(thisSocket, (struct sockaddr *)&destination, sizeof(destination))<0)
	{
		printf("\nBinding Socket FAILED!\n");
		if (thisSocket)
			close(thisSocket);
		return 0;
	}
	printf("\nListening on 13374...");
	if (listen(thisSocket, 5)<0){
		printf("\nListening on Socket FAILED!\n");
		if (thisSocket)
			close(thisSocket);
		return 0;
	}

	struct sockaddr_in clientAddress;
	int clientSize = sizeof(clientAddress);
	thisSocket = (socklen_t *)accept(thisSocket, (struct sockaddr *)&clientAddress, (int *) &clientSize);
	if (thisSocket<0)
	{
		printf("\nSocket Connection FAILED!\n");
		if (thisSocket) close(thisSocket);
		return 0;
	}
	printf("\nConnection Established!");

	destination.sin_port = htons(13374);
	destination.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (connect(thisSocket,(struct sockaddr *)&destination,sizeof(destination))!=0){
		printf("\nSocket Connection FAILED!\n");
		if (thisSocket) close(thisSocket);
		return 0;
	}
	printf("\nConnected!");
}
