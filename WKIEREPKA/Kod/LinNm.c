/** ==================================================================================================================*\
  @file LinNm.c

  @brief Implementacja LIN Network Managementu
  
  Implementacja LIN Network Managementu

  @see LinNm.pdf
\*====================================================================================================================*/

/*====================================================================================================================*\
    Załączenie nagłówków
\*====================================================================================================================*/
#include "LinNm.h"
#include "Lib/ComStackTypes.h"  /** [SWS_LinNM_00078] */
#include "Lib/Std_Types.h"

/*====================================================================================================================*\
    Konfiguracja
\*====================================================================================================================*/
#ifndef NULL
#define NULL ((void *)0)
#endif
/** [SWS_LinNm_00158] -> LinNm_NetworkRequest available */
/** [SWS_LinNm_00159] -> LinNm_NetworkRelease available */
/** [SWS_LinNm_00116] -> LinNm_SetUserData available condition 1 */
#define LINNM_PASSIVE_MODE_ENABLED FALSE
/** [SWS_LinNm_00091] -> LinNm_RequestBusSynchronization available */
#define LINNM_BUS_SYNCHRONIZATION_ENABLED  TRUE
/** [SWS_LinNm_00096] -> LinNm_CheckRemoteSleepIndication available */
#define LINNM_REMOTE_SLEEP_INDICATION_ENABLED  TRUE
/** [SWS_LinNm_00110] -> LinNm_DisableCommunication available */
/** [SWS_LinNm_00113] -> LinNm_EnableCommunication available */
#define LINNM_COM_CONTROL_ENABLED TRUE
/** [SWS_LinNm_00116] -> LinNm_SetUserData available condition 2 */
/** [SWS_LinNm_00119] -> LinNm_GetUserData available */
/** [SWS_LinNm_00122] -> LinNm_GetPduData available condition 1 */
#define LINNM_USER_DATA_ENABLED  TRUE
/** [SWS_LinNm_00122] -> LinNm_GetPduData available condition 2 */
/** [SWS_LinNm_00128] -> LinNm_GetNodeIdentifier available */
/** [SWS_LinNm_00128] -> LinNm_GetLocalNodeIdentifier available */
#define LINNM_NODE_ID_ENABLED TRUE
/** [SWS_LinNm_00125] -> LinNm_RepeatMessageRequest available */
#define LINNM_NODE_DETECTION_ENABLED  TRUE
/** [SWS_LinNm_00151] -> LinNm_Transmit available */
#define LINNM_COM_USER_DATA_SUPPORT TRUE
/** Precondition for [SWS_LinNm_00061] */
#define LINNM_STATE_CHANGE_IND_ENABLED TRUE
/** [SWS_LinNm_00140] -> LinNm_SynchronizationPoint always disabled */
#define LINNM_SYNCHRONIZATIONPOINT_ENABLED FALSE
/*====================================================================================================================*\
    Definicje typów
\*====================================================================================================================*/
typedef enum
{
  LINNM_STATUS_INIT,
  LINNM_STATUS_UNINIT
} LinNm_InitStatusType;

typedef struct
{
  Nm_ModeType   Mode;   /** [SWS_LinNm_00005] */
  Nm_StateType  State;  
} LinNm_InternalChannelType;

typedef struct
{
  LinNm_InitStatusType        InitStatus;
  LinNm_InternalChannelType   Channels[LINNM_CHANNEL_COUNT];
} LinNm_InternalType;

/*====================================================================================================================*\
    Zmienne globalne
\*====================================================================================================================*/
const static LinNm_ConfigType* LinNm_ConfigPtr;

static LinNm_InternalType LinNm_Internal = {
  .InitStatus = LINNM_STATUS_UNINIT
};

/*====================================================================================================================*\
    Kod funkcji
\*====================================================================================================================*/

