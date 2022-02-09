echo '
.vscode
test.c
test/
tests/
tests/*
test*
example.c
a.out.dSYM
*.out
*.a
*.o
*/core
core
*.rb
' >>.git/info/exclude

# USE CLANG ON LINUX!
clang -Wall -Wextra -Werror *.c && ./a.out
clang -Wall -Wextra -Werror *.c && time ./a.out

gcc -Wall -Wextra -Werror *.c && ./a.out
gcc -Wall -Wextra -Werror *.c && time ./a.out

norminette *.c *.h
