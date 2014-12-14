#include <boost/config.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/depth_first_search.hpp>

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
#include <osmium/memory/item.hpp>
#include <osmium/memory/item_iterator.hpp>
#include <vector>
//dijkstra-hoz szükséges adattipusok
typedef boost::adjacency_list<boost::vecS, boost::setS, boost::directedS,
boost::property <boost::vertex_name_t, osmium::unsigned_object_id_type >> NodeRefGraph;
typedef NodeRefGraph::vertex_descriptor NRGVertex;
typedef osmium::index::map::StlMap<osmium::unsigned_object_id_type, NRGVertex* > NRGVertices;
typedef std::pair<osmium::unsigned_object_id_type, osmium::unsigned_object_id_type> Edge;





/*Laci ezekbe kérem majd az utakat(<way></way>) illetve node-okat(<node></node>) és a node-ok számát beolvasni - Erik*/

osmium::memory::Buffer utak;
osmium::memory::Buffer nodeok;
osmium::memory::Buffer utvonal;
int node_num;



std::vector<Edge> parok()
{
    std::vector<Edge> par_lista;
    for(int i=0;i<utak.capacity();i++)
    {
        osmium::WayNodeList * utnodeok;
        utnodeok=&utak.get<osmium::Way>(i).nodes();
        for(int j=0;j<(*utnodeok).size()-1;j++)
        {
            Edge par;
            par.first=((*utnodeok)[j]).ref();
            par.second=((*utnodeok)[j+1]).ref();
            par_lista.push_back(par);
        }
    }
    return par_lista;
}

std::vector<int> sulyok(int s)
{
    std::vector<int> res;
    for(int i=0;i<s;i++)
        res.push_back(1);
    return res;
}

void route(){

using namespace boost;

std::vector<Edge> tmp=parok();
int edge_number=tmp.size();
Edge * Edge_array = &tmp[0];
int * weights = &sulyok(edge_number)[0];

graph g(Edge_array,Edge_array+edge_number,weights,node_num);
property_map<graph,edge_weight_t>::type weightmap=get(edge_weight,g);

//boost::dijkstra_shortest_paths(g)

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
