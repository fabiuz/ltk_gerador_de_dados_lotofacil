/*
 * Este arquivo gera os arquivos .csv pra serem populados nas tabelas e também
 * popula o arranjos de grupos pra serem utilizados posteriomente no gerador.
 *
 *
 * Autor:   Fábio Moura de Oliveira
 * Data:    30/03/2018
 *
 */

#include <cstdio>
#include "lotofacil_deslocamento.hpp"

/**
 * @brief grupo_2_bolas Armazena todas os ids das combinações de 2 bolas.
 */

/*
static long grupo_2_bolas[26][26];
static long grupo_3_bolas[26][26][26];
static long grupo_4_bolas[26][26][26][26];
static long grupo_5_bolas[26][26][26][26][26];
static long grupo_6_bolas[26][26][26][26][26][26];
static long grupo_7_bolas[26][26][26][26][26][26][26];
static long grupo_8_bolas[26][26][26][26][26][26][26][26];
static long grupo_9_bolas[26][26][26][26][26][26][26][26][26];
static long grupo_10_bolas[26][26][26][26][26][26][26][26][26][26];
*/

/*!
 * \brief obter_id_grupo_2_bolas Obtém o identificador do grupo de 2 bolas
 * se a combinação for válida.
 * Esta função valida todos os valores passados pelo usuário.
 * \param bolas
 * \return
 * Retorna o identificador do grupo de 2 bolas se válido, senão
 * retorna -1, se houver algum erro.
 */
long obter_id_grupo_2_bolas(const long * bolas){
    long b1, b2;
    b1 = bolas[1];
    b2 = bolas[2];

    bool b_b1 = (b1 >= 1) && (b1 <= 25);
    bool b_b2 = (b2 >= 2) && (b2 <= 25);

    if(!(b_b1 && b_b2)){
        return -1;
    }

    if(!(b1 < b2)){
        return -1;
    }

    return obter_deslocamento_2_bolas(b1, b2);
}

long obter_id_grupo_3_bolas(const long * bolas){
    long b1, b2, b3;
    b1 = bolas[1];
    b2 = bolas[2];
    b3 = bolas[3];

    bool b_b1 = (b1 >= 1) && (b1 <= 25);
    bool b_b2 = (b2 >= 2) && (b2 <= 25);
    bool b_b3 = (b3 >= 3) && (b3 <= 25);

    if(!(b_b1 && b_b2 && b_b3)){
        return -1;
    }

    b_b1 = b1 < b2;
    b_b2 = b2 < b3;

    if(!(b_b1 && b_b2))
    {
        return -1;
    }

    return obter_deslocamento_3_bolas(b1, b2, b3);
}

long obter_id_grupo_4_bolas(const long * bolas){
    long b1, b2, b3, b4;
    b1 = bolas[1];
    b2 = bolas[2];
    b3 = bolas[3];
    b4 = bolas[4];

    bool b_b1 = (b1 >= 1) && (b1 <= 25);
    bool b_b2 = (b2 >= 2) && (b2 <= 25);
    bool b_b3 = (b3 >= 3) && (b3 <= 25);
    bool b_b4 = (b4 >= 4) && (b4 <= 25);

    if(!(b_b1 && b_b2 && b_b3 && b_b4)){
        return -1;
    }

    b_b1 = b1 < b2;
    b_b2 = b2 < b3;
    b_b3 = b3 < b4;

    if(!(b_b1 && b_b2 && b_b3)){
        return -1;
    }

    return obter_deslocamento_4_bolas(b1, b2, b3, b4);
}

long obter_id_grupo_5_bolas(const long * bolas){
    long b1, b2, b3, b4, b5;
    b1 = bolas[1];
    b2 = bolas[2];
    b3 = bolas[3];
    b4 = bolas[4];
    b5 = bolas[5];

    bool b_b1 = (b1 >= 1) && (b1 <= 25);
    bool b_b2 = (b2 >= 2) && (b2 <= 25);
    bool b_b3 = (b3 >= 3) && (b3 <= 25);
    bool b_b4 = (b4 >= 4) && (b4 <= 25);
    bool b_b5 = (b5 >= 5) && (b5 <= 25);

    if(!(b_b1 && b_b2 && b_b3 && b_b4 && b_b5)){
        return -1;
    }

    b_b1 = b1 < b2;
    b_b2 = b2 < b3;
    b_b3 = b3 < b4;
    b_b4 = b4 < b5;

    if(!(b_b1 && b_b2 && b_b3 && b_b4)){
        return -1;
    }

    return obter_deslocamento_5_bolas(b1, b2, b3, b4, b5);
}


