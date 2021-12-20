#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

std::string askFile(std::fstream &fstream, const char* type, bool readMode){
    std::cout << type << " file: \t";
    std::string file;
    std::cin >> file;
    if (readMode)
        fstream.open(file, std::ios::binary | std::ios::in);
    else
        fstream.open(file, std::ios::binary | std::ios::out);
    if (!fstream) throw "Unable to open file";
    return file;
}

int main()
{
    int line;
    std::fstream input, output;
    std::string filename;
    try {
        filename = askFile(input, "Input", true); // Название файла необходимо для повторного открытия в конце
        askFile(output, "Output", false);
    } catch (const char* exception) {
        std::cout << "Error: " << exception;
        return 1;
    }


    do {
        std::cout << "Line length: \t";
        std::cin >> line;
    } while (line<=0);

    int s;
    int n;
    for (n = 0; (s = input.get()) != EOF; n += line) {
        output << std::left << std::setfill('0') << std::internal
        << std::setw(16) << std::hex << n << ":" << std::setfill(' ') << std::right; // Волшебные слова из референса
        bool flag = false; // Если flag = true, значит мы дошли до конца, и нужно записать пробелы
        for (int i = 0; i < line; ++i) {
            if (i%8 == 0) if (i!=0) output << " |";
            if (flag) {
                output << "   ";
                continue;
            }
            output << std::setw(3) << s; // Мы перевели поток через std::hex и std::internal в нужный режим выше
            s = input.get();
            if (s == EOF) flag = true;
        }

        if (flag){
            input.close(); // Такое чувство, что каретка не двигается после достижения конца, мне стоило попробовать сделать это через буффер
            input.open(filename,std::ios::binary | std::ios::in);
        }
        output << "  ";
        input.seekg(n, std::ios::beg);
        for (int i = 0; i < line; ++i) {
            s = input.get();
            if (s <= 33) output.put('_');
            else output.put(s);
        }
        output << std::endl;
    }
    return 0;
}
