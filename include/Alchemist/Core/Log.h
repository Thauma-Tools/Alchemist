#ifndef __ALCHEMIST_CORE_LOG_H_
#define __ALCHEMIST_CORE_LOG_H_

#include <Alchemist/Config.h>

#include <string>

namespace tt
{

class Logger
{
  public:
    static Logger TTAPI create(std::string);

    void TTAPI log(const std::string);

  private:
    Logger(std::string);

    std::string name;
};

} // namespace tt

#endif // __ALCHEMIST_CORE_LOG_H_
