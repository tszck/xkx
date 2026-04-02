// luoying-zhang.c 落英神劍掌
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N雙手平伸，向外掠出，一式"GRN"「春雲乍展」"NOR"，指尖輕盈漂動，輕輕反點$n的$l",
	"lvl" : 10,
	"skill_name" : "春雲乍展"
]),
([	"action" : "$N右手五指緩緩一收，一式"HIG"「迴風拂柳」"NOR"，五指忽然遙遙拂向$n，$n只覺得五股疾風襲向自己五處大穴",
	"lvl" : 0,
	"skill_name" : "迴風拂柳"
]),
([	"action" : "$N突然縱身躍入半空，一個輕巧轉身，單掌劈落，一式"MAG "「江城飛花」"NOR"，拍向$n的頭頂",
	"lvl" : 10,
	"skill_name" : "江城飛花"
]),
([	"action" : "$N突然躍起，雙手連環，運掌如劍，勢如疾風電閃，一式"HIM "「雨急風狂」"NOR"，攻向$n的全身",
	"lvl" : 10,
	"skill_name" : "雨急風狂"
]),
([	"action" : "$N左手揮起，掌心朝天，伸出右手併攏食指中指，捻個劍決，一式"CYN"「星河在天」"NOR"，直指$n的中盤",
	"lvl" : 20,
	"skill_name" : "星河在天"
]),
([	"action" : "$N突然抽身而退，接着一式"HIW"「流華紛飛」"NOR"，平身飛起，雙掌向$n的後腦連拍數掌",
	"lvl" : 30,
	"skill_name" : "流華紛飛"
]),
([	"action" : "$N突然抽身躍起，左掌挾着勁風洶湧拍出，接着右掌自左掌後突地伸出，一式"HIR"「彩雲追月」"NOR"搶在左掌前向$n的$l拍去",
	"lvl" : 30,
	"skill_name" : "彩雲追月"
]),
([	"action" : "$N使一式"HIC"「天如穹廬」"NOR"，全身突然飛速旋轉，雙掌忽前忽後，猛地拍向$n的胸口",
	"lvl" : 40,
	"skill_name" : "天如穹廬"
]),
([	"action" : "$N前後一揉，一式"HIB"「朝雲橫度」"NOR"，化掌如劍，一股凌厲劍氣襲向$n的下盤",
	"lvl" : 50,
	"skill_name" : "朝雲橫度"
]),
([	"action" : "$N使一式"HIW"「白虹經天」"NOR"，雙掌舞出無數圈勁氣，一環環向$n的$l斫去",
	"lvl" : 70,
	"skill_name" : "白虹經天"
]),
([	"action" : "$N雙手食指和中指一和，一式"HIM"「紫氣東來」"NOR"，一股強烈的氣流湧向$n的全身",
	"lvl" : 60,
	"skill_name" : "紫氣東來"
]),
([	"action" : "$N一式"HIC"「落英漫天」"NOR"，雙掌在身前疾轉，掌花飛舞，鋪天蓋地直指向$n。$n只見漫天掌花，眼花繚亂。",
	"lvl" : 99,
	"skill_name" : "落英漫天"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; } 
int valid_combine(string combo) { return combo=="xuanfeng-leg"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練落英神劍掌必須空手。\n");
	if ((int)me->query_skill("bibo-shengong", 1) < 15)
		return notify_fail("你的碧波神功火候不夠，無法學落英神劍掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力太弱，無法練落英神劍掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的內力不夠練落英神劍掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -15);
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
	int d_e1 = -35;
	int d_e2 = -15;
	int p_e1 = 5;
	int p_e2 = 35;
	int f_e1 = 180;
	int f_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("luoying-zhang", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"luoying-zhang/" + action;
}


int help(object me)
{
	write(HIC"\n落英神劍掌："NOR"\n");
	write(@HELP

    落英神劍掌脫胎於落英神劍，以掌代劍，威力不遜。
    可與旋風掃葉腿互備。

	學習要求：
		碧波神功15級
		內力100
HELP
	);
	return 1;
}

