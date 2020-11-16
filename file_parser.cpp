#include "file_parser.h"
#include "lock.h"

FileParser::FileParser() {
    this->line = 1;
}

void FileParser::getInstructions(std::string &buffer,
                std::map<std::string, std::vector<std::string>> &instructions,
                std::ifstream &file) {
    std::map <std::string, std::vector< std::string> > instructionsAux;
    std::unordered_map <std::string, std::string> labels;
    parseLines(buffer, instructionsAux, labels, file);
    convertLines(instructionsAux, instructions, labels);
    this->line = 0;
}

void FileParser::parseLines(std::string &buffer,
        std::map <std::string, std::vector< std::string> > &instructionsAux,
        std::unordered_map <std::string, std::string> &labels,
        std::ifstream &file) {
    while (std::getline(file, buffer, '\n')) {
        parseLine(buffer, instructionsAux, labels);
    }
}

void FileParser::parseLine(std::string &line,
        std::map <std::string, std::vector< std::string> > &instructionsAux,
        std::unordered_map <std::string, std::string> &labels) {
    std::string delimiter = " ";
    size_t pos = 0;

    while ((pos = line.find(delimiter)) != std::string::npos) {
        std::string token = line.substr(0, pos);
        line.erase(0, pos + 1);
        if (!token.size()) continue;
        if (token.find(':') != std::string::npos) {
            token.pop_back();
            labels[token] = std::to_string(this->line);
            continue;
        }
        if (token.find(',') != std::string::npos) token.pop_back();
        instructionsAux[std::to_string(this->line)].push_back(token);
    }

    if (!line.size()) return;
    instructionsAux[std::to_string(this->line)].push_back(line);
    ++this->line;
}

void FileParser::convertLines(
            std::map <std::string, std::vector< std::string> > &instructionsAux,
            std::map <std::string, std::vector< std::string> > &instructions,
            std::unordered_map <std::string, std::string> &labels) {
    for (auto &instr : instructionsAux) {
        std::string opCode = instr.second[0];
        if (jumpInstr.find(opCode) == jumpInstr.end() && opCode != "ret") {
            int jump_line = stoi(instr.first) + 1;
            instructions[instr.first].push_back(std::to_string(jump_line));
        } else if (opCode == "ret") {
            instructions[instr.first].push_back("-1");
        } else {
            if (inconditionalsJmp.find(opCode) == inconditionalsJmp.end()) {
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
