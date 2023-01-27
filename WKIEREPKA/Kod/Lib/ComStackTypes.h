#ifndef COM_STACK_TYPES_H
#define COM_STACK_TYPES_H


#include "./Std_Types.h"


/* [SWS_COMTYPE_00038] */
typedef uint8 NetworkHandleType;

/* [SWS_COMTYPE_00005] */
typedef uint8 PduIdType;

/* [SWS_COMTYPE_00011] */
typedef struct
{
    uint8* SduDataPtr;
    uint8* MetaDataPtr;
} PduInfoType;


#endif /* COM_STACK_TYPES_H */