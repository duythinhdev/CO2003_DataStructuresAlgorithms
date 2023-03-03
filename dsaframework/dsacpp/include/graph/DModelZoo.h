/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelZoo.h
 * Author: ltsach
 *
 * Created on July 13, 2021, 8:41 PM
 */

#ifndef DMODELZOO_H
#define DMODELZOO_H

#include "graph/DGraphModel.h"
#include <string>
using namespace std;

char    A='A', B='B', C='C', D='D', E='E', \
        F='F', G='G', H='H', I='I', J='J', \
        K='K', L='L', M='M', N='N', O='O', \
        P='P', Q='Q', R='R', S='S', T='T', \
        U='U', V='V', X='X', Y='Y', Z='Z', W='W';

bool vertexEQ(char& a, char& b){
    return a == b;
}
string vertex2str(char& v){
    return std::to_string(v);
}

bool vertexEQ(int& a, int& b){
    return a == b;
}
string vertex2str(int& v){
    return std::to_string(v);
}

bool vertexEQ(string& a, string& b){
    return a == b;
}
string vertex2str(string& v){
    return v;
}
/*
 https://i.ibb.co/B3RjSW3/DAG-5v.png
 */
IGraph<char>* burglary_earthquake(){
    char vertices[] = {B, E, A, M, J};
    Edge<char> edges[] = {
        Edge<char>(B, A),
        Edge<char>(E, A),
        Edge<char>(A, M),
        Edge<char>(A, J)
    };
    return DGraphModel<char>::create(
            vertices, sizeof(vertices)/sizeof(char),
            edges, sizeof(edges)/sizeof(Edge<char>),
            &vertexEQ, &vertex2str);
}

/*
 https://i.ibb.co/CsT98bx/DAG-6v.png
 */

IGraph<char>* dag_triangles_7v(){
    char vertices[] = {A, B, C, D, E, F, G};
    Edge<char> edges[] = {
        Edge<char>(A, B),
        Edge<char>(A, C),
        Edge<char>(A, F),
        Edge<char>(B, F),
        Edge<char>(C, F),
        Edge<char>(D, B),
        Edge<char>(D, F),
        Edge<char>(D, G),
        Edge<char>(E, C),
        Edge<char>(E, F),
        Edge<char>(E, G),
        Edge<char>(F, G)
    };
    return DGraphModel<char>::create(
            vertices, sizeof(vertices)/sizeof(char),
            edges, sizeof(edges)/sizeof(Edge<char>),
            &vertexEQ, &vertex2str);
}


/*
 https://i.ibb.co/1YVnYSn/DAG-0-9.png
 */

