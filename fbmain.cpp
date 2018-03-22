#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstring>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

/***
 *
 * Pares x Ímpares
 *
 */
long par_impar_id[16][16][2];
bool gerar_par_impar_comum_id();
bool gerar_par_impar_id(){

    FILE * f_par_impar = fopen("./arquivos_csv/lotofacil_id_par_impar.csv", "w");
    if(!f_par_impar){
        fprintf(stderr, "Erro ao abrir arquivo: lotofacil_id_par_impar.csv\n");
        return false;
    }

    fprintf(f_par_impar, "par_impar_id;par_impar_qt;par;impar");

    memset(par_impar_id, 0, sizeof(long) * 16 * 16 * 2);

    long id_par_impar = 0;
    long soma_par_impar = 0;

    for(int par = 2; par <= 12; par++)
    for(int impar = 3; impar <= 13; impar++){
        soma_par_impar = par + impar;

        if((soma_par_impar >= 15) && (soma_par_impar <= 18)){
            id_par_impar++;
            par_impar_id[par][impar][0] = id_par_impar;
            par_impar_id[par][impar][1] = 0;

            fprintf(f_par_impar, "\n%li;%li;%i;%i", id_par_impar, soma_par_impar, par, impar);
            fprintf(stdout, "\n%li;%li;%i;%i", id_par_impar, soma_par_impar, par, impar);

        }
    }

    fclose(f_par_impar);
    return gerar_par_impar_comum_id();
}

/**
    Gera as combinacoes comuns a combinacao atual.
**/
bool gerar_par_impar_comum_id(){

    FILE * f_par_impar_comum = fopen("./arquivos_csv/lotofacil_id_par_impar_comum.csv", "w");

    if(!f_par_impar_comum){
        fprintf(stderr, "Erro ao abrir arquivo: lotofacil_id_par_impar.csv");
        return false;
    }

    fprintf(f_par_impar_comum, "comum_id;par_impar_id;par_impar_id_comum");

    long soma_par_impar_1 = 0;
    long soma_par_impar_2 = 0;
    long comum_id = 0;

    for(int par_1 = 2; par_1 <= 12; par_1++)
    for(int impar_1 = 3; impar_1 <= 13; impar_1++){

        soma_par_impar_1 = par_1 + impar_1;

        if((soma_par_impar_1 >= 15) && (soma_par_impar_1 <= 18)){

                long id_par_impar_1 = par_impar_id[par_1][impar_1][0];

                for(int par_2 = 2; par_2 <= 12; par_2++)
                for(int impar_2 = 3; impar_2 <= 13; impar_2++){

                    long soma_par_impar_2 = par_2 + impar_2;

                    if((soma_par_impar_2 >= 15) && (soma_par_impar_2 <= 18)){
                        long id_par_impar_2 = par_impar_id[par_2][impar_2][0];
                        bool comum_localizado = false;

                        // Vamos detectar possivel combinacao comum.
                        for(int uA = 0; uA <= 3; uA++){
                            long impar_3 = uA;
                            for(long par_3 = 0; par_3 <= uA; par_3++){
                                long par_4 = par_1 + par_3;
                                long impar_4 = impar_1 + impar_3;

                                if((par_4 == par_2) && (impar_4 == impar_2)){
                                    comum_localizado = true;
                                    break;
                                }

                                par_4 = par_1 - par_3;
                                impar_4 = impar_1 - impar_3;

                                if((par_4 == par_2) && (impar_4 == impar_2)){
                                    comum_localizado = true;
                                    break;
                                }
                                impar_3--;
                            }
                            if(comum_localizado){
                                break;
                            }
                        }

                    if(comum_localizado)
                    {
                        comum_id++;

                            fprintf(f_par_impar_comum, "\n%li;%li;%li", comum_id, id_par_impar_1, id_par_impar_2);
                        }
                    }
                }
        }
    }

    fclose(f_par_impar_comum);
    return true;
}

/**
  Externos x Internos
**/
bool gerar_externo_interno_comum_id();
long externo_interno_id[17][10][2];
bool gerar_externo_interno_id(){

    FILE * f_externo_interno = fopen("./arquivos_csv/lotofacil_id_externo_interno.csv", "w");
    if(!f_externo_interno){
        fprintf(stderr, "Erro ao abrir arquivo: lotofacil_id_externo_interno.csv");
        return false;
    }

    fprintf(f_externo_interno, "externo_interno_id;externo_interno_qt;externo;interno");

    memset(externo_interno_id, 0, sizeof(long) * 17 * 10 * 2);

    long id_externo_interno = 0;
    long soma_externo_interno = 0;

    for(int externo = 0; externo <= 16; externo++)
    for(int interno = 0; interno <= 9; interno++){
        soma_externo_interno = externo + interno;

        if((soma_externo_interno >= 15) && (soma_externo_interno <= 18)){
            id_externo_interno++;
            externo_interno_id[externo][interno][0] = id_externo_interno;
            externo_interno_id[externo][interno][1] = 0;

            fprintf(f_externo_interno, "\n%li;%li;%i;%i", id_externo_interno, soma_externo_interno, externo, interno);
        }
    }

    fclose(f_externo_interno);
    return gerar_externo_interno_comum_id();
}

