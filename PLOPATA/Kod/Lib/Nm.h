#ifndef NM_H
#define NM_H

/// @brief 
typedef struct
{
    /// TODO: unknown type
    char a;
    int  b;
    
} NetworkHandleType;

/// @brief 
typedef struct
{
    /// TODO: unknown type
    char a;
    int  b;
} Nm_StateType;


/// @brief 
typedef struct 
{
    /// TODO: unknown type
    char a;
    int  b;
} Nm_ModeType;


/// @brief 
typedef struct
{
    /// TODO: unknown type
    char a;
    int  b;
} PduIdType;


/// @brief 
typedef struct
{
    /// TODO: unknown type
    char a;
    int  b;
} PduInfoType;



///TODO: define required interfaces
void Nm_BusSleepMode(void);
void Nm_NetworkMode(void);

///TODO: define optional interfaces
void Nm_CoordReadyToSleepCancellation(void);
void Nm_CoordReadyToSleepIndication(void);
void Nm_RemoteSleepIndication(void);
void Nm_StateChangeNotification(void);


#endif /* NM_H */
