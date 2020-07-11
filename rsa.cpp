#include <iostream>
using namespace std;

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

int isPrime (int p, int q)
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
  cout << "Enter p and q: ";
  cin >> p >> q;

  if (isPrime (p, q))
    {
      n = p * q;
      cout << "Product n (n = p * q) = " << n << endl;

      //finding phi(n)
      phiN = (p - 1) * (q - 1);
      cout << "phi(n) = " << phiN << endl;

      //finding possible values of e where 1 < e < phiN
      cout << "Possible values of e from " << phiN << endl;
      for (int i = 2; i < phiN; i++)
	{
	  if (hcf (i, phiN) == 1)
	    cout << i << " ";
	}

      //Choosing e from the list
      cout << endl << "Choose one from them: ";
      cin >> e;
      cout << "You have chosen " << e << endl;


      //Finding d
      d = 1;
      while (1)
	{
	  if ((d * e) % phiN == 1)
	    {
	      break;
	    }
	  d += 1;
	}
      cout << endl << "Details: " << endl << "p = " << p << endl << "q = " << q << endl
      << "n = " << n << endl << "phiN = " << phiN << endl << "e = " << e << endl
      << "d = " << d << endl;
      cout << endl;
      cout << "Public Key: {" << e << ", " << n <<"}" << endl;
      cout << "Private Key: {" << d << ", " << n <<"}" << endl;
    }
  else if (!isPrime(p, q))
    {
      cout << "Either or neither p and q are prime." << endl;
    }
  return 0;
}
