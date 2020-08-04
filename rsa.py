import sys

#checking a prime number function
def isPrime(p):
    if p >= 2:
        for i in range(2,p):
            if not ( p % i ):
                return False
    else:
        return False
    return True

#Greatest Common Factor function
def gcf(a, b):
    min = a
    max = b
    if a > b:
        min = b
        max = a
    if (max % min == 0):
        return min
    else:
        return gcf(max % min, min)

#Getting inputs p and q from user
p = int(input('Enter p: '))
q = int(input('Enter q: '))

#if both are prime, enter the condition
if isPrime(p) and isPrime(q):

    #getting product n from values p and q
    n = p * q
    print('Product n = ', n)

    #totient value
    phiN = (p - 1) * (q - 1)
    print('Totient = ', phiN)

    #printing out the possible values of e from the given totient and putting in lst
    lst = []
    for i in range(2, phiN):
        if gcf(i, phiN) == 1:
            lst.append(i)
            
    print('Possible values of e from ', phiN, ': ')
    print('Values: ', lst)
    print('\n')
    e = int(input('Choose from one of them: '))

    if e in lst:
        print('You have chosen ', e)
    else:
        print('Inputted e is not in the list...')
        sys.exit()

    #finding d
    d = 1
    while(1):
        if (d % e) % phiN == 1:
            break
        d = d + 1


    #Details
    print('Details: ')
    print('p = ', p)
    print('q = ', q)
    print('n = ', n)
    print('Totient = ', phiN)
    print('e = ', e)
    print('d = ', d)

    print('Public Key: {',e,',', n,'}')
    print('Private Key: {',d,',', n,'}')

else:
    print('Either or neither values inputted are primes')
    sys.exit()
