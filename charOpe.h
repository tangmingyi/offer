//
// Created by tmy on 19-8-6.
//

//#ifndef OFFER_REPLACE_BLANK_H
//#define OFFER_REPLACE_BLANK_H
//
//#endif //OFFER_REPLACE_BLANK_H

namespace offer_5_1 {

    void replace_blank(char string[], int length) {
        int blank_num = 0;
        int i = 0;
        int new_length;
        while (string[i] != '\0') {
            if (string[i] == ' ') {
                blank_num++;
            }
            ++i;
        }
        new_length = i + blank_num * 2;
        if (new_length > length) {
            return;
        }
        int old_index = i;
        int new_index = new_length;
        while (old_index >= 0) {
            if (string[old_index] != ' ') {
                string[new_index--] = string[old_index];
            } else {
                string[new_index--] = '0';
                string[new_index--] = '2';
                string[new_index--] = '%';
            }
            --old_index;

        }

    }
}

namespace offer_19_1 {

    bool core(char *str, char *pattern, int strIndex, int patternIndex) {
        if (str[strIndex] == '\0' && pattern[patternIndex] == '\0') {
            return true;
        }
        if ((str[strIndex] == '\0' || pattern[patternIndex] == '\0') &&
            (str[strIndex] != '\0' || pattern[patternIndex] != '\0')) {
            return false;
        }
        if (pattern[patternIndex + 1] != '*') {
            if (pattern[patternIndex] == str[strIndex] || pattern[patternIndex] == '.') {
                return core(str, pattern, strIndex + 1, patternIndex + 1);
            } else {
                return false;
            }
        } else {
            if ((pattern[patternIndex] == str[strIndex] || pattern[patternIndex] == '.') &&
                (pattern[patternIndex + 2] == str[strIndex] || pattern[patternIndex + 2] == '.')) {
                strIndex++;
                if (pattern[patternIndex + 3] == '*') {
                    return core(str, pattern, strIndex, patternIndex) ||
                           core(str, pattern, strIndex, patternIndex + 2);
                } else {
                    return core(str, pattern, strIndex, patternIndex) ||
                           core(str, pattern, strIndex, patternIndex + 3);
                }
            } else if (pattern[patternIndex + 2] == str[strIndex] || pattern[patternIndex + 2] == '.') {
                return core(str, pattern, strIndex + 1, patternIndex + 2);
            } else if (pattern[patternIndex] == str[strIndex] || pattern[patternIndex] == '.') {
                return core(str, pattern, strIndex + 1, patternIndex);
            } else {
                return false;
            }
        }
    }

    bool core2(char *str, char *pattern, int strIndex, int patternIndex) {
        if (str[strIndex] == '\0' && pattern[patternIndex] == '\0') {
            return true;
        }
        if ((str[strIndex] == '\0' || pattern[patternIndex] == '\0') &&
            (str[strIndex] != '\0' || pattern[patternIndex] != '\0')) {
            return false;
        }
        if (pattern[patternIndex + 1] != '*') {
            if (pattern[patternIndex] == str[strIndex] || pattern[patternIndex] == '.') {
                return core2(str, pattern, strIndex + 1, patternIndex + 1);
            } else {
                return false;
            }
        } else {
            if (pattern[patternIndex] == str[strIndex] || pattern[patternIndex] == '.') {
                return core2(str, pattern, strIndex + 1, patternIndex) ||
                       core2(str, pattern, strIndex + 1, patternIndex + 2) ||
                       core(str, pattern, strIndex, patternIndex + 2);
            }else{
                return false;
            }
        }
    }

    bool match(char *str, char *pattern) {
        int strIndex = 0;
        int patternIndex = 0;
        return core2(str, pattern, strIndex, patternIndex);
    }
}