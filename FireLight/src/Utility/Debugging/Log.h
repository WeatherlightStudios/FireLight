#pragma once


#include <glm/glm.hpp>
#include "../../../imgui/imgui.h"

#include <string>
#include <vector>
#include <tuple>
#include <memory>
#include <sstream>

namespace FL {
	
	class Log
	{
	public:
		enum Raiser{ GAME, ENGINE };
		enum Type{ ERR, WARN, GOOD, DOUBT, INFO};
		
		static void Draw();
		static void Generic(Raiser raiser, Type type, std::string prefix, ImVec4 col, std::string message);
		
		template<typename T>
		static std::string Format(T text) {
			throw "Type of Data not implemented for formatting, you should implement it yourself";
		}

		template<> static std::string Format<int>(int text) { return std::to_string(text); }
		template<> static std::string Format<float>(float text) { return std::to_string(text); }
		template<> static std::string Format<double>(double text) { return std::to_string(text); }
		template<> static std::string Format<std::string>(std::string text) { return text; }
		template<> static std::string Format<const char*>(const char* text) { return text; }
		template<> static std::string Format<glm::vec2>(glm::vec2 text) { return "[" + std::to_string(text.x) + ", " + std::to_string(text.y) + "]"; }
		template<> static std::string Format<glm::vec3>(glm::vec3 text) { return "[" + std::to_string(text.x) + ", " + std::to_string(text.y) + ", " + std::to_string(text.z) + "]"; }
		template<> static std::string Format<glm::vec4>(glm::vec4 text) { return "[" + std::to_string(text.x) + ", " + std::to_string(text.y) + ", " + std::to_string(text.z) + ", " + std::to_string(text.w) + "]"; }
		template<> static std::string Format<bool>(bool text) {
			if(text)
				return "true";
			return "false";
		}
		template<> static std::string Format<const void*>(const void* text) {
			std::stringstream ss;
			ss << text;  
			return ss.str();
			/*
			const void * address = static_cast<const void*>(this);
			std::string name = ss.str(); 
			*/
		}

		template<typename T, typename... Args>
		static std::string Format(T text, Args... args) {
			return Format(text) + Format(args...);
		}

	private:
		
		static std::vector<std::tuple<Raiser, Type, std::string, ImVec4, std::string>> logs;
		
		static bool shouldDisplay(Raiser, Type);
		static void ClearLogs();
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
	template<typename... Args> inline void LOG_ERROR(Args... text) {Log::Generic(Log::GAME, Log::ERR,   "[-] GAME Error: ",   ImVec4(1.0f, 0.0f, 0.0f, 1.0f),    Log::Format(text...));}
	template<typename... Args> inline void LOG_WARN (Args... text) {Log::Generic(Log::GAME, Log::WARN,  "[!] GAME Warning: ", ImVec4(0.97f, 0.58f, 0.02f, 1.0f), Log::Format(text...));}
	template<typename... Args> inline void LOG_SUCC (Args... text) {Log::Generic(Log::GAME, Log::GOOD,  "[+] GAME Success: ", ImVec4(0.0f, 1.0f, 0.0f, 1.0f),    Log::Format(text...));}
	template<typename... Args> inline void LOG_DOUBT(Args... text) {Log::Generic(Log::GAME, Log::DOUBT, "[?] GAME Doubt: ",   ImVec4(1.0f, 0.88f, 0.0f, 1.0f),   Log::Format(text...));}
	template<typename... Args> inline void LOG_INFO (Args... text) {Log::Generic(Log::GAME, Log::INFO,  "[~] GAME Info: ",    ImVec4(0.0f, 0.7f, 1.0f, 1.0f),    Log::Format(text...));}
	
	//Engine Logs
	template<typename... Args> inline void LOG_ERROR_ENGINE(Args... text) {Log::Generic(Log::ENGINE, Log::ERR,   "[-] ENGINE Error: ",   ImVec4(1.0f, 0.0f, 0.0f, 1.0f),    Log::Format(text...));}
	template<typename... Args> inline void LOG_WARN_ENGINE (Args... text) {Log::Generic(Log::ENGINE, Log::WARN,  "[!] ENGINE Warning: ", ImVec4(0.97f, 0.58f, 0.02f, 1.0f), Log::Format(text...));}
	template<typename... Args> inline void LOG_SUCC_ENGINE (Args... text) {Log::Generic(Log::ENGINE, Log::GOOD,  "[+] ENGINE Success: ", ImVec4(0.0f, 1.0f, 0.0f, 1.0f),    Log::Format(text...));}
	template<typename... Args> inline void LOG_DOUBT_ENGINE(Args... text) {Log::Generic(Log::ENGINE, Log::DOUBT, "[?] ENGINE Doubt: ",   ImVec4(1.0f, 0.88f, 0.0f, 1.0f),   Log::Format(text...));}
	template<typename... Args> inline void LOG_INFO_ENGINE (Args... text) {Log::Generic(Log::ENGINE, Log::INFO,  "[~] ENGINE Info: ",    ImVec4(0.0f, 0.7f, 1.0f, 1.0f),    Log::Format(text...));}
}
