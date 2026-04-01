#include <Alchemist/Core/Log.h>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <memory>

namespace tt
{

static void create_logger(std::string name)
{
    std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console =
        std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

    std::shared_ptr<spdlog::logger> result = std::make_shared<spdlog::logger>(name, spdlog::sinks_init_list{console});

    spdlog::register_logger(result);
}

Logger Logger::create(std::string name)
{
    return Logger(name);
}

Logger::Logger(std::string name) : name(name)
{
    if (!spdlog::get(name))
        create_logger(name);
}

void Logger::log(std::string msg)
{
    spdlog::get(this->name)->info(msg);
}

} // namespace tt
