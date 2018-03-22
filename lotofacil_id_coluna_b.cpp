/**
  Programa:     ltk_gerador_de_dados_lotofacil
  Autor:        Fábio Moura de Oliveira
  Arquivo:      lotofacil_id_coluna_b.cpp
  Descrição:    Gera arquivo .csv referente a posição das bolas, nos campos
                b_1, b_4, b8, b_12, b_15
**/


#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

bool gerar_b1_b4_b8_b12_b15_id();
bool gerar_b1_b8_b15_id();
bool gerar_b1_b15_id();
bool gerar_b1_id();

bool gerar_b1_b2_id();
bool gerar_b1_b2_b3_id();
bool gerar_b1_b2_b3_b4_id();
bool gerar_b1_b2_b3_b4_b5_id();

/**
    Na lotofacil:
    b1, corresponde a bola na coluna b_1 da tabela lotofacil_bolas,
    b4, corresponde a bola na coluna b_4 da tabela lotofacil_bolas,
    b8, corresponde a bola na coluna b_8 da tabela lotofacil_bolas,
    b12, corresponde a bola na coluna b_12 da tabela lotofacil_bolas,
    b15, corresponde a bola na coluna b_15 da tabela lotofacil_bolas.

    b1, vai de 1 a 11
    b4, vai de 4 a 14
    b8, vai de 8 a 18
    b12, vai de 12 a 22
    b15, vai de 15 a 25


**/

/**
    O ultimo indice da ultima dimensao, corresponde a:
    indice 0, identificador da combinacao;
    indice 1, quantidade de combinacoes encontradas com 15 bolas
    indice 2, quantidade de combinacoes encontradas com 16 bolas
    indice 3, quantidade de combinacoes encontradas com 17 bolas
    indice 4, quantidade de combinacoes encontradas com 18 bolas
    indice 5, quantidade de combinacoes encontradas.

    Estes índices são utilizados posteriormente no gerador pra contabilizar
    quantas combinações tem aquela combinação.
    Haja vista que, os campos b1, b4, b8, b12, e b15, existem nas
    combinações de 15 a 18 bolas.
**/
static long b1_id[12][6];
static long b1_b15_id[12][26][6];
static long b1_b8_b15_id[12][26][26][6];
static long b1_b4_b8_b12_b15_id[12][26][26][26][26][6];

static long b1_b2_id[12][26][6];
static long b1_b2_b3_id[12][26][26][6];
static long b1_b2_b3_b4_id[12][26][26][26][6];
static long b1_b2_b3_b4_b5_id[12][26][26][26][26][6];

const unsigned long QT_BOLAS_ALOCADAS_B1 = sizeof(long) * 12 * 6;
const unsigned long QT_BOLAS_ALOCADAS_B1_B15 = sizeof(long) * 12 * 26 * 6;
const unsigned long QT_BOLAS_ALOCADAS_B1_B8_B15 = sizeof(long) * 12 * static_cast<unsigned long>(pow(26, 2)) * 6;
const unsigned long QT_BOLAS_ALOCADAS_B1_B4_B8_B12_B15 = sizeof(long) * 12 * static_cast<unsigned long>(pow(26, 4)) * 6;

const unsigned long QT_BOLAS_ALOCADAS_B1_b2 = sizeof(long) * 12 * 26 * 6;
const unsigned long QT_BOLAS_ALOCADAS_B1_B2_B3 = sizeof(long) * 12 * static_cast<unsigned long>(pow(26, 2)) * 6;
const unsigned long QT_BOLAS_ALOCADAS_B1_B2_B3_B4 = sizeof(long) * 12 * static_cast<unsigned long>(pow(26, 3)) * 6;
const unsigned long QT_BOLAS_ALOCADAS_B1_B2_B3_B4_B5 = sizeof(long) * 12 * static_cast<unsigned long>(pow(26, 4)) * 6;





/*!
 * \brief obter_b1_id
 * Retorna o identificador da combinação b1.
 * \param b1 Combinação b1, que refere-se ao campo 'b_1' da tabela lotofacil_id_b1
 * \return
 * Retorna o identificador do parâmetro b1, que corresponde à combinação b1,
 * se for válida na lotofacil, entretanto, retorna -1, se o parâmetro não
 * corresponde a nenhum parâmetro.
 */
