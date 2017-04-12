all:
	gcc workstation.c Server.c Client.c header.c -o workstation
	gcc receiver.c Server.c Client.c header.c -o receiver

clean:
	rm workstation receiver
