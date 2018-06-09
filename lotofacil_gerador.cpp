/**
  Programa:     ltk_gerador_de_dados_lotofacil
  Autor:        Fábio Moura de Oliveira
  Arquivo:      lotofacil_gerador.cpp
  Descrição:    Este arquivo percorre todas as combinações possíveis da lotofacil
                e chama as funções que geram os dados estatísticos.
                A 'gerador_lotofacil()' gera um identificador um identificador unico
                e exclusivo pra cada combinacao da lotofacil e armazena tais combinacoes
                com o identificador em um arquivo *.csv.
**/


#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#include "lotofacil_giro.hpp"
#include "lotofacil_gerador.hpp"
#include "lotofacil_id_par_impar.h"
#include "lotofacil_id_primo_nao_primo.h"
#include "lotofacil_id_externo_interno.h"
#include "lotofacil_id_hrz_vrt_dg_crz.h"
#include "lotofacil_id_quarteto.h"
#include "lotofacil_id_trio.h"
#include "lotofacil_id_coluna_b.h"
#include "lotofacil_soma.hpp"
#include "lotofacil_hash.hpp"
#include "lotofacil_deslocamento.hpp"
#include "lotofacil_grupo.hpp"
#include "lotofacil_algarismo_na_dezena.hpp"


using namespace std;

