#ifndef __FILE_PARSER_H
#define __FILE_PARSER_H

#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include "thread.h"
#include "files.h"

class FileParser {
 private:
    int line;
    std::ifstream file;
    std::string actualFile;
    Files &files;
    void convertLines(
            std::map <std::string, std::vector< std::string> > &instructionsAux,
            std::map <std::string, std::vector< std::string> > &instructions,
            std::unordered_map <std::string, std::string> &labels);
    void parseLines(std::string &buffer,
            std::map <std::string, std::vector< std::string> > &instructionsAux,
            std::unordered_map <std::string, std::string> &labels);
 public:
    explicit FileParser(Files &files);
    // Parse the instructions and puts it in the map passed by argument
    void getInstructions(std::string &buffer,
            std::map<std::string, std::vector<std::string>> &instructions);
    // Returns the last proccessed file
    std::string proccessedFile();
    // Returns true if there is a file to proccess, false otherwise
    bool areFilesToProcces();
    ~FileParser();
};

#endif  // FILE_PARSER_H_
