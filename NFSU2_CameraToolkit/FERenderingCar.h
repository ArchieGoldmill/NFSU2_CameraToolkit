#pragma once
#include "RideInfo.h"
#include "CarRenderInfo.h"

struct FERenderingCar
{
	FERenderingCar* Next;
	FERenderingCar* Prev;
	RideInfo mRideInfo;
	CarRenderInfo* pCarRenderInfo;
	int ViewID;
	XMVECTOR Position;
	XMMATRIX BodyMatrix;
	XMMATRIX TireMatrices[4];
	XMMATRIX BrakeMatrices[4];
	struct eModel* OverrideModel;
	int Visible;
	int nPasses;
	int Reflection;
	int LightsOn;
	int CopLightsOn;
	BYTE padding[8];

	static FERenderingCar* Instance()
	{
		auto list = (FERenderingCar**)0x009B27EC;
		return *list;
	}

	static RideInfo* GetRideInfo()
	{
		return &Instance()->mRideInfo;
	}
};