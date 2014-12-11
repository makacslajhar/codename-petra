sudo apt-get install freetype-*
git clone https://github.com/mapnik/mapnik mapnik-2.3.x -b 2.3.x
cd mapnik-2.3.x
./configure && make && sudo make install
