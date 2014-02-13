#include <iostream>
#include "clase.h"


GRAFO::GRAFO(char nombrefichero[]) {
	
	//cout << "1" << endl;
	ElementoLista dummy, dummy1;
	unsigned i, h, r;
	ifstream textfile(nombrefichero);
	//textfile.open(nombrefichero);
	if (textfile.is_open()) {
		//cout << "2" << endl;
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		LS.resize(n);
		//LP.resize(n);
		for (unsigned k = 0; k < m; k++) {
			//cout << "3" << endl;
			textfile >> (unsigned &) r >> (unsigned &) i >> (unsigned &) h;
			
			dummy.c = --h;
			//cout << "paso1" << endl;
			dummy.j = --i;
			//cout << "paso2" << endl;
			LS[r].push_back(dummy);
			//cout << "paso3" << endl;
			//LP[h].push_back(dummy1);
			//cout << "paso4" << endl;
			if (dirigido == 0) {
				//cout << "4" << endl;
				dummy.j = i;
				dummy1.c = h;
				LS[r].push_back(dummy);
				//LP[i].push_back(dummy1);
			}
			cout << --r << "  " << i << "  " << h << endl;
		}
	}
	
	/*cout << LS[1][0].j <<  LS[1][0].c << endl;
	 cout << LS[1][1].j <<  LS[1][1].c << endl;
	 cout << LS[1][2].j <<  LS[1][2].c << endl;
	 cout << LS[2][0].j <<  LS[2][0].c << endl;
	 cout << LS[2][1].j <<  LS[2][1].c << endl;
	 cout << LS[3][0].j <<  LS[3][0].c << endl;
	 */
	
	textfile.close();
	
}

void GRAFO::Mostrar_Grafo(int i, unsigned s, vector<unsigned> pred) {
	
	cout << pred[i] << "<--" << endl;
	
}


void GRAFO::Dijkstra() {
	
	vector<bool> PermanentementeEtiquetado; //nodo etiquetado permanentemente
	vector<int> d; //vector que guarda las distancias de el nodo inicial al resto de los nodos.
	vector<unsigned> pred;// predecesor del nodo
	unsigned s; //nodo de partida
	unsigned candidato; // candidato para ser etiquetado permanentemente
	int k = 1;
	int m, i; // subindices para mover los bucles
	int maxint = 2147483647; // este es el número llamado infinito. el máximo de los enteros. 
	
	PermanentementeEtiquetado.resize(n,false); // pone a todos los nodos como que no han sido etiquetados.
	d.resize(n, maxint); // etiqueta la distancia a todos los nodos como infinito
	pred.resize(n, UERROR); // etiqueta a todos los predecesores con UERROR
	
	//cout << d[0] << endl;
	//cout << LS[1][0].c << endl;
	
	
	
	cout << "Introduzca el nodo de partida:" << endl;
	cin >> s; //nodo de partida
	d[s]=0; // pone la distancia del nodo de partida al nodo de partida como 0
	pred[s]=s; // pone como predecesor del nodo s al mismo nodo s
	
	//cout << "1" << endl;
	
	
	do {
		candidato = UERROR;
		cout << "-----------------------------------------------------" << endl;
		cout << "candidato = 65000" << endl;
		int resultado = 2147483647;
		for (i = 0; i < sizeof LS[k][i]; i++) {
			cout << "entramos en el primer bucle for" << endl;
			
			
			if (LS[k][i].c < resultado)
			{
				if (PermanentementeEtiquetado[i] == false) {
					cout << "no está etiquetado permanentemente" << endl;
					resultado = LS[k][i].c;
					candidato = LS[k][i].j;
				}
			}
		}
		
		if (candidato != UERROR) {
			cout << "..............................................................." << endl;
			cout << "si el candidato no es UERROR " << endl;
			PermanentementeEtiquetado[candidato] = true;
			cout << "y despues de haberle puesto la etiqueta de permanentemente etiquetado " << endl;
			for (m = 0; m <= sizeof LS[candidato][m]; m++) {
				cout << "entramos en el segundo bucle for " << endl;
				if (d[m] > d[candidato] + LS[k][m].c) {
					
					d[m] = (d[candidato] + LS[k][m].c);
					pred[m] = candidato;
					cout << "iteracion: " << m << endl;
					cout << pred[m] << endl;
				}
			}
			k++;
		}
	} while (candidato != UERROR);
	for (i = 0; i < n; i++) {
		//cout << "8" << endl;
		//Mostrar_Grafo(s,i,pred);
		if (PermanentementeEtiquetado[i] == true) {
			//cout << "9" << endl;
			Mostrar_Grafo(s,i,pred);
		}
		else {
			cout << "No hay camino desde:" << s << " al nodo:" << i  << endl;
		}
	}
}





void menu() {
	cout << endl;
	cout << "1. Dijkstra" << endl;
	cout << "2. Salir" << endl;
}

int main() {
	const int rrw = 85;
	char nombrefichero[rrw];
	
	cout << "Escriba el nombre del fichero que desea cargar: ";
	cin >> nombrefichero;
	
	GRAFO grafo(nombrefichero);
	
	int opc = 0;
	
	while(opc != 2) {
		menu();
		cin >> opc;
		switch(opc) {
			case 1: 
				grafo.Dijkstra();
				break;
			case 2:
				cout << "Adios!!" << endl;
				break;
			default: 
				cout << "ERROR: Vuelva a escribir una opción correcta" << endl;
				
		}
	}
	return 0;
}




