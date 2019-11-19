// Copyright (c) 2019 The Felicia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef RPLIDAR_RPLIDAR_H_
#define RPLIDAR_RPLIDAR_H_

#include "chromium/base/memory/weak_ptr.h"
#include "chromium/base/threading/thread.h"
#include "felicia/core/lib/error/statusor.h"
#include "felicia/core/util/timestamp/timestamper.h"
#include "felicia/drivers/lidar/lidar_interface.h"
// #define __le in sdk/sdk/src/hal causes a compilation error
#include <rplidar.h>

namespace felicia {
namespace drivers {

class RPlidar : public LidarInterface, public base::SupportsWeakPtr<RPlidar> {
 public:
  ~RPlidar();

  Status Init() override;
  Status Start(LidarFrameCallback lidar_frame_callback) override;
  Status Stop() override;

  Status GetSupportedScanModes(
      std::vector<rp::standalone::rplidar::RplidarScanMode>* scan_modes);
  Status Start(rp::standalone::rplidar::RplidarScanMode scan_mode,
               LidarFrameCallback lidar_frame_callback);

  void DoScanOnce();
  void DoScanLoop();

 private:
  friend class RPlidarFactory;

  RPlidar(const LidarEndpoint& lidar_endpoint);

  Status DoStart(rp::standalone::rplidar::RplidarScanMode* scan_mode,
                 LidarFrameCallback lidar_frame_callback);
  void DoScan();
  LidarFrame ToLidarFrame(rplidar_response_measurement_node_hq_t* nodes,
                          size_t node_count, double scan_time,
                          float angle_start, float angle_end);

  base::Thread thread_;
  Timestamper timestamper_;
  bool is_stopping_ = false;

  std::unique_ptr<rp::standalone::rplidar::RPlidarDriver> driver_;
  rp::standalone::rplidar::RplidarScanMode scan_mode_;

  DISALLOW_IMPLICIT_CONSTRUCTORS(RPlidar);
};

}  // namespace drivers
}  // namespace felicia

#endif  // RPLIDAR_RPLIDAR_H_