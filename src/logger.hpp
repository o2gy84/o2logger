#pragma once

#include <iostream>
#include <sstream>
#include <initializer_list>
#include <utility>
#include <tuple>
#include <string>

#include <assert.h>
#include <syslog.h>


namespace logger
{

class Logger
{
public:
    static Logger& impl();

    // TODO: log into file
    void log(const char *text) const
    {
        if (_syslog)
        {
            syslog(LOG_INFO, "%s", text);
        }
        else
        {
            std::cout << text;
        }
    }

    // OPTIONS
    void setOptionLogLevel(int level);
    void setOptionSyslog(const char *progname, bool syslog);

    // GETTERS
    uint16_t loglevel() const { return _log_level; }

private:
    Logger();
    Logger(const Logger &);
    Logger& operator=(const Logger &);
private:
    uint16_t _log_level;
    bool _syslog;
};


// get number from braced string like "{123}"
int braced_number(const std::string &s);

template <std::size_t N, typename... Tp>
typename std::enable_if<(N < sizeof...(Tp)), void>::type print_tuple_at(const std::tuple<Tp...> &t, std::ostream &os)
{
    os << std::get<N>(t);
}

template <std::size_t N, typename... Tp>
typename std::enable_if< (N >= sizeof...(Tp)), void>::type print_tuple_at(const std::tuple<Tp...> &, std::ostream &os)
{
    os << "nil";
}

template <std::size_t N, typename... Tp>
typename std::enable_if<(N < sizeof...(Tp)), void>::type print_tuple_or_nothing_at(const std::tuple<Tp...> &t, std::ostream &os)
{
    os << std::get<N>(t);
}

template <std::size_t N, typename... Tp>
typename std::enable_if< (N >= sizeof...(Tp)), void>::type print_tuple_or_nothing_at(const std::tuple<Tp...> &, std::ostream &)
{
}


// logging without args, string, char* e.t.c.
template<typename T>
void log_impl(char prefix, int log_level, const T &text)
{
    const Logger &l = Logger::impl();
    if (l.loglevel() < log_level) return;

    std::stringbuf stringbuf;
    std::ostream os(&stringbuf);
    os << "[" << prefix << "] " << text << std::endl;

    l.log(stringbuf.str().c_str());
}

// logging in style like: "key1" => "value1", "key2" => "value2"
template <typename ...Args>
void log_impl2(char prefix, int log_level, Args&&... args)
{
    const Logger &l = Logger::impl();
    if (l.loglevel() < log_level) return;

    std::stringbuf stringbuf;
    std::ostream os(&stringbuf);
    os << "[" << prefix << "] ";

    std::tuple<Args...> list(args...);
    constexpr size_t n = std::tuple_size<decltype(list)>::value;
    for (size_t i = 0; i < n; ++i)
    {
        switch (i)
        {
            case 0: print_tuple_or_nothing_at<0>(list, os); break;
            case 1: print_tuple_or_nothing_at<1>(list, os); break;
            case 2: print_tuple_or_nothing_at<2>(list, os); break;
            case 3: print_tuple_or_nothing_at<3>(list, os); break;
            case 4: print_tuple_or_nothing_at<4>(list, os); break;
            case 5: print_tuple_or_nothing_at<5>(list, os); break;
            case 6: print_tuple_or_nothing_at<6>(list, os); break;
            case 7: print_tuple_or_nothing_at<7>(list, os); break;
            case 8: print_tuple_or_nothing_at<8>(list, os); break;
            case 9: print_tuple_or_nothing_at<9>(list, os); break;
            default: throw std::runtime_error("logger: too many arguments (max = 9)");
        }
    }
    os << std::endl;
    l.log(stringbuf.str().c_str());
}

// logging in style like: string.format("key: {0}, value: {1}", key, val)
template <typename ...Args>
void log_impl3(char prefix, int log_level, const std::string &format, Args&&... args)
{
    const Logger &l = Logger::impl();
    if (l.loglevel() < log_level) return;

    std::tuple<Args...> list(args...);

    //std::cerr<< "test: " << std::tuple_size<decltype(list)>::value << "\n";

    std::stringbuf stringbuf;
    std::ostream os(&stringbuf);
    os << "[" << prefix << "] ";

    std::string::size_type last_pos = 0;
    std::string::size_type open_brace = format.find('{', 0);
    while (open_brace != std::string::npos)
    {
        std::string::size_type close_brace = format.find('}', open_brace + 1);
        if (close_brace == std::string::npos)
        {
            open_brace = format.find('{', open_brace + 1);
            continue;
        }

        // TODO: don't create temp string, use pointers
        int tuple_arg = braced_number(std::string(format.begin() + open_brace + 1, format.begin() + close_brace));
        if (tuple_arg == -1)
        {
            open_brace = format.find('{', open_brace + 1);
            continue;
        }

        os << std::string(format.begin() + last_pos, format.begin() + open_brace);
        switch (tuple_arg)
        {    
            case 0: print_tuple_at<0>(list, os); break;
            case 1: print_tuple_at<1>(list, os); break;
            case 2: print_tuple_at<2>(list, os); break;
            case 3: print_tuple_at<3>(list, os); break;
            case 4: print_tuple_at<4>(list, os); break;
            case 5: print_tuple_at<5>(list, os); break;
            case 6: print_tuple_at<6>(list, os); break;
            case 7: print_tuple_at<7>(list, os); break;
            case 8: print_tuple_at<8>(list, os); break;
            case 9: print_tuple_at<9>(list, os); break;
            default: throw std::runtime_error("logger: too many arguments (max = 9)");
        }

        last_pos = close_brace + 1;
        open_brace = format.find('{', close_brace + 1);
    }
    os << std::string(format.begin() + last_pos, format.end()) << std::endl;
    l.log(stringbuf.str().c_str());
}

}   // namespace logger
