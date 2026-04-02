// jinding-zhang.c 金頂綿掌
// Oct. 9 1997 by That

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "三陽開泰" ,
	"action" : "$N身形微晃，一招"RED"「三陽開泰」"NOR"，掌起風生，$n只覺得一股暖氣襲向$l",
	"lvl"   : 0
]),
([	"skill_name" : "五氣呈祥" ,
	"action" : "$N雙手變幻，五指輕彈，一招"HIR"「五氣呈祥」"NOR"，力分五路，招罩十方，抓向$n的$l",
	"lvl"   : 11
]),
([	"skill_name" : "罡風推雲" ,
	"action" : "$N左手前引，右手倏出，搶在頭裏，一招"CYN"「罡風推雲」"NOR"，疾抓向$n的$l",
	"lvl"   : 22
]),
([	"skill_name" : "逆流捧沙" ,
	"action" : "$N左手圈轉，輕拂$n的左手，反向推出，右手連續磕擊，一招"BLU"「逆流捧沙」"NOR"，猛地擊向$n的下巴",
	"lvl"   : 33
]),
([	"skill_name" : "雷洞霹靂" ,
	"action" : "$N舌綻春雷，一聲嬌喝，在$n一愣間，右手一招"HIB"「雷洞霹靂」"NOR"，直搗$n的$l",
	"lvl"   : 44
]),
([	"skill_name" : "金頂佛光" ,
	"action" : "$N雙手平舉握拳，臉露微笑，$n恍惚間看到$N分身為二，便見$N四掌齊出，一招"HIY"「金頂佛光」"NOR"不知哪兩掌是實？掌風已經襲面",
	"lvl"   : 55
]),
([	"skill_name" : "梵心降魔" ,
	"action" : "$N一幅寶像莊嚴，使出"YEL"「梵心降魔」"NOR"，掌勢如虹，繞着$n漂移不定",
	"lvl"   : 66
]),
([	"skill_name" : "法尊八荒" ,
	"action" : "$N全場遊走，雙臂疾舞，化為點點掌影，一招"HIC"「法尊八荒」"NOR"鋪天蓋地襲向$n全身各處大穴",
	"lvl"   : 77
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="tiangang-zhi"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練金頂綿掌必須空手。\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 10)
		return notify_fail("你的臨濟莊心法火候不夠，不能練金頂綿掌。\n");
	if ((int)me->query("max_neili") < 30)
		return notify_fail("你的內力太弱，無法練金頂綿掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 45)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的內力不夠練金頂綿掌。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -25);
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
	int d_e1 = -40;
	int d_e2 = -15;
	int p_e1 = 5;
	int p_e2 = 30;
	int f_e1 = 180;
	int f_e2 = 290;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jinding-zhang", 1);
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
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"jinding-zhang/"+ action;
}
int help(object me)
{
	write(HIC"\n金頂綿掌："NOR"\n");
	write(@HELP

    金頂綿掌為峨嵋派掌法。
    可與天罡指穴法互備。

	學習要求：
		臨濟十二莊20級
		內力30
HELP
	);
	return 1;
}

