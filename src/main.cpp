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
    logger::Logger &l = logger::get();

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

    logger::f::logi("key: ", 5, 4);
    return 0;
    logger::logi("Hello world!");
    logger::logw("World is in a danger!");
    logger::loge("Oh no, it is cruel world :(");
    logger::logd("Debug");
    logger::logd1("Debug level1");
    logger::logd2("Debug level2");
    logger::logd3("Debug level3");
    logger::logd4("Debug level4");
    logger::logd5("Debug level5");

    logger::logi("================");

    logger::f::logi("key value: {0}, {1}", 1, 2);
    logger::f::logw("key value: {1}, {0}", 1, 2);
    logger::f::loge("key {0} value {1}", 3.14);
    logger::f::logd("Deb{0}ug: ", 0);
    logger::f::logd1("Debug level: {0}", 1);
    logger::f::logd2("Debug level: {0}", 2);
    logger::f::logd3("Debug level: {0}", 3);
    logger::f::logd4("Debug level: {0}", 4);
    logger::f::logd5("Debug level: {0}", 5);

    logger::logi("================");

    logger::logi("key value: ", 1);
    logger::logw("key value: ", "abc");
    logger::loge("key value: ", 3.14);
    logger::logd("Debug: ", 0);
    logger::logd1("Debug level: ", 1);
    logger::logd2("Debug level: ", 2);
    logger::logd3("Debug level: ", 3);
    logger::logd4("Debug level: ", 4);
    logger::logd5("Debug level: ", 5);

    return 0;
}