/**
    Gera as combinaçoes comuns a combinacao atual.
**/
bool gerar_externo_interno_comum_id(){

    FILE * f_externo_interno_comum = fopen("./arquivos_csv/lotofacil_id_externo_interno_comum.csv", "w");

    if(!f_externo_interno_comum){
        fprintf(stderr, "Erro ao abrir arquivo: lotofacil_id_externo_interno.csv");
        return false;
    }

    fprintf(f_externo_interno_comum, "comum_id;externo_interno_id;externo_interno_id_comum");

    long soma_externo_interno_1 = 0;
    long soma_externo_interno_2 = 0;
    long comum_id = 0;

    for(int externo_1 = 0; externo_1 <= 16; externo_1++)
    for(int interno_1 = 0; interno_1 <= 9; interno_1++){

        soma_externo_interno_1 = externo_1 + interno_1;

        if((soma_externo_interno_1 >= 15) && (soma_externo_interno_1 <= 18)){

                long id_externo_interno_1 = externo_interno_id[externo_1][interno_1][0];

                for(int externo_2 = 0; externo_2 <= 16; externo_2++)
                for(int interno_2 = 0; interno_2 <= 9; interno_2++){

                    long soma_externo_interno_2 = externo_2 + interno_2;

                    if((soma_externo_interno_2 >= 15) && (soma_externo_interno_2 <= 18)){
                        long id_externo_interno_2 = externo_interno_id[externo_2][interno_2][0];
                        bool comum_localizado = false;

                        // Vamos detectar possivel combinacao comum.
                        for(int uA = 0; uA <= 3; uA++){
                            long interno_3 = uA;
                            for(long externo_3 = 0; externo_3 <= uA; externo_3++){
                                long externo_4 = externo_1 + externo_3;
                                long interno_4 = interno_1 + interno_3;

                                if((externo_4 == externo_2) && (interno_4 == interno_2)){
                                    comum_localizado = true;
                                    break;
                                }

                                externo_4 = externo_1 - externo_3;
                                interno_4 = interno_1 - interno_3;

                                if((externo_4 == externo_2) && (interno_4 == interno_2)){
                                    comum_localizado = true;
                                    break;
                                }
                                interno_3--;
                            }
                            if(comum_localizado){
                                break;
                            }
                        }

                    if(comum_localizado)
                    {
                        comum_id++;

                            fprintf(f_externo_interno_comum, "\n%li;%li;%li", comum_id, id_externo_interno_1, id_externo_interno_2);
                        }
                    }
                }
        }
    }

    fclose(f_externo_interno_comum);
    return true;
}

/***********************************************************************
           Primo x Não_Primo
************************************************************************/
bool gerar_primo_nao_primo_comum_id();
long primo_nao_primo_id[17][10][2];
bool gerar_primo_nao_primo_id(){

    FILE * f_primo_nao_primo = fopen("./arquivos_csv/lotofacil_id_primo_nao_primo.csv", "w");
    if(!f_primo_nao_primo){
        fprintf(stderr, "Erro ao abrir arquivo: lotofacil_id_primo_nao_primo.csv");
        return false;
    }

    fprintf(f_primo_nao_primo, "prm_id;prm_qt;primo;nao_primo");

    memset(primo_nao_primo_id, 0, sizeof(long) * 16 * 16 * 2);

    long id_primo_nao_primo = 0;
    long soma_primo_nao_primo = 0;

    for(int primo = 0; primo <= 9; primo++)
    for(int nao_primo = 0; nao_primo <= 16; nao_primo++){
        soma_primo_nao_primo = primo + nao_primo;

        if((soma_primo_nao_primo >= 15) && (soma_primo_nao_primo <= 18)){
            id_primo_nao_primo++;
            primo_nao_primo_id[primo][nao_primo][0] = id_primo_nao_primo;
            primo_nao_primo_id[primo][nao_primo][1] = id_primo_nao_primo;

            fprintf(f_primo_nao_primo, "\n%li;%li;%i;%i", id_primo_nao_primo, soma_primo_nao_primo, primo, nao_primo);
        }
    }

    fclose(f_primo_nao_primo);
    return gerar_primo_nao_primo_comum_id();
}

/**
    Gera as combinaçoes comuns a combinacao atual.
**/
bool gerar_primo_nao_primo_comum_id(){

    FILE * f_primo_nao_primo_comum = fopen("./arquivos_csv/lotofacil_id_primo_nao_primo_comum.csv", "w");

    if(!f_primo_nao_primo_comum){
        fprintf(stderr, "Erro ao abrir arquivo: lotofacil_id_primo_nao_primo.csv");
        return false;
    }

    fprintf(f_primo_nao_primo_comum, "comum_id;prm_id;prm_id_comum");

    long soma_primo_nao_primo_1 = 0;
    long soma_primo_nao_primo_2 = 0;
    long comum_id = 0;

    for(int primo_1 = 0; primo_1 <= 9; primo_1++)
    for(int nao_primo_1 = 0; nao_primo_1 <= 16; nao_primo_1++){

        soma_primo_nao_primo_1 = primo_1 + nao_primo_1;

        if((soma_primo_nao_primo_1 >= 15) && (soma_primo_nao_primo_1 <= 18)){

                long id_primo_nao_primo_1 = primo_nao_primo_id[primo_1][nao_primo_1][0];

                for(int primo_2 = 0; primo_2 <= 9; primo_2++)
                for(int nao_primo_2 = 0; nao_primo_2 <= 16; nao_primo_2++){

                    long soma_primo_nao_primo_2 = primo_2 + nao_primo_2;

                    if((soma_primo_nao_primo_2 >= 15) && (soma_primo_nao_primo_2 <= 18)){
                        long id_primo_nao_primo_2 = primo_nao_primo_id[primo_2][nao_primo_2][0];
                        bool comum_localizado = false;

                        // Vamos detectar possivel combinacao comum.
                        for(int uA = 0; uA <= 3; uA++){
                            long nao_primo_3 = uA;
                            for(long primo_3 = 0; primo_3 <= uA; primo_3++){
                                long primo_4 = primo_1 + primo_3;
                                long nao_primo_4 = nao_primo_1 + nao_primo_3;

                                if((primo_4 == primo_2) && (nao_primo_4 == nao_primo_2)){
                                    comum_localizado = true;
                                    break;
                                }

                                primo_4 = primo_1 - primo_3;
                                nao_primo_4 = nao_primo_1 - nao_primo_3;

                                if((primo_4 == primo_2) && (nao_primo_4 == nao_primo_2)){
                                    comum_localizado = true;
                                    break;
                                }
                                nao_primo_3--;
                            }
                            if(comum_localizado){
                                break;
                            }
                        }

                    if(comum_localizado)
                    {
                        comum_id++;

                            fprintf(f_primo_nao_primo_comum, "\n%li;%li;%li", comum_id, id_primo_nao_primo_1, id_primo_nao_primo_2);
                        }
                    }
                }
        }
    }

    fclose(f_primo_nao_primo_comum);
    return true;
}

