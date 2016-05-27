#include <ncurses.h>
#include "Pieza.h"
void imprimirTavlero(Pieza**);
int caracterAEntero(char);
void iniciarMatriz(Pieza**);
int main(int argc, char const *argv[]){
	initscr();
	Pieza** matriz = new Pieza*[7];
	start_color();
	iniciarMatriz(matriz);
	init_pair(1,COLOR_WHITE,COLOR_RED);
	init_pair(3,COLOR_BLACK,COLOR_RED);
	init_pair(2,COLOR_WHITE,COLOR_GREEN);
	move(2, 60);
	printw("%d", matriz[2][2].mover(1,3 , matriz));
	do{
		imprimirTavlero(matriz);
		refresh();
	}while(true);
	return 0;
}
void imprimirTavlero(Pieza** matriz){
	for(int FILA = 0; FILA < 8; FILA++){
		for(int COLUMNA = 0; COLUMNA < 8; COLUMNA++){
			int x = COLUMNA * 5;
			for(int i = 0; i < 5; i++){
				move(FILA * 5 + i, COLUMNA * 7);
				if((COLUMNA + FILA) % 2 == 0){
					attrset (COLOR_PAIR(1));
				}else{
					attrset (COLOR_PAIR(2));
				}
				if(matriz[FILA][COLUMNA].estaViva()){
					if(matriz[FILA][COLUMNA].esNegra()){
						attrset (COLOR_PAIR(3));
					}
					printw(" ***** ");
				}else{					
					printw("       ");
				}
			}
		}
	}
}
void iniciarMatriz(Pieza** matriz){
	for(int FILA = 0; FILA < 8; FILA++){
		matriz[FILA] = new Pieza[8];
		for(int COLUMNA = 0; COLUMNA < 8; COLUMNA++){
			if(FILA < 3 || FILA > 4){
				if((COLUMNA + FILA) % 2 == 0){
					matriz[FILA][COLUMNA] = Pieza(COLUMNA, FILA, FILA < 3 ? 0 : 1);
				}else{
					matriz[FILA][COLUMNA] = Pieza();
				}
			}else{
					matriz[FILA][COLUMNA] = Pieza();
				if(FILA == 3 && COLUMNA == 1){
					move(FILA + 5, COLUMNA + 60);
					printw("%d", matriz[FILA][COLUMNA].estaViva());
				}
			}
		}
	}
	
}
int caracterAEntero(char x){
	char letras[9] = "abcdefgh";
	for(int LETRA = 0; LETRA < 8; LETRA++){
		if(letras[LETRA] == x){
			return LETRA;
		}
	} 
	return -1;
}