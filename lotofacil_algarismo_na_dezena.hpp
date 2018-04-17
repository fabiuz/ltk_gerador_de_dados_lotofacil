#ifndef LOTOFACIL_ALGARISMO_NA_DEZENA_HPP
#define LOTOFACIL_ALGARISMO_NA_DEZENA_HPP

// Armazena o identificador da quantidade de bolas
// De 1 a 9, há 9 bolas
// de 10 a 19, há 10 bolas
// de 20 a 25, há 6 bolas
static long algarismo_na_dezena_id[10][11][7];
#endif // LOTOFACIL_ALGARISMO_NA_DEZENA_HPP

bool gerar_algarismo_na_dezena_id();
long obter_algarismo_na_dezena_id(long qt_dezena_0, long qt_dezena_1, long qt_dezena_2);
inline bool obter_lotofacil_qt_dezenas(long ltf_id,
                                      long ltf_qt,
                                      const long * const lotofacil_bolas,
                                      long * qt_dz_0,
                                      long * qt_dz_1,
                                      long * qt_dz_2);