/**
 * @brief gerar_arquivo_id
 * @return
 * Gera os arquivos:
 *  lotofacil_id_par_impar.csv
 *  lotofacil_id_primo_nao_primo.csv
 *  lotofacil_id_externo.csv
 *  lotofacil_id_horizontal.csv
 *  lotofacil_id_vertical.csv
 *  lotofacil_id_diagonal.csv
 *  lotofacil_id_cruzeta.csv
 *  lotofacil_id_quarteto.csv
 *  lotofacil_id_trio.csv
 *
 */
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

    if(!gerar_grupo_id()){
        fprintf(stderr, "Erro ao gerar arquivo de grupos.");
        return false;
    }

    if(!gerar_algarismo_na_dezena_id()){
        fprintf(stderr, "Erro ao gerar arquivo 'algarismo_na_dezena_id.csv'");
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
    FILE *f_lotofacil_num_bolas_binario = fopen("./arquivos_csv/lotofacil_num_bolas.ltf_bin", "wb");
    FILE *f_lotofacil_id = fopen("./arquivos_csv/lotofacil_id.csv", "w");
    FILE *f_lotofacil_diferenca = fopen("./arquivos_csv/lotofacil_diferenca_entre_bolas.csv", "w");
    FILE *f_lotofacil_soma = fopen("./arquivos_csv/lotofacil_soma.csv", "w");
    FILE *f_lotofacil_hash = fopen("./arquivos_csv/lotofacil_hash.csv", "w");
    FILE *f_lotofacil_giro = fopen("./arquivos_csv/lotofacil_giro.csv", "w");
    FILE *f_lotofacil_algarismo_na_dezena = fopen("./arquivos_csv/lotofacil_algarismo_na_dezena.csv", "w");
    FILE *f_lotofacil_coluna_b = fopen("./arquivos_csv/lotofacil_coluna_b.csv", "w");

    /*
    FILE *f_lotofacil_grupo_2_bolas = fopen("./arquivos_csv/lotofacil_grupo_2_bolas.csv", "w");
    FILE *f_lotofacil_grupo_3_bolas = fopen("./arquivos_csv/lotofacil_grupo_3_bolas.csv", "w");
        FILE *f_lotofacil_grupo_4_bolas = fopen("./arquivos_csv/lotofacil_grupo_4_bolas.csv", "w");
        FILE *f_lotofacil_grupo_5_bolas = fopen("./arquivos_csv/lotofacil_grupo_5_bolas.csv", "w");
        FILE *f_lotofacil_grupo_6_bolas = fopen("./arquivos_csv/lotofacil_grupo_6_bolas.csv", "w");
        FILE *f_lotofacil_grupo_7_bolas = fopen("./arquivos_csv/lotofacil_grupo_7_bolas.csv", "w");
        FILE *f_lotofacil_grupo_8_bolas = fopen("./arquivos_csv/lotofacil_grupo_8_bolas.csv", "w");
        FILE *f_lotofacil_grupo_9_bolas = fopen("./arquivos_csv/lotofacil_grupo_9_bolas.csv", "w");
        FILE *f_lotofacil_grupo_10_bolas = fopen("./arquivos_csv/lotofacil_grupo_10_bolas.csv", "w");
    */

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
    if(ferror(f_lotofacil_num_bolas_binario)){
        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_num_bolas_binario.ltfbin' pra gravação");
        return false;
    }
    if(ferror(f_lotofacil_id)){
        fprintf(stderr, "Erro ao abrir 'arquivo_lotofacil_id.csv pra gravacao");
        return false;
    }
    if(ferror(f_lotofacil_diferenca)){
        fprintf(stderr, "Erro ao abrir 'arquivo_diferenca_entre_bolas.csv pra gravacao");
        return false;
    }
    if(ferror(f_lotofacil_soma)){
        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_soma.csv' pra gravação");
        return false;
    }
    if(ferror(f_lotofacil_hash)){
        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_hash.csv' pra gravação.");
        return false;
    }
    if(ferror(f_lotofacil_giro)){
        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_giro.csv' pra gravaçaõ.");
        return false;
    }

//    if(ferror(f_lotofacil_grupo_2_bolas)){
//        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_grupo_2_bolas.csv', pra gravação.");
//        return false;
//    }
//    if(ferror(f_lotofacil_grupo_3_bolas)){
//        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_grupo_3_bolas.csv', pra gravação.");
//        return false;
//    }
    /*
    if(ferror(f_lotofacil_grupo_4_bolas)){
        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_grupo_4_bolas.csv', pra gravação.");
        return false;
    }
    if(ferror(f_lotofacil_grupo_5_bolas)){
        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_grupo_5_bolas.csv', pra gravação.");
        return false;
    }
    */
    /*
    if(ferror(f_lotofacil_grupo_6_bolas)){
        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_grupo_6_bolas.csv', pra gravação.");
        return false;
    }
    if(ferror(f_lotofacil_grupo_7_bolas)){
        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_grupo_7_bolas.csv', pra gravação.");
        return false;
    }
    if(ferror(f_lotofacil_grupo_8_bolas)){
        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_grupo_8_bolas.csv', pra gravação.");
        return false;
    }
    if(ferror(f_lotofacil_grupo_9_bolas)){
        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_grupo_9_bolas.csv', pra gravação.");
        return false;
    }
    if(ferror(f_lotofacil_grupo_10_bolas)){
        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_grupo_10_bolas.csv', pra gravação.");
        return false;
    }
    */
    if(ferror(f_lotofacil_algarismo_na_dezena)){
        fprintf(stderr, "Erro ao abrir o arquivo 'lotofacil_algarismo_na_dezena.csv', pra gravação");
        return false;
    }

    if(ferror(f_lotofacil_coluna_b)){
        fprintf(stderr, "Erro ao abrir arquivo 'lotofacil_coluna_b.csv', pra gravação.");
        return false;
    }


    // Gera os cabecalhos dos arquivos.
    // Arquivo: lotofacil_num.csv
    fprintf(f_lotofacil_num, "ltf_id;ltf_qt");
    for(int uA = 1; uA <= 25; uA++){
        fprintf(f_lotofacil_num, ";num_%i", uA);
        if(ferror(f_lotofacil_num)){
            fprintf(stderr, "Erro ao gravar cabecalho do arquivo: lotofacil_num.csv");
            return false;
        }
    }

    // Arquivo: lotofacil_bolas.csv
    fprintf(f_lotofacil_bolas, "ltf_id;ltf_qt");
    for(int uA = 1; uA <= 18; uA++){
        fprintf(f_lotofacil_bolas, ";b_%i", uA);
        if(ferror(f_lotofacil_bolas)){
            fprintf(stderr, "Erro ao gravar cabecalho do arquivo: lotofacil_bolas.csv");
            return false;
        }
    }

    // Arquivo: lotofacil_num_bolas.csv
    fprintf(f_lotofacil_num_bolas, "ltf_seq;ltf_id;ltf_qt;bola");
    if(ferror(f_lotofacil_num_bolas)){
        fprintf(stderr, "Erro ao gravar cabeçalho do arquivo: lotofacil_num_bolas.csv");
        return false;
    }

    // Arquivo: lotofacil_id.csv
    fprintf(f_lotofacil_id, "ltf_id;ltf_qt;par_impar_id;ext_int_id;prm_id;"
                            "hrz_id;vrt_id;dg_id;crz_id;qrt_id;trio_id;"
                            "b1_id;b1_b2_id;b1_b2_b3_id;b1_b2_b3_b4_id;b1_b2_b3_b4_b5_id;"
                            "b1_b15_id;b1_b8_b15_id;b1_b4_b8_b12_b15;dz_id");

    // Arquivo: lotofacil_diferenca_entre_bolas.csv
    fprintf(f_lotofacil_diferenca, "ltf_id;ltf_qt");
    for(int uA = 1; uA <= 18; uA++){
        fprintf(f_lotofacil_diferenca, ";df_%i", uA);
    }
    fprintf(f_lotofacil_diferenca, ";qt_dif_1;qt_dif_2;qt_dif_3;qt_dif_4;qt_dif_5;qt_dif_6;qt_dif_7;qt_dif_8;qt_dif_9;qt_dif_10;qt_dif_11");
    fprintf(f_lotofacil_diferenca, ";qt_alt");

    // Arquivo: lotofacil_soma.csv
    fprintf(f_lotofacil_soma, "ltf_id;ltf_qt;bola_soma");

    // Arquivo: lotofacil_hash.csv
    fprintf(f_lotofacil_hash, "ltf_id;ltf_qt;ltf_hash");

    // Arquivo: lotofacil_giro.csv
    fprintf(f_lotofacil_giro, "ltf_id;ltf_qt;giro_tipo;ltf_id_giro;qt_bolas_em_comum");

    // Arquivo: lotofacil_coluna_b.csv
    fprintf(f_lotofacil_coluna_b, "ltf_b;ltf_qt");

    for(long uA = 1; uA <= 15; uA++)
    {
        for(long uB = uA; uB <= 15; uB++)
        {
            fprintf(f_lotofacil_coluna_b, ";b%li_a_b%li_id", uA, uB);
        }
    }

    // Arquivo: lotofacil_grupo
//    fprintf(f_lotofacil_grupo_2_bolas, "ltf_id;ltf_qt;grp_id");
//    fprintf(f_lotofacil_grupo_3_bolas, "ltf_id;ltf_qt;grp_id");
    /*
    fprintf(f_lotofacil_grupo_4_bolas, "ltf_id;ltf_qt;grp_id");
    fprintf(f_lotofacil_grupo_5_bolas, "ltf_id;ltf_qt;grp_id");
    */
    /*
    fprintf(f_lotofacil_grupo_6_bolas, "ltf_id;ltf_qt;grp_id");
    fprintf(f_lotofacil_grupo_7_bolas, "ltf_id;ltf_qt;grp_id");
    fprintf(f_lotofacil_grupo_8_bolas, "ltf_id;ltf_qt;grp_id");
    fprintf(f_lotofacil_grupo_9_bolas, "ltf_id;ltf_qt;grp_id");
    fprintf(f_lotofacil_grupo_10_bolas, "ltf_id;ltf_qt;grp_id");
    */

    // Isto será usado pra ser passado para uma função.
    FILE * f_lotofacil_grupo[4] = {
        0, 0,
//        f_lotofacil_grupo_2_bolas,
//        f_lotofacil_grupo_3_bolas,
        /*
        f_lotofacil_grupo_4_bolas,
        f_lotofacil_grupo_5_bolas
        f_lotofacil_grupo_6_bolas,
        f_lotofacil_grupo_7_bolas,
        f_lotofacil_grupo_8_bolas,
        f_lotofacil_grupo_9_bolas,
        f_lotofacil_grupo_10_bolas
            */
    };

    fprintf(f_lotofacil_algarismo_na_dezena, "ltf_id;ltf_qt;id_dz");

    // Identificador pra cada combinaçao valida da lotofacil.
    long ltf_id = 0;
    long ltf_qt = 15;
    long ltf_id_gerado = 0;

    // Usado no arquivo lotofacil_num_bolas.csv, pois, iremos ter um registro
    // pra cada bola de uma única combinação.
    long long ltf_seq = 0;

    printf("Gerando combinações de 15 bolas...Aguarde...\n");
    for(int b1 = 1; b1 <= LOTOFACIL_ULTIMA_BOLA; b1++)
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
        ltf_id_gerado = obter_deslocamento_15_bolas(b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15);
        if(ltf_id != ltf_id_gerado)
        {
            printf("ltf_id = %li, ltf_id_gerado: %li\n", ltf_id, ltf_id_gerado);
            fprintf(stderr, "Erro ao gerar ltf_id");
            return 0;
        }

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
        gerar_lotofacil_num_bolas(ltf_id, ltf_qt, ltf_seq, lotofacil_bolas, f_lotofacil_num_bolas);
        gerar_lotofacil_bolas_novos_repetidos_binario(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_num_bolas_binario);
        gerar_lotofacil_diferenca(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_diferenca);
        gerar_lotofacil_soma(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_soma);
        gerar_lotofacil_hash(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_hash);
        gerar_lotofacil_giro(ltf_id, ltf_qt, lotofacil_num, f_lotofacil_giro);
        //gerar_lotofacil_grupo(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_grupo);
        gerar_lotofacil_algarismo_na_dezena(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_algarismo_na_dezena);
        gerar_lotofacil_coluna_b(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_coluna_b);

        lotofacil_num[b1] = 0; lotofacil_num[b2] = 0; lotofacil_num[b3] = 0; lotofacil_num[b4] = 0;
        lotofacil_num[b5] = 0; lotofacil_num[b6] = 0; lotofacil_num[b7] = 0; lotofacil_num[b8] = 0;
        lotofacil_num[b9] = 0; lotofacil_num[b10] = 0; lotofacil_num[b11] = 0; lotofacil_num[b12] = 0;
        lotofacil_num[b13] = 0; lotofacil_num[b14] = 0; lotofacil_num[b15] = 0;


    }    

    ltf_qt = 16;
    printf("Gerando combinações de 16 bolas...Aguarde...\n");    
    for(int b1 = 1; b1 <= LOTOFACIL_ULTIMA_BOLA; b1++)
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
    for(int b16 = b15 + 1; b16 <= LOTOFACIL_ULTIMA_BOLA; b16++)
    {
        ltf_id++;
        ltf_id_gerado = obter_deslocamento_16_bolas(b1, b2, b3, b4, b5,
                                                    b6, b7, b8, b9, b10,
                                                    b11, b12, b13, b14, b15, b16);
        if(ltf_id != ltf_id_gerado)
        {
            printf("ltf_id = %li, ltf_id_gerado: %li\n", ltf_id, ltf_id_gerado);
            fprintf(stderr, "Erro ao gerar ltf_id");
            return 0;
        }

        lotofacil_num[b1] = 1; lotofacil_num[b2] = 1; lotofacil_num[b3] = 1; lotofacil_num[b4] = 1;
        lotofacil_num[b5] = 1; lotofacil_num[b6] = 1; lotofacil_num[b7] = 1; lotofacil_num[b8] = 1;
        lotofacil_num[b9] = 1; lotofacil_num[b10] = 1; lotofacil_num[b11] = 1; lotofacil_num[b12] = 1;
        lotofacil_num[b13] = 1; lotofacil_num[b14] = 1; lotofacil_num[b15] = 1; lotofacil_num[b16] = 1;

        lotofacil_bolas[1] = b1; lotofacil_bolas[2] = b2; lotofacil_bolas[3] = b3; lotofacil_bolas[4] = b4;
        lotofacil_bolas[5] = b5; lotofacil_bolas[6] = b6; lotofacil_bolas[7] = b7; lotofacil_bolas[8] = b8;
        lotofacil_bolas[9] = b9; lotofacil_bolas[10] = b10; lotofacil_bolas[11] = b11; lotofacil_bolas[12] = b12;
        lotofacil_bolas[13] = b13; lotofacil_bolas[14] = b14; lotofacil_bolas[15] = b15; lotofacil_bolas[16] = b16;

        gerar_lotofacil_num(ltf_id, ltf_qt, lotofacil_num, f_lotofacil_num);
        gerar_lotofacil_bolas(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_bolas);
        gerar_lotofacil_id(ltf_id, ltf_qt, lotofacil_num, lotofacil_bolas, f_lotofacil_id);
        gerar_lotofacil_num_bolas(ltf_id, ltf_qt, ltf_seq, lotofacil_bolas, f_lotofacil_num_bolas);
        gerar_lotofacil_bolas_novos_repetidos_binario(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_num_bolas_binario);
        gerar_lotofacil_diferenca(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_diferenca);
        gerar_lotofacil_soma(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_soma);
        gerar_lotofacil_hash(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_hash);
        gerar_lotofacil_giro(ltf_id, ltf_qt, lotofacil_num, f_lotofacil_giro);
        //gerar_lotofacil_grupo(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_grupo);
        gerar_lotofacil_algarismo_na_dezena(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_algarismo_na_dezena);
        gerar_lotofacil_coluna_b(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_coluna_b);

        lotofacil_num[b1] = 0; lotofacil_num[b2] = 0; lotofacil_num[b3] = 0; lotofacil_num[b4] = 0;
        lotofacil_num[b5] = 0; lotofacil_num[b6] = 0; lotofacil_num[b7] = 0; lotofacil_num[b8] = 0;
        lotofacil_num[b9] = 0; lotofacil_num[b10] = 0; lotofacil_num[b11] = 0; lotofacil_num[b12] = 0;
        lotofacil_num[b13] = 0; lotofacil_num[b14] = 0; lotofacil_num[b15] = 0; lotofacil_num[b16] = 0;

    }

    ltf_qt = 17;
    printf("Gerando combinações de 17 bolas...Aguarde...\n");
    for(int b1 = 1; b1 <= LOTOFACIL_ULTIMA_BOLA; b1++)
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
    for(int b16 = b15 + 1; b16 <= LOTOFACIL_ULTIMA_BOLA; b16++)
    for(int b17 = b16 + 1; b17 <= LOTOFACIL_ULTIMA_BOLA; b17++)
    {
        ltf_id++;
        ltf_id_gerado = obter_deslocamento_17_bolas(b1, b2, b3, b4, b5, b6, b7, b8, b9, b10,
                                                    b11, b12, b13, b14, b15, b16, b17);
        if(ltf_id != ltf_id_gerado)
        {
            printf("ltf_id = %li, ltf_id_gerado: %li\n", ltf_id, ltf_id_gerado);
            fprintf(stderr, "Erro ao gerar ltf_id");
            return 0;
        }

        lotofacil_num[b1] = 1; lotofacil_num[b2] = 1; lotofacil_num[b3] = 1; lotofacil_num[b4] = 1;
        lotofacil_num[b5] = 1; lotofacil_num[b6] = 1; lotofacil_num[b7] = 1; lotofacil_num[b8] = 1;
        lotofacil_num[b9] = 1; lotofacil_num[b10] = 1; lotofacil_num[b11] = 1; lotofacil_num[b12] = 1;
        lotofacil_num[b13] = 1; lotofacil_num[b14] = 1; lotofacil_num[b15] = 1; lotofacil_num[b16] = 1;
        lotofacil_num[b17] = 1;

        lotofacil_bolas[1] = b1; lotofacil_bolas[2] = b2; lotofacil_bolas[3] = b3; lotofacil_bolas[4] = b4;
        lotofacil_bolas[5] = b5; lotofacil_bolas[6] = b6; lotofacil_bolas[7] = b7; lotofacil_bolas[8] = b8;
        lotofacil_bolas[9] = b9; lotofacil_bolas[10] = b10; lotofacil_bolas[11] = b11; lotofacil_bolas[12] = b12;
        lotofacil_bolas[13] = b13; lotofacil_bolas[14] = b14; lotofacil_bolas[15] = b15; lotofacil_bolas[16] = b16;
        lotofacil_bolas[17] = b17;

        gerar_lotofacil_num(ltf_id, ltf_qt, lotofacil_num, f_lotofacil_num);
        gerar_lotofacil_bolas(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_bolas);
        gerar_lotofacil_id(ltf_id, ltf_qt, lotofacil_num, lotofacil_bolas, f_lotofacil_id);
        gerar_lotofacil_num_bolas(ltf_id, ltf_qt, ltf_seq, lotofacil_bolas, f_lotofacil_num_bolas);
        gerar_lotofacil_bolas_novos_repetidos_binario(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_num_bolas_binario);
        gerar_lotofacil_diferenca(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_diferenca);
        gerar_lotofacil_soma(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_soma);
        gerar_lotofacil_hash(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_hash);
        gerar_lotofacil_giro(ltf_id, ltf_qt, lotofacil_num, f_lotofacil_giro);        
        //gerar_lotofacil_grupo(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_grupo);
        gerar_lotofacil_algarismo_na_dezena(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_algarismo_na_dezena);
        gerar_lotofacil_coluna_b(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_coluna_b);

        lotofacil_num[b1] = 0; lotofacil_num[b2] = 0; lotofacil_num[b3] = 0; lotofacil_num[b4] = 0;
        lotofacil_num[b5] = 0; lotofacil_num[b6] = 0; lotofacil_num[b7] = 0; lotofacil_num[b8] = 0;
        lotofacil_num[b9] = 0; lotofacil_num[b10] = 0; lotofacil_num[b11] = 0; lotofacil_num[b12] = 0;
        lotofacil_num[b13] = 0; lotofacil_num[b14] = 0; lotofacil_num[b15] = 0; lotofacil_num[b16] = 0;
        lotofacil_num[b17] = 0;

    }

    ltf_qt = 18;
    printf("Gerando combinações de 18 bolas...Aguarde...\n");
    for(int b1 = 1; b1 <= LOTOFACIL_ULTIMA_BOLA; b1++)
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
    for(int b16 = b15 + 1; b16 <= LOTOFACIL_ULTIMA_BOLA; b16++)
    for(int b17 = b16 + 1; b17 <= LOTOFACIL_ULTIMA_BOLA; b17++)
    for(int b18 = b17 + 1; b18 <= LOTOFACIL_ULTIMA_BOLA; b18++)
    {
        ltf_id++;
        ltf_id_gerado = obter_deslocamento_18_bolas(b1, b2, b3, b4, b5, b6, b7, b8, b9, b10,
                                                    b11, b12, b13, b14, b15, b16, b17, b18);
        if(ltf_id != ltf_id_gerado)
        {
            printf("ltf_id = %li, ltf_id_gerado: %li\n", ltf_id, ltf_id_gerado);
            fprintf(stderr, "Erro ao gerar ltf_id");
            return 0;
        }

        lotofacil_num[b1] = 1; lotofacil_num[b2] = 1; lotofacil_num[b3] = 1; lotofacil_num[b4] = 1;
        lotofacil_num[b5] = 1; lotofacil_num[b6] = 1; lotofacil_num[b7] = 1; lotofacil_num[b8] = 1;
        lotofacil_num[b9] = 1; lotofacil_num[b10] = 1; lotofacil_num[b11] = 1; lotofacil_num[b12] = 1;
        lotofacil_num[b13] = 1; lotofacil_num[b14] = 1; lotofacil_num[b15] = 1; lotofacil_num[b16] = 1;
        lotofacil_num[b17] = 1; lotofacil_num[b18] = 1;

        lotofacil_bolas[1] = b1; lotofacil_bolas[2] = b2; lotofacil_bolas[3] = b3; lotofacil_bolas[4] = b4;
        lotofacil_bolas[5] = b5; lotofacil_bolas[6] = b6; lotofacil_bolas[7] = b7; lotofacil_bolas[8] = b8;
        lotofacil_bolas[9] = b9; lotofacil_bolas[10] = b10; lotofacil_bolas[11] = b11; lotofacil_bolas[12] = b12;
        lotofacil_bolas[13] = b13; lotofacil_bolas[14] = b14; lotofacil_bolas[15] = b15; lotofacil_bolas[16] = b16;
        lotofacil_bolas[17] = b17; lotofacil_bolas[18] = b18;


        gerar_lotofacil_num(ltf_id, ltf_qt, lotofacil_num, f_lotofacil_num);
        gerar_lotofacil_bolas(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_bolas);
        gerar_lotofacil_id(ltf_id, ltf_qt, lotofacil_num, lotofacil_bolas, f_lotofacil_id);
        gerar_lotofacil_num_bolas(ltf_id, ltf_qt, ltf_seq, lotofacil_bolas, f_lotofacil_num_bolas);
        gerar_lotofacil_bolas_novos_repetidos_binario(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_num_bolas_binario);
        gerar_lotofacil_diferenca(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_diferenca);
        gerar_lotofacil_soma(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_soma);
        gerar_lotofacil_hash(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_hash);
        gerar_lotofacil_giro(ltf_id, ltf_qt, lotofacil_num, f_lotofacil_giro);
        //gerar_lotofacil_grupo(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_grupo);
        gerar_lotofacil_algarismo_na_dezena(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_algarismo_na_dezena);
        gerar_lotofacil_coluna_b(ltf_id, ltf_qt, lotofacil_bolas, f_lotofacil_coluna_b);

        lotofacil_num[b1] = 0; lotofacil_num[b2] = 0; lotofacil_num[b3] = 0; lotofacil_num[b4] = 0;
        lotofacil_num[b5] = 0; lotofacil_num[b6] = 0; lotofacil_num[b7] = 0; lotofacil_num[b8] = 0;
        lotofacil_num[b9] = 0; lotofacil_num[b10] = 0; lotofacil_num[b11] = 0; lotofacil_num[b12] = 0;
        lotofacil_num[b13] = 0; lotofacil_num[b14] = 0; lotofacil_num[b15] = 0; lotofacil_num[b16] = 0;
        lotofacil_num[b17] = 0; lotofacil_num[b18] = 0;

    }

