#include "Director.h"
Director::Director() {}
void Director::add(Builder* builder) { builders.push_back(builder); }
void Director::Construct() {
    for (auto& builder : builders) {
        builder->build();
    }
}
