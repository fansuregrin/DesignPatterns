#include "Bike.h"

int main() {
    int n = 0;
    cin >> n;
    string bike_type;
    Director mountain_bike_director(unique_ptr<BikeBuilder>(new MountainBikeBuilder()));
    Director road_bike_director(unique_ptr<BikeBuilder>(new RoadBikeBuilder()));
    for (int i=0; i<n; ++i) {
        cin >> bike_type;
        if (bike_type == "mountain") {
            cout << mountain_bike_director.build() << endl;
        } else if (bike_type == "road") {
            cout << road_bike_director.build() << endl;
        }
    }
}