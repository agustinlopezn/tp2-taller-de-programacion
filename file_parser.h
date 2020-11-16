#ifndef __FILE_PARSER_H
#define __FILE_PARSER_H

#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <unordered_set>
#include "thread.h"
#include "files.h"

class FileParser {
 private:
    int line;
    std::unordered_set <std::string> jumpInstr {"jmp", "ja", "jeq", "jneq",
                                "jne", "jlt", "jle", "jgt",  "jge", "jset"};
    std::unordered_set <std::string> inconditionalsJmp {"jmp", "ja"};
    
    // Parse the line passed by parameter and puts the information needed in
    // instructionsAux, if the line has a label puts it in the unordered_map
    // labels in the format <label, lineNumber>
    void parseLine(std::string &line,
        std::map <std::string, std::vector< std::string> > &instructionsAux,
        std::unordered_map <std::string, std::string> &labels);
    
    // Converts the lines in instructionAux (using labels info) to the final
    // format <lineNumber, jumpsToLineNumber>, by using the sets attributes
    // to diferenciate the behaviors
    void convertLines(
            std::map <std::string, std::vector< std::string> > &instructionsAux,
            std::map <std::string, std::vector< std::string> > &instructions,
            std::unordered_map <std::string, std::string> &labels);
    
    // Reads line by line from the file and calls parseLine() for each.
    void parseLines(std::string &buffer,
            std::map <std::string, std::vector< std::string> > &instructionsAux,
            std::unordered_map <std::string, std::string> &labels,
            std::ifstream &file);

 public:
    // Constructor and destructor
    FileParser();
    ~FileParser();

    // Parse the instructions from the file received and
    // puts them in the map passed by argument
    void getInstructions(std::string &buffer,
            std::map<std::string, std::vector<std::string>> &instructions,
            std::ifstream &file);
};

#endif  // FILE_PARSER_H_
