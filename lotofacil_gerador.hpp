#ifndef LOTOFACIL_GERADOR_HPP
#define LOTOFACIL_GERADOR_HPP
inline bool gerar_lotofacil_num(long ltf_id, long ltf_qt, const long *const lotofacil_num, FILE *f_lotofacil_num);
inline bool gerar_lotofacil_id(long ltf_id, long ltf_qt, const long *const lotofacil_num, const long *const lotofacil_bolas,
                          FILE *f_arquivo_id);
inline bool gerar_lotofacil_bolas(long ltf_id, long ltf_qt, const long *const lotofacil_bolas, FILE *f_lotofacil_bolas);
inline bool gerar_lotofacil_num_bolas(long ltf_id,
                                      long ltf_qt,
                                      long long & ltf_seq,
                                      const long *const lotofacil_bolas,
                                      FILE *f_lotofacil_num_bolas);
inline bool gerar_lotofacil_diferenca(long ltf_id,
                                long ltf_qt,
                                const long * const lotofacil_bolas,
                                FILE * f_lotofacil_dif);

inline bool gerar_lotofacil_algarismo_na_dezena(long ltf_id,
                            long ltf_qt,
                            const long * const lotofacil_bolas,
                            FILE * f_lotofacil_);



bool gerar_par_impar_id();
bool gerar_primo_nao_primo_id();
bool gerar_externo_interno_id();
bool gerar_combinacao_com_5_bolas();
bool gerar_quarteto_id();
bool gerar_trio_id();
bool gerar_coluna_b();


#endif // LOTOFACIL_GERADOR_HPP
