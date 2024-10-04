#include "Bike.h"

int main() {
    int n = 0;
    cin >> n;
    string bike_type;
    auto mountain_bike_builder = make_shared<MountainBikeBuilder>();
    auto road_bike_builder = make_shared<RoadBikeBuilder>();
    Director director;
    for (int i=0; i<n; ++i) {
        cin >> bike_type;
        if (bike_type == "mountain") {
            director.setBuilder(mountain_bike_builder);
            director.build();
            cout << mountain_bike_builder->getBike() << endl;
        } else if (bike_type == "road") {
            director.setBuilder(road_bike_builder);
            director.build();
            cout << road_bike_builder->getBike() << endl;
        }
    }
}