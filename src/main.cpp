#include <iostream>
#include <string>
#include <sstream>

#include "o2logger.hpp"


std::string usage(const std::string &bin)
{
    std::stringstream ss;
    ss << "Usage: " << bin + " [ --syslog ] [ --loglevel n]" << std::endl;
    ss << "\tsyslog: write logs into syslog" << std::endl;
    ss << "\tloglevel: 1-5" << std::endl;
    return ss.str();
}

int set(int argc, char *argv[])
{
    o2logger::Logger &l = o2logger::Logger::impl();

    for (int i = 1; i < argc; ++i)
    {
        std::string cur(argv[i]);
        std::string next;
        if (i < argc - 1)
        {
            next.assign(argv[i + 1]);
        }

        if (cur == "-h" || cur == "--help")
        {
            std::cerr << usage(argv[0]);
            return 0;
        }
        else if (cur == "--syslog")
        {
            l.setOptionSyslog(argv[0], true);
        }
        else if (cur == "--loglevel")
        {
            if (next.empty())
            {
                std::cerr << usage(argv[0]);
                return -1;
            }

            int loglevel = 0;
            try
            {
                loglevel = std::stoi(next);
            }
            catch (...)
            {
                std::cerr << usage(argv[0]);
                return -1;
            }

            l.setOptionLogLevel(loglevel);
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (set(argc, argv) <= 0) return 0;

    o2logger::logi("Hello world!");
    o2logger::logw("World is in a danger!");
    o2logger::loge("Oh no, it is cruel world :(");
    o2logger::logd("Debug");
    o2logger::logd1("Debug level1");
    o2logger::logd2("Debug level2");
    o2logger::logd3("Debug level3");
    o2logger::logd4("Debug level4");
    o2logger::logd5("Debug level5");

    o2logger::logi("================");

    o2logger::f::logi("key value: {0}, {1}", 1, 2);
    o2logger::f::logw("key value: {1}, {0}", 1, 2);
    o2logger::f::loge("key {0} value {1}", 3.14);
    o2logger::f::logd("Deb{0}ug: ", 0);
    o2logger::f::logd1("Debug level: {0}", 1);
    o2logger::f::logd2("Debug level: {0}", 2);
    o2logger::f::logd3("Debug level: {0}", 3);
    o2logger::f::logd4("Debug level: {0}", 4);
    o2logger::f::logd5("Debug level: {0}", 5);

    o2logger::logi("================");

    o2logger::logi("key value: ", 1);
    o2logger::logw("key value: ", "abc");
    o2logger::loge("key value: ", 3.14);
    o2logger::logd("Debug: ", 0, 1, 3);
    o2logger::logd("Debug: ", 0, ", Debug2: ", 2, ", Debug3: ", 3);
    o2logger::logd1("Debug level: ", 1);
    o2logger::logd2("Debug level: ", 2);
    o2logger::logd3("Debug level: ", 3);
    o2logger::logd4("Debug level: ", 4);
    o2logger::logd5("Debug level: ", 5);

    return 0;
}
