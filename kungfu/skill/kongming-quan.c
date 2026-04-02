// kongming.c 空明拳
// Last Modified by sir 10.21.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N使一招"HIW"「空屋住人」"NOR"，雙手輕飄飄地箍向$n$l",
	"lvl":0,
	"skill_name": "空屋住人"
]),
([	"action": "$N左掌一平,右掌一伸,一招"HIW"「空碗盛飯」"NOR"直拍$n的$l",
	"lvl":10,
	"skill_name": "空碗盛飯"
]),
([	"action": "$N身形繞$n一轉，雙手上撩,一招"HIW"「空缽裝水」"NOR"擊向$n$l",
	"lvl":20,
	"skill_name": "空缽裝水"
]),
([	"action": "$N左掌一按,右掌一揮,一招"HIW"「虛懷若谷」"NOR"拍向$n的$l",
	"lvl":30,
	"skill_name": "虛懷若谷"
]),
([	"action": "$N使一招"HIW"「空山鳥語」"NOR"，$n的$l已圍在$N的重重掌影之下",
	"lvl":40,
	"skill_name": "空山鳥語"
]),
([	"action": "$N神色一斂，使出"HIW"「我心空明」"NOR"，圍繞$n的$l接連出掌",
	"lvl":50,
	"skill_name": "我心空明"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

  if (!me->query("zhou/jieyi") && !me->query_skill("kongming-quan",1)
   && me->query("family/family_name")!="全真教")
    return notify_fail("空明拳必須向周伯通請教。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練空明拳必須空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力太弱，無法練空明拳。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 70)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 70)
		return notify_fail("你的內力不夠了！休息一下再練吧。\n");
	me->receive_damage("qi", 60);
	me->add("neili", -60);
	return 1;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 5;
	int d_e2 = 20;
	int p_e1 = -50;
	int p_e2 = 30;
	int f_e1 = 400;
	int f_e2 = 500;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("kongming-quan", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 獲得招數序號上限 */
			break;
		}
	seq = random(seq);       /* 選擇出手招數序號 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,		
		"damage_type" : random(2) ? "內傷" : "瘀傷",
	]);
}

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"kongming-quan/" + action;
}

int help(object me)
{
	write(HIC"\n空明拳："NOR"\n");
	write(@HELP

    空明拳是老頑童周伯通在桃花島囚洞中悟出來的武功。
    老子《道德經》裏有句話道：“埏埴以為器，當其無，有器之
用。鑿戶牖以為室，當其無，有室之用。”就是説，碗只因為中間
是空的，才有盛飯的功用，倘若它是實心的一塊瓷土，還能裝甚麼
飯？建造房屋，開設門窗，只因為有了四壁中間的空隙，房子才能
住人。倘若房屋是實心的，倘若門窗不是有空，磚頭木材四四方方
的砌上這麼一大堆，那就一點用處也沒有了。全真派最上乘的武功，
要旨就在“空、柔”二字，那就是所謂“大成若缺，其用不弊。大
盈若衝，其用不窮”。空明拳乃是天下至柔的武功，能增強招架。

	學習要求：
		內力100
HELP
	);
	return 1;
}

