#include <Eigen/Core>


std::tuple<Eigen::MatrixX3f, Eigen::MatrixX3i> BBoxToCube(const Eigen::Vector3f& pMin, const Eigen::Vector3f& pMax)
{
    Eigen::MatrixX3i faces;
    faces.resize(12,3);
    faces << 1,7,5,
    1,3,7,
    1,4,3,
    1,2,4,
    3,8,7,
    3,4,8,
    5,7,8,
    5,8,6,
    1,5,6,
    1,6,2,
    2,6,8,
    2,8,4;

    Eigen::MatrixX3f verts;
    verts.resize(8, 3);

    for (size_t idx = 0; idx < 8; idx++)
    {
        Eigen::Vector3f v(pMin);
        bool x_max = (idx >> 2) % 2;
        bool y_max = (idx >> 1) % 2;
        bool z_max = idx  % 2;
        
        if (x_max)
            v[0] = pMax[0];
        if (y_max)
            v[1] = pMax[1];
        if (z_max)
            v[2] = pMax[2];

        verts.row(idx) = v;
    }

    return std::make_tuple(verts, faces);
}