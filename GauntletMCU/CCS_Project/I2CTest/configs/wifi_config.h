/*
 * wifi_config.h
 *
 *  Created on: Feb 7, 2020
 *      Author: halitosisman
 */


#include <ti/drivers/net/wifi/simplelink.h>

#ifndef CONFIGS_WIFI_CONFIG_H_
#define CONFIGS_WIFI_CONFIG_H_

#define DEVICE_NAME "FGprototype"

#define SSID_NAME "im_a_potato"
#define SECURITY_KEY "potatoss"
#define SECURITY_TYPE SL_WLAN_SEC_TYPE_WPA_WPA2;

#define CONNECT_TIMEOUT_MS 5000 // It's entirely possible that one of the Simplelink configs overrides this.

#endif /* CONFIGS_WIFI_CONFIG_H_ */
