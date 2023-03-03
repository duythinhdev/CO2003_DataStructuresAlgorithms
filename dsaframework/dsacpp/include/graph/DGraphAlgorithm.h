/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DGraphAlgorithm.h
 * Author: ltsach
 *
 * Created on July 11, 2021, 10:23 PM
 */

#ifndef DGRAPHALGORITHM_H
#define DGRAPHALGORITHM_H
#include "graph/DGraphModel.h"

//////////////////////////////////////////////////////////////////////
//////////////////// Algorithms with DGraphModel  ////////////////////
//////////////////////////////////////////////////////////////////////


template<class T>
class DGraphAlgorithm{
public:
    class Node;
    DGraphAlgorithm(){}
    static bool vertexEQ(T& lhs, T& rhs){
        return lhs==rhs;
    }
    static bool nodeEQ(Node*& lhs, Node*& rhs){
        return vertexEQ(lhs->vertex, rhs->vertex);
    }
    static string item2str(T& item){
        stringstream os;
        os << item;
        return os.str();
    }
    DLinkedList<Path<T>*> dijkstra(DGraphModel<T>* pGraph, T start){
        DLinkedList<Node*> explored(0, DGraphAlgorithm<T>::nodeEQ);
        PriorityQueue<Node*> frontier(&Node::compare);
        frontier.push(new Node(0, start, 0, &DGraphAlgorithm<T>::vertexEQ));
        while(!frontier.empty()){
            Node *node = frontier.pop();
            explored.add(node);
            DLinkedList<T> children = pGraph->getOutwardEdges(node->vertex);
            
            typename DLinkedList<T>::Iterator childrenIt = children.begin();
            while(childrenIt != children.end()){
                T child = *childrenIt;
                
                float stepCost = pGraph->weight(node->vertex, child);
                Node* childNode = new Node(node, child, node->pathCost + stepCost, &DGraphAlgorithm<T>::vertexEQ);
                if(!explored.contains(childNode)){
                    bool inFrontier = false;
                    
                    //
                    typename Heap<Node*>::Iterator frontierIt = frontier.begin();
                    while(frontierIt != frontier.end()){
                        Node* frontierNode = *frontierIt;
                        float oldPathCost = frontierNode->pathCost;
                        float newPathCost = childNode->pathCost;
                        if(vertexEQ(frontierNode->vertex, child) ){
                            inFrontier = true;
                            if(newPathCost < oldPathCost){
                                frontierIt.remove();
                                frontier.push(childNode);
                                break;
                            }
                        }
                        
                        frontierIt++;
                    }
                    if(!inFrontier) frontier.push(childNode);
                }//if
                
                childrenIt++;
            }//while: process each child
        }
        return constructPath(explored);
    }
    
    DLinkedList<Path<T>*> constructPath(DLinkedList<Node*> explored){
        
        DLinkedList<Path<T>*> list;
        typename DLinkedList<Node*>::Iterator it = explored.begin();
        while(it != explored.end()){
            Node* node = *it;
            
            Path<T>* path = new Path<T>();
            Stack<Node*> stack; //more params
            
            path->setCost(node->pathCost);
            while(node != 0){
                stack.push(node);
                node = node->parent;
            }
            while(!stack.empty()){
                Node* item = stack.pop();
                T vertex = item->vertex;
                path->add(vertex);
            }
            list.add(path);
            
            it++;
        }
        return list;
    }
    
    //////////////////////////////////////////////////////////////////////
    ////////////////////////  INNER CLASSES DEFNITION ////////////////////
    //////////////////////////////////////////////////////////////////////
public:
    class Node{
    private:
        Node* parent;
        T vertex;
        float pathCost;
        bool (*vertexEQ_PTR)(T&,T&);
        
        friend class DGraphAlgorithm;
        
    public:
        Node(   Node* parent, T vertex, float pathCost, 
                bool (*vertexEQ_PTR)(T&,T&)){
            this->parent = parent;
            this->vertex = vertex;
            this->pathCost = pathCost;
            this->vertexEQ_PTR = vertexEQ_PTR;
        }
        bool equals(Node& node){
            return this->vertexEQ_PTR(this->vertex, node.vertex);
        }
        string toString(){
            stringstream os;
            os << this->vertex;
            return os.str();
        }
        static int compare(Node*& lhs, Node*& rhs){
            float diff = lhs->pathCost - rhs->pathCost;
            if(diff < 0) return -1;
            else if(diff > 0) return +1;
            else return 0;
        }
        
    };
};


#endif /* DGRAPHALGORITHM_H */

