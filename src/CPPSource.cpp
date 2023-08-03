#include <iostream>
using namespace std;

class Robot {
	WorldSpace Position;
	float orientation;

	class Port {
		Port Analog;	
		Port Digital;
		Port Motor;
		Port Servo;
	};
	class Measurements {
		class Physical {
			class Wheel {
				float wheelradius;
				float axelradius;
				float turnrate;	
			};
			class Arm {
				float armlength;
				float armoffsetz;
				float armoffsetx;
			};
		};
		class Digital {
			float leftdelta;
			float rightdelta;

			float leftvelocity;
			float rightvelocity;
			float leftpercent;
			float rightpercent;

			int leftstart;
			int leftend;
			int rightstart;
			int rightend;
		};
	};
	class SubSystems {
		bool athena;
		float athenamargin;
		bool collision;
		char hex[] = {'F', 'F', 'F'};
		int commandCalls = 0;
	};
};

class Obstacle {
	Worldspace Object;
	float radius;
};

class WorldSpace {
	float x;
	float y;
	bool collider;
};

class Time {
	int centisec;
	int sec;
	int min;
};

class Menu {
	bool autotravel = false;
	bool confirm = false;
	bool diagnostics = false;
	bool athena = true;
	bool handsoff = false;
	bool collision = true;
	int menubuffer = 0;
};

class Port {
	int portzero = 0;
	int portone = 1;
	int porttwo = 2;
	int portthree = 3;
};
