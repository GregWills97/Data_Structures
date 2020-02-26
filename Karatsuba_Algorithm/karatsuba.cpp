/* Karatsuba multiplication */
#include <iostream>
#include <cmath>


using namespace std;

int numDigits(int num);
int pow10(int n);



int karatsuba(int x, int y) {
    	
    int digX = numDigits(x);
    int digY = numDigits(y);
    int n, a, b, c, d;
    int c1, c2, c3;

    //base case
    if(numDigits(x) && numDigits(y) == 1){
	return x*y;
    }
    
    else{
	
	if(digX > digY){
	    n = digX;
	}
	else if(digY > digX){	//sets the n to the input with highest amount of digits
	    n = digY;
	}
	else{
	    n = digX;
	}

	
	if(n % 2 != 0){
	    n -= 1;		//if n is odd subtracts one
	}
	
	a = x / pow10(n/2);
	b = x % pow10(n/2);
	c = y / pow10(n/2);	//sets abcd
	d = y % pow10(n/2);

	c1 = karatsuba(a, c);
	c2 = karatsuba(b, d);				//the three recursive calls
	c3 = karatsuba(a + b, c + d) - c1 - c2;

	return (pow10(n) * c1) + (pow10(n/2) * c3) + c2;  //result
    }    
}

// Helper function - returns number of digits
int numDigits(int num) {

    if(num < 0){
	num *= -1;
    }
    int dig = 0;
    do{
	num /= 10;
	dig ++;
    }while(num > 0);
    return dig;
}

// Helper function - integer exponentiation
int pow10(int n) {
    if(n == 0){
	return 1;
    }else if (n < 0){
	return -1;
    }
    else{
	return 10 * pow10(n-1);
    }
}





