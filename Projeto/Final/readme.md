# Cálculo Paralelo da Constante de Euler (e)

Este programa em C calcula a constante de Euler (e) usando uma abordagem paralela com a série de Taylor.

Este código usa a diretiva #pragma omp parallel for para paralelizar o loop de cálculo da série de Taylor. A cláusula reduction(*:termo) garante que a variável termo seja tratada como uma variável privada para cada thread e, ao final do loop, seja realizada a operação de multiplicação em todas as threads.

Nessa versão final, as principais alterações foram:

Usei a cláusula 'reduction' para as variáveis 'e' e 'termo'. Isso é útil para evitar condições de corrida e permite que o OpenMP realize eficientemente as operações de redução.

Removi a inclusão desnecessária da biblioteca '<stdlib.h>', pois não está sendo utilizada.

Usei a cláusula 'reduction(+:e)' para somar os termos da série e 'reduction(*:termo)' para multiplicar os termos. Isso elimina a necessidade de atualizações atômicas ou outros mecanismos de sincronização para garantir a consistência dos resultados parciais em um ambiente paralelo.

Substituí o número de threads pelo valor padrão, permitindo que o OpenMP escolha o número de threads com base nas configurações do ambiente.

Note que a eficiência real dependerá do hardware e do número de núcleos disponíveis na máquina. Experimente diferentes valores de n e ajuste o número de threads conforme necessário para otimizar o desempenho.

## Compilação

Certifique-se de ter um compilador C que suporte OpenMP instalado no seu sistema. O exemplo a seguir usa o GCC.

```bash
gcc -fopenmp ProjV1.c -o ProjV1

# Execução

Após compilar, você pode executar o programa da seguinte maneira:

./ProjV1

O programa irá calcular o valor de e e imprimir o resultado, bem como o tempo total necessário para o cálculo.


## RESULTADOS

Valores com n = 1000000
O valor de e alcançado foi e = 2,718303
E o tempo de para isso foi T = 0,012268 segundos

Valores com n = 1000000000
O valor de e alcançado foi e = 2,718282
E o tempo de para isso foi T = 5,275209 segundos
