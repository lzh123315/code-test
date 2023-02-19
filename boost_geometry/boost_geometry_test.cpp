#include <vector>
#include <fstream>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

typedef boost::geometry::model::d2::point_xy<double> point_2d;

int main(){
    // Declare a stream and an SVG mapper
    std::ofstream svg("boost_geometry_test.svg");
    boost::geometry::svg_mapper<point_2d> mapper(svg, 1000, 1000);

    boost::geometry::model::polygon<point_2d> bound;
    std::vector<point_2d> points{{0, 0}, {0, 100}, {100, 100}, {100, 0}, {0, 0}};
    boost::geometry::assign_points(bound, points);
    boost::geometry::correct(bound);

    mapper.add(bound);
    mapper.map(bound, "fill-opacity:1.0;fill:rgb(128,128,128);stroke:rgb(0,0,0);stroke-width:6"); // White

        // Write title at the lower right corner on canvas
    mapper.text(point_2d(6, 6), "test_planner_2d",
                "fill-opacity:1.0;fill:rgb(10,10,250);");
}