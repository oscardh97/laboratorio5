#include "Pieza.h"
#include<string>

using std::string;

Pieza::Pieza(){
	General=false;
}

Pieza::Pieza(int x,int y,bool color){
	this->x=x;
	this->y=y;
	this->General=false;
	this->Negra=color;
}
bool Pieza::esGeneral(){
	return this->General;
}

bool Pieza::esNegra(){
	return this->Negra;
}

int Pieza::getX(){
	return this->x;
}

int Pieza::getY(){
	return this->y;
}

void Pieza::setX(int x){
	this->x=x;
}

void Pieza::setY(int y){
	this->y=y;
}

bool Pieza::mover(int x,int y,Pieza** matriz){
	if(!Negra&&!General){
		if(x>=8||y>=8||x<0||y<0){
			return false;
		}else if(this->x==x&&this->y==y){
			return false;
		}else if( (x==this->x+1||x==this->x-1)&&(y==this->y+1)&&matriz[y][x]==NULL){
			return true;
		}else if( (x==this->x+2&&y==this->y+2&&!matriz[this->y+1][this->x+1].esNegra()&&matriz[y][x]==NULL)||(x==this->x-2&&y==this->y+2&&!matriz[this->y-1][this->x+1].esNegra()&&matriz[y][x]==NULL)){
			return true;
		}else{
			return false;
		}
	}else if(Negra&&!General){
		if(x>=8||y>=8||x<0||y<0){
                        return false;
                }else if(this->x==x&&this->y==y){
                        return false;
                }else if( (x==this->x+1||x==this->x-1)&&(y==this->y-1)&&matriz[y][x]==NULL){
                        return true;
                }else if( (x==this->x+2&&y==this->y-2&&!matriz[this->y-1][this->x+1].esNegra()&&matriz[y][x]==NULL)||(x==this->x-2&&y==this->y-2&&matriz[this->y-1][this->x+1].esNegra()&&matriz[y][x]==NULL)){
                        return true;
                }else{
                        return false;
                }

	}
}



