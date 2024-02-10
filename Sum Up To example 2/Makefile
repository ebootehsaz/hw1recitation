default: main

main: 
	gcc -w -g sum_to.c -o sum_to

asan: 
	gcc -w -fsanitize=address -g sum_to.c -o sum_to

clean:
	rm -rf sum_to; rm -rf sum_to.dSYM 