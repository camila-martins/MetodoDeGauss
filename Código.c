//Tarefa 3 - Métodos Numéricos II
#include <stdio.h>
#include<math.h>
#include<stdlib.h>

FILE *fp;
double **ler(char *matriz, int *dim)
{
  int i, j, a;
  double **M;
  fp=fopen(matriz, "r");
  i=fscanf(fp, "%d\t", dim);
  M=malloc(*dim *sizeof(double*));
  for(i=0; i<*dim; i++)
  {
    M[i]=malloc((*dim+1)*sizeof(double));
  }
  i=0;
  j=0;
  
  while(fscanf(fp, "%d", &a)!=EOF)
  {
    M[i][j]=a;
    j++;
    if(j== *dim+1)
    {
      j=0;
      j++;
    }
  }
  return (M);
}

void imprime(double **M, int dim)
{
  int i, j;
  printf("\n");
  for(i=0;i<dim+1;i++)
  {
    for(j=0; j<dim+1; j++)
    {
      printf("%3g\t", M[i][j]);
    }
    puts("");
  }
}
double **triangsup(double **M, int dim)
{
  int i, j, k, l;
  double N;
  for(k=0; k<dim+1; k++)
  {
    for(i=k+1; i<dim; i++)
    {
      N=M[i][k]/M[k][k];
      for(j=0; j<dim+1; j++)
      {
        M[i][j]=N[i][j]-(N*M[k][j]);
      }
    }
  }
  return (M);
}
 
int main (int argc , char ** argv )
{
  double ** M;
  double * raizes ;
  int i , dim ;

  printf("\nMatriz lida no arquivo Matriz.dat:\n");
  M= ler ( argv [1] ,& dim );
  imprime (M , dim ) ;
  
  printf("\n Matriz triangularizada:\n");
  triangsup (M , dim ) ;
  imprime (M , dim ) ;
  
  
  raizes = malloc ( dim * sizeof ( double ) );
  subsreversa (M , raizes , dim );
  for ( i =0; i < dim ; i ++) 
    printf ("x%1d = %5.2 lf\n",i , raizes [ i]) ;
  return 0;
  }
