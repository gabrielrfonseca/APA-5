#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

int max(int a, int b) {
    return (a > b)? a : b;
}

int MochilaInteira(int M, int peso[], int valor[], int n) {
    int i, j;
    int K[n+1][M+1];

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= M; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (peso[i-1] <= j)
                K[i][j] = max(valor[i-1] + K[i-1][j-peso[i-1]],  K[i-1][j]);
            else
                K[i][j] = K[i-1][j];
        }
    }

return K[n][M];
}

int main(void){
    int m, n, i;
	int peso[n];
	int valor[n];
	int aux = 0;

	int ordem[1000000];
	string arquivo;

	cout << "Arquivo de teste .txt: ";
	cin >> arquivo;

	ifstream in(arquivo);
	char num[10];
	int fim = 0;
	while(!in.eof()){
		in >> num;
		ordem[fim] = atoi(num);
		fim++;
	}

	 n = ordem[0];
	 m = ordem[1];

	for(i=2; i<2*n+2; i=i+2){
		peso[aux] = ordem[i];
		valor[aux] = ordem[i+1];
		aux++;
	}

	cout << "Valor Otimo: " << MochilaInteira(m, peso, valor, n) << endl;
	return 0;

}
