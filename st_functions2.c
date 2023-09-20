#include "shell.h"

/* copy string */
char *string_copy(char *dest, char *src) {
  if (dest == src || src == NULL) return dest;
  while (*src) *dest++ = *src++;
  *dest = '\0';
  return dest;
}

/* duplicate string */
char *string_duplicate(const char *str) {
  int length = 0;
  char *ret;

  if (str == NULL) return NULL;
  while (*str++) length++;
  ret = malloc(sizeof(char) * (length + 1));
  if (!ret) return NULL;
  for (length++; length--;) ret[length] = *--str;
  return ret;
}

/* print string */
void print_string(char *str) {
  if (!str) return;
  while (*str != '\0') putchar(*str++);
}

/* put character */
int putchar(char c) {
  static int i;
  static char buf[WRITE_BUF_SIZE];

  if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE) {
    write(1, buf, i);
    i = 0;
  }
  if (c != BUF_FLUSH) buf[i++] = c;
  return 1;
}
