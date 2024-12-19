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
typedef enum
{
  N1,
  N2,
  N3
} Notas;
typedef struct
{
  char nome[50];
  int matricula;
  Notas nota;
} Aluno;
void print_aluno(Aluno *x)
{
  printf("%s %d ", x->nome, x->matricula);
  if (x->nota == N1)
  {
    printf("N1\n");
  }
  else if (x->nota == N2)
  {
    printf("N2\n");
  }
  else if (x->nota == N3)
  {
    printf("N3\n");
  }
}
int main(int argc, char **argv)
{
  Aluno buffer;
  FILE *file = fopen(FILE_NAME, "wb+");
  if (file == NULL)
  {
    printf("Erro ao criar o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  int i;
  Aluno alunos[3];
  for (i = 0; i < N; i++)
  {
    char nota[10];
    scanf("%50s%d%2s", alunos[i].nome, &alunos[i].matricula, nota);
    if (strncmp(nota, "N1", 3) == 0)
    {
      alunos[i].nota = N1;
    }
    else if (strncmp(nota, "N2", 3) == 0)
    {
      alunos[i].nota = N2;
    }
    else if (strncmp(nota, "N3", 3) == 0)
    {
      alunos[i].nota = N3;
    }
    fwrite(&alunos[i], sizeof(Aluno), 1, file);
    print_aluno(&alunos[i]);
  }
  fseek(file, 0, SEEK_SET);
  while (fread(&buffer, sizeof(Aluno), 1, file) != 0)
  {
    print_aluno(&buffer);
  }
  fclose(file);
  return 0;
}