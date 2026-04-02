// Last Modified by winder on May. 29 2001
// zui-club.c 少林醉棍

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":""HIB"「藍採和，提籃勸酒醉朦朧」"NOR"，$N手中$w半提，緩緩划向$n的$l",	
	"lvl" : 0,
	"skill_name" : "藍採和，提籃勸酒醉朦朧"
]),
([	"action":""MAG"「何仙姑，攔腰敬酒醉仙步」"NOR"，$N左掌護胸，右臂挾棍猛地掃向$n的腰間",
	"lvl" : 20,
	"skill_name" : "何仙姑，攔腰敬酒醉仙步"
]),
([	"action":""HIY"「曹國舅，千杯不醉倒金盅」"NOR"，$N倒豎$w，指天打地，向$n的$l劈去",
	"lvl" : 30,
	"skill_name" : "曹國舅，千杯不醉倒金盅"
]),
([	"action":""HIC"「韓湘子，鐵棍提胸醉拔蕭」"NOR"，$N橫提$w，棍端劃了個半圈，擊向$n的$l",
	"lvl" : 40,
	"skill_name" : "韓湘子，鐵棍提胸醉拔蕭"
]),
([	"action":""HIR"「漢鍾離，跌步翻身醉盤龍」"NOR"，$N手中棍花團團，疾風般向卷向$n",
	"lvl" : 50,
	"skill_name" : "漢鍾離，跌步翻身醉盤龍"
]),
([	"action":""HIW"「鐵柺李，踢倒金山醉玉池」"NOR"，$N單腿支地，一腿一棍齊齊擊向$n的$l",
	"lvl" : 55,
	"skill_name" : "鐵柺李，踢倒金山醉玉池"
]),
([	"action":""YEL"「張果老，醉酒拋杯倒騎驢」"NOR"，$N扭身反背，$w從胯底鑽出，戳向$n的胸口",
	"lvl" : 60,
	"skill_name" : "張果老，醉酒拋杯倒騎驢"
]),
([	"action":""CYN"「呂洞賓，酒醉提壺力千鈞」"NOR"，$N騰空而起，如山棍影，疾疾壓向$n",
	"lvl" : 64,
	"skill_name" : "呂洞賓，酒醉提壺力千鈞"
]),
});

int valid_enable(string usage) { return (usage=="club") || (usage=="parry"); }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的內力不夠。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 50)
		return notify_fail("你的站樁功火候太淺。\n");
	if ((int)me->query_skill("weituo-club", 1) < 20)
		return notify_fail("你的韋陀棍火候太淺。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("你的內力或氣不夠練少林醉棍。\n");
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
	int d_e1 = -45;
	int d_e2 = -35;
	int p_e1 = 10;
	int p_e2 = 25;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 100;
	int m_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("zui-club", 1);
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
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : "挫傷",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"zui-club/" + action;
}

int help(object me)
{
	write(HIC"\n少林醉棍："NOR"\n");
	write(@HELP

    少林醉棍是南少林高級棍法。

	學習要求：
		站樁功50級
		韋陀棍20級
		內力修爲500
HELP
	);
	return 1;
}

