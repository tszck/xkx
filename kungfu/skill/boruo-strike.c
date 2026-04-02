// Last Modified by Winder on May. 29 2001
// boruo-strike.c 般若掌 和龍爪功互備 取自佛門《十願》。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N後腿腳尖點地而出，一式"HIY"「禮敬諸佛」"NOR"，二掌合十，罡氣直出，攻向$n全身",
	"lvl"   : 0,
	"skill_name" : "禮敬諸佛"
]),
([	"action" : "$N左掌劃一半圓護胸，一式"YEL"「稱讚如來」"NOR"，右掌化刀斜穿而出，疾插$n$l",
	"lvl"   : 10,
	"skill_name" : "稱讚如來"
]),
([	"action" : "$N使一式"HIB"「廣修供養」"NOR"，右掌上引，左掌由後而上一個甩拍，穿過$n護牆擊出",
	"lvl"   : 30,
	"skill_name" : "廣修供養"
]),
([	"action" : "$N左掌護胸，右拳凝勁，一式"MAG"「懺悔業障」"NOR"，四周罡氣瀰漫，出掌緩緩拍向$n$l",
	"lvl"   : 50,
	"skill_name" : "懺悔業障"
]),
([	"action" : "$N使一式"BLU"「請轉法輪」"NOR"，全身飛速旋轉，罡氣飛卷，雙掌一前一後，猛地按向$n的胸口",
	"lvl"   : 60,
	"skill_name" : "請轉法輪"
]),
([	"action" : "$N合掌抱球，猛吸一口氣，一式"HIM"「隨喜功德」"NOR"，全身護滿至陽罡氣，跟着雙掌疾推$n",
	"lvl"   : 80,
	"skill_name" : "隨喜功德"
]),
([	"action" : "$N向上高高躍起，一式"RED"「請佛往世」"NOR"，罡氣居高臨下，四散而出，將掌力籠罩了$n的全身",
	"lvl"   : 100,
	"skill_name" : "請佛往世"
]),
([	"action" : "$N使一式"HIR"「恆順眾生」"NOR"，瞬間勁氣瀰漫，$P雙掌連劈如輪，一環環向$n的$l斬去",
	"lvl"   : 120,
	"skill_name" : "恆順眾生"
]),
([	"action" : "$N兩掌上下護胸，一式"HIC"「普皆迴向」"NOR"拍出，掌影重重疊疊，帶起無邊罡氣攻向$n",
	"lvl"   : 150,
	"skill_name" : "普皆迴向"
]),
});
int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo){ return combo=="dragon-claw"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練般若掌必須空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 80)
		return notify_fail("你的站樁功火候不夠，無法學般若掌。\n");
	if ((int)me->query("max_neili") < 800)
		return notify_fail("你的內力太弱，無法練般若掌。\n");
	if ((me->query_skill("nianhua-finger", 1) < 50) ||
		(me->query_skill("jingang-strike", 1) < 50))
		return notify_fail("你的大金剛神掌和拈花指火候不夠，無法學般若掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 55)
		return notify_fail("你的力氣太低了。\n");
	if ((int)me->query("neili") < 35)
		return notify_fail("你的內力不夠練般若掌。\n");
	me->receive_damage("qi", 50);
	me->add("neili", -30);
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
	int d_e1 = -50;
	int d_e2 = -30;
	int p_e1 = -10;
	int p_e2 = 20;
	int f_e1 = 260;
	int f_e2 = 360;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("banruo-strike", 1);
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
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"boruo-strike/" + action;
}

int help(object me)
{
	write(HIC"\n般若掌："NOR"\n");
	write(@HELP

    般若掌是南少林掌法，和龍爪功互備。
    出自佛門《十願》。

	學習要求：
		站樁功80級
		拈花指50級
		大金剛神掌50級
		內力修為800
HELP
	);
	return 1;
}

