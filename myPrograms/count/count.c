# include <stdio.h>

int main(int argc, char **argv){
  char c;
  int nDigit = 0, nWhite = 0, nOther = 0;
  while ((c = getchar()) != EOF){
    if (c == ' ' || c == '\n' || c == '\t'){
      nWhite ++;
    } else if (c >= '0' && c <= '9') {
      nDigit ++;
    } else {
      nOther ++;
    }
  }

  printf("Number of whites is: %d \n",nWhite);
  printf("Number of digits is: %d \n",nDigit);
  printf("Number of other char is: %d \n", nOther);

  return(0);
}
