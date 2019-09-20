#pragma once

#include <FireLight.h>
#include <string>
#include <vector>
#include <tuple>
#include <memory>

namespace FL {
	
	class Log
	{
	public:
		enum Raiser{ GAME, ENGINE };
		enum Type{ ERR, WARN, GOOD, DOUBT, INFO};
		
		static void Draw();
		
		static void Generic(Raiser raiser, Type type, std::string prefix, ImVec4 col, std::string message);

	private:
		
		static std::vector<std::tuple<Raiser, Type, std::string, ImVec4, std::string>> logs;
		
		static bool shouldDisplay(Raiser, Type);

		//should show window
		static bool showLogWindow;

		//display only based on raise point
		static bool showGameLogs;
		static bool showEngineLogs;

		//display only based on type
		static bool showErrLogs;
		static bool showWarnLogs;
		static bool showGoodLogs;
		static bool showDoubtLogs;
		static bool showInfoLogs;
	};

	//Game/Application Logs
	inline void LOG_ERROR(std::string text) {Log::Generic(Log::GAME, Log::ERR,   "[-] GAME Error: ",   ImVec4(1.0f, 0.0f, 0.0f, 1.0f),    (text));}
	inline void LOG_WARN (std::string text) {Log::Generic(Log::GAME, Log::WARN,  "[!] GAME Warning: ", ImVec4(0.97f, 0.58f, 0.02f, 1.0f), (text));}
	inline void LOG_SUCC (std::string text) {Log::Generic(Log::GAME, Log::GOOD,  "[+] GAME Success: ", ImVec4(0.0f, 1.0f, 0.0f, 1.0f),    (text));}
	inline void LOG_DOUBT(std::string text) {Log::Generic(Log::GAME, Log::DOUBT, "[?] GAME Doubt: ",   ImVec4(1.0f, 0.88f, 0.0f, 1.0f),   (text));}
	inline void LOG_INFO (std::string text) {Log::Generic(Log::GAME, Log::INFO,  "[~] GAME Info: ",    ImVec4(0.0f, 0.7f, 1.0f, 1.0f),    (text));}
	
	//Engine Logs
	inline void LOG_ERROR_ENGINE(std::string text) {Log::Generic(Log::ENGINE, Log::ERR,   "[-] ENGINE Error: ",   ImVec4(1.0f, 0.0f, 0.0f, 1.0f),    (text));}
	inline void LOG_WARN_ENGINE (std::string text) {Log::Generic(Log::ENGINE, Log::WARN,  "[!] ENGINE Warning: ", ImVec4(0.97f, 0.58f, 0.02f, 1.0f), (text));}
	inline void LOG_SUCC_ENGINE (std::string text) {Log::Generic(Log::ENGINE, Log::GOOD,  "[+] ENGINE Success: ", ImVec4(0.0f, 1.0f, 0.0f, 1.0f),    (text));}
	inline void LOG_DOUBT_ENGINE(std::string text) {Log::Generic(Log::ENGINE, Log::DOUBT, "[?] ENGINE Doubt: ",   ImVec4(1.0f, 0.88f, 0.0f, 1.0f),   (text));}
	inline void LOG_INFO_ENGINE (std::string text) {Log::Generic(Log::ENGINE, Log::INFO,  "[~] ENGINE Info: ",    ImVec4(0.0f, 0.7f, 1.0f, 1.0f),    (text));}
}
