lltest: test.c linkedlist.c
	gcc -Wall -Wextra -g3 test.c linkedlist.c -o lltest
	./lltest
	rm -f lltest
