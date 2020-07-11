#include <stdio.h>
#include <stdbool.h>
int hcf (int a, int b)
{
  //first we find the maximum and minimum in a and b
  int min = a, max = b;
  if (a > b)
    {				//if a>b then min != a and max != b so we change them for this case
      min = b;
      max = a;
    }
  //if the min of the number divides the max then the min is hcf,
  //else their hcf is the hcf of the remainder found when max is divided by min and the min in the two numbers
  return (max % min == 0) ? min : hcf (max % min, min);
}

int isPrime(int p, int q) 
{
  if (p <= 1 || q <= 1)
    return false;
  if (p == 2 || q == 2)
    return true;
  if ((p > 2 && p % 2 == 0) || (q > 2 && q % 2 == 0))
    return false;
}

int main ()
{
  int p, q, n, phiN, e, d;
  //formula: e*d % phi_n = 1

  //finding n from p and q
  printf ("Enter p and q: ");
  scanf ("%d %d", &p, &q);
  
  if (isPrime(p, q)) {
    n = p * q;
    printf ("Product n (n = p * q) = %d\n", n);

    //finding phi(n)
    phiN = (p - 1) * (q - 1);
    printf ("phi(n) = %d\n", phiN);

    //finding possible values of e where 1 < e < phiN
    printf ("Possible values of e from %d:\n ", phiN);
    for (int i = 2; i < phiN; i++) 
    {
        if (hcf (i, phiN) == 1)
	    printf ("%d ", i);
    }

    //Choosing e from the list
    printf ("\nChoose one from them: ");
    scanf ("%d", &e);
    printf ("You have chosen %d\n", e);


    //Finding d
    d = 1;
    while (1) {
        if ((d * e) % phiN == 1){
	    break;
        }
        d += 1;
     }
        printf ("\nDetails: \np = %d\nq = %d\nn = %d\nphi(n) = %d\ne = %d\nd = %d\n", p, q, n,
	    phiN, e, d);
	    printf("\nPublic Key: {%d, %d}\n", e, n);
	    printf("Private Key: {%d, %d}\n", d, n);
  }
  else if(!isPrime(p, q)){
      printf("Either or neither p and q are prime.\n");
  }
  return 0;
}
