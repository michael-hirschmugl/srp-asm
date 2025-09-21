#include "assembler.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    const char* inFileName = argv[1];
    const char* outFileName = argv[2];

    SrpAsm::Assembler asmbl(inFileName);   // parse & assemble the source file

    auto temp = asmbl.program();

    for (auto const &str : temp)
    {
        std::cout << str << std::endl;
    }

    std::ofstream outFile(outFileName, std::ios::binary); // Öffne die Datei im Binärmodus
    if (!outFile) {
        std::cerr << "Fehler beim Öffnen der Datei!" << std::endl;
        return 1;
    }

    outFile.write(reinterpret_cast<const char*>(temp.data()), temp.size() * sizeof(uint32_t));

    outFile.close();

}