/**
  @brief LinNm_Init
  Funkcja inicjalizująca LIN Network Management
  @param ConfigPtr 
  @note Realizacja wymagań:
  [SWS_LinNm_00054]
*/
void LinNm_Init(const LinNm_ConfigType* ConfigPtr)
{
  /** [SWS_LinNm_00102] - No callouts shall be made inside LinNm_Init*/
  if(ConfigPtr == NULL)
  {
    // add DET
    /** [SWS_LinNm_00048] */
  }
  else
  {
    for(uint8 channel=0; channel<LINNM_CHANNEL_COUNT; channel++)
    {
      const LinNm_ChannelType* ChannelConf = ConfigPtr->ChannelConfig[channel];
      LinNm_InternalChannelType* ChannelInternal = &LinNm_Internal.Channels[channel];
      NetworkHandleType ChannelHandle = ChannelConf->ComMNetworkHandleRef;

      ChannelInternal->State = NM_STATE_UNINIT;   /** [SWS_LinNm_00017] */

      ChannelInternal->Mode = NM_MODE_BUS_SLEEP;    /** [SWS_LinNm_00020] */
      ChannelInternal->State = NM_STATE_BUS_SLEEP;  /** [SWS_LinNm_00018], [SWS_LinNm_00019] */
      LinNm_Internal.InitStatus = LINNM_STATUS_INIT;
    //  Nm_BusSleepMode(ChannelHandle);   /** [SWS_LinNm_00006] */

      /** [SWS_LinNm_00061] */
      #ifdef LINNM_STATE_CHANGE_IND_ENABLED
     //   Nm_StateChangeNotification(ChannelHandle, NM_STATE_UNINIT, NM_STATE_BUS_SLEEP);
      #endif
    }
  }
}


/**
  @brief LinNm_PassiveStartUp
  Funkcja umożliwiająca pasywne uruchomienie LIN Network Management
  @param nmChannelHandle 
  @note Realizacja wymagań:
  [SWS_LinNm_00063],
  [SWS_LinNm_00064],
  [SWS_LinNm_00065]
*/
#if (LINNM_PASSIVE_MODE_ENABLED == FALSE)   /** [SWS_LinNm_00158] */
Std_ReturnType LinNm_PassiveStartUp(NetworkHandleType nmChannelHandle)
{
  Std_ReturnType retVal = E_OK;
  uint8 channelNr;

  if(LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] [SWS_LinNm_00065] */
  }

  if(LinNm_Internal.Channels[channelNr].Mode != NM_MODE_BUS_SLEEP)
  {
    return E_NOT_OK;  /** [SWS_LinNm_00064] */
  }
  
  if( retVal == E_OK )
  {
    if( LinNm_Internal.Channels[channelNr].Mode == NM_MODE_BUS_SLEEP )
    {
      LinNm_Internal.Channels[channelNr].Mode   = NM_MODE_NETWORK;           /** [SWS_LinNm_00161] */
      LinNm_Internal.Channels[channelNr].State  = NM_STATE_NORMAL_OPERATION; /** [SWS_LinNm_00160] */
     // Nm_NetworkMode(nmChannelHandle);

      /** [SWS_LinNm_00061] */
      #ifdef LINNM_STATE_CHANGE_IND_ENABLED
     //  Nm_StateChangeNotification(nmChannelHandle, NM_STATE_BUS_SLEEP, NM_STATE_NORMAL_OPERATION);
      #endif

     // Nm_RemoteSleepIndication(nmChannelHandle);  /** [SWS_LinNm_00141] */
    }
    else if( LinNm_Internal.Channels[channelNr].Mode == NM_MODE_NETWORK )
    {
      retVal = E_NOT_OK;  /** [SWS_LinNm_00022] */
    }
  }
 // retVal = E_NOT_OK; //remove when done
  return retVal;
}
#endif


