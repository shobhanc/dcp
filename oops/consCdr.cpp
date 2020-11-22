/*
 *
 * cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair.
 * For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.
 *
 * Given this implementation of cons:
 *
 * def cons(a, b):
 *    def pair(f):
 *       return f(a, b)
 *    return pair
 * Implement car and cdr.
 */

#include <iostream>

using namespace std;

class Pair{
	public:
		int first;
		int last;
		Pair(int theA, int theB){
			first=theA;
			last=theB;
		}
};

class Program{
	public:
		Pair* cons(int a, int b){
			return new Pair(a,b);
		}

		int car(Pair *p){
			return p->first;
		}

		int cdr(Pair *p){
			return p->last;
		}
};

int main(int argc, char* argv[]){
	Program p;
	Pair *pr = p.cons(3,4);
	cout<<"first="<<p.car(pr)<<endl;
	cout<<"last="<<p.cdr(pr)<<endl;
	return 0;
}
