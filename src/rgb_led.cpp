/**
 * \file
 * \brief   Plugin for MAVROS to control RGB LED
 * \author  Andrey Stepanov
 * \version 0.0.1
 * \copyright
 * MIT License \n
 * Copyright (c) 2020 Andrey Stepanov \n
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions: \n
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software. \n
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <mavros/mavros_plugin.h>

namespace mavros {

using Subscriptions = plugin::PluginBase::Subscriptions;

namespace rgbled_plugin {

/**
 * \brief   RGB Led plugin
 * \details Send command to RGB LED via LED_CONTROL message
 */
class RGBLEDPlugin : public plugin::PluginBase {
    public:
        RGBLEDPlugin();

        void initialize(UAS& uas_);

        Subscriptions get_subscriptions();

    private:
        ros::NodeHandle plugin_nh;
};

RGBLEDPlugin::RGBLEDPlugin():
        PluginBase(),
        plugin_nh("~rgb_led")
{}

void RGBLEDPlugin::initialize(UAS& uas_) {
    PluginBase::initialize(uas_);
}

Subscriptions RGBLEDPlugin::get_subscriptions() {
    return {};
}

} // namespace std_plugins

} // namespace mavros

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mavros::rgbled_plugin::RGBLEDPlugin, mavros::plugin::PluginBase)
