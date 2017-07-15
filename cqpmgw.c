#include <cqpmgw.h>
#include <stdlib.h>
#include <memory.h>
#include <windows.h>

static void memcpyrev(void *dst,const char *src,size_t n) // memcpy + memrev
{
    if(n <= 0)return;
    char *s = (char *)dst;
    for(size_t i = n;i != 0;i--)
    {
        s[n - i] = src[i - 1];
    }
}

const CQ_GroupMemberInfo *CQ_getGroupMemberInfoStruct(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL nocache)
{
    CQ_GroupMemberInfo *dst = malloc(sizeof(CQ_GroupMemberInfo));
    char buf[MAXBYTE * 4] = {'\0'};
    DWORD bufsize = sizeof(buf);    
    const char *data = CQ_getGroupMemberInfoV2(AuthCode,groupid,QQID,nocache);
    CryptStringToBinaryA(data,strlen(data),CRYPT_STRING_BASE64,(BYTE*)buf,&bufsize,NULL,NULL);
    
    char *p = buf;
    int16_t len = 0;
    // GID
    memcpyrev(&dst->gid,p,8);p+=8;
    // QQID
    memcpyrev(&dst->qqid,p,8);p+=8;
    // Nickname
    memcpyrev(&len,p,2);p+=2;
    char *nick = malloc(len + 1);
    memcpy(nick,p,len);p+=len;
    nick[len] = '\0';
    dst->nicknameLen = len;
    dst->nickname = nick;
    // Cardname
    memcpyrev(&len,p,2);p+=2;
    char *card = malloc(len + 1);
    memcpy(card,p,len);p+=len;
    card[len] = '\0';
    dst->cardnameLen = len;
    dst->cardname = card;
    // Sex
    memcpyrev(&dst->sex,p,4);p+=4;
    // Age
    memcpyrev(&dst->age,p,4);p+=4;
    // Region
    memcpyrev(&len,p,2);p+=2;
    char *region = malloc(len + 1);
    memcpy(region,p,len);p+=len;
    region[len] = '\0';
    dst->regionLen = len;
    dst->region = card;
    // JoinTime
    memcpyrev(&dst->joinTime,p,4);p+=4;
    // LastTalk
    memcpyrev(&dst->lastTalk,p,4);p+=4;
    // LevelLen
    memcpyrev(&len,p,2);p+=2;
    char *level = malloc(len + 1);
    memcpy(level,p,len);p+=len;
    level[len] = '\0';
    dst->levelLen = len;
    dst->level = level;
    // Permission
    memcpyrev(&dst->permission,p,4);p+=4;
    // hasBlackMark
    int32_t hasBlackMark;
    memcpyrev(&hasBlackMark,p,4);p+=4;
    dst->hasBlackMark = hasBlackMark == 1;
    // specialTitle
    memcpyrev(&len,p,2);p+=2;
    char *specialTitle = malloc(len + 1);
    memcpy(specialTitle,p,len);p+=len;
    specialTitle[len] = '\0';
    dst->specialTitleLen = len;
    dst->specialTitle = specialTitle;
    // specialTitleDuration
    memcpyrev(&dst->specialTitleDuration,p,4);p+=4;
    // allowCardModification
    int32_t allowCardModification;
    memcpyrev(&allowCardModification,p,4);p+=4;
    dst->allowCardModification = allowCardModification == 1;
    return dst;
}

void CQ_freeGroupMemberInfoStruct(const CQ_GroupMemberInfo *ptr)
{
    free((void*)ptr->nickname);
    free((void*)ptr->cardname);
    free((void*)ptr->region);
    free((void*)ptr->level);
    free((void*)ptr->specialTitle);
    free((void*)ptr);
}

const CQ_StrangerInfo *CQ_getStrangerInfoStruct(int32_t AuthCode, int64_t QQID, CQBOOL nocache)
{
    CQ_StrangerInfo *dst = malloc(sizeof(CQ_StrangerInfo));
    char buf[MAXBYTE * 4] = {'\0'};
    DWORD bufsize = sizeof(buf);    
    const char *data = CQ_getStrangerInfo(AuthCode,QQID,nocache);
    CryptStringToBinaryA(data,strlen(data),CRYPT_STRING_BASE64,(BYTE*)buf,&bufsize,NULL,NULL);
    
    char *p = buf;
    int16_t len = 0;
    // QQID
    memcpyrev(&dst->qqid,p,8);p+=8;
    // Nickname
    memcpyrev(&len,p,2);p+=2;
    char *nick = malloc(len + 1);
    memcpy(nick,p,len);p+=len;
    nick[len] = '\0';
    dst->nicknameLen = len;
    dst->nickname = nick;
    // Sex
    memcpyrev(&dst->sex,p,4);p+=4;
    // Age
    memcpyrev(&dst->age,p,4);p+=4;
    return dst;
}

void CQ_freeStrangerInfoStruct(const CQ_StrangerInfo *ptr)
{
    free((void*)ptr->nickname);
    free((void*)ptr);
}