sair:
    // Fecha os arquivos
    fclose(f_lotofacil_num);
    fclose(f_lotofacil_bolas);
    fclose(f_lotofacil_id);
    fclose(f_lotofacil_num_bolas);
    fclose(f_lotofacil_num_bolas_binario);
    fclose(f_lotofacil_diferenca);
    fclose(f_lotofacil_soma);
    fclose(f_lotofacil_hash);
    fclose(f_lotofacil_giro);
    fclose(f_lotofacil_coluna_b);

//    for(int uA = 2; uA <= 10; uA++){
//        fclose(f_lotofacil_grupo[uA]);
//    }

    fclose(f_lotofacil_algarismo_na_dezena);

    return true;
}

/**
    Gera dados pra o arquivo lotofacil_num.csv
    Retorna true, se gravado com sucesso.
**/
inline bool gerar_lotofacil_num(long ltf_id, long ltf_qt, const long *const lotofacil_num, FILE *f_lotofacil_num){
    fprintf(f_lotofacil_num,
                "\n%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;%li;"
                "%li;%li;%li;%li;%li;%li;%li",
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
    Gera os dados para o arquivo lotofacil_bolas.csv
**/
inline bool gerar_lotofacil_bolas(long ltf_id, long ltf_qt, const long *const lotofacil_bolas, FILE *f_lotofacil_bolas){    
    fprintf(f_lotofacil_bolas, "\n%li;%li", ltf_id, ltf_qt);
    fprintf(f_lotofacil_bolas, ";%li", lotofacil_bolas[1]);
    for(int uA = 2; uA <= ltf_qt; uA++){
        fprintf(f_lotofacil_bolas, ";%li", lotofacil_bolas[uA]);
    }

    // Coloca os pontos e vírgula no final conforme a quantidade de bolas.
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

/**
 *  Gera os dados pra o arquivo 'lotofacil_coluna_b.csv'.
 *
**/
inline bool gerar_lotofacil_coluna_b(long ltf_id, long ltf_qt, const long *const lotofacil_bolas, FILE * f_lotofacil_coluna_b)
{
    fprintf(f_lotofacil_coluna_b, "\n%li;%li", ltf_id, ltf_qt);

    // Há 121 elementos, de 0 a 120, entretanto, iremos usar os índices de 1 a 120.
    long coluna_b_id[121];
    memset(coluna_b_id, 0, sizeof(long) * 121);
    long *pt = &coluna_b_id[1];

    const long * pt_b = lotofacil_bolas;

    /*
     * Algoritmo
     * Autor    :   Fábio Moura de Oliveira
     * Descrição:   Dado um arranjo com bolas ordenadas em ordem crescente, obter
     *              os grupos de 1 até o total de bolas do grupo.
     *
     */

    for(long uA = 1; uA <= 15; uA++)
    {
        switch(uA){
        case 1:
            // Aponta pra coluna antes de b_1.
            pt_b = lotofacil_bolas;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
            *pt = obter_deslocamento_3_bolas(pt_b[1], pt_b[2], pt_b[3]); pt++;
            *pt = obter_deslocamento_4_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4]); pt++;
            *pt = obter_deslocamento_5_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5]); pt++;
            *pt = obter_deslocamento_6_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6]); pt++;
            *pt = obter_deslocamento_7_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7]); pt++;
            *pt = obter_deslocamento_8_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8]); pt++;
            *pt = obter_deslocamento_9_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9]); pt++;
            *pt = obter_deslocamento_10_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10]); pt++;
            *pt = obter_deslocamento_11_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11]); pt++;
            *pt = obter_deslocamento_12_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11], pt_b[12]); pt++;
            *pt = obter_deslocamento_13_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11], pt_b[12], pt_b[13]); pt++;
            *pt = obter_deslocamento_14_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11], pt_b[12], pt_b[13], pt_b[14]); pt++;
            *pt = obter_deslocamento_15_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11], pt_b[12], pt_b[13], pt_b[14], pt_b[15]); pt++;
            break;

        case 2:
            // Aponta pra coluna antes de b_2.
            pt_b = lotofacil_bolas + 1;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
            *pt = obter_deslocamento_3_bolas(pt_b[1], pt_b[2], pt_b[3]); pt++;
            *pt = obter_deslocamento_4_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4]); pt++;
            *pt = obter_deslocamento_5_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5]); pt++;
            *pt = obter_deslocamento_6_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6]); pt++;
            *pt = obter_deslocamento_7_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7]); pt++;
            *pt = obter_deslocamento_8_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8]); pt++;
            *pt = obter_deslocamento_9_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9]); pt++;
            *pt = obter_deslocamento_10_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10]); pt++;
            *pt = obter_deslocamento_11_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11]); pt++;
            *pt = obter_deslocamento_12_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11], pt_b[12]); pt++;
            *pt = obter_deslocamento_13_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11], pt_b[12], pt_b[13]); pt++;
            *pt = obter_deslocamento_14_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11], pt_b[12], pt_b[13], pt_b[14]); pt++;
        break;

        case 3:
            pt_b = lotofacil_bolas + 2;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
            *pt = obter_deslocamento_3_bolas(pt_b[1], pt_b[2], pt_b[3]); pt++;
            *pt = obter_deslocamento_4_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4]); pt++;
            *pt = obter_deslocamento_5_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5]); pt++;
            *pt = obter_deslocamento_6_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6]); pt++;
            *pt = obter_deslocamento_7_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7]); pt++;
            *pt = obter_deslocamento_8_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8]); pt++;
            *pt = obter_deslocamento_9_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9]); pt++;
            *pt = obter_deslocamento_10_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10]); pt++;
            *pt = obter_deslocamento_11_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11]); pt++;
            *pt = obter_deslocamento_12_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11], pt_b[12]); pt++;
            *pt = obter_deslocamento_13_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11], pt_b[12], pt_b[13]); pt++;
        break;
        case 4:
            pt_b = lotofacil_bolas + 3;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
            *pt = obter_deslocamento_3_bolas(pt_b[1], pt_b[2], pt_b[3]); pt++;
            *pt = obter_deslocamento_4_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4]); pt++;
            *pt = obter_deslocamento_5_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5]); pt++;
            *pt = obter_deslocamento_6_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6]); pt++;
            *pt = obter_deslocamento_7_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7]); pt++;
            *pt = obter_deslocamento_8_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8]); pt++;
            *pt = obter_deslocamento_9_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9]); pt++;
            *pt = obter_deslocamento_10_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10]); pt++;
            *pt = obter_deslocamento_11_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11]); pt++;
            *pt = obter_deslocamento_12_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11], pt_b[12]); pt++;
        break;

        case 5:
            pt_b = lotofacil_bolas + 4;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
            *pt = obter_deslocamento_3_bolas(pt_b[1], pt_b[2], pt_b[3]); pt++;
            *pt = obter_deslocamento_4_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4]); pt++;
            *pt = obter_deslocamento_5_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5]); pt++;
            *pt = obter_deslocamento_6_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6]); pt++;
            *pt = obter_deslocamento_7_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7]); pt++;
            *pt = obter_deslocamento_8_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8]); pt++;
            *pt = obter_deslocamento_9_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9]); pt++;
            *pt = obter_deslocamento_10_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10]); pt++;
            *pt = obter_deslocamento_11_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10], pt_b[11]); pt++;
        break;

        case 6:
            pt_b = lotofacil_bolas + 5;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
            *pt = obter_deslocamento_3_bolas(pt_b[1], pt_b[2], pt_b[3]); pt++;
            *pt = obter_deslocamento_4_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4]); pt++;
            *pt = obter_deslocamento_5_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5]); pt++;
            *pt = obter_deslocamento_6_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6]); pt++;
            *pt = obter_deslocamento_7_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7]); pt++;
            *pt = obter_deslocamento_8_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8]); pt++;
            *pt = obter_deslocamento_9_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9]); pt++;
            *pt = obter_deslocamento_10_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9], pt_b[10]); pt++;
        break;

        case 7:
            pt_b = lotofacil_bolas + 6;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
            *pt = obter_deslocamento_3_bolas(pt_b[1], pt_b[2], pt_b[3]); pt++;
            *pt = obter_deslocamento_4_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4]); pt++;
            *pt = obter_deslocamento_5_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5]); pt++;
            *pt = obter_deslocamento_6_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6]); pt++;
            *pt = obter_deslocamento_7_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7]); pt++;
            *pt = obter_deslocamento_8_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8]); pt++;
            *pt = obter_deslocamento_9_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8], pt_b[9]); pt++;
        break;

        case 8:
            pt_b = lotofacil_bolas + 7;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
            *pt = obter_deslocamento_3_bolas(pt_b[1], pt_b[2], pt_b[3]); pt++;
            *pt = obter_deslocamento_4_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4]); pt++;
            *pt = obter_deslocamento_5_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5]); pt++;
            *pt = obter_deslocamento_6_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6]); pt++;
            *pt = obter_deslocamento_7_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7]); pt++;
            *pt = obter_deslocamento_8_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7], pt_b[8]); pt++;
        break;

        case 9:
            pt_b = lotofacil_bolas + 8;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
            *pt = obter_deslocamento_3_bolas(pt_b[1], pt_b[2], pt_b[3]); pt++;
            *pt = obter_deslocamento_4_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4]); pt++;
            *pt = obter_deslocamento_5_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5]); pt++;
            *pt = obter_deslocamento_6_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6]); pt++;
            *pt = obter_deslocamento_7_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6], pt_b[7]); pt++;
        break;

        case 10:
            pt_b = lotofacil_bolas + 9;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
            *pt = obter_deslocamento_3_bolas(pt_b[1], pt_b[2], pt_b[3]); pt++;
            *pt = obter_deslocamento_4_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4]); pt++;
            *pt = obter_deslocamento_5_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5]); pt++;
            *pt = obter_deslocamento_6_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5], pt_b[6]); pt++;
        break;

        case 11:
            pt_b = lotofacil_bolas + 10;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
            *pt = obter_deslocamento_3_bolas(pt_b[1], pt_b[2], pt_b[3]); pt++;
            *pt = obter_deslocamento_4_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4]); pt++;
            *pt = obter_deslocamento_5_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4], pt_b[5]); pt++;
        break;

        case 12:
            pt_b = lotofacil_bolas + 11;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
            *pt = obter_deslocamento_3_bolas(pt_b[1], pt_b[2], pt_b[3]); pt++;
            *pt = obter_deslocamento_4_bolas(pt_b[1], pt_b[2], pt_b[3], pt_b[4]); pt++;
        break;

        case 13:
            pt_b = lotofacil_bolas + 12;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
            *pt = obter_deslocamento_3_bolas(pt_b[1], pt_b[2], pt_b[3]); pt++;
        break;

        case 14:
            pt_b = lotofacil_bolas + 13;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
            *pt = obter_deslocamento_2_bolas(pt_b[1], pt_b[2]); pt++;
        break;

        case 15:
            pt_b = lotofacil_bolas + 14;
            *pt = obter_deslocamento_1_bola(pt_b[1]); pt++;
        break;

        }
    }

    for(long uA = 1; uA <= 120; uA++){
        fprintf(f_lotofacil_coluna_b, ";%li", coluna_b_id[uA]);
    }

    if(ferror(f_lotofacil_coluna_b))
    {
        return false;
    }

    return true;

}




