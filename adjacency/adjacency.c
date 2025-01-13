#include "adjacency.h"

bool path(adjmat mat, int u, int v){
  /*
  
    We will utilize a parent path approach.
    We ascend up from the lower node, because the directed graph can only go down. We then attempt to find a possible path.
  
  */
  
  int current; /* Current vertex number */
  int i; /* Loop variable */
  int foundParent; /* On each iteration, we check whether the parent was in fact found for our current vertex, if not, we exit the search. */
  
  if ((u < 0 || u >= N) || (v < 0) || (v >= N)){
    /* If either u or v are out of the matrix bounds */
    return FALSE;
  }
  
  current = v;
  while (current != u){
    foundParent = FALSE;
    
    for (i = 0; i < N; i++){
      /* Iterate through the current column, to find the parent node. */
      if (mat[i][current] == 1){
          /* This means the the ith row on our current column is the parent node. Update our current.  */
          current = i;
          foundParent = TRUE;
          break;
      }
    }
    
    if (!foundParent){
      /* If the current vertice has no existing parent, it means that we reached the top of our tree, therefore no more space to search. */
      return FALSE;
    }
    
  }
  
  /* Reaching this point means that eventually a legal traversal of our tree led us from the start (u) to (v) */
  return TRUE;
}

void printMat(adjmat mat){
  /*
  
    Receives a matrix mat and nicely prints it out with comma separation.
  
  */

  int i, j; /* Initialize current matrix indexes */
  
  for (i = 0; i < N; i++){ /* Loop across the columns */
    for (j = 0; j < N; j++){ /* Loop across the rows */
      printf("%d", mat[i][j]); /* Print the current value at i,j */
      
      if (j != N - 1){
        /* Last element of a row does not contain a comma afterwards */
        printf(",");
      }
    }
    
    printf("\n"); /* Write each row in a separate line */
  }
}

int main(){
  int i, j; /* Loop variables to input matrix */
  int u, v; /* Initialize our u,v variables */
  bool result; /* The result of the call for path */
  int readU; /* The u value read from the user */
  int readV; /* The v value read from the user */ 

  adjmat mat; /* Initialize our matrix variable */
  
  printf("Please enter the contents of the %dX%d adjacency matrix:\n", N, N); /* Instruct the user to input the matrix */
  

  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++){
      /* Iterate thourgh every i,jth element of the matrix and input it, then assign the value into the matrix cell. */
      scanf("%d", &mat[i][j]);
    }
  }
  
  printMat(mat); /* Print out the user's inputted matrix */
  printf("\n\n"); /* Create 2 new lines to separate things out */
  
  while ( !(u == -1 || v == -1 ) ){
    /*
      This loop runs as long as we don't reach a pair (-1,-1).
    */
    
    /* Scan into u,v the input values */
    printf("Please provide 2 indexes of vertices with order:\n");
    readU = scanf("%d", &u);
    readV = scanf("%d", &v);
    
    if (readU == EOF || readV == EOF){
      /* Once we meet the EOF, we exit out of our loop. */
      printf("End of file reached!");
      break;
    }
    
    /* Call path function to check if there exists a path */
    result = path(mat, u, v);
    printf("\nThe pair of indexes u=%d, v=%d %s.\n\n", u, v, (result == TRUE ? " have a direct path from u to v" : "do not have a direct path from u to v")); /* Briefly inform the user about the result. */
  }
  
  return 0;
}
