#pragma once

#define BOOST_LOG_DYN_LINK
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace Framework {
  class Logger {
    public:
      static boost::log::sources::logger logger;
  };
};