long obter_b1_id(long b1){
    bool b_b1 = (b1 >= 1) && (b1 <= 11);

    if(!b_b1)
        return -1;

    return b1_id[b1][0];
}

long obter_b1_b15_id(long b1, long b15){
    bool b_b1_b15 =     (b1  >= 1 ) && (b1 <= 11) &&
                        (b15 >= 15) && (b1 <= 25);

    if(!b_b1_b15)
        return -1;

    return b1_b15_id[b1][b15][0];
}

long obter_b1_b8_b15_id(long b1, long b8, long b15){
    bool b_b1_b8_b15 =  (b1  >=  1) && (b1 <= 11) &&
                        (b8  >=  8) && (b8 <= 18) &&
                        (b15 >= 15) && (b15 <= 25);

    if(!b_b1_b8_b15)
        return - 1;

    return b1_b8_b15_id[b1][b8][b15][0];
}

long obter_b1_b4_b8_b12_b15_id(long b1, long b4, long b8, long b12, long b15){
    bool b_b1_b4_b8_b12_b15 =   (b1  >=  1) && (b1  <= 11) &&
                                (b4  >=  4) && (b4  <= 14) &&
                                (b8  >=  8) && (b8  <= 18) &&
                                (b12 >= 12) && (b12 <= 22) &&
                                (b15 >= 15) && (b15 <= 25);

    if(!b_b1_b4_b8_b12_b15)
        return -1;

    return b1_b4_b8_b12_b15_id[b1][b4][b8][b12][b15][0];
}

/***
 *
 */
long obter_b1_b2_id(long b1, long b2){
    bool b_b1_b2 =     (b1  >= 1 ) && (b1 <= 11) &&
                        (b2 >= 2) && (b1 <= 12);

    if(!b_b1_b2)
        return -1;

    return b1_b2_id[b1][b2][0];
}

long obter_b1_b2_b3_id(long b1, long b2, long b3){
    bool b_b1_b2_b3 =  (b1  >=  1) && (b1 <= 11) &&
                        (b2  >=  2) && (b2 <= 12) &&
                        (b3 >= 3) && (b3 <= 13);

    if(!b_b1_b2_b3)
        return - 1;

    return b1_b2_b3_id[b1][b2][b3][0];
}

long obter_b1_b2_b3_b4_id(long b1, long b2, long b3, long b4){
    bool b_b1_b2_b3_b4 =    (b1 >= 1) && (b1 <= 11) &&
                            (b2 >= 2) && (b2 <= 12) &&
                            (b3 >= 3) && (b3 <= 13) &&
                            (b4 >= 4) && (b4 <= 14);

    if(!b_b1_b2_b3_b4)
        return -1;

    return b1_b2_b3_b4_id[b1][b2][b3][b4][0];
}


long obter_b1_b2_b3_b4_b5_id(long b1, long b2, long b3, long b4, long b5){
    bool b_b1_b2_b3_b4_b5 =     (b1 >= 1) && (b1 <= 11) &&
                                (b2 >= 2) && (b2 <= 12) &&
                                (b3 >= 3) && (b3 <= 13) &&
                                (b4 >= 4) && (b4 <= 14) &&
                                (b5 >= 5) && (b5 <= 15);

    if(!b_b1_b2_b3_b4_b5)
        return -1;

    return b1_b2_b3_b4_b5_id[b1][b2][b3][b4][b5][0];
}


/**
    Chama todas as funçoes, se todas as funçoes
    retornar true, entao, todos os arquivos foram gerados
    corretamente.
**/
bool gerar_coluna_b(){
    return  gerar_b1_b4_b8_b12_b15_id() &&
            gerar_b1_b8_b15_id() &&
            gerar_b1_b15_id() &&
            gerar_b1_id() &&
            gerar_b1_b2_id() &&
            gerar_b1_b2_b3_id() &&
            gerar_b1_b2_b3_b4_id() &&
            gerar_b1_b2_b3_b4_b5_id();
}


