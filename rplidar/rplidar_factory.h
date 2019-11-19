// Copyright (c) 2019 The Felicia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef RPLIDAR_RPLIDAR_FACTORY_H_
#define RPLIDAR_RPLIDAR_FACTORY_H_

#include "chromium/base/macros.h"

#include "rplidar/rplidar.h"

namespace felicia {
namespace drivers {

class RPlidarFactory {
 public:
  static std::unique_ptr<RPlidar> NewLidar(const LidarEndpoint& lidar_endpoint);

  DISALLOW_COPY_AND_ASSIGN(RPlidarFactory);
};

}  // namespace drivers
}  // namespace felicia

#endif  // RPLIDAR_RPLIDAR_FACTORY_H_