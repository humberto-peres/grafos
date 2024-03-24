# Implementação do Algoritmo de Dijkstra em C

Este repositório contém uma implementação do algoritmo de Dijkstra em C, juntamente com uma estrutura de dados simples para representar grafos. O algoritmo de Dijkstra é utilizado para encontrar o caminho mais curto entre dois vértices em um grafo com pesos de arestas não negativos.

## Uso
### Para utilizar esta implementação, siga estes passos:

1. Compile o código usando um compilador C, como o GCC:

```
gcc dijkstra.c -o dijkstra
```

2. Execute o executável compilado:

```
./dijkstra
```
3. Insira os vértices de origem e destino quando solicitado. O programa calculará e exibirá o caminho mais curto entre os vértices especificados.

## Como Funciona
O programa cria um grafo usando uma representação de lista de adjacências. Em seguida, solicita ao usuário para inserir os vértices de origem e destino. O algoritmo de Dijkstra é então aplicado para encontrar o caminho mais curto entre os vértices especificados. O caminho mais curto é impresso no console.

## Sobre o Algoritmo de Dijkstra
O algoritmo de Dijkstra é um algoritmo de busca em grafos que resolve o problema do caminho mais curto a partir de uma única origem em um grafo com pesos de arestas não negativos. Ele opera selecionando iterativamente o vértice com a menor distância a partir do vértice de origem e atualizando as distâncias para seus vértices adjacentes. Esse processo continua até que todos os vértices tenham sido visitados ou o vértice de destino seja alcançado.
