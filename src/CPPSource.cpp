#include <iostream>
#include <cstring>
#include <cstdlib>

namespace Mine {}

using namespace Mine;

	class WorldSpace { public:
		float o;
		float x;
		float y;
		bool collider;
	};


	class Analog { public:
		int reading(int port);	
	};
	class DigitalSensor { public:
		int reading(int port);
	};
	class Motor { public:
		void clearposition(int port);
		int getposition(int port);
		void brake(int port);
		void setpercent(int port, float percent);
		float getpercent(int port);
		void off(int port);
		void alloff();
	};
	class Servo { public:
		void setstatus(int port, int status);
		int getstatus(int port);
		void setallstatus(int status);
		void setposition(int port, int ticks);
		int getposition(int port);
	};

		class AReading {
			float x();
			float y();
			float z();
			float a();
		};
	class Accelerometer {
		void callibrate();
		AReading Reading;
	};
		class GReading { public:
			float x();
			float y();
			float z();
			float a();
		};
	class Gyroscope { public:
		void callibrate();		
		GReading Reading;	
	};
		class MReading { public:
			float x();
			float y();
			float z();
			float a();
		};
	class Magnetometer { public:
		void callibrate();
		MReading Reading;
	};
	class Battery { public:
		float power_level();
	};	

				class Down { public:
					bool a();
					bool b();
					bool c();
					bool x();
					bool y();
					bool z();
					bool any();
				};
				class Up { public:
					bool a();
					bool b();
					bool c();
					bool x();
					bool y();
					bool z();
					bool any();		
				};
				class Pressed { public:
					bool a();
					bool b();
					bool c();
					bool x();
					bool y();
					bool z();
					bool any();	
				};
			class Button { public:
				void setvisibility(bool vis);
				bool getvisibility();
				Down Down;
				Up Up;
				Pressed Pressed;
			};
			class Console { public:
				void clear();
			};
		class Screen { public:
			Button Button;
			Console Console;
		};


				class Wheel { public:
					float wheelradius = 1;
					float axelradius = 4;
					float turnrate = 3.8;	
				};
				class Arm { public:
					float armlength = 6;
					float armoffsetz = 8;
					float armoffsetx = 2;
				};
			class Physical { public:
				Wheel Wheel;
				Arm Arm;
			};
			class Digital { public:
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

		class Measurements { public:
			void diagnostics(char[]);
			Physical Physical;
			Digital Digital;
		};
		class SubSystems { public:
			bool athena;
			float athenamargin;
			bool collision;
			char hex[3] = {'F', 'F', 'F'};
			int commandCalls = 0;
		};

	class Obstacle { public:
		WorldSpace Object;
		float radius;
	};

		class StopWatch { public:
			void start();
			int centisec;
			int sec;
			int min;
		};
		class Timer { public:
			void start(int minutes, int seconds, int centiseconds);
			int centisec;
			int sec;
			int min;
		};
	class Time { public:
		StopWatch StopWatch;
		Timer Timer;
	};

	class Menu { public:
		bool autotravel = false;
		bool confirm = false;
		bool diagnostics = false;
		bool athena = true;
		bool handsoff = false;
		bool collision = true;
		int menubuffer = 0;
	};

	class External { public:
		Analog Analog;
		DigitalSensor Digital;
		Motor Motor;
		Servo Servo;
	};

	class Internal { public:
		Accelerometer Accelerometer;
		Gyroscope Gyroscope;
		Magnetometer Magnetometer;
		Battery Battery;
	};

	class Robot { public:	
		WorldSpace Position;
		External External;
		Internal Internal;
		Measurements Measurements;
		SubSystems Subsystems;
		Screen Screen;
	};