/***********************************************************************
 *          HORIZONTAL
 *          VERTICAL
 *          DIAGONAL
 *          CRUZETA
 **********************************************************************/
static long horizontal_id[6][6][6][6][6][2];
static long vertical_id[6][6][6][6][6][2];
static long diagonal_id[6][6][6][6][6][2];
static long cruzeta_id[6][6][6][6][6][2];

bool gerar_combinacao_com_5_bolas(){
    FILE * f_horizontal = fopen("./arquivos_csv/lotofacil_id_horizontal.csv", "w");
    if(!f_horizontal){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_horizontal.csv pra gravaçao");
        return false;
    }

    FILE * f_vertical = fopen("./arquivos_csv/lotofacil_id_vertical.csv", "w");
    if(!f_vertical){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_vertical.csv pra gravaçao");
        return false;
    }

    FILE * f_diagonal = fopen("./arquivos_csv/lotofacil_id_diagonal.csv", "w");
    if(!f_diagonal){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_diagonal.csv pra gravaçao");
        return false;
    }

    FILE * f_cruzeta = fopen("./arquivos_csv/lotofacil_id_cruzeta.csv", "w");
    if(!f_cruzeta){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_cruzeta.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_horizontal, "hrz_id;hrz_qt;hrz_1;hrz_2;hrz_3;hrz_4;hrz_5");
    fprintf(f_vertical, "vrt_id;vrt_qt;vrt_1;vrt_2;vrt_3;vrt_4;vrt_5");
    fprintf(f_diagonal, "dg_id;dg_qt;dg_1;dg_2;dg_3;dg_4;dg_5");
    fprintf(f_cruzeta, "crz_id;crz_qt;crz_1;crz_2;crz_3;crz_4;crz_5");

    // Reseta o valor das variaveis
    memset(horizontal_id, 0, sizeof(long) * 6 * 6 * 6 * 6 * 6 * 2);
    memset(vertical_id, 0, sizeof(long) * 6 * 6 * 6 * 6 * 6 * 2);
    memset(diagonal_id, 0, sizeof(long) * 6 * 6 * 6 * 6 * 6 * 2);
    memset(cruzeta_id, 0, sizeof(long) * 6 * 6 * 6 * 6 * 6 * 2);

    for(int b1 = 0; b1 <= 5; b1++)
    for(int b2 = 0; b2 <= 5; b2++)
    for(int b3 = 0; b3 <= 5; b3++)
    for(int b4 = 0; b4 <= 5; b4++)
    for(int b5 = 0; b5 <= 5; b5++){
        int soma_combinacao = b1 + b2 + b3 + b4 + b5;
        if((soma_combinacao >= 15) && (soma_combinacao <= 18)){
            id_combinacao++;

            horizontal_id[b1][b2][b3][b4][b5][0] = id_combinacao;
            vertical_id[b1][b2][b3][b4][b5][0] = id_combinacao;
            diagonal_id[b1][b2][b3][b4][b5][0] = id_combinacao;
            cruzeta_id[b1][b2][b3][b4][b5][0] = id_combinacao;

            horizontal_id[b1][b2][b3][b4][b5][1] = 0;
            vertical_id[b1][b2][b3][b4][b5][1] = 0;
            diagonal_id[b1][b2][b3][b4][b5][1] = 0;
            cruzeta_id[b1][b2][b3][b4][b5][1] = 0;

            fprintf(f_horizontal, "\n%i;%i;%i;%i;%i;%i;%i", id_combinacao, soma_combinacao, b1, b2, b3, b4, b5);
            fprintf(f_vertical, "\n%i;%i;%i;%i;%i;%i;%i", id_combinacao, soma_combinacao, b1, b2, b3, b4, b5);
            fprintf(f_diagonal, "\n%i;%i;%i;%i;%i;%i;%i", id_combinacao, soma_combinacao, b1, b2, b3, b4, b5);
            fprintf(f_cruzeta, "\n%i;%i;%i;%i;%i;%i;%i", id_combinacao, soma_combinacao, b1, b2, b3, b4, b5);

            if(ferror(f_horizontal) ||
               ferror(f_vertical) ||
               ferror(f_diagonal) ||
               ferror(f_cruzeta)){
                fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_horizontal,"
                                "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
                return false;
            }
        }
    }

    fclose(f_horizontal);
    fclose(f_vertical);
    fclose(f_diagonal);
    fclose(f_cruzeta);

    return true;
}

/**************************************************************************
 *                      QUARTETO
 * ***********************************************************************/
long quarteto_id[5][5][5][5][5][6][2];