/**
 * @brief gerar_lotofacil_num_bolas
 * @param ltf_id
 * @param ltf_qt
 * @param ltf_seq
 * @param lotofacil_bolas
 * @param f_lotofacil_bolas
 * @return
 */
inline bool gerar_lotofacil_num_bolas(long ltf_id,
                                      long ltf_qt,
                                      long long & ltf_seq,
                                      const long *const lotofacil_bolas,
                                      FILE *f_lotofacil_num_bolas){
    for(int uA = 1; uA <= ltf_qt; uA++){
        ltf_seq += 1;
        fprintf(f_lotofacil_num_bolas, "\n%lli;%li;%li;%li",
                ltf_seq,
                ltf_id,
                ltf_qt,
                lotofacil_bolas[uA]);
        if(ferror(f_lotofacil_num_bolas)){
            fprintf(stderr, "Erro ao gravar dados em 'lotofacil_num.csv'\n");
            return false;
        }
    }

    return true;
}

/**
 * @brief A st_ltf_num_bolas struct
 * usada pra armazenar em formato binário todas as combinações
 * possíveis da lotofacil.
 * Há 6874010 combinações possíveis.
 */
struct st_ltf_num_bolas{
    unsigned int ltf_id;                        // 4 bytes: de 1 a 6874010
    unsigned char ltf_qt;                       // 1 byte:  de 15 a 18.
    unsigned char novos_repetidos_id;           // de 0 a 10.
    unsigned char qt_bolas_comuns_b1_a_b15;     // de 0 a 15.
    unsigned char qt_bolas_subindo_b1_a_b15;    // de 0 a 15.
    unsigned char qt_bolas_descendo_b1_a_b15;   // de 0 a 15.
    unsigned char cmp_b_id;                     // Cabe tudo em um unico byte.
    unsigned char nao_usado[2];                 // Serve pra alinhar a próxima estrutura em posição multipla de 4 bytes.
    unsigned int novos_repetidos_id_alternado;
    unsigned int id_aleatorio;
    unsigned char bolas[20];            // 2 bytes adicional pra alinhamento.
};

