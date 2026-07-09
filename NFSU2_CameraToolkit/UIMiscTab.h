#pragma once
#include "UICommon.h"
#include "Globals.h"
#include "Utilities.h"
#include "Game.h"
#include "TimeOfDay.h"
#include "FEManager.h"

namespace UI::Misc
{
	int forceLod = 0;
	void Draw()
	{
		if (ImGui::BeginTable("MiscTabTable", 3))
		{
			ImGui::TableNextRow();
			{
				ImGui::TableSetColumnIndex(0);
				{
					const char* forceLodComboItems[] = { "Default", "0", "1", "2", "3", "4" };
					if (DrawComboBox("Force LOD", "##ForceLOD", forceLodComboItems, 6, &forceLod))
					{
						Game::CarLod = forceLod - 1;
						Game::TireLOD = forceLod - 1;
					}
				}

				ImGui::TableSetColumnIndex(1);
				{
					DrawCheckBox("Draw HUD", Game::DrawFE);
				}

				ImGui::TableSetColumnIndex(2);
				{
					ImGui::Text(" ");
					ImGui::IncCursorPosX(20);
					ImGui::Checkbox("Force rain", Game::ForceRain);
				}
			}

			ImGui::TableNextRow();
			{
				ImGui::TableSetColumnIndex(0);
				{
					DrawCheckBox("Override game speed", &Globals::GameSpeedOverride);
				}

				ImGui::TableSetColumnIndex(1);
				{
					ImGui::BeginDisabled(!Globals::GameSpeedOverride);
					ImGui::Text("");
					ImGui::SliderFloat("Game speed", &Game::Speed, 0.0f, 1.0f, "%.3f");
					ImGui::EndDisabled();
				}

				ImGui::TableSetColumnIndex(2);
				{
					ImGui::Text("");
					ImGui::IncCursorPosX(20);
					if (DrawButton("Remove tire skids"))
					{
						Game::KillSkidsOnRaceRestart();
					}
				}
			}

			ImGui::TableNextRow();
			{
				ImGui::TableSetColumnIndex(0);
				{
					ImGui::Text("");
					ImGui::SliderFloat("Time", &TimeOfDay::instance->current_time_of_day, 0.0f, 1.0f, "%.3f");
				}

				float updateRate = TimeOfDay::instance->update_rate;
				ImGui::TableSetColumnIndex(1);
				{
					if (DrawFloatInput("Update rate", "##Updaterate", &updateRate, 0.1))
					{
						TimeOfDay::instance->update_rate = updateRate;
					}
				}
			}

			ImGui::TableNextRow();
			{
				ImGui::TableSetColumnIndex(0);
				{
					ImGui::Text("");
					ImGui::SliderFloat("Steer angle", Game::FrontSteerAngle, -60.0, 60.0, "%.f");
				}

				float sunAzimuth = XMConvertToDegrees(TimeOfDay::instance->sun_azimuth);
				ImGui::TableSetColumnIndex(1);
				{
					ImGui::Text("");
					if (ImGui::SliderFloat("Sun azimuth", &sunAzimuth, 0.0f, 360.0f, "%.1f"))
					{
						TimeOfDay::instance->sun_azimuth = XMConvertToRadians(sunAzimuth);
					}
				}
			}

			ImGui::EndTable();
		}
	}
}