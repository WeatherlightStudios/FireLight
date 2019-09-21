#include "Log.h"
namespace FL {

	std::vector<std::tuple<Log::Raiser, Log::Type, std::string, ImVec4, std::string>> Log::logs;
	bool Log::showLogWindow = true;

	bool Log::showGameLogs = true;
	bool Log::showEngineLogs = true;

	bool Log::showErrLogs = true;
	bool Log::showWarnLogs = true;
	bool Log::showGoodLogs = true;
	bool Log::showDoubtLogs = true;
	bool Log::showInfoLogs = true;

	void Log::Draw() {
		ImGui::Begin("Console", &showLogWindow, ImGuiWindowFlags_MenuBar);

		if (ImGui::BeginMenuBar()) {
			if (ImGui::BeginMenu("Log From..."))
			{
				ImGui::Checkbox("Show Game Logs", &showGameLogs);
				ImGui::SameLine();
				ImGui::Checkbox("Show Engine Logs", &showEngineLogs);
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Log Type..."))
			{
				ImGui::Checkbox("Show Error Logs", &showErrLogs);
				ImGui::Checkbox("Show Warning Logs", &showWarnLogs);
				ImGui::Checkbox("Show Success Logs", &showGoodLogs);
				ImGui::Checkbox("Show Doubt Logs", &showDoubtLogs);
				ImGui::Checkbox("Show Info Logs", &showInfoLogs);
				ImGui::EndMenu();
			}
			if (ImGui::Button("Clear")) {
				ClearLogs();
			}
			ImGui::EndMenuBar();
		}

		//display each log only if necessary
		for (auto &log : logs) {
			auto raiser = std::get<0>(log);
			auto type = std::get<1>(log);
			if (!shouldDisplay(raiser, type)) {
				continue;
			}

			auto col = std::get<3>(log);
			auto pref = std::get<2>(log).c_str();
			auto message = std::get<4>(log).c_str();

			ImGui::PushStyleColor(ImGuiCol_Text, col);
			ImGui::Text(pref);
			ImGui::PopStyleColor();
			ImGui::SameLine();
			ImGui::Text(message);
		}

		ImGui::End();
	}

	void Log::ClearLogs() {
		logs.clear();
	}

	//Check to see if it should display this current log line
	bool Log::shouldDisplay(Raiser r, Type t) {

		if (r == Raiser::GAME   && !showGameLogs)   { return false; }
		if (r == Raiser::ENGINE && !showEngineLogs) { return false; }

		if (t == Type::DOUBT && !showDoubtLogs) { return false; }
		if (t == Type::ERR   && !showErrLogs)   { return false; }
		if (t == Type::GOOD  && !showGoodLogs)  { return false; }
		if (t == Type::INFO  && !showInfoLogs)  { return false; }
		if (t == Type::WARN  && !showWarnLogs)  { return false; }

		return true;
	}


	void Log::Generic(Raiser raiser, Type type, std::string prefix, ImVec4 col, std::string message) {
		logs.push_back(std::make_tuple(raiser, type, prefix, col, message));
	}

}