inline bool gerar_lotofacil_bolas_novos_repetidos_binario(long ltf_id,
                                      long ltf_qt,
                                      const long *const lotofacil_bolas,
                                      FILE *f_lotofacil_num_bolas_binario){

    st_ltf_num_bolas ltf_num_bolas;

    // Todo o registro será zerado.
    memset(&ltf_num_bolas, 0, sizeof(st_ltf_num_bolas));

    ltf_num_bolas.ltf_id = static_cast<unsigned int>(ltf_id);
    ltf_num_bolas.ltf_qt = static_cast<unsigned char>(ltf_qt);

    for(int uA = 1; uA <= ltf_qt; uA++){
        ltf_num_bolas.bolas[uA] = static_cast<unsigned char>(lotofacil_bolas[uA]);
    }
    fwrite(&ltf_num_bolas, sizeof(st_ltf_num_bolas), 1, f_lotofacil_num_bolas_binario);
    if(ferror(f_lotofacil_num_bolas_binario)){
        fprintf(stderr, "Erro ao gravar dados em 'lotofacil_num.csv'\n");
        return false;
    }

    return true;
}



/**
 * @brief gerar_lotofacil_id
 *  @details Gera o arquivo lotofacil_id.csv, onde cada campo corresponde
 * a um id de cada tipo de combinação.
 * @param ltf_id
 * @param ltf_qt
 * @param lotofacil_num
 * @param lotofacil_bolas
 * @param f_arquivo_id
 * @return
 */

