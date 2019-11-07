#ifndef OPTION_H
#define OPTION_H

#include <boost/shared_ptr.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdint.h>
#define Random(x) (rand() % (x))

namespace dhcp{
/*
typedef std::vector<uint8_t> OptionBuffer;
typedef boost::shared_ptr<OptionBuffer> OptionBufferPtr;
typedef OptionBuffer::iterator OptionBufferIter;
typedef OptionBuffer::const_iterator OptionBufferConstIter;

class option;
typedef boost::shared_ptr<option> OptionPtr;

size_t RandomFactory(){
    srand((int)time(0));
    size_t res = rand();
    return res;
}
*/
const static std::string flagStr = "EdSj";
class option {

private:
    std::string option_;


    
public:
    const static size_t OPTION4_HDR_LEN = 2;

    option();

    option(uint8_t messageType);

    //option(uint8_t optionType, const OptionBuffer & data);

    //option(uint8_t optionType, OptionBufferConstIter first, OptionBufferConstIter last);

    option(const option & source);

    void AddEssentialOption();

    void AddOptionalOptionn(uint8_t optionType);

    void EndOption();

    const std::string GetOption() const {return option_;};
};
}

#endif
