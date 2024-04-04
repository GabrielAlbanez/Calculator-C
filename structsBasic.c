#include <stdio.h>
#include <string.h>
#include <locale.h>
#define TAM 50

int main()
{

    setlocale(LC_ALL, "portuguese");

    // structs serve para com que vc defina um novo tipo de dados por exemplo pode ter um arry com dados diferentes

    struct DataUser
    {
        char nome[TAM];
        int idade;
        char sexo;
    };

    // typedef server para vc dar um novo nome para o identificador do struct
    typedef struct DataUser dadosUser;

    // declaracao do struct atraves do dadosUser caso vc nao tenha usando o tydef vc tem que colocar struct e o nome dele e a variavel
    // por isso usamos o struct
    dadosUser usuario = {"Gabriel", 10, "masculino"};

    // usamos a strcpy para atribuir valores strig para vertores char da lib <string.h>
    strcpy(usuario.nome, "Fernando");
    usuario.idade = 20;
    usuario.sexo = 'm';

    printf("Nome:  %s\n", usuario.nome);

    return 0;
}
