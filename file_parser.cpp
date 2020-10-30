#include "file_parser.h"

FileParser::FileParser(const std::string file_name) {
    this->line = 1;
    this->file.open(file_name);
    if (!this->file) {
        throw "FileParserException";
    }
}

void FileParser::getInstructions(std::map<std::string, std::vector<std::string>> &instructions, std::string &buffer) {
    std::map <std::string, std::vector< std::string> > instructions_aux;
    std::unordered_map <std::string, std::string> labels;
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
                instructions_aux[std::to_string(this->line)].push_back(token);
            }
            buffer.erase(0, pos + 1);
        }
        if (buffer.compare("") != 0) instructions_aux[std::to_string(this->line)].push_back(buffer);
        ++this->line;
    }

    for (auto &instr : instructions_aux) {
        if (instr.second[0][0] != 'j' && instr.second[0][0] != 'r') {
            int jump_line = stoi(instr.first) + 1;
            instructions[instr.first].push_back(std::to_string(jump_line));
        } else {
            if (instr.second[0][1] != 'm' && instr.second[0][1] != 'a' && instr.second[0][0] != 'r') {
                std::string jump_line = std::to_string(stoi(instr.first) + 1);
                instructions[instr.first].push_back(jump_line);
            }
            for (auto &label : instr.second) {
                if (labels.find(label) != labels.end()){
                    instructions[instr.first].push_back(labels[label]);
                }
            }
        }
    }
}

FileParser::~FileParser() {
    this->file.close();
    this->line = 0;
}
