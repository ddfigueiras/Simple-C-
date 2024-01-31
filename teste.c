#include <stdio.h>
#include <string.h>

int main() {
  char word[100];
  char result[100];
  int len, i, j = 0;

  printf("Enter a word with _: ");
  scanf("%s", word);

  len = strlen(word);
  for (i = 0; i < len; i++) {
    if (word[i] == '_') {
      if (i % 2 != 0) {
        result[j++] = word[i-1];
        result[j++] = (char)(i / 2) + '0';
      }
    }
  }

  result[j] = '\0';
  printf("Result: %s\n", result);

  return 0;
}
