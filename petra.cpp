#include <iostream>
//#include <cstddef>
#include <osmium/io/xml_input.hpp>
#include <osmium/handler.hpp>
#include <osmium/visitor.hpp>
#include <osmium/osm/node.hpp>
#include <osmium/osm/way.hpp>
#include <osmium/osm/relation.hpp>
#include <osmium/index/map/sparse_table.hpp>
#include <osmium/handler/node_locations_for_ways.hpp>

//Na ebből kéne kiindulni :D
array<osmium::Node> szurke;
array<osmium::Node> feher;
array<osmium::Way> utak;

void init_dijk()
{
    szurke.add(new osmium::Location::Location())

}

array<osmium::Node> dijkstra(osmium::Node Starting,osmium::Node Ending){
    feher.add(Starting)
    while (true){
        for(n:szurke)
        {

        }
    }

}


int main()
{
    std::cout<<"Hello World\n";
    return 0;
}
