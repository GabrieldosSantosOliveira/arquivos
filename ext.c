#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "rando.txt"
#define N 1000
#define ERROR_OPEN_FILE 30
typedef enum
{
  true = 1,
  false = 0
} bool;



int main(int argc, char **argv)
{

  FILE *file = fopen(FILE_NAME, "w+");

  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  int buffer;
  srand(time(NULL));
  for (size_t i = 0; i < N; i++)
  {
    buffer = rand() % 100;
    fprintf(file, "%d\n", buffer);
  }
  fclose(file);
  return 0;
}