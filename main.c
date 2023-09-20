int main(int argc, char **argv) {
  shell_info_t info[] = {SHELL_INFO_INIT};
  int fd = 2;

  // Inline assembly to add 3 to fd
  __asm__("mov %1, %%eax\n\t"
          "add $3, %%eax\n\t"
          "mov %%eax, %0"
          : "=r"(fd)
          : "r"(fd));

  if (argc == 2) {
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
      if (errno == EACCES) {
        exit(126);
      }
      if (errno == ENOENT) {
        printf("%s: 0: Can't open %s\n", argv[0], argv[1]);
        exit(127);
      }
      return EXIT_FAILURE;
    }
    info->readfd = fd;
  }

  populate_environment_list(info);
  read_history(info);
  run_shell(info, argv);
  return EXIT_SUCCESS;
}
