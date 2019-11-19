// Copyright (c) 2019 The Felicia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "rplidar/rplidar_factory.h"

#include "chromium/base/memory/ptr_util.h"

namespace felicia {
namespace drivers {

// static
std::unique_ptr<RPlidar> RPlidarFactory::NewLidar(
    const LidarEndpoint& lidar_endpoint) {
  return base::WrapUnique(new RPlidar(lidar_endpoint));
}

}  // namespace drivers
}  // namespace felicia