#include "shell.h"

/* copy string, up to n characters */
char *string_strncpy(char *dest, char *src, int n) {
  int i;
  char *s = dest;

  i = 0;
  while (src[i] != '\0' && i < n - 1) {
    dest[i] = src[i];
    i++;
  }
  if (i < n) {
    while (i < n) {
      dest[i] = '\0';
      i++;
    }
  }
  return s;
}

/* concatenate two strings, up to n characters */
char *string_strncat(char *dest, char *src, int n) {
  int i, j;
  char *s = dest;

  i = 0;
  j = 0;
  while (dest[i] != '\0') i++;
  while (src[j] != '\0' && j < n) {
    dest[i] = src[j];
    i++;
    j++;
  }
  if (j < n) dest[i] = '\0';
  return s;
}

/* locate a character in a string */
char *string_strchr(char *s, char c) {
  do {
    if (*s == c) return s;
  } while (*s++ != '\0');

  return NULL;
} 
