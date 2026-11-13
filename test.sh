#!/bin/bash
ulimit -n 4096   # bach dup2(fd, 2000) ykhdem

for n in 1 2 10 42 9999 10000000; do
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=$n \
     main.c get_next_line_bonus.c get_next_line_utils_bonus.c \
     -fsanitize=address -g -o a.out || exit 1

  if ./a.out | diff - file.txt > /dev/null; then
    echo "BUFFER_SIZE=$n OK"
  else
    echo "BUFFER_SIZE=$n KO"
  fi
done
