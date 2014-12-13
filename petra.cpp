#include <vector>
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
//ez még nem biztos hogy kell
/*
typedef struct
{
    osmium::Node csp;
    osmium::Node * forras;
}RNODE;

std::vector<osmium::Node> szurke;
std::vector<osmium::Node> feher;
*/

/*Laci ezekbe kérem majd az utakat(<way></way>) illetve node-okat(<node></node>) beolvasni - Erik*/

std::vector<osmium::Way> utak;
std::vector<osmium::Node> nodeok;


std::vector<osmium::Way> route(osmium::Node Starting,osmium::Node Ending){
    feher.push_back(Starting);
    osmium::Node * cur;
    while (true){

        for(osmium::Node n:feher)
        {

        }
    }

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