bool gerar_quarteto_id(){
    FILE * f_quarteto = fopen("./arquivos_csv/lotofacil_id_quarteto.csv", "w");
    if(!f_quarteto){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_quarteto.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_quarteto, "qrt_id;qrt_qt;qrt_1;qrt_2;qrt_3;qrt_4;qrt_5;qrt_6");

    if(ferror(f_quarteto)){
        fprintf(stderr, "Erro ao gravar cabecalho no arquivo lotofacil_id_quarteto.cpp");
        return false;
    }

    // Reseta o valor das variaveis
    memset(quarteto_id, 0, sizeof(long) * 5 * 5 * 5 * 5 * 5 * 6 * 2);

    for(int b1 = 0; b1 <= 4; b1++)
    for(int b2 = 0; b2 <= 4; b2++)
    for(int b3 = 0; b3 <= 4; b3++)
    for(int b4 = 0; b4 <= 4; b4++)
    for(int b5 = 0; b5 <= 4; b5++)
    for(int b6 = 0; b6 <= 5; b6++) {
        int soma_combinacao = b1 + b2 + b3 + b4 + b5 + b6;
        if((soma_combinacao >= 15) && (soma_combinacao <= 18)){
            id_combinacao++;

            quarteto_id[b1][b2][b3][b4][b5][b6][0] = id_combinacao;
            quarteto_id[b1][b2][b3][b4][b5][b6][1] = 0;

            fprintf(f_quarteto, "\n%i;%i;%i;%i;%i;%i;%i;%i", id_combinacao, soma_combinacao, b1, b2, b3, b4, b5, b6);

            if(ferror(f_quarteto)){
                fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_quarteto,"
                                "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
                return false;
            }
        }
    }

    fclose(f_quarteto);
    return true;
}

/*******************************************************************************
 *                          TRIO
 * ****************************************************************************/
long trio_id[4][4][4][4][4][4][4][5][2];

bool gerar_trio_id(){
    FILE * f_trio = fopen("./arquivos_csv/lotofacil_id_trio.csv", "w");
    if(!f_trio){
        fprintf(stderr, "Erro ao abrir arquivo lotofacil_id_trio.csv pra gravaçao");
        return false;
    }

    int id_combinacao = 0;

    // Grava cabecalho.
    fprintf(f_trio, "tr_id;tr_qt;tr_1;tr_2;tr_3;tr_4;tr_5;tr_6;tr_7;tr_8");

    if(ferror(f_trio)){
        fprintf(stderr, "Erro ao gravar cabecalho no arquivo lotofacil_id_trio.cpp");
        return false;
    }

    // Reseta o valor das variaveis
    memset(trio_id, 0, sizeof(long) * 4 * 4 * 4 * 4 * 4 * 4 * 4 * 5 * 2);

    for(int b1 = 0; b1 <= 3; b1++)
    for(int b2 = 0; b2 <= 3; b2++)
    for(int b3 = 0; b3 <= 3; b3++)
    for(int b4 = 0; b4 <= 3; b4++)
    for(int b5 = 0; b5 <= 3; b5++)
    for(int b6 = 0; b6 <= 3; b6++)
    for(int b7 = 0; b7 <= 3; b7++)
    for(int b8 = 0; b8 <= 4; b8++)
    {
        int soma_combinacao = b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8;
        if((soma_combinacao >= 15) && (soma_combinacao <= 18)){
            id_combinacao++;

            trio_id[b1][b2][b3][b4][b5][b6][b7][b8][0] = id_combinacao;
            trio_id[b1][b2][b3][b4][b5][b6][b7][b8][1] = 0;

            fprintf(f_trio, "\n%i;%i;%i;%i;%i;%i;%i;%i;%i;%i", id_combinacao, soma_combinacao, b1, b2, b3, b4, b5, b6, b7, b8);

            if(ferror(f_trio)){
                fprintf(stderr, "Erro ao gravar em um dos arquivos: lotofacil_id_trio,"
                                "lotofacil_id_vertical, lotofacil_id_diagonal, lotofacil_id_cruzeta");
                return false;
            }
        }
    }

    fclose(f_trio);
    return true;
}

/***********************************************************************************
 *                          COLUNAS B1, B1_15, B1_B8_B15, B1_B4_B8_B12_B15
 * ********************************************************************************/
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
    memset(b1_b4_b8_b12_b15_id, 0, sizeof(long) * 12 * 26 * 26 * 26 * 26 * 6);

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
    memset(b1_b8_b15_id, 0, sizeof(long) * 12 * 26 * 26 * 6);

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
    memset(b1_b15_id, 0, sizeof(long) * 12 * 26 * 6);

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
    memset(b1_id, 0, sizeof(long) * 12 * 6);

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

/********************************************************************************
 *                  GERADOR LOTOFACIL
 * ******************************************************************************/
bool gerar_arquivo_id(){
    if(!gerar_par_impar_id()){
        fprintf(stderr, "Erro ao gerar arquivo para combinacao par x impar.\n");
        return false;
    }

    if(!gerar_primo_nao_primo_id()){
        fprintf(stderr, "Erro ao gerar arquivo para combinacao primo x nao_primo.\n");
        return false;
    }

    if(!gerar_externo_interno_id()){
        fprintf(stderr, "Erro ao gerar arquivo para combinacao externo x interno.\n");
        return false;
    }

    if(!gerar_combinacao_com_5_bolas()){
        fprintf(stderr, "Erro ao gerar arquivo com 5 combinaçoes.\n");
        return false;
    }

    if(!gerar_quarteto_id()){
        fprintf(stderr, "Erro ao gerar arquivo lotofacil_id_quarteto.csv");
        return false;
    }

    if(!gerar_trio_id()){
        fprintf(stderr, "Erro ao gerar arquivo lotofacil_id_trio.csv");
        return false;
    }

    if(!gerar_coluna_b()){
        fprintf(stderr, "Erro ao gerar arquivo lotofacil_id_trio.csv");
        return false;
    }

    return true;
}

/**
    Gera os arquivos csv:
    lotofacil_num.csv,
    lotofacil_bolas.csv e
    lotofacil_num_bolas.csv

    Iremos alterar a logica do identificador de combinaçao 'ltf_id',
    ele vai gerar o id primeiro pra todas as combinaçoes com 15 numeros,
    depois, pra 16, ate chegar a 18 numeros.
*/

