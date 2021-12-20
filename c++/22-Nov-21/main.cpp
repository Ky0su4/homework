#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

std::string askFile(std::fstream &fstream, const char* type, bool read){
    std::cout << type << " file: \t";
    std::string file;
    std::cin >> file;
    if (read)
        fstream.open(file, std::ios::binary | std::ios::in);
    else
        fstream.open(file, std::ios::binary | std::ios::out);
    if (!fstream) throw "Unable to open file";
    return file;
}


int main()
{
    std::fstream input, output;

    auto filename = askFile(input, "Input", true);
    askFile(output, "Output", false);

    int s;
    int n = 0;
    while ((s = input.get()) != EOF) {
        output << std::left << std::setfill('0');
        output << std::internal << std::setw(16) << std::hex << n << ":";
        output << std::setfill(' ') << std::right;
        bool flag = false;
        for (int i = 0; i < 8; ++i) {
            if (flag) {
                output << "   ";
                continue;
            }
            output << std::setw(3) << s;
            s = input.get();
            if (s == EOF) {
                flag = true;
            }
        }
        output << " |";
        for (int i = 0; i < 8; ++i) {
            if (flag) {
                output << "   ";
                continue;
            }
            output << std::setw(3) << s;
            s = input.get();
            if (s == EOF) {
                flag = true;
            }
        }
        if (!flag) {
            output << "  ";
            input.seekg(n, std::ios::beg);
            for (int i = 0; i < 16; ++i) {
                s = input.get();
                if (s <= 33) output.put('.');
                else output.put(s);
            }
            output << std::endl;
            output.flush();
            n += 16;
        }
    }

    // Костыль, я открываю и дочитываю файл после дохождения до конца, без понятия почему не работает, стоит попробовать сделать через буффер

    input.close();
    input.open(filename,std::ios::binary | std::ios::in);
    output << "  ";
    input.seekg(n, std::ios::beg);
    for (int i = 0; i < 16; ++i) {
        s = input.get();
        if (s <= 33) output.put('.');
        else output.put(s);
    }
    output << std::endl;
    output.flush();
    n += 16;

    return 0;
}
