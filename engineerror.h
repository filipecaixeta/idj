#pragma once
#include <iostream>
#include <string>

void printErro(std::string msg,std::string msg2="")
{
    std::cerr << "Erro em " <<  __FILE__ << " linha " << __LINE__ << std::endl;
    std::cerr << msg << " " << msg2 << std::endl;
}
