cmake_minimum_required(VERSION 3.20)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkList List/llist.c)
add_executable(LinkList2 List/llist2.c)
add_executable(SeqList List/slist.c)
add_executable(SeqString List/seqstring.c)

add_executable(LinkStack Stack/lstack.c)
add_executable(SeqStack Stack/sstack.c)
add_executable(Maze Stack/maze.c)

add_executable(SeqQueue Queue/squeue.c)
add_executable(BinTree BinTree/huffman.c)
add_executable(Tree BinTree/tree_child.c)

add_executable(Dic Dic/dic_hashopen.c)

add_executable(Graph Graph/graph_adjmat.c)
add_executable(GraphKruskal Graph/graph_kruskal.c)
add_executable(GraphPrim Graph/graph_prim.c)