/**
    Funçao principal, que chama as demais funcoes.
**/
inline bool gerar_lotofacil_num(long ltf_id, long ltf_qt, const long *const lotofacil_num, FILE *f_lotofacil_num);
inline bool gerar_lotofacil_bolas(long ltf_id, long ltf_qt, const long *const lotofacil_bolas, FILE *f_lotofacil_bolas);
inline bool gerar_lotofacil_id(long ltf_id, long ltf_qt, long * lotofacil_num, long * lotofacil_bolas, FILE *f_arquivo_id);

bool gerador_lotofacil(){
    if(!gerar_arquivo_id()){
        return false;
    }

    const int LOTOFACIL_ULTIMA_BOLA = 25;

    // Iremos usar 25 numeros, de 1 a 25.
    // Indice em C, sao baseado em zero, entao e necessario colocar 26.
    long lotofacil_num[26];

    // Iremos usar indice de 1 a 18.
    long lotofacil_bolas[19];

    // Zera o conteudo dos arranjos.
    memset(lotofacil_num, 0, 26 * sizeof(long));
    memset(lotofacil_bolas, 0, 19 * sizeof(long));

    // Inicia os arquivos que armazenarao os dados.
    FILE *f_lotofacil_num = fopen("./arquivos_csv/lotofacil_num.csv", "w");
    FILE *f_lotofacil_bolas = fopen("./arquivos_csv/lotofacil_bolas.csv", "w");
    FILE *f_lotofacil_num_bolas = fopen("./arquivos_csv/lotofacil_num_bolas.csv", "w");
    FILE *f_lotofacil_id = fopen("./arquivos_csv/lotofacil_id.csv", "w");

    if(ferror(f_lotofacil_num)){
        fprintf(stderr, "Erro ao abrir 'arquivo_lotofacil_num.csv pra gravacao");
        return false;
    }
    if(ferror(f_lotofacil_bolas)){
        fprintf(stderr, "Erro ao abrir 'arquivo_lotofacil_bolas.csv pra gravacao");
        return false;
    }
    if(ferror(f_lotofacil_num_bolas)){
        fprintf(stderr, "Erro ao abrir 'arquivo_lotofacil_num_bolas.csv pra gravacao");
        return false;
    }
    if(ferror(f_lotofacil_id)){
        fprintf(stderr, "Erro ao abrir 'arquivo_lotofacil_id.csv pra gravacao");
        return false;
    }

    // Gera os cabecalhos dos arquivos.
    fprintf(f_lotofacil_num, "ltf_id;ltf_qt");
    for(int uA = 1; uA <= 25; uA++){
        fprintf(f_lotofacil_num, ";num_%i", uA);
        if(ferror(f_lotofacil_num)){
            fprintf(stderr, "Erro ao gravar cabecalho do arquivo: lotofacil_num.csv");
            return false;
        }
    }

    fprintf(f_lotofacil_bolas, "ltf_id;ltf_qt");
    for(int uA = 1; uA <= 18; uA++){
        fprintf(f_lotofacil_bolas, ";b_%i", uA);
        if(ferror(f_lotofacil_bolas)){
            fprintf(stderr, "Erro ao gravar cabecalho do arquivo: lotofacil_bolas");
            return false;
        }
    }

    fprintf(f_lotofacil_id, "ltf_id;ltf_qt;par_impar_id;ext_int_id;prm_id;"
                            "hrz_id;vrt_id;dg_id;crz_id;qrt_id;trio_id;"
                            "b1_id;b1_b15_id;b1_b8_b15_id;b1_b4_b8_b12_b15");

    // Identificador pra cada combinaçao valida da lotofacil.
    long ltf_id = 0;
    long ltf_qt = 15;

    for(int b1 = 1     ; b1 <= LOTOFACIL_ULTIMA_BOLA; b1++)
    for(int b2 = b1 + 1; b2 <= LOTOFACIL_ULTIMA_BOLA; b2++)
    for(int b3 = b2 + 1; b3 <= LOTOFACIL_ULTIMA_BOLA; b3++)
    for(int b4 = b3 + 1; b4 <= LOTOFACIL_ULTIMA_BOLA; b4++)
    for(int b5 = b4 + 1; b5 <= LOTOFACIL_ULTIMA_BOLA; b5++)
    for(int b6 = b5 + 1; b6 <= LOTOFACIL_ULTIMA_BOLA; b6++)
    for(int b7 = b6 + 1; b7 <= LOTOFACIL_ULTIMA_BOLA; b7++)
    for(int b8 = b7 + 1; b8 <= LOTOFACIL_ULTIMA_BOLA; b8++)
    for(int b9 = b8 + 1; b9 <= LOTOFACIL_ULTIMA_BOLA; b9++)
    for(int b10 = b9 + 1; b10 <= LOTOFACIL_ULTIMA_BOLA; b10++)
    for(int b11 = b10 + 1; b11 <= LOTOFACIL_ULTIMA_BOLA; b11++)
    for(int b12 = b11 + 1; b12 <= LOTOFACIL_ULTIMA_BOLA; b12++)
    for(int b13 = b12 + 1; b13 <= LOTOFACIL_ULTIMA_BOLA; b13++)
    for(int b14 = b13 + 1; b14 <= LOTOFACIL_ULTIMA_BOLA; b14++)
    for(int b15 = b14 + 1; b15 <= LOTOFACIL_ULTIMA_BOLA; b15++)
    {
        ltf_id++;
        lotofacil_num[b1] = 1; lotofacil_num[b2] = 1; lotofacil_num[b3] = 1; lotofacil_num[b4] = 1;
        lotofacil_num[b5] = 1; lotofacil_num[b6] = 1; lotofacil_num[b7] = 1; lotofacil_num[b8] = 1;
        lotofacil_num[b9] = 1; lotofacil_num[b10] = 1; lotofacil_num[b11] = 1; lotofacil_num[b12] = 1;
        lotofacil_num[b13] = 1; lotofacil_num[b14] = 1; lotofacil_num[b15] = 1;

        lotofacil_bolas[1] = b1; lotofacil_bolas[2] = b2; lotofacil_bolas[3] = b3; lotofacil_bolas[4] = b4;
        lotofacil_bolas[5] = b5; lotofacil_bolas[6] = b6; lotofacil_bolas[7] = b7; lotofacil_bolas[8] = b8;
        lotofacil_bolas[9] = b9; lotofacil_bolas[10] = b10; lotofacil_bolas[11] = b11; lotofacil_bolas[12] = b12;
        lotofacil_bolas[13] = b13; lotofacil_bolas[14] = b14; lotofacil_bolas[15] = b15;

        gerar_lotofacil_num(ltf_id, ltf_qt, lotofacil_num, f_lotofacil_num);
        gerar_lotofacil_bolas(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_bolas);
        gerar_lotofacil_id(ltf_id, ltf_qt, lotofacil_num, lotofacil_bolas, f_lotofacil_id);

        lotofacil_num[b1] = 0; lotofacil_num[b2] = 0; lotofacil_num[b3] = 0; lotofacil_num[b4] = 0;
        lotofacil_num[b5] = 0; lotofacil_num[b6] = 0; lotofacil_num[b7] = 0; lotofacil_num[b8] = 0;
        lotofacil_num[b9] = 0; lotofacil_num[b10] = 0; lotofacil_num[b11] = 0; lotofacil_num[b12] = 0;
        lotofacil_num[b13] = 0; lotofacil_num[b14] = 0; lotofacil_num[b15] = 0;

        if(ltf_id == 50000){
                goto sair;
        }
    }

sair:
    // Fecha os arquivos
    fclose(f_lotofacil_num);
    fclose(f_lotofacil_bolas);
    fclose(f_lotofacil_id);

    return true;
}

