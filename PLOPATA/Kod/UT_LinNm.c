/** ==================================================================================================================*\
  @file UT_LinNm.c

  @brief Testy jednostkowe do LinNm
\*====================================================================================================================*/

#include "./Lib/acutest.h"
#include "./Lib/Std_Types.h"
#include "LinNm.c"


/**
  @brief Test inicjalizowania LinNm

  Funkcja testująca inicjalizację LinNm
*/
void UT_LinNm_Init(void)
{
    Std_ReturnType result = E_NOT_OK;
    TEST_CHECK(result == E_OK);
}


/**
  @brief Test pasywnego uruchamiania LinNm

  Funkcja testująca pasywne uruchamianie LinNm
*/
void UT_LinNm_PassiveStartUp(void)
{
    Std_ReturnType result = E_NOT_OK;
    TEST_CHECK(result == E_OK);
}


/**
  @brief Test złożenia prośby o udostępnienie magistrali

  Funkcja testująca prośbę o udostępnienie magistrali LIN
*/
void UT_LinNm_NetworkRequest(void)
{
    Std_ReturnType result = E_NOT_OK;
    TEST_CHECK(result == E_OK);
}


/**
  @brief Test zwolnienia magistrali

  Funkcja testująca zwalnianie magistrali LIN
*/
void UT_LinNm_NetworkRelease(void)
{
    Std_ReturnType result = E_NOT_OK;
    TEST_CHECK(result == E_OK);
}


/**
  @brief Test odczytu wersji modułu LinNm

  Funkcja testująca odczyt wersji modułu LinNm
*/
void UT_LinNm_GetVersionInfo(void)
{
    Std_ReturnType result = E_NOT_OK;
    TEST_CHECK(result == E_OK);
}


/**
  @brief Test funkcji LinNm_RequestBusSynchronization

  Funkcja testująca wartość zwracaną w pustej funkcji LinNm_RequestBusSynchronization
*/
void UT_LinNm_RequestBusSynchronization(void)
{
    NetworkHandleType   channelHandler;
    Std_ReturnType      result = E_NOT_OK;

    result = LinNm_RequestBusSynchronization(channelHandler);

    TEST_CHECK(result == E_OK);
}


/**
  @brief Test funkcji LinNm_CheckRemoteSleepIndication

  Funkcja testująca wartość zwracaną w pustej funkcji LinNm_CheckRemoteSleepIndication
*/
void UT_LinNm_CheckRemoteSleepIndication(void)
{
    NetworkHandleType   channelHandler;
    boolean*            nmRemoteSleepIndPtr;
    Std_ReturnType      result = E_NOT_OK;
    
    result = LinNm_CheckRemoteSleepIndication(channelHandler, nmRemoteSleepIndPtr);

    TEST_CHECK(result == E_OK);
}


/**
  @brief Test funkcji LinNm_SetSleepReadyBit

  Funkcja testująca wartość zwracaną w pustej funkcji LinNm_SetSleepReadyBit
*/
void UT_LinNm_SetSleepReadyBit(void)
{
    NetworkHandleType   channelHandler;
    boolean             sleepReadyBit;
    Std_ReturnType      result = E_NOT_OK;

    result = LinNm_SetSleepReadyBit(channelHandler, sleepReadyBit);

    TEST_CHECK(result == E_OK);
}


/**
  @brief Test funkcji LinNm_DisableCommunication

  Funkcja testująca wartość zwracaną w pustej funkcji LinNm_DisableCommunication
*/
void UT_LinNm_DisableCommunication(void)
{
    NetworkHandleType   channelHandler;
    Std_ReturnType      result = E_NOT_OK;

    result = LinNm_DisableCommunication(channelHandler);

    TEST_CHECK(result == E_OK);
}


/**
  @brief Test funkcji LinNm_EnableCommunication

  Funkcja testująca wartość zwracaną w pustej funkcji LinNm_EnableCommunication
*/
void UT_LinNm_EnableCommunication(void)
{
    NetworkHandleType   channelHandler;
    Std_ReturnType      result = E_NOT_OK;

    result = LinNm_EnableCommunication(channelHandler);

    TEST_CHECK(result == E_OK);
}


/**
  @brief Test funkcji LinNm_SetUserData

  Funkcja testująca wartość zwracaną w pustej funkcji LinNm_SetUserData
*/
void UT_LinNm_SetUserData(void)
{
    NetworkHandleType   channelHandler;
    uint8*              nmUserDataPtr;
    Std_ReturnType      result = E_NOT_OK;

    result = LinNm_SetUserData(channelHandler, nmUserDataPtr);

    TEST_CHECK(result == E_OK);
}


/**
  @brief Test funkcji LinNm_GetUserData

  Funkcja testująca wartość zwracaną w pustej funkcji LinNm_GetUserData
*/
void UT_LinNm_GetUserData(void)
{
    NetworkHandleType   channelHandler;
    uint8               nmUserDataPtr;
    Std_ReturnType      result = E_NOT_OK;

    result = LinNm_GetUserData(channelHandler, &nmUserDataPtr);

    TEST_CHECK(result == E_OK);
}