bool gerar_b1_b4_b8_b12_b15_id(){
    FILE * f_b1_b4_b8_b12_b15 = fopen("./arquivos_csv/lotofacil_id_b1_b4_b8_b12_b15.csv", "w");
    if(!f_b1_b4_b8_b12_b15){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_b1_b4_b8_b12_b15.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_b1_b4_b8_b12_b15, "b1_b4_b8_b12_b15_id;b1;b4;b8;b12;b15");

    if(ferror(f_b1_b4_b8_b12_b15)){
        fprintf(stderr, "Erro ao gravar cabecalho no arquivo lotofacil_id_b1_b4_b8_b12_b15.cpp");
        return false;
    }

    // Reseta o valor das variaveis
    memset(b1_b4_b8_b12_b15_id, 0, QT_BOLAS_ALOCADAS_B1_B4_B8_B12_B15);

    for(int b1 = 1; b1 <= 11; b1++)
    for(int b4 = b1 + 3; b4 <= 14; b4++)
    for(int b8 = b4 + 4; b8 <= 18; b8++)
    for(int b12 = b8 + 4; b12 <= 22; b12++)
    for(int b15 = b12 + 3; b15 <= 25; b15++)
    {
        id_combinacao++;

        b1_b4_b8_b12_b15_id[b1][b4][b8][b12][b15][0] = id_combinacao;
        b1_b4_b8_b12_b15_id[b1][b4][b8][b12][b15][1] = 0;
        b1_b4_b8_b12_b15_id[b1][b4][b8][b12][b15][2] = 0;
        b1_b4_b8_b12_b15_id[b1][b4][b8][b12][b15][3] = 0;
        b1_b4_b8_b12_b15_id[b1][b4][b8][b12][b15][4] = 0;
        b1_b4_b8_b12_b15_id[b1][b4][b8][b12][b15][5] = 0;

        fprintf(f_b1_b4_b8_b12_b15, "\n%i;%i;%i;%i;%i;%i", id_combinacao, b1, b4, b8, b12, b15);

        if(ferror(f_b1_b4_b8_b12_b15)){
            fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_b1_b4_b8_b12_b15,"
                            "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
            return false;
        }
    }

    fclose(f_b1_b4_b8_b12_b15);
    return true;
}

bool gerar_b1_b8_b15_id(){
    FILE * f_b1_b8_b15 = fopen("./arquivos_csv/lotofacil_id_b1_b8_b15.csv", "w");
    if(!f_b1_b8_b15){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_b1_b8_b15.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_b1_b8_b15, "b1_b8_b15_id;b1;b8;b15");

    if(ferror(f_b1_b8_b15)){
        fprintf(stderr, "Erro ao gravar cabecalho no arquivo lotofacil_id_b1_b8_b15.cpp");
        return false;
    }

    // Zera os valores.
    memset(b1_b8_b15_id, 0, QT_BOLAS_ALOCADAS_B1_B8_B15);

    for(int b1 = 1; b1 <= 11; b1++)
    for(int b8 = b1 + 7; b8 <= 18; b8++)
    for(int b15 = b8 + 7; b15 <= 25; b15++)
    {
        id_combinacao++;

        b1_b8_b15_id[b1][b8][b15][0] = id_combinacao;
        b1_b8_b15_id[b1][b8][b15][1] = 0;
        b1_b8_b15_id[b1][b8][b15][2] = 0;
        b1_b8_b15_id[b1][b8][b15][3] = 0;
        b1_b8_b15_id[b1][b8][b15][4] = 0;
        b1_b8_b15_id[b1][b8][b15][5] = 0;

        fprintf(f_b1_b8_b15, "\n%i;%i;%i;%i", id_combinacao, b1, b8, b15);

        if(ferror(f_b1_b8_b15)){
            fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_b1_b8_b15,"
                            "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
            return false;
        }
    }

    fclose(f_b1_b8_b15);
    return true;
}

bool gerar_b1_b15_id(){
    FILE * f_b1_b15 = fopen("./arquivos_csv/lotofacil_id_b1_b15.csv", "w");
    if(!f_b1_b15){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_b1_b15.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_b1_b15, "b1_b15_id;b1;b15");

    if(ferror(f_b1_b15)){
        fprintf(stderr, "Erro ao gravar cabecalho no arquivo lotofacil_id_b1_b15.cpp");
        return false;
    }

    // Zera os valores.
    memset(b1_b15_id, 0, QT_BOLAS_ALOCADAS_B1_B15);

    for(int b1 = 1; b1 <= 11; b1++)
    for(int b15 = b1 + 14; b15 <= 25; b15++)
    {
        id_combinacao++;

        b1_b15_id[b1][b15][0] = id_combinacao;
        b1_b15_id[b1][b15][1] = 0;
        b1_b15_id[b1][b15][2] = 0;
        b1_b15_id[b1][b15][3] = 0;
        b1_b15_id[b1][b15][4] = 0;
        b1_b15_id[b1][b15][5] = 0;

        fprintf(f_b1_b15, "\n%i;%i;%i", id_combinacao, b1, b15);

        if(ferror(f_b1_b15)){
            fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_b1_b15,"
                            "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
            return false;
        }
    }

    fclose(f_b1_b15);
    return true;
}

