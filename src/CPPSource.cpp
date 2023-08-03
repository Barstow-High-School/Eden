#include <iostream>
using namespace Mine;

class Robot {
	WorldSpace Position;
	float orientation;

	class External {
		class Analog {
			int reading(int port);	
		};
		class Digital {
			int reading(int port);
		};
		class Motor {
			void clearposition(int port);
			int getposition(int port);
			void brake(int port);
			void setpercent(int port, float percent);
			float getpercent(int port);
			void off(int port);
			void alloff();
		};
		class Servo {
			void setstatus(int port, int status);
			int getstatus(int port);
			void setallstatus(int status);
			void setposition(int port, int ticks);
			int getposition(int port);
		}
	};
	class Internal {
		class Accelerometer {
			callibrate();
			class Reading {
				float x();
				float y();
				float z();
				float a();
			};
		};
		class Gyroscope {
			callibrate();
			class Reading {
				float x();
				float y();
				float z();
				float a();
			};
		
		};
		class Magnetometer {
			callibrate();
			class Reading {
				float x();
				float y();
				float z();
				float a();
			};

		};
		class Battery {
			float power_level();
		};	
	};
	class Screen {
		class Button {
			void setvisibility(bool vis);
			bool getvisibility();
			class Down {
				a();
				b();
				c();
				x();
				y();
				z();
				any();
			};
			class Up {
				a();
				b();
				c();
				x();
				y();
				z();
				any();			
			};
			class Pressed {
				a();
				b();
				c();
				x();
				y();
				z();
				any();			
			};
		}
		class Console {
			void clear();
		}
	};
	class Measurements {
		void diagnostics(char[]);
		class Physical {
			class Wheel {
				const float wheelradius;
				const float axelradius;
				const float turnrate;	
			};
			class Arm {
				const float armlength;
				const float armoffsetz;
				const float armoffsetx;
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