long obter_id_grupo_6_bolas(const long * bolas){
    long b1, b2, b3, b4, b5, b6;
    b1 = bolas[1];
    b2 = bolas[2];
    b3 = bolas[3];
    b4 = bolas[4];
    b5 = bolas[5];
    b6 = bolas[6];

    bool b_b1 = (b1 >= 1) && (b1 <= 25);
    bool b_b2 = (b2 >= 2) && (b2 <= 25);
    bool b_b3 = (b3 >= 3) && (b3 <= 25);
    bool b_b4 = (b4 >= 4) && (b4 <= 25);
    bool b_b5 = (b5 >= 5) && (b5 <= 25);
    bool b_b6 = (b6 >= 6) && (b6 <= 25);

    if(!(b_b1 && b_b2 && b_b3 && b_b4 && b_b5 && b_b6)){
        return -1;
    }

    b_b1 = b1 < b2;
    b_b2 = b2 < b3;
    b_b3 = b3 < b4;
    b_b4 = b4 < b5;
    b_b5 = b5 < b6;

    if(!(b_b1 && b_b2 && b_b3 && b_b4 && b_b5)){
        return -1;
    }

    return obter_deslocamento_6_bolas(b1, b2, b3, b4, b5, b6);
}



long obter_id_grupo_7_bolas(const long * bolas){
    long b1, b2, b3, b4, b5, b6, b7;
    b1 = bolas[1];
    b2 = bolas[2];
    b3 = bolas[3];
    b4 = bolas[4];
    b5 = bolas[5];
    b6 = bolas[6];
    b7 = bolas[7];

    bool b_b1 = (b1 >= 1) && (b1 <= 25);
    bool b_b2 = (b2 >= 2) && (b2 <= 25);
    bool b_b3 = (b3 >= 3) && (b3 <= 25);
    bool b_b4 = (b4 >= 4) && (b4 <= 25);
    bool b_b5 = (b5 >= 5) && (b5 <= 25);
    bool b_b6 = (b6 >= 6) && (b6 <= 25);
    bool b_b7 = (b7 >= 7) && (b7 <= 25);

    if(!(b_b1 && b_b2 && b_b3 && b_b4 && b_b5 && b_b6 && b_b7)){
        return -1;
    }

    b_b1 = b1 < b2;
    b_b2 = b2 < b3;
    b_b3 = b3 < b4;
    b_b4 = b4 < b5;
    b_b5 = b5 < b6;
    b_b6 = b6 < b7;

    if(!(b_b1 && b_b2 && b_b3 && b_b4 && b_b5 && b_b6)){
        return -1;
    }

    return obter_deslocamento_7_bolas(b1, b2, b3, b4, b5, b6, b7);
}

long obter_id_grupo_8_bolas(const long * bolas){
    long b1, b2, b3, b4, b5, b6, b7, b8;
    b1 = bolas[1];
    b2 = bolas[2];
    b3 = bolas[3];
    b4 = bolas[4];
    b5 = bolas[5];
    b6 = bolas[6];
    b7 = bolas[7];
    b8 = bolas[8];

    bool b_b1 = (b1 >= 1) && (b1 <= 25);
    bool b_b2 = (b2 >= 2) && (b2 <= 25);
    bool b_b3 = (b3 >= 3) && (b3 <= 25);
    bool b_b4 = (b4 >= 4) && (b4 <= 25);
    bool b_b5 = (b5 >= 5) && (b5 <= 25);
    bool b_b6 = (b6 >= 6) && (b6 <= 25);
    bool b_b7 = (b7 >= 7) && (b7 <= 25);
    bool b_b8 = (b8 >= 8) && (b8 <= 25);

    if(!(b_b1 && b_b2 && b_b3 && b_b4 && b_b5 && b_b6 && b_b7 && b_b8)){
        return -1;
    }

    b_b1 = b1 < b2;
    b_b2 = b2 < b3;
    b_b3 = b3 < b4;
    b_b4 = b4 < b5;
    b_b5 = b5 < b6;
    b_b6 = b6 < b7;
    b_b7 = b7 < b8;

    if(!(b_b1 && b_b2 && b_b3 && b_b4 && b_b5 && b_b6 && b_b7)){
        return -1;
    }

    return obter_deslocamento_8_bolas(b1, b2, b3, b4, b5, b6, b7, b8);
}

