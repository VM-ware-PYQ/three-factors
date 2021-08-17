/*
Simple approach is to count factors by generating all divisors of a number by using this approach, after that check whether 
the count of all factors are equal to ‘3’ or not. 
Time complexity of this approach is O(sqrt(n)). 


Better approach is to use Number theory. According to property of perfect square, “Every perfect square(x2) always have only 
odd numbers of factors“. 

If the square root of given number(say x2) is prime(after conforming that number is perfect square) then it must have exactly 
three distinct factors i.e., 

>> A number 1 of course.
>> Square root of a number i.e., x(prime number).
>> Number itself i.e., x2.


*/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}

bool isThreeDisctFactors(long long n)
{
    // Find square root of number
    int sq = (int)sqrt(n);
 
    // Check whether number is perfect
    // square or not
    
    /*
	1LL and 2LL simply means the numbers 1 or 2 saved using at least 64 bits. It's called a long long integer.
	*/
	
    if (1LL * sq * sq != n)
        return false;
 
    // If number is perfect square, check
    // whether square root is prime or
    // not
    return isPrime(sq) ? true : false;
}


// Driver program
int main()
{
    long long num = 9;
    if (isThreeDisctFactors(num))
        cout << "Yes\n";
    else
        cout << "No\n";
 
    num = 15;
    if (isThreeDisctFactors(num))
        cout << "Yes\n";
    else
        cout << "No\n";
 
    num = 12397923568441;
    if (isThreeDisctFactors(num))
        cout << "Yes\n";
    else
        cout << "No\n";
 
    return 0;
}
