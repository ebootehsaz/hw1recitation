# The first target in the Makefile is the default target.
# If you just type 'make' without specifying a target, this is what will be executed.
# In this case, the default target is 'main'.
default: main

# This defines the 'main' target.
# When 'make main' is executed, it triggers the compilation of 'c_review_completed.c'
# using the gcc compiler with certain options.
# The '-w' option suppresses all warnings.
# The '-g' option includes debugging information in the compiled program,
# which is useful for debugging.
main: 
	gcc -w -g c_review_completed.c

# This defines the 'asan' target.
# When 'make asan' is executed, it compiles the same 'c_review_completed.c' file
# but with different gcc options.
# The '-fsanitize=address' option enables AddressSanitizer, a memory error detector.
# It helps in finding memory leaks, buffer overflows, etc.
# This target also includes the '-w' (suppress warnings) and '-g' (debugging info) options.
asan: 
	gcc -w -fsanitize=address -g c_review_completed.c

# This defines the 'clean' target.
# It's a conventional name used in many Makefiles to clean up the files that the build process creates.
# When 'make clean' is executed, it removes the 'a.out' file or any file named 'a.out*'.
# 'rm' is the Unix command for removing files, '-rf' forces the removal without prompt and handles directories.
# 'a.out' is the default name of the executable created by gcc when the '-o' option is not used.
clean:
	rm -rf a.out*
