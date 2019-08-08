//
// Created by tmy on 19-8-6.
//

//#ifndef OFFER_REPLACE_BLANK_H
//#define OFFER_REPLACE_BLANK_H
//
//#endif //OFFER_REPLACE_BLANK_H

namespace offer_5_1{

    void replace_blank(char string[],int length){
        int blank_num=0;
        int i = 0;
        int new_length;
        while (string[i]!='\0'){
            if (string[i] == ' '){
                blank_num++;
            }
            ++i;
        }
        new_length = i + blank_num * 2;
        if (new_length > length){
            return;
        }
        int old_index = i;
        int new_index = new_length;
        while (old_index >= 0){
            if (string[old_index] != ' '){
                string[new_index--] = string[old_index];
            } else{
                string[new_index--] = '0';
                string[new_index--] = '2';
                string[new_index--] = '%';
            }
            --old_index;

        }

    }
}