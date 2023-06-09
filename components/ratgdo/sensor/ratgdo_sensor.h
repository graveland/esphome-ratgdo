#pragma once

#include "../ratgdo.h"
#include "../ratgdo_child.h"
#include "../ratgdo_state.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/core/component.h"

namespace esphome {
namespace ratgdo {

    enum RATGDOSensorType {
        RATGDO_OPENINGS
    };

    class RATGDOSensor : public sensor::Sensor, public RATGDOClient, public Component {
    public:
        void setup() override;
        void dump_config() override;
        void set_ratgo_sensor_type(RATGDOSensorType sensor_type_) { this->ratgdo_sensor_type_ = sensor_type_; }

        void on_openings_change(uint32_t openings) override;

    protected:
        RATGDOSensorType ratgdo_sensor_type_;
    };

} // namespace ratgdo
} // namespace esphome
