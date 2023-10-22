#include "Director.h"
Director::Director() {}
void Director::add(std::unique_ptr<Builder> builder) {
    builders.push_back(std::move(builder));
}
void Director::Construct() {
    for (auto& builder : builders) {
        builder->build();
    }
}
