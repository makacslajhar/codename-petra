#include <boost/config.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>


#include <osmium/memory/buffer.hpp>
#include <iostream>
//#include <cstddef>
#include <osmium/io/xml_input.hpp>
#include <osmium/handler.hpp>
#include <osmium/visitor.hpp>
#include <osmium/osm/node.hpp>
#include <osmium/osm/way.hpp>
#include <osmium/osm/relation.hpp>
#include <osmium/index/map/sparse_table.hpp>
#include <osmium/index/map/stl_map.hpp>
#include <osmium/handler/node_locations_for_ways.hpp>

typedef boost::adjacency_list<boost::vecS, boost::setS, boost::directedS,
boost::property <boost::vertex_name_t, osmium::unsigned_object_id_type >> NodeRefGraph;
typedef NodeRefGraph::vertex_descriptor NRGVertex;
typedef osmium::index::map::StlMap<osmium::unsigned_object_id_type, NRGVertex* > NRGVertices;


/*
osmium::memory::Buffer szurke;
osmium::memory::Buffer feher;
*/

/*Laci ezekbe kérem majd az utakat(<way></way>) illetve node-okat(<node></node>) beolvasni - Erik*/

//osmium::memory::Buffer utak;
osmium::memory::Buffer nodeok;


osmium::memory::Buffer route(osmium::Node * Starting,osmium::Node * Ending)
{


}


void usage()
{
    std::cout<<"usage: ./petra lat1 lon1 lat2 lon2"<<std::endl;
}

int main(int argc,const char * argv[])
{
    if (argc==5)
    {
        std::cout<<argv[1]<<' '<<argv[2]<<' '<<argv[3]<<' '<<argv[4]<<std::endl;
    }
    else
    {
        std::cout<<"nem megfelelo szamu koordinata!"<<std::endl;
        usage();
    }
    return 0;
}
