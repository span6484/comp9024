/*
 * Assignment COMP9024 Complexities Analysis
 * Created by shao on 2021/11/2
 *
 * The program includes 3 steps which includes:
 *  - Print words sequence and store them
 *  - Build ArrayList
 *  - Find the maximum sequence and print them out
 * Because we require to analyse the bad worst case , so we will ignore the name variable complexity  O(1)
 * Step 1
 * Here we applied the loop to store the string printed by scanf, the time complexity of it is O(n)
 * The worst time complexity of step2 is O(n)
 *
 * Step 2
 *  - We apply loop outside to iterate all words, O(n)
 *  - PART 1
 *  - In the loop, we use strcpy() to copy the words content, total: O(n^2)
 *  - the inserLL() is O(n), because in the loop, O(n^2)
 *  - Now we come to the Part1
 *  - We use Nesting cycle to find out where we should add the sign,because the string length here will 1 more than the origin input, because it needs to add % ,it cost O((n+1)^2) , same to the strcpy() and insertLL(), total: O(n^3)
 *  - PART 2
 *  - Using the Iteration to change each char in string one by one, total O(n^2)
 *
 *  The worst time complexity of step2 is O(n^3)
 *
 * Step 3
 *  - PART 1
 *  - Initial the graph, newGraph()  is O(n)
 *  - two loop to read out all case of words with signs , which we added in step1's linkedlist. O(n^2)
 *  - inside the nesting cycle, find string which satisfy the condition via compareTwostr(), O(n^3)  total: O(n^5)
 *  - then display the path via displayPath(), O(n^2)
 *  -PART 2
 *  - Apply the findLongestSeequence() to print out the max sequence number and items,
 *  - Repeat, this part modified Michael's Dijkstra code which published in Promblem set 5
 *  - Under the queue: O(n)
 *  - pop from the priority Queue cose O(n), total: O(n^2)
 *  - add into the dist array and path array O(n), total: O(n^2)
 *
 *
 *  - Then, find the max sequence via a loop: O(n)
 *  - print the all words: O(n)
 *
 * In conclusion, the worst time complexity costs O(n^5) where in the step3 part 1;
 *
 *
 *
 *
 *
 *
*/
#include <stdio.h>
#include <string.h>
//#include "WGraph.h"
#include "list.h"
#include "PQueue.h"
#define VERY_LOW_VALUE -999999
int findMax(int s, int pred[], char store_word[][32], int max);        //find the max length of sequence
void findLongestSequence(Graph graph, char store_word[][32], int num_vertex);
void showPath(int s, int pred[], char store_word[][32]);
int main(void) {
    int num_vertex;         //numbers of words
    //----------------------Step1          Start---------------------------------------------

    // save words all into array, and basic print
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
//----------------------Step1          Done-------------------------------------------------

//----------------------Step2          Start---------------------------------------------

    // Add All possibilities into list

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

    //----------------------Step3          Start---------------------------------------------
    // Build Graph, compare with the word-list, set the directed graph with word satisfies the condition

    // PART1: printout words and its connected words

    Graph graph = newGraph(num_vertex);
    Edge e;
    int j;
    List compare_list;                 //store per word situations to compare
    for(int i = 0; i < num_vertex; i++) {
        compare_list = store_word_sign[i];
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

    //Part2: print out the max sequence number and items
    findLongestSequence(graph, store_word, num_vertex);
    freeGraph(graph);
    for(int i = 0; i < num_vertex; i++) {
        freeLL(store_word_sign[i]);
    }
    //----------------------Step3          Done---------------------------------------------

    return 0;
}
//PART 2: start with dijkstra to find the longest path
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/* !!! This part is adapted from the Dijkstra code published by Michael in Problem set 5!!!!!! */
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void findLongestSequence(Graph graph, char store_word[][32], int num_vertex) {

    int source = 0;                 //define the start point
    int s, cur, path;
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
        cur = popPQueue(dist);
        for (int i = cur+1; i < num_vertex; i++) {
            path = adjacent(graph, cur, i);
            if (path > 0 && path + dist[cur] > dist[i]) {
                dist[i] = path + dist[cur];
                pred[i] = cur;
            }
        }
    }

    // find the max value
    int max = 0;
    for (s = source; s < num_vertex; s++) {
        if (max < dist[s]){
            max = dist[s];
        }
    }
    int max1 = 0;
    for (s = source; s < num_vertex; s++) {
        if (dist[s] == max){
            max1 = findMax(s, pred, store_word,max1);
            break;
        }
    }
    printf("Maximum sequence length: %d\n",max1);
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
int findMax(int s, int pred[], char store_word[][32], int max) {
    if(pred[s] == -1) {
        max++;
    }
    else{
        max = findMax(pred[s], pred, store_word,max);
        max++;
    }
    return max;
}