/**
  @brief LinNm_NetworkRequest
  Funkcja umożliwiająca wykonanie prośby o udostępnienie magistrali LIN.
  ECU potrzebuje komunikować się po magistrali.
  @param nmChannelHandle 
  @note Realizacja wymagań:
  [SWS_LinNm_00055],
  [SWS_LinNm_00053],
  [SWS_LinNm_00158]
*/
#if (LINNM_PASSIVE_MODE_ENABLED == FALSE)   /** [SWS_LinNm_00159] */
Std_ReturnType LinNm_NetworkRequest(NetworkHandleType nmChannelHandle)
{
  Std_ReturnType retVal = E_OK;
  uint8 channelNr;

  if(LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] [SWS_LinNm_00053] */
  }
  
  if( retVal == E_OK )
  {
    if( LinNm_Internal.Channels[channelNr].Mode == NM_MODE_BUS_SLEEP )
    {
      LinNm_Internal.Channels[channelNr].Mode   = NM_MODE_NETWORK;            /** [SWS_LinNm_00162], [SWS_LinNm_00014] */
      LinNm_Internal.Channels[channelNr].State  = NM_STATE_NORMAL_OPERATION;  /** [SWS_LinNm_00015] */
     // Nm_NetworkMode(nmChannelHandle);

      /** [SWS_LinNm_00061] */
      #ifdef LINNM_STATE_CHANGE_IND_ENABLED
     //   Nm_StateChangeNotification(nmChannelHandle, NM_STATE_BUS_SLEEP, NM_STATE_NORMAL_OPERATION);
      #endif

      //Nm_RemoteSleepIndication(nmChannelHandle);  /** [SWS_LinNm_00141] */
    }
    else if( LinNm_Internal.Channels[channelNr].Mode == NM_MODE_NETWORK )
    {
      retVal = E_NOT_OK;  /** [SWS_LinNm_00156] */
    }
  }
  else{}

  return retVal;
}
#endif


/**
  @brief LinNm_NetworkRelease
  Funkcja umożliwiająca wykonanie prośby o zwolnienie magistrali LIN.
  ECU już nie potrzebuje komunikować się po magistrali.
  @param nmChannelHandle 
  @note Realizacja wymagań:
  [SWS_LinNm_00056],
  [SWS_LinNm_00058],
  [SWS_LinNm_00159]
*/
#if (LINNM_PASSIVE_MODE_ENABLED == FALSE) /** [SWS_LinNm_00159] */
Std_ReturnType LinNm_NetworkRelease(NetworkHandleType nmChannelHandle)
{
  Std_ReturnType retVal = E_OK;
  uint8 channelNr;

  if(LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] [SWS_LinNm_00058] */
  }
  
  if( retVal == E_OK )
  {
    if( LinNm_Internal.Channels[channelNr].Mode == NM_MODE_NETWORK )
    {
      LinNm_Internal.Channels[channelNr].Mode   = NM_MODE_BUS_SLEEP;    /** [SWS_LinNm_00004] */
      LinNm_Internal.Channels[channelNr].State  = NM_STATE_BUS_SLEEP;   /** [SWS_LinNm_00016] */
    //  Nm_BusSleepMode(nmChannelHandle);   /** [SWS_LinNm_00012] */

      /** [SWS_LinNm_00061] */
      #ifdef LINNM_STATE_CHANGE_IND_ENABLED
     //   Nm_StateChangeNotification(nmChannelHandle, NM_STATE_NORMAL_OPERATION, NM_STATE_BUS_SLEEP);
      #endif
    }
    else if( LinNm_Internal.Channels[channelNr].Mode == NM_MODE_BUS_SLEEP )
    {
      retVal = E_NOT_OK;  /** [SWS_LinNm_00157] */
    }
  }
  else{}

  return retVal;
}
#endif


/**
  @brief LinNm_GetVersionInfo
  Funkcja umożliwiająca odczytanie aktualnej wersji modułu LinNm
  @param versioninfo 
  @note Realizacja wymagań:
  [SWS_LinNm_00106],
  [SWS_LinNm_00163]
*/
void LinNm_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
  if( versioninfo == NULL )
  {
    //add DET. report an error LINNM_E_PARAM_POINTER DET 
    /** [SWS_LinNm_00048] [SWS_LinNm_00163] */
  }
  else
  {
    //obsługa funkcji
  }
}


/**
  @brief LinNm_RequestBusSynchronization 
  Funkcja ma pozostać pusta
  @param nmChannelHandle
  @note Realizacja wymagań:
  [SWS_LinNm_00089],
  [SWS_LinNm_00095],
  [SWS_LinNm_00090],
  [SWS_LinNm_00091]
*/
//#ifdef LINNM_BUS_SYNCHRONIZATION_ENABLED  /** [SWS_LinNm_00091] */
//#ifndef LINNM_PASSIVE_MODE_ENABLED  /** [SWS_LinNm_00091] */
Std_ReturnType LinNm_RequestBusSynchronization(NetworkHandleType nmChannelHandle)
{
  Std_ReturnType retVal = E_OK;
  uint8 channelNr;
  
  if(LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] [SWS_LinNm_00090] */
  }

  /** [SWS_LinNm_00095] -> pusta implementacja */

  return retVal;
}
//#endif
//#endif