long obter_id_grupo_9_bolas(const long * bolas){
    long b1, b2, b3, b4, b5, b6, b7, b8, b9;
    b1 = bolas[1];
    b2 = bolas[2];
    b3 = bolas[3];
    b4 = bolas[4];
    b5 = bolas[5];
    b6 = bolas[6];
    b7 = bolas[7];
    b8 = bolas[8];
    b9 = bolas[9];

    bool b_b1 = (b1 >= 1) && (b1 <= 25);
    bool b_b2 = (b2 >= 2) && (b2 <= 25);
    bool b_b3 = (b3 >= 3) && (b3 <= 25);
    bool b_b4 = (b4 >= 4) && (b4 <= 25);
    bool b_b5 = (b5 >= 5) && (b5 <= 25);
    bool b_b6 = (b6 >= 6) && (b6 <= 25);
    bool b_b7 = (b7 >= 7) && (b7 <= 25);
    bool b_b8 = (b8 >= 8) && (b8 <= 25);
    bool b_b9 = (b9 >= 9) && (b9 <= 25);

    if(!(b_b1 && b_b2 && b_b3 && b_b4 && b_b5 && b_b6 && b_b7 && b_b8 && b_b9)){
        return -1;
    }

    b_b1 = b1 < b2;
    b_b2 = b2 < b3;
    b_b3 = b3 < b4;
    b_b4 = b4 < b5;
    b_b5 = b5 < b6;
    b_b6 = b6 < b7;
    b_b7 = b7 < b8;
    b_b8 = b8 < b9;

    if(!(b_b1 && b_b2 && b_b3 && b_b4 && b_b5 && b_b6 && b_b7 && b_b8)){
        return -1;
    }

    return obter_deslocamento_9_bolas(b1, b2, b3, b4, b5, b6, b7, b8, b9);
}

long obter_id_grupo_10_bolas(const long * bolas){
    long b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;
    b1 = bolas[1];
    b2 = bolas[2];
    b3 = bolas[3];
    b4 = bolas[4];
    b5 = bolas[5];
    b6 = bolas[6];
    b7 = bolas[7];
    b8 = bolas[8];
    b9 = bolas[9];
    b10 = bolas[10];

    bool b_b1 = (b1 >= 1) && (b1 <= 25);
    bool b_b2 = (b2 >= 2) && (b2 <= 25);
    bool b_b3 = (b3 >= 3) && (b3 <= 25);
    bool b_b4 = (b4 >= 4) && (b4 <= 25);
    bool b_b5 = (b5 >= 5) && (b5 <= 25);
    bool b_b6 = (b6 >= 6) && (b6 <= 25);
    bool b_b7 = (b7 >= 7) && (b7 <= 25);
    bool b_b8 = (b8 >= 8) && (b8 <= 25);
    bool b_b9 = (b9 >= 9) && (b9 <= 25);
    bool b_b10 = (b10 >= 10) && (b10 <= 25);

    if(!(b_b1 && b_b2 && b_b3 && b_b4 && b_b5 && b_b6 && b_b7 && b_b8 && b_b9 && b_b10)){
        return -1;
    }

    b_b1 = b1 < b2;
    b_b2 = b2 < b3;
    b_b3 = b3 < b4;
    b_b4 = b4 < b5;
    b_b5 = b5 < b6;
    b_b6 = b6 < b7;
    b_b7 = b7 < b8;
    b_b8 = b8 < b9;
    b_b9 = b9 < b10;

    if(!(b_b1 && b_b2 && b_b3 && b_b4 && b_b5 && b_b6 && b_b7 && b_b8 && b_b9)){
        return -1;
    }

    return obter_deslocamento_10_bolas(b1, b2, b3, b4, b5, b6, b7, b8, b9, b10);
}