bool gerar_b1_id(){
    FILE * f_b1 = fopen("./arquivos_csv/lotofacil_id_b1.csv", "w");
    if(!f_b1){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_b1.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_b1, "b1_id;b1");

    if(ferror(f_b1)){
        fprintf(stderr, "Erro ao gravar cabecalho no arquivo lotofacil_id_b1.cpp");
        return false;
    }

    // Zera os valores.
    memset(b1_id, 0, QT_BOLAS_ALOCADAS_B1);

    for(int b1 = 1; b1 <= 11; b1++)
    {
        id_combinacao++;

        b1_id[b1][0] = id_combinacao;
        b1_id[b1][1] = 0;
        b1_id[b1][2] = 0;
        b1_id[b1][3] = 0;
        b1_id[b1][4] = 0;
        b1_id[b1][5] = 0;

        fprintf(f_b1, "\n%i;%i", id_combinacao, b1);

        if(ferror(f_b1)){
            fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_b1,"
                            "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
            return false;
        }
    }

    fclose(f_b1);
    return true;
}

bool gerar_b1_b2_id(){
    FILE * f_b1_b2 = fopen("./arquivos_csv/lotofacil_id_b1_b2.csv", "w");
    if(!f_b1_b2){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_b1_b2.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_b1_b2, "b1_b2_id;b1;b2");

    if(ferror(f_b1_b2)){
        fprintf(stderr, "Erro ao gravar cabecalho no arquivo lotofacil_id_b1_b2.cpp");
        return false;
    }

    // Zera os valores.
    memset(b1_b2_id, 0, QT_BOLAS_ALOCADAS_B1_b2);

    for(int b1 = 1; b1 <= 11; b1++)
    for(int b2 = b1 + 1; b2 <= 12; b2++)
    {
        id_combinacao++;

        b1_b2_id[b1][b2][0] = id_combinacao;
        b1_b2_id[b1][b2][1] = 0;
        b1_b2_id[b1][b2][2] = 0;
        b1_b2_id[b1][b2][3] = 0;
        b1_b2_id[b1][b2][4] = 0;
        b1_b2_id[b1][b2][5] = 0;

        fprintf(f_b1_b2, "\n%i;%i;%i", id_combinacao, b1, b2);

        if(ferror(f_b1_b2)){
            fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_b1_b2,"
                            "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
            return false;
        }
    }

    fclose(f_b1_b2);
    return true;
}

bool gerar_b1_b2_b3_id(){
    FILE * f_b1_b2_b3 = fopen("./arquivos_csv/lotofacil_id_b1_b2_b3.csv", "w");
    if(!f_b1_b2_b3){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_b1_b2_b3.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_b1_b2_b3, "b1_b2_b3_id;b1;b2;b3");

    if(ferror(f_b1_b2_b3)){
        fprintf(stderr, "Erro ao gravar cabecalho no arquivo lotofacil_id_b1_b2_b3.cpp");
        return false;
    }

    // Zera os valores.
    memset(b1_b2_b3_id, 0, QT_BOLAS_ALOCADAS_B1_B2_B3);

    for(int b1 = 1; b1 <= 11; b1++)
    for(int b2 = b1 + 1; b2 <= 12; b2++)
    for(int b3 = b2 + 1; b3 <= 13; b3++)
    {
        id_combinacao++;

        b1_b2_b3_id[b1][b2][b3][0] = id_combinacao;
        b1_b2_b3_id[b1][b2][b3][1] = 0;
        b1_b2_b3_id[b1][b2][b3][2] = 0;
        b1_b2_b3_id[b1][b2][b3][3] = 0;
        b1_b2_b3_id[b1][b2][b3][4] = 0;
        b1_b2_b3_id[b1][b2][b3][5] = 0;

        fprintf(f_b1_b2_b3, "\n%i;%i;%i;%i", id_combinacao, b1, b2, b3);

        if(ferror(f_b1_b2_b3)){
            fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_b1_b2_b3,"
                            "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
            return false;
        }
    }

    fclose(f_b1_b2_b3);
    return true;
}

