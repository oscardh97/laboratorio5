pragma once;
#include <string>

using std::string;

class Pieza{
private:
	int x,y;
	bool Negra;
	bool General;
public:
	Pieza();
	Pieza(int,int,string)
	bool esNegra();
	bool esGeneral():
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	void mover(int,int,Pieza**);
};

