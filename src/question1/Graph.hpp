#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <list>

class Vertex
{
    public:
        std::string data_;
        Vertex(std::string data)
        {
            this->data_ = data;
        };
};

class Graph
{
    private:
        std::vector<std::list<Vertex*>*> adj_list;
    public:
        ~Graph()
        {
            deleteGraph();
        }
        void addVertex(Vertex* vertex)
        {
            std::list<Vertex*> *current_list = new std::list<Vertex*>;
            current_list->push_back(vertex);
            adj_list.push_back(current_list);
        };
        void addEdge(int source, int destination)
        {
            std::list<Vertex*> *current_list = adj_list[source];
            Vertex* destination_vertex = adj_list[destination]->front();
            current_list->push_back(destination_vertex);
        };
        bool checkEdge(int source, int destination)
        {
            std::list<Vertex*> *current_list = adj_list[source];
            Vertex* destination_vertex = adj_list[destination]->front();
            for(auto vertex : *current_list)
            {
                if(vertex == destination_vertex && vertex != current_list->front())
                {
                    return true;
                }
            }
            return false;
        };
        void printGraph()
        {
            for(auto list : adj_list)
            {
                for(auto vertex : *list)
                {
                    std::cout << vertex->data_ << " -> ";
                }
                std::cout << std::endl;
            }
        };
        void deleteGraph()
        {
            for(auto list : adj_list)
            {
                delete list;
                adj_list.clear();
            }
        }
};

#endif