inline bool gerar_lotofacil_id(long ltf_id, long ltf_qt, const long *const lotofacil_num, const long *const lotofacil_bolas,
                          FILE *f_arquivo_id)
{
    // Colunas b
    long b1  = lotofacil_bolas[1];
    long b2  = lotofacil_bolas[2];
    long b3  = lotofacil_bolas[3];
    long b4  = lotofacil_bolas[4];
    long b5  = lotofacil_bolas[5];
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
    long id_par_impar = obter_par_impar_id(qt_par, qt_impar);
    long id_externo_interno = obter_externo_interno_id(qt_externo, qt_interno);
    long id_primo_nao_primo = obter_primo_nao_primo_id(qt_primo,qt_nao_primo);
    long id_horizontal = obter_horizontal_id(qt_hrz_1, qt_hrz_2, qt_hrz_3, qt_hrz_4, qt_hrz_5);
    long id_vertical = obter_vertical_id(qt_vrt_1, qt_vrt_2, qt_vrt_3, qt_vrt_4, qt_vrt_5);
    long id_diagonal = obter_diagonal_id(qt_dg_1, qt_dg_2, qt_dg_3, qt_dg_4, qt_dg_5);
    long id_cruzeta = obter_cruzeta_id(qt_crz_1, qt_crz_2, qt_crz_3, qt_crz_4, qt_crz_5);
    long id_quarteto = obter_quarteto_id(qt_qrt_1, qt_qrt_2, qt_qrt_3, qt_qrt_4, qt_qrt_5, qt_qrt_6);
    long id_trio = obter_trio_id(qt_trio_1, qt_trio_2, qt_trio_3, qt_trio_4, qt_trio_5,qt_trio_6, qt_trio_7, qt_trio_8);

    // Identificadores para colunas b1.
    long id_b1 = obter_b1_id(b1);
    long id_b1_b2 = obter_b1_b2_id(b1, b2);
    long id_b1_b2_b3 = obter_b1_b2_b3_id(b1, b2, b3);
    long id_b1_b2_b3_b4 = obter_b1_b2_b3_b4_id(b1, b2, b3, b4);
    long id_b1_b2_b3_b4_b5 = obter_b1_b2_b3_b4_b5_id(b1, b2, b3, b4, b5);

    long id_b1_b15 = obter_b1_b15_id(b1,b15);
    long id_b1_b8_b15 = obter_b1_b8_b15_id(b1,b8,b15);
    long id_b1_b4_b8_b12_b15 = obter_b1_b4_b8_b12_b15_id(b1,b4,b8,b12,b15);

    long qt_dz_0 = 0;
    long qt_dz_1 = 0;
    long qt_dz_2 = 0;

    obter_lotofacil_qt_dezenas(ltf_id, ltf_qt, lotofacil_bolas, &qt_dz_0, &qt_dz_1, &qt_dz_2);

    long id_algarismo_na_dezena = obter_algarismo_na_dezena_id(qt_dz_0, qt_dz_1, qt_dz_2);

    bool bErro = false;
    if(id_par_impar == -1){
        cout << "ltf_id: " << ltf_id << ", erro: id_par_impar invalido. "
             << "obter_par_impar_id(" << qt_par << ", " << qt_impar << ")" << endl;
        bErro = true;
    }

    if(id_externo_interno == -1){
        cout << "ltf_id: " << ltf_id << ", erro: id_externo_interno invalido. "
             << "obter_externo_interno(" << qt_externo << ", " << qt_interno << endl;
    }


    fprintf(f_arquivo_id, "\n%li;%li", ltf_id, ltf_qt);
    fprintf(f_arquivo_id, ";%li;%li;%li", id_par_impar, id_externo_interno, id_primo_nao_primo);
    fprintf(f_arquivo_id, ";%li;%li;%li", id_horizontal, id_vertical, id_diagonal);
    fprintf(f_arquivo_id, ";%li;%li;%li", id_cruzeta, id_quarteto, id_trio);
    // Iremos incluir as colunas b em ordem.
    fprintf(f_arquivo_id, ";%li;%li;%li;%li;%li",   id_b1,
                                                    id_b1_b2,
                                                    id_b1_b2_b3,
                                                    id_b1_b2_b3_b4,
                                                    id_b1_b2_b3_b4_b5);
    fprintf(f_arquivo_id, ";%li;%li;%li", id_b1_b15, id_b1_b8_b15, id_b1_b4_b8_b12_b15);
    fprintf(f_arquivo_id, ";%li", id_algarismo_na_dezena);

    // Agora, iremos contabilizar a quantidade de combinacoes, pra posteriormente, gravarmos.
    /**
    par_impar_id[qt_par][ qt_impar][1] += 1;
    externo_interno_id[qt_externo][qt_interno][1] += 1;
    primo_nao_primo_id[qt_primo][qt_nao_primo][1] += 1;
    horizontal_id[qt_hrz_1][qt_hrz_2][qt_hrz_3][qt_hrz_4][qt_hrz_5][1] += 1;
    vertical_id[qt_vrt_1][qt_vrt_2][qt_vrt_3][qt_vrt_4][qt_vrt_5][1] += 1;
    diagonal_id[qt_dg_1][qt_dg_2][qt_dg_3][qt_dg_4][qt_dg_5][1] += 1;
    cruzeta_id[qt_crz_1][qt_crz_2][qt_crz_3][qt_crz_4][qt_crz_5][1] += 1;
    quarteto_id[qt_qrt_1][qt_qrt_2][qt_qrt_3][qt_qrt_4][qt_qrt_5][qt_qrt_6][1] += 1;
    trio_id[qt_trio_1][qt_trio_2][qt_trio_3][qt_trio_4][qt_trio_5][qt_trio_6][qt_trio_7][qt_trio_8][1] += 1;
    **/


    long indice_bola = ltf_qt - 14;
    if((indice_bola < 1) || (indice_bola > 4))
    {
        fprintf(stderr, "Erro, funcao gerar_lotofacil_id, ltf_qt invalido");
        return false;
    }

    /*
    b1_id[b1][indice_bola] += 1;
    b1_id[b1][5] += 1;

    b1_b15_id[b1][b15][indice_bola] += 1;
    b1_b15_id[b1][b15][5] += 1;

    b1_b8_b15_id[b1][b8][b15][indice_bola] += 1;
    b1_b8_b15_id[b1][b8][b15][5] += 1;

    b1_b4_b8_b12_b15_id[b1][b4][b8][b12][b15][indice_bola] += 1;
    b1_b4_b8_b12_b15_id[b1][b4][b8][b12][b15][5] += 1;
    */

    return true;
}