IGraph<int>* dag_lattice_0_9(){
    int vertices[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Edge<int> edges[] = {
        Edge<int>(0, 1),
        Edge<int>(0, 5),
        Edge<int>(1, 7),
        Edge<int>(3, 2),
        Edge<int>(3, 4),
        Edge<int>(3, 7),
        Edge<int>(3, 8),
        Edge<int>(4, 8),
        Edge<int>(6, 0),
        Edge<int>(6, 1),
        Edge<int>(6, 2),
        Edge<int>(8, 2),
        Edge<int>(8, 7),
        Edge<int>(9, 4)
        
    };
    return DGraphModel<int>::create(
            vertices, sizeof(vertices)/sizeof(int),
            edges, sizeof(edges)/sizeof(Edge<int>),
            &vertexEQ, &vertex2str);
}
/*
https://i.ibb.co/4TY2fwJ/DAG-weights-8v.png
 */

IGraph<char>* dag_weights_8v(){
    char vertices[] = {S, A, B, C, D, E, F, T};
    Edge<char> edges[] = {
        Edge<char>(S, A, 2),
        Edge<char>(S, C, 4),
        Edge<char>(S, E, 1),
        Edge<char>(A, B, 5),
        Edge<char>(C, A, 2),
        Edge<char>(C, F, 3),
        Edge<char>(E, D, 2),
        Edge<char>(E, F, 3),
        Edge<char>(B, T, 3),
        Edge<char>(D, B, 5),
        Edge<char>(D, T, 2),
        Edge<char>(F, T, 1)
    };
    return DGraphModel<char>::create(
            vertices, sizeof(vertices)/sizeof(char),
            edges, sizeof(edges)/sizeof(Edge<char>),
            &vertexEQ, &vertex2str);
}
/*
https://i.ibb.co/t8H3fyL/DAG-9v.png
 */

IGraph<char>* dag_9v(){
    char vertices[] = {'A', 'X', 'G', 'H', 'P', 'E', 'Y', 'M', 'J'};
    Edge<char> edges[] = {
        Edge<char>('A', 'X'),
        Edge<char>('X', 'G'),
        Edge<char>('X', 'H'),
        Edge<char>('G', 'H'),
        Edge<char>('G', 'P'),
        Edge<char>('H', 'P'),
        Edge<char>('H', 'E'),
        Edge<char>('E', 'M'),
        Edge<char>('E', 'Y'),
        Edge<char>('Y', 'M'),
        Edge<char>('M', 'J')
    };
    return DGraphModel<char>::create(
            vertices, sizeof(vertices)/sizeof(char),
            edges, sizeof(edges)/sizeof(Edge<char>),
            &vertexEQ, &vertex2str);
}

IGraph<string> * dsaframework(){
    string vertices[] = {
        "ISort",
        "StraightInsertionSort",
        "ShellSort",
        "StraightSelectionSort",
        "HeapSort",
        "BubbleSort",
        "QuickSort",
        "IList",
        "XArrayList",
        "SLinkedList",
        "DLinkedList",
        "XArrayListSE",
        "SLinkedListSE",
        "DLinkedListSE",
        "IHeap",
        "Heap",
        "IDeck",
        "Stack",
        "Queue",
        "PriorityQueue",
        "Pair",
        "IMap",
        "XHashMap",
        "IBST",
        "ITreeWalker",
        "BST",
        "AVL",
        "Edge",
        "IGraph",
        "AbstractGraph",
        "UGraphModel",
        "DGraphModel",
        "UGraphAlgorithm",
        "DGraphAlgorithm",
        "TopoSorter"
    };
    Edge<string> edges[] = {
        Edge<string>("StraightInsertionSort", "ISort"),
        Edge<string>("ShellSort", "ISort"),
        Edge<string>("StraightSelectionSort", "ISort"),
        Edge<string>("HeapSort", "ISort"),
        Edge<string>("BubbleSort", "ISort"),
        Edge<string>("QuickSort", "ISort"),
        Edge<string>("HeapSort", "IHeap"),
        Edge<string>("HeapSort", "Heap"),
        Edge<string>("XArrayList", "IList"),
        Edge<string>("SLinkedList", "IList"),
        Edge<string>("DLinkedList", "IList"),
        Edge<string>("XArrayListSE", "XArrayList"),
        Edge<string>("SLinkedListSE", "SLinkedList"),
        Edge<string>("DLinkedListSE", "DLinkedList"),
        Edge<string>("XArrayListSE", "ISort"),
        Edge<string>("Heap", "IHeap"),
        Edge<string>("PriorityQueue", "Heap"),
        Edge<string>("Stack", "IDeck"),
        Edge<string>("Queue", "IDeck"),
        Edge<string>("IDeck", "IList"),
        Edge<string>("IDeck", "XArrayList"),
        Edge<string>("IDeck", "SLinkedList"),
        Edge<string>("IDeck", "DLinkedList"),
        Edge<string>("Stack", "IList"),
        Edge<string>("Stack", "XArrayList"),
        Edge<string>("Stack", "SLinkedList"),
        Edge<string>("Stack", "DLinkedList"),
        Edge<string>("Queue", "IList"),
        Edge<string>("Queue", "XArrayList"),
        Edge<string>("Queue", "SLinkedList"),
        Edge<string>("Queue", "DLinkedList"),
        Edge<string>("XHashMap", "IMap"),
        Edge<string>("IMap", "IList"),
        Edge<string>("IMap", "XArrayList"),
        Edge<string>("IMap", "SLinkedList"),
        Edge<string>("IMap", "DLinkedList"),
        Edge<string>("XHashMap", "IList"),
        Edge<string>("XHashMap", "XArrayList"),
        Edge<string>("XHashMap", "SLinkedList"),
        Edge<string>("XHashMap", "DLinkedList"),
        Edge<string>("BST", "IBST"),
        Edge<string>("BST", "ITreeWalker"),
        Edge<string>("AVL", "BST"),
        Edge<string>("IBST", "IDeck"),
        Edge<string>("IBST", "Stack"),
        Edge<string>("IBST", "Queue"),
        Edge<string>("ITreeWalker", "IDeck"),
        Edge<string>("ITreeWalker", "Stack"),
        Edge<string>("ITreeWalker", "Queue"),
        Edge<string>("BST", "IDeck"),
        Edge<string>("BST", "Stack"),
        Edge<string>("BST", "Queue"),
        Edge<string>("AVL", "IDeck"),
        Edge<string>("AVL", "Stack"),
        Edge<string>("AVL", "Queue"),
        Edge<string>("AbstractGraph", "IGraph"),
        Edge<string>("UGraphModel", "AbstractGraph"),
        Edge<string>("DGraphModel", "AbstractGraph"),
        Edge<string>("UGraphAlgorithm", "UGraphModel"),
        Edge<string>("DGraphAlgorithm", "DGraphModel"),
        Edge<string>("TopoSorter", "DGraphModel"),
        Edge<string>("IGraph", "IList"),
        Edge<string>("IGraph", "XArrayList"),
        Edge<string>("IGraph", "SLinkedList"),
        Edge<string>("IGraph", "DLinkedList"),
        Edge<string>("IGraph", "XArrayListSE"),
        Edge<string>("IGraph", "SLinkedListSE"),
        Edge<string>("IGraph", "DLinkedListSE"),
        Edge<string>("AbstractGraph", "IList"),
        Edge<string>("AbstractGraph", "XArrayList"),
        Edge<string>("AbstractGraph", "SLinkedList"),
        Edge<string>("AbstractGraph", "DLinkedList"),
        Edge<string>("AbstractGraph", "XArrayListSE"),
        Edge<string>("AbstractGraph", "SLinkedListSE"),
        Edge<string>("AbstractGraph", "DLinkedListSE"),
        Edge<string>("UGraphModel", "IList"),
        Edge<string>("UGraphModel", "XArrayList"),
        Edge<string>("UGraphModel", "SLinkedList"),
        Edge<string>("UGraphModel", "DLinkedList"),
        Edge<string>("UGraphModel", "XArrayListSE"),
        Edge<string>("UGraphModel", "SLinkedListSE"),
        Edge<string>("UGraphModel", "DLinkedListSE"),
        Edge<string>("DGraphModel", "IList"),
        Edge<string>("DGraphModel", "XArrayList"),
        Edge<string>("DGraphModel", "SLinkedList"),
        Edge<string>("DGraphModel", "DLinkedList"),
        Edge<string>("DGraphModel", "XArrayListSE"),
        Edge<string>("DGraphModel", "SLinkedListSE"),
        Edge<string>("DGraphModel", "DLinkedListSE"),
        Edge<string>("TopoSorter", "IList"),
        Edge<string>("TopoSorter", "XArrayList"),
        Edge<string>("TopoSorter", "SLinkedList"),
        Edge<string>("TopoSorter", "DLinkedList"),
        Edge<string>("TopoSorter", "XArrayListSE"),
        Edge<string>("TopoSorter", "SLinkedListSE"),
        Edge<string>("TopoSorter", "DLinkedListSE"),
        Edge<string>("UGraphAlgorithm", "IList"),
        Edge<string>("UGraphAlgorithm", "XArrayList"),
        Edge<string>("UGraphAlgorithm", "SLinkedList"),
        Edge<string>("UGraphAlgorithm", "DLinkedList"),
        Edge<string>("UGraphAlgorithm", "XArrayListSE"),
        Edge<string>("UGraphAlgorithm", "SLinkedListSE"),
        Edge<string>("UGraphAlgorithm", "DLinkedListSE"),
        Edge<string>("DGraphAlgorithm", "IList"),
        Edge<string>("DGraphAlgorithm", "XArrayList"),
        Edge<string>("DGraphAlgorithm", "SLinkedList"),
        Edge<string>("DGraphAlgorithm", "DLinkedList"),
        Edge<string>("DGraphAlgorithm", "XArrayListSE"),
        Edge<string>("DGraphAlgorithm", "SLinkedListSE"),
        Edge<string>("DGraphAlgorithm", "DLinkedListSE"),
        Edge<string>("TopoSorter", "IDeck"),
        Edge<string>("TopoSorter", "Stack"),
        Edge<string>("TopoSorter", "Queue")
    };
    return DGraphModel<string>::create(
            vertices, (198 - 164 + 1),
            edges, (313 - 201 + 1),
            &vertexEQ, &vertex2str);
}

IGraph<string> * dsamodules(){
    string vertices[] = {
        "SortAlgorithm",
        "List",
        "Heap",
        "StackQueue",
        "Tree",
        "Hash",
        "Graph"
    };
    Edge<string> edges[] = {
        Edge<string>("SortAlgorithm", "Heap"),
        Edge<string>("List", "SortAlgorithm"),
        Edge<string>("StackQueue", "List"),
        Edge<string>("StackQueue", "Heap"),
        Edge<string>("Tree", "List"),
        Edge<string>("Tree", "StackQueue"),
        Edge<string>("Hash", "List"),
        Edge<string>("Graph", "List"),
        Edge<string>("Graph", "StackQueue"),
        Edge<string>("Graph", "Hash"),
       
    };
    return DGraphModel<string>::create(
            vertices, 7,
            edges, 10,
            &vertexEQ, &vertex2str);
}

#endif /* MODELZOO_H */

