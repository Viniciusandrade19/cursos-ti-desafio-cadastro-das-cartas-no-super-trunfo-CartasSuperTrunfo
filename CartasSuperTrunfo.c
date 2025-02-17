#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NUM_PAISES 2
#define NUM_ESTADOS 4
#define CIDADES_POR_ESTADO 2

// Estrutura para representar uma cidade
struct Cidade {
    char codigo[4];  // Código da carta (Ex: A01, B02)
    char nome[50];
    int populacao;
    int area;
    int pib;
    int pontos_turisticos;
};

// Estrutura para representar um estado
struct Estado {
    char letra;
    char nome[50];
    struct Cidade cidades[CIDADES_POR_ESTADO];
    int populacao_total;
    int area_total;
    int pib_total;
    int pontos_turisticos_total;
};

// Estrutura para representar um país
struct Pais {
    char nome[50];
    struct Estado estados[NUM_ESTADOS];
    int populacao_total;
    int area_total;
    int pib_total;
    int pontos_turisticos_total;
};

// Função para exibir uma cidade
void exibir_cidade(const struct Cidade* cidade) {
    printf("  📍 Cidade %s - %s\n", cidade->codigo, cidade->nome);
    printf("    - População: %d\n", cidade->populacao);
    printf("    - Área: %d km²\n", cidade->area);
    printf("    - PIB: %d milhões\n", cidade->pib);
    printf("    - Pontos turísticos: %d\n\n", cidade->pontos_turisticos);
}

// Função para exibir um estado
void exibir_estado(const struct Estado* estado) {
    printf("\n🌎 Estado %c - %s\n", estado->letra, estado->nome);
    printf("  - População Total: %d\n", estado->populacao_total);
    printf("  - Área Total: %d km²\n", estado->area_total);
    printf("  - PIB Total: %d milhões\n", estado->pib_total);
    printf("  - Pontos turísticos: %d\n", estado->pontos_turisticos_total);

    for (int i = 0; i < CIDADES_POR_ESTADO; i++) {
        exibir_cidade(&estado->cidades[i]);
    }
}

// Função para exibir um país
void exibir_pais(const struct Pais* pais) {
    printf("\n🌍 País: %s\n", pais->nome);
    printf("  - População Total: %d\n", pais->populacao_total);
    printf("  - Área Total: %d km²\n", pais->area_total);
    printf("  - PIB Total: %d milhões\n", pais->pib_total);
    printf("  - Total de Pontos Turísticos: %d\n", pais->pontos_turisticos_total);

    for (int i = 0; i < NUM_ESTADOS; i++) {
        exibir_estado(&pais->estados[i]);
    }
}

#ifdef __cplusplus
}
#endif

int main() {
    // Criando os países com estados e cidades
    struct Pais paises[NUM_PAISES] = {
        {
            "Brasil",
            {
                {'A', "São Paulo", {{"A01", "São Paulo", 12300000, 1521, 850000, 25}, {"A02", "Campinas", 1100000, 795, 150000, 10}}, 13400000, 2316, 1000000, 35},
                {'B', "Rio de Janeiro", {{"B01", "Rio de Janeiro", 6750000, 1182, 400000, 50}, {"B02", "Niterói", 500000, 130, 80000, 15}}, 7250000, 1312, 480000, 65},
                {'C', "Minas Gerais", {{"C01", "Belo Horizonte", 2500000, 331, 200000, 20}, {"C02", "Uberlândia", 700000, 411, 90000, 8}}, 3200000, 742, 290000, 28},
                {'D', "Bahia", {{"D01", "Salvador", 2880000, 693, 150000, 30}, {"D02", "Feira de Santana", 620000, 132, 60000, 12}}, 3500000, 825, 210000, 42}
            },
            27350000, 5195, 1980000, 170
        },
        {
            "Estados Unidos",
            {
                {'E', "Califórnia", {{"E01", "Los Angeles", 3900000, 1302, 1200000, 30}, {"E02", "San Diego", 1400000, 842, 600000, 15}}, 5300000, 2144, 1800000, 45},
                {'F', "Texas", {{"F01", "Houston", 2300000, 1625, 1000000, 25}, {"F02", "Dallas", 1340000, 887, 700000, 20}}, 3640000, 2512, 1700000, 45},
                {'G', "Flórida", {{"G01", "Miami", 470000, 143, 500000, 20}, {"G02", "Orlando", 300000, 294, 300000, 30}}, 770000, 437, 800000, 50},
                {'H', "Nova York", {{"H01", "Nova York", 8410000, 783, 1600000, 50}, {"H02", "Buffalo", 256000, 135, 200000, 10}}, 8666000, 918, 1800000, 60}
            },
            18396000, 6011, 7100000, 200
        }
    };

    // Exibir os países com suas informações
    for (int i = 0; i < NUM_PAISES; i++) {
        exibir_pais(&paises[i]);
    }

    return 0;
}
