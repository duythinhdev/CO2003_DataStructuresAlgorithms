/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UGraphAlgorithmTest.h
 * Author: ltsach
 *
 * Created on July 11, 2021, 10:33 PM
 */

#ifndef UGRAPHALGORITHMTEST_H
#define UGRAPHALGORITHMTEST_H

#include "doctest.h"
#include "graph/UGraphModel.h"
#include "graph/UGraphAlgorithm.h"


//////////////////////////////////////////////////////////////////////
/////////////  UGraphModel: Algorithm Test        ////////////////////
//////////////////////////////////////////////////////////////////////

TEST_CASE( "Minimum Spanning Tree with UGraphModel" ) {
    UGraphModel<char> model(&charEQ, &char2str);
    REQUIRE(model.size() == 0);
    REQUIRE(model.empty() == true);
    
    int nv = 6;
    int ne = 9;
    char vertex[]       = {'A', 'B', 'C', 'D', 'E', 'F'};
    
    char from[]         = {'A',  'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E'};
    char to[]           = {'B',  'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F'};
    float weight[]      = { 6,    3,   2,   5,   3,   4,   2,   3,   5};
    int indegree[]      = { 1,    1,   3,   3,   1,   1}; //Tree expected
    int outdegree[]     = { 1,    1,   3,   3,   1,   1}; //Tree expected
    
    for(int v=0; v < nv; v++) model.add(vertex[v]);
    for(int e=0; e < ne; e++) model.connect(from[e], to[e], weight[e]);

    REQUIRE(model.size() == nv);
    REQUIRE(model.empty() == false);
    
    UGraphAlgorithm<char> mst;
    UGraphModel<char> tree = mst.minSpanningTree(&model);
    
    for(int v=0; v < nv; v++){
        REQUIRE(tree.inDegree(vertex[v]) == indegree[v]);
        REQUIRE(tree.outDegree(vertex[v]) == outdegree[v]);
    }
}
#endif /* UGRAPHALGORITHMTEST_H */

