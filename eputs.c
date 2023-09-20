#include"shell.h"

void eputs(char *str) {
  int i = 0;

  if (!str)
    return;
  while (str[i] != '\0') {
    eputchar(str[i]);
    i++;
  }
}

int eputchar(char c) {
  static int i;
  static char buf[WRITE_BUF_SIZE];

  if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE) {
    write(2, buf, i);
    i = 0;
  }
  if (c != BUF_FLUSH)
    buf[i++] = c;
  return (1);
}

int putfd(char c, int fd) {
  static int i;
  static char buf[WRITE_BUF_SIZE];

  if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE) {
    write(fd, buf, i);
    i = 0;
  }
  if (c != BUF_FLUSH)
    buf[i++] = c;
  return (1);
}

int putsfd(char *str, int fd) {
  int i = 0;

  if (!str)
    return (0);
  while (*str) {
    i += putfd(*str++, fd);
  }
  return (i);
}
