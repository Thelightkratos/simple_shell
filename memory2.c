int free_pointer(void *ptr) {
  if (ptr) {
    free(ptr);
    ptr = NULL;
    return 1;
  }
  return 0;
}
