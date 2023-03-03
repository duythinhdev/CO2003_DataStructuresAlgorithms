/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TopoSorter.h
 * Author: ltsach
 *
 * Created on July 11, 2021, 10:21 PM
 */

#ifndef TOPOSORTER_H
#define TOPOSORTER_H
#include "graph/DGraphModel.h"
#include "list/DLinkedList.h"
#include "sorting/DLinkedListSE.h"

template<class T>
class TopoSorter{
public:
    static int DFS;
    static int BFS; 
    
protected:
    DGraphModel<T>* graph;
    int (*hash_code)(T&, int);
    
public:
    TopoSorter(DGraphModel<T>* graph, int (*hash_code)(T&, int)=0){
        this->graph = graph;
        this->hash_code = hash_code;
    }   
    DLinkedList<T> sort(int mode=0, bool sorted=true){
        if(mode == DFS) return dfsSort(sorted);
        else return bfsSort(sorted);
    }
    DLinkedList<T> bfsSort(bool sorted=true){ 
        DLinkedList<T> topoOrder; //explored already
        XHashMap<T, int> indegreeMap = vertex2inDegree(this->hash_code);
        DLinkedListSE<T> list = listOfZeroInDegrees();
        if(sorted) list.sort(); //only for education
        
        Queue<T> open; //to be explored
        for(typename DLinkedListSE<T>::Iterator it= list.begin(); it != list.end(); it++)
            open.push(*it);
        while(!open.empty()){
            T vertex = open.pop();
            topoOrder.add(vertex);
            
            DLinkedListSE<T> children = this->graph->getOutwardEdges(vertex);
            if(sorted) children.sort(); //only for education
            for(typename DLinkedListSE<T>::Iterator it=children.begin(); it != children.end(); it++){
                T child = *it;
                if(open.contains(child)) continue; //to be explored
                if(topoOrder.contains(child)) continue; //already explored
                
                //dec indegree of child
                int new_indeg = indegreeMap.get(child) - 1;
                indegreeMap.put(child, new_indeg);
                if(new_indeg == 0) open.push(child);
            }
        }
        return topoOrder;
    }

    DLinkedList<T> dfsSort(bool sorted=true){
        DLinkedList<T> topoOrder; //explored already
        XHashMap<T, int> outdegreeMap = vertex2outDegree(this->hash_code);
        DLinkedListSE<T> list = listOfZeroInDegrees();
        if(sorted) list.sort(); //only for education
        
        Stack<T> open;
        for(typename DLinkedListSE<T>::Iterator it=list.begin(); it != list.end(); it++)
            open.push(*it);
        
        while(!open.empty()){
            T vertex = open.peek();
            int outDegree = outdegreeMap.get(vertex); 
            if(outDegree == 0){
                //is leaf
                open.pop();
                topoOrder.add(0, vertex); //mark as explored
            }
            else{
                DLinkedListSE<T> children = this->graph->getOutwardEdges(vertex);
                if(sorted) children.sort(); //only for education
                for(typename DLinkedListSE<T>::Iterator it=children.begin(); it != children.end(); it++){
                    T child = *it;
                    if(open.contains(child)){
                        //PREFER to be deeper => move child to top
                        open.remove(child);
                        open.push(child);
                    }
                    
                    if(!open.contains(child) && !topoOrder.contains(child) )
                        open.push(child); //not exlored + not to be explored => push
                    
                    //dec outdegree of vertex => WHEN hit to 0 :=> to topoOrder
                    outdegreeMap.put(vertex, outDegree - 1);    
                }
            }
        }//while: stack not empty
        return topoOrder;
    }

protected:
    XHashMap<T, int> vertex2inDegree(int (*hash)(T&, int)){
        /*
        int (*hash)(T&, int);
        if(this->hash_code != 0 ) hash = this->hash_code;
        else hash = &XHashMap<T, int>::simpleHash;
        */
        
        XHashMap<T, int> map(hash);
        typename DGraphModel<T>::Iterator vertexIt = this->graph->begin();
        while(vertexIt != this->graph->end()){
            T vertex = *vertexIt;
            int inDegree = this->graph->inDegree(vertex);
            map.put(vertex, inDegree);
            
            vertexIt++;
        }
        return map;
    }
    XHashMap<T, int> vertex2outDegree(int (*hash)(T&, int)){
        /*
        int (*hash)(T&, int);
        if(this->hash_code != 0 ) hash = this->hash_code;
        else hash = &XHashMap<T, int>::simpleHash;
        */
        
        XHashMap<T, int> map(hash);
        typename DGraphModel<T>::Iterator vertexIt = this->graph->begin();
        while(vertexIt != this->graph->end()){
            T vertex = *vertexIt;
            int outDegree = this->graph->outDegree(vertex);
            map.put(vertex, outDegree);
            
            vertexIt++;
        }
        return map;
    }
    
    DLinkedList<T> listOfZeroInDegrees(){
        DLinkedList<T> list;
        typename DGraphModel<T>::Iterator vertexIt = this->graph->begin();
        while(vertexIt != this->graph->end()){
            T vertex = *vertexIt;
            int inDegree = this->graph->inDegree(vertex);
            if(inDegree == 0) list.add(vertex);
            
            vertexIt++;
        }
        return list;
    }
}; //TopoSorter
template<class T>
int TopoSorter<T>::DFS = 0;
template<class T>
int TopoSorter<T>::BFS = 1;

/////////////////////////////End of TopoSorter//////////////////////////////////


#endif /* TOPOSORTER_H */

