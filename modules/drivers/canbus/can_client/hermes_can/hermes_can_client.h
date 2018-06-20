/***************************************************************************
 *
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
 * @file esd_can_client.h
 * @author zhuzhenguang<zhuzhenguang@baidu.com>(zhuzhenguang@baidu.com)
 * @date 2016/03/16 20:54:43
 * @brief the encapsulate call the api of esd can card according to can_client.h interface
 *
 **/

#ifndef  MODULES_DRIVERS_CANBUS_CAN_CLIENT_CLIENT_HERMES_CAN_CLIENT_H
#define  MODULES_DRIVERS_CANBUS_CAN_CLIENT_CLIENT_HERMES_CAN_CLIENT_H

#include <string>

#include "gflags/gflags.h"
#include "modules/common/proto/error_code.pb.h"
#include "modules/drivers/canbus/can_client/can_client.h"
#include "modules/drivers/canbus/common/canbus_consts.h"
#include "modules/drivers/canbus/proto/can_card_parameter.pb.h"

#include "modules/drivers/canbus/can_client/hermes_can/bcan.h"
/**
 * @namespace apollo::drivers::canbus::can
 * @brief apollo::drivers::canbus::can
 */

namespace apollo {
namespace drivers {
namespace canbus {
namespace can {

/**
 * @class HermesCanClient
 * @brief The class which defines a BCAN client which inherits CanClient.
 */

class HermesCanClient : public CanClient {
public :

    /**
     * @brief Initialize the BCAN client by specified CAN card parameters.
     * @param parameter CAN card parameters to initialize the CAN client.
     */
    //explicit HermesCanClient(const CANCardParameter &parameter);
   
    /**
     * @brief Destructor
     */
    virtual ~HermesCanClient();

    /**
     * @brief Start the ESD CAN client.
     * @return The status of the start action which is defined by
     *         apollo::common::ErrorCode.
     */
    bool Init(const CANCardParameter &parameter) override;

    /**
     * @brief Start the ESD CAN client.
     * @return The status of the start action which is defined by
     *         apollo::common::ErrorCode.
     */
    apollo::common::ErrorCode Start() override;

    /**
     * @brief Stop the ESD CAN client.
     */

    virtual void Stop();

    /**
     * @brief Send messages
     * @param frames The messages to send.
     * @param frame_num The amount of messages to send.
     * @return The status of the sending action which is defined by
     *         apollo::common::ErrorCode.
     */                                     
    virtual apollo::common::ErrorCode Send(const std::vector<CanFrame> &frames, int32_t *const frame_num);

   /**
    * @brief Receive messages
    * @param frames The messages to receive.
    * @param frame_num The amount of messages to receive.
    * @return The status of the receiving action which is defined by
    *         apollo::common::ErrorCode.
    */                                    
    virtual apollo::common::ErrorCode Receive(std::vector<CanFrame> *const frames, 
                                              int32_t *const frame_num);
    /**
     * @brief Get the error string.
     * @param status The status to get the error string.
     */                                              
    virtual std::string GetErrorString(const int32_t status);
    /**
     * @brief Set inited status.
     * @param if status is inited.
     */  
    void SetInited(bool init);

private:
    bool _is_init;
    bcan_hdl_t _dev_handler;
    CANCardParameter::CANChannelId _card_port;
    bcan_msg_t _send_frames[MAX_CAN_SEND_FRAME_LEN];
    bcan_msg_t _recv_frames[MAX_CAN_RECV_FRAME_LEN];
};

} // namespace can
} // namespace canbus
} // namespace drivers
} // namespace apollo

#endif // MODULES_DRIVERS_CANBUS_CAN_CLIENT_CLIENT_HERMES_CAN_CLIENT_H

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */