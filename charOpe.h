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
            } else {
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

namespace offer_20_1 {
    bool oneCharIsNum(char str) {
        int num = str - '0';
        if(num>=0 && num<10){
            return true;
        }
        return false;
    }
    bool charIsNumNotZero(char str){
        int num = str - '0';
        if(num>0 && num<10){
            return true;
        }
        return false;
    }
    bool checkIntHead(char* str,int index){
        if( charIsNumNotZero(str[index]) || ( (str[index]=='-' || str[index]=='+') && charIsNumNotZero(str[index+1]))){
            return true;
        } else if((str[index]=='0'&&str[index+1]=='.') || ((str[index]=='-' || str[index]=='+')&&(str[index+1]=='0'&&str[index+2]=='.')) ){
            return true;
        }
        return false;
    }
    bool checkFloatHeat(char* str,int index){
        if(str[index]=='.' && charIsNumNotZero(str[index+1])){
            return true;
        }
        return false;
    }
    bool checkEHeat(char* str,int index){
        if( (str[index]=='e' || str[index]=='E') && (charIsNumNotZero(str[index+1]) || ((str[index+1]=='-' ||  str[index+1]=='+')&&charIsNumNotZero(str[index+2])) ) ){
            return true;
        }
        return false;
    }
    //不需要模式检测，因为不同模式之间是由无符号整形或有符号整形分割的，重点思考模式是如何转换的。
    bool isNum(char* num) {
        bool IsInteger = checkIntHead(num,0);
        bool IsFloat = checkFloatHeat(num,0);
        bool IsE = false;
        int eStart = -1;
        if(!IsInteger&&!IsFloat){
            return false;
        }
        int i = 1;
        while (num[i] != '\0') {
            if (IsInteger) {
                if(checkFloatHeat(num,i)){
                    if (IsFloat){
                        return false;
                    }else{IsFloat=true;IsInteger= false;i++;
                        continue;}
                } else if (checkEHeat(num,i)){
                    if(IsE){
                        return false;
                    } else{IsFloat= true;IsInteger=false;eStart=i;i++;
                        continue;}
                }
                if(!oneCharIsNum(num[i])){
                    return false;
                }
            }

            if(IsFloat){
                if(checkEHeat(num,i)){
                    if(IsE){
                        return false;
                    } else{IsFloat= false;IsE=true;eStart=i;i++;
                        continue;}
                }
                if(!oneCharIsNum(num[i])){
                    return false;
                }
            }
            if(IsE){
                if(i == eStart+1){
                    if(!(oneCharIsNum(num[i]) || (num[i]=='-' || num[i]=='+') )){
                        return false;
                    }
                }else if(!oneCharIsNum(num[i])){
                    return false;
                }
            }
            i++;
        }
        return true;

    }
    namespace right{
        bool isUnsignedNum(const char** str){
            const char* before = *str;
            while(**str!='\0' && **str>='0'&&**str<='9'){
                (*str)++;
            }
            return *str>before;
        }
        bool isNum(const char** str){
            if(**str=='+'||**str=='-'){
                (*str)++;
            }
            return isUnsignedNum(str);
        }
        bool isNumeric(const char* str){
            if(str== nullptr){
                return false;
            }
            bool numeric = isNum(&str);
            if(*str=='.'){
                str++;
                numeric = numeric || isUnsignedNum(&str);
            }
            if(*str=='e'||*str=='E'){
                str++;
                numeric = numeric && isNum(&str);
            }
            return numeric;
        }
    }
}