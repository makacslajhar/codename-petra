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
#include <osmium/handler/node_locations_for_ways.hpp>

//Na ebből kéne kiindulni :D
//ez még nem biztos hogy kell
/*
typedef struct
{
    osmium::Node csp;
    osmium::Node * forras;
}RNODE;
*/

osmium::memory::Buffer szurke;
osmium::memory::Buffer feher;


/*Laci ezekbe kérem majd az utakat(<way></way>) illetve node-okat(<node></node>) beolvasni - Erik*/

osmium::memory::Buffer utak;
osmium::memory::Buffer nodeok;


osmium::memory::Buffer route(osmium::Node * Starting,osmium::Node * Ending){
    nodeok.reserve_space(sizeof(osmium::Node));
    nodeok.add_item(*Starting);
    nodeok.commit();
    osmium::Node * cur;
    while (true){

        //for()
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
