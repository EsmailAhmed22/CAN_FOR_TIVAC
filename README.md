# CAN_FOR_TIVAC
Dynamic Driver for Controller Area Network(CAN)
## Summary
### What does this driver support?
* Support CAN0 and CAN1 in TIVA-C
* Dynamic configuration for :
  * CAN-Rx PIN and CAN-Tx PIN changeable.
  * Bit Time Sampling.
  * 32 Message configuration at initialization then can be edited as needed.
* Message configurations are:
  * Message ID.
  * Messge ID extension enable and disble.
  * All kind of filtering to turn them on or off.
  * Message Type whether it is Transmit or Receive message.
  * Message Enable and Disable.
  * Remote Enable and Disable.
  * The size of the payload.   
### What does this driver does not support
* Working with interrupts.
* All test modes.

## Functions Implemented
* __void CAN_Init(const CAN_ConfigType *a_config_Ptr);__
  * This function is responsible for initializing the I2C.

* __void CAN_Data_Update(uint8 a_message_number , uint8 * a_payload , uint8 a_can_id);__
  * This function is responsible for Updating data.

* __void CAN_Send_Frame(uint8 a_message_number,uint8 a_can_id);__
  *  This function is responsible for Sending data frame and remote frame.

* __uint8 CAN_Is_Message_Received(uint8 a_message_number,uint8 a_can_id);__
  * This function to check wether their is newdata.

* __void CAN_Received_Message(uint8 a_message_number,uint8 a_can_id);__
  * This function responsbile for receiving data.
