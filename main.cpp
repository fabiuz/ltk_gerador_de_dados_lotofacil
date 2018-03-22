/**
  Programa:     ltk_gerador_de_dados_lotofacil
  Autor:        Fábio Moura de Oliveira

  Objetivo:     Gerar arquivos csv pra serem posteriormente populados em tabelas
  de banco de dados pra analisar o jogo da lotofacil.
**/


#include <iostream>
#include <cstdlib>
#include <cstring>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "lotofacil_diferenca_entre_bolas.h"

using namespace std;

bool gerador_lotofacil();
void gerar_lotomania();

int **lotofacil;
int lotofacil2[6874011][26];

int main()
{
    lotofacil = new int*[6874011];

    for(int uA = 0; uA < 6874011; uA++){
        lotofacil[uA] = new int[26];
    }


    // gerar_lotomania();
    // exit(30);


    // Cria a pasta se não existe.
    struct stat diretorio;
    if(stat("./arquivos_csv", &diretorio) == -1){

        if(mkdir("arquivos_csv", 0770) != 0){
            fprintf(stderr, "Nao foi possivel criar o diretorio arquivos_csv\n");
            return -1;
        }
    }

    if(!gerador_lotofacil()){
        fprintf(stderr, "Erro ao gerar arquivo");
        return -1;
    }

    cout << "Todos os arquivos foram gerados com sucesso!!!" << endl;
    return 0;
}

