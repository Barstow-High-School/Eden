#pragma once
#include "D:\EdenCommon\UserOS.h"
class Eve : public common {
	void TankSpeed(float SpeedL, float SpeedR, float Time) const override {
		if (commandCalls) {
			printf("TankSpeed called. \n");
		}
		float Lo = TTIW(gmpc(LeftMotor));
		float Ro = TTIW(gmpc(RightMotor));
		create_drive_direct((SpeedL * LMM), (SpeedR * RMM));
		msleep((Time * 1000) * timemult);
		float Lt = TTIW(gmpc(LeftMotor));
		float Rt = TTIW(gmpc(RightMotor));
		float DelL = Lt - Lo;
		float DelR = Rt - Ro;
		if (AthenaOn) {
			AthenaDecision(DelL, DelR);
		}
	}

	int DTTW(float Degrees) const override {
		if (commandCalls) {
			printf("DTTW called. \n");
		}
		int Ticks = Degrees * 5.55;
		return Ticks;
	}

	float TTDW(int Ticks) const override {
		if (commandCalls) {
			printf("TTDW called. \n");
		}
		float Degrees = Ticks / 5.55;
		return Degrees;
	}

	float DTIW(float Degrees) const override {
		if (commandCalls) {
			printf("DTIW called. \n");
		}
		float Inches = WheelRadius * rad(Degrees);
		return Inches;
	}

	float ITDW(float Inches) const override {
		if (commandCalls) {
			printf("ITDW called. \n");
		}
		float Degrees = degrees(WheelRadius / Inches);
		return Degrees;
	}

	float TTIW(int Ticks) const override {
		if (commandCalls) {
			printf("TTIW called. \n");
		}
		float Inches = Ticks / 206.49999936;
		return Inches;
	}

	int ITTW(float Inches) const override {
		if (commandCalls) {
			printf("ITTW called. \n");
		}
		int Ticks = Inches * 206.49999936;
		return Ticks;
	}

	int DTTA(float Degrees) const override {
		if (commandCalls) {
			printf("DTTA called. \n");
		}
		int Tics = (0.09 / Degrees) + 57.15;
		return Tics;
	}

	float TTDA(int Tics) const override {
		if (commandCalls) {
			printf("TTDA called. \n");
		}
		float Degrees = (0.09 * Tics) - 57.15;
		return Degrees;
	}

	int DTTC(float Degrees) const override {
		if (commandCalls) {
			printf("DTTC called. \n");
		}
		int Tics = (12.05 * Degrees) + 723.5;
		return Tics;
	}

	float TTDC(int Tics) const override {
		if (commandCalls) {
			printf("TTDC called. \n");
		}
		float Degrees = (0.082 * Tics) - 60;
		return Degrees;
	}

	void Stop() const override {
		if (commandCalls) {
			printf("Stop called. \n");
		}
		TankSpeed(0, 0, 0.1);
	}

	void CMR() const override {
		if (commandCalls) {
			printf("CMR called. \n");
		}
		cmpc(LeftMotor);
		cmpc(RightMotor);
	}
};
