#pragma once

struct FEManager
{
	static FEManager* Instance()
	{
		return *(FEManager**)0x00A97A7C;
	}

	char* GetUserProfile()
	{
		auto _GetUserProfile = (char* (__thiscall*)(FEManager*, int))0x00572B90;
		return _GetUserProfile(this, 0);
	}
};