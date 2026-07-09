#pragma once
#include "Game.h"
#include "CarRenderInfo.h"

struct VehicleRenderConn
{
	static inline auto& Player = *(VehicleRenderConn***)0x009B37CC;

	int vTable;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	XMMATRIX* Matrix;
	int field_38;
	int field_3C;
	int field_40;
	CarRenderInfo* pCarRenderInfo;
};