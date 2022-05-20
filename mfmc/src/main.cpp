#include <iostream>
#include <list>

#include "graph/graph.h"

int format(char* filepath);

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cout << "Usage: " << argv[0] << " [filename] [options?]"
                  << std::endl;
        return 1;
    }

    Graph g = read_graph_file(argv[1]);

    if (argc > 2) {
        std::string cur_arg(argv[2]);
        if (cur_arg == "-p" || cur_arg == "--print") {
            print_graph(g);
        } else if (cur_arg == "-s" || cur_arg == "--shortest-path") {
            if (argc == 5) {
                auto path = g.path_to(std::stoi(std::string(argv[3])),
                                      std::stoi(std::string(argv[4])));
                for (auto const& i : path) std::cout << i << " ";
            } else {
                std::cout << "Usage: " << argv[0]
                          << " [filename] -s [from_node] [to_node]";
            }
        }
    }

    std::cout << std::endl;

    return 0;
}
