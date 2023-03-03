/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UGraphAlgorithm.h
 * Author: ltsach
 *
 * Created on July 11, 2021, 10:18 PM
 */

#ifndef UGRAPHALGORITHM_H
#define UGRAPHALGORITHM_H
#include "graph/UGraphModel.h"
#include "stacknqueue/PriorityQueue.h"
//////////////////////////////////////////////////////////////////////
//////////////////// Algorithms with UGraphModel  ////////////////////
//////////////////////////////////////////////////////////////////////

template<class T>
class UGraphAlgorithm{
private:
public:
    UGraphAlgorithm(){
    }
    
    UGraphModel<T> minSpanningTree(UGraphModel<T>* pGraph){
        //(1) Obtain the list of vertices being processed
        DLinkedList<T> vertexList;
        typename AbstractGraph<T>::Iterator vertexIt = pGraph->begin();
        while(vertexIt != pGraph->end()){
            T vertex = *vertexIt;
            vertexList.add(vertex);
            
            vertexIt++;
        }
        
        //(2) Process each vertex in vertexList
        UGraphModel<T> mst(pGraph->getVertexEQ(), pGraph->getVertex2Str());
        while(!vertexList.empty()){
            T vertex = vertexList.removeAt(0);

            mst.add(vertex);
            bool hasChildren = true;
            do{
                PriorityQueue<Edge*> crossEdges(&Edge::edgeComparator);
                typename AbstractGraph<T>::Iterator mstIt = mst.begin();
                while(mstIt != mst.end()){
                    T parent = *mstIt;
                    
                    DLinkedList<T> children = pGraph->getOutwardEdges(parent);
                    typename DLinkedList<T>::Iterator childrenIt = children.begin();
                    while(childrenIt != children.end() ){
                        T child = *childrenIt;
                        
                        if(!mst.contains(child)){
                            float weight = pGraph->weight(parent, child);
                            Edge* edge = new Edge(parent, child, weight);
                            crossEdges.push(edge);
                        }
                        //next
                        childrenIt++;
                    }//while:childrenIt
                    
                    //next
                    mstIt++;
                }//while: mstIt
                
                hasChildren = crossEdges.size() > 0;
                if(hasChildren){
                    Edge* smallest = crossEdges.pop();
                    mst.add(smallest->to);
                    mst.connect(smallest->from, smallest->to, smallest->weight);
                    vertexList.removeItem(smallest->to);
                }
            } while(hasChildren);
        }

        return mst;
    }
    
    
    //////////////////////////////////////////////////////////////////////
    ////////////////////////  INNER CLASSES DEFNITION ////////////////////
    //////////////////////////////////////////////////////////////////////
    
    class Edge{
    private:
        T from;
        T to;
        float weight;
        
        //friend class UGraphModel;
        friend class UGraphAlgorithm;
        
    public:
        Edge(T from, T to, float weight){
            this->from = from;
            this->to = to;
            this->weight = weight;
        }
        
        static int edgeComparator(Edge*& edge1, Edge*& edge2){
            float diff = edge1->weight - edge2->weight;
            if(diff < 0) return -1;
            else if(diff > 0) return +1;
            else return 0;
        }
    };
    
};

#endif /* UGRAPHALGORITHM_H */

