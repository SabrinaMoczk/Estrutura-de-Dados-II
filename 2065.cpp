/* Nome: Sabrina Moczulski
Disclina: Estruturas de Dados II
Matrícula: 1611100045
Email: sabrina.moczulski@gmail.com */

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

#define MAX 11234

typedef pair < int , int > caixa;

int cli[MAX], cx[MAX];

int main(void){
	int i, n, m, ans = 0;
	priority_queue <  caixa, vector < caixa >, greater< caixa > > pq;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++){
		scanf("%d", &cx[i]);
	}
	for(i = 0; i < m; i++)
		scanf("%d", &cli[i]);
	for(i = 0; cx[i]; i++)
		pq.push(caixa(cx[i] * cli[i], i));
	while(!pq.empty()){
		ans = pq.top().first;
		n = pq.top().second;
		pq.pop();
		if(cli[i]){
			pq.push(caixa(cx[n] * cli[i++] + ans, n));
		}
	}
	printf("%d\n", ans);
	return 0;
}
