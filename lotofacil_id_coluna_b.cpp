#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

bool gerar_b1_b4_b8_b12_b15_id();
bool gerar_b1_b8_b15_id();
bool gerar_b1_b15_id();
bool gerar_b1_id();

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
**/
static long b1_id[12][6];
static long b1_b15_id[12][26][6];
static long b1_b8_b15_id[12][26][26][6];
static long b1_b4_b8_b12_b15_id[12][26][26][26][26][6];

const unsigned long QT_BOLAS_ALOCADAS_B1 = sizeof(long) * 12 * 6;
const unsigned long QT_BOLAS_ALOCADAS_B1_B15 = sizeof(long) * 12 * 26 * 6;
const unsigned long QT_BOLAS_ALOCADAS_B1_B8_B15 = sizeof(long) * 12 * static_cast<unsigned long>(pow(26, 2)) * 6;
const unsigned long QT_BOLAS_ALOCADAS_B1_B4_B8_B12_B15 = sizeof(long) * 12 * static_cast<unsigned long>(pow(26, 4)) * 6;

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


/**
    Chama todas as funçoes, se todas as funçoes
    retornar true, entao, todos os arquivos foram gerados
**/
bool gerar_coluna_b(){
    return  gerar_b1_b4_b8_b12_b15_id() &&
            gerar_b1_b8_b15_id() &&
            gerar_b1_b15_id() &&
            gerar_b1_id();
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
