// sun-finger.c 一陽指 book: 一陽指訣
// Last Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"GRN"「陽關三疊」"NOR"，真氣自指間噴薄而出，連出三指，快如電閃，點向$n的$l",
	"lvl" : 0,
	"skill_name" : "陽關三疊"
]),
([	"action" : "$N身形一轉，一步跨到$n身後。$n急忙轉身，$N又如閃電般躍回，
一式"YEL"「魯陽返日」"NOR"，右手食指疾出，指向$n的$l",
	"lvl" : 20,
	"skill_name" : "魯陽返日"
]),
([	"action" : "$N向左踏出一步，左手輕揚，右手食指挾着雄渾內力疾點$n的$l，
招式光明坦蕩，正是一式"HIW"「陽春白雪」"NOR"",
	"lvl" : 40,
	"skill_name" : "陽春白雪"
]),
([	"action" : "$N身影飄起，一式"MAG"「陽鈎揮天」"NOR"，自上而下，左腳彎曲如鈎，踹向$n的右肩，$n側身相避，$N右手趁勢點向$n的$l",
	"lvl" : 60,
	"skill_name" : "陽鈎揮天"
]),
([	"action" : "只見$N臉上忽地一紅，左手一收，一式"RED"「烈日驕陽」"NOR"，右手食指斜指，向$n的$l點去",
	"lvl" : 70,
	"skill_name" : "烈日驕陽"
]),
([	"action" : "$N左掌斜削，突然間變掌為指，嗤的一聲響，一式"HIM"「丹鳳朝陽」"NOR"，使出一陽指力，疾點$n的$l",
	"lvl" : 90,
	"skill_name" : "丹鳳朝陽"
]),
([	"action" : "$N反身一躍，閃身到$n背後，左膝一屈，右手食指回身一式"BLU"「陰陽交錯」"NOR"，射向$n的後腦",
	"lvl" : 100,
	"skill_name" : "陰陽交錯"
]),
([	"action" : "$N一聲大吼, 一式"HIY"「三陽開泰」"NOR"，用盡全力向$n的$l點去",
	"lvl" : 130,
	"skill_name" : "三陽開泰"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練一陽指必須空手。\n");
	if (me->query("gender") != "男性")
		return notify_fail("你陽氣不足，無法學一陽指。\n");
	if ((int)me->query("max_neili") < 700)
		return notify_fail("你的內力太弱，無法練一陽指。\n");
	if ((int)me->query_skill("kurong-changong", 1) > 80 ||
		(int)me->query_skill("xiantian-qigong", 1) > 80)
		return 1;
	else
		return notify_fail("你的本門內功火候不夠，無法學一陽指。\n");
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的內力不夠練一陽指!\n");
	me->receive_damage("qi", 50);
	me->add("neili", -20);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -35;
	int p_e2 = -15;
	int f_e1 = 390;
	int f_e2 = 490;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("sun-finger", 1);
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
		"damage_type" : random(2) ? "刺傷" : "瘀傷",
	]);
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) 
{
  if(me->query_skill("kurong-changong") > 10) return 1.0;
  else return 0.6;
}


string perform_action_file(string action)
{
	return __DIR__"sun-finger/" + action;
}
int help(object me)
{
	write(HIC"\n一陽指："NOR"\n");
	write(@HELP

    原為大理段氏獨門招牌武功，當年一燈大師段智興挾此技參與
華山論劍，獲得南帝稱號。後一燈大師用一陽指和重陽真人交換先
天氣功，此技亦流入全真派中。
    可與全真教昊天掌互備。

	學習要求：
		男性
		枯榮禪功或先天氣功80級
		內力700
HELP
	);
	return 1;
}

