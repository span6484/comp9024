//
// Created by shao on 2021/11/2.
//
#include <stdio.h>
#include <string.h>
#include "WGraph.h"
#include "list.h"

int main(void) {
    int num_vertex;         //numbers of words
    // step1: save words all into array, scanf print
    freopen("/Users/shao/Documents/unsw/2021-s3/comp9024/C_ENV_SETTING-master/Codes/Assignment/test.txt", "r",
            stdin);
    printf("Enter a number: ");
    scanf("%d", &num_vertex);
    char store_word[num_vertex][32];         //array to store word
    int index = 0;                          //record array index for control adding
    printf("Enter a word: ");
    while (scanf("%s", store_word[index]) == 1) {
        index++;
        printf("Enter a word: ");
        if (index == num_vertex) break;     // jump out when catch enough words
    }
    printf("Done.\n");
//    ------------------Step1        Done-------------------------------------------------

    // STEP2: Add All possibilities into list

    // insert % to word
    List store_word_sign[num_vertex];         //array to store word list
    for(int i = 0; i < num_vertex; i++) {         // array for each word
        // ex: lad
        char word[33];
        strcpy(word,store_word[i]);
        List word_lst = NULL;                // word with its all possibilities store as list: lab->%lab->l%ab

        word_lst = insertLL(word_lst, word);
        store_word_sign[i] = word_lst;
        // PART 1:  add sign % in position i, lab-> %lab, l%ab, la%b, lab%
        char new_word[37];
        new_word[strlen(word)+1] = '\0';            // set where to stop the new word;
        for(int position = 0; position < strlen(word)+1; position++) {
            strcpy(new_word, word);    //reset new_word
            int j;              // control the moving of the unchanged part of word
            for(j = strlen(word)-1; j >= position && j >= 0; j--){
                new_word[j + 1] = new_word[j];
            }
            new_word[j+1] = '%';
            word_lst = insertLL(word_lst, new_word);
        }

        // PART 2: change the word      lab->%ab  l%b -> la%
        char cur_word[33];
        for(int position = 0; position < strlen(word); position++) {
            strcpy(cur_word, word);
            cur_word[position] = '%';
            word_lst = insertLL(word_lst, cur_word);
        }
    }
    //----------------------Step2          Done---------------------------------------------

    // STEP3:
    // Build Graph, compare with the word-list, set the directed graph with case satisfies the condition
//    List store_word_sign[num_vertex];         //array to store word with sign like la%d
//    List list = NULL;
//    list = insertLL(list,"a");
//    list = insertLL(list,"b");
//    store_word_sign[0] = list;
//    List list1 = NULL;
//    list1 = insertLL(list1,"a1");
//    list1 = insertLL(list1,"b1");
//    store_word_sign[1] = list1;
    showLL(store_word_sign[0]);
    showLL(store_word_sign[1]);
    showLL(store_word_sign[2]);
//    freeLL(store_word_sign[0]);
//    freeLL(store_word_sign[1]);
//    freeLL(store_word_sign[2]);
//    printf("%d\n", sizeof(store_word_sign[1]) / sizeof (store_word_sign[1][0]));


    return 0;
}