/**
  @brief LinNm_CheckRemoteSleepIndication
  Funkcja ma pozostać pusta
  @param nmChannelHandle,nmRemoteSleepIndPtr
  @note Realizacja wymagań:
  [SWS_LinNm_00092],
  [SWS_LinNm_00093],
  [SWS_LinNm_00094],
  [SWS_LinNm_00096]
*/
#ifdef LINNM_REMOTE_SLEEP_INDICATION_ENABLED  /** [SWS_LinNm_00096] */
Std_ReturnType LinNm_CheckRemoteSleepIndication(NetworkHandleType nmChannelHandle, boolean* nmRemoteSleepIndPtr)
{
  Std_ReturnType retVal = E_OK;
  
  if(LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] [SWS_LinNm_00094] */
  }
  if( /** Nm is not initialized correctly */ FALSE )
  {
    //add DET
    /** [SWS_LinNm_00094] */
    retVal = E_NOT_OK;
  }
  if( nmRemoteSleepIndPtr == NULL )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00048] */
  }

  /** [SWS_LinNm_00093] -> pusta implementacja */

  return retVal;
}
#endif


/**
  @brief LinNm_SetSleepReadyBit
  Funkcja ma pozostać pusta
  @param nmChannelHandle,nmSleepReadyBit
  @note Realizacja wymagań:
  [SWS_LinNm_00175],
  [SWS_LinNm_00176],
  [SWS_LinNm_00177]
*/
#if (LINNM_COORDINATOR_SYNC_SUPPORT == True)  /** [SWS_LinNm_00169]  */
Std_ReturnType LinNm_SetSleepReadyBit(NetworkHandleType nmChannelHandle, boolean nmSleepReadyBit)
{
  Std_ReturnType retVal = E_OK;
  
  if( LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] */
  }

  /** [SWS_LinNm_00177] -> pusta implementacja */
  
  return retVal;
}
#endif

/**
  @brief LinNm_DisableCommunication
  Funkcja ma pozostać pusta
  @param NetworkHandle
  @note Realizacja wymagań:
  [SWS_LinNm_00108],
  [SWS_LinNm_00109],
  [SWS_LinNm_00110]
*/
#if (LINNM_COM_CONTROL_ENABLED == TRUE) /** [SWS_LinNm_00110] */
Std_ReturnType LinNm_DisableCommunication(NetworkHandleType NetworkHandle)
{
  Std_ReturnType retVal = E_OK;
  
  if( LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] */
  }
  if( /** Nm is not initialized correctly */ FALSE )
  {
    //add DET
    /** [SWS_LinNm_00109] */
    retVal = E_NOT_OK;
  }

  /** [SWS_LinNm_00108] -> pusta implementacja */

  return retVal;
}
#endif


/**
  @brief LinNm_EnableCommunication
  Funkcja ma pozostać pusta
  @param NetworkHandle
  @note Realizacja wymagań:
  [SWS_LinNm_00111],
  [SWS_LinNm_00112],
  [SWS_LinNm_00113]
*/
#if (LINNM_COM_CONTROL_ENABLED == TRUE) /** [SWS_LinNm_00113] */
Std_ReturnType LinNm_EnableCommunication(NetworkHandleType NetworkHandle)
{
  Std_ReturnType retVal = E_OK;
  
  if( LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] */
  }
  if( /** Nm is not initialized correctly */ FALSE )
  {
    //add DET
    /** [SWS_LinNm_00112] */
    retVal = E_NOT_OK;
  }

  /** [SWS_LinNm_00111] -> pusta implementacja */

  return retVal;
}
#endif


/**
  @brief LinNm_SetUserData
  Funkcja ma pozostać pusta.
  @param NetworkHandle,nmUserDataPtr
  @note Realizacja wymagań:
  [SWS_LinNm_00114],
  [SWS_LinNm_00115],
  [SWS_LinNm_00116]
*/
#if ((LINNM_USER_DATA_ENABLED == TRUE) && (LINNM_PASSIVE_MODE_ENABLED == FALSE))  /** [SWS_LinNm_00116] */
Std_ReturnType LinNm_SetUserData(NetworkHandleType NetworkHandle, const uint8* nmUserDataPtr)
{
  Std_ReturnType retVal = E_OK;
  
  if( LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] */
  }
  if( /** Nm is not initialized correctly */ FALSE )
  {
    //add DET
    /** [SWS_LinNm_00115] */
    retVal = E_NOT_OK;
  }
  if( nmUserDataPtr == NULL )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00048] */
  }

  /** [SWS_LinNm_00114] -> pusta implementacja */

  return retVal;
}
#endif


