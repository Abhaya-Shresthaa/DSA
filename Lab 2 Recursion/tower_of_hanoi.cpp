#include <iostream>
using namespace std;

void toh (int n, char source, char aux, char destination)
{
    if (n==1)
    {
        cout << "Disk 1: " << source << "->"<< destination << endl;
        return;
    }
    else 
    {
        toh (n-1, source, destination, aux);
        cout << "Disk "<< n << ": " << source << "->" << destination << endl; //n-1 disks moved above, largest nth disk only remains to move
        toh (n-1, aux, source, destination );
        return;
    }
}

int main()
{
    int n;
    cout << "Enter the number of disks for Tower of Hanoi: ";
    cin >> n;
    cout<<endl;
    toh(n, 'A', 'B', 'C');
    return 0;  
}