/**
    Gera dados pra o arquivo lotofacil_num.csv
    Retorna true, se gravado com sucesso.
**/
inline bool gerar_lotofacil_num(long ltf_id, long ltf_qt, const long *const lotofacil_num, FILE *f_lotofacil_num){
    fprintf(f_lotofacil_num,
                "\n%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;"
                "%li;%li;%li;%li;%li;%li;%li;",
                ltf_id, ltf_qt,
                lotofacil_num[1], lotofacil_num[2 ], lotofacil_num[3 ], lotofacil_num[4 ],
                lotofacil_num[5], lotofacil_num[6 ], lotofacil_num[7 ], lotofacil_num[8 ],
                lotofacil_num[9], lotofacil_num[10], lotofacil_num[11], lotofacil_num[12],
                lotofacil_num[13],lotofacil_num[14], lotofacil_num[15], lotofacil_num[16],
                lotofacil_num[17],lotofacil_num[18], lotofacil_num[19], lotofacil_num[20],
                lotofacil_num[21],lotofacil_num[22], lotofacil_num[23], lotofacil_num[24],
                lotofacil_num[25]
                );
    if(ferror(f_lotofacil_num))
        return false;
    else
        return true;
}

/**
    Gera os dados no arquivo lotofacil_bolas.csv
**/
inline bool gerar_lotofacil_bolas(long ltf_id, long ltf_qt, const long *const lotofacil_bolas, FILE *f_lotofacil_bolas){
    fprintf(f_lotofacil_bolas, "\n%li;%li", ltf_id, ltf_qt);
    fprintf(f_lotofacil_bolas, ";%li", lotofacil_bolas[1]);
    for(int uA = 2; uA <= ltf_qt; uA++){
        fprintf(f_lotofacil_bolas, ";%li", lotofacil_bolas[uA]);
    }

    if(ltf_qt==15)
        fprintf(f_lotofacil_bolas, ";;;");
    else if(ltf_qt == 16)
        fprintf(f_lotofacil_bolas, ";;");
    else if(ltf_qt == 17)
        fprintf(f_lotofacil_bolas, ";");

    if(ferror(f_lotofacil_bolas))
        return false;
    else
        return true;
}

