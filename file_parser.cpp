#include "file_parser.h"
#include "lock.h"

FileParser::FileParser(Files &files) :
    line(1), files(files) {}

void FileParser::getInstructions(std::string &buffer,
                std::map<std::string, std::vector<std::string>> &instructions) {
    std::map <std::string, std::vector< std::string> > instructionsAux;
    std::unordered_map <std::string, std::string> labels;
    this->actualFile = this->files.getFile(this->file);
    parseLines(buffer, instructionsAux, labels);
    this->file.close();
    convertLines(instructionsAux, instructions, labels);
    this->line = 0;
}

bool FileParser::areFilesToProcces() {
    return this->files.areFilesToProcces();
}

std::string FileParser::proccessedFile() {
    return this->actualFile;
}

void FileParser::parseLines(std::string &buffer,
        std::map <std::string, std::vector< std::string> > &instructionsAux,
        std::unordered_map <std::string, std::string> &labels) {
    while (std::getline(this->file, buffer, '\n')) {
        std::string delimiter = " ";
        size_t pos = 0;
        while ((pos = buffer.find(delimiter)) != std::string::npos) {
            std::string token = buffer.substr(0, pos);
            if (token.find(':') != std::string::npos) {
                token.pop_back();
                labels[token] = std::to_string(this->line);
            } else if (token.compare("") != 0) {
                if (token.find(',') != std::string::npos) {
                    token.pop_back();
                }
                instructionsAux[std::to_string(this->line)].push_back(token);
            }
            buffer.erase(0, pos + 1);
        }
        if (buffer.compare("") != 0) {
            instructionsAux[std::to_string(this->line)].push_back(buffer);
            ++this->line;
        }
    }
}

void FileParser::convertLines(
            std::map <std::string, std::vector< std::string> > &instructionsAux,
            std::map <std::string, std::vector< std::string> > &instructions,
            std::unordered_map <std::string, std::string> &labels) {
    for (auto &instr : instructionsAux) {
        if (instr.second[0][0] != 'j' && instr.second[0][0] != 'r') {
            int jump_line = stoi(instr.first) + 1;
            instructions[instr.first].push_back(std::to_string(jump_line));
        } else if (instr.second[0][0] == 'r') {
            instructions[instr.first].push_back("-1");
        } else {
            if (instr.second[0][1] != 'm' && instr.second[0][1] != 'a') {
                std::string jump_line = std::to_string(stoi(instr.first) + 1);
                instructions[instr.first].push_back(jump_line);
            }
            for (auto &label : instr.second) {
                if (labels.find(label) != labels.end()) {
                    instructions[instr.first].push_back(labels[label]);
                }
            }
        }
    }
}

FileParser::~FileParser() {
    this->line = 0;
}
