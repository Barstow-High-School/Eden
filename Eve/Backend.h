#pragma once
#include "D:\EdenCommon\Backend.h"
class Eve : public common {
public:
	void TankSpeed(float SpeedL, float SpeedR, float Time) {
		if (commandCalls) {
			printf("TankSpeed called. \n");
		}
		float Lo = TTIW(Lc);
		float Ro = TTIW(Rc);
		create_drive_direct((SpeedL * LMM), (SpeedR * RMM));
		msleep((Time * 1000) * timemult);
		float Lt = TTIW(Lc);
		float Rt = TTIW(Rc);
		float DelL = Lt - Lo;
		float DelR = Rt - Ro;
		if (AthenaOn) {
			AthenaDecision(DelL, DelR);
		}
	}

	int DTTW(float Degrees) {
		if (commandCalls) {
			printf("DTTW called. \n");
		}
		int Ticks = Degrees * 5.55;
		return Ticks;
	}

	float TTDW(int Ticks) {
		if (commandCalls) {
			printf("TTDW called. \n");
		}
		float Degrees = Ticks / 5.55;
		return Degrees;
	}

	float DTIW(float Degrees) {
		if (commandCalls) {
			printf("DTIW called. \n");
		}
		float Inches = WheelRadius * rad(Degrees);
		return Inches;
	}

	float ITDW(float Inches) {
		if (commandCalls) {
			printf("ITDW called. \n");
		}
		float Degrees = degrees(WheelRadius / Inches);
		return Degrees;
	}

	float TTIW(int Ticks) {
		if (commandCalls) {
			printf("TTIW called. \n");
		}
		float Inches = Ticks / 206.49999936;
		return Inches;
	}

	int ITTW(float Inches) {
		if (commandCalls) {
			printf("ITTW called. \n");
		}
		int Ticks = Inches * 206.49999936;
		return Ticks;
	}

	int DTTA(float Degrees) {
		if (commandCalls) {
			printf("DTTA called. \n");
		}
		int Tics = (0.09 / Degrees) + 57.15;
		return Tics;
	}

	float TTDA(int Tics) {
		if (commandCalls) {
			printf("TTDA called. \n");
		}
		float Degrees = (0.09 * Tics) - 57.15;
		return Degrees;
	}

	int DTTC(float Degrees) {
		if (commandCalls) {
			printf("DTTC called. \n");
		}
		int Tics = (12.05 * Degrees) + 723.5;
		return Tics;
	}

	float TTDC(int Tics) {
		if (commandCalls) {
			printf("TTDC called. \n");
		}
		float Degrees = (0.082 * Tics) - 60;
		return Degrees;
	}

	void Stop() {
		if (commandCalls) {
			printf("Stop called. \n");
		}
		TankSpeed(0, 0, 0.1);
	}

	void CMR() {
		if (commandCalls) {
			printf("CMR called. \n");
		}
		//cmpc(LeftMotor);
		//cmpc(RightMotor);
	}
	long gpwmc(bool wheel) {
		long l, r = 0;
		_create_get_raw_encoders(&l, &r);
		//0 = left, 1 = right
		if (wheel) {
			return r;
		} else return l;
	}
	void Velocity() {
		if (commandCalls) {
			printf("Velocity called. \n");
		}
		while (1) {
			Lv = gpwmc(0);
			Rv = gpwmc(1);
			Lp = Lv / 6;
			Rp = Rv / 6;
		}
	}
};
Eve ebknd;
