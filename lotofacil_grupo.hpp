#ifndef LOTOFACIL_GRUPO_HPP
#define LOTOFACIL_GRUPO_HPP

#endif // LOTOFACIL_GRUPO_HPP

#include <cstdio>

/*
 *  No código abaixo, há vários parâmetros, ao invés disto, irei passar um arranjo com todas as bolas,
 * neste caso, o código fica com mais desempenho.
 *
 *
long obter_id_grupo_2_bolas(long b1, long b2);
long obter_id_grupo_3_bolas(long b1, long b2, long b3);
long obter_id_grupo_4_bolas(long b1, long b2, long b3, long b4);
long obter_id_grupo_5_bolas(long b1, long b2, long b3, long b4, long b5);
long obter_id_grupo_6_bolas(long b1, long b2, long b3, long b4, long b5, long b6);
long obter_id_grupo_7_bolas(long b1, long b2, long b3, long b4, long b5, long b6, long b7);
long obter_id_grupo_8_bolas(long b1, long b2, long b2, long b2, long b2, long b2, long b2, long b2);
long obter_id_grupo_9_bolas(long b1, long b2, long b2, long b2, long b2, long b2, long b2, long b2, long b2);
long obter_id_grupo_10_bolas(long b1, long b2, long b2, long b2, long b2, long b2, long b2, long b2, long b2, long b2);
*/

long obter_id_grupo_2_bolas(const long * bolas);
long obter_id_grupo_3_bolas(const long * bolas);
long obter_id_grupo_4_bolas(const long * bolas);
long obter_id_grupo_5_bolas(const long * bolas);
long obter_id_grupo_6_bolas(const long * bolas);
long obter_id_grupo_7_bolas(const long * bolas);
long obter_id_grupo_8_bolas(const long * bolas);
long obter_id_grupo_9_bolas(const long * bolas);
long obter_id_grupo_10_bolas(const long * bolas);

bool gerar_grupo_id();

