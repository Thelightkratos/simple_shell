size_t linked_list_length(const linked_list_node_t *head) {
  size_t i = 0;

  while (head) {
    head = head->next;
    i++;
  }
  return (i);
}

char **linked_list_to_strings(linked_list_node_t *head) {
  linked_list_node_t *node = head;
  size_t i = linked_list_length(head), j;
  char **strs;
  char *str;

  if (!head || !i) {
    return (NULL);
  }
  strs = malloc(sizeof(char *) * (i + 1));
  if (!strs) {
    return (NULL);
  }
  for (i = 0; node; node = node->next, i++) {
    str = malloc(_strlen(node->str) + 1);
    if (!str) {
      for (j = 0; j < i; j++) {
        free(strs[j]);
      }
      free(strs);
      return (NULL);
    }

    str = _strcpy(str, node->str);
    strs[i] = str;
  }
  strs[i] = NULL;
  return (strs);
}

size_t print_linked_list(const linked_list_node_t *head) {
  size_t i = 0;

  while (head) {
    _puts(convert_number(head->num, 10, 0));
    _putchar(':');
    _putchar(' ');
    _puts(head->str ? head->str : "(nil)");
    _puts("\n");
    head = head->next;
    i++;
  }
  return (i);
}

linked_list_node_t *linked_list_node_starts_with(linked_list_node_t *node, char *prefix, char c) {
  char *p = NULL;

  while (node) {
    p = starts_with(node->str, prefix);
    if (p && ((c == -1) || (*p == c))) {
      return (node);
    }
    node = node->next;
  }
  return (NULL);
}

ssize_t get_linked_list_node_index(linked_list_node_t *head, linked_list_node_t *node) {
  size_t i = 0;

  while (head) {
    if (head == node) {
      return (i);
    }
    head = head->next;
    i++;
  }
  return (-1);
}