/**
  @brief LinNm_GetUserData
  Funkcja ma pozostać pusta
  @param NetworkHandle,nmUserDataPtr
  @note Realizacja wymagań:
  [SWS_LinNm_00117],
  [SWS_LinNm_00118],
  [SWS_LinNm_00119]
*/
#if (LINNM_USER_DATA_ENABLED == TRUE) /** [SWS_LinNm_00119] */
Std_ReturnType LinNm_GetUserData(NetworkHandleType NetworkHandle, uint8* nmUserDataPtr)
{
  Std_ReturnType retVal = E_OK;
  
  if( LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] */
    //add error code
  }
  if( /** Nm is not initialized correctly */ FALSE )
  {
    //add DET
    /** [SWS_LinNm_00118] */
    retVal = E_NOT_OK;
  }
  if( nmUserDataPtr == NULL )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00048] */
  }

  /** [SWS_LinNm_00117] -> pusta implementacja */

  return retVal;
}
#endif


/**
  @brief LinNm_GetPduData
  Funkcja ma pozostać pusta
  @param NetworkHandle,nmPduData
  @note Realizacja wymagań:
  [SWS_LinNm_00120],
  [SWS_LinNm_00121],
  [SWS_LinNm_00122]
*/
#if ((LINNM_NODE_ID_ENABLED == TRUE) || (LINNM_USER_DATA_ENABLED == TRUE))
Std_ReturnType LinNm_GetPduData(NetworkHandleType NetworkHandle, uint8* nmPduData)
{
  Std_ReturnType retVal = E_OK;
  
  if( LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] */
    //add error code
  }
  if( /** Nm is not initialized correctly */ FALSE )
  {
    //add DET
    /** [SWS_LinNm_00121] */
    retVal = E_NOT_OK;
  }
  if( nmPduData == NULL )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00048] */
  }

  /** [SWS_LinNm_00120] -> pusta implementacja */

  return retVal;
}
#endif


/**
  @brief LinNm_RepeatMessageRequest
  Funkcja ma pozostać pusta
  @param NetworkHandle
  @note Realizacja wymagań:
  [SWS_LinNm_00123],
  [SWS_LinNm_00124],
  [SWS_LinNm_00125]
*/
#if (LINNM_NODE_DETECTION_ENABLED == TRUE) /** [SWS_LinNm_00125] */
Std_ReturnType LinNm_RepeatMessageRequest(NetworkHandleType NetworkHandle)
{
  Std_ReturnType retVal = E_OK;
  
  if(LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] */
    //add error code
  }
  if( /** Nm is not initialized correctly */ FALSE )
  {
    //add DET
    /** [SWS_LinNm_00124] */
    retVal = E_NOT_OK;
  }

  /** [SWS_LinNm_00123] -> pusta implementacja */

  return retVal;
}
#endif


/**
  @brief LinNm_GetNodeIdentifier
  Funkcja ma pozostać pusta
  @param NetworkHandle,nmNodeIdPtr
  @note Realizacja wymagań:
  [SWS_LinNm_00126],
  [SWS_LinNm_00127],
  [SWS_LinNm_00128]
*/
#if (LINNM_NODE_ID_ENABLED == TRUE) /** [SWS_LinNm_00128] */
Std_ReturnType LinNm_GetNodeIdentifier(NetworkHandleType NetworkHandle, uint8* nmNodeIdPtr)
{
  Std_ReturnType retVal = E_OK;
  
  if( LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] */
  }
  if( /** Nm is not initialized correctly */ FALSE )
  {
    //add DET
    /** [SWS_LinNm_00127] */
    retVal = E_NOT_OK;
  }
  if( nmNodeIdPtr == NULL )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00048] */
  }

  /** [SWS_LinNm_00126] -> pusta implementacja */

  return retVal;
}
#endif


