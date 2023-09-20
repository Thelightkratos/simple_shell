int strtoi(char *s)
{
  int i = 0;
  unsigned long int result = 0;

  if (*s == '+') {
    s++;
  }

  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      result *= 10;
      result += (s[i] - '0');
      if (result > INT_MAX) {
        return (-1);
      }
    } else {
      return (-1);
    }
  }
  return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *    -1 on error
 */
void print_error(info_t *info, char *estr)
{
  printf("%s: %d: %s: %s\n", info->fname, info->line_count, info->argv[0], estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
  char buf[50];
  int count = 0;

  sprintf(buf, "%d", input);
  count = fputs(buf, fd);

  return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
  char buf[50];
  char *ptr;

  ptr = &buf[49];
  *ptr = '\0';

  do {
    *--ptr = "0123456789abcdef"[(unsigned long)num % base];
    num /= base;
  } while (num != 0);

  return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
  int i;

  for (i = 0; buf[i] != '\0'; i++) {
    if (buf[i] == '#' && (!i || buf[i - 1] == ' ')) {
      buf[i] = '\0';
      break;
    }
  }
}
