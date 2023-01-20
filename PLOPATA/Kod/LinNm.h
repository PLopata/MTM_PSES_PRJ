#ifndef LIN_NM_H
#define LIN_NM_H

/**===================================================================================================================*\
  @file LinNm.h

  @brief LIN Network Management
  
  API funkcji nieschedule'owanych Network Managementu dla LIN

  @see LinNm.pdf
\*====================================================================================================================*/

/*====================================================================================================================*\
    Załączenie nagłówków
\*====================================================================================================================*/
#include "./Lib/ComStackTypes.h"
#include "./Lib/Nm.h"

/*====================================================================================================================*\
    Makra globalne
\*====================================================================================================================*/
#ifndef LINNM_CHANNEL_COUNT
#define LINNM_CHANNEL_COUNT 1
#endif

/*====================================================================================================================*\
    API
\*====================================================================================================================*/
typedef struct
{
  boolean             NodeDetectionEnabled;
  boolean             NodeIdEnabled;
  float32             TimeoutTime;
  NetworkHandleType   ComMNetworkHandleRef;
} LinNm_ChannelType;

/* [SWS_LinNm_00172] */
typedef struct 
{
  boolean             BusSynchronizationEnabled;
  boolean             RemoteSleepIndicationEnabled;
  boolean             UserDataEnabled;
  boolean             StateChangeIndEnabled;
  boolean             ComControlEnabled;
  boolean             PassiveModeEnabled;
  boolean             SynchronizationPointEnabled;
  boolean             CoordinatorSyncSupport;
  float32             MainFunctionPeriod;
  LinNm_ChannelType*  ChannelConfig[LINNM_CHANNEL_COUNT];
} LinNm_ConfigType;

/* [SWS_LinNm_00054] */
void LinNm_Init(const LinNm_ConfigType* ConfigPtr);

/* [SWS_LinNm_00063]*/
Std_ReturnType LinNm_PassiveStartUp(NetworkHandleType nmChannelHandle);

/* [SWS_LinNm_00055] */
Std_ReturnType LinNm_NetworkRequest(NetworkHandleType nmChannelHandle);

/* [SWS_LinNm_00056] */
Std_ReturnType LinNm_NetworkRelease(NetworkHandleType nmChannelHandle);

/* [SWS_LinNm_00106] */
void LinNm_GetVersionInfo(Std_VersionInfoType* versioninfo);

/* [SWS_LinNm_00089] */
Std_ReturnType LinNm_RequestBusSynchronization(NetworkHandleType nmChannelHandle);

/* [SWS_LinNm_00092] */
Std_ReturnType LinNm_CheckRemoteSleepIndication(NetworkHandleType nmChannelHandle, boolean* nmRemoteSleepIndPtr);

/* [SWS_LinNm_00175] */
Std_ReturnType LinNm_SetSleepReadyBit(NetworkHandleType nmChannelHandle, boolean nmSleepReadyBit);

/* [SWS_LinNm_00108] */
Std_ReturnType LinNm_DisableCommunication(NetworkHandleType NetworkHandle);

/* [SWS_LinNm_00111] */
Std_ReturnType LinNm_EnableCommunication(NetworkHandleType NetworkHandle);

/* [SWS_LinNm_00114] */
Std_ReturnType LinNm_SetUserData(NetworkHandleType NetworkHandle, const uint8* nmUserDataPtr);

/* [SWS_LinNm_00117] */
Std_ReturnType LinNm_GetUserData(NetworkHandleType NetworkHandle, uint8* nmUserDataPtr);

/* [SWS_LinNm_00120] */
Std_ReturnType LinNm_GetPduData(NetworkHandleType NetworkHandle, uint8* nmPduData);

/* [SWS_LinNm_00123] */
Std_ReturnType LinNm_RepeatMessageRequest(NetworkHandleType NetworkHandle);

/* [SWS_LinNm_00126] */
Std_ReturnType LinNm_GetNodeIdentifier(NetworkHandleType NetworkHandle, uint8* nmNodeIdPtr);

/* [SWS_LinNm_00129] */
Std_ReturnType LinNm_GetLocalNodeIdentifier(NetworkHandleType NetworkHandle, uint8* nmNodeIdPtr);

/* [SWS_LinNm_00135] */
Std_ReturnType LinNm_GetState(NetworkHandleType nmNetworkHandle, Nm_StateType* nmStatePtr, Nm_ModeType* nmModePtr);

/* [SWS_LinNm_00148] */
Std_ReturnType LinNm_Transmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr);

/* [SWS_LinNm_00153] */
void LinNm_TxConfirmation(PduIdType TxPduId, Std_ReturnType result);


#endif