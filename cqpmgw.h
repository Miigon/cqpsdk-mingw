#ifndef CQP_H_
#define CQP_H_

#ifdef CQEVENT
#ifndef CQ_FORCE_SDK
	#error You have included VC++ version of CoolQ SDK! Dual SDKs may not work properly.
	#error You can still use this SDK FORCEDLY by adding `#define CQ_FORCE_SDK` before the include statement.
#endif
#endif

#include <stdint.h>

#define CQAPIVER 9
#define CQAPIVERTEXT "9"

#ifdef __cplusplus
extern "C"
{
#define CQEVENT extern "C" __stdcall
#else
#define CQEVENT __stdcall
#endif
#define CQAPI __stdcall

typedef int32_t CQBOOL;

#define EVENT_IGNORE 0        //事件_忽略
#define EVENT_INTERCEPT 1     //事件_拦截 ！注意此处与VC++ SDK不同！
#define EVENT_BLOCK \
	#error EVENT_BLOCK has been renamed to EVENT_INTERCEPT,use EVENT_INTERCEPT instead

#define REQUEST_ALLOW 1       //请求_通过
#define REQUEST_DENY 2        //请求_拒绝

#define REQUEST_GROUPADD 1    //请求_群添加
#define REQUEST_GROUPINVITE 2 //请求_群邀请

#define CQLOG_DEBUG 0           //调试 灰色
#define CQLOG_INFO 10           //信息 黑色
#define CQLOG_INFOSUCCESS 11    //信息(成功) 紫色
#define CQLOG_INFORECV 12       //信息(接收) 蓝色
#define CQLOG_INFOSEND 13       //信息(发送) 绿色
#define CQLOG_WARNING 20        //警告 橙色
#define CQLOG_ERROR 30          //错误 红色
#define CQLOG_FATAL 40          //致命错误 深红

CQAPI int32_t CQ_sendPrivateMsg(int32_t AuthCode, int64_t QQID, const char *msg);
CQAPI int32_t CQ_sendGroupMsg(int32_t AuthCode, int64_t groupid, const char *msg);
CQAPI int32_t CQ_sendDiscussMsg(int32_t AuthCode, int64_t discussid, const char *msg);
CQAPI int32_t CQ_sendLike(int32_t AuthCode, int64_t QQID);
CQAPI int32_t CQ_setGroupKick(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL rejectaddrequest);
CQAPI int32_t CQ_setGroupBan(int32_t AuthCode, int64_t groupid, int64_t QQID, int64_t duration);
CQAPI int32_t CQ_setGroupAdmin(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL setadmin);
CQAPI int32_t CQ_setGroupWholeBan(int32_t AuthCode, int64_t groupid, CQBOOL enableban);
CQAPI int32_t CQ_setGroupAnonymousBan(int32_t AuthCode, int64_t groupid, const char *anomymous, int64_t duration);
CQAPI int32_t CQ_setGroupAnonymous(int32_t AuthCode, int64_t groupid, CQBOOL enableanomymous);
CQAPI int32_t CQ_setGroupCard(int32_t AuthCode, int64_t groupid, int64_t QQID, const char *newcard);
CQAPI int32_t CQ_setGroupLeave(int32_t AuthCode, int64_t groupid, CQBOOL isdismiss);
CQAPI int32_t CQ_setGroupSpecialTitle(int32_t AuthCode, int64_t groupid, int64_t QQID, const char *newspecialtitle, int64_t duration);
CQAPI int32_t CQ_setDiscussLeave(int32_t AuthCode, int64_t discussid);
CQAPI int32_t CQ_setFriendAddRequest(int32_t AuthCode, const char *responseflag, int32_t responseoperation, const char *remark);
CQAPI int32_t CQ_setGroupAddRequestV2(int32_t AuthCode, const char *responseflag, int32_t requesttype, int32_t responseoperation, const char *reason);
CQAPI const char * CQ_getGroupMemberInfoV2(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL nocache); // 返回原始数据，使用 `CQ_getGroupMemberInfoStruct` 获取struct
CQAPI const char * CQ_getStrangerInfo(int32_t AuthCode, int64_t QQID, CQBOOL nocache);
CQAPI int32_t CQ_addLog(int32_t AuthCode, int32_t priority, const char *category, const char *content);
CQAPI const char * CQ_getCookies(int32_t AuthCode);
CQAPI int32_t CQ_getCsrfToken(int32_t AuthCode);
CQAPI int64_t CQ_getLoginQQ(int32_t AuthCode);
CQAPI const char * CQ_getLoginNick(int32_t AuthCode);
CQAPI const char * CQ_getAppDirectory(int32_t AuthCode);
CQAPI int32_t CQ_setFatal(int32_t AuthCode, const char *errorinfo);

typedef struct
{
	int64_t gid;
	int64_t qqid;
	const char *nickname;int16_t nicknameLen;
	const char *cardname;int16_t cardnameLen;
	int32_t sex;// 0男 1女
	int32_t age;
	const char *region;int16_t regionLen;
	int32_t joinTime;
	int32_t lastTalk;
	const char *level;int16_t levelLen;
	int32_t permission;
	int32_t hasBlackMark;
	const char *specialTitle;int16_t specialTitleLen;
	int32_t specialTitleDuration;
	int32_t allowCardModification;
	
}CQ_GroupMemberInfo;

const CQ_GroupMemberInfo *CQ_getGroupMemberInfoStruct(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL nocache); // 请对应用 `CQ_freeGroupMemberInfoStruct` 释放
void CQ_freeGroupMemberInfoStruct(const CQ_GroupMemberInfo *ptr);

typedef struct
{
	int64_t qqid;
	const char *nickname;int16_t nicknameLen;
	int32_t sex;// 0男 1女
	int32_t age;
}CQ_StrangerInfo;

const CQ_StrangerInfo *CQ_getStrangerInfoStruct(int32_t AuthCode, int64_t QQID, CQBOOL nocache);
void CQ_freeStrangerInfoStruct(const CQ_StrangerInfo *ptr);

#ifdef __cplusplus
}
#endif
#endif
