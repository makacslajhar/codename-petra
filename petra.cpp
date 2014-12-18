#include <boost/config.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/iteration_macros.hpp>
#include <boost/graph/properties.hpp>

#include <osmium/memory/buffer.hpp>
#include <iostream>
#include <osmium/osm.hpp>
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
#include <cmath>
//dijkstra-hoz szükséges adattipusok
typedef boost::adjacency_list<boost::vecS, boost::setS, boost::directedS,
boost::property <boost::vertex_name_t, osmium::unsigned_object_id_type >> NodeRefGraph;
typedef NodeRefGraph::vertex_descriptor NRGVertex;
typedef osmium::index::map::StlMap<osmium::unsigned_object_id_type, NRGVertex* > NRGVertices;
typedef std::pair<const osmium::NodeRef,const osmium::NodeRef> Edge;

/*Laci ezekbe kérem majd az utakat(<way></way>) illetve node-okat(<node></node>) és a node-ok számát beolvasni - Erik*/

osmium::memory::Buffer utak;
osmium::memory::Buffer nodeok;
osmium::memory::Buffer utvonal;
int node_num;



std::vector<Edge> parok()
{
    std::vector<Edge> par_lista;
    for(unsigned int i=0;i<utak.capacity();i++)
    {
        osmium::WayNodeList * utnodeok;
        utnodeok=&utak.get<osmium::Way>(i).nodes();
        for(unsigned int j=0;j<(*utnodeok).size()-1;j++)
        {
            Edge par(((*utnodeok)[j]),((*utnodeok)[j+1]));
            /*par.first=((*utnodeok)[j]).ref();
            par.second=((*utnodeok)[j+1]).ref();*/
            par_lista.push_back(par);
        }
    }
    return par_lista;
}

int tav(osmium::NodeRef a,osmium::NodeRef b)
{
    return sqrt(std::pow(a.x()-b.x(),2)+std::pow(a.y()-b.y(),2));

}

double tav(double lat1,double lon1,double lat2,double lon2)
{
    return sqrt(std::pow(lon1-lon2,2)+std::pow(lat1-lat2,2));

}

std::vector<int> sulyok(int s,Edge * v)
{
    std::vector<int> res;
    for(int i=0;i<s;i++)
        res.push_back(tav(v[i].first,v[i].second));
    return res;
}

void route(osmium::NodeRef start,osmium::NodeRef veg){

using namespace boost;

std::vector<Edge> tmp=parok();
int edge_number=tmp.size();
Edge * Edge_array = &tmp[0];
int * weights = &sulyok(edge_number,Edge_array)[0];

NodeRefGraph g(Edge_array,Edge_array+edge_number,weights,node_num);
//property_map<NodeRefGraph,vertex_name_t>::type weightmap = get(vertex_name_t,g);

//boost::dijkstra_shortest_paths(g)

}

osmium::NodeRef nearest_node(double lat,double lon)
{
    osmium::NodeRef near_node=(nodeok.get<osmium::Node>(0)).id();
    double tavolsag=tav(lat,lon,near_node.lat(),near_node.lon());
    for(int i=1;i<nodeok.capacity();i++)
    {
        osmium::NodeRef vizsgalt_node=(nodeok.get<osmium::Node>(i)).id();
        if (tav(lat,lon,vizsgalt_node.lat(),vizsgalt_node.lon()<tavolsag))
        {
            tavolsag=tav(lat,lon,vizsgalt_node.lat(),vizsgalt_node.lon());
            near_node=vizsgalt_node;
        }
    }
    return near_node;

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
    osmium::NodeRef start=nearest_node(atof(argv[1]),atof(argv[2]));
    osmium::NodeRef vege=nearest_node(atof(argv[3]),atof(argv[4]));
    route(start,vege);

    return 0;
}
