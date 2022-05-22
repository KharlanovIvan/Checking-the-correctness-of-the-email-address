#include <iostream>

bool validLetter (char l) {
    if (l >= 'A' && l <= 'Z' || l >= 'a' && l <= 'z' || l >= '0'
      && l <= '9' || l == '.' || l == '-') {
        return true;
    }
    else return false;
}

bool validSymbol (char s) {
    std::string val = "!#$%&'*+-/=?^_`{|}~";
    for (int i = 0; i < val.length(); i++) {
        if (s == val[i]) {
            return true;
        }
    }
    return false;
}

int part1 (std::string str) {
    if (str[0] == '@' || str[0] == '.' ) return -1;
    for (int i = 0; i < str.length(); i++) {
        if (str [i] == '@') return i;
        else if (i > 64 || !validLetter(str[i]) && !validSymbol(str[i])
          || str[i] == '.' && str[i + 1] == '.') return -1;
    }
    return -1;
}

int part2 (std::string str) {
    int n = part1(str) + 1;
    if (str[n] == '.' || str [str.length() - 1] == '.') return -1;
    for (int i = n; i < str.length(); i++) {
        if (i > n + 62 || !validLetter(str[i]) || str[i] == '.' && str[i - 1] == '.') return -1;
    }
    return 0;
}

int main() {
        std::cout << "Enter your email address : " << std::endl;
        std::string email;
        std::getline(std::cin, email);

        part1(email) >= 0 && part2(email) >= 0 ? std::cout << "Yes!\n" : std::cout << "No!\n" << std::endl;

    return 0;
}
