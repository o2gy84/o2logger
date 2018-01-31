#include "logger.hpp"


namespace logger
{

int braced_number(const std::string &s)
{
    int ret = -1;
    try
    {
        size_t pos;
        ret = std::stoi(s, &pos);
        if (pos < s.size())
        {
            return -1;
        }
    }
    catch (std::invalid_argument& e)
    {
        // no conversion could be performed
        return -1;
    }
    catch (std::out_of_range& e)
    {
        // if the converted value would fall out of the range of the result type 
        // or if the underlying function (std::strtol or std::strtoull) sets errno 
        // to ERANGE.
        return -1;
    }
    return ret;
}

Logger::Logger()
{
    _log_level = 0;
    _syslog = false;
}

void Logger::setOptionLogLevel(int level)
{
    if (level < 0) level = 0;
    _log_level = level;
}

void Logger::setOptionSyslog(const char *progname, bool syslog)
{
    _syslog = syslog;

    if (_syslog)
    {
        int options = LOG_PID;
        // TODO: change facility
        int facility = LOG_LOCAL0;
        openlog(progname, options, facility);
    }
}

Logger& Logger::impl()
{
    static Logger logger;
    return logger;
}

}   // namespace logger
