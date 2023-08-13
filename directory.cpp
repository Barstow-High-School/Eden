#include <iostream>   // Input and output stream operations
#include <iomanip>    // Input/output manipulators
#include <cmath>      // Math functions
#include <string>     // String handling
#include <array>      // Static arrays
#include <map>        // Associative arrays (maps)
#include <set>        // Sets
#include <algorithm>  // Algorithms like sorting
#include <fstream>    // File input/output
#include <ctime>      // Time functions
#include <cstdlib>    // General utilities
#include <kipr/wombat.h>

namespace Aztec {
	class Timer {
		bool paused = false;
	public:
		void start() {
			
		}
		void pause() {
			paused = !paused;
		}
		void stop() {

		}
		float elapsed() {

		}
		float remaining() {
			
		}
	};

	class StopWatch {
	public:
		int precision = 1;
	private:
		bool paused = false;
		void(*stopwatch()) {
			Timer();
		}
		thread StopWatch = thread_create(stopwatch);
	public:
		void start() {
			thread_start(this->StopWatch);
		}
		void pause() {
			paused = !paused;
		}
		void stop() {

		}
		float elapsed() {

		}
	};
	class Time {
	public:
		class Timer Timer;
		class StopWatch StopWatch;
	};

	class Up {
	public:
		bool a() {
			if (a_button()) {
				return false;
			}
			else return true;
		}
		bool b() {
			if (b_button()) {
				return false;
			}
			else return true;
		}
		bool c() {
			if (c_button()) {
				return false;
			}
			else return true;
		}
		bool x() {
			if (x_button()) {
				return false;
			}
			else return true;
		}
		bool y() {
			if (y_button()) {
				return false;
			}
			else return true;
		}
		bool z() {
			if (z_button()) {
				return false;
			}
			else return true;
		}
	};
	class Down {
	public:
		bool a() {
			if (a_button()) {
				return true;
			}
			else return false;
		}
		bool b() {
			if (b_button()) {
				return true;
			}
			else return false;
		}
		bool c() {
			if (c_button()) {
				return true;
			}
			else return false;
		}
		bool x() {
			if (x_button()) {
				return true;
			}
			else return false;
		}
		bool y() {
			if (y_button()) {
				return true;
			}
			else return false;
		}
		bool z() {
			if (z_button()) {
				return true;
			}
			else return false;
		}
	};
	class Pressed {
	public:
		bool a() {
			if (a_button_clicked()) {
				return true;
			}
			else return false;
		}
		bool b() {
			if (b_button_clicked()) {
				return true;
			}
			else return false;
		}
		bool c() {
			if (c_button_clicked()) {
				return true;
			}
			else return false;
		}
		bool x() {
			if (x_button_clicked()) {
				return true;
			}
			else return false;
		}
		bool y() {
			if (y_button_clicked()) {
				return true;
			}
			else return false;
		}
		bool z() {
			if (z_button_clicked()) {
				return true;
			}
			else return false;
		}
	};
	class Buttons {
	public:
		void setvisibility(bool vis) {
			if (vis == true) {
				extra_buttons_show();
			}
			if (vis == false) {
				extra_buttons_hide();
			}
		}
		bool getvisibility() {
			if (get_extra_buttons_visible() == 1) {
				return true;
			}
			else return false;
		}
		class Up Up;
		class Down Down;
		class Pressed Pressed;
	};
	class Console {
	public:
		void clear() {
			console_clear();
		}
		class Buttons Buttons;
	};


	class AnalogGet {
	public:
		int value(int port) {
			return analog10(port);
		}
	};
	class Analog {
	public:
		int startlight = 0;
		int linefollow = 1;
		class AnalogGet Get;
	};

	class DigitalGet {
	public:
		bool value(int port) {
			if (digital(port) == 1) {
				return true;
			}
			else return false;
		}
	};
	class Digital {
	public:
		int backleftbutton = 0;
		int frontbar = 1;
		int backrightbutton = 2;
		class DigitalGet Get;
	};

	class MotorGet {
	public:
		int goalpower(int port) {
			return getpwm(port);
		}
		int position(int port) {
			return gmpc(port);
		}
		bool done(int port) {
			return get_motor_done(port);
		}
	};
	class MotorSet {
	public:
		void speed(int port, int value) {
			setpwm(port, value);
		}
		void brake(int port) {
			freeze(port);
		}
		void clearposition(int port) {
			cmpc(port);
		}
	};
	class Motor {
	public:
		int left = 0;
		int right = 1;
		class MotorGet Get;
		class MotorSet Set;
	};

