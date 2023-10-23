#include <iostream>
using namespace std;

void sequencia(){

    //contador para percorrer os numeros
    int count = 0;

    //iniciando o vetor
    int n = 0;

    cout << "Digite um valor:" << endl;
    cin >> n;

    while (true){

        if (n % 3 == 1){
            n = 3*n + 1;
            cout << n << endl;
        }else{
            break;
        }

        if (n % 2 == 0){
            n = n/2;
        }else if (n == 1)
        {
            break;
        }
    }

    cout << n;



}


int main(){

    sequencia();



    return 0;
}