/**
  @brief Test funkcji LinNm_GetPduData

  Funkcja testująca wartość zwracaną w pustej funkcji LinNm_GetPduData
*/
void UT_LinNm_GetPduData(void)
{
    NetworkHandleType   channelHandler;
    uint8               nmPduData;
    Std_ReturnType      result = E_NOT_OK;

    result = LinNm_GetPduData(channelHandler, &nmPduData);

    TEST_CHECK(result == E_OK);
}


/**
  @brief Test funkcji LinNm_RepeatMessageRequest

  Funkcja testująca wartość zwracaną w pustej funkcji LinNm_RepeatMessageRequest
*/
void UT_LinNm_RepeatMessageRequest(void)
{
    NetworkHandleType   channelHandler;
    Std_ReturnType      result = E_NOT_OK;

    result = LinNm_RepeatMessageRequest(channelHandler);

    TEST_CHECK(result == E_OK);
}


/**
  @brief Test funkcji LinNm_GetNodeIdentifier

  Funkcja testująca wartość zwracaną w pustej funkcji LinNm_GetNodeIdentifier
*/
void UT_LinNm_GetNodeIdentifier(void)
{
    NetworkHandleType   channelHandler;
    uint8*              nmNodeIdPtr;
    Std_ReturnType      result = E_NOT_OK;

    result = LinNm_GetNodeIdentifier(channelHandler, nmNodeIdPtr);

    TEST_CHECK(result == E_OK);
}


/**
  @brief Test funkcji LinNm_GetLocalNodeIdentifier

  Funkcja testująca wartość zwracaną w pustej funkcji LinNm_GetLocalNodeIdentifier
*/
void UT_LinNm_GetLocalNodeIdentifier(void)
{
    NetworkHandleType   NetworkHandle;
    uint8*              nmNodeIdPtr;
    Std_ReturnType      result = E_NOT_OK;

    result = LinNm_GetLocalNodeIdentifier(NetworkHandle, nmNodeIdPtr);

    TEST_CHECK(result == E_OK);
}


/* [SWS_LinNm_00135] */
void UT_LinNm_GetState(void)
{
    Std_ReturnType result = E_NOT_OK;
    TEST_CHECK(result == E_OK);
}


/* [SWS_LinNm_00148] */
void UT_LinNm_Transmit(void)
{
    Std_ReturnType result = E_NOT_OK;
    TEST_CHECK(result == E_OK);
}


/* [SWS_LinNm_00153] */
void UT_LinNm_TxConfirmation(void)
{
    Std_ReturnType result = E_NOT_OK;
    TEST_CHECK(result == E_OK);
}


/*
  Lista testów - wykomentować testy jakich nie chcecie puszczać
*/
TEST_LIST = {
    { "Test of LinNm_Init"                       , UT_LinNm_Init                         },   /* Format to { "nazwa testu", nazwa_funkcji } */
    { "Test of LinNm_PassiveStartUp"             , UT_LinNm_PassiveStartUp               },
    { "Test of LinNm_NetworkRequest"             , UT_LinNm_NetworkRequest               },
    { "Test of LinNm_NetworkRelease"             , UT_LinNm_NetworkRelease               },
    { "Test of LinNm_GetVersionInfo"             , UT_LinNm_GetVersionInfo               },
    { "Test of LinNm_RequestBusSynchronization"  , UT_LinNm_RequestBusSynchronization    },
    { "Test of LinNm_CheckRemoteSleepIndication" , UT_LinNm_CheckRemoteSleepIndication   },
    { "Test of LinNm_SetSleepReadyBit"           , UT_LinNm_SetSleepReadyBit             },
    { "Test of LinNm_DisableCommunication"       , UT_LinNm_DisableCommunication         },
    { "Test of LinNm_EnableCommunication"        , UT_LinNm_EnableCommunication          },
    { "Test of LinNm_SetUserData"                , UT_LinNm_SetUserData                  },
    { "Test of LinNm_GetUserData"                , UT_LinNm_GetUserData                  },
    { "Test of LinNm_GetPduData"                 , UT_LinNm_GetPduData                   },
    { "Test of LinNm_RepeatMessageRequest"       , UT_LinNm_RepeatMessageRequest         },
    { "Test of LinNm_GetNodeIdentifier"          , UT_LinNm_GetNodeIdentifier            },
    { "Test of LinNm_GetLocalNodeIdentifier"     , UT_LinNm_GetLocalNodeIdentifier       },
    { "Test of LinNm_GetState"                   , UT_LinNm_GetState                     },
    { "Test of LinNm_Transmit"                   , UT_LinNm_Transmit                     },
    { "Test of LinNm_TxConfirmation"             , UT_LinNm_TxConfirmation               },
    { NULL, NULL } /* To musi być na końcu */
};