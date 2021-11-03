//
// Created by shao on 2021/11/2.
//
#include <stdio.h>
#include <string.h>
//#include "WGraph.h"
#include "list.h"
#include "PQueue.h"
#define VERY_LOW_VALUE -999999

void findLongestSequence(Graph graph, char store_word[][32], int num_vertex);
void showPath(int s, int pred[], char store_word[][32]);
int main(void) {
    int num_vertex;         //numbers of words
    // step1: save words all into array, scanf print
//    freopen("/Users/shao/Documents/unsw/2021-s3/comp9024/C_ENV_SETTING-master/Codes/Assignment/test.txt", "r",
//            stdin);
    printf("Enter a number: ");
    scanf("%d", &num_vertex);
    char store_word[num_vertex][32];         //array to store word
    int index = 0;                          //record array index for control adding
    printf("Enter a word: ");
    while (index < num_vertex) {
        scanf("%s", store_word[index]);
        index++;
        if(index < num_vertex) {
            printf("Enter a word: ");
        }
    }
    printf("\n");
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
//    showLL(store_word_sign[0]);
    //----------------------Step2          Done---------------------------------------------

    // STEP3:
    // Build Graph, compare with the word-list, set the directed graph with word satisfies the condition

    // PART1: printout words and its connected words

    Graph graph = newGraph(num_vertex);
    Edge e;
    int i;
    int j;
    for(i = 0; i < num_vertex; i++) {
        List compare_list = store_word_sign[i];
        for(j = i + 1; j < num_vertex; j++){
            // add edge if word satisfies the condition:
            List compare_list2 = store_word_sign[j];
            if (compareTwoStr(compare_list,compare_list2)) {
                e.v = i;
                e.w = j;
                e.weight = 1;
                insertEdge(graph,e);
            }
        }
    }

    displayPath(graph,store_word,num_vertex);
    printf("\n");
    //PART 2: start with dijkstra to find the longest path
    //
    findLongestSequence(graph, store_word, num_vertex);
    return 0;
}

void findLongestSequence(Graph graph, char store_word[][32], int num_vertex) {

    int source = 0;                 //define the start point
    //start with difference point
    // Learn from the dijkstra code
//    printf("source:    %d\n\n",source);
    int s, cur, path;
    s = source;
    int dist[MAX_NODES];
    int pred[MAX_NODES];
    PQueueInit();
    for (s = 0; s < num_vertex; s++) {
        joinPQueue(s);
        dist[s] = VERY_LOW_VALUE;
        pred[s] = -1;
    }
    dist[source] = 1;
    while (!PQueueIsEmpty()) {
//        printf("dist---\n");
        for(int i = 0; i < num_vertex; i++) {
//            printf("%d:  %d  ",i, dist[i]);
        }
        cur = popPQueue(dist);
//        printf("cur: %d\n",cur);
        for (int i = cur+1; i < num_vertex; i++) {
            path = adjacent(graph, cur, i);
//
//            printf("for the point cur: %d,  i: %d, path is %d ",cur, i, path);
//            printf("dist_i[%d] is %d   ", i, dist[i]);
//            printf("dist_cur[%d] is %d   ", cur, dist[cur]);
            if (path > 0 && path + dist[cur] > dist[i]) {
                dist[i] = path + dist[cur];
//                printf("after add dis is %d\n", dist[i]);
                pred[i] = cur;
            }
//            printf("\n");
        }
    }

    // find the max value
    int max = 0;
    for (s = source; s < num_vertex; s++) {
        if (max < dist[s]){
            max = dist[s];
        }
    }
    printf("Maximum sequence length: %d\n",max);
    printf("Maximal sequence(s):\n");
    for (s = source; s < num_vertex; s++) {
        if (dist[s] == max){
            showPath(s, pred, store_word);
            putchar('\n');
        }
    }





}
void showPath(int s, int pred[], char store_word[][32]) {
    if(pred[s] == -1) {
        printf("%s",store_word[s]);
    }
    else{
        showPath(pred[s], pred, store_word);
        printf(" -> %s",store_word[s]);
    }
}