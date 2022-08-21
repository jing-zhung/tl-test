#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <list>

// Define vertex
class Vertex
{
    public:
        std::string data_;
        Vertex(std::string data)
        {
            this->data_ = data;
        };
};

// Define graph
class Graph
{
    private:
        // Adjacency lists
        std::vector<std::list<Vertex*>*> adj_lists;

    public:
        ~Graph()
        {
            deleteGraph();
        }

        /**
         * @brief Add vertex to graph
         * @param vertex Vertex to be added
         */
        void addVertex(Vertex* vertex)
        {
            std::list<Vertex*> *current_list = new std::list<Vertex*>;
            current_list->push_back(vertex);
            adj_lists.push_back(current_list);
        };

        /**
         * @brief Add edge to graph
         * @param source Index of source vertex
         * @param destination Index of destination vertex
         */
        void addEdge(int source, int destination)
        {
            std::list<Vertex*> *current_list = adj_lists[source];
            Vertex* destination_vertex = adj_lists[destination]->front();
            current_list->push_back(destination_vertex);
        };

        /**
         * @brief Check if an edge exists in graph
         * @param source Index of source vertex
         * @param destination Index of destination vertex
         * @return boolean if edge exists or not
         */
        bool checkEdge(int source, int destination)
        {
            std::list<Vertex*> *current_list = adj_lists[source];
            Vertex* destination_vertex = adj_lists[destination]->front();
            for(auto vertex : *current_list)
            {
                if(vertex == destination_vertex && vertex != current_list->front())
                {
                    return true;
                }
            }
            return false;
        };

        /**
         * @brief Print graph in terminal in the format of a list of adjacency lists
         */
        void printGraph()
        {
            for(auto list : adj_lists)
            {
                for(auto vertex : *list)
                {
                    std::cout << vertex->data_ << " -> ";
                }
                std::cout << std::endl;
            }
        };

        /**
         * @brief Delete adjacency lists
         */
        void deleteGraph()
        {
            for(auto list : adj_lists)
            {
                delete list;
                adj_lists.clear();
            }
        }
};

#endif