/**
 * @brief gerar_lotofacil_diferenca
 * @details
 *  Gera um arquivo lotofacil_diferenca_entre_bolas.csv, onde cada campo da esquerda pra direita
 * indica a diferença da bola atual menos a bola anterior.
 * Com isto, conseguimos detectar possíveis bolas em sequencia.
 * @param ltf_id
 * @param ltf_qt
 * @param lotofacil_bolas
 * @param f_lotofacil_seq
 * @return
 */
inline bool gerar_lotofacil_diferenca(long ltf_id,
                                long ltf_qt,
                                const long * const lotofacil_bolas,
                                FILE * f_lotofacil_dif){
    
    // A diferenca máxima é 11, seja:
    // b15, última coluna, valor 25,
    // b14, penúltima coluna, valor 14.
    // Resultado: 25 - 14 = 11
    
    long * ltf_dif = new long[12];
    memset(ltf_dif, 0, sizeof(long) * 12);    

    fprintf(f_lotofacil_dif, "\n%li;%li", ltf_id, ltf_qt);

    // Iremos da esquerda pra direita, realização a subtração,
    // onde a partir do segundo, iremos fazer a diferença entre
    // o atual e o anterior à esquerda.
    long uB = 1;
    long diferenca_anterior = 0;
    long qt_diferenca_alternadas = 0;
    for(long uA = 2; uA <= ltf_qt; uA++){
        uB = lotofacil_bolas[uA] - lotofacil_bolas[uA-1];

        // A cada alteração no valor da diferença, iremos contabilizar tal alteração
        // o objetivo disto é detectar se as diferenças alteram pouco ou muito.
        // Quanto menor a alternância, quer há vários números em sequências.
        // Na primeira passagem, iremos registrar o número anterior.
        if(uA == 2)
            diferenca_anterior = uB;

        if(diferenca_anterior != uB){
            qt_diferenca_alternadas++;
            diferenca_anterior = uB;
        }
        
        if((uB < 0) && (uB > 11)){
            fprintf(stderr, "Diferenca fora da faixa, deve estar entre 1 e 11\n");
            return false;
        }
        ltf_dif[uB] += 1;
        
        fprintf(f_lotofacil_dif, ";%li", uB);
        if(ferror(f_lotofacil_dif)){
            return false;
        }
    }

    if(ltf_qt == 15){
        fprintf(f_lotofacil_dif, ";0;0;0;0");
    }else if(ltf_qt == 16){
        fprintf(f_lotofacil_dif, ";0;0;0");
    }else if(ltf_qt == 17){
        fprintf(f_lotofacil_dif, ";0;0");
    }else if(ltf_qt == 18){
        fprintf(f_lotofacil_dif, ";0");
    }
    
    for(int uA = 1; uA <= 11; uA++){
        fprintf(f_lotofacil_dif, ";%li", ltf_dif[uA]);
    }

    // A quantidade de diferencas alternadas.
    fprintf(f_lotofacil_dif, ";%li", qt_diferenca_alternadas);

    return true;
}

