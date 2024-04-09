#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>

using namespace std;

const int SCREEN_WIDTH = 40;
const int SCREEN_HEIGHT = 10;
const char FROG = 'F';
const char EMPTY = '.';
const char CAR = 'C';
const char BORDER = '#';

class Frog {
protected:
	int x, y;
	
public:
	Frog(int initialX, int initialY) : x(initialX), y(initialY) {}
	
	int getX() const {
		return x;
	}
	
	int getY() const {
		return y;
	}
	
	void moveFrog(char direction) {
		switch (direction) {
		case 'w':
			if (y > 1) y--;
			break;
		case 's':
			if (y < SCREEN_HEIGHT - 2) y++;
			break;
		case 'a':
			if (x > 1) x--;
			break;
		case 'd':
			if (x < SCREEN_WIDTH - 2) x++;
			break;
		}
	}
};

class Car {
protected:
	int position;
	int speed;
	
public:
	Car(int initialPosition, int initialSpeed) : position(initialPosition), speed(initialSpeed) {}
	
	void move() {
		position = (position + speed) % SCREEN_WIDTH;
	}
	
	int getPosition() const {
		return position;
	}
};

class FroggerGame : public Frog, public Car {
private:
	int car2Position, car3Position;
	int car2Speed, car3Speed;
	
public:
	FroggerGame() : Frog(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 1), Car(0, rand() % 3 + 1),
		car2Position(SCREEN_WIDTH / 3), car3Position(2 * SCREEN_WIDTH / 3),
		car2Speed(rand() % 3 + 1), car3Speed(rand() % 3 + 1) {
		srand(static_cast<unsigned>(time(0)));
	}
	
	void drawScreen() {
		system("cls");
		
		// Draw border
		for (int i = 0; i < SCREEN_WIDTH + 2; ++i)
			cout << BORDER;
		cout << endl;
		
		for (int i = 0; i < SCREEN_HEIGHT; ++i) {
			cout << BORDER;
			for (int j = 0; j < SCREEN_WIDTH; ++j) {
				if (i == getY() && j == getX())
					cout << FROG;
				else if (i == SCREEN_HEIGHT - 2 && (j == getPosition() || j == car2Position || j == car3Position))
					cout << CAR;
				else
					cout << EMPTY;
			}
			cout << BORDER << endl;
		}
		
		for (int i = 0; i < SCREEN_WIDTH + 2; ++i)
			cout << BORDER;
		cout << endl;
	}
	
	bool checkCollision() {
		return (getX() == getPosition() && getY() == SCREEN_HEIGHT - 2) ||
			(getX() == car2Position && getY() == SCREEN_HEIGHT - 2) ||
			(getX() == car3Position && getY() == SCREEN_HEIGHT - 2);
	}
	
	void respawnFrog() {
		x = SCREEN_WIDTH / 2;
		y = SCREEN_HEIGHT - 1;
	}
	
	void moverCars() {
		
		car2Position = (car2Position + car2Speed) % SCREEN_WIDTH;
		car3Position = (car3Position + car3Speed) % SCREEN_WIDTH;
	}
	
	void play() {
		while (true) {
			drawScreen();
			
			if (_kbhit()) {
				char key = _getch();
				moveFrog(key);
			}
			moverCars();
			
			if (checkCollision()) {
				cout << "Pisaron la rana!" << endl;
				Sleep(1000);
				respawnFrog();
			}
			
			Sleep(100);
		}
	}
};

int main(int argc, char *argv[]) {
	FroggerGame game;
	game.play();
	
	return 0;
}
