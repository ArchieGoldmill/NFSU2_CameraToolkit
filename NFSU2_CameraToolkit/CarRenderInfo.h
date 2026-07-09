#pragma once
#include "RideInfo.h"

struct CarMaterials
{
	eLightMaterial* Body;
	eLightMaterial* Hood;
	eLightMaterial* WindowTint;
	eLightMaterial* FrontWheel;
	eLightMaterial* Calipers;
	eLightMaterial* Spoiler;
	eLightMaterial* RoofScoop;
	eLightMaterial* Unknown;
};

struct CarRenderInfo
{
	BYTE unk0[0x3F0];
	RideInfo* pRideInfo;
	void* CarTypeInfo;
	void* CarShadowTexture;
	void* CarShadowRampTexture;
	CarMaterials Materials;
};