bool gerar_b1_b2_b3_b4_id(){
    FILE * f_b1_b2_b3_b4 = fopen("./arquivos_csv/lotofacil_id_b1_b2_b3_b4.csv", "w");
    if(!f_b1_b2_b3_b4){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_b1_b2_b3_b4.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_b1_b2_b3_b4, "b1_b2_b3_b4_id;b1;b2;b3;b4;b5");

    if(ferror(f_b1_b2_b3_b4)){
        fprintf(stderr, "Erro ao gravar cabecalho no arquivo lotofacil_id_b1_b2_b3_b4.cpp");
        return false;
    }

    // Reseta o valor das variaveis
    memset(b1_b2_b3_b4_id, 0, QT_BOLAS_ALOCADAS_B1_B2_B3_B4);

    for(int b1 = 1; b1 <= 11; b1++)
    for(int b2 = b1 + 1; b2 <= 12; b2++)
    for(int b3 = b2 + 1; b3 <= 13; b3++)
    for(int b4 = b3 + 1; b4 <= 14; b4++)
    {
        id_combinacao++;

        b1_b2_b3_b4_id[b1][b2][b3][b4][0] = id_combinacao;
        b1_b2_b3_b4_id[b1][b2][b3][b4][1] = 0;
        b1_b2_b3_b4_id[b1][b2][b3][b4][2] = 0;
        b1_b2_b3_b4_id[b1][b2][b3][b4][3] = 0;
        b1_b2_b3_b4_id[b1][b2][b3][b4][4] = 0;
        b1_b2_b3_b4_id[b1][b2][b3][b4][5] = 0;

        fprintf(f_b1_b2_b3_b4, "\n%i;%i;%i;%i;%i", id_combinacao, b1, b2, b3, b4);

        if(ferror(f_b1_b2_b3_b4)){
            fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_b1_b2_b3_b4,"
                            "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
            return false;
        }
    }

    fclose(f_b1_b2_b3_b4);
    return true;
}

bool gerar_b1_b2_b3_b4_b5_id(){
    FILE * f_b1_b2_b3_b4_b5 = fopen("./arquivos_csv/lotofacil_id_b1_b2_b3_b4_b5.csv", "w");
    if(!f_b1_b2_b3_b4_b5){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_b1_b2_b3_b4_b5.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_b1_b2_b3_b4_b5, "b1_b2_b3_b4_b5_id;b1;b2;b3;b4;b5");

    if(ferror(f_b1_b2_b3_b4_b5)){
        fprintf(stderr, "Erro ao gravar cabecalho no arquivo lotofacil_id_b1_b2_b3_b4_b5.cpp");
        return false;
    }

    // Reseta o valor das variaveis
    memset(b1_b2_b3_b4_b5_id, 0, QT_BOLAS_ALOCADAS_B1_B2_B3_B4_B5);

    for(int b1 = 1; b1 <= 11; b1++)
    for(int b2 = b1 + 1; b2 <= 12; b2++)
    for(int b3 = b2 + 1; b3 <= 13; b3++)
    for(int b4 = b3 + 1; b4 <= 14; b4++)
    for(int b5 = b4 + 1; b5 <= 15; b5++)
    {
        id_combinacao++;

        b1_b2_b3_b4_b5_id[b1][b2][b3][b4][b5][0] = id_combinacao;
        b1_b2_b3_b4_b5_id[b1][b2][b3][b4][b5][1] = 0;
        b1_b2_b3_b4_b5_id[b1][b2][b3][b4][b5][2] = 0;
        b1_b2_b3_b4_b5_id[b1][b2][b3][b4][b5][3] = 0;
        b1_b2_b3_b4_b5_id[b1][b2][b3][b4][b5][4] = 0;
        b1_b2_b3_b4_b5_id[b1][b2][b3][b4][b5][5] = 0;

        fprintf(f_b1_b2_b3_b4_b5, "\n%i;%i;%i;%i;%i;%i", id_combinacao, b1, b2, b3, b4, b5);

        if(ferror(f_b1_b2_b3_b4_b5)){
            fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_b1_b2_b3_b4_b5,"
                            "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
            return false;
        }
    }

    fclose(f_b1_b2_b3_b4_b5);
    return true;
}
