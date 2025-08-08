#pragma once

#include "export.h"

#include <vector>
#include <algorithm>

namespace RRE::instanceManagers {

template <typename T>
class RRE_API InstanceHandler {
  private:
    std::vector<T *> instances;

  public:
    void add(T *instance) {
        instances.push_back(instance);
    }

    void remove(T *instance) {
        auto it = std::remove(instances.begin(), instances.end(), instance);
        instances.erase(it, instances.end());
    }

    void run() {
        for (auto instance : instances)
            instance->run();
    }

    const std::vector<T *> &getAll() const {
        return instances;
    }
};

} // namespace RevRLCore
