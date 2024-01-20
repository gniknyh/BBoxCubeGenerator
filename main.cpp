#include <iostream>
#include <string>
#include <format>
#include <fstream>

#include <BBoxCubeGenerator.h>

int main(int, char**){
    std::string filename{"cube.obj"};
    std::fstream f_stream;
    f_stream.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);

    Eigen::Vector3f pMin(0.5,0,0);
    Eigen::Vector3f pMax(2,2,2);

    auto [verts, faces] = BBoxToCube(pMin, pMax);
    
    std::string output = "g cube \n";
    for (size_t row_idx = 0; row_idx < verts.rows(); row_idx++)
    {
        output += std::format("v {} {} {} \n", verts(row_idx, 0), verts(row_idx, 1), verts(row_idx, 2));
    }

    for (size_t row_idx = 0; row_idx < faces.rows(); row_idx++)
    {
        output += std::format("f {}// {}// {}// \n", faces(row_idx, 0), faces(row_idx, 1),faces(row_idx, 2));
    }
    f_stream << output;

}
