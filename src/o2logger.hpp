#pragma once

#include "logger.hpp"


/*
 *   logi - [i] - info
 *   logw - [w] - warning
 *   loge - [e] - error
 *   logd - [d] - debug [logd1, logd2, logd3, logd4, logd5]
 */


namespace o2logger
{

using logger::Logger;

template<typename T> void logi(const T &text)
{
    logger::log_impl('i', 0, text);
}
template<typename T> void loge(const T &text)
{
    logger::log_impl('e', 0, text);
}
template<typename T> void logw(const T &text)
{
    logger::log_impl('w', 0, text);
}
template<typename T> void logd(const T &text)
{
    logger::log_impl('d', 0, text);
}
template<typename T> void logd1(const T &text)
{
    logger::log_impl('d', 1, text);
}
template<typename T> void logd2(const T &text)
{
    logger::log_impl('d', 2, text);
}
template<typename T> void logd3(const T &text)
{
    logger::log_impl('d', 3, text);
}
template<typename T> void logd4(const T &text)
{
    logger::log_impl('d', 4, text);
}
template<typename T> void logd5(const T &text)
{
    logger::log_impl('d', 5, text);
}

template<typename ...Args> void logi(Args&&... args)
{
    logger::log_impl2('i', 0, args...);
}
template<typename ...Args> void loge(Args&&... args)
{
    logger::log_impl2('e', 0, args...);
}
template<typename ...Args> void logw(Args&&... args)
{
    logger::log_impl2('w', 0, args...);
}
template<typename ...Args> void logd(Args&&... args)
{
    logger::log_impl2('d', 0, args...);
}
template<typename ...Args> void logd1(Args&&... args)
{
    logger::log_impl2('d', 1, args...);
}
template<typename ...Args> void logd2(Args&&... args)
{
    logger::log_impl2('d', 2, args...);
}
template<typename ...Args> void logd3(Args&&... args)
{
    logger::log_impl2('d', 3, args...);
}
template<typename ...Args> void logd4(Args&&... args)
{
    logger::log_impl2('d', 4, args...);
}
template<typename ...Args> void logd5(Args&&... args)
{
    logger::log_impl2('d', 5, args...);
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
}   // namespace o2logger