inline bool gerar_lotofacil_grupo(long ltf_id, long ltf_qt, const long * lotofacil_bolas, FILE ** f_lotofacil_grupo){

    if(!((ltf_qt >= 15) && (ltf_qt <= 18))){
        // Retorna 1, se há erro.
        return 1;
    }

    FILE *f_arquivo = f_lotofacil_grupo[0];
    long bolas[11];     // Será usado os índices de 1 a 10.

    f_arquivo = f_lotofacil_grupo[2];
    for(long b1 = 1; b1 <= ltf_qt; b1++){
        for(long b2 = b1 + 1; b2 <= ltf_qt; b2++){
            bolas[0] = 0;
            bolas[1] = lotofacil_bolas[b1];
            bolas[2] = lotofacil_bolas[b2];
            long id_grupo = obter_id_grupo_2_bolas(bolas);

            fprintf(f_arquivo, "\n%li;%li;%li", ltf_id, ltf_qt, id_grupo);
        }
    }

    f_arquivo = f_lotofacil_grupo[3];
    for(long b1 = 1; b1 <= ltf_qt; b1++){
        for(long b2 = b1 + 1; b2 <= ltf_qt; b2++){
            for(long b3 = b2 + 1; b3 <= ltf_qt; b3++){
                bolas[0] = 0;
                bolas[1] = lotofacil_bolas[b1];
                bolas[2] = lotofacil_bolas[b2];
                bolas[3] = lotofacil_bolas[b3];
                long id_grupo = obter_id_grupo_3_bolas(bolas);
                fprintf(f_arquivo, "\n%li;%li;%li", ltf_id, ltf_qt, id_grupo);
            }
        }
    }

    /*
    f_arquivo = f_lotofacil_grupo[4];
    for(long b1 = 1; b1 <= ltf_qt; b1++){
        for(long b2 = b1 + 1; b2 <= ltf_qt; b2++){
            for(long b3 = b2 + 1; b3 <= ltf_qt; b3++){
                for(long b4 = b3 + 1; b4 <= ltf_qt; b4++){
                    bolas[0] = 0;
                    bolas[1] = lotofacil_bolas[b1];
                    bolas[2] = lotofacil_bolas[b2];
                    bolas[3] = lotofacil_bolas[b3];
                    bolas[4] = lotofacil_bolas[b4];
                    long id_grupo = obter_id_grupo_4_bolas(bolas);
                    fprintf(f_arquivo, "\n%li;%li;%li", ltf_id, ltf_qt, id_grupo);
                }
            }
        }
    }

    f_arquivo = f_lotofacil_grupo[5];
    for(long b1 = 1; b1 <= ltf_qt; b1++){
        for(long b2 = b1 + 1; b2 <= ltf_qt; b2++){
            for(long b3 = b2 + 1; b3 <= ltf_qt; b3++){
                for(long b4 = b3 + 1; b4 <= ltf_qt; b4++){
                    for(long b5 = b4 + 1; b5 <= ltf_qt; b5++){
                        bolas[0] = 0;
                        bolas[1] = lotofacil_bolas[b1];
                        bolas[2] = lotofacil_bolas[b2];
                        bolas[3] = lotofacil_bolas[b3];
                        bolas[4] = lotofacil_bolas[b4];
                        bolas[5] = lotofacil_bolas[b5];
                        long id_grupo = obter_id_grupo_5_bolas(bolas);
                        fprintf(f_arquivo, "\n%li;%li;%li", ltf_id, ltf_qt, id_grupo);
                    }
                }
            }
        }
    }
    */



    // Não iremos utilizar o código abaixo, pois, o arquivo *.csv é muito grande e
    // também acho desnecessário.

    /*
    f_arquivo = f_lotofacil_grupo[6];
    for(long b1 = 1; b1 <= ltf_qt; b1++){
        for(long b2 = b1 + 1; b2 <= ltf_qt; b2++){
            for(long b3 = b2 + 1; b3 <= ltf_qt; b3++){
                for(long b4 = b3 + 1; b4 <= ltf_qt; b4++){
                    for(long b5 = b4 + 1; b5 <= ltf_qt; b5++)
                        for(long b6 = b5 + 1; b6 <= ltf_qt; b6++)
                            {
                                bolas[0] = 0;
                                bolas[1] = lotofacil_bolas[b1];
                                bolas[2] = lotofacil_bolas[b2];
                                bolas[3] = lotofacil_bolas[b3];
                                bolas[4] = lotofacil_bolas[b4];
                                bolas[5] = lotofacil_bolas[b5];
                                bolas[6] = lotofacil_bolas[b6];
                                long id_grupo = obter_id_grupo_6_bolas(bolas);
                                fprintf(f_arquivo, "\n%li;%li;%li", ltf_id, ltf_qt, id_grupo);
                            }
                }
            }
        }
    }

    f_arquivo = f_lotofacil_grupo[7];
    for(long b1 = 1; b1 <= ltf_qt; b1++){
        for(long b2 = b1 + 1; b2 <= ltf_qt; b2++){
            for(long b3 = b2 + 1; b3 <= ltf_qt; b3++){
                for(long b4 = b3 + 1; b4 <= ltf_qt; b4++){
                    for(long b5 = b4 + 1; b5 <= ltf_qt; b5++){
                        for(long b6 = b5 + 1; b6 <= ltf_qt; b6++){
                            for(long b7 = b6 + 1; b7 <= ltf_qt; b7++)
                            {
                                bolas[0] = 0;
                                bolas[1] = lotofacil_bolas[b1];
                                bolas[2] = lotofacil_bolas[b2];
                                bolas[3] = lotofacil_bolas[b3];
                                bolas[4] = lotofacil_bolas[b4];
                                bolas[5] = lotofacil_bolas[b5];
                                bolas[6] = lotofacil_bolas[b6];
                                bolas[7] = lotofacil_bolas[b7];
                                long id_grupo = obter_id_grupo_7_bolas(bolas);
                                fprintf(f_arquivo, "\n%li;%li;%li", ltf_id, ltf_qt, id_grupo);
                            }
                        }
                    }
                }
            }
        }
    }

    f_arquivo = f_lotofacil_grupo[8];
    for(long b1 = 1; b1 <= ltf_qt; b1++){
        for(long b2 = b1 + 1; b2 <= ltf_qt; b2++){
            for(long b3 = b2 + 1; b3 <= ltf_qt; b3++){
                for(long b4 = b3 + 1; b4 <= ltf_qt; b4++){
                    for(long b5 = b4 + 1; b5 <= ltf_qt; b5++){
                        for(long b6 = b5 + 1; b6 <= ltf_qt; b6++){
                            for(long b7 = b6 + 1; b7 <= ltf_qt; b7++)
                                for(long b8 = b7 + 1; b8 <= ltf_qt; b8++)
                            {
                                bolas[0] = 0;
                                bolas[1] = lotofacil_bolas[b1];
                                bolas[2] = lotofacil_bolas[b2];
                                bolas[3] = lotofacil_bolas[b3];
                                bolas[4] = lotofacil_bolas[b4];
                                bolas[5] = lotofacil_bolas[b5];
                                bolas[6] = lotofacil_bolas[b6];
                                bolas[7] = lotofacil_bolas[b7];
                                bolas[8] = lotofacil_bolas[b8];
                                long id_grupo = obter_id_grupo_8_bolas(bolas);
                                fprintf(f_arquivo, "\n%li;%li;%li", ltf_id, ltf_qt, id_grupo);
                            }
                        }
                    }
                }
            }
        }
    }

    f_arquivo = f_lotofacil_grupo[9];
    for(long b1 = 1; b1 <= ltf_qt; b1++){
        for(long b2 = b1 + 1; b2 <= ltf_qt; b2++){
            for(long b3 = b2 + 1; b3 <= ltf_qt; b3++){
                for(long b4 = b3 + 1; b4 <= ltf_qt; b4++){
                    for(long b5 = b4 + 1; b5 <= ltf_qt; b5++){
                        for(long b6 = b5 + 1; b6 <= ltf_qt; b6++){
                            for(long b7 = b6 + 1; b7 <= ltf_qt; b7++){
                                for(long b8 = b7 + 1; b8 <= ltf_qt; b8++){
                                    for(long b9 = b8 + 1; b9 <= ltf_qt; b9++)
                                    {
                                        bolas[0] = 0;
                                        bolas[1] = lotofacil_bolas[b1];
                                        bolas[2] = lotofacil_bolas[b2];
                                        bolas[3] = lotofacil_bolas[b3];
                                        bolas[4] = lotofacil_bolas[b4];
                                        bolas[5] = lotofacil_bolas[b5];
                                        bolas[6] = lotofacil_bolas[b6];
                                        bolas[7] = lotofacil_bolas[b7];
                                        bolas[8] = lotofacil_bolas[b8];
                                        bolas[9] = lotofacil_bolas[b9];
                                        long id_grupo = obter_id_grupo_9_bolas(bolas);
                                        fprintf(f_arquivo, "\n%li;%li;%li", ltf_id, ltf_qt, id_grupo);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    f_arquivo = f_lotofacil_grupo[10];
    for(long b1 = 1; b1 <= ltf_qt; b1++){
        for(long b2 = b1 + 1; b2 <= ltf_qt; b2++){
            for(long b3 = b2 + 1; b3 <= ltf_qt; b3++){
                for(long b4 = b3 + 1; b4 <= ltf_qt; b4++){
                    for(long b5 = b4 + 1; b5 <= ltf_qt; b5++){
                        for(long b6 = b5 + 1; b6 <= ltf_qt; b6++){
                            for(long b7 = b6 + 1; b7 <= ltf_qt; b7++){
                                for(long b8 = b7 + 1; b8 <= ltf_qt; b8++){
                                    for(long b9 = b8 + 1; b9 <= ltf_qt; b9++)
                                        for(long b10 = b9 + 1; b10 <= ltf_qt; b10++)
                                    {
                                        bolas[0] = 0;
                                        bolas[1] = lotofacil_bolas[b1];
                                        bolas[2] = lotofacil_bolas[b2];
                                        bolas[3] = lotofacil_bolas[b3];
                                        bolas[4] = lotofacil_bolas[b4];
                                        bolas[5] = lotofacil_bolas[b5];
                                        bolas[6] = lotofacil_bolas[b6];
                                        bolas[7] = lotofacil_bolas[b7];
                                        bolas[8] = lotofacil_bolas[b8];
                                        bolas[9] = lotofacil_bolas[b9];
                                        long id_grupo = obter_id_grupo_10_bolas(bolas);
                                        fprintf(f_arquivo, "\n%li;%li;%li", ltf_id, ltf_qt, id_grupo);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    */

    return true;

}



