#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "rando.txt"
#define N 3
#define ERROR_OPEN_FILE 30
typedef enum
{
  true = 1,
  false = 0
} bool;

void bubble_sort(int *v, int n)
{
  int i = 0;
  int end = (n - 1);
  while (end >= 1)
  {
    bool flag = false;
    int k;
    for (k = 0; k < end; k++)
    {
      if (v[k + 1] < v[k])
      {
        int tmp = v[k];
        v[k] = v[k + 1];
        v[k + 1] = tmp;
        flag = true;
      }
    }
    end = end - 1;
    if (flag == false)
    {
      break;
    }
  }
}

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    printf("Informe o nome do arquivo de entrada e saida\n");
    return -1;
  }

  FILE *file = fopen(argv[1], "r+");
  FILE *output = fopen(argv[2], "r+");
  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  if (output == NULL)
  {
    printf("Erro ao abrir o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  int buffer[2];

  while (fscanf(file, "%d%d", &(buffer[0]), &(buffer[1])) != EOF)
  {
    if (buffer[0] > buffer[1])
    {
      int tmp = buffer[0];
      buffer[0] = buffer[1];
      buffer[1] = tmp;
    }
    fprintf(output, "%d\n%d\n", buffer[0], buffer[1]);
  }
  fseek(output, 0, SEEK_SET);
  int num;
  while (fscanf(output, "%d", &num) != EOF)
  {
    printf("%d\n", num);
  }

  fclose(file);
  fclose(output);
  return 0;
}