inline bool gerar_lotofacil_id(long ltf_id, long ltf_qt, long * lotofacil_num, long * lotofacil_bolas, FILE *f_arquivo_id)
{
    // Colunas b
    long b1  = lotofacil_bolas[1];
    long b4  = lotofacil_bolas[4];
    long b8  = lotofacil_bolas[8];
    long b12 = lotofacil_bolas[12];
    long b15 = lotofacil_bolas[15];

    // Contabiliza números par e ímpar.
    long qt_par = lotofacil_num[2] +  lotofacil_num[4] +  lotofacil_num[6] +
            lotofacil_num[8] +  lotofacil_num[10] + lotofacil_num[12] +
            lotofacil_num[14] + lotofacil_num[16] + lotofacil_num[18] +
            lotofacil_num[20] + lotofacil_num[22] + lotofacil_num[24];

    long qt_impar = lotofacil_num[1] + lotofacil_num[3] + lotofacil_num[5] +
              lotofacil_num[7] + lotofacil_num[9] +
              lotofacil_num[11] + lotofacil_num[13] + lotofacil_num[15] +
              lotofacil_num[17] + lotofacil_num[19] + lotofacil_num[21] +
              lotofacil_num[23] + lotofacil_num[25];

    // Contabiliza externo e interno
    long qt_externo = lotofacil_num[1]  + lotofacil_num[2]  + lotofacil_num[3]  +
               lotofacil_num[4]  + lotofacil_num[5]  + lotofacil_num[6]  +
               lotofacil_num[10] + lotofacil_num[11] + lotofacil_num[15] +
               lotofacil_num[16] + lotofacil_num[20] + lotofacil_num[21] +
               lotofacil_num[22] + lotofacil_num[23] + lotofacil_num[24] +
               lotofacil_num[25];

    // Internos, verificado.
    long qt_interno = lotofacil_num[7]  + lotofacil_num[8]  + lotofacil_num[9]  +
                  lotofacil_num[12] + lotofacil_num[13] + lotofacil_num[14] +
                  lotofacil_num[17] + lotofacil_num[18] + lotofacil_num[19];

    // Contabiliza números primos e não primos.
    long qt_primo =    lotofacil_num[2]  + lotofacil_num[3]  + lotofacil_num[5] +
                 lotofacil_num[7]  + lotofacil_num[11] + lotofacil_num[13] +
                 lotofacil_num[17] + lotofacil_num[19] + lotofacil_num[23];

    // Números não primos.
    long qt_nao_primo = lotofacil_num[1] + lotofacil_num[4] + lotofacil_num[6] +
                 lotofacil_num[8] + lotofacil_num[9] + lotofacil_num[10] +
                 lotofacil_num[12] + lotofacil_num[14] + lotofacil_num[15] +
                 lotofacil_num[16] + lotofacil_num[18] + lotofacil_num[20] +
                 lotofacil_num[21] + lotofacil_num[22] + lotofacil_num[24] +
                 lotofacil_num[25];


    /// Trio: São grupos de 3 bolas, geralmente, duas destas bolas, estão em sequência.
    long qt_trio_1 = lotofacil_num[1] + lotofacil_num[2] + lotofacil_num[6];
    long qt_trio_2 = lotofacil_num[3] + lotofacil_num[7] + lotofacil_num[8];
    long qt_trio_3 = lotofacil_num[4] + lotofacil_num[5] + lotofacil_num[10];
    long qt_trio_4 = lotofacil_num[9] + lotofacil_num[14] + lotofacil_num[15];
    long qt_trio_5 = lotofacil_num[19] + lotofacil_num[20] + lotofacil_num[25];
    long qt_trio_6 = lotofacil_num[18] + lotofacil_num[23] + lotofacil_num[24];
    long qt_trio_7 = lotofacil_num[12] + lotofacil_num[13] + lotofacil_num[17];
    long qt_trio_8 = lotofacil_num[11] + lotofacil_num[16] + lotofacil_num[21] + lotofacil_num[22];

    // Horizontal.
    long qt_hrz_1 = lotofacil_num[1] + lotofacil_num[2] + lotofacil_num[3] + lotofacil_num[4] + lotofacil_num[5];
    long qt_hrz_2 = lotofacil_num[6] + lotofacil_num[7] + lotofacil_num[8] + lotofacil_num[9] + lotofacil_num[10];
    long qt_hrz_3 = lotofacil_num[11] + lotofacil_num[12] + lotofacil_num[13] + lotofacil_num[14] + lotofacil_num[15];
    long qt_hrz_4 = lotofacil_num[16] + lotofacil_num[17] + lotofacil_num[18] + lotofacil_num[19] + lotofacil_num[20];
    long qt_hrz_5 = lotofacil_num[21] + lotofacil_num[22] + lotofacil_num[23] + lotofacil_num[24] + lotofacil_num[25];

    // Vertical.
    long qt_vrt_1 = lotofacil_num[1] + lotofacil_num[6] + lotofacil_num[11] + lotofacil_num[16] + lotofacil_num[21];
    long qt_vrt_2 = lotofacil_num[2] + lotofacil_num[7] + lotofacil_num[12] + lotofacil_num[17] + lotofacil_num[22];
    long qt_vrt_3 = lotofacil_num[3] + lotofacil_num[8] + lotofacil_num[13] + lotofacil_num[18] + lotofacil_num[23];
    long qt_vrt_4 = lotofacil_num[4] + lotofacil_num[9] + lotofacil_num[14] + lotofacil_num[19] + lotofacil_num[24];
    long qt_vrt_5 = lotofacil_num[5] + lotofacil_num[10] + lotofacil_num[15] + lotofacil_num[20] + lotofacil_num[25];

    // Diagonal.
    long qt_dg_1 = lotofacil_num[1] + lotofacil_num[7] + lotofacil_num[13] + lotofacil_num[19] + lotofacil_num[25];
    long qt_dg_2 = lotofacil_num[2] + lotofacil_num[8] + lotofacil_num[14] + lotofacil_num[20] + lotofacil_num[21];
    long qt_dg_3 = lotofacil_num[3] + lotofacil_num[9] + lotofacil_num[15] + lotofacil_num[16] + lotofacil_num[22];
    long qt_dg_4 = lotofacil_num[4] + lotofacil_num[10] + lotofacil_num[11] + lotofacil_num[17] + lotofacil_num[23];
    long qt_dg_5 = lotofacil_num[5] + lotofacil_num[6] + lotofacil_num[12] + lotofacil_num[18] + lotofacil_num[24];

    // Cruzeta.
    long qt_crz_1 = lotofacil_num[1] + lotofacil_num[2] + lotofacil_num[6] + lotofacil_num[7] + lotofacil_num[11];
    long qt_crz_2 = lotofacil_num[4] + lotofacil_num[5] + lotofacil_num[9] + lotofacil_num[10] + lotofacil_num[15];
    long qt_crz_3 = lotofacil_num[3] + lotofacil_num[8] + lotofacil_num[13] + lotofacil_num[18] + lotofacil_num[23];
    long qt_crz_4 = lotofacil_num[12] + lotofacil_num[16] + lotofacil_num[17] + lotofacil_num[21] + lotofacil_num[22];
    long qt_crz_5 = lotofacil_num[14] + lotofacil_num[19] + lotofacil_num[20] + lotofacil_num[24] + lotofacil_num[25];

    // Quarteto.
    long qt_qrt_1 = lotofacil_num[1] + lotofacil_num[20] + lotofacil_num[24] + lotofacil_num[7];
    long qt_qrt_2 = lotofacil_num[16] + lotofacil_num[5] + lotofacil_num[9] + lotofacil_num[22];
    long qt_qrt_3 = lotofacil_num[2] + lotofacil_num[6] + lotofacil_num[19] + lotofacil_num[25];
    long qt_qrt_4 = lotofacil_num[4] + lotofacil_num[17] + lotofacil_num[10] + lotofacil_num[21];
    long qt_qrt_5 = lotofacil_num[8] + lotofacil_num[11] + lotofacil_num[15] + lotofacil_num[18];
    long qt_qrt_6 = lotofacil_num[3] + lotofacil_num[12] + lotofacil_num[13] + lotofacil_num[14] +
            lotofacil_num[23];

    // Agora pega os identificadores.
    ///long id_par_impar = par_impar_id[qt_par][ qt_impar][ 0];



    long id_par_impar = par_impar_id[qt_par][ qt_impar][ 0];
    printf("par: %li, impar: %li, %li", qt_par, qt_impar, par_impar_id[qt_par][ qt_impar][ 0]);

    long id_externo_interno = externo_interno_id[qt_externo][ qt_interno][ 0];
    long id_primo_nao_primo = primo_nao_primo_id[qt_primo][ qt_nao_primo][ 0];
    long id_horizontal = horizontal_id[qt_hrz_1][ qt_hrz_2][ qt_hrz_3][ qt_hrz_4][ qt_hrz_5][ 0];
    long id_vertical = vertical_id[qt_vrt_1][ qt_vrt_2][ qt_vrt_3][ qt_vrt_4][ qt_vrt_5][ 0];
    long id_diagonal = diagonal_id[qt_dg_1][ qt_dg_2][ qt_dg_3][ qt_dg_4][ qt_dg_5][ 0];
    long id_cruzeta = cruzeta_id[qt_crz_1][ qt_crz_2][ qt_crz_3][ qt_crz_4][ qt_crz_5][ 0];
    long id_quarteto = quarteto_id[qt_qrt_1][ qt_qrt_2][ qt_qrt_3][ qt_qrt_4][ qt_qrt_5][ qt_qrt_6][ 0];
    long id_trio = trio_id[qt_trio_1][ qt_trio_2][ qt_trio_3][ qt_trio_4][ qt_trio_5][qt_trio_6][ qt_trio_7][ qt_trio_8][  0];


    // Identificadores para colunas b1.
    long id_b1 = b1_id[b1][0];
    long id_b1_b15 = b1_b15_id[b1][b15][0];
    long id_b1_b8_b15 = b1_b8_b15_id[b1][b8][b15][ 0];
    long id_b1_b4_b8_b12_b15 = b1_b4_b8_b12_b15_id[b1][ b4][ b8][ b12][ b15][ 0];

    fprintf(f_arquivo_id, "\n%li;%li", ltf_id, ltf_qt);
    fprintf(f_arquivo_id, ";%li;%li;%li", id_par_impar, id_externo_interno, id_primo_nao_primo);
    fprintf(f_arquivo_id, ";%li;%li;%li", id_horizontal, id_vertical, id_diagonal);
    fprintf(f_arquivo_id, ";%li;%li;%li", id_cruzeta, id_quarteto, id_trio);
    fprintf(f_arquivo_id, ";%li;%li;%li;%li", id_b1, id_b1_b15, id_b1_b8_b15, id_b1_b4_b8_b12_b15);

    // Agora, iremos contabilizar a quantidade de combinacoes, pra posteriormente, gravarmos.
    par_impar_id[qt_par][ qt_impar][ 1] += 1;
    externo_interno_id[qt_externo][ qt_interno][1] += 1;
    primo_nao_primo_id[qt_primo][ qt_nao_primo][1] += 1;
    horizontal_id[qt_hrz_1][qt_hrz_2][qt_hrz_3][qt_hrz_4][qt_hrz_5][1] += 1;
    vertical_id[qt_vrt_1][qt_vrt_2][qt_vrt_3][qt_vrt_4][ qt_vrt_5][1] += 1;
    diagonal_id[qt_dg_1][qt_dg_2][qt_dg_3][qt_dg_4][qt_dg_5][1] += 1;
    cruzeta_id[qt_crz_1][qt_crz_2][qt_crz_3][qt_crz_4][qt_crz_5][1] += 1;
    quarteto_id[qt_qrt_1][qt_qrt_2][qt_qrt_3][qt_qrt_4][qt_qrt_5][qt_qrt_6][1] += 1;
    trio_id[qt_trio_1][qt_trio_2][qt_trio_3][qt_trio_4][qt_trio_5][qt_trio_6][qt_trio_7][qt_trio_8][1] += 1;


    long indice_bola = ltf_qt - 14;
    if((indice_bola < 1) || (indice_bola > 4))
    {
        fprintf(stderr, "Erro, funcao gerar_lotofacil_id, ltf_qt invalido");
        return false;
    }

    b1_id[b1][indice_bola] += 1;
    b1_id[b1][5] += 1;

    b1_b15_id[b1][b15][indice_bola] += 1;
    b1_b15_id[b1][b15][5] += 1;

    b1_b8_b15_id[b1][b8][b15][indice_bola] += 1;
    b1_b8_b15_id[b1][b8][b15][5] += 1;

    b1_b4_b8_b12_b15_id[b1][b4][b8][b12][b15][indice_bola] += 1;
    b1_b4_b8_b12_b15_id[b1][b4][b8][b12][b15][5] += 1;

    return true;
}

/********************************************************
 *                  Início do programa
 * *****************************************************/
int bbmain()
{
    // Cria a pasta se não existe.
    struct stat diretorio;
    if(stat("./arquivos_csv", &diretorio) == -1){
        if(!mkdir("arquivos_csv", 0770)){
            fprintf(stderr, "Nao foi possivel criar o diretorio arquivos_csv\n");
            return - 1;
        }
    }

    if(!gerador_lotofacil()){
        fprintf(stderr, "Erro ao gerar arquivo");
        return -1;
    }

    cout << "Arquivos gerados com sucesso!!!" << endl;
    return 0;
}



