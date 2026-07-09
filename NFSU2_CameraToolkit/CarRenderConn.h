#pragma once
#include "CarRenderInfo.h"

struct CarRenderConn
{
	BYTE unk[0x40];
	CarRenderInfo* pCarRenderInfo;

	static int GetListCount()
	{
		static int* ListCount = (int*)0x00B77DBC;
		return *ListCount;
	}

	static CarRenderConn** GetList()
	{
		static CarRenderConn*** List = (CarRenderConn***)0x00B77DB4;
		return *List;
	}
};