#include "shell.h"

size_t str_length(const char *str) {
	size_t i = 0;

	while (*str) {
		i++;
		str++;
	}

	return i;
}

int str_compare(const char *str1, const char *str2) {
	while (*str1 && *str2) {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}

		str1++;
		str2++;
	}

	if (*str1 == *str2) {
		return 0;
	} else if (*str1 < *str2) {
		return -1;
	} else {
		return 1;
	}
}

char *str_starts_with(const char *haystack, const char *needle) {
	while (*needle) {
		if (*needle != *haystack) {
			return NULL;
		}

		needle++;
		haystack++;
	}

	return (char *)haystack;
}

char *str_concatenate(char *dest, const char *src) {
	char *ret = dest;

	while (*dest) {
		dest++;
	}

	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return ret;
}
