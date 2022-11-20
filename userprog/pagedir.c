#include "userprog/pagedir.h"
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "threads/init.h"
#include "threads/pte.h"
#include "threads/palloc.h"
  
// static uint64_t *active_pd (void);
// static void invalidate_pagedir (uint64_t *);
  
/** Page directory with kernel mappings only. */
uint64_t *init_page_dir;

/** Creates a new page directory that has mappings for kernel
  virtual addresses, but none for user virtual addresses.
  Returns the new page directory, or a null pointer if memory
  allocation fails. */
void *
pagedir_create(void) 
{
  void *pd = palloc_get_page (0);
  if (pd != NULL)
    memcpy (pd, init_page_dir, PGSIZE);
  return pd;
}