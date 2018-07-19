#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void bubble_sort(int* numeros, int position, int n, int help)
{
  if(position == n)
  {
    return;
  }
  if(numeros[position] < numeros[position+1])
  {
    help = numeros[position];
    numeros[position] = numeros[position+1];
    numeros[position+1] = help;
  }
  position += 1;
  bubble_sort(numeros, position, n, help);

}

void sorteio(int* numeros, int digito, int position, int* sorteados, int position_2, int qntd)
{
  //printf("%d\n", numeros[position]);
  if(position == qntd)
  {
    return;
  }
  if(numeros[position] == digito)
  {
    sorteados[position_2] = numeros[position];
    //printf("\t%d %d %d\n", numeros[position], sorteados[position_2], position_2);
    position_2 += 1;
  }
  else if((numeros[position]%10) == digito)
  {
    sorteados[position_2] = numeros[position];
    position_2 += 1;
  }
  position += 1;
  sorteio(numeros, digito, position, sorteados, position_2, qntd);
}

void ler(int* numeros, int lim, int position)
{
  if(lim == 0)
  {
    return;
  }
  lim--;
  scanf("%d", &numeros[position]);
  ler(numeros, lim, position+1);
}

int main()
{
  int n, digito;
  scanf("%d", &n);
  int numeros[n];
  int sorteados[5];
  scanf("%d", &digito);
  ler(numeros, n, 0);
  sorteio(numeros, digito, 0, sorteados, 0, n);
  printf("%d %d %d", sorteados[0], sorteados[1], sorteados[2]);
	return 0;
}
