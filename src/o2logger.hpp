#pragma once

#include "logger.hpp"


/*
 *   logi - [i] - info
 *   logw - [w] - warning
 *   loge - [e] - error
 *   logd - [d] - debug [logd1, logd2, logd3, logd4, logd5]
 */


namespace logger
{

logger::Logger& get()
{
    return logger::Logger::impl();
}

template<typename T> void logi(const T &text)
{
    logger::logi_impl('i', 0, text);
}
template<typename T> void loge(const T &text)
{
    logger::logi_impl('e', 0, text);
}
template<typename T> void logw(const T &text)
{
    logger::logi_impl('w', 0, text);
}
template<typename T> void logd(const T &text)
{
    logger::logi_impl('d', 0, text);
}
template<typename T> void logd1(const T &text)
{
    logger::logi_impl('d', 1, text);
}
template<typename T> void logd2(const T &text)
{
    logger::logi_impl('d', 2, text);
}
template<typename T> void logd3(const T &text)
{
    logger::logi_impl('d', 3, text);
}
template<typename T> void logd4(const T &text)
{
    logger::logi_impl('d', 4, text);
}
template<typename T> void logd5(const T &text)
{
    logger::logi_impl('d', 5, text);
}


// TODO: many args..., why just key-value?
template<typename T> void logi(const std::string &key, const T &val)
{
    logger::logi_impl2('i', 0, key, val);
}
template<typename T> void loge(const std::string &key, const T &val)
{
    logger::logi_impl2('e', 0, key, val);
}
template<typename T> void logw(const std::string &key, const T &val)
{
    logger::logi_impl2('w', 0, key, val);
}
template<typename T> void logd(const std::string &key, const T &val)
{
    logger::logi_impl2('d', 0, key, val);
}
template<typename T> void logd1(const std::string &key, const T &val)
{
    logger::logi_impl2('d', 1, key, val);
}
template<typename T> void logd2(const std::string &key, const T &val)
{
    logger::logi_impl2('d', 2, key, val);
}
template<typename T> void logd3(const std::string &key, const T &val)
{
    logger::logi_impl2('d', 3, key, val);
}
template<typename T> void logd4(const std::string &key, const T &val)
{
    logger::logi_impl2('d', 4, key, val);
}
template<typename T> void logd5(const std::string &key, const T &val)
{
    logger::logi_impl2('d', 5, key, val);
}

namespace f  // formatted
{

template<typename ...Args> void logi(const std::string &format, Args&&... args)
{
    logger::log_impl3('i', 0, format, args...);
}
template<typename ...Args> void loge(const std::string &format, Args&&... args)
{
    logger::log_impl3('e', 0, format, args...);
}
template<typename ...Args> void logw(const std::string &format, Args&&... args)
{
    logger::log_impl3('w', 0, format, args...);
}
template<typename ...Args> void logd(const std::string &format, Args&&... args)
{
    logger::log_impl3('d', 0, format, args...);
}
template<typename ...Args> void logd1(const std::string &format, Args&&... args)
{
    logger::log_impl3('d', 1, format, args...);
}
template<typename ...Args> void logd2(const std::string &format, Args&&... args)
{
    logger::log_impl3('d', 2, format, args...);
}
template<typename ...Args> void logd3(const std::string &format, Args&&... args)
{
    logger::log_impl3('d', 3, format, args...);
}
template<typename ...Args> void logd4(const std::string &format, Args&&... args)
{
    logger::log_impl3('d', 4, format, args...);
}
template<typename ...Args> void logd5(const std::string &format, Args&&... args)
{
    logger::log_impl3('d', 5, format, args...);
}

}   // namespace f
}   // namespace logger
