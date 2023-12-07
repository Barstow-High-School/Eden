#include "Backend.h"
using namespace UsOS;
void Tournament();
void Initialize();
//getsetpid!!!!
int main() {
	//newthread Timer(bknd.Clock);
	Initialize();
	//Tournament();
	//Timer.Run();
	Motor.Accelerate.Tank(100, 100, 10);


	return 0;
}

void Tournament() {
	Misc.StartUp();
	Misc.Wait(1);
	bknd.commandCalls = false;
	Misc.HandsOff();
	std::cout << "The way to get started is to quit talking and begin doing.";
}
void Initialize() {
	bknd.LeftMotor = 0;
	bknd.RightMotor = 3;
	bknd.LMM = 1;
	bknd.RMM = 1;

	bknd.ClawServo = 1;
	bknd.ArmServo = 3;

	bknd.LeftButton = 0;
	bknd.RightButton = 1;
	bknd.StartLight = 0;
	bknd.DownLight = 1;
	bknd.FrontLight = 2;
	bknd.CurrentO = 0;
	bknd.CurrentX = 0;
	bknd.CurrentY = 0;

	using namespace UsOS;
	Misc.StartUp();
	worldspace Pipe1(5, 12, 5);

	//newthread Vel(bknd.Velocity);
	//Vel.Run();
	Preprocess();
}
