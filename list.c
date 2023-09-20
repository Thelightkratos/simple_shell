linked_list_node_t *linked_list_add_node_at_head(linked_list_node_t **head, const char *str, int num) {
  linked_list_node_t *new_head;

  if (!head) {
    return NULL;
  }
  new_head = malloc(sizeof(linked_list_node_t));
  if (!new_head) {
    return NULL;
  }
  memset((void *)new_head, 0, sizeof(linked_list_node_t));
  new_head->num = num;
  if (str) {
    new_head->str = strdup(str);
    if (!new_head->str) {
      free(new_head);
      return NULL;
    }
  }
  new_head->next = *head;
  *head = new_head;
  return new_head;
}

/**
 * linked_list_add_node_at_end - adds a node to the end of the linked list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: pointer to the new node
 */
linked_list_node_t *linked_list_add_node_at_end(linked_list_node_t **head, const char *str, int num) {
  linked_list_node_t *new_node, *node;

  if (!head) {
    return NULL;
  }

  node = *head;
  new_node = malloc(sizeof(linked_list_node_t));
  if (!new_node) {
    return NULL;
  }
  memset((void *)new_node, 0, sizeof(linked_list_node_t));
  new_node->num = num;
  if (str) {
    new_node->str = strdup(str);
    if (!new_node->str) {
      free(new_node);
      return NULL;
    }
  }
  if (node) {
    while (node->next) {
      node = node->next;
    }
    node->next = new_node;
  } else {
    *head = new_node;
  }
  return new_node;
}

/**
 * linked_list_print_str - prints only the str element of the linked list
 * @head: pointer to the first node
 *
 * Return: size of the linked list
 */
size_t linked_list_print_str(const linked_list_node_t *head) {
  size_t i = 0;

  while (head) {
    printf("%s\n", head->str ? head->str : "(nil)");
    head = head->next;
    i++;
  }
  return i;
}

/**
 * linked_list_delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int linked_list_delete_node_at_index(linked_list_node_t **head, unsigned int index) {
  linked_list_node_t *node, *prev_node;
  unsigned int i = 0;

  if (!head || !*head) {
    return 0;
  }

  if (!index) {
    node = *head;
    *head = (*head)->next;
    free(node->str);
    free(node);
    return 1;
  }
  node = *head;
  while (node) {
    if (i == index) {
      prev_node->next = node->next;
      free(node->str);
      free(node);
      return 1;
    }
    i++;
    prev_node = node;
