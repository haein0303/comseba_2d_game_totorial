#include<iostream>
#include<vector>
#include <windows.h>

using namespace std;

class Framework {
private:

	//레일은 총 몇개의 플레이어가 달릴지 정하는 수 입니다.
	int _rail;

	//러너는 레일의 갯수에 따라서 그때마다 동적으로 할당해서 사용할 것입니다.
	int* _runner;

	int _rail_count = 40;

	int sleep_time = 1000;

	int* _winners;
	int _winer_counter = 0;
	int _startcounter;



public:
	bool _finish = false;
	//각 값들을 초기화 하는 생성자를 만들어 줍시다. 
	Framework(int rail) :_rail(rail), _runner(nullptr),_winners(nullptr) {

	}
	
	void init() {
		_runner = new int[_rail];
		_winners = new int[_rail];
		_startcounter = 5;
		for (int i = 0; i < _rail; ++i) {
			//시작할때 모든 러너들의 값을 초기화 해줍시다.
			//임의로 할당받은 공간 내부의 값은 예측할 수 없으니깐요.
			_runner[i] = 0;
			_winners[i] = 0;
		}

	}

	//동작에 관련한 부분들을 정의(구성)하는 파트입니다.
	void logic() {
		if (_startcounter > 0) {
			_startcounter--;
		}else
		//시작할때 타이머 바꾸장
		if (_startcounter == 0) {
			sleep_time = 500;
			_startcounter--;
		}
		else {
			for (int i = 0; i < _rail; ++i) {
				if (_runner[i] >= _rail_count-1) {
					_runner[i] = _rail_count;
					if (_winners[i] == 0) {
						_winer_counter++;
						_winners[i] = _winer_counter;
					}					
				}
				else {
					_runner[i] += rand() % 5 + 1;
				}
			}
		}
		if (_winer_counter == _rail) {
			_finish = true;
		}
		Sleep(sleep_time);
	}

	//그려오옹
	void draw() {
		system("cls");
		if (_startcounter >= 0) {
			if (_startcounter == 0) {
				cout << "                    START!" << endl;
			}
			else if (_startcounter == 4) {
				cout << "                    READY!" << endl;
			}
			else {
				cout << "                    " <<_startcounter << endl;
			}
			
		}
		else {
			cout << endl;
		}

		for (int i = 0; i < _rail; ++i) {
			cout << i << " ";
			for (int j = 0; j <= _rail_count; ++j) {

				if (j == _rail_count) {
					cout << "|";
				}

				if (_runner[i] == j) {
					cout << "◎";
				}
				else {
					cout << "_";
				}
				if (j == 0) {
					cout << "|";
				}
			}

			if (_winners[i] != 0) {
				cout << " FINISH [" << _winners[i] << "]";
			}
			cout << endl;
		}
	}
	void destroy() {
		//동적으로 만들어준 러너는 게임이 끝날때 초기화를 해줎히다.
		delete(_runner);
	}
};






int main() {
	Framework framework(10);
	framework.init();
	while (1) {
		framework.logic();
		framework.draw();
		if (framework._finish) {
			break;
		}
	}

}