	class ServoGet {
	public:
		bool enable(int port) {
			if (get_servo_enabled(port) == 1) {
				return true;
			}
			else return false;
		}
		int position(int port) {
			return get_servo_position(port);
		}
	};
	class ServoSet {
	public:
		void enable(int port, bool value) {
			set_servo_enabled(port, value);
		}
		void position(int port, int value) {
			set_servo_position(port, value);
		}
	};
	class Servo {
	public:
		int arm = 0;
		int claw = 1;
		class ServoGet Get;
		class ServoSet Set;
	};

	class External {
	public:
		class Analog Analog;
		class Digital Digital;
		class Motor Motor;
		class Servo Servo;
	};

	class Accelerometer {
	public:
		bool calibrate() {
			if (accel_calibrate() == 1) {
				return true;
			}
			else return false;
		}
		float x() {
			return accel_x();
		}
		float y() {
			return accel_y();
		}
		float z() {
			return accel_z();
		}
		float a() {
			return (accel_x() + accel_y() + accel_z()) / 3;
		}
	};
	class Gyrometer {
	public:
		bool calibrate() {
			if (gyro_calibrate() == 1) {
				return true;
			}
			else return false;
		}
		float x() {
			return gyro_x();
		}
		float y() {
			return gyro_y();
		}
		float z() {
			return gyro_z();
		}
		float a() {
			return (gyro_x() + gyro_y() + gyro_z()) / 3;
		}
	};
	class Battery {
	public:
		bool charging() {
			if (battery_charging() == 1) {
				return true;
			}
			else return false;
		}
		float power() {
			return power_level();
		}
	};
	class Internal {
	public:
		class Accelerometer Accelerometer;
		class Gyrometer Gyrometer;
		class Battery Battery;
	};


	class Arm {
	public:
		const float x = -2;
		const float z = 5.3;
		const float length = 6.2;
	};
	class Wheel {
	public:
		const float radius = 1.5;
		const float base = 3.25;
		const float turnrate = 3.8;
	};
	class Physical {
	public:
		class Arm Arm;
		class Wheel Wheel;
	};


	class Side {
	public:
		float delta = 0;
		float positionOne = 0;
		float positionTwo = 0;
		float velocity = 0;
		float percent = 0;
		float multiplier = 1;
	};

	class LeftSide : public Side {
	public:

	};

	class RightSide : public Side {
	public:

	};
	class DigitalWheel {
	public:
		float maximizer = 1;
		float timeMultiplier = 0;

		LeftSide left;
		RightSide right;
	};
	class DigitalMeasure {
	public:
		class DigitalWheel Wheel;
	};
	class Measurements {
	public:
		class Physical Physical;
		class DigitalMeasure Digital;
	};

	class Athena {
	public:
		float margin = 0.5;
	};
	class Artemis {
	public:

	};
	class Hephaestus {
	public:

	};
	class Hermes {
	public:

	};
	class Pathfinding {
	public:
		bool on = true;
		class Athena Athena;
		class Artemis Artemis;
		class Hephaestus Hephaestus;
		class Hermes Hermes;
	};
	class Collision {
	public:
		bool on = true;
	};
	class Subroutines {
	public:
		class Pathfinding Pathfinding;
		class Collision Collision;
	};
	class WorldSpace {
	public:
		float x;
		float y;
		float o;
		float radius;
	};
	class Robot {
	public:
		class Console Console;
		class External External;
		class Internal Internal;
		class Measurements Measurements;
		class Subroutines Subroutines;
		class WorldSpace Position;
	};

	class Robot Adam;
	bool declaremyballs = true;
};
using namespace Aztec;
/*
External
	External>Analog
		External>Analog>Get
	External>Digital
		External>Digital>Get
	External>Motor
		External>Motor>Get
		External>Motor>Set
	External>Servo
		External>Servo>Get
		External>Servo>Set

Internal
	Internal>Accelerometer
	Internal>Gyrometer
	Internal>Magnetometer
	Internal>Battery

Measurements
	Measurements>Physical
		Measurements>Physical>Arm
		Measurements>Physical>Wheel
	Measurements>Digital
		Measurements>Digital>Wheel

Subroutines
	Subroutines>Collision
	Subroutines>Pathfinding
		Subroutines>Pathfinding>Athena
		Subroutines>Pathfinding>Artemis
		Subroutines>Pathfinding>Hephaestus
		Subroutines>Pathfinding>Hermes

Console
	Console>Buttons
		Console>Buttons>Up
		Console>Buttons>Down
		Console>Buttons>Pressed
*/


int main() {
	Adam.Console.Buttons.Up.a();
	return 0;
}
