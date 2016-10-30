#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(char necklace[], long l) {
  /*printf("IN rotate(%s, %lu)\n", necklace, l);*/
  char end = necklace[0];
  for (long i = 0; i < l; i++) {
    necklace[i] = necklace[i + 1];
  }
  necklace[l - 1] = end;
  /*printf("OUT rotate: %s\n", necklace);*/
}

void recurs_canonicalize(char necklace[], long l, long remaining, char mem[]) {
  if (remaining > 0) {
    rotate(necklace, l);
    if (strcmp(necklace, mem) < 0) {
      strcpy(mem, necklace);
    }
    recurs_canonicalize(necklace, l, remaining - 1, mem);
  }
}

void canonicalize(char necklace[], long l) {
  char first[l+1];
  strcpy(first, necklace);
  recurs_canonicalize(first, l, l - 1, necklace);
}

/*void sprintf_list(char* list[], long length, char* result) {*/
  /*if (length == 0) {*/
    /*return;*/
  /*}*/
  /*strcpy(result, list[0]);*/
  /*for (int i = 1; i < length; i++) {*/
    /*strcat(result, ",");*/
    /*strcat(result, list[i]);*/
  /*}*/
/*}*/

void shiftr(char* list[], long length) {
  /*printf("IN shiftr(%s, %lu)", list[0], length);*/
  for (int i = length; i > 0; i--) {
    list[i] = list[i - 1];
  }
  /*printf("OUT shiftr: %s", list[0]);*/
}

int sorted_insert(char* list[], long length, char necklace[], char l) {
  /*char* list_str = malloc(length+(l+2));*/
  /*sprintf_list(list, length, list_str);*/
  /*printf("sorted_insert([%s], %lu, %s)\n", list_str, length, necklace);*/
  if (length == 0) {
    list[0] = necklace;
    return 1;
  } else {
    long pivot = length / 2;
    /*printf("pivot: list[%lu] = %s\n", pivot, list[pivot]);*/
    /*printf("strcmp('%s', '%s')...\n", necklace, list[pivot]);*/
    int cmp = strncmp(necklace, list[pivot], l);
    if (cmp < 0) {
      /*printf("lower than\n");*/
      shiftr(&list[pivot], length - pivot);
      return sorted_insert(list, pivot, necklace, l);
    } else if (cmp > 0) {
      /*printf("greater than\n");*/
      return sorted_insert(&list[pivot + 1], length - pivot - 1, necklace, l);
    } else {
      /*printf("equal!\n");*/
      // Do not insert
      return 0;
    }
  }
}

int main(void) {
  char* input = (char*)malloc(20);
  fgets(input, 20, stdin);
  char* end;
  long n = strtol(input, &end, 10);
  long l = strtol(end, &end, 10);

  /*printf("n=%lu, l=%lu\n", n, l);*/
  char ch;
  char lines[n][l+1];
  for (long i = 0; i < n; i++) {
    fgets(lines[i], l+1, stdin);
    while (((ch = getchar()) != '\n') && (ch != EOF));
    /*printf("Line %lu: %s, size: %lu, last char is \\0: %s\n", i, lines[i], strlen(lines[i]), (lines[i][l] == '\0' ? "true" : "false"));*/
  }
  char *uniq_necklaces[n];
  long length = 0;
  for (long i = 0; i < n; i++) {
    canonicalize(lines[i], l);
    /*printf("Canonicalized line %lu: %s\n", i, lines[i]);*/
    length += sorted_insert(uniq_necklaces, length, lines[i], l);
    /*char* list_str = malloc(length+(l+2));*/
    /*sprintf_list(uniq_necklaces, length, list_str);*/
    /*printf("sorted_list: [%s]\n", list_str);*/
  }
  /*printf("Total unique:\n");*/
  /*for(int i = 0; i < 5e7; i++) {}*/
  printf("%lu", length);

  return 0;
}