/**
  @brief LinNm_GetLocalNodeIdentifier
  TODO: Co to właściwie znaczy funkcja ma zostać pusta?
  Empty function to be complaint with NM specifications.
  @param NetworkHandle,nmNodeIdPtr
  @note Realizacja wymagań:
  [SWS_LinNm_00129],
  [SWS_LinNm_00130],
  [SWS_LinNm_00131]
*/
#if (LINNM_NODE_ID_ENABLED == TRUE) /** [SWS_LinNm_00131] */
Std_ReturnType LinNm_GetLocalNodeIdentifier(NetworkHandleType NetworkHandle, uint8* nmNodeIdPtr)
{
  Std_ReturnType retVal = E_OK;
  
  if( LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] */
  }
  if( /** Nm is not initialized correctly */ FALSE )
  {
    /** [SWS_LinNm_00130] */
    //add DET
    retVal = E_NOT_OK;
  }
  if( nmNodeIdPtr == NULL )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00048] */
  }

  /** [SWS_LinNm_00129] -> pusta implementacja */

  return retVal;
}
#endif


/**
  @brief LinNm_GetState
  @param nmNetworkHandle,nmStatePtr
  
  Funkcja zwraca stan Network Managementu. Funkcja LinNm_GetState
  ma zostać wywołana jeśli kanał został skonfigurowany na LIN.
  
  Realizacja wymagań:
  [SWS_LinNm_00135],
  [SWS_LinNm_00136]
*/
Std_ReturnType LinNm_GetState(NetworkHandleType nmNetworkHandle, Nm_StateType* nmStatePtr, Nm_ModeType* nmModePtr)
{
  Std_ReturnType retVal = E_OK;
  uint8 channelNr;
  
  if( LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] */
    //add error code
  }
  if( /** Nm is not initialized correctly */ FALSE )
  {
    //add DET
    /** [SWS_LinNm_00136] */
    retVal = E_NOT_OK;
  }
  if( nmStatePtr == NULL )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00048] */
  }
  
  if( retVal == E_OK )
  {
    nmStatePtr = &LinNm_Internal.Channels[channelNr].State;
    nmModePtr = &LinNm_Internal.Channels[channelNr].Mode;
  }
  else{}

  return retVal;
}


/**
  @brief LinNm_Transmit
  @param TxPduId,PduInfoPtr
  
  Funkcja prosi o transmisję PDU.
  
  Realizacja wymagań:
  [SWS_LinNm_00148],
  [SWS_LinNm_00149],
  [SWS_LinNm_00178],
  [SWS_LinNm_00150],
  [SWS_LinNm_00151]
*/
//#if (LINNM_COM_USER_DATA_SUPPORT == True) /** [SWS_LinNm_00151]  */
Std_ReturnType LinNm_Transmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  
  if( LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00025] */
  }
  if( /** Nm is not initialized correctly */ FALSE )
  {
    //add DET
    /** [SWS_LinNm_00150] */
    retVal = E_NOT_OK;
  }
  if( PduInfoPtr == NULL )
  {
    //add DET
    retVal = E_NOT_OK;  /** [SWS_LinNm_00048] */
  }

  /** [SWS_LinNm_00149] -> pusta implementacja */

  return E_NOT_OK; /** [SWS_LinNm_00178] -> zawsze zwraca E_NOT_OK*/
}
//#endif


/**
  @brief LinNm_TxConfirmation:
  Niższa warstwa modułu interfejsu komunikacyjnego potwierdza
  poprawne wykonanie transmisji PDU, albo zwraca informację
  o błędzie podczas próby transmisji.
  @param TxPduId,result
  @note Realizacja wymagań:
  [SWS_LinNm_00153],
  [SWS_LinNm_00154],
  [SWS_LinNm_00179]
*/
void LinNm_TxConfirmation(PduIdType TxPduId, Std_ReturnType result)
{
  if( LinNm_Internal.InitStatus == LINNM_STATUS_UNINIT )
  {
    /** [SWS_LinNm_00025] */
    //add error code
  }
  else if( /** Nm is not initialized correctly */ FALSE )
  {
    //add DET
    /** [SWS_LinNm_00154] */
  }
  else
  {
    if( result != E_OK )
    {
      /**[SWS_LinNm_00179] -> raise development error LINNM_E_INVALID_PARAMETER */
    }
  }
}
