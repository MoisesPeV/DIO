#include <stdio.h>
#include <stdlib.h>

struct Livro {
  char titulo[50];
  char autor[50];
  int ano;
};

int main() {
  int n;
  scanf(" %d", & n);
  struct Livro biblioteca[n];
  for (int i = 0; i < n; i++) {
    //O padr�o " %[^\n]" l� o texto digitado at� a tecla "enter", armazenando o texto na vari�vel.
    //Al�m disso, o espa�o adicional no in�cio garante a limpeza do buffer de leitura.
    scanf(" %[^\n]", biblioteca[i].titulo);
    scanf(" %[^\n]", biblioteca[i].autor);
    scanf(" %d", & biblioteca[i].ano);
  }
  
  int indiceLivroMaisAntigo = 0;
  //TODO: Identificar o �ndice do livro mais antigo, percorrendo a "biblioteca".
  for (int i = 1; i < n; i++) {
    if (biblioteca[i].ano < biblioteca[indiceLivroMaisAntigo].ano) {
      indiceLivroMaisAntigo = i; // Atualiza o �ndice se encontrar um livro mais antigo
    }
  }

  printf("%s\n", biblioteca[indiceLivroMaisAntigo].titulo);
  printf("%s\n", biblioteca[indiceLivroMaisAntigo].autor);
  printf("%d", biblioteca[indiceLivroMaisAntigo].ano);
  
  return 0;
}
