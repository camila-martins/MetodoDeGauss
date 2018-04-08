//Tarefa 3 - Métodos Numéricos II
#include <stdio.h>
#include<math.h>
#include<stdlib.h>

FILE *fp;
double **ler(char *matriz, int *dim)
{
  int i, j, a;
  double **M;
  fp=fopen("Matriz.dat", "r");
  i=fscanf(fp, "%d\t", dim);
  M=malloc(*dim*sizeof(double*));
  for(i=0; i<*dim; i++)
  {
    M[i]=malloc((*dim+1)*sizeof(double));
  }
  i=j=0;
  
  while(fscanf(fp, "%d\t", &a)!=EOF)
  {
    M[i][j]=a;
    j++;
    if(j==*dim+1)
    {
      j=0;
      j++;
    }
  }
  return (M);
}

int main (int argc , char ** argv )
{
  double ** M;
  double * raizes ;
  int i , dim ;

  M= ler ( argv [1] ,& dim );
  imprime (M , dim ) ;
  triangsup (M , dim ) ;
  imprime (M , dim ) ;  
  raizes = malloc ( dim * sizeof ( double ) );
  subsreversa (M , raizes , dim );
  for ( i =0; i < dim ; i ++) 
    printf ("x%1d = %5.2 lf\n",i , raizes [ i]) ;
  return 0;
  }
