//Tarefa 3 - Métodos Numéricos II
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
