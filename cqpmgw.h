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
#define CQEVENT extern "C" __stdcall
#define CQAPI extern "C" __stdcall
#else
#define CQEVENT __stdcall
#define CQAPI __stdcall
#endif

typedef int32_t CQBOOL;

#define EVENT_IGNORE 0        //�¼�_����
#define EVENT_INTERCEPT 1     //�¼�_���� ��ע��˴���VC++ SDK��ͬ��
#define EVENT_BLOCK \
	#error EVENT_BLOCK has been renamed to EVENT_INTERCEPT,use EVENT_INTERCEPT instead

#define REQUEST_ALLOW 1       //����_ͨ��
#define REQUEST_DENY 2        //����_�ܾ�

#define REQUEST_GROUPADD 1    //����_Ⱥ���
#define REQUEST_GROUPINVITE 2 //����_Ⱥ����

#define CQLOG_DEBUG 0           //���� ��ɫ
#define CQLOG_INFO 10           //��Ϣ ��ɫ
#define CQLOG_INFOSUCCESS 11    //��Ϣ(�ɹ�) ��ɫ
#define CQLOG_INFORECV 12       //��Ϣ(����) ��ɫ
#define CQLOG_INFOSEND 13       //��Ϣ(����) ��ɫ
#define CQLOG_WARNING 20        //���� ��ɫ
#define CQLOG_ERROR 30          //���� ��ɫ
#define CQLOG_FATAL 40          //�������� ���

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
CQAPI const char * CQ_getGroupMemberInfoV2(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL nocache);
CQAPI const char * CQ_getStrangerInfo(int32_t AuthCode, int64_t QQID, CQBOOL nocache);
CQAPI int32_t CQ_addLog(int32_t AuthCode, int32_t priority, const char *category, const char *content);
CQAPI const char * CQ_getCookies(int32_t AuthCode);
CQAPI int32_t CQ_getCsrfToken(int32_t AuthCode);
CQAPI int64_t CQ_getLoginQQ(int32_t AuthCode);
CQAPI const char * CQ_getLoginNick(int32_t AuthCode);
CQAPI const char * CQ_getAppDirectory(int32_t AuthCode);
CQAPI int32_t CQ_setFatal(int32_t AuthCode, const char *errorinfo);

#endif