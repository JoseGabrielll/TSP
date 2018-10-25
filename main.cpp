#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std; 

#define TAM 10

int TSP(int GRAFO[TAM][TAM]){ 

    vector<int> vertices; 

    for (int i = 0; i < TAM; i++){ 
        if (i != 0) 
            vertices.push_back(i); 
    }

    int caminhoMin = INT_MAX; //começa com ele extremamente alto
    
    do{  
        int pesoAtual = 0;            
        int k = 0; 

        for (int i = 0; i < vertices.size(); i++) { 
            pesoAtual += GRAFO[k][vertices[i]]; 
            k = vertices[i]; 
        } 
        pesoAtual += GRAFO[k][0]; 
  
        caminhoMin = min(caminhoMin, pesoAtual); 
         
    }while(next_permutation(vertices.begin(), vertices.end())); 
  
    return caminhoMin; 
} 

int main() 
{  
    int nElementos = 0;
    
    //LER ARQUIVO
    FILE* fp = fopen("pcv10.txt", "r");

    fscanf(fp, "%d", &nElementos);

    int matriz[TAM][TAM] = {};
    
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            fscanf(fp, "%d ", &matriz[i][j]);
        }
    }

    for(int i = 0 ; i<TAM ; i++){
        for(int j=0 ; j<TAM ; j++){
            printf("%d ", matriz[i][j]);
        }
        puts("");
    }
     

    cout << TSP(matriz) << endl;  
    return 0; 
} 
