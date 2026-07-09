#pragma once

struct TimeOfDay
{
	float update_rate;
	int update_direction;
	float current_time_of_day;
	float sun_azimuth;

	static inline TimeOfDay*& instance = *reinterpret_cast<TimeOfDay**>(0x009B392C);
};