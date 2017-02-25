#include <iostream>
#include <string>
#include <sstream>

#include "logger.hpp"



std::string usage(const std::string &bin)
{
    std::stringstream ss;
    ss << "Usage: " << bin + " [ --syslog ] [ --loglevel n]" << std::endl;
    ss << "\tsyslog: write logs into syslog" << std::endl;
    ss << "\tloglevel: 1-5" << std::endl;
    return ss.str();
}

int main(int argc, char *argv[])
{
    Logger &l = Logger::get();

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

    logi("Hello world!");
    logw("World is in a danger!");
    loge("Oh no, it is cruel world :(");
    logd("Debug");
    logd1("Debug level1");
    logd2("Debug level2");
    logd3("Debug level3");
    logd4("Debug level4");
    logd5("Debug level5");

    logi("================");

    logi("key value: {0}, {1}", 1, 2);
    logw("key value: {1}, {0}", 1, 2);
    loge("key {0} value {1}", 3.14);
    logd("Deb{0}ug: ", 0);
    logd1("Debug level: {0}", 1);
    logd2("Debug level: {0}", 2);
    logd3("Debug level: {0}", 3);
    logd4("Debug level: {0}", 4);
    logd5("Debug level: {0}", 5);

    logi("================");

    kvlogi("key value: ", 1);
    kvlogw("key value: ", "abc");
    kvloge("key value: ", 3.14);
    kvlogd("Debug: ", 0);
    kvlogd1("Debug level: ", 1);
    kvlogd2("Debug level: ", 2);
    kvlogd3("Debug level: ", 3);
    kvlogd4("Debug level: ", 4);
    kvlogd5("Debug level: ", 5);

    return 0;
}
