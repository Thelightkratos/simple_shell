#include <stdio.h>
#include <string.h>

int my_strlen(char *string) {
  int length = 0;
  while (string[length] != '\0') {
    length++;
  }
  return length;
}

int my_strcmp(char *string1, char *string2) {
  while (*string1 != '\0' && *string2 != '\0') {
    if (*string1 != *string2) {
      return *string1 - *string2;
    }
    string1++;
    string2++;
  }
  if (*string1 == '\0' && *string2 == '\0') {
    return 0;
  } else if (*string1 == '\0') {
    return -1;
  } else {
    return 1;
  }
}

char *my_strcpy(char *destination, char *source) {
  int i = 0;
  while (source[i] != '\0') {
    destination[i] = source[i];
    i++;
  }
  destination[i] = '\0';
  return destination;
}

char *my_strncat(char *destination, char *source, int n) {
  int i = 0;
  int j = 0;
  while (destination[i] != '\0') {
    i++;
  }
  while (source[j] != '\0' && j < n) {
    destination[i] = source[j];
    i++;
    j++;
  }
  if (j < n) {
    destination[i] = '\0';
  }
  return destination;
}

char *my_strchr(char *string, char character) {
  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == character) {
      return &string[i];
    }
  }
  return NULL;
}

char **my_strtow(char *string, char *delimiters) {
  int num_words = 0;
  for (int i = 0; string[i] != '\0'; i++) {
    if (!is_delim(string[i], delimiters) && (is_delim(string[i + 1], delimiters) || !string[i + 1])) {
      num_words++;
    }
  }

  char **words = malloc((num_words + 1) * sizeof(char *));
  if (!words) {
    return NULL;
  }

  int j = 0;
  int start = 0;
  int end = 0;
  while (end < strlen(string)) {
    if (string[end] in delimiters) {
      if (end > start) {
        words[j] = malloc((end - start + 1) * sizeof(char));
        if (!words[j]) {
          for (int k = 0; k < j; k++) {
            free(words[k]);
          }
          free(words);
          return NULL;
        }
        strncpy(words[j], string + start, end - start);
        words[j][end - start] = '\0';
        j++;
      }
      start = end + 1;
    }
    end++;
  }
  if (start < end) {
    words[j] = malloc((end - start + 1) * sizeof(char));
    if (!words[j]) {
      for (int k = 0; k < j; k++) {
        free(words[k]);
      }
      free(words);
      return NULL;
    }
    strncpy(words[j], string + start, end - start);
    words[j][end - start] = '\0';
    j++;
  }
  words[j] = NULL;
  return words;
}

char **my_strtow2(char *string, char delimiter) {
  int num_words = 0;
  for (int i = 0; string[i] != '\0'; i++) {
    if ((string[i] != delimiter && string[i + 1] == delimiter) ||
        (string[i] != delimiter && !string
