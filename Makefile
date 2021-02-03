compile:
	gcc -Wall -g3 -fsanitize=address -pthread server.c -o server
	gcc -Wall -g3 -fsanitize=address -pthread client.c -o client
uninstall : 
	rm -r *.dSYM
	rm  client server