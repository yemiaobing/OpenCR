/*
 * micrortps.h
 *
 *  Created on: Mar 20, 2018
 *      Author: Kei
 */

#ifndef MICRORTPS_H_
#define MICRORTPS_H_

#include "microcdr/microcdr.h"
#include "micrortps/client/client.h"
#include "micrortps/client/xrce_protocol_spec.h"

#ifdef __cplusplus
 extern "C" {
#endif


typedef struct {
  XRCEInfo ids;
  uint8_t  operation;
  uint8_t  status;
} RtpsResponse_t;

typedef struct {
  bool is_init;
  XRCEInfo participant_info;
  XRCEInfo subscriber_info;
  XRCEInfo data_reader_info;
  XRCEInfo read_callback_info;
  DeserializeTopic func_deserialize;
} RtpsSubscriber_t;

typedef struct {
  bool is_init;
  XRCEInfo participant_info;
  XRCEInfo publisher_info;
  XRCEInfo data_writer_info;
  SerializeTopic func_serialize;
} RtpsPublisher_t;


typedef enum {
  CREATE_CLIENT = 0,
  CREATE_PARTICIPANT,
  CREATE_TOPIC,
  CREATE_PUBLISHER,
  CREATE_SUBSCRIBER,
  CREATE_WRITER,
  CREATE_READER,
} RtpsProcess_t;

typedef char* RtpsXml;


bool microRtpsIsInit(void);
bool microRtpsInit(void);
bool microRtpsSetup(void);
void microRtpsStop(void);
RtpsPublisher_t* microRtpsCreatePub(RtpsXml topic_profile, RtpsXml data_writer_profile, SerializeTopic func_serialize, uint32_t timeout);
RtpsSubscriber_t* microRtpsCreateSub(RtpsXml topic_profile, RtpsXml data_reader_profile, DeserializeTopic func_deserialize, uint32_t timeout);
void microRtpsWrite(RtpsPublisher_t* p_pub, void* topic);
void microRtpsRead(RtpsSubscriber_t* p_sub, OnTopicReceived callback_func, void* callback_func_args);

void microRtpslistenToAgent(void);




#ifdef __cplusplus
 }
#endif

#endif /* MICRORTPS_H_ */
