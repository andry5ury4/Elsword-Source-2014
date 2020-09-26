#pragma once

//{{ 2012. 02. 03	박세훈	이벤트 관련정보 처리방법 변경 ( Script -> DB )
#ifdef SERV_CHANGE_EVENT_INFO_SCRIPT_TO_DB

enum ReleaseTickType
{
	RTT_ABUSER_TYPE_PVP,
	RTT_ABUSER_TYPE_ITEM,
	RTT_ABUSER_TYPE_ENCHANT,
	RTT_ABUSER_TYPE_ED,
	RTT_ABUSER_TYPE_MONITORING,
	RTT_ABUSER_TYPE_TRAFFIC,

	RTT_EVENT_DATA_TYPE,
	RTT_EVENT_MONSTER_TYPE,
	RTT_EVENT_NOTIFY_MSG_SERVER_INFO,

	RTT_REWARD_DATA,
	RTT_REWARD_LEVEL_UP,
	RTT_REWARD_RETAIN_USER_ITEM,
	RTT_END
};

#endif SERV_CHANGE_EVENT_INFO_SCRIPT_TO_DB
//}}
