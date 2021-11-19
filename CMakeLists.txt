cmake_minimum_required(VERSION 3.14)
project(C_ENV_SETTING C)

set(CMAKE_C_STANDARD 11)

add_executable(stack
        Codes/lab_learn/stack.c Codes/lab_learn/stack.h Codes/lab_learn/stackMain.c)

#add_executable(problem_set
#       Codes/lab_learn/3001_list_single_str.c Codes/lab_learn/3001_list_single_str_main.c Codes/lab_learn/3000_1list_single_str.h)
add_executable(problem_set
        Codes/lab_learn/3005_graph.c Codes/lab_learn/3005_graph.h Codes/lab_learn/3005_graphMain.c Codes/lecture_program/test/graph.c Codes/lecture_program/test/graph.h)

#add_executable(problem_set
#        Codes/lab_learn/graph.c Codes/lab_learn/graph.h Codes/lab_learn/graph_main.c)

add_executable(wee4_graph
        Codes/ Codes/lecture_program/week4/Graph.c Codes/lecture_program/week4/Graph.h Codes/lecture_program/week4/GraphMain.c)


add_executable(FollowerBase Codes/problem_set/week5/Dijkstra/WGraph.c Codes/problem_set/week5/Dijkstra/WGraph.h Codes/problem_set/week5/Dijkstra/dijkstra.c)
add_executable(test Codes/test.c)
add_executable(warshall_alg Codes/Warshall's_Algorithm/warshall_alg.c Codes/Warshall's_Algorithm/graph.c Codes/Warshall's_Algorithm/graph.h Codes/Warshall's_Algorithm/lib_graph.h)

add_executable(dijkstra
        Codes/problem_set/week5/Dijkstra/dijkstra.c
        Codes/problem_set/week5/Dijkstra/WGraph.c
        Codes/problem_set/week5/Dijkstra/WGraph.h
        Codes/problem_set/week5/Dijkstra/PQueue.c
        Codes/problem_set/week5/Dijkstra/PQueue.h
        )

add_executable(BST Codes/problem_set/week7/BSTree/BSTree.c Codes/problem_set/week7/BSTree/BSTree.h Codes/problem_set/week7/BSTree/BST_main.c)


add_executable(assignment Codes/Assignment/WGraph.c Codes/Assignment/WGraph.h Codes/Assignment/words.c Codes/Assignment/list.c Codes/Assignment/list.h Codes/Assignment/PQueue.c Codes/Assignment/PQueue.h)
add_executable(BSTree Codes/week7/BSTree/BSTree.c Codes/week7/BSTree/BSTree.h)
add_executable(treeLab Codes/problem_set/week8/BST_modify/treeLab.c Codes/problem_set/week8/BST_modify/BST.c Codes/problem_set/week8/BST_modify/BST.h)
add_executable(RBTree Codes/problem_set/week8/RBTree/RBTree.c Codes/problem_set/week8/RBTree/RBTree.h)
add_executable(problem_set10 Codes/problem_set/week10 Codes/problem_set/week10/mypassword.c)