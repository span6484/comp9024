//
// Created by shao on 2021/11/2.
//
#include <stdio.h>
#include <string.h>
#include "WGraph.h"
#include "list.h"
int main(void) {
    int num_vertex;         //numbers of words
    // step1: save words all into array
//    freopen("/Users/shao/Documents/unsw/2021-s3/comp9024/C_ENV_SETTING-master/Codes/Assignment/test.txt", "r",
//            stdin);
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

    // step2: create Graph and connect the edges

    // create the graph
//    Graph graph = newGraph(num_vertex);


    // insert % to word
//    char store_word_sign[num_vertex][65][33];         //array to store word with sign like la%d
//    int k = 0;                                              // store_word_sign[i][k]: k = 0 %d
//    for(int i = 0; i < num_vertex; i++) {         // array for each word
//        // ex: lad
//        char word[32];
//        strcpy(word,store_word[i]);
//        int m = 0;
//        // add sign % in position i, lab-> %lab, l%ab, la%b, lab%
//        char new_word[strlen(store_word)+1];
////        printf("word now is %s\n", word);
////        printf("old word len is %d\n", strlen(word));
//        for(int position = 0; position < strlen(word)+1; position++) {
//            strcpy(new_word, word);    //reset new_word
//            int j;              // control the moving of the unchanged part of word
//            for(j = strlen(word)-1; j >= position && j >= 0; j--){
//                new_word[j + 1] = new_word[j];
//            }
//            new_word[j+1] = '%';
//
//            strcpy(store_word_sign[k][m], new_word);
//            m++;
//        }
//
//        // change the word      lab->_ab  l_b -> la_
//        char cur_word[strlen(store_word)];
//        for(int position = 0; position < strlen(word); position++) {
//            strcpy(cur_word, word);
//            cur_word[position] = '%';
//            strcpy(store_word_sign[k][m],cur_word);
//            m++;
//        }
//        k++;
//    }
//    printf("%d\n", sizeof(store_word_sign[1]) / sizeof (store_word_sign[1][0]));


    List list = NULL;
    list = insertLL(list, "12");
    list = insertLL(list, "lad");
    list = insertLL(list, "lac");
    showLL(list);
    freeLL(list);
    return 0;
}

