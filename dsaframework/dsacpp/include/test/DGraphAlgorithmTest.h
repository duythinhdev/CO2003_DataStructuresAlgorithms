/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DGraphAlgorithmTest.h
 * Author: ltsach
 *
 * Created on July 11, 2021, 10:35 PM
 */

#ifndef DGRAPHALGORITHMTEST_H
#define DGRAPHALGORITHMTEST_H
#include "doctest.h"
#include "graph/DGraphModel.h"
#include "graph/DGraphAlgorithm.h"
#include "graph/TopoSorter.h"


//////////////////////////////////////////////////////////////////////
/////////////  DGraphModel: Algorithm Test        ////////////////////
//////////////////////////////////////////////////////////////////////

TEST_CASE( "Dijkstra with DGraphModel" ) {
    int nv = 5, ne = 10;
    char vertex[]   = {'0', '1', '2', '3', '4'};
    char from[]     = {'0', '0', '0', '1', '1', '2', '2', '4', '4', '4'};
    char to[]       = {'1', '2', '4', '2', '3', '1', '3', '1', '2', '3'};
    float weight[]  = { 5,   3,   2,   2,   6,   1,   2,   6,   10,  4};
    char path_exp[][5] = {
        {'0'},  //1st path
        {'0', '4'}, //2nd path
        {'0', '2'},
        {'0', '2', '1'},
        {'0', '2', '3'}
    };
    int path_length[]= {1,  2,  2,  3,  3};
    float path_cost[]= {0,  2,  3,  4,  5};
    
    
    DGraphModel<char> model(&charComparator, &vertex2str);
    REQUIRE(model.size() == 0);
    REQUIRE(model.empty() == true);
    for(int v=0; v < nv; v++) model.add(vertex[v]);
    for(int e=0; e < ne; e++) model.connect(from[e], to[e], weight[e]);
    REQUIRE(model.size() == nv);
    
    DGraphAlgorithm<char> finder;
    DLinkedList<Path<char>*> list = finder.dijkstra(&model, '0');
    int pathIdx = 0;
    for(DLinkedList<Path<char>*>::Iterator it= list.begin(); it != list.end(); it++){
        Path<char>* path = *it;
        DLinkedList<char>& vertexList = path->getPath(); 
        REQUIRE(path->getCost() == path_cost[pathIdx]);
        REQUIRE(vertexList.size() == path_length[pathIdx]);
        DLinkedList<char>::Iterator vit;
        int vidx = 0;
        for(vit = vertexList.begin(); vit != vertexList.end(); vit++){
            char vn = *vit;
            REQUIRE(vn == path_exp[pathIdx][vidx++]);
        }
        pathIdx++;
    }

}

#endif /* DGRAPHALGORITHMTEST_H */

