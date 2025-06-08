#include<iostream>

using namespace std;

int tail_factorial (int n, int result)
{
    if (n<0){
        cerr<<"Invalid input for factorial";
        exit(1);
    }
    else if (n==0) return result;
    else return tail_factorial(n-1, n*result);

}

int main()
{
    int n;
    cout<<"Enter: ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is "<<tail_factorial(n,1)<<".";
    return 0;
}