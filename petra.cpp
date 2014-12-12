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

/*Laci ezekbe kérem majd az utakat(<way></way>) illetve node-okat(<node></node>) beolvasni - Erik*/
array<osmium::Way> utak;
array<osmium::Node> nodeok;


array<osmium::Node> connections(osmium::Node v_node)
{
    array<osmium::Node> res;
    for(ut:utak)
    {
        bool benne_van=false;
        for(n:ut.nodes())
        {
            if (n==v_node) benne_van=true;
        }
        if (benne_van)
            for(n:ut.nodes())
            {
                res.add(n);
            }
    }
    return res;
}



array<osmium::Way> dijkstra(osmium::Node Starting,osmium::Node Ending){
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
