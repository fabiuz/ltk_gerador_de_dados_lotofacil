TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lotofacil_id_trio.cpp \
    lotofacil_id_quarteto.cpp \
    lotofacil_gerador.cpp \
    lotofacil_id_par_impar.cpp \
    lotofacil_id_coluna_b.cpp \
    lotofacil_id_hrz_vrt_dg_crz.cpp \
    lotofacil_id_externo_interno.cpp \
    lotofacil_id_primo_nao_primo.cpp \
    lotofacil_diferenca_entre_bolas.cpp \
    lotofacil_soma.cpp \
    lotofacil_hash.cpp \
    lotomania.cpp \
    lotofacil_giro.cpp \
    lotofacil_deslocamento.cpp \
    lotofacil_novos_repetidos.cpp


HEADERS += \
    lotofacil_id_trio.h \
    lotofacil_id_quarteto.h \
    lotofacil_id_coluna_b.h \
    lotofacil_gerador.hpp \
    lotofacil_id_hrz_vrt_dg_crz.h \
    lotofacil_id_externo_interno.h \
    lotofacil_id_primo_nao_primo.h \
    lotofacil_id_par_impar.h \
    lotofacil_diferenca_entre_bolas.h \
    lotofacil_soma.hpp \
    lotofacil_hash.hpp \
    lotofacil_deslocamento.hpp \
    lotofacil_giro.hpp \
    lotofacil_novos_repetidos.hpp
