/**
 * is_executable - determines if a file is an executable command
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_executable(char *path) {
  struct stat st;

  if (!path || stat(path, &st)) {
    return 0;
  }

  if (st.st_mode & S_IFREG) {
    return 1;
  }
  return 0;
}

/**
 * str_dup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: a pointer to the new string
 */
char *str_dup(char *str) {
  int len = strlen(str);
  char *new_str = malloc(len + 1);
  if (!new_str) {
    return NULL;
  }

  memcpy(new_str, str, len + 1);
  return new_str;
}

/**
 * find_path_to_command - finds the full path to a command, given the PATH string
 * @pathstr: the PATH string
 * @cmd: the command to find
 *
 * Return: the full path to the command, or NULL if the command is not found
 */
char *find_path_to_command(char *pathstr, char *cmd) {
  int i = 0, curr_pos = 0;
  char *path;

  if (!pathstr) {
    return NULL;
  }

  if ((strlen(cmd) > 2) && starts_with(cmd, "./")) {
    if (is_executable(cmd)) {
      return cmd;
    }
  }

  while (1) {
    if (!pathstr[i] || pathstr[i] == ':') {
      path = str_dup(pathstr + curr_pos);
      if (!*path) {
        strcat(path, cmd);
      } else {
        strcat(path, "/");
        strcat(path, cmd);
      }

      if (is_executable(path)) {
        return path;
      }

      if (!pathstr[i]) {
        break;
      }

      curr_pos = i;
    }
    i++;
  }
  return NULL;
}
