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

/*====================================================================================================================*\
    Zmienne globalne
\*====================================================================================================================*/

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
Std_ReturnType LinNm_PassiveStartUp(NetworkHandleType nmChannelHandle)
{
  Std_ReturnType retVal = E_OK;

  return retVal;
}


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
Std_ReturnType LinNm_NetworkRequest(NetworkHandleType nmChannelHandle)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


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
Std_ReturnType LinNm_NetworkRelease(NetworkHandleType nmChannelHandle)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


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
Std_ReturnType LinNm_RequestBusSynchronization(NetworkHandleType nmChannelHandle)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


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
Std_ReturnType LinNm_CheckRemoteSleepIndication(NetworkHandleType nmChannelHandle, boolean* nmRemoteSleepIndPtr)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


/**
  @brief LinNm_SetSleepReadyBit
  Funkcja ma pozostać pusta
  @param nmChannelHandle,nmSleepReadyBit
  @note Realizacja wymagań:
  [SWS_LinNm_00175],
  [SWS_LinNm_00176],
  [SWS_LinNm_00177]
*/
Std_ReturnType LinNm_SetSleepReadyBit(NetworkHandleType nmChannelHandle, boolean nmSleepReadyBit)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


/**
  @brief LinNm_DisableCommunication
  Funkcja ma pozostać pusta
  @param NetworkHandle
  @note Realizacja wymagań:
  [SWS_LinNm_00108],
  [SWS_LinNm_00109],
  [SWS_LinNm_00110]
*/
Std_ReturnType LinNm_DisableCommunication(NetworkHandleType NetworkHandle)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


/**
  @brief LinNm_EnableCommunication
  Funkcja ma pozostać pusta
  @param NetworkHandle
  @note Realizacja wymagań:
  [SWS_LinNm_00111],
  [SWS_LinNm_00112],
  [SWS_LinNm_00113]
*/
Std_ReturnType LinNm_EnableCommunication(NetworkHandleType NetworkHandle)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


/**
  @brief LinNm_SetUserData
  Funkcja ma pozostać pusta.
  @param NetworkHandle,nmUserDataPtr
  @note Realizacja wymagań:
  [SWS_LinNm_00114],
  [SWS_LinNm_00115],
  [SWS_LinNm_00116]
*/
Std_ReturnType LinNm_SetUserData(NetworkHandleType NetworkHandle, const uint8* nmUserDataPtr)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


/**
  @brief LinNm_GetUserData
  Funkcja ma pozostać pusta
  @param NetworkHandle,nmUserDataPtr
  @note Realizacja wymagań:
  [SWS_LinNm_00117],
  [SWS_LinNm_00118],
  [SWS_LinNm_00119]
*/
Std_ReturnType LinNm_GetUserData(NetworkHandleType NetworkHandle, uint8* nmUserDataPtr)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


/**
  @brief LinNm_GetPduData
  Funkcja ma pozostać pusta
  @param NetworkHandle,nmPduData
  @note Realizacja wymagań:
  [SWS_LinNm_00120],
  [SWS_LinNm_00121],
  [SWS_LinNm_00122]
*/
Std_ReturnType LinNm_GetPduData(NetworkHandleType NetworkHandle, uint8* nmPduData)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


/**
  @brief LinNm_RepeatMessageRequest
  Funkcja ma pozostać pusta
  @param NetworkHandle
  @note Realizacja wymagań:
  [SWS_LinNm_00123],
  [SWS_LinNm_00124],
  [SWS_LinNm_00125]
*/
Std_ReturnType LinNm_RepeatMessageRequest(NetworkHandleType NetworkHandle)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


/**
  @brief LinNm_GetNodeIdentifier
  Funkcja ma pozostać pusta
  @param NetworkHandle,nmNodeIdPtr
  @note Realizacja wymagań:
  [SWS_LinNm_00126],
  [SWS_LinNm_00127],
  [SWS_LinNm_00128]
*/
Std_ReturnType LinNm_GetNodeIdentifier(NetworkHandleType NetworkHandle, uint8* nmNodeIdPtr)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


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
Std_ReturnType LinNm_GetLocalNodeIdentifier(NetworkHandleType NetworkHandle, uint8* nmNodeIdPtr)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


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
Std_ReturnType LinNm_Transmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr)
{
  Std_ReturnType retVal = E_OK;
  
  return retVal;
}


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

}
