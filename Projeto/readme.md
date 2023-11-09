# Cálculo Paralelo da Constante de Euler (e)

Este programa em C calcula a constante de Euler (e) usando uma abordagem paralela com a série de Taylor.

Este código usa a diretiva #pragma omp parallel for para paralelizar o loop de cálculo da série de Taylor. A cláusula reduction(*:termo) garante que a variável termo seja tratada como uma variável privada para cada thread e, ao final do loop, seja realizada a operação de multiplicação em todas as threads.

## Compilação

Certifique-se de ter um compilador C que suporte OpenMP instalado no seu sistema. O exemplo a seguir usa o GCC.

```bash
gcc -fopenmp ProjV1.c -o ProjV1

# Execução

Após compilar, você pode executar o programa da seguinte maneira:

./ProjV1

O programa irá calcular o valor de e e imprimir o resultado, bem como o tempo total necessário para o cálculo.

