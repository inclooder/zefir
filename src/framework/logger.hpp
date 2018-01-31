#ifndef FRAMEWORK_LOGGER_H
#define FRAMEWORK_LOGGER_H

#define BOOST_LOG_DYN_LINK 
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace Framework {
  class Logger {
    public:
      static boost::log::sources::logger logger;
  };
};



#endif /* end of include guard: FRAMEWORK_ */
