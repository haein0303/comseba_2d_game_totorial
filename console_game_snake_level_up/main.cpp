#include <iostream>
#include "util.h"

using namespace std;

struct position {
	int x=100, y=100;
};

struct snake {
	position _postion; 
	int _look;
	int _y = 5;
	int _size = 0;
	position _tails[50];
};

int main() {
	snake player;

	int wall_size = 20;

	player._postion.x = 10;
	player._postion.y = 10;
	player._look = 1;
	
	position feed = { 3,3 };


	while (1) {
		ClearUI();

		int key = getKey();
		if (key != 0) {
			player._look = key;
		}

		position p_old = player._postion;
		

		switch (player._look) {
		case 1:
			player._postion.x--;
			break;
		case 2:
			player._postion.x++;
			break;
		case 3:
			player._postion.y--;
			break;
		case 4:
			player._postion.y++;
			break;
		}	
		
		if (player._postion.x >= wall_size-1 || player._postion.x <= 0 || player._postion.y >= wall_size-1 || player._postion.y <= 0) {
			ClearUI();
			cout << "GAME OVER" << endl;
			cout << "SCORE : " << player._size << endl;
			break;
		}

		if (feed.x == player._postion.x && feed.y == player._postion.y) {
			player._size++;

			feed.x = rand() % (wall_size - 2);
			feed.y = rand() % (wall_size - 2);
		}

		for (int i = player._size - 1; i >= 0; --i) {
			player._tails[i + 1] = player._tails[i];			
		}
		
		player._tails[0] = p_old;

		for (int i = 0; i < wall_size; ++i) {
			for (int j = 0; j < wall_size; ++j) {
				if (i == 0 || i == wall_size-1 || j == 0 || j == wall_size-1) {
					cout << "¡á ";
				}
				else {
					bool check = true;
					if (player._postion.x == j && player._postion.y == i) {
						cout << "¡ß ";
						check = false;
					}

					for (int k = 0; k < player._size; ++k) {
						if (player._tails[k].x == j && player._tails[k].y == i) {
							cout << "# ";
							check = false;
						}
					}

					if (feed.x == j && feed.y == i) {
						cout << "¡Ú ";
						check = false;
					}

					if(check) {
						cout << "  ";
					}
					
				}				
			}
			cout << endl;
		}
		Sleep(500);
	}


}