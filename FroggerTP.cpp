#include<iostream>
#include<windows.h>
#include<ctime>
#include<conio.h>

using namespace std;

//introducir tamaños y caracteres
const int SCREEN_WIDTH = 40;
const int SCREEN_HEIGHT = 10;
const char FROG = 'F';
const char EMPTY = '.';
const char CAR = 'C';
const char BORDER = '#';

//Creacion de clase Frogger conteniendo el frog, los autos y sus posiciones y velocidades
class FroggerGame{
private:
	int frogPosicionX, frogPosicionY;
	int car1Posicion, car2Posicion, car3Posicion;
	int car1Velocidad, car2Velocidad, car3Velocidad;
	
public:
	FroggerGame() : frogPosicionX(SCREEN_WIDTH / 2), frogPosicionY(SCREEN_HEIGHT - 1),
		        car1Posicion(0), car2Posicion(SCREEN_WIDTH / 3), car3Posicion(2 * SCREEN_WIDTH / 3),
		        car1Velocidad(rand() % 3 + 1), car2Velocidad(rand() % 3 + 1), car3Velocidad(rand() % 3 + 1) {
		srand(static_cast<unsigned>(time(0)));  //Semilla para generacion aleatoria de numeros
	}
	
	void srawScreen(){
		system("cls"); //system cls para limpiar la pantalla
		
		//Dybujar borde
		for (int i = 0; i < SCREEN_WIDTH + 2; ++i){
			cout<<BORDER; 
		}
		cout<<endl;
		
		for (int i = 0; i < SCREEN_HEIGHT; ++i){
			cout<<BORDER;
			for (int j = 0; j < SCREEN_WIDTH; ++j) {
				if (i == frogPosicionY && j == frogPosicionX) {
					cout << FROG;
				} else if (i == SCREEN_HEIGHT - 2 && (j == car1Posicion || j == car2Posicion || j == car3Posicion)) {
					cout << CAR;
				} else {
					cout << EMPTY;
				}
			}
			cout << BORDER << endl;
		}
		for (int i = 0; i < SCREEN_WIDTH + 2; ++i) {
			cout << BORDER;
		}
		cout << endl;
		}
		
	void moveFrog(char direction) {
		switch (direction){
		case 'w':
			if (frogPosicionY > 1){
				frogPosicionY--;
			}
			break;
		case 's':
			if (frogPosicionY < SCREEN_HEIGHT - 2){
				frogPosicionY++;
			}
			break;
		case 'a':
			if (frogPosicionX > 1){
				frogPosicionX--;
			}
			break;
		case 'd':
			if (frogPosicionX < SCREEN_WIDTH - 2){
				frogPosicionX++;
			}
			break;
		}
	}	
	
	void
		

	
	
	
	
	
};





int main(int argc, char *argv[]) {
	
	return 0;
}

