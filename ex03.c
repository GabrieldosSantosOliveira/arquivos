#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MISSING_PARAM_ERROR 10
#define ERROR_OPEN_FILE 20
#define ARQUIVO "arquivo.txt"

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("Informe o valor de N\n");
    return MISSING_PARAM_ERROR;
  }
  int n = atoi(argv[1]);
  FILE *file = fopen(ARQUIVO, "w");
  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  srand(time(NULL));
  while (n--)
  {
    char letter = rand() % 26 + 'a';
    fprintf(file, "%c", letter);
  }
  fclose(file);
  return 0;
}