/**
 * @brief gerar_lotofacil_algarismo_na_dezena
 * Gera a contabilização de quantas bolas começa na posição das dezenas com
 * o valor 0, 1 ou 2 pra cada combinação.
 * @param ltf_id
 * @param ltf_qt
 * @param lotofacil_bolas
 * @param f_lotofacil_dif
 * @return
 */
inline bool gerar_lotofacil_algarismo_na_dezena(long ltf_id,
                                      long ltf_qt,
                                      const long * const lotofacil_bolas,
                                      FILE * f_lotofacil_algarismo_na_dezena)
{
    if(!((ltf_qt >= 15) && (ltf_qt <= 18))){
        return false;
    }

    long qt_dezena_0 = 0;
    long qt_dezena_1 = 0;
    long qt_dezena_2 = 0;

    for(long uA = 1; uA <= ltf_qt; uA++){

        long bola_numero = lotofacil_bolas[uA];
        if(bola_numero <= 9)
            qt_dezena_0++;
        else if(bola_numero <= 19)
            qt_dezena_1++;
        else if(bola_numero <= 25)
            qt_dezena_2++;
    }

    // Verifica se está dentro dos limites.
    if(qt_dezena_0 > 9)
        return false;

    if(qt_dezena_1 > 10)
        return false;

    if(qt_dezena_2 > 6)
        return false;


    fprintf(f_lotofacil_algarismo_na_dezena,
            "\n%li;%li;%li",
            ltf_id, ltf_qt,
            obter_algarismo_na_dezena_id(qt_dezena_0, qt_dezena_1, qt_dezena_2)
            );


    return true;
}

inline bool obter_lotofacil_qt_dezenas(long ltf_id,
                                      long ltf_qt,
                                      const long * const lotofacil_bolas,
                                      long * qt_dz_0,
                                      long * qt_dz_1,
                                      long * qt_dz_2)
{
    if(!((ltf_qt >= 15) && (ltf_qt <= 18))){
        return false;
    }

    long qt_dezena_0 = 0;
    long qt_dezena_1 = 0;
    long qt_dezena_2 = 0;

    for(long uA = 1; uA <= ltf_qt; uA++){

        long bola_numero = lotofacil_bolas[uA];
        if(bola_numero <= 9)
            qt_dezena_0++;
        else if(bola_numero <= 19)
            qt_dezena_1++;
        else if(bola_numero <= 25)
            qt_dezena_2++;
    }

    // Verifica se está dentro dos limites.
    if(qt_dezena_0 > 9)
        return false;

    if(qt_dezena_1 > 10)
        return false;

    if(qt_dezena_2 > 6)
        return false;

    if((!qt_dz_0) || (!qt_dz_1) || !(qt_dz_2))
        return false;

    * qt_dz_0 = qt_dezena_0;
    * qt_dz_1 = qt_dezena_1;
    * qt_dz_2 = qt_dezena_2;

    return true;
}

