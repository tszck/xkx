// canhe-finger.c 參合指
// Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"MAG"「目不識丁」"NOR"，真氣自指間噴薄而出，連出三指，快如電閃，點向$n的$l",
	"lvl" : 0,
	"skill_name" : "目不識丁"
]),
([	"action" : "$N身形一轉，一式"HIR"「畫龍點睛」"NOR"，右手自下而起，食指伸處，一股真氣衝關而出，直向$n的眼睛點去",
	"lvl" : 20,
	"skill_name" : "畫龍點睛"
]),
([	"action" : "$N左手食指一抬，向$n點去，右手食指緊接着點向$n的$l，一式"GRN"「撲朔迷離」"NOR"，雙手亦虛亦實，$n頓覺不知道如何對付",
	"lvl" : 40,
	"skill_name" : "撲朔迷離"
]),
([	"action" : "$N忽然面現驚懼之色，返身欲走，只一瞬間，身形不退反進，一式
"BLU"「受寵若驚」"NOR"，右手食指自下而上，趁勢點向$n的$l",
	"lvl" : 60,
	"skill_name" : "受寵若驚"
]),
([	"action" : "$N運起慕容世家自然心法，左右手一收一放，一式"YEL"「滔滔不絕」"NOR"，雙手食指連指，向$n的$l點去",
	"lvl" : 70,
	"skill_name" : "滔滔不絕"
]),
([	"action" : "$N左右雙腳碎步後移，眼角瞥見$n跟進，突然間左手變掌爲指，嗤的一聲響，一式"CYN"「退避三舍」"NOR"，回點$n的$l",
	"lvl" : 90,
	"skill_name" : "退避三舍"
]),
([	"action" : "$N一閃身到了$n背後，左膝一屈，側身右手一指，一式"RED"「臥薪嚐膽」"NOR"，指向$n的後腰",
	"lvl" : 100,
	"skill_name" : "臥薪嚐膽"
]),
([	"action" : "$N左腳向左踏出一步，又快如閃電般抽回，右步上前一大步，頓時欺近$n，"GRN"「相煎何急」"NOR"！食指疾點$n的$l",
	"lvl" : 130,
	"skill_name" : "相煎何急"
]),
});
int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="xingyi-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練參合指必須空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力太弱，無法練參合指。\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 15)
		return notify_fail("你的神元火候不夠，無法學參合指。\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 25)
		return notify_fail("你的內力不夠練。\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 280;
	int f_e2 = 380;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("canhe-finger", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point() { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"canhe-finger/" + action;
}

int help(object me)
{
	write(HIC"\n參合指："NOR"\n");
	write(@HELP

    參合指爲姑蘇慕容家指法絕技。慕容氏家學淵源，參合指威力
亦不遜於少林派大力金剛指。
    可與星移掌互備。

	學習要求：
		神元功15級
		內力100
HELP
	);
	return 1;
}

