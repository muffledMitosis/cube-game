#pragma once
#include "spdlog/common.h"
#include "spdlog/logger.h"
#include <spdlog/spdlog.h>

class Log
{
public:
 static void Init(spdlog::level::level_enum level)
 {
	 spdlog::set_pattern("[%T] [%L] %v");
	 spdlog::set_level(level);
 }
};

#define SEP ,

#define LOG_INFO(x) spdlog::info(x)
#define LOG_DEBUG(x) spdlog::debug(x)
#define LOG_WARN(x) spdlog::warn(x)
#define LOG_ERROR(x) spdlog::error(x)

#define LOG_LEVEL_INFO spdlog::level::info
#define LOG_LEVEL_DEBUG spdlog::level::debug
#define LOG_LEVEL_WARN spdlog::level::warn
#define LOG_LEVEL_ERROR spdlog::level::error