bool gerar_grupo_id(){
    long id_grupo = 0;

    FILE * f_lotofacil_id_grupo_2_bolas = fopen("./arquivos_csv/lotofacil_id_grupo_2_bolas.csv", "w");
    FILE * f_lotofacil_id_grupo_3_bolas = fopen("./arquivos_csv/lotofacil_id_grupo_3_bolas.csv", "w");
    FILE * f_lotofacil_id_grupo_4_bolas = fopen("./arquivos_csv/lotofacil_id_grupo_4_bolas.csv", "w");
    FILE * f_lotofacil_id_grupo_5_bolas = fopen("./arquivos_csv/lotofacil_id_grupo_5_bolas.csv", "w");

    // Não irei utilizar os grupos de 6 a 10 bolas
    /*
    FILE * f_lotofacil_id_grupo_6_bolas = fopen("./arquivos_csv/lotofacil_id_grupo_6_bolas.csv", "w");
    FILE * f_lotofacil_id_grupo_7_bolas = fopen("./arquivos_csv/lotofacil_id_grupo_7_bolas.csv", "w");
    FILE * f_lotofacil_id_grupo_8_bolas = fopen("./arquivos_csv/lotofacil_id_grupo_8_bolas.csv", "w");
    FILE * f_lotofacil_id_grupo_9_bolas = fopen("./arquivos_csv/lotofacil_id_grupo_9_bolas.csv", "w");
    FILE * f_lotofacil_id_grupo_10_bolas = fopen("./arquivos_csv/lotofacil_id_grupo_10_bolas.csv", "w");
    */

    FILE * f_lotofacil_id_grupo[] = {
        0, 0,
        f_lotofacil_id_grupo_2_bolas,
        f_lotofacil_id_grupo_3_bolas,
        f_lotofacil_id_grupo_4_bolas,
        f_lotofacil_id_grupo_5_bolas
        /*
        f_lotofacil_id_grupo_6_bolas,
        f_lotofacil_id_grupo_7_bolas,
        f_lotofacil_id_grupo_8_bolas,
        f_lotofacil_id_grupo_9_bolas,
        f_lotofacil_id_grupo_10_bolas
            */
    };
    FILE * f_temp = 0;

    fprintf(f_lotofacil_id_grupo[2], "grp_id;b1;b2;");
    fprintf(f_lotofacil_id_grupo[3], "grp_id;b1;b2;b3");
    fprintf(f_lotofacil_id_grupo[4], "grp_id;b1;b2;b3;b4");
    fprintf(f_lotofacil_id_grupo[5], "grp_id;b1;b2;b3;b4;b5");
    /*
    fprintf(f_lotofacil_id_grupo[6], "grp_id;b1;b2;b3;b4;b5;b6");
    fprintf(f_lotofacil_id_grupo[7], "grp_id;b1;b2;b3;b4;b5;b6;b7");
    fprintf(f_lotofacil_id_grupo[8], "grp_id;b1;b2;b3;b4;b5;b6;b7;b8");
    fprintf(f_lotofacil_id_grupo[9], "grp_id;b1;b2;b3;b4;b5;b6;b7;b8;b9");
    fprintf(f_lotofacil_id_grupo[10], "grp_id;b1;b2;b3;b4;b5;b6;b7;b8;b9;b10");
    */

    printf("Gerando id grupo...");

    id_grupo = 0;
    f_temp = f_lotofacil_id_grupo[2];
    for(int b1= 1; b1 <= 25; b1++)
        for(int b2 = b1 + 1; b2 <= 25; b2++){
            id_grupo++;
            if(id_grupo != obter_deslocamento_2_bolas(b1, b2)){
                fprintf(stderr, "Erro ao gerar id grupo 2 bolas.\n");
                return false;
            }
            fprintf(f_temp, "\n%li;%i;%i", id_grupo, b1, b2);
        }

    id_grupo = 0;
    f_temp = f_lotofacil_id_grupo[3];
    for(int b1= 1; b1 <= 25; b1++)
        for(int b2 = b1 + 1; b2 <= 25; b2++)
            for(int b3 = b2 + 1; b3 <= 25; b3++)
            {
                id_grupo++;
                if(id_grupo != obter_deslocamento_3_bolas(b1, b2, b3)){
                    fprintf(stderr, "Erro ao gerar id grupo de 3 bolas.\n");
                    return false;
                }
                fprintf(f_temp, "\n%li;%i;%i;%i", id_grupo, b1, b2, b3);
            }

    id_grupo = 0;
    f_temp = f_lotofacil_id_grupo[4];
    for(int b1= 1; b1 <= 25; b1++)
        for(int b2 = b1 + 1; b2 <= 25; b2++)
            for(int b3 = b2 + 1; b3 <= 25; b3++)
                for(int b4 = b3 + 1; b4 <= 25; b4++)
                {
                    id_grupo++;
                    if(id_grupo != obter_deslocamento_4_bolas(b1, b2, b3, b4)){
                        fprintf(stderr, "Erro ao gerar id pra grupo de 4 bolas.\n");
                        return false;
                    }
                    fprintf(f_temp, "\n%li;%i;%i;%i;%i", id_grupo, b1, b2, b3, b4);
                }

    id_grupo = 0;
    f_temp = f_lotofacil_id_grupo[5];
    for(int b1= 1; b1 <= 25; b1++)
        for(int b2 = b1 + 1; b2 <= 25; b2++)
            for(int b3 = b2 + 1; b3 <= 25; b3++)
                for(int b4 = b3 + 1; b4 <= 25; b4++)
                    for(int b5 = b4 + 1; b5 <= 25; b5++)
                {
                    id_grupo++;
                    if(id_grupo != obter_deslocamento_5_bolas(b1, b2, b3, b4, b5)){
                        fprintf(stderr, "Erro ao gerar id pra grupo de 5 bolas.\n");
                        return false;
                    }
                    fprintf(f_temp, "\n%li;%i;%i;%i;%i;%i", id_grupo, b1, b2, b3, b4, b5);
                }

    /*

    id_grupo = 0;
    f_temp = f_lotofacil_id_grupo[6];
    for(int b1= 1; b1 <= 25; b1++)
        for(int b2 = b1 + 1; b2 <= 25; b2++)
            for(int b3 = b2 + 1; b3 <= 25; b3++)
                for(int b4 = b3 + 1; b4 <= 25; b4++)
                    for(int b5 = b4 + 1; b5 <= 25; b5++)
                        for(int b6 = b5 + 1; b6 <= 25; b6++)
                {

                    id_grupo++;
                    if(id_grupo != obter_deslocamento_6_bolas(b1, b2, b3, b4, b5, b6)){
                        fprintf(stderr, "Erro ao gerar id pra grupo de 6 bolas.\n");
                        return false;
                    }
                    fprintf(f_temp, "\n%li;%i;%i;%i;%i;%i;%i", id_grupo, b1, b2, b3, b4, b5, b6);
                }


    id_grupo = 0;
    f_temp = f_lotofacil_id_grupo[7];
    for(int b1= 1; b1 <= 25; b1++)
        for(int b2 = b1 + 1; b2 <= 25; b2++)
            for(int b3 = b2 + 1; b3 <= 25; b3++)
                for(int b4 = b3 + 1; b4 <= 25; b4++)
                    for(int b5 = b4 + 1; b5 <= 25; b5++)
                        for(int b6 = b5 + 1; b6 <= 25; b6++)
                            for(int b7 = b6 + 1; b7 <= 25; b7++)
                            {
                                id_grupo++;
                                if(id_grupo != obter_deslocamento_7_bolas(b1, b2, b3, b4, b5, b6, b7)){
                                    fprintf(stderr, "Erro ao gerar id pra grupo de 7 bolas.\n");
                                    return false;
                                }
                                fprintf(f_temp, "\n%li;%i;%i;%i;%i;%i;%i;%i", id_grupo, b1, b2, b3, b4, b5, b6, b7);
                            }


    id_grupo = 0;
    f_temp = f_lotofacil_id_grupo[8];
    for(int b1= 1; b1 <= 25; b1++)
        for(int b2 = b1 + 1; b2 <= 25; b2++)
            for(int b3 = b2 + 1; b3 <= 25; b3++)
                for(int b4 = b3 + 1; b4 <= 25; b4++)
                    for(int b5 = b4 + 1; b5 <= 25; b5++)
                        for(int b6 = b5 + 1; b6 <= 25; b6++)
                            for(int b7 = b6 + 1; b7 <= 25; b7++)
                                for(int b8 = b7 + 1; b8 <= 25; b8++)
                                {
                                    id_grupo++;
                                    if(id_grupo != obter_deslocamento_8_bolas(b1, b2, b3, b4, b5, b6, b7, b8))
                                    {
                                        fprintf(stderr, "Erro ao gerar id pra grupo de 8 bolas.\n");
                                        return false;
                                    }
                                    fprintf(f_temp, "\n%li;%i;%i;%i;%i;%i;%i;%i;%i", id_grupo, b1, b2, b3, b4, b5, b6, b7, b8);
                                }


    id_grupo = 0;
    f_temp = f_lotofacil_id_grupo[9];
    for(int b1= 1; b1 <= 25; b1++)
        for(int b2 = b1 + 1; b2 <= 25; b2++)
            for(int b3 = b2 + 1; b3 <= 25; b3++)
                for(int b4 = b3 + 1; b4 <= 25; b4++)
                    for(int b5 = b4 + 1; b5 <= 25; b5++)
                        for(int b6 = b5 + 1; b6 <= 25; b6++)
                            for(int b7 = b6 + 1; b7 <= 25; b7++)
                                for(int b8 = b7 + 1; b8 <= 25; b8++)
                                    for(int b9 = b8 + 1; b9 <= 25; b9++)
                                    {
                                        id_grupo++;
                                        if(id_grupo != obter_deslocamento_9_bolas(b1, b2, b3, b4, b5, b6, b7, b8, b9))
                                        {
                                            fprintf(stderr, "Erro ao gerar id pra grupo de 9 bolas.\n");
                                            return false;
                                        }
                                        fprintf(f_temp, "\n%li;%i;%i;%i;%i;%i;%i;%i;%i;%i", id_grupo, b1, b2, b3, b4, b5, b6, b7, b8, b9);
                                    }


    id_grupo = 0;
    f_temp = f_lotofacil_id_grupo[10];
    for(int b1= 1; b1 <= 25; b1++)
        for(int b2 = b1 + 1; b2 <= 25; b2++)
            for(int b3 = b2 + 1; b3 <= 25; b3++)
                for(int b4 = b3 + 1; b4 <= 25; b4++)
                    for(int b5 = b4 + 1; b5 <= 25; b5++)
                        for(int b6 = b5 + 1; b6 <= 25; b6++)
                            for(int b7 = b6 + 1; b7 <= 25; b7++)
                                for(int b8 = b7 + 1; b8 <= 25; b8++)
                                    for(int b9 = b8 + 1; b9 <= 25; b9++)
                                        for(int b10 = b9 + 1; b10 <= 25; b10++)
                                        {
                                            id_grupo++;
                                            if(id_grupo != obter_deslocamento_10_bolas(b1, b2, b3, b4, b5, b6, b7, b8, b9, b10))
                                            {
                                                fprintf(stderr, "Erro ao gerar id pra grupo de 10 bolas.\n");
                                                return false;
                                            }
                                            fprintf(f_temp, "\n%li;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i", id_grupo, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10);
                                        }
    */

    // Fecha os arquivos.
    for(long uA = 2; uA <= 5; uA++){
        fclose(f_lotofacil_id_grupo[uA]);
    }

    return true;
}


/*
inline bool gerar_lotofacil_grupo(long ltf_id, long ltf_qt, const long * lotofacil_bolas, FILE ** f_lotofacil_grupo){

    if(!((ltf_qt >= 15) && (ltf_qt <= 18))){
        // Retorna 1, se há erro.
        return 1;
    }

    FILE *f_arquivo = f_lotofacil_grupo[0];
    for(int uA = 1; uA <= ltf_qt; uA++){
        fprintf(f_arquivo, "\n%li;%li;%li", ltf_id, ltf_qt, lotofacil_bolas[uA]);
    }

}
*/
